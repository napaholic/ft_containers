//
// Created by jaewkim on 2022/07/18.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include "ft_random_access_iterator.hpp"
#include "ft_reverse_iterator.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
	public:
		//Member types===========================================================================
		typedef T													value_type;
		typedef Allocator											allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef typename allocator_type::size_type						size_type;
		typedef ft::random_access_iterator<value_type>					iterator;
		typedef ft::random_access_iterator<const value_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;

	protected:
		//Member variables=======================================================================
		pointer 		_start;
		pointer 		_end;
		pointer			_capacity;
		allocator_type	_alloc;

	public:
		//Constructors===========================================================================

		explicit vector(const allocator_type& alloc = allocator_type())
			: _start(ft_nullptr), _end(ft_nullptr), _capacity(ft_nullptr), _alloc(alloc)
		{}

		explicit vector(size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type())
			: _start(ft_nullptr), _end(ft_nullptr), _capacity(ft_nullptr), _alloc(alloc)
		{
			_start = _alloc.allocate(n);
			_end = _start;
			_capacity = _start + n;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_end++, value);
		}
	};
}

#endif //FT_CONTAINERS_VECTOR_HPP
