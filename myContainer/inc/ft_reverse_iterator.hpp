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
		typedef Iter														iterator_type;
		typedef typename	ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename	ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename	ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename	ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename	ft::iterator_traits<Iter>::reference			reference;
		
	private:
		iterator_type	__iter;
		
	public:
		reverse_iterator() : __iter(iterator_type()) {}
		explicit reverse_iterator(Iter x) : __iter(x) {}
		template <typename _Up>
		reverse_iterator(const reverse_iterator<_Up>& ref)
			: __iter(ref.base())
		{ }
		template <typename U>
		reverse_iterator& operator=(const reverse_iterator<U>& ref) {
			__iter = ref.base();
			return *this;
		}
		iterator_type base() const {
			return iterator_type(this->__iter);
		}
		reference operator*() const {
			iterator_type tmp = __iter;
			return (*--tmp);
		}
		pointer operator->() const {
			return &(operator *());
		}
		reverse_iterator& operator++() {
			--__iter;
			return *this;
		}
		reverse_iterator operator++(int) {
			reverse_iterator tmp = *this;
			--__iter;
			return tmp;
		}
		reverse_iterator operator--() {
			++__iter;
			return *this;
		}
		reverse_iterator operator--(int) {
			reverse_iterator tmp = *this;
			++__iter;
			return tmp;
		}
		reverse_iterator operator+(difference_type _n) const {
			return reverse_iterator(__iter - _n);
		}
		reverse_iterator operator-(difference_type _n) const {
			return reverse_iterator(__iter + _n);
		}
		reverse_iterator operator+=(difference_type _n) {
			__iter -= _n;
			return *this;
		}
		reverse_iterator operator-=(difference_type _n) {
			__iter += _n;
			return *this;
		}
		reference operator[](difference_type __n) {
			return *(*this + __n);
		}
		
		const reference operator[](difference_type __n) const {
			return *(*this + __n);
		}
	};
	
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
	{
		return rev_it + n;
	}
	
	template <class Iterator, class Iterator2>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return rhs.base() - lhs.base();
	}
	
	template <class Iterator, class Iterator2>
	bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() == rhs.base();
	}
	
	template <class Iterator, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() != rhs.base();
	}
	
	template <class Iterator, class Iterator2>
	bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() > rhs.base();
	}
	
	template <class Iterator, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() >= rhs.base();
	}
	
	template <class Iterator, class Iterator2>
	bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() < rhs.base();
	}
	
	template <class Iterator, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		return lhs.base() <= rhs.base();
	}
}

#endif //FT_CONTAINERS_REVERSE_ITERATOR_HPP
