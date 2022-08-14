//
// Created by jaewkim on 2022/07/14.
//

#ifndef FT_CONTAINERS_CONFIG_HPP
#define FT_CONTAINERS_CONFIG_HPP
#include <cstddef>
#include <functional>
#include <iostream>
#include <memory>
#include "ft_iterator.hpp"

namespace ft {
	
	//enable_if
	
	template <bool cond, typename T = void>
	struct enable_if {};
	
	template <typename T>
	struct enable_if<true, T> {
		typedef T type;
	};
	
	// is_integral
	
	template<bool is_integral, typename T>
	struct is_integral_base {
		typedef T type;
		const static bool value = is_integral;
	};
	
	template<typename>
	struct is_integral : public is_integral_base<false, void> {
	};
	
	template<>
	struct is_integral<bool> : public is_integral_base<true, bool> {
	};
	
	template<>
	struct is_integral<char> : public is_integral_base<true, char> {
	};
	
	template<>
	struct is_integral<signed char> : public is_integral_base<true, signed char> {
	};
	
	template<>
	struct is_integral<short> : public is_integral_base<true, short> {
	};
	
	template<>
	struct is_integral<unsigned short> : public is_integral_base<true, unsigned short> {
	};
	
	template<>
	struct is_integral<int> : public is_integral_base<true, int> {
	};
	
	template<>
	struct is_integral<unsigned int> : public is_integral_base<true, unsigned int> {
	};
	
	template<>
	struct is_integral<long> : public is_integral_base<true, long> {
	};
	
	template<>
	struct is_integral<unsigned long> : public is_integral_base<true, unsigned long> {
	};
	
	template<>
	struct is_integral<long long> : public is_integral_base<true, long long> {
	};
	
	template<>
	struct is_integral<unsigned long long> : public is_integral_base<true, unsigned long long> {
	};
	
	template<>
	struct is_integral<wchar_t> : public is_integral_base<true, wchar_t> {
	};
	
	template<>
	struct is_integral<char16_t> : public is_integral_base<true, char16_t> {
	};
	
	template<>
	struct is_integral<char32_t> : public is_integral_base<true, char32_t> {
	};

	// distance
	
	template <typename InputIt>
	typename ft::iterator_traits <InputIt>::difference_type distance(InputIt first, InputIt last) {
		typename ft::iterator_traits<InputIt>::difference_type n = 0;
		while (first != last) {
			++first;
			++n;
		}
		return n;
	}

	// ft_nullptr
	
	const class {
	public:
		template<class T>
		operator T *() const { return 0; }
		
		template<class C, class T>
		operator T C::*() const { return 0; }
	
	private:
		void operator&() const;
	} ft_nullptr = {};
	
	// lexicographical compare
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}
	
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1,*first2))
				return true;
			++first1; ++first2;
		}
		return (first2 != last2);
	}
	
	//compare object
	template <class Arg1, class Arg2, class Result>
	struct binary_function {
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};
	
	template <class T>
	struct less : public binary_function<T,T,bool> {
		bool operator()(const T& x, const T& y) const {
			return (x < y);
		}
	};
}
#endif //FT_CONTAINERS_CONFIG_HPP
