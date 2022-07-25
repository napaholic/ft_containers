//
// Created by jaewkim on 2022/07/14.
//

#ifndef FT_CONTAINERS_CONFIG_HPP
#define FT_CONTAINERS_CONFIG_HPP
#include <cstddef>
#include <functional>
#include <iostream>
#include <memory>
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
}
#endif //FT_CONTAINERS_CONFIG_HPP
