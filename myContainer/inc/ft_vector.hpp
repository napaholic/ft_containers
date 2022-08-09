//
// Created by jaewkim on 2022/07/18.
//

#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include "ft_random_access_iterator.hpp"
#include "ft_reverse_iterator.hpp"
#include "config.hpp"
#include <vector>

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
	
	public:
		//Member types===========================================================================
		typedef T														value_type;
		typedef Allocator												allocator_type;
		typedef typename allocator_type::reference						reference;
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
		// Member variables=======================================================================
		pointer 		_start;
		pointer 		_end;
		pointer			_capacity;
		allocator_type	_alloc;

	public:
		// Constructors===========================================================================

		explicit vector(const allocator_type& alloc = allocator_type())
			: _start(ft_nullptr), _end(ft_nullptr), _capacity(ft_nullptr), _alloc(alloc)
		{}

		explicit vector(size_type n, const value_type& value = value_type(),
						const allocator_type& alloc = allocator_type())
			: _start(ft_nullptr), _end(ft_nullptr), _capacity(ft_nullptr), _alloc(alloc)
		{
			_start = _alloc.allocate(n);
			_end = _start;
			_capacity = _start + n;
			for (size_type i = 0; i < n; i++)
				_alloc.construct(_end++, value);
		}
		
		template <typename InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			   typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = ft_nullptr)
			   : _alloc(alloc)
		{
			size_type n = ft::distance(first, last);
			_start = _alloc.allocate(n);
			_end = _start;
			_capacity = _start + n;
			while (n--) {
				_alloc.construct(_end++, *first);
				++first;
			}
		}
		
		vector(const vector& other) : _start(ft_nullptr), _end(ft_nullptr), _capacity(ft_nullptr), _alloc(ft_nullptr)
		{
			size_type n = other.size();
			_start = _alloc.allocate(n);
			_end = _start;
			_capacity = _start + n;
			pointer p = other._start;
			while (n--) {
				_alloc.construct(_end++, *p);
				++p;
			}
		}
		
		vector& operator=(const vector& other) {
			if (this != &other) {
				this->clear();
				insert(_start, other, other.begin(), other.end());
			}
			return (*this);
		}
		
		~vector() {
			this->clear();
			_alloc.deallocate(_start, this->capacity());
		}
		
		// Iterator
		iterator				begin() { return (_start); }
		const_iterator			begin() const { return (_start); }
		iterator				end() { return (_end); }
		const_iterator			end() const	{ return (_end); }
		reverse_iterator		rbegin() { return (reverse_iterator(_end)); }
		const_reverse_iterator	rbegin() const { return (reverse_iterator(_end)); }
		reverse_iterator		rend() { return (reverse_iterator(_start)); }
		const_reverse_iterator	rend() const { return (reverse_iterator(_start)); }
		
		// Capacity
		bool		empty() const { return (_start == _end); }
		size_type	size() const { return (_end - _start); }
		size_type	max_size() const { return (_alloc.max_size()); }
		size_type	capacity() const { return (_capacity - _start); }
		void		reserve(size_type n) { //need to complete
			if (n > this->max_size())
				throw std::length_error("ft::vector::reserve: n > max_size()");
			if (n > this->capacity()) {
				pointer prev_start = _start;
				pointer prev_end = _end;
				size_type prev_capa = this->capacity();
				size_type prev_size = this->size();
				
				_start = _alloc.allocate(n);
				_end = _start;
				_capacity = _start + n;
				while (prev_start != prev_end)
				{
					_alloc.construct(_end, *prev_start);
					_end++;
					prev_start++;
				}
				_alloc.deallocate(prev_start - prev_size, prev_capa);
			}
		}
		
		void		resize(size_type n, value_type val = value_type()) {
			if (n > this->max_size())
				throw std::length_error("ft::vector::resize: n > _alloc.max_size()");
			if (this->size() == n)
				return;
			if (n < this->size()) {
				while (this->size() != n)
					pop_back();
			} else {
				if (this->capacity() * 2 < n)
					reserve(n);
				while (this->size() != n)
					push_back(val);
			}
		}
		
		// Element Access
		
		reference			operator[](size_type n) { return (_start[n]); }
		const_reference		operator[](size_type n) const { return (_start[n]); }
		reference			at(size_type n) {
			if (n >= this->size())
				throw std::out_of_range("ft::vector::at : size overflow");
			return ((*this)[n]);
		}
		const_reference		at(size_type n) const {
			if (n >= this->size())
				throw std::out_of_range("ft::vector::at : size overflow");
			return ((*this)[n]);
		}
		reference			front() { return (*_start); }
		const_reference		front() const { return (*_start); }
		reference			back() { return (*(_end - 1)); }
		const_reference		back() const { return (*(_end - 1)); }
		
		// Modifiers
		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last,
					   typename ft::enable_if<!ft::is_integral<InputIterator>::value,
							   InputIterator>::type* = ft_nullptr) {
			this->clear();
			size_type size = ft::distance(first, last);
			if (size <= this->capacity()) {
				while (&*first != &*last)
					_alloc.construct(_end++, *first);
			} else {
				this->reserve(size);
				while (&*first != &*last)
					_alloc.construct(_end++, *first);
			}
		}
		
		void assign(size_type n, const value_type& val) {
			this->clear();
			if (this->capacity() < n) {
				this->reserve(n);
				while (n--)
					_alloc.construct(_end++, val);
			} else {
				while (n--)
					_alloc.construct(_end++, val);
			}
		}
		
		iterator insert(iterator position, const value_type& val) {
			size_type	pos = &*position - _start;
			size_type	rpos = _end - &*position;
			
			if (this->size() == 0)
				this->reserve(1);
			else if (_end == _capacity)
				this->reserve(2 * this->size());
			for (size_type i = 0; i < rpos; i++) {
				_alloc.construct(_end - i, *(_end - i - 1));
				_alloc.destroy(_end - i - 1);
			}
			_alloc.construct(_start + pos, val);
			_end++;
			return (iterator(_start + pos));
		}
		
		void insert(iterator position, size_type n, const value_type& val) {
			if (position > this->end() || position < this->begin())
				return;
			
			size_type	next_size = this->size() + n;
			size_type	pos = &*position - _start;
			size_type	prev_capa = this->capacity();
			size_type	alloced_size = 0;
			pointer		new_start = ft_nullptr;
			pointer		prev_capa_end = _capacity;
			
			if (this->max_size() < next_size)
				throw std::length_error("ft::vector::insert: max_size() < this->size() + n");
			if (this->capacity() < next_size) {
				new_start = _alloc.allocate(next_size);
				_capacity = new_start + next_size;
				alloced_size = next_size;
			} else {
				new_start = _alloc.allocate(this->capacity() * 2);
				_capacity = new_start + this->capacity() * 2;
				alloced_size = this->capacity() * 2;
			}
			try {
				for (size_type i = 0; i < pos; ++i)
					_alloc.construct(new_start + i, *(_start + i));
				for (size_type i = 0; i < n; ++i)
					_alloc.construct(new_start + pos + i, val);
				for (size_type i = 0; i < this->size() - pos; ++i)
					_alloc.construct(new_start + pos + n + i, *(_start + pos + i));
			} catch(std::exception &e) {
				for (size_type i = 0; i < pos; ++i)
					_alloc.destroy(new_start + i);
				for (size_type i = 0; i < n; ++i)
					_alloc.destroy(new_start + pos + i);
				for (size_type i = 0; i < this->size() - pos; ++i)
					_alloc.destroy(new_start + pos + n + i);
				_alloc.deallocate(new_start, alloced_size);
				_capacity = prev_capa_end;
				throw e;
			}
			
			for (size_type i = 0; i < this->size(); ++i)
				_alloc.destroy(_start + i);
			_alloc.deallocate(_start, prev_capa);
			_end = new_start + n + this->size();
			_start = new_start;
		}
		
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = ft_nullptr) {
			if (position > this->end() || position < this->begin())
				return;
			
			size_type	num = ft::distance(first, last);
			size_type	next_size = this->size() + num;
			size_type	prev_capa = this->capacity();
			size_type	pos = &*position - _start;
			size_type	alloced_size = 0;
			pointer		new_start = ft_nullptr;
			pointer		prev_capa_ptr = _capacity;
			
			if (this->max_size() < next_size)
				throw std::length_error("ft::vector::insert: max_size() < this->size() + n");
			if (this->capacity() * 2 < next_size) {
				new_start = _alloc.allocate(next_size);
				_capacity = new_start + next_size;
				alloced_size = next_size;
			} else {
				new_start = _alloc.allocate(this->capacity() * 2);
				_capacity = new_start + this->capacity() * 2;
				alloced_size = this->capacity() * 2;
			}
			try {
				for (size_type i = 0; i < pos; ++i)
					_alloc.construct(new_start + i, *(_start + i));
				for (size_type i = 0; i < num; ++i)
					_alloc.construct(new_start + pos + i, *(&*first++));
				for (size_type i = 0; i < this->size() - pos; ++i)
					_alloc.construct(new_start + pos + num + i, *(_start + pos + i));
			} catch(std::exception &e) {
				for (size_type i = 0; i < pos; ++i)
					_alloc.destroy(new_start + i);
				for (size_type i = 0; i < num; ++i)
					_alloc.destroy(new_start + pos + i);
				for (size_type i = 0; i < this->size() - pos; ++i)
					_alloc.destroy(new_start + pos + num + i);
				_alloc.deallocate(new_start, alloced_size);
				_capacity = prev_capa_ptr;
				throw e;
			}
			for (size_type i = 0; i < this->size(); ++i)
				_alloc.destroy(_start + i);
			_alloc.deallocate(_start, prev_capa);
			_end = new_start + num + this->size();
			_start = new_start;
		}
		
		void push_back(const value_type& val) {
			if (_end == _capacity) {
				this->reserve((this->size + 2) * 2);
			}
			_alloc.construct(_end, val);
			_end++;
		}
		
		void pop_back() {
			if (this->size() != 0) {
				_alloc.destroy(--_end);
			}
		}
		
		iterator erase(iterator pos) {
			return (this->erase(pos, pos + 1));
		}
		
		iterator erase(iterator first, iterator last) {
			pointer prev_first = &(*first); //포인터에 레퍼런스대입?? alloc 형변환때문!
			for (; &(*first) != &(*last); first++)
				_alloc.destroy(&(*first));
			for (int i = 0; i < _end - &(*last); i++) {
				_alloc.construct(prev_first + i, *(&(*last) + i));
				_alloc.destroy(&(*last) + i);
			}
			_end -= (&(*last) - prev_first);
			return (iterator(prev_first));
		}
		
		void swap(vector& other) {
			pointer			tmp_start = _start;
			pointer			tmp_end = _end;
			pointer			tmp_capacity = _capacity;
			allocator_type	tmp_alloc = _alloc;
			
			_start = other._start;
			_end = other._end;
			_capacity = other._capacity;
			_alloc = other._alloc;
			
			other._start = tmp_start;
			other._end = tmp_end;
			other._capa_end = tmp_capacity;
			other._alloc = tmp_alloc;
		}
		
		void clear() {
			while (_start != _end) {
				_alloc.destroy(--_end);
			}
		}
		
		// Allocator
		
		allocator_type get_allocator() const {
			return allocator_type();
		}
	};
	
	//relational operators
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		typename ft::vector<T>::const_iterator first1 = lhs.begin();
		typename ft::vector<T>::const_iterator first2 = rhs.begin();
		
		while (first1 != lhs.end()) {
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return (true);
	}
	
	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs == rhs); }
	
	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(),rhs.begin(), rhs.end());
	}
	
	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(rhs < lhs); }
	
	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs); }
	
	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs < rhs); }
}

#endif //FT_CONTAINERS_VECTOR_HPP
