#include <vector>
#include <iostream>
#include <iterator>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <sys/time.h>
#include "../ft_containers-unit-test/sources/system/lib.hpp"
#include "../ft_containers-unit-test/sources/vector_tests/swap().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/insert(range).cpp"
#include <map>

#define	_vector 			ft::vector
#define	_stack	 			ft::stack
#define	_map 				ft::map

template <typename T>
std::vector<int> assign_test(std::vector<T> vector) {
	std::vector<int> v;
	std::vector<int> tmp, tmp2;
	vector.assign(3, 3);
	tmp.assign(4000 * _ratio, 1);
	tmp2.assign(4 * _ratio, 1);
	g_start1 = timer();
	vector.assign(tmp.begin(), tmp.end());
	v.push_back(vector[1]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.assign(tmp2.begin(), tmp2.end());
	g_end1 = timer();
	v.push_back(vector[444]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

template <typename T>
std::vector<int> assign_test(_vector<T> vector) {
	std::vector<int> v;
	_vector<int> tmp, tmp2;
	vector.assign(3, 3);
	tmp.assign(4000 * _ratio, 1);
	tmp2.assign(4 * _ratio, 1);
	g_start2 = timer();
	vector.assign(tmp.begin(), tmp.end());
	v.push_back(vector[1]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.assign(tmp2.begin(), tmp2.end());
	g_end2 = timer();
	v.push_back(vector[444]);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	return v;
}

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

template <typename T>
std::vector<int> resize_test(std::vector<T> vector) {
	std::vector<int> v;
	vector.assign(9900 * _ratio, 1);
	g_start1 = timer();
	vector.resize(5000 * _ratio);
	vector.reserve(5000 * _ratio);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.resize(7000 * _ratio);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.resize(15300 * _ratio, T());
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	v.push_back(vector[65]);
	g_end1 = timer();
	return v;
}

template <typename T>
std::vector<int> resize_test(_vector<T> vector) {
	std::vector<int> v;
	vector.assign(9900 * _ratio, 1);
	g_start2 = timer();
	vector.resize(5000 * _ratio);
	vector.reserve(5000 * _ratio);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.resize(7000 * _ratio);
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	vector.resize(15300 * _ratio, T());
	v.push_back(vector.size());
	v.push_back(vector.capacity());
	v.push_back(vector[65]);
	g_end2 = timer();
	return v;
}

int main(void) {
	std::map<int, int> t;
	t.insert(std::make_pair(1, 4));
	t.insert(std::make_pair(2, 3));
	t.insert(std::make_pair(3, 2));
	t.insert(std::make_pair(4, 1));
	t.insert(std::make_pair(5, 1));
	std::map<int, int> p;
	p.insert(std::make_pair(1, 4));
	p.insert(std::make_pair(2, 3));
	p.insert(std::make_pair(3, 2));
	p.insert(std::make_pair(4, 1));
	p.insert(std::make_pair(4, 2));
	p.insert(std::make_pair(4, 2));
	std::cout << "========================================================" << std::endl;
	std::cout << "========================================================" << std::endl;
	std::cout << "=============lexicographical_compare test===============" << std::endl;
	bool tmp = t < p;
	std::cout << tmp << std::endl;
	
	std::cout << "========================================================" << std::endl;
	std::cout << p[0] << std::endl;
	std::cout << p[1] << std::endl;
	std::cout << p[2] << std::endl;
	std::cout << p[3] << std::endl;
	std::cout << p[4] << std::endl;
	std::cout << p[5] << std::endl;
	std::cout << t[0] << std::endl;
	std::cout << t[1] << std::endl;
	std::cout << t[2] << std::endl;
	std::cout << t[3] << std::endl;
	std::cout << t[4] << std::endl;
	std::cout << t[5] << std::endl;
	std::cout << t[6] << std::endl;
	std::cout << t[7] << std::endl;
	std::cout << t[8] << std::endl;
	std::cout << &t[8] << std::endl;
	std::cout << &t[5] << std::endl;
	std::cout << t[5] << std::endl;
	std::map<int, int>::iterator iter = t.end();
	std::cout << &(*t.end()) << std::endl;
	std::cout << &*(t.end()) << std::endl;
	std::cout << "========================================================" << std::endl;
	ft::map<int, int> my;
	std::map<int, int> std;
	my[0] = 1;
	my[0] = 2;
	my[0] = 3;
	ft::map<int, int>::iterator iter2 = my.end();
	std::cout << &*iter2 << std::endl;
	iter2--;
	std::cout << &*iter2 << std::endl;
	std::cout << my.rbegin()->second << std::endl;
	std[0] = 1;
	ft::vector<int> myv;
	const int a = 4;
	myv.push_back(3);
	std::cout << myv[0] << std::endl;
	std::cout << myv[1] << std::endl;
	ft::vector<int> myv1;
	myv1.push_back(4);
	myv = myv1;
	std::cout << myv[0] << std::endl;
	std::cout << "=======================resize test=========================" << std::endl;
	std::cout << myv1.capacity() << std::endl;
	myv1.resize(10);
	std::cout << myv1.capacity() << std::endl;
	myv1.insert(myv1.begin(), 10, 1);
	ft::vector<int> test;
	std::vector<int> standard;
	//if (resize_test(test) == resize_test(standard));
	//	std::cout << "ok" << std::endl;
	std::cout << "false" << std::endl;
	std::cout << "=======================assign test=========================" << std::endl;
	if (assign_test(test) == assign_test(standard))
		std::cout << "ok" << std::endl;
	std::cout << "=======================swap test=========================" << std::endl;
	//std::vector<int> my_result = swap_test(test);
	//std::vector<int> std_result = swap_test(standard);
	//if (my_result == std_result)
	//	std::cout << "swap is ok" << std::endl;
	
	std::cout << "=======================insert test=========================" << std::endl;
	ft::vector<int> insert_myv;
	std::vector<int> insert_stdv;
	std::vector<int> my_insert = insert_test_3(insert_myv);
	std::vector<int> std_insert = insert_test_3(insert_stdv);
	if (my_insert == std_insert)
		std::cout << "insert ok" << std::endl;
	
}