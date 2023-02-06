/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdy <ahamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:29:31 by ahamdy            #+#    #+#             */
/*   Updated: 2023/02/06 11:21:56 by ahamdy           ###   ########.fr       */
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
		typedef T value_type;
		typedef typename ft::vector_iterator<T*> iterator;
		typedef typename ft::vector_iterator<const T*> const_iterator;
		typedef std::size_t  size_type;
		typedef  ptrdiff_t difference_type;
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
		{}
		explicit vector(size_type n, const T& value = T(),
		const Allocator& = Allocator())
		{
			for (int i = 0; i < n; i++)
				push_back(value);
		}
		// template <class InputIterator>
		// vector(InputIterator first, InputIterator last,
		// const Allocator& = Allocator());
		vector(const vector<T,Allocator>& x);
		// ~vector();
		// vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
		// template <class InputIterator>
		// void assign(InputIterator first, InputIterator last);
		// void assign(size_type n, const T& u);
		allocator_type get_allocator() const
		{ return _alloc;}
	// ******** ITERATORS ************
		iterator begin()
		{
			return (iterator(_array));
		}
		const_iterator begin() const
		{ return (const_iterator(_array)); }
		iterator end()
		{
			if (this->empty())
				return (begin());
			return (iterator(_array + size()));
		}
		const_iterator end() const
		{ return (const_iterator(_array + size())); }
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;
	// ************ capacity *****************
	 		size_type size() const
			{ return (_size); }
			size_type max_size() const
			{ return _alloc.max_size();}
			void resize(size_type n, value_type c = value_type())
			{
				if (_size == n)
					return ;
				value_type *new_type = _alloc.allocate(n);
				for (int i = 0; i < n; i++)
				{
					if (n >= _size)
						_alloc.construct(new_type  + i, c);
					else
					_alloc.construct(new_type + i, std::move(_array[i]));
				}
				for (int i = 0; i < _size; i++)
					_alloc.destroy(_array + i);
				_alloc.deallocate(_array, _capacity);
				_array = new_type;
				_capacity = n;
				_size = n;
			}
			size_type capacity() const
			{ return (_capacity);}
			bool empty() const
			{
				if (!_size)
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
				this->_capacity = n;
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
		reference front()
		{
			return (*_array);
		}
		const_reference front() const
		{
			return(*_array);
		}
		reference back()
		{
			return (*_array + size() - 1);
		}
		const_reference back() const
		{
			return (*_array + size() + 1);
		}
	// ***********operators********************
		template <class value_type, class allocator_type>  
		bool operator== (const vector<value_type,allocator_type>& rhs)
		{
			if (_size == rhs.size())
			{
				for(int i = 0; i < rhs.size(); i++)
				{
					if (rhs[i] != _array[i])
						return (0);
				}
			}
			else
				return (0);
			return (1);
		}
		template <class value_type, class allocator_type> 
		bool operator!= (const vector<value_type,allocator_type>& rhs)
		{ return (!(*this == rhs)); }
		template <class value_type, class allocator_type> 
		bool operator<  (const vector<value_type,allocator_type>& rhs)
		{
			if (_size < rhs.size())
			{
				for(int i = 0; i < rhs.size(); i++)
				{
					if (rhs[i] > _array[i])
						return (0);
				}
			}
			else
				return (0);
			return (1);
		}
		template <class value_type, class allocator_type> 
		bool operator> (const vector<value_type,allocator_type>& rhs)
		{ return (!(*this < rhs)); }
		template <class value_type, class allocator_type> 
		bool operator<= (const vector<value_type,allocator_type>& rhs)
		{ return ((*this < rhs)  | (*this == rhs)); }
		template <class value_type, class allocator_type>
		bool operator>= (const vector<value_type,allocator_type>& rhs)
		{ return ((*this > rhs)  | (*this == rhs));}
	// ************ MODIFIERS ******************
		void push_back(const value_type& x)
		{
			if (_size == _capacity)
			{
				if (!_capacity)
					_capacity += 1;
				this->reserve(_capacity * 2);
			}
			_array[_size] = x;
			_size += 1;
		}
		void pop_back()
		{
			size_type n = _size - 1;
			value_type *new_data = _alloc.allocate(_capacity);
			for (int i = 0; i < n; i++)
				_alloc.construct(new_data + i, std::move(_array[i]));
			for (int i = 0; i < _size; i++)
				_alloc.destroy(_array + i);
			_alloc.deallocate(_array, _capacity);
			_array = new_data;
			_size = n;
		}
		iterator insert(iterator position, const value_type& x)
		{
			int p_index = position - begin();
			value_type tmp;

			if (position == this->end())
			{
				push_back(x);
			}
			else if (_size == _capacity)
			{
				value_type *new_data = _alloc.allocate(_size + 1);
				_size += 1;
				int i_2 = 0;
				for (int i = 0; i_2 < _size + 1; i++)
				{
					if (p_index  == i_2)
					{
						_alloc.construct(new_data + i_2, x);
						i--;
					}
					else 
					_alloc.construct(new_data + i_2, std::move(_array[i]));
					i_2++;
				}
				for (int i = 0; i < _size; i++)
					_alloc.destroy(_array + i);
				_alloc.deallocate(_array, _capacity);
				_array = new_data;
				_capacity += 1;
			}
			else
			{
				value_type tmp_2;
				tmp_2 = x;
				_size += 1;
				for (int i = p_index; i < _size; i++)
				{
					tmp = _array[i];
					_array[i] = tmp_2;
					tmp_2 = tmp;
				}
			}
			return (begin() + p_index);
		}
		void insert(iterator position, size_type n, const T& x)
		{
			int p_index = position - begin();
			for (int i = 0; i < n; i++)
				insert(begin() + p_index, x);
		}
		// template <class InputIterator>
		// void insert(iterator position,
		// InputIterator first, InputIterator last);
		iterator erase (iterator first, iterator last)
		{
			int p_index = first - begin();
			if (last == end())
			{
				while (first < last)
				{
					last--;
					pop_back();
				}
			}
			else
			{
				// std::cout << "size = " << _size << std::endl;
				value_type *new_data = _alloc.allocate(_size - (last - first));
				for (int i = 0; i < _size - (last - first); i++)
				{
					if (p_index  == i)
					{
						p_index++;
					}
					else
					_alloc.construct(new_data + i, std::move(_array[i]));
					// std::cout << "i_2 = " << i_2 << std::endl;
					// std::cout << "i = " << i << std::endl;
				}
				for (int i = 0; i < _size; i++)
					_alloc.destroy(_array + i);
				_alloc.deallocate(_array, _capacity);
				_size -= last - first;
				_array = new_data;
				_capacity += 1;
			}
		}
		// iterator erase(iterator first, iterator last);
		void swap(vector<value_type, allocator_type>& copy)
		{
			value_type *tmp_array = copy._array;
			size_type tmp_capacity = copy._capacity;
			size_type tmp_size = copy._size;

			copy._array = _array;
			copy._capacity = _capacity;
			copy._size = _size;
			_array = tmp_array;
			_capacity = tmp_capacity;
			_size = tmp_size;
		}
		void clear()
		{
			int i;

			for (i = 0; i < _size; i++)
				_alloc.destroy(_array + i);
			_size = 0;
		}
};
}