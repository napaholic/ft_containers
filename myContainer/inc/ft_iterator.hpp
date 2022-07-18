//
// Created by jaewkim on 2022/07/12.
//

#ifndef FT_CONTAINERS_FT_ITERATOR_H
#define FT_CONTAINERS_FT_ITERATOR_H

#include "./config.hpp"

namespace ft {
	
	struct input_iterator {};
	struct output_iterator {};
	struct forward_iterator : public input_iterator {};
	struct bidirectional_iterator : public forward_iterator {};
	struct random_access_iterator : public bidirectional_iterator {};
	
	//iterator =====================================
	template<class Category,
			class T,
			class Distance = ptrdiff_t,
			class Pointer = T *,
			class Reference = T &>
	struct iterator {
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};
	//iterator_tarits================================
	template <typename Iterator>
	struct iterator_traits {
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};
	
	template <typename T>
	struct iterator_traits<T*> {
		typedef random_access_iterator	iterator_category;
		typedef T						value_type;
		typedef ptrdiff_t				difference_type;
		typedef T*						pointer;
		typedef T&						reference;
	};
	
	template <typename T>
	struct iterator_traits<const T*> {
		typedef random_access_iterator	iterator_category;
		typedef T						value_type;
		typedef	ptrdiff_t				difference_type;
		typedef const T*				pointer;
		typedef const T&				reference;
	};
	
	
	
}

#endif //FT_CONTAINERS_FT_ITERATOR_H
