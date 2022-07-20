//
// Created by jaewkim on 2022/07/14.
//

#ifndef FT_CONTAINERS_CONFIG_HPP
#define FT_CONTAINERS_CONFIG_HPP
#include <cstddef>
#include <functional>
#include <iostream>
#include <memory>



// ft_nullptr

const class {
public:
	template<class T>
	operator T*() const
	{ return 0; }
	template <class C, class T>
	operator T C::*() const
	{ return 0; }
private:
	void operator&() const;
} ft_nullptr = {};

#endif //FT_CONTAINERS_CONFIG_HPP
