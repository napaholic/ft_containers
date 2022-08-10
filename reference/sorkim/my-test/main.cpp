#include <iostream>
#include "../vector.hpp"
#include "../map.hpp"
#include "vector_tests.cpp"
#include "stack_test.cpp"
#include "map_tests.cpp"

void	vector_tests()
{
	std::cout << "\n***** INSERT() TESTS *****\n" << std::endl;
	testInsert();
	std::cout << "\n***** CLEAR() TESTS *****\n" << std::endl;
	testClear();
	std::cout << "\n***** COPY CONSTRUCT() TESTS *****\n" << std::endl;
	construct_copy();
	std::cout << "\n*****  CONSTRUCT() TESTS *****\n" << std::endl;
	construct();
	std::cout << "\n***** OPERATOR=() TESTS *****\n" << std::endl;
	opEqual();
	std::cout << "\n***** BEGIN() && END() TESTS *****\n" << std::endl;
	begin();
	std::cout << "\n***** RBEGIN() &&REND() TESTS *****\n" << std::endl;
	rbegin();
	std::cout << "\n***** MAXSIZE()&& CAPACITY() TESTS *****\n" << std::endl;
	maxSizeCap();
	std::cout << "\n***** EMPTY() TESTS *****\n" << std::endl;
	empty();
	std::cout << "\n***** RESERVE() TESTS *****\n" << std::endl;
	reserveCapacity();
	std::cout << "\n***** OPERATOR[]() TESTS *****\n" << std::endl;
	operatorIndex();
	std::cout << "\n***** CONST OPERATOR[]() TESTS *****\n" << std::endl;
	constoperatorIndex();
	std::cout << "\n***** AT() TESTS *****\n" << std::endl;
	operatorAt();
	std::cout << "\n***** CONST AT() TESTS *****\n" << std::endl;
	constoperatorAt();
	std::cout << "\n*****FRONT() TESTS *****\n" << std::endl;
	front();
	std::cout << "\n*****CONST FRONT() TESTS *****\n" << std::endl;
	constfront();
	std::cout << "\n***** BACK() TESTS *****\n" << std::endl;
	back();
	std::cout << "\n***** ERASE() TESTS *****\n" << std::endl;
	testErase();
	std::cout << "\n***** POP_BACK() TESTS *****\n" << std::endl;
	testPop_back();
	std::cout << "\n***** PUSH_BACK() TESTS *****\n" << std::endl;
	testPush_back();
	std::cout << "\n***** ASSIGN() TESTS *****\n" << std::endl;
	testAssign();
	std::cout << "\n***** SWAP() TESTS *****\n" << std::endl;
	testSwap();
	std::cout << "\n***** GET_ALLOCATOR() TESTS *****\n" << std::endl;
	getAlloc();
	std::cout << "\n***** CONST ITERATORS TESTS *****\n" << std::endl;
	testConstIterators();
	std::cout << "\n***** REVITERATORS TESTS *****\n" << std::endl;
	testRevIterators();
	std::cout << "\n***** RESIZE() TESTS *****\n" << std::endl;
	testResize();
	std::cout << "\n***** printSize() TESTS *****\n" << std::endl;	
	printSize();
	std::cout << "\n***** RELATIONNAL OP() TESTS *****\n" << std::endl;	
	relationnalOp();
}

void	stack_tests()
{
	std::cout << "\n***** CONSTRUCTOR() TESTS *****\n" << std::endl;	
	stackConstruct();
	std::cout << "\n***** EMPTY() TESTS *****\n" << std::endl;	
	stackEmpty();
	std::cout << "\n***** SIZE() TESTS *****\n" << std::endl;	
	stackSize();
	std::cout << "\n***** TOP() TESTS *****\n" << std::endl;	
	stackTop();
	std::cout << "\n***** PUSH() TESTS *****\n" << std::endl;	
	stackPush();
	std::cout << "\n***** RELATIONNAL OP() TESTS *****\n" << std::endl;	
	stackOp();
}

void	map_tests()
{
	std::cout << "\n***** ITERATOR() && INSERT() TESTS *****\n" << std::endl;
	testMapInsertnIterator();
	std::cout << "\n***** ++IT TESTS *****\n" << std::endl;
	plusminus();
	std::cout << "\n***** INSERT(IT first, IT last) TESTS *****\n" << std::endl;
	testMapItLastFirstInsert();
	std::cout << "\n***** INSERT(POS, VALUE) TESTS *****\n" << std::endl;
	testMapPosInsert();
	std::cout << "\n***** OPERATIONS FUNCTIONS TEST: FT VS STD *****\n" << std::endl;
	testOperations();
	std::cout << "\n***** CONST ITERATOR() && INSERT() TESTS *****\n" << std::endl;
	testMapInsertnConstIterator();
	std::cout << "\n***** REV ITERATOR() *****\n" << std::endl;
	testMapRevIt();
	std::cout << "\n***** CONST REV ITERATOR() && [] TESTS *****\n" << std::endl;
	testMapConstRevIt();
	std::cout << "\n***** MAP SWAP TESTS *****\n" << std::endl;
	testMapSwap();
	std::cout << "\n***** MAP VALUE COMP && OPERATOR= && OPERATOR[] TESTS *****\n" << std::endl;	
	testValComp();
	std::cout << "\n***** MAP EMPTY() TESTS *****\n" << std::endl;	
	testMapEmpty();
	std::cout << "\n***** MAP KEY_COMP() TESTS *****\n" << std::endl;	
	testMapKeyComp();
	std::cout << "\n***** MAP FIND() TESTS *****\n" << std::endl;	
	testMapFind();
	std::cout << "\n***** MAP COUNT() TESTS *****\n" << std::endl;	
	testMapCount();
	std::cout << "\n***** MAP EQUAL_RANGE() TESTS *****\n" << std::endl;	
	testMapEqRange();
	std::cout << "\n***** MAP CONSTRUCT() TESTS *****\n" << std::endl;	
	testConstructs();
	std::cout << "\n***** MAP ERASE() TESTS *****\n" << std::endl;	
	mapErase();
	std::cout << "\n***** MAP LOWER_BOUND() && UPPER_BOUND TESTS *****\n" << std::endl;	
	mapLowerUpper();
	std::cout << "\n***** MAP CLEAR() TESTS *****\n" << std::endl;	
	mapClear();
}

int main ()
{
	struct timeval start, end;
    gettimeofday(&start, NULL);

	std::cout << "\n=============== VECTOR TESTS ===============\n" << std::endl;
	vector_tests();
	std::cout << "\n=============== STACK TESTS ===============\n" << std::endl;
	stack_tests();
	std::cout << "\n===============  MAP TESTS   ===============\n" << std::endl;
	map_tests();
	gettimeofday(&end, NULL);

    double time_taken;

    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec - 
                              start.tv_usec)) * 1e-6;

    std::cout << "Time taken by program is : " << std::fixed
         << time_taken;
    std::cout << " sec" << std::endl;
  	return 0;
}