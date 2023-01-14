#pragma once
#include<iostream>
#include<vector>
namespace sx
{
	enum Status
	{
		EXIST,
		DELETED,
		EMPTY
	};

	template<class K, class V>
	struct HashData
	{
		HashData()
			:
			_key(0),
			_value(0),
			_state(EMPTY)
		{}
		K _key;
		V _value;
		Status _state;
	};

	template<class K, class V>
	class HashTable
	{
	public:
		HashTable()
			:
			_table(nullptr),
			_n(0),
			_size(0)
		{}

		~HashTable()
		{
			if(_table)
				delete _table;
			_n = _size = 0;
		}

		bool insert(const K& key, const V& value)
		{
			if (find(key))
				return false;
			if (_size == 0)
			{
				_size = 10;
				_table = new HashData<K, V>[_size];
				size_t hashi = key % _size;
				_table[hashi]._key = key;
				_table[hashi]._value = value;
				_table[hashi]._state = EXIST;
				++_n;
				return true;
			}
			else if (_n * 10 / _size >= 7)
			{
				size_t newsize =  2 * _size;
				HashTable new_hashtable;
				new_hashtable._table = new HashData<K, V>[newsize];
				new_hashtable._size = newsize;
				new_hashtable._n = 0;

				for (int i = 0; i < _size; ++i)
				{
					if(_table[i]._state == EXIST)
						new_hashtable.insert(_table[i]._key, _table[i]._value);
				}
				new_hashtable.insert(key, value);
				std::swap(_table, new_hashtable._table);
				++_n;
				_size = newsize;
				return true;
			}
			else
			{
				size_t hashi = key % _size;
				while (_table[hashi]._state == EXIST)
				{
					++hashi;
					if (hashi == _size)
						hashi = 0;
				}
				_table[hashi]._key = key;
				_table[hashi]._value = value;
				_table[hashi]._state = EXIST;
				++_n;
				return true;
			}
		}

		HashData<K, V>* find(const K& key)
		{
			if (_size == 0)
				return nullptr;
			size_t hashi = key % _size;
			while (_table[hashi]._state != EMPTY)
			{
				if (_table[hashi]._state == EXIST && _table[hashi]._key == key)
				{
					return &_table[hashi];
				}
				++hashi;
			}
			return nullptr;
		}

		bool erase(const K& key)
		{
			HashData<K, V>* ret = find(key);
			if (ret)
			{
				ret->_state = DELETED;
				_n--;
				return true;
			}
			else
				return false;
		}
	private:
		HashData<K, V>* _table;
		size_t _n;
		size_t _size;
	};
}