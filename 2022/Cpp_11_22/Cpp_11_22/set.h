#pragma once
#include "RBTree.h"

namespace sx
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;

		iterator begin() const
		{
			return _t.Begin();
		}

		iterator end() const
		{
			return _t.End();
		}

		pair<iterator, bool> insert(const K& key)
		{
			//pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> ret = _t.Insert(key);
			auto ret = _t.Insert(key);
			return pair<iterator, bool>(iterator(ret.first._node), ret.second);
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}