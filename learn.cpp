#include<iostream>
#include <memory>
#include "vector.hpp"
#include<vector>
// class MyALLOC {

// };
// class A {
// public:
//     int x;
//     A(int x) : x(x) { }
// };

// class B {
// public:
//     int x;
//     explicit B(int x) : x(x) { }
//     // implicit conversion from A to B
//     // explicit B(const A& a) : x(a.x) { }
// };

int main ()
{

  ft::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator_vector it = myvector.begin() ; it != myvector.end(); ++it)
	{
		std::cout << ' ' << *it;
		if(it + 1 == myvector.end())
			std::cout << ' ' << *it;
	}

  std::cout << '\n';

  return 0;
}







