#include <iostream>
#include <memory>
#include<vector>
#include "vector.hpp"

#include "ft_containers-unit-test/sources/system/lib.hpp"


// class B {
// public:
//     char *l;
//     int i;
//     B():l(nullptr), i(1) {};
//     B(const int &ex) {
//         this->i = ex;
//         this->l = new char('a');
//     };
//     virtual ~B() {
//         delete this->l;
//         this->l = nullptr;
//     };
// };

// class A : public B {
// public:
//     A():B(){};
//     A(const B* ex){
//         this->l = new char(*(ex->l));
//         this->i = ex->i;
//         if (ex->i == -1) throw "n";
//     }
//     ~A() {
//         delete this->l;
//         this->l = nullptr;
//     };
// };

// template <typename T>
// std::vector<int> insert_test_3(std::vector<T> vector) {
//     std::vector<int> v;
//     std::vector<int> tmp;
//     tmp.assign(4, 1);
//     vector.assign(2, 1);
//     vector.insert(vector.end(), tmp.begin(), tmp.end());
//     v.push_back(vector[3]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
// 	std::cout << "STD : " <<vector.size() << std::endl;
// 	std::cout << "STD: " <<vector.capacity() << std::endl;
// 	// return v;
//     std::unique_ptr<B> k2(new B(3));
//     std::unique_ptr<B> k3(new B(4));
//     std::unique_ptr<B> k4(new B(-1));
//     std::vector<A> vv;
//     std::vector<B*> v1;

//     v1.push_back(&(*k2));
//     v1.push_back(&(*k3));
//     v1.push_back(&(*k4));
//     try {std::cout <<"STD: " << v1.size() << std::endl;
// 	std::cout << "STD: " << vv.capacity() << std::endl;
// 	 vv.insert(vv.begin(), v1.begin(), v1.end()); }
//     catch (...) {
//         v.push_back(vv.size());
//         v.push_back(vv.capacity());
//     }

//     return v;
// }

// template <typename T>
// std::vector<int> insert_test_3(_vector<T> vector) {
//     std::vector<int> v;
//     _vector<int> tmp;
//     tmp.assign(4, 1);
//     vector.assign(2, 1);
//     vector.insert(vector.end(), tmp.begin(), tmp.end());
//     v.push_back(vector[3]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
// 	std::cout << "FT: " << vector.size() << std::endl;
// 	std::cout << "FT: " << vector.capacity() << std::endl;
// 	// return v;
//     std::unique_ptr<B> k2(new B(3));
//     std::unique_ptr<B> k3(new B(4));
//     std::unique_ptr<B> k4(new B(-1));
//     _vector<A> vv;
//     _vector<B*> v1;

//     v1.push_back(&(*k2));
//     v1.push_back(&(*k3));
//     v1.push_back(&(*k4));
//     try {
// 	std::cout <<"FTs: " << v1.size() << std::endl;
// 	std::cout << "FTs: " << vv.capacity() << std::endl;
// 		 vv.insert(vv.begin(), v1.begin(), v1.end()); 
// 		 }
//     catch (...) {
//         v.push_back(vv.size());
//         v.push_back(vv.capacity());
	
//     }

//     return v;
// }

// int main() {
// 	 (insert_test_3((ft::vector<int>())));
// 		// std::cout << "Gotcha i don't throw exception\n";
// 	system("leaks a.out");
// 	// std::cout <<  ((constructor_test(std::vector<int>())) ==  (constructor_test(ft::vector<int>())))  << std::endl;
// }




class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};

template <typename T>
std::vector<int> insert_test_3(std::vector<T> vector) {
    std::vector<int> v;
    std::vector<int> tmp;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 1);
    vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    v.push_back(vector[3]);
    v.push_back(vector.size());
	std::cout << "STD : "  << vector.size() << std::endl;
	std::cout << "STD: " << vector.capacity() << std::endl;
    v.push_back(vector.capacity());

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    std::vector<A> vv;
    std::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }

    return v;
}

template <typename T>
std::vector<int> insert_test_3(_vector<T> vector) {
    std::vector<int> v;
    _vector<int> tmp;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 1);
	std::cout << vector.size() * 2 << std::endl;
    vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    v.push_back(vector[3]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
	std::cout << "ft : "  << vector.size() << std::endl;
	std::cout << "ft: " << vector.capacity() << std::endl;
    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    _vector<A> vv;
    _vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }

    return v;
}


int main() {
	 std::cout << (insert_test_3((ft::vector<int>())) == insert_test_3((std::vector<int>())));
		// std::cout << "Gotcha i don't throw exception\n";
	system("leaks a.out");
	// std::cout <<  ((constructor_test(std::vector<int>())) ==  (constructor_test(ft::vector<int>())))  << std::endl;
}


