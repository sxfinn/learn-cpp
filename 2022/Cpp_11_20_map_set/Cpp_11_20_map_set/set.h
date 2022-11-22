#pragma once
#include"RBtree.h"

namespace sx
{
	template<class K>
	class set
	{
		struct KeyOfSet
		{
			const K& operator()(const K& data)//·µ»ØKEYÖµ
			{
				return data;
			}
		};
		typedef RBTree<K, K, KeyOfSet> RBT_K;
		
	public:
		typedef typename RBTree<K, K, KeyOfSet>::_const_iterator iterator;
		typedef typename RBTree<K, K, KeyOfSet>::_const_iterator const_iterator;
		iterator begin()const
		{
			return _t.Begin();
		}

		iterator end()const
		{
			return _t.End();
		}

		pair<iterator, bool> insert(const K& key)
		{
			pair<typename RBTree<K, K, KeyOfSet>::_iterator, bool> ret = _t.Insert(key);
			return make_pair(iterator(ret.first._node), ret.second);
		}

		iterator find(const K& key)const
		{
			return _t.Find(key);
		}

		void swap(set<K>& x)
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
		RBT_K _t;
	};
}