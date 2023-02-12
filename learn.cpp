#include <iostream>
#include <memory>
#include<vector>
#include "vector.hpp"
// #include "vector.hpp"

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
  ft::vector<int> myvector(5, 200);

	// std::cout << myvector.size() << std::endl;
//   std::cout << "here\n";
//  for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];

	ft::vector<int> second_vector(4, 100);
  // set some values (from 1 to 10)
//   for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  // myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
//   myvector.erase (myvector.begin(),myvector.begin()+3);
	// myvector.insert(myvector.begin() + 2, second_vector.begin(), second_vector.end());

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
  return 0;
}


// template <typename T>
// struct has_typedef_foobar {
//   // Types "yes" and "no" are guaranteed to have different sizes,
//   // specifically sizeof(yes) == 1 and sizeof(no) == 2.
//   typedef char yes[1];
//   typedef char no[2];

//   template <typename C>
//   static yes& test(typename C::foobar*);

//   template <typename>
//   static no& test(...);

//   // If the "sizeof" of the result of calling test<T>(nullptr) is equal to
//   // sizeof(yes), the first overload worked and T has a nested type named
//   // foobar.
//   static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
// };

// struct foo {
//   typedef float foobar;
// };

// int main() {
//   std::cout << std::boolalpha;
//   std::cout << has_typedef_foobar<int>::value << std::endl;  // Prints false
//   std::cout << has_typedef_foobar<foo>::value << std::endl;  // Prints true
// }
