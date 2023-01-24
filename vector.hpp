/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:29:31 by ahamdy            #+#    #+#             */
/*   Updated: 2023/01/24 17:00:21 by ahamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<memory>

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
	public:
	// ************* TYPES ***********************
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		// typedef implementation defined iterator;
		// typedef implementation defined const_iterator;
		typedef  unsigned int  size_type;
		// typedef implementation defined difference_type;
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		// typedef std::reverse_iterator<iterator> reverse_iterator;
		// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	private :
		size_type _size;
		size_type _capacity;
		value_type*	_array;
		allocator_type _alloc;
	public :
	// *********** CONSTRUCTORS/DISTRUCTOR ****************
		explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc) , _size() , _capacity(), _array()
		{
			std::cout << "default constructor\n";
		}
		// explicit vector(size_type n, const T& value = T(),
		// const Allocator& = Allocator());
		// template <class InputIterator>
		// vector(InputIterator first, InputIterator last,
		// const Allocator& = Allocator());
		// vector(const vector<T,Allocator>& x);
		// ~vector();
		// vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
		// template <class InputIterator>
		// void assign(InputIterator first, InputIterator last);
		// void assign(size_type n, const T& u);
		// allocator_type get_allocator() const;
	// ******** ITERATORS ************
		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;
	// ************ capacity *****************
	 		size_type size() const
			{ return (_size); }
	/*		size_type max_size() const;
			void resize(size_type sz, T c = T()); */
			size_type capacity() const
			{ return (_capacity);}
			bool empty() const
			{
				if (_size)
					return (1);
				return (0);
			}
			void reserve(size_type n)
			{
				if (n <= _capacity) return;
				value_type *new_data = _alloc.allocate(n);
				for (int i = 0; i < _size; i++)
					_alloc.construct(new_data + i, std::move(_array[i]));
				for (int i = 0; i < _size; i++)
					_alloc.destroy(_array + i);
				_alloc.deallocate(_array, _capacity);
				_array = new_data;
				_capacity = n;
			}
	// ************** ELEMENT ACCESS ****************
		reference operator[](size_type n)
		{ return (_array[n]); }
		const_reference operator[](size_type n) const
		{ return (_array[n]); }
		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("out of range");
			return (this->operator[](n));
		}
		reference at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("out of range");
			return (this->operator[](n));
		}
		// reference front();
		// const_reference front() const;
		// reference back();
		// const_reference back() const;
	// ************ MODIFIERS ******************
		// void push_back(const value_type& x)
		// {
			
		// }
		// void pop_back();
		// iterator insert(iterator position, const T& x);
		// void insert(iterator position, size_type n, const T& x);
		// template <class InputIterator>
		// void insert(iterator position,
		// InputIterator first, InputIterator last);
		// iterator erase(iterator position);
		// iterator erase(iterator first, iterator last);
		// void swap(vector<T,Allocator>&);
		// void clear(); 
};
}