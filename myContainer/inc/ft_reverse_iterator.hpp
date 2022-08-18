//
// Created by jaewkim on 2022/07/18.
//

#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP
#include "iterator.hpp"

namespace ft {
	
	template<typename Iter>
	class reverse_iterator {
	public:
		typedef Iter	iterator_type;
		typedef typename	ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename	ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename	ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename	ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename	ft::iterator_traits<Iter>::reference			reference;
		
	private:
		iterator_type	__iter;
		
	public:
		reverse_iterator() : __iter() {};
		explicit reverse_iterator(Iter x) : __iter(x) {};
		template <typename _Up>
		reverse_iterator(const reverse_iterator<_Up>& ref)
			: __iter(ref.base())
		{ };
		reverse_iterator& operator=(const reverse_iterator& x) {
			__iter = x.base();
			return *this;
		};
		Iter base() const {
			return __iter;
		};
		reference operator*() const {
			iterator_type tmp = __iter;
			return (*--tmp);
		};
		pointer operator->() const {
			return &(operator *());
		};
		reverse_iterator& operator++() {
			--__iter;
			return *this;
		};
		reverse_iterator operator++(int) {
			reverse_iterator tmp = *this;
			--__iter;
			return tmp;
		};
		reverse_iterator operator--() {
			++__iter;
			return *this;
		};
		reverse_iterator operator--(int) {
			reverse_iterator tmp = *this;
			++__iter;
			return tmp;
		};
		reverse_iterator operator+(difference_type __n) const {
			return reverse_iterator(__iter - __n);
		};
		reverse_iterator operator-(difference_type __n) const {
			return reverse_iterator(__iter + __n);
		};
		reverse_iterator operator+=(difference_type __n) {
			__iter -= __n;
			return *this;
		};
		reverse_iterator operator-=(difference_type __n) {
			__iter += __n;
			return *this;
		};
		reverse_iterator operator[](difference_type __n) const {
			return *(*this + __n);
		}
	};
}

#endif //FT_CONTAINERS_REVERSE_ITERATOR_HPP
