//
// Created by jaewkim on 2022/07/14.
//

#ifndef FT_CONTAINERS_ITERATOR_TRAITS_HPP
#define FT_CONTAINERS_ITERATOR_TRAITS_HPP

#include "./ft_iterator.hpp"

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
		pointer _ptr;
		
	public:
		
		random_access_iterator() : _ptr(ft_nullptr) {}
		
		random_access_iterator(const random_access_iterator& ref) : _ptr(ref._ptr) {}
		
		random_access_iterator(pointer ptr) : _ptr(ptr) {}
		
		virtual ~random_access_iterator() {}
		
		random_access_iterator& operator=(const random_access_iterator& ref) {
			if (this != &ref)
				this->_ptr = ref._ptr;
			return (*this);
		}
	
	};
}

#endif //FT_CONTAINERS_ITERATOR_TRAITS_HPP
