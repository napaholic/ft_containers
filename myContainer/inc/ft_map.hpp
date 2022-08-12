//
// Created by jaewkim on 2022/08/09.
//

#ifndef MYCONTAINER_FT_MAP_HPP
#define MYCONTAINER_FT_MAP_HPP

#include "config.hpp"

namespace ft
{
	//Map Iterator
	
	template <typename T>
	class map_const_iterator;
	
	template <typename T>
	class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
	
	public:
		typedef bidirectional_iterator_tag		iterator_category;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::ptrdiff_t					difference_type;
		
		typedef typename Node<T>::node_ptr node_ptr;
	
}

#endif //MYCONTAINER_FT_MAP_HPP