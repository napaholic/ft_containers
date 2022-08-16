#ifndef MAP_HPP
#define MAP_HPP

#include "utils.hpp"
#include "iterator.hpp"
#include "reverseIterator.hpp"
#include "tree.hpp"

namespace ft
{
	/*************************************************************************************
	************************************* Map Iterator ***********************************
	**************************************************************************************/
	template <typename T>
	struct map_iterator
	{
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef ptrdiff_t difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;

		typedef typename Node<T>::node_ptr node_ptr;
		node_ptr _node;

		map_iterator() : _node() {}
		map_iterator(node_ptr x) : _node(x) {}

		reference operator*() const
		{
			return (_node)->_data;
		}
		pointer operator->() const
		{
			return &(_node)->_data;
		}
		map_iterator &operator++()
		{
			_node = next_node<node_ptr>(_node);
			return *this;
		}
		map_iterator operator++(int)
		{
			map_iterator tmp = *this;
			_node = next_node<node_ptr>(_node);
			return tmp;
		}
		map_iterator &operator--()
		{
			_node = prev_node<node_ptr>(_node);
			return *this;
		}
		map_iterator operator--(int)
		{
			map_iterator tmp = *this;
			_node = prev_node<node_ptr>(_node);
			return tmp;
		}
		bool operator==(const map_iterator &x) const
		{
			return _node == x._node;
		}
		bool operator!=(const map_iterator &x) const
		{
			return _node != x._node;
		}

	};


	/*************************************************************************************
	********************************** Const Map Iterator ********************************
	**************************************************************************************/
	template <typename T>
	struct const_map_iterator
	{
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef ptrdiff_t difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef map_iterator<T> map_iterator;

		typedef typename Node<T>::const_node_ptr node_ptr;
		node_ptr _node;

		const_map_iterator() : _node() {}
		const_map_iterator(node_ptr x) : _node(x) {}
		const_map_iterator(const map_iterator &it) : _node(it._node) {}

		reference operator*() const
		{
			return (_node)->_data;
		}
		pointer operator->() const
		{
			return &(_node)->_data;
		}
		const_map_iterator &operator++()
		{
			_node = next_node<node_ptr>(_node);
			return *this;
		}
		const_map_iterator operator++(int)
		{
			const_map_iterator tmp = *this;
			_node = next_node<node_ptr>(_node);
			return tmp;
		}
		const_map_iterator &operator--()
		{
			_node = prev_node<node_ptr>(_node);
			return *this;
		}
		const_map_iterator operator--(int)
		{
			const_map_iterator tmp = *this;
			_node = prev_node<node_ptr>(_node);
			return tmp;
		}
		bool operator==(const const_map_iterator &x) const
		{
			return _node == x._node;
		}
		bool operator!=(const const_map_iterator &x) const
		{
			return _node != x._node;
		}

	};
	
	template <typename node_ptr>
	bool operator==(const map_iterator<node_ptr> &x, const const_map_iterator<node_ptr> &y)
	{
		return x._node == y._node;
	}

	template <typename node_ptr>
	bool operator!=(const map_iterator<node_ptr> &x, const const_map_iterator<node_ptr> &y)
	{
		return x._node != y._node;
	}


	/*************************************************************************************
	***************************************** Map ****************************************
	**************************************************************************************/

	template <typename Key,
			  typename T,
			  typename Compare = ft::<Key>,
			  typename Alloc = std::allocator<pair<const Key, T> > >
	class map
	{
	public:
		typedef Key 													key_type;
		typedef T 														mapped_type;
		typedef pair<const key_type, mapped_type> 						value_type;
		typedef Compare 												key_compare;
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;

		protected:
			key_compare comp;
			value_compare(key_compare c) : comp(c) {}

		public:
			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(x.first, y.first);
			}
		};

		typedef Alloc 													allocator_type;
		typedef typename allocator_type::reference 						reference;
		typedef typename allocator_type::const_reference 				const_refernce;
		typedef typename allocator_type::pointer 						pointer;
		typedef typename allocator_type::const_pointer 					const_pointer;
		typedef typename allocator_type::difference_type 				difference_type;
		typedef typename allocator_type::size_type 						size_type;

		typedef map_iterator<value_type> 								iterator;
		typedef const_map_iterator<value_type> 							const_iterator;
		typedef ft::reverse_iterator<iterator> 							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> 					const_reverse_iterator;
		typedef typename AVLTree<value_type, value_compare>::node_ptr	node_ptr;

	private:
		value_compare 													_comp;
		allocator_type 													_alloc;
		AVLTree<value_type, value_compare> 								_tree;

	public:
		/*
		** ------------------------------- CONSTRUCTOR --------------------------------
		*/
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _tree(value_compare(_comp)) {}
		
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _tree(value_compare(comp))
		{
			insert(first, last);
		}

		map(const map &x) : _comp(x._comp), _alloc(x._alloc), _tree(value_compare(_comp))
		{
			insert(x.begin(), x.end());
		}

		/*
		** ------------------------------- DESTRUCTOR --------------------------------
		*/

		~map() {}


		/*
		** ------------------------------- OPERATOR --------------------------------
		*/

		map &operator=(const map &x)
		{
			if (this != &x)
			{
				clear();
				insert(x.begin(), x.end());
			}
			return *this;
		}

		/*
		** ------------------------------- ITERATOR --------------------------------
		*/

		iterator begin()
		{
			if (_tree.get_min_node() == NULL)
				return iterator(_tree.get_end_node());
			return iterator(_tree.get_min_node());
		}

		const_iterator begin() const
		{
			if (_tree.get_min_node() == NULL)
				return const_iterator(_tree.get_end_node());
			return const_iterator(_tree.get_min_node());
		}

		iterator end()
		{
			return iterator(_tree.get_end_node());
		}

		const_iterator end() const
		{
			return const_iterator(_tree.get_end_node());
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		/*
		** ------------------------------- CAPACITY --------------------------------
		*/

		bool empty() const
		{
			return _tree.is_empty();
		}

		size_type size() const
		{
			return _tree.get_size();
		}

		size_type max_size() const
		{
			return _tree.get_max_size();
		}

		/*
		** ------------------------------- ELEMENT ACCESS --------------------------------
		*/

		mapped_type &operator[](const key_type &k)
		{
			return (*((insert(ft::make_pair(k, mapped_type()))).first)).second;
		}

		/*
		** ------------------------------- MODIFIERS --------------------------------
		*/

		//insert
		pair<iterator, bool> insert(const value_type &val)
		{
			node_ptr found = _tree.find(val);

			if (found == _tree.get_end_node())
			{
				_tree.insert(val);
				return ft::make_pair(iterator(_tree.find(val)), true);
			}
			return ft::make_pair(iterator(found), false);
		}

		iterator insert(iterator position, const value_type &val)
		{
			node_ptr found = _tree.find(val);

			if (found == _tree.get_end_node())
			{
				insert(val);
				return iterator(_tree.find(val));
			}
			return iterator(found);
			position++;
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(ft::make_pair((*first).first, (*first).second));
				first++;
			}
		}

		//erase
		void erase(iterator position)
		{
			if (position != iterator(NULL))
				_tree.erase(ft::make_pair(position->first, position->second));
		}

		size_type erase(const key_type &k)
		{
			if (_tree.find(ft::make_pair(k, mapped_type())) == _tree.get_end_node())
				return 0;
			_tree.erase(ft::make_pair(k, mapped_type()));
			return 1;
		}

		void erase(iterator first, iterator last)
		{
			while (first != last)
				erase(first++);
		}

		//swap
		void swap(map &x)
		{
			_tree.swap(x._tree);
		}

		//clear
		void clear()
		{
			_tree.clear();
		}

		//compare
		key_compare key_comp() const
		{
			return key_compare();
		}

		value_compare value_comp() const
		{
			return value_compare(_comp);
		}

		//find
		iterator find(const key_type &k)
		{
			return iterator(_tree.find(ft::make_pair(k, mapped_type())));
		}

		const_iterator find(const key_type &k) const
		{
			return const_iterator(_tree.find(ft::make_pair(k, mapped_type())));
		}
		
		//count
		size_type count(const key_type &k) const
		{
			if (_tree.find(ft::make_pair(k, mapped_type())) == _tree.get_end_node()) 
				return 0;
			return 1;
		}
		
		//bounds
		iterator lower_bound(const key_type &k)
		{
			return iterator(_tree.lower_bound(ft::make_pair(k, mapped_type())));
		}
		
		const_iterator lower_bound(const key_type &k) const
		{
			return const_iterator(_tree.lower_bound(ft::make_pair(k, mapped_type())));
		}
		
		iterator upper_bound(const key_type &k)
		{
			return iterator(_tree.upper_bound(ft::make_pair(k, mapped_type())));
		}
		
		const_iterator upper_bound(const key_type &k) const
		{
			return const_iterator(_tree.upper_bound(ft::make_pair(k, mapped_type())));
		}
		
		//range
		ft::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}
		
		ft::pair<iterator, iterator> equal_range(const key_type &k)
		{
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}
		
		//allocator
		allocator_type get_alloc() const
		{
			return allocator_type();
		}
	};

	/*
	** ------------------------------- NON-MEMBER OVERLOADS --------------------------------
	*/

	template <class Key, class T, class Compare, class Alloc>
  	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

}

#endif