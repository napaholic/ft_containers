//
// Created by jaewkim on 2022/08/09.
//

#ifndef MYCONTAINER_MAP_HPP
#define MYCONTAINER_MAP_HPP

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
		
		map_iterator(const map_iterator& ref) : __node(ref.__node) {}
		
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
		typedef typename ft::const_map_iterator<value_type>		const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef typename AvlTree<value_type, Compare>::node_ptr	node_ptr;
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
		: __comp(comp), __alloc(alloc), __tree(value_compare(__comp))
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
		
		iterator begin() {
			if (__tree.get_min_node() == ft_nullptr)
				return iterator(__tree.get_end_node());
			return iterator(__tree.get_min_node());
		}
		
		const_iterator begin() const {
			if (__tree.get_min_node() == ft_nullptr)
				return const_iterator(__tree.get_end_node());
			return const_iterator(__tree.get_min_node());
		}
		
		iterator end() {
			return iterator(__tree.get_end_node());
		}
		
		const_iterator end() const {
			return const_iterator(--__tree.get_end_node());
		}
		
		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}
		
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(end());
		}
		
		reverse_iterator rend() {
			return reverse_iterator(begin());
		}
		
		const_reverse_iterator rend() const {
			return const_reverse_iterator(begin());
		}
	
	//==================
	
	//capacity
		
		bool empty() const {
			return __tree.is_empty();
		}
		
		size_type size() const {
			return __tree.get_size();
		}
		
		size_type max_size() const {
			return __tree.get_max_size();
		}
	
	//==================
	
	//element access
		
		mapped_type &operator[](const key_type &k)
		{
			return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
		}
		
	//==================
	
	//modifiers
	
	//insert
		pair<iterator, bool> insert(const value_type &val) {
		 node_ptr found = __tree.find(val);
		 
		 if (found == __tree.get_end_node()) {
			 __tree.insert(val);
			 return ft::make_pair(iterator(__tree.find(val)), true);
		 }
		 return ft::make_pair(iterator(found), false);
		}
		
		iterator insert(iterator position, const value_type &val)
		{
			node_ptr found = __tree.find(val);
			
			if (found == __tree.get_end_node()) {
				insert(val);
				return iterator(__tree.find(val));
			}
			return iterator(found);
			position++;
		}
		
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last) {
			while (first != last) {
				insert(ft::make_pair((*first).first, (*first).second));
				first++;
			}
		}
	
	//==================
	
	//erase
		void erase(iterator position) {
			if (position.base() != ft_nullptr)
				__tree.erase(*position);
		}//ft::make_pair(position->first, position->second)
		
		size_type erase(const key_type &key) {
			if (__tree.find(ft::make_pair(key, mapped_type())) == __tree.get_end_node())
				return 0;
			__tree.erase(ft::make_pair(key, mapped_type()));
			return 1;
		}
		
		void erase(iterator first, iterator last) {
			while (first != last)
				erase(first++);
		}
		
		//swap
		void swap(map &x) {
			__tree.swap(x.__tree);
		}
		
		//clear
		void clear() {
			__tree.clear();
		}
		
		//observers
		key_compare key_comp() const {
			return key_compare();
		}
		
		value_compare value_comp() const {
			return value_compare(__comp);
		}
		
		//find
		iterator find(const key_type &key) {
			return __tree.find(ft::make_pair(key, mapped_type()));
		}
		
		const_iterator find(const key_type &key) const {
			return __tree.find(ft::make_pair(key, mapped_type()));
		}
		
		//count
		size_type count(const key_type &key) const {
			if (__tree.find(ft::make_pair(key, mapped_type())) == __tree.get_end_node())
				return 0;
			return 1;
		}
		
		//bounds
		iterator lower_bound(const key_type &key) {
			value_type val = ft::make_pair(key, mapped_type());
			node_ptr cur = __tree.find_min_node(__tree.get_root_node());
			
			while (cur && cur != __tree.get_end_node()) {
				if (!__comp(cur->_value, key))
					return iterator(cur);
				cur = next_node(cur);
			}
			return iterator(__tree.get_end_node());
		}
		
		const_iterator lower_bound(const key_type &key) const {
			value_type val = ft::make_pair(key, mapped_type());
			node_ptr cur = __tree.find_min_node(__tree.get_root_node());
			
			while (cur && cur != __tree.get_end_node()) {
				if (!__comp(cur->_value, key))
					return const_iterator(cur);
				cur = next_node(cur);
			}
			return const_iterator(__tree.get_end_node());
		}
		
		iterator upper_bound(const key_type &key) {
			value_type val = ft::make_pair(key, mapped_type());
			node_ptr cur = __tree.find_min_node(__tree.get_root_node());
			
			while (cur && cur != __tree.get_end_node()) {
				if (__comp(cur->_value, key))
					return iterator(cur);
				cur = next_node(cur);
			}
			return iterator(__tree.get_end_node());
		}
		
		const_iterator upper_bound(const key_type &key) const {
			value_type val = ft::make_pair(key, mapped_type());
			node_ptr cur = __tree.find_min_node(__tree.get_root_node());
			
			while (cur && cur != __tree.get_end_node()) {
				if (__comp(cur->_value, key))
					return const_iterator(cur);
				cur = next_node(cur);
			}
			return const_iterator(__tree.get_end_node());
		}
	
		//range
		pair<iterator, iterator> equal_range(const key_type& key) {
			iterator it1 = this->lower_bound(key);
			iterator it2 = this->upper_bound(key);
			return ft::make_pair(it1, it2);
		}
		
		pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
			const_iterator it1 = this->lower_bound(key);
			const_iterator it2 = this->upper_bound(key);
			return ft::make_pair(it1, it2);
		}
		
		allocator_type get_allocator() const {
			return allocator_type();
		}
	};
	
	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
		x.swap(y);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return !(lhs == rhs);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return !(rhs < lhs);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return rhs < lhs;
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return !(lhs < rhs);
	}
}

#endif //MYCONTAINER_MAP_HPP