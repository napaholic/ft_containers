//
// Created by jaewkim on 2022/07/14.
//

#ifndef FT_CONTAINERS_ITERATOR_TRAITS_HPP
#define FT_CONTAINERS_ITERATOR_TRAITS_HPP

#include "./iterator.hpp"
#include "config.hpp"

namespace ft {

	template<typename T>
	class random_access_iterator : public ft::iterator<random_access_iterator_tag, T> {
	public:
	//Member types
		typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category iterator_category;
		typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
		typedef typename ft::iterator<random_access_iterator_tag, T>::value_type 		value_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		
	private:
		pointer __ptr;
		
	public:
		
		random_access_iterator() : __ptr(ft_nullptr) {}
		
		random_access_iterator(const random_access_iterator& ref) : __ptr(ref.__ptr) {}
		
		random_access_iterator(pointer ptr) : __ptr(ptr) {}
		
		virtual ~random_access_iterator() {}
		
		random_access_iterator& operator=(const random_access_iterator& ref) {
			if (this != &ref)
				this->__ptr = ref.__ptr;
			return (*this);
		}
		pointer base() const {
			return (__ptr);
		}
		
		random_access_iterator&		operator+=(difference_type	n) {
			__ptr += n;
			return (*this);
		}
		
		random_access_iterator		operator+(difference_type	n) const {
			random_access_iterator __tmp = (*this);
			return (__tmp += n);
		}
		
		random_access_iterator		operator-=(difference_type	n) {
			__ptr -= n;
			return (*this);
		}
		
		random_access_iterator		operator-(difference_type	n) const {
			random_access_iterator	__tmp = (*this);
			return (__tmp -= n);
		}
		
		reference					operator[](difference_type	n) { return (__ptr[n]); }
		const reference 			operator[](difference_type	n) const { return (__ptr[n]); }
		
		template<typename U>
		random_access_iterator&		operator=(random_access_iterator<U> other) {
			__ptr = other.base();
			return (*this);
		}
		
		random_access_iterator&		operator--() {
			--__ptr;
			return (*this);
		}
		
		random_access_iterator		operator--(int) {
			random_access_iterator iter = (*this);
			--__ptr;
			return (iter);
		}
		
		random_access_iterator&		operator++() {
			++__ptr;
			return (*this);
		}
		
		random_access_iterator		operator++(int) {
			random_access_iterator tmp_iter = (*this);
			++__ptr;
			return (tmp_iter);
		}
		
		reference 					operator*() { return (*__ptr); }
		const reference 			operator*() const { return (*__ptr); }
		pointer						operator->() { return (__ptr); }
		
		operator random_access_iterator<const T> () const { return (random_access_iterator<const T>(this->__ptr)); }
		
	};
	
	template<typename T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T>& iterator) {
		random_access_iterator<T> iter = iterator;
		return (iter + n);
	}
	
	template<typename iter>
	typename ft::random_access_iterator<iter>:: difference_type  operator-(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) {
		return (lhs.base() - rhs.base());
	}
	
	template<typename iter1, typename iter2>
	typename ft::random_access_iterator<iter1>::difference_type operator-(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) {
		return (lhs.base() - rhs.base());
	}
	
	template<typename iter>
	bool	operator==(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (lhs.base() == rhs.base()); }
	
	template<typename iter>
	bool	operator!=(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (lhs.base() != rhs.base()); }
	
	template<typename iter>
	bool	operator<(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (lhs.base() < rhs.base()); }
	
	template<typename iter>
	bool	operator>(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return (rhs < lhs); }
	
	template<typename iter>
	bool	operator<=(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return !(rhs < lhs); }
	
	template<typename iter>
	bool	operator>=(const random_access_iterator<iter>& lhs, const random_access_iterator<iter>& rhs) { return !(lhs < rhs); }
	
	template<typename iter1, typename iter2>
	bool	operator==(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (lhs.base() == rhs.base()); }
	
	template<typename iter1, typename iter2>
	bool	operator!=(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (lhs.base() != rhs.base()); }
	
	template<typename iter1, typename iter2>
	bool	operator<(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (lhs.base() < rhs.base()); }
	
	template<typename iter1, typename iter2>
	bool	operator>(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return (rhs < lhs); }
	
	template<typename iter1, typename iter2>
	bool	operator<=(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return !(rhs < lhs); }
	
	template<typename iter1, typename iter2>
	bool	operator>=(const random_access_iterator<iter1>& lhs, const random_access_iterator<iter2>& rhs) { return !(lhs < rhs); }
	
}

#endif //FT_CONTAINERS_ITERATOR_TRAITS_HPP
