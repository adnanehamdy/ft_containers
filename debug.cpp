#include <iostream>
#include <memory>
#include<vector>
#include "vector.hpp"

#include "ft_containers-unit-test/sources/system/lib.hpp"

template <typename T>
std::vector<int> iterator_test(std::vector<T> vector) {
    typename std::vector<T>::iterator it;
    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
        vector.push_back(i);
    it = vector.begin();
    v.push_back(*(++it));
    v.push_back(*(--it));
    v.push_back(*(it + 1));
    it += 1;
    v.push_back(*(it - 1));
    it -= 1;
    v.push_back(*it);
    return v;
}

template <typename T>
std::vector<int> iterator_test(_vector<T> vector) {
    typename _vector<T>::iterator it;
    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
        vector.push_back(i);
    it = vector.begin();
    v.push_back(*(++it));
    v.push_back(*(--it));
    v.push_back(*(it + 1));
    it += 1;
    v.push_back(*(it - 1));
    it -= 1;
    v.push_back(*it);
    return v;
}

int main() {
	std::cout << ((iterator_test(ft::vector<int>())) == (iterator_test(std::vector<int>()))) << std::endl;
	system("leaks a.out");
	// std::cout <<  ((constructor_test(std::vector<int>())) ==  (constructor_test(ft::vector<int>())))  << std::endl;

}
