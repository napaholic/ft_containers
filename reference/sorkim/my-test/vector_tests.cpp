#ifndef STD
#include "../vector.hpp"
namespace opt=ft;
#else
#include <vector>
namespace opt=std;
#endif

void testInsert()
{
	opt::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (100);
	myvector.push_back (100);
	opt::vector<int>::iterator it;
	opt::vector<int>::iterator ite;

	it = myvector.begin();
	it = myvector.insert ( it ,200 );
	myvector.insert (it,2,300);
	it = myvector.begin();
	opt::vector<int>::const_iterator itconst = myvector.begin();

	std::cout << "IT == ITCONST ?" << std::endl;
	if (it == itconst)
	std::cout << "YES" << std::endl;

	opt::vector<int> anothervector;
	anothervector.push_back (400);
	anothervector.push_back (400);

	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);
	
	std::cout << "myvector contains :";
	for (it=myvector.begin(), ite =myvector.end() ; it != ite; it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	/* OUTPUT SHOULD BE 
	myvector contains: 501 502 503 300 300 400 400 200 100 100 100
	*/
}

void construct_copy()
{
	opt::vector<int> vct(5);
	opt::vector<int>::iterator it = vct.begin(), ite = vct.end();

	std::cout << "len: " << (ite - it) << std::endl;
	for (; it != ite; ++it)
		*it = (ite - it);

	it = vct.begin();
	opt::vector<int> vct_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;

	it = vct.begin();
	opt::vector<int> vct_copy(vct);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	vct_copy.push_back(42);
	vct_copy.push_back(21);

	std::cout << "\t-- PART ONE --" << std::endl;
	std::cout << vct.size() << std::endl;
	std::cout << vct_range.size() << std::endl;
	std::cout << vct_copy.size() << std::endl;
	
	vct = vct_copy;
	vct_copy = vct_range;
	vct_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	std::cout << vct.size() << std::endl;
	std::cout << vct_range.size() << std::endl;
	std::cout << vct_copy.size() << std::endl;
}

void    construct()
{
     // constructors used in the same order as described above:
  opt::vector<int> first;                                // empty vector of ints
  opt::vector<int> second (4,100);                       // four ints with value 100
  opt::vector<int> third (second.begin(),second.end());  // iterating through second
  opt::vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  opt::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (opt::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

void    opEqual()
{
    opt::vector<int> foo (3,0);
    opt::vector<int> bar (5,0);

    bar = foo;
    foo = opt::vector<int>();

    std::cout << "Size of foo: " << int(foo.size()) << '\n';
    std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

void    begin()
{
    opt::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);

    std::cout << "myvector contains:";
    for (opt::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

     opt::vector<int> myvectorc;
    for (int i=1; i<=5; i++) myvectorc.push_back(i);

    std::cout << "myvector with begin_const contains:";
    for (opt::vector<int>::const_iterator it = myvectorc.begin() ; it != myvectorc.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void    rbegin()
{
    opt::vector<int> myvector (5);  // 5 default-constructed ints

    int i=0;

    opt::vector<int>::reverse_iterator rit = myvector.rbegin();
    for (; rit!= myvector.rend(); ++rit)
        *rit = ++i;

    std::cout << "myvector contains:";
    for (opt::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

void    maxSizeCap()
{
    opt::vector<int> myvector;

    // set some content in the vector:
    for (int i=0; i<100; i++) myvector.push_back(i);

    std::cout << "size: " << myvector.size() << "\n";
    std::cout << "capacity: " << myvector.capacity() << "\n";
    std::cout << "max_size: " << myvector.max_size() << "\n";
}

void    empty()
{
    opt::vector<int> myvector;
    int sum (0);

    for (int i=1;i<=10;i++) myvector.push_back(i);

    while (!myvector.empty())
    {
        sum += myvector.back();
        myvector.pop_back();
    }

    std::cout << "total: " << sum << '\n';

}

void    reserveCapacity()
{
    opt::vector<int>::size_type sz;

    opt::vector<int> foo;
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i=0; i<100; ++i) {
        foo.push_back(i);
        if (sz!=foo.capacity()) {
        sz = foo.capacity();
        std::cout << "capacity changed: " << sz << '\n';
        }
    }

    opt::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
        bar.push_back(i);
        if (sz!=bar.capacity()) {
        sz = bar.capacity();
        std::cout << "capacity changed: " << sz << '\n';
        }
    }
}

void    operatorIndex()
{
    opt::vector<int> myvector (10);   // 10 zero-initialized elements

    opt::vector<int>::size_type sz = myvector.size();

    // assign some values:
    for (unsigned i=0; i<sz; i++) myvector[i]=i;

    // reverse vector using operator[]:
    for (unsigned i=0; i<sz/2; i++)
    {
        int temp;
        temp = myvector[sz-1-i];
        myvector[sz-1-i]=myvector[i];
        myvector[i]=temp;
    }

    std::cout << "myvector contains:";
    for (unsigned i=0; i<sz; i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';
}

void    constoperatorIndex()
{
    const opt::vector<int> myvector (10, 10);   // 10 zero-initialized elements

    opt::vector<int>::size_type sz = myvector.size();

    // assign some values:

    std::cout << "myvector contains:";
    for (unsigned i=0; i<sz; i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';
}

void    operatorAt()
{
    opt::vector<int> myvector (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector.at(i);
    std::cout << '\n';
}

void    constoperatorAt()
{
    const opt::vector<int> myvector (10, 10);

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector.at(i);
    std::cout << '\n';
}

void    front()
{
    opt::vector<int> myvector;

    myvector.push_back(78);
    myvector.push_back(16);

    // now front equals 78, and back 16

    myvector.front() -= myvector.back();

    std::cout << "myvector.front() is now " << myvector.front() << '\n';
}
void    constfront()
{
    opt::vector<int> myvector;

    myvector.push_back(78);
    myvector.push_back(16);

    // now front equals 78, and back 16

    myvector.front() -= myvector.back();

    std::cout << "myvector.front() is now " << myvector.front() << '\n';
}

void    back()
{
    opt::vector<int> myvector;
    myvector.push_back(10);
    while (myvector.back() != 0)
    {
        myvector.push_back ( myvector.back() -1 );
    }
    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size() ; i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';
}


void	testClear()
{
	opt::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	testErase()
{
	opt::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	// erase the 6th element
	myvector.erase(myvector.begin()+5);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	testPop_back()
{
	opt::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	
	while (!myvector.empty())
		myvector.pop_back();
	if (myvector.empty())
		std::cout << "The vector is empty " << '\n';
}

void testPush_back()
{
	opt::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	opt::vector<int>::iterator it;
	opt::vector<int>::iterator ite;
	for(it = myvector.begin(), ite = myvector.end(); it != ite; it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	testAssign()
{
	opt::vector<int> first;
	opt::vector<int> second;
	opt::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	opt::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
	opt::vector<int>::iterator ite;
	for(it = first.begin(), ite = first.end(); it != ite; it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	testSwap()
{
	opt::vector<int> foo ; 
	foo.push_back (100);
	foo.push_back (200);
	foo.push_back (300);
	foo.push_back (100);  // three ints with a value of 100
	opt::vector<int> bar;   // five ints with a value of 200
	bar.push_back (1);
	bar.push_back (2);
	bar.push_back (3);

	std::cout << "Address of FOO" << std::endl;
	std::cout << &foo << std::endl;
	std::cout << "Address of BAR" << std::endl;
	std::cout << &bar << std::endl;

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';

	foo.swap(bar);

	std::cout << "AFTER SWAP Address of FOO" << std::endl;
	std::cout << &foo << std::endl;
	std::cout << "AFTER SWAP Address of BAR" << std::endl;
	std::cout << &bar << std::endl;

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';
}

void	testConstIterators()
{
	opt::vector<int>::const_iterator itconst;
	opt::vector<int>::const_iterator iteconst;
	opt::vector<int> myvector;
	myvector.push_back(10);
	myvector.push_back(11);
	myvector.push_back(12);
	myvector.push_back(13);
	myvector.begin();
	for (itconst = myvector.begin(), iteconst = myvector.end() ; itconst != iteconst; itconst++)
		std::cout << ' ' << *itconst;
	std::cout << '\n' << "CONST REVERSE TESTS" << std::endl;
	opt::vector<int>::const_reverse_iterator itconst1;
	opt::vector<int>::const_reverse_iterator iteconst2;
	opt::vector<int> myvector1;
	myvector1.push_back(10);
	myvector1.push_back(11);
	myvector1.push_back(12);
	myvector1.push_back(13);
	for (itconst1 = myvector1.rbegin(), iteconst2 = myvector1.rend() ; itconst1 != iteconst2; itconst1++)
		std::cout << ' ' << *itconst1;
	std::cout << '\n';
}


void	testRevIterators()
{
	opt::vector<int>::reverse_iterator itconst;
	opt::vector<int>::reverse_iterator iteconst;
	opt::vector<int> myvector;
	myvector.push_back(1);
	myvector.push_back(2);
	myvector.push_back(3);
	myvector.push_back(4);
	itconst = myvector.rbegin();
	std::cout << "Result of itbegin + 1 : " << *itconst + 1 << std::endl;
	std::cout  << std::endl;
	std::cout << "Result of itbegin - 1 : " << *itconst - 1 << std::endl;
	std::cout  << std::endl;
	std::cout << "Result of itbegin[3] : " << itconst[3] << std::endl;
	std::cout  << std::endl;
	iteconst = myvector.rend();
	for (itconst = myvector.rbegin() ; itconst != iteconst; itconst++)
		std::cout << ' ' << *itconst;
	std::cout << '\n';
}

void	testResize()
{
	opt::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (size_t i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	/* OUTPUT SHOULD BE
	myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0
	*/
}

void    getAlloc()
{

    opt::vector<int> myvector;
    int * p;
    unsigned int i;

    // allocate an array with space for 5 elements using vector's allocator:
    p = myvector.get_allocator().allocate(5);

    // construct values in-place on the array:
    for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

    std::cout << "The allocated array contains:";
    for (i=0; i<5; i++) std::cout << ' ' << p[i];
    std::cout << '\n';

    // destroy and deallocate:
    for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
    myvector.get_allocator().deallocate(p,5);
}

void    relationnalOp()
{
    opt::vector<int> foo (3,100);   // three ints with a value of 100
    opt::vector<int> bar (2,200);   // two ints with a value of 200

    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n"; 
}

void	printSize()
{
	opt::vector<int> vct;
	vct.push_back(1);
	vct.push_back(2);
	vct.push_back(3);
	vct.push_back(4);

	const size_t size = vct.size();
	const size_t capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	
		opt::vector<int>::const_iterator it = vct.begin();
		opt::vector<int>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;

	std::cout << "###############################################" << std::endl;
}

