#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <sys/time.h>

#ifndef STD
#include "../map.hpp"
namespace opt=ft;
#else
#include <map>
namespace opt=std;
#endif

void plusminus()
{
	 	opt::map<char, int> m ;

		opt::pair<char, int> p1('a', 5);
		opt::pair<char, int> p2('b', 3);
		opt::pair<char, int> p3('c', 2);
		m.insert(p1);
		m.insert(p2);
		m.insert(p3);

		std::cout << "pre++" << (++m.begin())->first << std::endl;
}

void  testMapInsertnIterator()
{
     /* Initializer_list constructor */
	opt::map<std::string, int> my;
	opt::map<std::string, int> my2;

	opt::pair<std::string, int> p1("y", 5);
	opt::pair<std::string, int> p2("c", 3);
	opt::pair<std::string, int> p3("z", 2);
	opt::pair<std::string, int> p4("f", 6);
	opt::pair<std::string, int> p5("b", 1);
	opt::pair<std::string, int> p6("a", 6);
	opt::pair<std::string, int> p7("x", 1);
	opt::pair<std::string, int> p8("j", 1);
	opt::pair<std::string, int> p9("n", 6);
	opt::pair<std::string, int> p10("m", 1);
	
	std::cout << '\n' << "INSERTING 10 VALUES" << std::endl;

	my.insert(p1);
	my.insert(p2);
	my.insert(p3);
	my.insert(p4);
	my.insert(p5);
	my.insert(p6);
	my.insert(p7);
	my.insert(p8);
	my.insert(p9);
	my.insert(p10);

	my2 = my;

	opt::map<std::string, int>::iterator tit;
	opt::map<std::string, int>::iterator tat;
	opt::map<std::string, int>::iterator cit;
	opt::map<std::string, int>::iterator cit2;

	cit = my.begin();
	cit2 = my.end();
	tit = my2.begin();
	tat =  my2.end();
	std::cout << '\n' << "DISPLAYING MAP WITH IT++" << std::endl;
	while(cit != cit2)
	{
			std::cout << cit->first << " <-> " << (*cit).second << std::endl;
			cit++;
	}
	std::cout << '\n' << "DISPLAYING via OPERATOR=() | MAP2 = MAP | MAP WITH IT++" << std::endl;
	while(tit != tat)
	{
			std::cout << tit->first << " <-> " << (*tit).second << std::endl;
			tit++;
	}
	std::cout << '\n' << "DISPLAYING REVERSE MAP WITH IT--" << std::endl;
	cit = my.end();
	cit--;
	while(cit != my.begin())
	{
			std::cout << (*cit).first << "<->" << (*cit).second << std::endl;
			cit--;
	}
	std::cout << (*cit).first << "<->" << (*cit).second << std::endl;
	
}

void  testMapInsertnConstIterator()
{
	opt::map<std::string, int> my;
	opt::pair<std::string, int> p1("y", 5);
	opt::pair<std::string, int> p2("c", 3);
	opt::pair<std::string, int> p3("z", 2);
	opt::pair<std::string, int> p4("f", 6);
	opt::pair<std::string, int> p5("b", 1);
	opt::pair<std::string, int> p6("a", 6);
	opt::pair<std::string, int> p7("x", 1);

	std::cout << '\n' << "INSERTING 7 VALUES" << std::endl;

	my.insert(p1);
	my.insert(p2);
	my.insert(p3);
	my.insert(p4);
	my.insert(p5);
	my.insert(p6);
	my.insert(p7);

	opt::map<std::string, int>::const_iterator it;
	opt::map<std::string, int>::const_iterator it2;
	
	int i = 0;
	it = my.begin();
	it2 = my.end();
	std::cout << '\n' << "DISPLAYING MAP WITH IT++" << std::endl;
	while(it != it2)
	{
			std::cout << it->first << " <-> " << (*it).second << std::endl;
			 i++;
			if (i == 6)
				break;
			it++;
	}
	std::cout << '\n' << "DISPLAYING REVERSE MAP WITH IT--" << std::endl;
	while(it != my.begin())
	{
			std::cout << (*it).first << "<->" << (*it).second << std::endl;
			it--;
	}
	std::cout << (*it).first << "<->" << (*it).second << std::endl;
}

void	testMapItLastFirstInsert()
{
	opt::map<std::string, int> my;
	opt::pair<std::string, int> p1("y", 5);
	opt::pair<std::string, int> p2("c", 3);
	opt::pair<std::string, int> p3("z", 2);
	opt::pair<std::string, int> p4("f", 6);
	opt::pair<std::string, int> p5("b", 1);
	opt::pair<std::string, int> p6("a", 6);
	opt::pair<std::string, int> p7("x", 1);

	my.insert(p1);
	my.insert(p2);
	my.insert(p3);
	my.insert(p4);
	my.insert(p5);
	my.insert(p6);
	my.insert(p7);

	std::cout << '\n' << "INSERTING 7 VALUES TO NEW_MAP USING ITERATORS" << std::endl;
	
	opt::map<std::string, int>new_map;
	new_map.insert(my.begin(), my.end());
	
	opt::map<std::string, int>::iterator it;
	opt::map<std::string, int>::iterator it2;
	it = new_map.begin();
	it2 = new_map.end();
	std::cout << '\n' << "DISPLAYING MAP WITH IT++" << std::endl;
	while(it != it2)
	{
		std::cout << (*it).first << " <-> " << (*it).second << std::endl;
		it++;
	}
}

void	testMapPosInsert()
{
	opt::map<std::string, int> my;
	opt::pair<std::string, int> p1("y", 5);
	opt::pair<std::string, int> p2("c", 3);
	opt::pair<std::string, int> p3("z", 2);
	opt::pair<std::string, int> p4("f", 6);
	opt::pair<std::string, int> p5("b", 1);
	opt::pair<std::string, int> p6("a", 6);
	opt::pair<std::string, int> p7("x", 1);

	my.insert(p2);
	my.insert(p1);
	my.insert(p4);
	my.insert(p5);
	my.insert(p6);
	my.insert(p7);
	opt::map<std::string, int>::iterator i;
	opt::map<std::string, int>::iterator ie;
	i = my.begin();
	ie = my.end();
	std::cout << '\n' << "DISPLAYING" << std::endl;
	while (i != ie)
	{
		std::cout << (*i).first << " <-> " << (*i).second << std::endl;
		i++;
	}
	opt::map<std::string, int> mysecond(i, ie);

	i = my.begin();
	ie = my.end();
	my.insert(my.begin(), p6);	

	std::cout << "-------TEST INSERT(INPUTITERATOR)----------" << std::endl;
	while(i != ie)
	{
			std::cout << (*i).first << "<->" << (*i).second << std::endl;
			i++;
	}
}

void	testOperations()
{
	opt::map<std::string, int> my;
	opt::pair<std::string, int> p1("y", 5);
	opt::pair<std::string, int> p2("c", 3);
	opt::pair<std::string, int> p3("z", 2);
	opt::pair<std::string, int> p4("f", 6);
	opt::pair<std::string, int> p5("b", 1);
	opt::pair<std::string, int> p6("a", 6);
	opt::pair<std::string, int> p7("x", 1);

	my.insert(p2);
	my.insert(p1);
	my.insert(p4);
	my.insert(p5);
	my.insert(p6);
	my.insert(p7);

	if (my.find("c") != my.end())
		std::cout << (*(my.find("c"))).first << std::endl;
	if (my.find("d") != my.end())
		std::cout << (*(my.find("d"))).first << std::endl;
	if (my.upper_bound("l") != my.end())
		std::cout << (*(my.upper_bound("l"))).first << std::endl;
	if (my.upper_bound("z") != my.end())
		std::cout << (*(my.upper_bound("z"))).first << std::endl;
	if (my.upper_bound("a") != my.end())
		std::cout << (*(my.upper_bound("a"))).first << std::endl;

	std::cout << my.size() << std::endl;
	std::cout << my.max_size() << std::endl;
	if (my.empty() == true)
		std::cout << "TRUE" << std::endl;

	std::cout << "-------------FT----------------" << std::endl;
	std::cout << "my['p'] is " << my["p"] << std::endl;
	std::cout << "my['k'] is " << my["k"] << std::endl;
	std::cout << "my['c'] is " << my["c"] << std::endl;
	std::cout << "my['d'] is " << my["d"] << std::endl;
	std::cout << "-------------FT----------------" << std::endl;
	std::cout << "my['p'] is " << my["p"] << '\n';
	std::cout << "my['k'] is " << my["k"] << '\n';
	std::cout << "my['c'] is " << my["c"] << '\n';
	std::cout << "my['d'] is " << my["d"] << '\n';

	std::cout << "my now contains " << my.size() << " elements.\n";
}

void	testMapConstRevIt()
{
	opt::map<std::string,int> mymap;

	opt::pair<std::string, int> p1("a", 5);
	opt::pair<std::string, int> p2("b", 3);
	opt::pair<std::string, int> p3("c", 2);
	opt::pair<std::string, int> p4("d", 6);
	opt::pair<std::string, int> p5("e", 1);
	opt::pair<std::string, int> p6("f", 6);
	opt::pair<std::string, int> p7("g", 1);

	mymap.insert(p7);
	mymap.insert(p6);
	mymap.insert(p3);
	mymap.insert(p2);
	mymap.insert(p5);
	mymap.insert(p4);
	mymap.insert(p1);

  // show content:
	opt::map<std::string,int>::const_reverse_iterator rit = mymap.rbegin();
	opt::map<std::string,int>::const_reverse_iterator rite = mymap.rend();
	
	while (rit != rite)
	{
		std::cout << (*rit).first << std::endl;
		rit++;
	}
}

void	testMapRevIt()
{
	opt::map<std::string,int> mymap;

	opt::pair<std::string, int> p1("a", 5);

	opt::pair<std::string, int> p2("b", 3);
	opt::pair<std::string, int> p3("c", 2);
	opt::pair<std::string, int> p4("d", 6);
	opt::pair<std::string, int> p5("e", 1);
	opt::pair<std::string, int> p6("f", 6);
	opt::pair<std::string, int> p7("g", 1);

	mymap.insert(p7);
	mymap.insert(p6);
	mymap.insert(p3);
	mymap.insert(p2);
	mymap.insert(p5);
	mymap.insert(p4);
	mymap.insert(p1);
	std::cout << "---------------" << std::endl;

  // show content:
 	opt::map<std::string,int>::reverse_iterator rit = mymap.rbegin();
	opt::map<std::string,int>::reverse_iterator rite = mymap.rend();

	while (rit != rite)
	{
		std::cout << (*rit).first << std::endl;
		rit++;
	}
}

void	testMapSwap()
{
	opt::map<std::string, int> foo;
	opt::pair<std::string, int> p1("y", 5);
	opt::pair<std::string, int> p2("c", 3);
	opt::pair<std::string, int> p3("z", 2);

	opt::map<std::string, int> bar;
	opt::pair<std::string, int> p4("f", 6);
	opt::pair<std::string, int> p5("b", 1);
	opt::pair<std::string, int> p6("a", 6);
	opt::pair<std::string, int> p7("x", 1);

	bar.insert(p2);
	bar.insert(p1);
	bar.insert(p4);
	bar.insert(p3);
	foo.insert(p5);
	foo.insert(p6);
	foo.insert(p7);

	std::cout << "Standard display " << std::endl;
	std::cout << "FOO is ==> " << std::endl;
	for (opt::map<std::string, int>::iterator it = foo.begin(); it !=foo.end(); it++)
		std::cout << (*it).first << " <----> " << (*it).second << std::endl;
	std::cout << "BAR is ==> " << std::endl;
	for (opt::map<std::string, int>::iterator it = bar.begin(); it !=bar.end(); it++)
		std::cout << (*it).first << " <----> " << (*it).second << std::endl;

	bar.swap(foo);
	std::cout << "Display after swapping " << std::endl;
	std::cout << "FOO is ==> " << std::endl;
	for (opt::map<std::string, int>::iterator it = foo.begin(); it != foo.end(); it++)
	
		std::cout << (*it).first << " <----> " << (*it).second << std::endl;
	std::cout << "BAR is ==> " << std::endl;
	for (opt::map<std::string, int>::iterator it = bar.begin(); it != bar.end(); it++)
		std::cout << (*it).first << " <----> " << (*it).second << std::endl;
}

void	testValComp()
{
	opt::map<char,int> mymap;

	opt::pair<char, int> p1('a', 5);
	opt::pair<char, int> p2('b', 3);
	opt::pair<char, int> p3('c', 2);
	mymap.insert(p1);
	mymap.insert(p2);
	mymap.insert(p3);

	std::cout << "mymap contains:\n";
	opt::map<char,int>::iterator it = mymap.begin();	
	while ( it != mymap.end() )
	{
		mymap.value_comp();
		std::cout << it->first << " => " << it->second << '\n';
		it++;
	}
}

void	testMapEmpty()
{
	opt::map<char,int> mymap;

	opt::pair<char, int> p1('a', 5);
	opt::pair<char, int> p2('b', 3);
	opt::pair<char, int> p3('c', 2);
	mymap.insert(p1);
	mymap.insert(p2);
	mymap.insert(p3);
	
	opt::map<char,int>::iterator it = mymap.begin();			
	while (it != mymap.end())
	{
		if (mymap.empty())
		{
			std::cout << "Map is empty" << std::endl;
			break;
		}
		std::cout << it->first << " => " << it->second << '\n';
		mymap.erase(it);
		it = mymap.begin();
	}
	std::cout << "SIZE IS : " <<mymap.size() << std::endl;
	if (mymap.empty())
	{
		std::cout << "Map is empty" << std::endl;
	}
}

void	testMapKeyComp()
{
	opt::map<char,int> mymap;
	opt::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;

	opt::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );
	std::cout << '\n';
}

void	testMapFind()
{
	opt::map<char,int> mymap;
	opt::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
}

void	testMapCount()
{
	opt::map<char,int> 	mymap;
	char 				c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
		std::cout << " is an element of mymap.\n";
		else 
		std::cout << " is not an element of mymap.\n";
	}
}

void	testMapEqRange()
{
	opt::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	opt::pair<opt::map<char,int>::iterator,opt::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "VALUE " <<  mymap.begin()->second << "\n";
	std::cout << "lower bound points to: ";
	std::cout <<  ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

void	testConstructs()
{
	opt::map<char,int> mymap;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	std::cout << "DISPLAY MYMAP" << "\n";
	for (opt::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); it++)
		std::cout << (*it).first << " <-----> " << (*it).second <<  std::endl;
	
	opt::map<char, int> cpy = mymap;
	
	std::cout << "\n DISPLAY operator= MYMAP" << "\n";
	for (opt::map<char,int>::iterator it = cpy.begin(); it != cpy.end(); it++)
		std::cout << (*it).first << " <-----> " << (*it).second <<  std::endl;

 	opt::map<char,int>::iterator it = mymap.begin();

	opt::map<char,int>::iterator ite = mymap.end();

	opt::map<char, int> mp;

	opt::map<char, int> mp_range(it, --(--ite));

	mp = cpy;

	std::cout << "\n DISPLAY cpy = mp_range" << "\n";

	for (opt::map<char,int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		if (it == mp.end())
			std::cout << "trop chelou" << "\n";
		std::cout << (*it).first << " <-----> " << (*it).second <<  std::endl;
	}
}


void	mapErase()
{
		opt::map<char,int> mymap;
	opt::map<char,int>::iterator it;

	// insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	mapLowerUpper()
{
	opt::map<char,int> mymap;
	opt::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (opt::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	mapClear()
{
	opt::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (opt::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	if (mymap.empty())
		std::cout << " MAP IS EMPTY" << "\n";
	for (opt::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';
}