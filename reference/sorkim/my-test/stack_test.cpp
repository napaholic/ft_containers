
#include <iostream>

#ifndef STD
#include "../stack.hpp"
#include "../vector.hpp"
#include <deque>
namespace opt=ft;
#else
#include <stack>
#include <vector>
#include <deque>
namespace opt=std;
#endif

void    stackConstruct()
{
	opt::stack<int> s1;

   for (int i = 0; i < 5; ++i)
	  s1.push(i + 1);

   opt::stack<int> s2(s1);

   std::cout << "Contents of stack s2" << std::endl;
   while (!s2.empty()) {
	  std::cout << s2.top() << std::endl;
	  s2.pop();
   }
}

void	stackEmpty()
{
	opt::stack<int> mystack;
	int sum (0);

	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}

	std::cout << "total: " << sum << '\n';
}

void	stackSize()
{
	opt::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';
}

void	stackTop()
{
	opt::stack<int> mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

void	stackPush()
{
	opt::stack<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';
}

void	stackOp()
{
	opt::stack<int> foo;   // three ints with a value of 100
    opt::stack<int> bar;   // two ints with a value of 200

	for (int i=0; i<5; ++i) foo.push(i);
	for (int i=0; i<5; ++i) bar.push(i);
	//for (int i=10; i<50; ++i) bar.push(i);


    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n"; 
}