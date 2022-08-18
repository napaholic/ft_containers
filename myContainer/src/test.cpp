#include <vector>
#include <iostream>
#include <iterator>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <map>

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
	//test_1();
}