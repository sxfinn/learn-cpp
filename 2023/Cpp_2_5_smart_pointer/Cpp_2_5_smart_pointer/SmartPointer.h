#pragma once
#include<iostream>
using namespace std;
namespace sx
{
	template<class T>
	struct DefaultDelete
	{
		void operator()(T* ptr)
		{
			delete ptr;
		}
	};


	template<class T, class D = DefaultDelete<T>>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:
			_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}

		unique_ptr(const unique_ptr<T, D>& up) = delete;
		unique_ptr<T, D>& operator=(const unique_ptr<T, D>& up) = delete;

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()const
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};



	template<class T, class D = DefaultDelete<T>>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:
			_ptr(ptr)
		{}

		~auto_ptr()
		{
			if (_ptr)
			{
				D del;
				del(_ptr);
				_ptr = nullptr;
			}
		}

		auto_ptr(auto_ptr<T, D>& ap)
			:
			_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		auto_ptr<T, D>& operator=(auto_ptr<T, D>& ap)
		{
			_ptr = ap._ptr;
			ap._ptr = nullptr;
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()const
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};



	template<class T, class D = DefaultDelete<T>>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:
			_ptr(ptr),
			_pCount(new int(1))
		{}

		~shared_ptr()
		{
			if (--(*_pCount) == 0 && _ptr)
			{
				cout << "~shared_ptr()" << endl;
				D del;
				del(_ptr);
				_ptr = nullptr;
				del(_pCount);
				_pCount = nullptr;
			}
		}

		shared_ptr(const shared_ptr<T, D>& sp)
			:
			_ptr(sp._ptr),
			_pCount(sp._pCount)
		{
			(*_pCount)++;
		}

		shared_ptr<T, D>& operator=(shared_ptr<T, D>& sp)
		{
			if (_ptr == sp._ptr)
				return *this;
			if (--(*_pCount) == 0 && _ptr)
			{
				D del;
				del(_ptr);
				_ptr = nullptr;
				del(_pCount);
				_pCount = nullptr;
			}
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			(*_pCount)++;
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()const
		{
			return _ptr;
		}

		int use_count()const
		{
			return *_pCount;
		}

	private:
		T* _ptr;
		int* _pCount;
	};



	template<class T, class D = DefaultDelete<T>>
	class weak_ptr
	{
	public:
		weak_ptr()
			:
			_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T, D>& sp)
			:
			_ptr(sp.get())
		{}

		weak_ptr& operator=(const shared_ptr<T, D>& sp)
		{
			_ptr = sp.get();
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()const
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};
}
