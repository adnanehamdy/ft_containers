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

int main() {
	ft::vector<int> test;
	try
	{
	test.reserve(10);
	std::cout << test.capacity();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//  std::vector<int> original;

	// std::cout << original.size();
	// original.push_back(3);
	// std::cout << original.size();
	// original.push_back(1);
	// original.push_back(5);
	// std::cout << original.capacity();
}