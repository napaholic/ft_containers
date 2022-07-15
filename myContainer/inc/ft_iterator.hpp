//
// Created by jaewkim on 2022/07/12.
//

#ifndef FT_CONTAINERS_FT_ITERATOR_H
#define FT_CONTAINERS_FT_ITERATOR_H

#include "./config.hpp"

namespace ft {
	
	template<class _Category,
			class _T,
			class _Distance = ptrdiff_t,
			class _Pointer = T *,
			class _Reference = T &>
	struct iterator {
		typedef _T value_type;
		typedef _Distance difference_type;
		typedef _Pointer pointer;
		typedef _Reference reference;
		typedef _Category iterator_category
	};
	
	template<class Iterator>
	class wrap_iterator {
	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
		typedef typename ft::iterator_traits
	};
	
}

#endif //FT_CONTAINERS_FT_ITERATOR_H
