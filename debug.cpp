#include <iostream>
#include <memory>
#include<vector>
#include "vector.hpp"

#include "ft_containers-unit-test/sources/system/lib.hpp"

template <typename T>
std::vector<int> resize_test(std::vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    vector.resize(5000 * _ratio);
    vector.reserve(5000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(15300 * _ratio, T());
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    v.push_back(vector[65]);
    return v;
}

template <typename T>
std::vector<int> resize_test(_vector<T> vector) {
    std::vector<int> v;
    vector.assign(9900 * _ratio, 1);
    vector.resize(5000 * _ratio);
    vector.reserve(5000 * _ratio);
	std::cout << vector.capacity();
    v.push_back(vector.size());
    v.push_back(vector.capacity());
	std::cout << 7000 * _ratio << std::endl;
    vector.resize(7000 * _ratio);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.resize(15300 * _ratio, T());
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    v.push_back(vector[65]);
    return v;
}


int main() {
	std::vector<int> vector =  resize_test(std::vector<int>());
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << std::endl;

}