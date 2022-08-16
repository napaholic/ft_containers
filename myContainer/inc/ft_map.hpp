//
// Created by jaewkim on 2022/08/09.
//

#ifndef MYCONTAINER_FT_MAP_HPP
#define MYCONTAINER_FT_MAP_HPP

#include "config.hpp"
#include "ft_avl_tree.hpp"
#include "ft_reverse_iterator.hpp"

namespace ft
{
	//Map Iterator
	
	template <typename T>
	class const_map_iterator;
	
	template <typename T>
	class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
	
	public:
		typedef ft::bidirectional_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::ptrdiff_t					difference_type;
		
	
	private:
		typedef typename avl_node<T>::node_ptr	node_ptr;
		node_ptr 								__node;
		
	public:
		
		map_iterator() : __node(ft_nullptr) {}
		
		map_iterator(const map_iterator& ref) : __node(ref._node) {}
		
		map_iterator(node_ptr node) : __node(node) {}
		
		~map_iterator() {}
		
		node_ptr base() const { return (__node); }
		
		map_iterator& operator=(const map_iterator& ref) {
			if (this != &ref)
				__node = ref.__node;
			return (*this);
		}
		
		reference operator*() const {
			return (__node->_value);
		}
		
		map_iterator &operator++() {
			__node = next_node<node_ptr>(__node);
			return *this;
		}
		
		map_iterator operator++(int) {
			map_iterator tmp = *this;
			__node = next_node<node_ptr>(__node);
			return tmp;
		}
		
		map_iterator &operator--() {
			__node = prev_node<node_ptr>(__node);
			return *this;
		}
		
		map_iterator operator--(int) {
			map_iterator tmp = *this;
			__node = prev_node<node_ptr>(__node);
			return tmp;
		}
		
		bool operator==(const map_iterator &iter) const {
			return (__node == iter.__node);
		}
		
		bool operator!=(const map_iterator &iter) const {
			return (__node != iter.__node);
		}
		
		bool operator==(const const_map_iterator<T>& ref) const {
			return (__node == ref.__node);
		}
		
		bool operator!=(const const_map_iterator<T>& ref) const {
			return (__node != ref.__node);
		}
		
		
	};
	//const Map Iterator
	
	template <typename T>
	class const_map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
	
	public:
		typedef ft::bidirectional_iterator_tag			iterator_category;
		typedef T 										value_type;
		typedef const T*								pointer;
		typedef const T& 								reference;
		typedef std::ptrdiff_t							difference_type;
		typedef map_iterator<T>							map_iterator;
		
	private:
		typedef typename avl_node<T>::const_node_ptr	node_ptr;
		node_ptr 										__node;
		
	public:
		const_map_iterator() : __node() {}
		
		const_map_iterator(node_ptr node) : __node(node) {}
		
		const_map_iterator(const map_iterator &ref) : __node(ref.__node) {}
		
		reference operator*() const {
			return (__node->_value);
		}
		
		pointer operator->() const {
			return (&(__node)->_value);
		}
		
		const_map_iterator &operator++() {
			__node = next_node<node_ptr>(__node);
			return (*this);
		}
		
		const_map_iterator operator++(int) {
			const_map_iterator tmp = *this;
			__node = next_node<node_ptr>(__node);
			return (tmp);
		}
		
		const_map_iterator &operator--() {
			__node = prev_node<node_ptr>(__node);
			return (*this);
		}
		
		const_map_iterator operator--(int) {
			const_map_iterator tmp = *this;
			__node = prev_node<node_ptr>(__node);
			return (tmp);
		}
		
		bool operator==(const const_map_iterator &iter) const {
			return (__node == iter._node);
		}
		
		bool operator!=(const const_map_iterator &iter) const {
			return (__node != iter._node);
		}
		
	};
	
	template <typename node_ptr>
	bool operator==(const map_iterator<node_ptr> &iter1, const const_map_iterator<node_ptr> &iter2) {
		return iter1.__node == iter2.__node;
	}
	
	template <typename node_ptr>
	bool operator!=(const map_iterator<node_ptr> &iter1, const const_map_iterator<node_ptr> &iter2) {
		return iter1.__node != iter2.__node;
	}
	
	//map
	template <	typename Key,
				typename T,
				typename Compare = ft::less<Key>,
				typename Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
	
	public:
		//typedefs
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef ft::pair<const key_type, mapped_type>			value_type;
		typedef Compare											key_compare;
		typedef Alloc											allocator_type;
		typedef size_t											size_type;
		typedef ptrdiff_t										difference_type;
		
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename ft::map_iterator<value_type>			iterator;
		typedef typename ft::const_map_iterator<value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		//=================
		
		//value_compare
		class value_compare : public ft::binary_function<value_type, value_type, bool> {
			friend class map;
		protected:
			Compare _comp;
			value_compare(Compare const& comp) : _comp(comp) {}
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator()(const value_type& x, const value_type& y) const {
				return _comp(x.first, y.first);
			}
		};
		//=================
		
	//member variables
	private:
		value_compare 													__comp;
		allocator_type 													__alloc;
		AvlTree<value_type, value_compare> 								__tree;
	//=================
	
	public:
	//constructors
		//default
		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type())
		: __comp(comp), __alloc(alloc), __tree(value_compare(__comp), __alloc)
		{}
	
		//range
		template <typename InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		: __comp(comp), __alloc(alloc), __tree(value_compare(__comp)) {
			this->insert(first, last);
		}
		
		//copy
		map(const map& other)
		: __comp(other.__comp), __alloc(other.__alloc), __tree(other.__tree)
		{}
		
		map& operator=(const map& other) {
			if (this != &other) {
				clear();
				insert(other.begin(), other.end());
			}
			return *this;
		}
	//==================
	
	//destructor
	
	~map() {}
	
	//==================
	
	//iterator
		
		iterator begin() { return __tree.begin(); }
		iterator end() { return __tree.end(); }
		const_iterator begin() const { return __tree.begin(); }
		const_iterator end() const { return __tree.end(); }
		reverse_iterator rbegin() { return __tree.rbegin(); }
		reverse_iterator rend() { return __tree.rend(); }
		const_reverse_iterator rbegin() const { return __tree.rbegin(); }
		const_reverse_iterator rend() const { return __tree.rend(); }
	
	//==================
	
	};
}

#endif //MYCONTAINER_FT_MAP_HPP