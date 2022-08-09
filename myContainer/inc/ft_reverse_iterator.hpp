//
// Created by jaewkim on 2022/07/18.
//

#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP
#include <vector>
#include "ft_iterator.hpp"

namespace ft {
	
	template<typename _Iter>
	class reverse_iterator {
	public:
		typedef _Iter	iterator_type;
		typedef typename	ft::iterator_traits<_Iter>::iterator_category	iterator_category;
		typedef typename	ft::iterator_traits<_Iter>::value_type			value_type;
		typedef typename	ft::iterator_traits<_Iter>::difference_type		difference_type;
		typedef typename	ft::iterator_traits<_Iter>::pointer				pointer;
		typedef typename	ft::iterator_traits<_Iter>::reference			reference;
		
	private:
		iterator_type	_iter;
		
	public:
		reverse_iterator() : _iter() {};
		explicit reverse_iterator(_Iter x) : _iter(x) {};
		template <typename _Up>
		reverse_iterator(const reverse_iterator<_Up>& ref)
			: _iter(ref.base())
		{ };
		reverse_iterator& operator=(const reverse_iterator& x) {
			_iter = x.base();
			return *this;
		};
		_Iter base() const {
			return _iter;
		};
		reference operator*() const {
			iterator_type tmp = _iter;
			return (*--tmp);
		};
		pointer operator->() const {
			return &(operator *());
		};
		reverse_iterator& operator++() {
			--_iter;
			return *this;
		};
		reverse_iterator operator++(int) {
			reverse_iterator tmp = *this;
			--_iter;
			return tmp;
		};
		reverse_iterator operator--() {
			++_iter;
			return *this;
		};
		reverse_iterator operator--(int) {
			reverse_iterator tmp = *this;
			++_iter;
			return tmp;
		};
		reverse_iterator operator+(difference_type __n) const {
			return reverse_iterator(_iter - __n);
		};
		reverse_iterator operator-(difference_type __n) const {
			return reverse_iterator(_iter + __n);
		};
		reverse_iterator operator+=(difference_type __n) {
			_iter -= __n;
			return *this;
		};
		reverse_iterator operator-=(difference_type __n) {
			_iter += __n;
			return *this;
		};
		reverse_iterator operator[](difference_type __n) const {
			return *(*this + __n);
		}
	};
}

#endif //FT_CONTAINERS_REVERSE_ITERATOR_HPP
