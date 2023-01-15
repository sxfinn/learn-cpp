#pragma once
#include"HashTable.h"

namespace sx
{
	template<class K, class HashFunc = DefaultHash<K>>
	class unordered_set
	{
		struct KeyOfSet
		{
			K operator()(const K& data)
			{
				return data;
			}
		};
	public:
		typedef typename HashTable<K, K, KeyOfSet, HashFunc>::Iterator iterator;

		unordered_set() = default;

		unordered_set(unordered_set& set)
			:
			_ht(set._ht)
		{}

		unordered_set& operator=(unordered_set& set)
		{
			_ht = set._ht;
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

		pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}

		iterator erase(const K& key)
		{
			return _ht.Erase(key);
		}

		iterator find(const K& key)
		{
			return _ht.Find(key);
		}

	private:
		HashTable<K, K, KeyOfSet, HashFunc> _ht;
	};
}