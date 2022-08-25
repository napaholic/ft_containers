#include <vector>
#include <iostream>
#include <iterator>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <sys/time.h>
//vector test inc
#include "../ft_containers-unit-test/sources/system/lib.hpp"
#include "../ft_containers-unit-test/sources/vector_tests/assign().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/assign(std iterators).cpp"
#include "../ft_containers-unit-test/sources/vector_tests/at().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/back().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/begin().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/capacity().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/clear().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/constructor(std iterators).cpp"
#include "../ft_containers-unit-test/sources/vector_tests/constructor.cpp"
#include "../ft_containers-unit-test/sources/vector_tests/data().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/empty().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/end().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/erase(range).cpp"
#include "../ft_containers-unit-test/sources/vector_tests/erase(value).cpp"
#include "../ft_containers-unit-test/sources/vector_tests/front().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/insert(fill).cpp"
#include "../ft_containers-unit-test/sources/vector_tests/insert(range).cpp"
#include "../ft_containers-unit-test/sources/vector_tests/insert(std iterators).cpp"
#include "../ft_containers-unit-test/sources/vector_tests/insert(value).cpp"
#include "../ft_containers-unit-test/sources/vector_tests/iterators.cpp"
#include "../ft_containers-unit-test/sources/vector_tests/max_size().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/operator !=.cpp"
#include "../ft_containers-unit-test/sources/vector_tests/operator <.cpp"
#include "../ft_containers-unit-test/sources/vector_tests/operator <=.cpp"
#include "../ft_containers-unit-test/sources/vector_tests/operator ==.cpp"
#include "../ft_containers-unit-test/sources/vector_tests/operator >.cpp"
#include "../ft_containers-unit-test/sources/vector_tests/operator >=.cpp"
#include "../ft_containers-unit-test/sources/vector_tests/operator[].cpp"
#include "../ft_containers-unit-test/sources/vector_tests/pop_back().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/push_back().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/rbegin().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/rend().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/reserve().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/resize().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/size().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/swap().cpp"
#include "../ft_containers-unit-test/sources/vector_tests/using allocator.cpp"

//map test inc
#include <map>
#include "../ft_containers-unit-test/sources/map_tests/assign overload.cpp"
#include "../ft_containers-unit-test/sources/map_tests/at().cpp"
#include "../ft_containers-unit-test/sources/map_tests/clear().cpp"
#include "../ft_containers-unit-test/sources/map_tests/compare class.cpp"
#include "../ft_containers-unit-test/sources/map_tests/constructor.cpp"
#include "../ft_containers-unit-test/sources/map_tests/count().cpp"
#include "../ft_containers-unit-test/sources/map_tests/empty().cpp"
#include "../ft_containers-unit-test/sources/map_tests/equal_range().cpp"
#include "../ft_containers-unit-test/sources/map_tests/erase(InputIt).cpp"
#include "../ft_containers-unit-test/sources/map_tests/erase(key).cpp"
#include "../ft_containers-unit-test/sources/map_tests/erase(pos).cpp"
#include "../ft_containers-unit-test/sources/map_tests/find().cpp"
#include "../ft_containers-unit-test/sources/map_tests/insert(hint).cpp"
#include "../ft_containers-unit-test/sources/map_tests/insert(InputIt).cpp"
#include "../ft_containers-unit-test/sources/map_tests/insert(value).cpp"
#include "../ft_containers-unit-test/sources/map_tests/iterators.cpp"
#include "../ft_containers-unit-test/sources/map_tests/key_comp().cpp"
#include "../ft_containers-unit-test/sources/map_tests/key_redefinition.cpp"
#include "../ft_containers-unit-test/sources/map_tests/lower_bound().cpp"
#include "../ft_containers-unit-test/sources/map_tests/max_size().cpp"
#include "../ft_containers-unit-test/sources/map_tests/operator !=.cpp"
#include "../ft_containers-unit-test/sources/map_tests/operator <.cpp"
#include "../ft_containers-unit-test/sources/map_tests/operator <=.cpp"
#include "../ft_containers-unit-test/sources/map_tests/operator ==.cpp"
#include "../ft_containers-unit-test/sources/map_tests/operator >.cpp"
#include "../ft_containers-unit-test/sources/map_tests/operator >=.cpp"
#include "../ft_containers-unit-test/sources/map_tests/operator[].cpp"
#include "../ft_containers-unit-test/sources/map_tests/reverse iterators.cpp"
#include "../ft_containers-unit-test/sources/map_tests/size().cpp"
#include "../ft_containers-unit-test/sources/map_tests/swap().cpp"
#include "../ft_containers-unit-test/sources/map_tests/upper_bound().cpp"
#include "../ft_containers-unit-test/sources/map_tests/using allocator.cpp"

#define	_vector 			ft::vector
#define	_stack	 			ft::stack
#define	_map 				ft::map

int main(void) {
	std::cout << "=======================vector test=========================" << std::endl;
	std::cout << "=======================assign test=========================" << std::endl;
	std::vector<int> my_assign;
	std::vector<int> std_assign;
	if (assign_test(my_assign) == assign_test(std_assign))
		std::cout << "assign is ok" << std::endl;
	std::cout << "=======================assign_std_test=========================" << std::endl;
	std::vector<int> my_assign_std;
	std::vector<int> std_assign_std;
	if (assign_std_test(my_assign_std) == assign_std_test(std_assign_std))
		std::cout << "assign_std_test is ok" << std::endl;
	std::cout << "=======================at_test=========================" << std::endl;
	std::vector<int> my_at_test;
	std::vector<int> std_at_test;
	if (at_test(my_at_test) == at_test(std_at_test))
		std::cout << "at_test is ok" << std::endl;
	std::cout << "=======================back_test=========================" << std::endl;
	std::vector<int> my_back_test;
	std::vector<int> std_back_test;
	if (back_test(my_back_test) == back_test(std_back_test))
		std::cout << "back_test is ok" << std::endl;
	std::cout << "=======================begin_test=========================" << std::endl;
	std::vector<int> my_begin_test;
	std::vector<int> std_begin_test;
	if (begin_test(my_begin_test) == begin_test(std_begin_test))
		std::cout << "begin_test is ok" << std::endl;
	std::cout << "=======================capacity_test=========================" << std::endl;
	std::vector<int> my_capacity_test;
	std::vector<int> std_capacity_test;
	if (capacity_test(my_capacity_test) == capacity_test(std_capacity_test))
		std::cout << "begin_test is ok" << std::endl;
	std::cout << "=======================clear_test=========================" << std::endl;
	std::vector<int> my_clear_test;
	std::vector<int> std_clear_test;
	if (clear_test(my_clear_test) == clear_test(std_clear_test))
		std::cout << "clear_test is ok" << std::endl;
	std::cout << "=======================constructor_std_test=========================" << std::endl;
	std::vector<int> my_con_test;
	std::vector<int> std_con_test;
	if (constructor_std_test(my_con_test) == constructor_std_test(std_con_test))
		std::cout << "constructor_std_test is ok" << std::endl;
	std::cout << "=======================constructor_test=========================" << std::endl;
	std::vector<int> my_constructor_test;
	std::vector<int> std_constructor_test;
	if (constructor_test(my_constructor_test) == constructor_test(std_constructor_test))
		std::cout << "constructor_test is ok" << std::endl;
	std::cout << "=======================data_test=========================" << std::endl;
	std::vector<int> my_data_test;
	std::vector<int> std_data_test;
	if (data_test(my_data_test) == data_test(std_data_test))
		std::cout << "data_test is ok" << std::endl;
	
	std::cout << "=======================swap test=========================" << std::endl;
	std::vector<int> my_swap;
	std::vector<int> std_swap;
	if (swap_test(my_swap) == swap_test(std_swap))
		std::cout << "swap is ok" << std::endl;
	std::cout << "=======================empty_test=========================" << std::endl;
	std::vector<int> my_empty;
	std::vector<int> std_empty;
	if (empty_test(my_empty) == empty_test(std_empty))
		std::cout << "empty_test is ok" << std::endl;
	std::cout << "=======================end_test=========================" << std::endl;
	std::vector<int> my_end_test;
	std::vector<int> std_end_test;
	if (end_test(my_end_test) == end_test(std_end_test))
		std::cout << "end_test is ok" << std::endl;
	std::cout << "=======================erase_test_range=========================" << std::endl;
	std::vector<int> my_erase_test_2;
	std::vector<int> std_erase_test_2;
	if (erase_test_2(my_erase_test_2) == erase_test_2(std_erase_test_2))
		std::cout << "erase_test_range is ok" << std::endl;
	std::cout << "=======================erase_test_value=========================" << std::endl;
	std::vector<int> my_erase_test_value;
	std::vector<int> std_erase_test_value;
	if (erase_test_1(my_erase_test_value) == erase_test_1(std_erase_test_value))
		std::cout << "erase_test_value is ok" << std::endl;
	std::cout << "=======================front_test=========================" << std::endl;
	std::vector<int> my_front_test;
	std::vector<int> std_front_test;
	if (front_test(my_front_test) == front_test(std_front_test))
		std::cout << "front_test is ok" << std::endl;
	std::cout << "=======================insert_test_fill=========================" << std::endl;
	std::vector<int> my_insert_test_2;
	std::vector<int> std_insert_test_2;
	if (insert_test_2(my_insert_test_2) == insert_test_2(std_insert_test_2))
		std::cout << "insert_test_fill is ok" << std::endl;
	std::cout << "=======================insert_test_range=========================" << std::endl;
	std::vector<int> my_insert_test_range;
	std::vector<int> std_insert_test_range;
	if (insert_test_3(my_insert_test_range) == insert_test_3(std_insert_test_range))
		std::cout << "insert_test_range is ok" << std::endl;
	std::cout << "=======================insert_std_test=========================" << std::endl;
	std::vector<int> my_insert_std_test;
	std::vector<int> std_insert_std_test;
	if (insert_std_test(my_insert_std_test) == insert_std_test(std_insert_std_test))
		std::cout << "insert_std_test is ok" << std::endl;
	std::cout << "=======================insert_std_value=========================" << std::endl;
	std::vector<int> my_insert_test_1;
	std::vector<int> std_insert_test_1;
	if (insert_test_1(my_insert_test_1) == insert_test_1(std_insert_test_1))
		std::cout << "insert_std_value is ok" << std::endl;
	std::cout << "=======================iterator_test=========================" << std::endl;
	std::vector<int> my_iterator_test;
	std::vector<int> std_iterator_test;
	if (iterator_test(my_iterator_test) == iterator_test(std_iterator_test))
		std::cout << "iterator_test is ok" << std::endl;
	std::cout << "=======================maxsize_test=========================" << std::endl;
	std::vector<int> my_maxsize_test;
	std::vector<int> std_maxsize_test;
	if (maxsize_test(my_maxsize_test) == maxsize_test(std_maxsize_test))
		std::cout << "maxsize_test is ok" << std::endl;
	std::cout << "=======================operator!=_test=========================" << std::endl;
	if (operator_not_equal_test)
		std::cout << "operator!=_test is ok" << std::endl;
	std::cout << "=======================operator<_test=========================" << std::endl;
	if (operator_less_test)
		std::cout << "operator<_test is ok" << std::endl;
	std::cout << "=======================operator<=_test=========================" << std::endl;
	if (operator_less_equal_test)
		std::cout << "operator<=_test is ok" << std::endl;
	std::cout << "=======================operator==_test=========================" << std::endl;
	if (operator_equal_test)
		std::cout << "operator==_test is ok" << std::endl;
	std::cout << "=======================operator>_test=========================" << std::endl;
	if (operator_more_test)
		std::cout << "operator>_test is ok" << std::endl;
	std::cout << "=======================operator>=_test=========================" << std::endl;
	if (operator_more_equal_test)
		std::cout << "operator>=_test is ok" << std::endl;
	std::cout << "=======================operator[]_test=========================" << std::endl;
	std::vector<int> my_access_operator;
	std::vector<int> std_access_operator;
	if (operator1_test(my_access_operator) == operator1_test(std_access_operator))
		std::cout << "operator[]_test is ok" << std::endl;
	std::cout << "=======================pop_back_test=========================" << std::endl;
	std::vector<int> my_pop_back_test;
	std::vector<int> std_pop_back_test;
	if (pop_back_test(my_pop_back_test) == pop_back_test(std_pop_back_test))
		std::cout << "pop_back_test is ok" << std::endl;
	std::cout << "=======================push_back_test=========================" << std::endl;
	std::vector<int> my_push_back_test;
	std::vector<int> std_push_back_test;
	if (push_back_test(my_push_back_test) == push_back_test(std_push_back_test))
		std::cout << "push_back_test is ok" << std::endl;
	std::cout << "=======================rbegin_test=========================" << std::endl;
	std::vector<int> my_rbegin_test;
	std::vector<int> std_rbegin_test;
	if (rbegin_test(my_rbegin_test) == rbegin_test(std_rbegin_test))
		std::cout << "rbegin_test is ok" << std::endl;
	std::cout << "=======================rend_test=========================" << std::endl;
	std::vector<int> my_rend_test;
	std::vector<int> std_rend_test;
	if (rend_test(my_rend_test) == rend_test(std_rend_test))
		std::cout << "rbegin_test is ok" << std::endl;
	std::cout << "=======================reserve_test=========================" << std::endl;
	std::vector<int> my_reserve_test;
	std::vector<int> std_reserve_test;
	if (reserve_test(my_reserve_test) == reserve_test(std_reserve_test))
		std::cout << "reserve_test is ok" << std::endl;
	std::cout << "=======================resize_test=========================" << std::endl;
	std::vector<int> my_resize_test;
	std::vector<int> std_resize_test;
	if (resize_test(my_resize_test) == resize_test(std_resize_test))
		std::cout << "resize_test is ok" << std::endl;
	std::cout << "=======================size_test=========================" << std::endl;
	std::vector<int> my_size_test;
	std::vector<int> std_size_test;
	if (size_test(my_size_test) == size_test(std_size_test))
		std::cout << "size_test is ok" << std::endl;
	std::cout << "=======================swap_test=========================" << std::endl;
	std::vector<int> my_swap_test;
	std::vector<int> std_swap_test;
	if (swap_test(my_swap_test) == swap_test(std_swap_test))
		std::cout << "swap_test is ok" << std::endl;
	std::cout << "=======================allocator_test=========================" << std::endl;
	ft::vector<int, Alloc<int> >my_vector;
	allocator_test(my_vector);
	if (my_vector.get_alloc_test())
		std::cout << "vector allocator test is ok" << std::endl;
	
	std::cout << "=======================map test=========================" << std::endl;
	std::cout << "=======================assign overload test=========================" << std::endl;
	ft::map<int, int> my_assign_overload;
	std::map<int, int> std_assign_overload;
	if (assign_overload_test(my_assign_overload) == assign_overload_test(std_assign_overload))
		std::cout << "assign is ok" << std::endl;
	std::cout << "=======================at test=========================" << std::endl;
	ft::map<int, int> my_at;
	std::map<int, int> std_at;
	if (at_test(my_at) == at_test(std_at))
		std::cout << "at test is ok" << std::endl;
	std::cout << "=======================clear() test=========================" << std::endl;
	ft::map<int, int> my_clear;
	std::map<int, int> std_clear;
	if (clear_test(my_clear) == clear_test(std_clear))
		std::cout << "clear test is ok" << std::endl;
	std::cout << "=======================compare class test=========================" << std::endl;
	ft::map<int, int> my_compare;
	std::map<int, int> std_compare;
	if (comparator_test(my_compare) == comparator_test(std_compare))
		std::cout << "clear test is ok" << std::endl;
	std::cout << "=======================constructor test=========================" << std::endl;
	ft::map<int, int> my_constructor;
	std::map<int, int> std_constructor;
	if (copy_constructor_test(my_constructor) == copy_constructor_test(std_constructor))
		std::cout << "constructor test is ok" << std::endl;
	std::cout << "=======================count() test=========================" << std::endl;
	ft::map<int, int> my_count;
	std::map<int, int> std_count;
	if (count_test(my_count) == count_test(std_count))
		std::cout << "count test is ok" << std::endl;
	std::cout << "=======================empty() test=========================" << std::endl;
	ft::map<int, int> my_map_empty;
	std::map<int, int> std_map_empty;
	if (empty_test(my_map_empty) == empty_test(std_map_empty))
		std::cout << "empty test is ok" << std::endl;
	std::cout << "=======================equal_range_test() test=========================" << std::endl;
	ft::map<int, int> my_equal_range;
	std::map<int, int> std_equal_range;
	if (equal_range_test(my_equal_range) == equal_range_test(std_equal_range))
		std::cout << "equal_range_test is ok" << std::endl;
	std::cout << "=======================erase(InputIt) test=========================" << std::endl;
	ft::map<int, int> my_erase;
	std::map<int, int> std_erase;
	if (erase_test_3(my_erase) == erase_test_3(std_erase))
		std::cout << "erase(InputIt) test is ok" << std::endl;
	std::cout << "=======================erase(key) test=========================" << std::endl;
	ft::map<int, int> my_erase_key;
	std::map<int, int> std_erase_key;
	if (erase_test_1(my_erase_key) == erase_test_1(std_erase_key))
		std::cout << "erase(key) test is ok" << std::endl;
	std::cout << "=======================erase(pos) test=========================" << std::endl;
	ft::map<int, int> my_erase_pos;
	std::map<int, int> std_erase_pos;
	if (erase_test_2(my_erase_pos) == erase_test_2(std_erase_pos))
		std::cout << "erase(pos) test is ok" << std::endl;
	std::cout << "=======================find_test test=========================" << std::endl;
	ft::map<int, int> my_find_test;
	std::map<int, int> std_find_test;
	if (find_test(my_find_test) == find_test(std_find_test))
		std::cout << "find_test test is ok" << std::endl;
	std::cout << "=======================insert(hint)_test test=========================" << std::endl;
	ft::map<int, int> my_insert_hint;
	std::map<int, int> std_insert_hint;
	if (insert_test_3(my_insert_hint) == insert_test_3(std_insert_hint))
		std::cout << "insert(hint) test is ok" << std::endl;
	std::cout << "=======================insert(inputit)_test test=========================" << std::endl;
	ft::map<int, int> my_insert_inputit;
	std::map<int, int> std_insert_inputit;
	if (insert_test_2(my_insert_inputit) == insert_test_2(std_insert_inputit))
		std::cout << "insert(inputit) test is ok" << std::endl;
	std::cout << "=======================insert(value)_test test=========================" << std::endl;
	ft::map<int, int> my_insert_value;
	std::map<int, int> std_insert_value;
	if (insert_test(my_insert_value) == insert_test(std_insert_value))
		std::cout << "insert(value) test is ok" << std::endl;
	std::cout << "=======================iterators_test test=========================" << std::endl;
	ft::map<int, int> my_iterators;
	std::map<int, int> std_iterators;
	if (iterators_test(my_iterators) == iterators_test(std_iterators))
		std::cout << "iterators_test is ok" << std::endl;
	std::cout << "=======================key_comp_test test=========================" << std::endl;
	ft::map<int, int> my_key_comp_test;
	std::map<int, int> std_key_comp_test;
	if (key_comp_test(my_key_comp_test) == key_comp_test(std_key_comp_test))
		std::cout << "key_comp_test is ok" << std::endl;
	std::cout << "=======================key_redefinition test=========================" << std::endl;
	ft::map<int, int>::iterator my_redefinition;
	//my_redefinition->first = 1;
	std::cout << "key_redefinition is ok" << std::endl;
	std::cout << "=======================lower_bound test=========================" << std::endl;
	ft::map<int, int> my_lower;
	std::map<int, int> std_lower;
	if (lower_bound_test(my_lower) == lower_bound_test(std_lower))
		std::cout << "lower_bound_test is ok" << std::endl;
	
	std::cout << "=======================max_size_test=========================" << std::endl;
	ft::map<int, int> my_max_test;
	std::map<int, int> std_max_test;
	if (max_size_test(my_max_test) == max_size_test(std_max_test))
		std::cout << "max_size_test is ok" << std::endl;
	
	std::cout << "=======================reverse iterater test=========================" << std::endl;
	ft::map<int, int> my_riter;
	std::map<int, int> std_riter;
	if (reverse_iterators_test_ft(my_riter) == reverse_iterators_test_std(std_riter))
		std::cout << "reverse iterator test" << std::endl;
	std::cout << "=======================operator!= test=========================" << std::endl;
	if (map_not_equal_test())
		std::cout << "operator!= test is ok" << std::endl;
	std::cout << "=======================operator< test=========================" << std::endl;
	if (map_less_than_test())
		std::cout << "operator< test is ok" << std::endl;
	std::cout << "=======================operator<= test=========================" << std::endl;
	if (map_less_or_equal_test())
		std::cout << "operator<= test is ok" << std::endl;
	std::cout << "=======================operator== test=========================" << std::endl;
	if (map_equal_test())
		std::cout << "operator== test is ok" << std::endl;
	std::cout << "=======================operator> test=========================" << std::endl;
	if (map_more_than_test())
		std::cout << "operator> test is ok" << std::endl;
	std::cout << "=======================operator>= test=========================" << std::endl;
	if (map_more_or_equal_test())
		std::cout << "operator>= test is ok" << std::endl;
	std::cout << "=======================operator[] test=========================" << std::endl;
	ft::map<int, int> my_op_test;
	std::map<int, int> std_op_test;
	if (operator_sq_test(my_op_test) == operator_sq_test(std_op_test))
		std::cout << "operator[] test is ok" << std::endl;
	std::cout << "=======================reverse iterators test=========================" << std::endl;
	ft::map<int, int> my_reverse_iter;
	std::map<int, int> std_reverse_iter;
	if (reverse_iterators_test_ft(my_reverse_iter) == reverse_iterators_test_std(std_reverse_iter))
		std::cout << "reverse iterators test is ok" << std::endl;
	std::cout << "=======================size_test=========================" << std::endl;
	ft::map<int, int> mym_size_test;
	std::map<int, int> stdm_size_test;
	if (size_test(mym_size_test) == size_test(stdm_size_test))
		std::cout << "size_test is ok" << std::endl;
	std::cout << "=======================swap_test=========================" << std::endl;
	ft::map<int, int> mym_swap_test;
	std::map<int, int> stdm_swap_test;
	if (swap_test(mym_swap_test) == swap_test(stdm_swap_test))
		std::cout << "swap_test is ok" << std::endl;
	std::cout << "=======================upper_bound_test=========================" << std::endl;
	ft::map<int, int> my_upper_bound_test;
	std::map<int, int> std_upper_bound_test;
	if (upper_bound_test(my_upper_bound_test) == upper_bound_test(std_upper_bound_test))
		std::cout << "upper_bound_test is ok" << std::endl;
	std::cout << "=======================allocator_test=========================" << std::endl;
	ft::map<int, int, std::less<int>, Alloc<_pair<const int, int> > > my_map;
	allocator_test(my_map);
	if (my_map.get_alloc_test())
		std::cout << "allocator test is ok" << std::endl;
}