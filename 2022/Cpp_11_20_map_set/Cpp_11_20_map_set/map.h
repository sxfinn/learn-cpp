#pragma once
#include"RBtree.h"

namespace sx
{
	
	template<class K, class V>
	class map
	{
		struct KeyOfMap
		{
			const K& operator()(const pair<K, V>& data)//·µ»ØKEYÖµ
			{
				return data.first;
			}
		};
		typedef RBTree<K, pair<K, V>, KeyOfMap> RBT_KV;
		
	public:
		typedef typename RBTree<K, pair<K, V>, KeyOfMap>::_iterator iterator;
		typedef typename RBTree<K, pair<K, V>, KeyOfMap>::_const_iterator const_iterator;

		iterator begin()
		{
			return _t.Begin();
		}

		iterator end()
		{
			return _t.End();
		}

		const_iterator begin()const
		{
			return _t.Begin();
		}

		const_iterator end()const
		{
			return _t.End();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}

		const_iterator find(const K& key)const
		{
			return _t.Find(key);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
			return (ret.first)->second;
		}

		void swap(map<K, V>& x)
		{
			_t.swap(x._t);
		}

		void clear()const
		{
			_t.~RBTree();
		}

		bool empty()const
		{
			return _t.Empty();
		}

		size_t size()const
		{
			return _t.Size();
		}

		bool IsValid()const
		{
			return _t.IsBalanceTree() && _t.IsHeightBalance() && _t.IsRBTree();
		}
	private:
		RBT_KV _t;
	};

}