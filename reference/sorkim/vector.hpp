#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <iostream>
#include "iterator"
#include "reverseIterator.hpp"
#include "utils.hpp"
#include <stdexcept>

namespace ft
{
	/*************************************************************************************
	*********************************** Vector Iterator **********************************
	**************************************************************************************/
	template <typename T>
	class vector_iterator
	{
	public:
		typedef typename iterator_traits<T *>::value_type 			value_type;
		typedef typename iterator_traits<T *>::difference_type 		difference_type;
		typedef typename iterator_traits<T *>::pointer 				pointer;
		typedef typename iterator_traits<T *>::reference 			reference;//const int&
		typedef typename iterator_traits<T *>::iterator_category	iterator_category;

		/*
		** ------------------------------- CONSTRUCTOR --------------------------------
		*/

		//default constructor
		vector_iterator() : _ptr(0) {}

		//copy constructor
		template <class Other>
		vector_iterator(const vector_iterator<Other> &src) : _ptr(src.get_ptr()) {}

		vector_iterator(const vector_iterator &src) : _ptr(src.get_ptr()) {}

		//initialization
		vector_iterator(pointer ptr) : _ptr(ptr) {}

		/*
		** ------------------------------- DESTRUCTOR --------------------------------
		*/

		//destructor
		~vector_iterator(){};

		/*
		** -------------------------- Assignment Operator -----------------------------
		*/

		//assignment operator overloading
		vector_iterator &operator=(const vector_iterator &src)
		{
			if (this != &src)
				this->_ptr = src.get_ptr();
			return *this;
		}

		/*
		** -------------------------------- Getter ---------------------------------
		*/

		pointer get_ptr() const
		{
			return this->_ptr;
		}

		/*
		** ------------------------------- Operators --------------------------------
		*/
	
		vector_iterator &operator++()
		{
			this->_ptr++;
			return *this;
		}

		vector_iterator operator++(int)
		{
			vector_iterator tmp(*this);
			this->_ptr++;
			return tmp;
		}

		vector_iterator &operator--()
		{
			this->_ptr--;
			return *this;
		}

		vector_iterator operator--(int)
		{
			vector_iterator tmp(*this);
			this->_ptr--;
			return tmp;
		}

		reference operator*() const
		{
			return *this->_ptr;
		}

		pointer operator->() const
		{
			return &(operator*()); 
		}

		reference operator[](difference_type n) const
		{
			return *(this->_ptr + n);
		}

		vector_iterator &operator+=(difference_type n)
		{
			this->_ptr += n;
			return *this;
		}

		vector_iterator operator+(difference_type n)
		{
			return vector_iterator(this->_ptr + n);
		}

		vector_iterator &operator-=(difference_type n)
		{
			this->_ptr -= n;
			return *this;
		}

		vector_iterator operator-(difference_type n)
		{
			return vector_iterator(this->_ptr - n);
		}

	private:
		pointer _ptr;
	};

	template <class A, class B>
	bool operator==(const vector_iterator<A> &lhs,
					const vector_iterator<B> &rhs)
	{
		return lhs.get_ptr() == rhs.get_ptr();
	}

	template <class A, class B>
	bool operator!=(const vector_iterator<A> &lhs,
					const vector_iterator<B> &rhs)
	{
		return !operator==(lhs, rhs);
	}

	template <class A, class B>
	bool operator<(const vector_iterator<A> &lhs,
				   const vector_iterator<B> &rhs)
	{
		return lhs.get_ptr() < rhs.get_ptr();
	}

	template <class A, class B>
	bool operator>(const vector_iterator<A> &lhs,
				   const vector_iterator<B> &rhs)
	{
		return operator<(rhs, lhs);
	}

	template <class A, class B>
	bool operator<=(const vector_iterator<A> &lhs,
					const vector_iterator<B> &rhs)
	{
		return !operator>(lhs, rhs);
	}

	template <class A, class B>
	bool operator>=(const vector_iterator<A> &lhs,
					const vector_iterator<B> &rhs)
	{
		return !operator<(lhs, rhs);
	}


	template <class T>
	vector_iterator<T> operator+(
		typename vector_iterator<T>::difference_type n,
		vector_iterator<T> iter)
	{
		return iter + n;
	}


	template <class A, class B>
	typename vector_iterator<A>::difference_type operator-(
		vector_iterator<A> lhs,
		vector_iterator<B> rhs)
	{
		return lhs.get_ptr() - rhs.get_ptr();
	}

	template <class T>
	vector_iterator<T> operator+(vector_iterator<T> lhs, typename vector_iterator<T>::difference_type rhs)
	{
		lhs += rhs;
		return lhs;
	}


	template <class T>
	vector_iterator<T> operator-(vector_iterator<T> lhs, typename vector_iterator<T>::difference_type rhs)
	{
		lhs -= rhs;
		return lhs;
	}

	/*************************************************************************************
	**************************************** Vector **************************************
	**************************************************************************************/

	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T 															value_type;
		typedef Alloc 														allocator_type;
		typedef typename allocator_type::reference 							reference;
		typedef typename allocator_type::const_reference 					const_reference;
		typedef typename allocator_type::pointer 							pointer;
		typedef typename allocator_type::const_pointer 						const_pointer;
		typedef typename allocator_type::size_type 							size_type;
		typedef ft::vector_iterator<value_type> 							iterator;
		typedef ft::vector_iterator<const value_type> 						const_iterator;
		typedef ft::reverse_iterator<iterator> 								reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> 						const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type 	difference_type;

	private:
		pointer 															_data;
		size_type 															_size;
		size_type															_capacity;
		allocator_type 														_alloc;

	public:
		/*
		** ------------------------------- CONSTRUCTOR --------------------------------
		*/
		// default
		explicit vector(const allocator_type &alloc = allocator_type())
		{
			this->_size = 0;
			this->_capacity = 0;
			this->_alloc = alloc;
			this->_data = 0;
		}

		// fill
		explicit vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
		{
			this->_size = n;
			this->_capacity = n;
			this->_alloc = alloc;
			this->_data = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(&this->_data[i], val);
		}

		// range
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
			   typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) : _alloc(alloc)
		{
			this->_size = 0;
			for (InputIterator it = first; it != last; it++)
				this->_size++;
			this->_capacity = this->_size;
			this->_alloc = alloc;
			this->_data = this->_alloc.allocate(this->_capacity);
			size_type i = 0;
			for (InputIterator it = first; it != last; it++)
			{
				this->_alloc.construct(&this->_data[i], *it);
				i++;
			}
		};

		// copy
		vector(const vector &x)
		{
			this->_size = x.size();
			this->_capacity = x.capacity();
			this->_alloc = x.get_allocator();
			this->_data = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(&this->_data[i], x._data[i]);
		}

		/*
		** ------------------------------- DESTRUCTOR --------------------------------
		*/

		~vector()
		{
			if (this->_data)
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_data[i]);
				this->_alloc.deallocate(this->_data, this->_capacity);
			}
		}

		/*
		** --------------------------------- operator= ---------------------------------
		*/

		vector &operator=(const vector &x)
		{
			if (this != &x)
			{
				if (this->_data)
				{
					for (size_type i = 0; i < this->_size; i++)
						this->_alloc.destroy(&this->_data[i]);
					this->_alloc.deallocate(this->_data, this->_capacity);
				}
				this->_size = x.size();
				this->_capacity = x.capacity();
				this->_data = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(&this->_data[i], x._data[i]);
			}
			return *this;
		}

		/*
		** --------------------------------- Iterators ---------------------------------
		*/

		iterator begin()
		{
			iterator it(this->_data);
			return it;
		}

		const_iterator begin() const
		{
			const_iterator it(this->_data);
			return it;
		}

		iterator end()
		{
			if (this->empty())
				return this->begin();
			iterator it(&this->_data[this->size()]);
			return it;
		}

		const_iterator end() const
		{
			if (this->empty())
				return this->begin();
			const_iterator it(&this->_data[this->size()]);
			return it;
		}

		reverse_iterator rbegin()
		{
			reverse_iterator it(this->end());
			return it;
		}

		const_reverse_iterator rbegin() const
		{
			const_reverse_iterator it(this->end());
			return it;
		}

		reverse_iterator rend()
		{
			reverse_iterator it(this->begin());
			return it;
		}

		const_reverse_iterator rend() const
		{
			const_reverse_iterator it(this->begin());
			return it;
		}

		/*
		** --------------------------------- Capacity ---------------------------------
		*/

		size_type size() const
		{
			return this->_size;
		}

		size_type max_size() const
		{
			return this->_alloc.max_size();
		}

		size_type capacity() const
		{
			return this->_capacity;
		}

		bool empty() const
		{
			return this->_size == 0 ? true : false;
		}

		void reserve(size_type n)
		{
			pointer new_data;

			if (n <= this->_capacity)
				return;
			if (n > this->max_size())
				throw std::length_error("vector");
			new_data = this->_alloc.allocate(n);
			if (this->_data)
			{
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(&new_data[i], this->_data[i]);
					this->_alloc.destroy(&this->_data[i]);
				}
				this->_alloc.deallocate(this->_data, this->_capacity);
			}
			this->_capacity = n;
			this->_data = new_data;
		}

		void resize(size_type n, value_type val = value_type())
		{
			for (size_type i = n; i < this->_size; i++)
				this->_alloc.destroy(&this->_data[i]);
			if (n > this->_capacity)
				this->reserve(n);
			for (size_type i = this->_size; i < n; i++)
				this->_alloc.construct(&this->_data[i], val);
			this->_size = n;
		}

		/*
		** --------------------------------- Element access ---------------------------------
		*/
		// reference by original, value by copy
		// return const = not change value -> to prevent side effect by concurrency
		// const function = not change a member variable of the class

		reference operator[](size_type n)
		{
			return this->_data[n];
		}

		const_reference operator[](size_type n) const
		{
			return this->_data[n];
		}

		reference at(size_type n)
		{
			if (n >= this->_size)
				throw std::out_of_range("vector");
			return this->_data[n];
		}

		const_reference at(size_type n) const
		{
			if (n >= this->_size)
				throw std::out_of_range("vector");
			return this->_data[n];
		}

		reference front()
		{
			return this->_data[0];
		}

		const_reference front() const
		{
			return this->_data[0];
		}

		reference back()
		{
			return this->_data[this->_size - 1];
		}

		const_reference back() const
		{
			return this->_data[this->_size - 1];
		}

		/*
		** --------------------------------- Modifiers ---------------------------------
		*/

		//[1] assign
		// range
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			size_type new_size = 0;

			for (InputIterator it = first; it != last; it++)
				new_size++;
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(&this->_data[i]);
			if (new_size > this->_capacity)
				this->reserve(new_size);
			size_type i = 0;
			for (InputIterator it = first; it != last; it++)
			{
				this->_alloc.construct(&this->_data[i], *it);
				i++;
			}
			this->_size = new_size;
		}

		// fill
		void assign(size_type n, const value_type &val)
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(&this->_data[i]);
			if (n > this->_capacity)
				this->reserve(n);
			for (size_type i = 0; i < n; i++)
				this->_alloc.construct(&this->_data[i], val);
			this->_size = n;
		}

		//[2] push_back
		void push_back(const value_type &val)
		{
			if (this->_capacity == 0)
				this->reserve(1);
			else if (this->_size == this->_capacity)
				this->reserve(this->_capacity * 2);
			this->_alloc.construct(&this->_data[this->_size], val);
			this->_size++;
		}

		//[3] pop_back
		void pop_back()
		{
			this->_alloc.destroy(&this->_data[this->_size - 1]);
			this->_size--;
		}
	

		//[4] insert
		// single element
		iterator insert(iterator position, const value_type &val)
		{
			pointer new_data;
			pointer tmp;
			size_type tmp_size = 0;
			size_type i;
			size_type new_capacity;

			if (position == this->end())
			{
				this->push_back(val);
				position = this->end() - 1;
			}
			else
			{
				for (iterator it = position; it != this->end(); it++)
					tmp_size++;
				tmp = this->_alloc.allocate(tmp_size);
				i = 0;
				for (iterator it = position; it != this->end(); it++)
				{
					this->_alloc.construct(&tmp[i], *it);
					this->_alloc.destroy(&*it);
					i++;
				}
				// reallocation
				if (this->_size == this->_capacity)
				{
					new_capacity = this->_capacity * 2;
					// if (new_capacity > this->max_size())
					// 	throw std::length_error("vector");
					new_data = this->_alloc.allocate(new_capacity);
					if (this->_data)
					{
						i = 0;
						for (iterator it = this->begin(); it != position; it++)
						{
							this->_alloc.construct(&new_data[i], *it);
							this->_alloc.destroy(&*it);
							i++;
						}
						this->_alloc.deallocate(this->_data, this->_capacity);
					}
					this->_capacity = new_capacity;
					this->_data = new_data;
					position = iterator(&this->_data[i]);
				}
				// insert
				this->_alloc.construct(&*position, val);
				this->_size++;
				// copy after insert
				i = 0;
				for (iterator it = position + 1; it != this->end(); it++)
				{
					this->_alloc.construct(&*it, tmp[i]);
					i++;
				}
				// free
				for (i = 0; i < tmp_size; i++)
					this->_alloc.destroy(&tmp[i]);
				this->_alloc.deallocate(tmp, tmp_size);
			}
			return position;
		}

		// fill
		void insert(iterator position, size_type n, const value_type &val)
		{
			pointer new_data;
			pointer tmp;
			iterator it;
			size_type tmp_size = 0;
			size_type i;
			size_type new_capacity;

			if (position == this->end())
			{
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
				return;
			}
			for (iterator it = position; it != this->end(); it++)
				tmp_size++;
			tmp = this->_alloc.allocate(tmp_size);
			i = 0;
			for (iterator it = position; it != this->end(); it++)
			{
				this->_alloc.construct(&tmp[i], *it);
				this->_alloc.destroy(&*it);
				i++;
			}
			// reallocation
			if ((this->_size + n) > this->_capacity)
			{
				if ((this->_size + n) > (this->_capacity * 2))
					new_capacity = this->_size + n;
				else
					new_capacity = this->_capacity * 2;
				// if (new_capacity > this->max_size())
				// 	throw std::length_error("vector");
				new_data = this->_alloc.allocate(new_capacity);
				if (this->_data)
				{
					i = 0;
					for (iterator it = this->begin(); it != position; it++)
					{
						this->_alloc.construct(&new_data[i], *it);
						this->_alloc.destroy(&*it);
						i++;
					}
					this->_alloc.deallocate(this->_data, this->_capacity);
				}
				this->_capacity = new_capacity;
				this->_data = new_data;
				position = iterator(&this->_data[i]);
			}
			// insert
			it = position;
			for (i = 0; i < n; i++)
			{
				this->_alloc.construct(&*it, val);
				this->_size++;
				it++;
			}
			// copy after insert
			i = 0;
			for (it = position + n; it != this->end(); it++)
			{
				this->_alloc.construct(&*it, tmp[i]);
				i++;
			}
			// free
			for (i = 0; i < tmp_size; i++)
				this->_alloc.destroy(&tmp[i]);
			this->_alloc.deallocate(tmp, tmp_size);
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			pointer new_data;
			pointer tmp;
			iterator it;
			size_type tmp_size = 0;
			size_type i;
			size_type new_capacity;
			size_type range = 0;

			if (position == this->end())
			{
				for (InputIterator it = first; it != last; it++)
					this->push_back(*it);
				return;
			}
			for (InputIterator it = first; it != last; it++)
				range++;
			for (iterator it = position; it != this->end(); it++)
				tmp_size++;
			tmp = this->_alloc.allocate(tmp_size);
			i = 0;
			for (iterator it = position; it != this->end(); it++)
			{
				this->_alloc.construct(&tmp[i], *it);
				this->_alloc.destroy(&*it);
				i++;
			}
			// reallocation
			if ((this->_size + range) > this->_capacity)
			{
				if ((this->_size + range) > (this->_capacity * 2))
					new_capacity = this->_size + range;
				else
					new_capacity = this->_capacity * 2;
				// if (new_capacity > this->max_size())
				// 	throw std::length_error("vector");
				new_data = this->_alloc.allocate(new_capacity);
				if (this->_data)
				{
					i = 0;
					for (iterator it = this->begin(); it != position; it++)
					{
						this->_alloc.construct(&new_data[i], *it);
						this->_alloc.destroy(&*it);
						i++;
					}
					this->_alloc.deallocate(this->_data, this->_capacity);
				}
				this->_capacity = new_capacity;
				this->_data = new_data;
				position = iterator(&this->_data[i]);
			}
			// insert
			it = position;
			for (InputIterator range = first; range != last; range++)
			{
				this->_alloc.construct(&*it, *range);
				this->_size++;
				it++;
			}
			// copy after insert
			i = 0;
			for (it = position + range; it != this->end(); it++)
			{
				this->_alloc.construct(&*it, tmp[i]);
				i++;
			}
			// free
			for (i = 0; i < tmp_size; i++)
				this->_alloc.destroy(&tmp[i]);
			this->_alloc.deallocate(tmp, tmp_size);
		}

		// template <class InputIterator> // error if first is not position
    	// void insert (iterator position, InputIterator first, InputIterator last,
		// 	typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0){
		// 		size_type pos = position - begin(); // Posi of elemen
		// 		size_type n = last - first;

		// 		if (!this->_size)
		// 			reserve(n);
		// 		else if ((n + size()) > capacity()){
		// 			if ((n + size()) <= (capacity() * 2))
		// 				reserve(capacity() * 2);
		// 			else
		// 				reserve(n + size());
		// 		}
		// 		for (size_type i = pos; i < size(); i++)
		// 			this->_alloc.construct(this->_data + i + n, (*this)[i]);
		// 		this->_size += n;
		// 		for (size_type i = 0; i < n; i++)
		// 			this->_alloc.construct(this->_data + pos + i, *(first++)); // insert elements
		// }

		//[5] erase
		// position

		iterator erase (iterator position){
			difference_type pos = position.get_ptr() - this->_data; // Posi of element

			this->_size--;
			this->_alloc.destroy(this->_data + pos); // delete element
			for (size_type i = pos; i < size() + 1; i++) // Relocate elements
				this->_alloc.construct(this->_data + i, (*this)[i + 1]);
			this->_alloc.destroy(this->_data + size());
			return (iterator(this->_data + pos));
		}

		// range
		iterator erase(iterator first, iterator last)
		{
			size_type pos = first.get_ptr() - this->_data ; // Posi of element
			size_type n = last - first;

			// std::cout << "pos = " << pos << " | n = " << n << std::endl;
			for (size_type i = pos; i < pos + n; i++)			// delete elements
				this->_alloc.destroy(this->_data + i); 
			for (size_type i = pos; (i + n) < size() ; i++) 	//  Relocate elements
				this->_alloc.construct(this->_data + i, (*this)[i + n]);
			for (size_type i = size() - n; i < size(); i++)	// destroy empty storage;
				this->_alloc.destroy(this->_data + i); 
			this->_size -= n;
			return (iterator(this->_data + pos));
		}

		void swap(vector &x)
		{
			pointer tmp_data = this->_data;
			size_type tmp_size = this->_size;
			size_type tmp_capacity = this->_capacity;

			this->_data = x._data;
			this->_size = x._size;
			this->_capacity = x._capacity;

			x._data = tmp_data;
			x._size = tmp_size;
			x._capacity = tmp_capacity;
		}

		void clear()
		{
			while (this->_size != 0)
			{
				this->_alloc.destroy(&this->_data[this->_size - 1]);
				this->_size--;
			}
		}

		/*
		** --------------------------------- Allocator ---------------------------------
		*/

		allocator_type get_allocator() const
		{
			return this->_alloc;
		}
	};

	/*
	** --------------------------------- Non-member function overloads ---------------------------------
	*/

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
		{
			return false;
		}
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	};

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	};

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
										   rhs.end());
	};

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	};

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	};

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	};
}

#endif