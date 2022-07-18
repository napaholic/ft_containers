//
// Created by jaewkim on 2022/07/18.
//

#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP
#include <vector>
#include "iterator.hpp"

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
		{ }
		reverse_iterator operator=(const reverse_iterator& x)
		
		
	};
}

#endif //FT_CONTAINERS_REVERSE_ITERATOR_HPP
