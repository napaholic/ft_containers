#include <vector>
#include <iostream>
#include <iterator>
#include "ft_vector.hpp"
#include "config.hpp"
#include <string>

void test_1(void) {
	std::vector<int> v;
	ft::vector<int> myv;
	std::cout << "========================================================" << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << myv.size() << std::endl;
	std::cout << "========================================================" << std::endl;
	ft::random_access_iterator<int> iter = myv.begin();
	std::vector<int>::iterator iter2;
	std::cout << v.capacity() << "/size is : " << v.size() << (&(*v.begin()))  << std::endl;
	v.insert(v.begin(), 1);
	std::cout << v.capacity()  << "/size is : " << v.size() << (&(*v.begin())) << " end is : " << *v.end() << " v[0] : " <<  v[0] << " v[1] : " << v[1] << std::endl;
	v.insert(v.begin(), 5, 4);
	std::cout << v.capacity() << "/size is : " << v.size() << (&(*v.begin())) << "//end = : " << &v[1] << "minus : " << &v[1] - &*v.begin() << std::endl;
	v.insert(v.begin(), 2);
	std::cout << v.capacity() << "/size is : " << v.size() << (&(*v.begin())) << std::endl;
	std::cout << "========================================================" << std::endl;
	for (iter2 = v.begin(); iter2 != v.end(); iter2++) {
		std::cout << *iter2 << std::endl;
	}
}

int main(void) {
	test_1();
}