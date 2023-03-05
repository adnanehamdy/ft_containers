namespace ft {
	template <class Iterator>
	class reverse_iterator {
		protected:
		Iterator current;
		public:
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef  typename iterator_traits<Iterator>::value_type value_type;
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::reference reference;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		reverse_iterator() : current()
		{}
		explicit reverse_iterator(Iterator x)
		{
			current = x;
		}
		template <class U> reverse_iterator(const reverse_iterator<U>& u)
		{
			current = u.current;
		}
		Iterator base()	const
		{
			return (current);
		}
		reference operator*() const
		{
			Iterator tmp = current;
			return *--tmp;
		}
		pointer operator->() const
		{
			return &(operator*());
		}
		reverse_iterator& operator++()
		{
			--current;
			return (*this);
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			--current;
			return tmp;
		}
		reverse_iterator& operator--()
		{
			++current;
			return (*this);
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			++current;
			return tmp;
		}
		reverse_iterator operator+ (difference_type n) const
		{
			return (reverse_iterator(current-n));
		}
		reverse_iterator& operator+=(difference_type n)
		{
			current -= n;
			return(*this);
		}
		reverse_iterator operator- (difference_type n) const
		{
			return (reverse_iterator(current+n));
		}
		reverse_iterator& operator-=(difference_type n)
		{
			current += n;
			return (*this);
		}
		reference operator[](difference_type n) const
		{
			return (current[-n-1]);
		}
		template< typename relational_Iterator>
		friend bool operator==(const reverse_iterator<relational_Iterator>& x, const reverse_iterator<relational_Iterator>& y);
		template<typename relational_Iterator>
		friend bool operator<(const reverse_iterator<relational_Iterator>& x, const reverse_iterator<relational_Iterator>& y);
		template<typename relational_Iterator>
		friend bool operator!=(const reverse_iterator<relational_Iterator>& x, const reverse_iterator<relational_Iterator>& y);
		template<typename relational_Iterator>
		friend bool operator>(const reverse_iterator<relational_Iterator>& x, const reverse_iterator<relational_Iterator>& y);
		template<typename relational_Iterator>
		friend bool operator>=(const reverse_iterator<relational_Iterator>& x, const reverse_iterator<relational_Iterator>& y);
		template<typename relational_Iterator>
		friend bool operator==(const reverse_iterator<relational_Iterator>& x, const reverse_iterator<relational_Iterator>& y);
		template<typename relational_Iterator>
		friend bool operator<=(const reverse_iterator<relational_Iterator>& x, const reverse_iterator<relational_Iterator>& y);
		template<typename relational_Iterator>
		friend typename reverse_iterator<relational_Iterator>::difference_type operator-(const reverse_iterator<relational_Iterator>& x, const reverse_iterator<relational_Iterator>& y);
		template<typename relational_Iterator>
		friend reverse_iterator<relational_Iterator> operator+(typename reverse_iterator<relational_Iterator>::difference_type n, const reverse_iterator<relational_Iterator>& x);
		};
		template <class relational_Iterator>
		bool operator==(
		const reverse_iterator<relational_Iterator>& x,
		const reverse_iterator<relational_Iterator>& y)
		{
			x.current == y.current;
		}
		template <class relational_Iterator>
		bool operator<(
		const reverse_iterator<relational_Iterator>& x,
		const reverse_iterator<relational_Iterator>& y)
		{
			x.current > y.current;
		}
		template <class relational_Iterator>
		bool operator!=(
		const reverse_iterator<relational_Iterator>& x,
		const reverse_iterator<relational_Iterator>& y)
		{
			x.current != y.current;
		}
		template <class relational_Iterator>
		bool operator>(
		const reverse_iterator<relational_Iterator>& x,
		const reverse_iterator<relational_Iterator>& y)
		{
			x.current < y.current;
		}
		template <class relational_Iterator>
		bool operator>=(
		const reverse_iterator<relational_Iterator>& x,
		const reverse_iterator<relational_Iterator>& y)
		{
			x.current <= y.current;
		}
		template <class relational_Iterator>
		bool operator<=(
		const reverse_iterator<relational_Iterator>& x,
		const reverse_iterator<relational_Iterator>& y)
		{
			x.current >= y.current;
		}
		template <class relational_Iterator>
		typename reverse_iterator<relational_Iterator>::difference_type operator-(
		const reverse_iterator<relational_Iterator>& x,
		const reverse_iterator<relational_Iterator>& y)
		{
			y.current - x.current;
		}
		template <class relational_Iterator>
		reverse_iterator<relational_Iterator> operator+(
		typename reverse_iterator<relational_Iterator>::difference_type n,
		const reverse_iterator<relational_Iterator>& x)
		{
			return (reverse_iterator<relational_Iterator> (x.current - n));
		}
	template <typename Iterator>
	class const_reverse_iterator : ft::reverse_iterator<const Iterator>
	{
		const typename ft::reverse_iterator<const Iterator>::reference operator*() const
		{
			Iterator tmp = this->current;
			return *--tmp;
		}
		const typename ft::reverse_iterator<const Iterator>::reference operator->() const
		{
			return &(operator*());
		}
	};
}