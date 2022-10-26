#pragma once
#include<iostream>
using namespace std;
namespace sx
{
	template<class T>
	struct list_node
	{
		typedef list_node<T> Node;
		list_node<T>(const T& data = T())
			:
			_data(data),
			_prev(nullptr),
			_next(nullptr)
		{}
		T _data;
		Node* _prev;
		Node* _next;
	};

	template<class T, class Ref, class Ptr>
	struct list_iterator
	{
		typedef list_node<T> Node;
		typedef list_iterator<T, Ref, Ptr> self;
		list_iterator(Node* const pnode)
			:
			_pnode(pnode)
		{}
		Ref operator*()const
		{
			return _pnode->_data;
		}
		Ptr operator->()const
		{
			return &_pnode->_data;
		}
		self& operator++()
		{
			_pnode = _pnode->_next;
			return *this;
		}
		self operator++(int)
		{
			self tmp(*this);
			++(*this);
			return tmp;
		}
		self& operator--()
		{
			_pnode = _pnode->_prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(*this);
			--(*this);
			return tmp;
		}
		bool operator!=(const self& it)const
		{
			return _pnode != it._pnode;
		}
		bool operator==(const self& it)const
		{
			return _pnode == it._pnode;
		}
		Node* _pnode;
	};
	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:

		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		
		typedef Reverse_iterator<iterator, T*, T&> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T*, const T&> const_reverse_iterator;

		list<T>()
			:
			_head(new Node)
		{
			_head->_next = _head;
			_head->_prev = _head;
		}
		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		reverse_iterator rbegin()
		{
			return end();
		}

		reverse_iterator rend()
		{
			return begin();
		}

		const_reverse_iterator rbegin()const
		{
			return end();
		}

		const_reverse_iterator rend()const
		{
			return begin();
		}

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}

		template<class InputIterator>
		list<T>(InputIterator first, InputIterator last)
			:
			_head(new Node)
		{
			_head->_next = _head;
			_head->_prev = _head;
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list<T>(const list<T>& lt)
			:
			_head(new Node)
		{
			_head->_next = _head;
			_head->_prev = _head;
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}
		list<T>operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}
		~list<T>()
		{
			/*Node* cur = _head->_next;
			while (cur != _head)
			{
				Node* next = cur->_next;
				delete cur;
				cur = next;
			}*/
			clear();
			delete _head;
			_head = nullptr;
		}
		void push_back(const T& val)
		{
			/*Node* newnode = new Node(val);
			Node* tail = _head->_prev;
			Node* head = _head;
			newnode->_next = _head;
			_head->_prev = newnode;
			tail->_next = newnode;
			newnode->_prev = tail;*/
			insert(_head, val);
		}
		void push_front(const T& val)
		{
			insert(_head->_next, val);
		}
		iterator insert(iterator pos, const T& val)
		{
			Node* newnode = new Node(val);
			Node* prev = pos._pnode->_prev;
			Node* next = pos._pnode;
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = next;
			next->_prev = newnode;
			return iterator(newnode);
		}
		iterator erase(iterator pos)
		{
			Node* prev = pos._pnode->_prev;
			Node* next = pos._pnode->_next;
			prev->_next = next;
			next->_prev = prev;
			delete pos._pnode;
			return next;
		}
		void pop_back()
		{
			erase(_head->_prev);
		}
		void pop_front()
		{
			erase(_head->_next);
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
	private:
		Node* _head;
	};
}