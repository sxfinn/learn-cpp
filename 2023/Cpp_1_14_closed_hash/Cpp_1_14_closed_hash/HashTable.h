#pragma once
#include<vector>
#include<string>
using namespace std;

namespace sx
{
	enum Status
	{
		EMPTY,
		EXIST,
		DELETED
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		Status _state = EMPTY;
	};

	template<class K>
	struct DefaultHash
	{
		size_t operator()(const K& key)
		{
			return key;
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

	template<class K, class V, class HashFunc = DefaultHash<K>>
	class HashTable
	{
		typedef HashData<K, V> Data;
	public:
		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;
			HashFunc hf;
			if (_table.size() == 0 || _n * 10 / _table.size() >= 7)
			{
				size_t newSize = _table.size() == 0 ? 7 : 2 * _table.size();
				HashTable<K, V, HashFunc> newHashTable;
				newHashTable._table.resize(newSize);
				for (auto& e : _table)
				{
					if (e._state == EXIST)
					{
						newHashTable.Insert(e._kv);
					}
				}
				newHashTable.Insert(kv);
				_table.swap(newHashTable._table);
				_n++;
			}
			else
			{
				size_t starti = hf(kv.first);
				starti %= _table.size();
				size_t hashi = starti;
				size_t i = 1;
				while (_table[hashi]._state == EXIST)
				{
					hashi = starti + i;//线性探测
					++i;
					hashi %= _table.size();
				}
				_table[hashi]._kv = kv;
				_table[hashi]._state = EXIST;
				_n++;
			}
			return true;
		}


		Data* Find(const K& key)
		{
			if (_table.size() == 0)
				return nullptr;
			HashFunc hf;
			size_t starti = hf(key);
			starti %= _table.size();
			size_t hashi = starti;
			size_t i = 1;
			while (_table[hashi]._state != EMPTY)
			{
				if (_table[hashi]._state == EXIST && _table[hashi]._kv.first == key)
				{
					return &_table[hashi];
				}
				hashi = starti + i;
				++i;
				hashi %= _table.size();
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			Data* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETED;
				_n--;
				return true;
			}
			else
			{
				return false;
			}
		}

		size_t Size()
		{
			return _n;
		}

		bool Empty()
		{
			return _n == 0;
		}

		void Swap(HashTable<K, V, HashFunc>& ht)//交换得保证模板参数也要相同（即必须是同一类型）
		{
			_table.swap(ht._table);
			std::swap(_n, ht._n);
		}
	private:
		vector<Data> _table;
		size_t _n = 0;
	};
}