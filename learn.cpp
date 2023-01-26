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
  unsigned int i;
	std::vector<int> foo;   // three ints with a value of 100
  std::vector<int> bar;   // five ints with a value of 200

	foo.resize(10,10);
	bar.resize(5,5);
  foo.swap(bar);
  foo.swap(bar);

  std::cout << "foo contains:";
  for (int i = 0 ;i < foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (int i = 0 ;i < bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';

  return 0;
}



