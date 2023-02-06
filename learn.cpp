#include<iostream>
#include <memory>
#include "vector_iterator.hpp"
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
  std::vector<int> myvector (3,100);
//   myvector.push_back(1);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert (it , 200);

  myvector.insert (it,2,300);

  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}








