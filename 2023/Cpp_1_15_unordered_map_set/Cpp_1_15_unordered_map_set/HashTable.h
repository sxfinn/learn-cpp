#pragma once
#include<vector>
#include<string>
#include<assert.h>
using namespace std;

namespace sx
{
	template<class T>
	struct HashNode
	{
		HashNode(const T& data)
			:
			_data(data),
			_next(nullptr)
		{}
		T _data;
		HashNode<T>* _next;
	};

	template<class K>
	struct DefaultHash
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};

	template<>
	struct DefaultHash<string>
	{
		size_t operator()(const string& str)
		{
			size_t ret = 0;
			for (auto& e : str)
			{
				ret = ret * 131 + (size_t)e;
			}
			return ret;
		}
	};

	template<class K, class T, class KeyOfData, class HashFunc> //声明模板类HashTable
	class HashTable;

	template<class K, class T, class KeyOfData, class HashFunc>
	struct __HTIterator
	{
		typedef HashNode<T> Node;
		typedef __HTIterator<K, T, KeyOfData, HashFunc> Self;

		__HTIterator(){}

		__HTIterator(Node* pNode, HashTable<K, T, KeyOfData, HashFunc>* pHT)
			:
			_pNode(pNode),
			_pHT(pHT)
		{}

		Self& operator++()
		{
			assert(_pNode);
			if (_pNode->_next)
			{
				_pNode = _pNode->_next;
			}
			else
			{
				KeyOfData kod;
				HashFunc hf;
				size_t hashi = hf(kod(_pNode->_data)) % ((_pHT->_table).size());
				++hashi;
				while (hashi < (_pHT->_table).size() && _pHT->_table[hashi] == nullptr)
				{
					++hashi;
				}
				if (hashi < (_pHT->_table).size())
					_pNode = _pHT->_table[hashi];
				else
					_pNode = nullptr;
			}
			return *this;
		}

		Self operator++(int)
		{
			Self tmp = *this;
			++(*this);
			return tmp;
		}

		T& operator*()
		{
			return _pNode->_data;
		}

		T* operator->()
		{
			return &_pNode->_data;
		}

		bool operator==(const Self& it)const
		{
			return _pNode == it._pNode;
		}

		bool operator!=(const Self& it)const
		{
			return _pNode != it._pNode;
		}

		HashTable<K, T, KeyOfData, HashFunc>* _pHT;
		Node* _pNode;
	};

	template<class K, class T, class KeyOfData, class HashFunc>
	class HashTable
	{
	public:
		typedef __HTIterator<K, T, KeyOfData, HashFunc> Iterator;
	private:
		typedef HashNode<T> Node;
		friend Iterator;
	public:
		HashTable() = default;

		HashTable(HashTable& ht)
		{
			Iterator it = ht.Begin();
			while (it != ht.End())
			{
				Insert(*it);
				++it;
			}
		}

		HashTable& operator=(HashTable ht)
		{
			_table.swap(ht._table);
			std::swap(_n, ht._n);
			return *this;
		}

		~HashTable()
		{
			for (auto& e : _table)
			{
				Node* cur = e;
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				e = nullptr;
			}
			_n = 0;
		}

		size_t GetNextPrime(size_t prime)
		{
			const int PRIMECOUNT = 28;
			static const size_t primeList[PRIMECOUNT] =
			{
				53ul, 97ul, 193ul, 389ul, 769ul,
				1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
				49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
				1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
				50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
				1610612741ul, 3221225473ul, 4294967291ul
			};

			// 获取比prime大那一个素数
			size_t i = 0;
			for (; i < PRIMECOUNT; ++i)
			{
				if (primeList[i] > prime)
					return primeList[i];
			}

			return primeList[i];
		}

		pair<Iterator, bool> Insert(const T& data)
		{
			KeyOfData kod;
			HashFunc hf;
			Iterator pos = Find(kod(data));
			if (pos != End())
			{
				return pair<Iterator, bool>(pos, false);
			}

			if (_n == _table.size())//扩容
			{
				size_t newSize = _table.size() == 0 ? 23 : GetNextPrime(_table.size());
				vector<Node*> newTable;
				newTable.resize(newSize, nullptr);
				for (auto& e : _table)
				{
					Node* cur = e;
					while (cur)
					{
						Node* next = cur->_next;
						size_t hashi = hf(kod(cur->_data)) % newTable.size();
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;
						cur = next;
					}
				}
				newTable.swap(_table);
			}

			size_t hashi = hf(kod(data)) % _table.size();
			Node* newNode = new Node(data);
			newNode->_next = _table[hashi];
			_table[hashi] = newNode;
			_n++;
			return make_pair(Iterator(newNode, this), false);
		}

		Iterator Find(const K& key)
		{
			if (_table.size() == 0)
			{
				return Iterator(nullptr, this);
			}
			HashFunc hf;
			KeyOfData kod;
			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			while (cur)
			{
				if (kod(cur->_data) == key)
				{
					return Iterator(cur, this);
				}
				cur = cur->_next;
			}
			return Iterator(nullptr, this);
		}

		Iterator Begin()
		{
			for (auto& e : _table)
			{
				if (e)
					return Iterator(e, this);
			}
			return End();
		}

		Iterator End()
		{
			return Iterator(nullptr, this);
		}

		Iterator Erase(const K& key)
		{
			Iterator it = Find(key);
			Node* p = it._pNode;
			if (p)
			{
				HashFunc hf;
				size_t hashi = hf(key) % _table.size();
				Node* pHead = _table[hashi];
				Iterator ret = ++it;
				std::swap(pHead->_data, p->_data);
				_table[hashi] = pHead->_next;
				delete pHead;
				_n--;
				return ret;
			}
			else
			{
				return Iterator(nullptr, this);
			}
		}
	private:
		vector<Node*> _table;
		size_t _n = 0;
	};
}
