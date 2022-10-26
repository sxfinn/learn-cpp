#pragma once

namespace sx
{
	template<class Iterator, class Ptr, class Ref>
	struct Reverse_iterator
	{
		typedef Reverse_iterator<Iterator, Ptr, Ref> self;
		Reverse_iterator(Iterator it)
			:
			_it(it)
		{}

		self operator++()
		{
			--_it;
			return *this;
		}
		
		self operator--()
		{
			++_it;
			return *this;
		}

		Ref operator*()const
		{
			Iterator tmp = _it;
			return *(--tmp);
		}

		Ptr operator->()const
		{
			return &(operator*());
		}

		bool operator!=(const self& rit)const
		{
			return _it != rit._it;
		}

		Iterator _it;
	};
}