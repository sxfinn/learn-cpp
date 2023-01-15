#pragma once
#include"HashTable.h"

namespace sx
{
	template<class K, class V, class HashFunc = DefaultHash<K>>
	class unordered_map
	{
		struct KeyOfMap
		{
			K operator()(const pair<K, V>& data)
			{
				return data.first;
			}
		};
	public:
		typedef typename HashTable<K, pair<K, V>, KeyOfMap, HashFunc>::Iterator iterator;

		unordered_map() = default;

		unordered_map(unordered_map& map)
			:
			_ht(map._ht)
		{}

		unordered_map& operator=(unordered_map& map)
		{
			_ht = map._ht;
			return *this;
		}

		iterator begin()
		{
			return _ht.Begin();
		}

		iterator end()
		{
			return _ht.End();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		iterator find(const K& key)
		{
			return _ht.Find(key);
		}

		iterator erase(const K& key)
		{
			return _ht.Erase(key);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> pr = insert(make_pair(key, V()));
			return (pr.first)->second;
		}

	private:
		HashTable<K, pair<K, V>, KeyOfMap, HashFunc> _ht;
	};
}