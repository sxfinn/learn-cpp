#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

enum Color
{
	RED,
	BLACK
};

template<class K, class V>

struct RBTreeNode
{
	RBTreeNode(const pair<K, V>& kv)
		:
		_kv(kv),
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_colr(RED)
	{}

	pair<K, V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Color _colr;
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree() = default;

	RBTree(const RBTree<K, V>& tree)
	{
		_root = _CopyTree(tree._root);
	}

	RBTree<K, V>& operator=(RBTree<K, V> tree)
	{
		swap(tree);
		return *this;
	}

	~RBTree()
	{
		_DestroyTree(_root);
		_root = nullptr;
	}

	void swap(RBTree<K, V>& tree)
	{
		std::swap(_root, tree._root);
	}

	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_colr = BLACK;
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		Node* newnode = new Node(kv);
		cur = newnode;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = newnode;
		}
		else
		{
			parent->_left = newnode;
		}
		newnode->_parent = parent;

		while (parent && parent->_colr == RED)
		{
			Node* grandpa = parent->_parent;
			Node* uncle = nullptr;
			assert(grandpa);//理论上不可能走到这里
			if (grandpa->_left == parent)
			{
				uncle = grandpa->_right;
				if (uncle && uncle->_colr == RED)
				{
					//情况一
					parent->_colr = uncle->_colr = BLACK;
					grandpa->_colr = RED;
					cur = grandpa;
					parent = grandpa->_parent;	
				}
				else if(uncle == nullptr || uncle->_colr == BLACK)
				{
					if (parent->_left == cur)
					{
						//情况二
						RotateR(grandpa);
						parent->_colr = BLACK;
						grandpa->_colr = RED;
					}
					else //parent->_right == cur
					{
						//情况三
						Node* pRight = parent->_right;
						RotateLR(grandpa);
						pRight->_colr = BLACK;
						grandpa->_colr = RED;
					}
					break;
				}
				else
				{
					assert(false);
				}
			}
			else
			{
				uncle = grandpa->_left;
				if (uncle && uncle->_colr == RED)
				{
					//情况一
					parent->_colr = uncle->_colr = BLACK;
					grandpa->_colr = RED;
					parent = grandpa->_parent;
					cur = grandpa;
				}
				else if (uncle == nullptr || uncle->_colr == BLACK)
				{
					if (parent->_right == cur)
					{
						//情况二
						RotateL(grandpa);
						parent->_colr = BLACK;
						grandpa->_colr = RED;
					}
					else //parent->_left == cur
					{
						//情况三
						Node* pLeft = parent->_left;
						RotateRL(grandpa);
						pLeft->_colr = BLACK;
						grandpa->_colr = RED;
					}
					break;
				}
				else
				{
					assert(false);
				}
			}
		}
		_root->_colr = BLACK;
		return true;
	}

	bool IsHeightBalance()
	{
		int MaxH = _MaxHeight(_root);
		int MinH = _MinHeight(_root);
		if (MaxH > MinH * 2)
		{
			cout << "error:路径长度不满足要求" << endl;
			return false;
		}

		cout << "最长路径:" << MaxH << endl;
		cout << "最短路径:" << MinH << endl;
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	bool IsRBTree()
	{
		if (_root == nullptr)
			return true;
		if (_root->_colr != BLACK)
		{
			cout << "error:根节点颜色不满足要求" << endl;
			return false;
		}
		int BlackCount = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_colr == BLACK)
			{
				++BlackCount;				
			}
			cur = cur->_left;
		}
		cout << "各路径中黑色节点个数" << BlackCount << endl;
		int k = 0;
		return _IsRBTree(_root, k , BlackCount);
	}

	bool IsBalanceTree()
	{
		// 检查红黑树几条规则
		Node* pRoot = _root;

		// 空树也是红黑树
		if (nullptr == pRoot)
			return true;

		// 检测根节点是否满足情况
		if (BLACK != pRoot->_colr)
		{
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}

		// 获取任意一条路径中黑色节点的个数 -- 比较基准值
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_colr)
				blackCount++;

			pCur = pCur->_left;
		}

		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}
private:
	void _DestroyTree(Node* root)
	{
		if (root == nullptr)
			return;

		_DestroyTree(root->_left);
		_DestroyTree(root->_right);
		delete(root);
	}

	Node* _CopyTree(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		Node* newroot = new Node(root->_kv);
		newroot->_colr = root->_colr;
		Node* pl = _CopyTree(root->_left);
		newroot->_left = pl;
		if(pl)
			pl->_parent = newroot;
		Node* pr = _CopyTree(root->_right);
		newroot->_right = pr;
		if(pr)
			pr->_parent = newroot;

		return newroot;
	}

	bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount)
	{
		//走到null之后，判断k和black是否相等
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
			return true;
		}

		// 统计黑色节点的个数
		if (BLACK == pRoot->_colr)
			k++;

		// 检测当前节点与其双亲是否都为红色
		if (RED == pRoot->_colr && pRoot->_parent && pRoot->_parent->_colr == RED)
		{
			cout << "违反性质三：存在连在一起的红色节点" << endl;
			return false;
		}

		return _IsValidRBTree(pRoot->_left, k, blackCount) &&
			_IsValidRBTree(pRoot->_right, k, blackCount);
	}

	bool _IsRBTree(Node* root, int k, int BlackCount)
	{
		if (root == nullptr)
		{
			if (k == BlackCount)
				return true;
			else
			{
				cout << "error:不满足每条路径中黑色节点个数相同的条件" << endl;
				return false;
			}
		}
		if (root->_colr == BLACK)
			++k;

		Node* parent = root->_parent;
		if (root->_colr == RED && parent && parent->_colr == RED)
		{
			cout << "error:有连续红色节点" << endl;
			return false;
		}
		return _IsRBTree(root->_left, k, BlackCount) && _IsRBTree(root->_right, k, BlackCount);
	}

	int _MinHeight(Node* root)
	{
		if (root == nullptr)
			return 0;

		int hLeft = _MinHeight(root->_left);
		int hRight = _MinHeight(root->_right);
		return (hLeft > hRight ? hRight : hLeft) + 1;
	}

	int _MaxHeight(Node* root)
	{
		if (root == nullptr)
			return 0;

		int hLeft = _MaxHeight(root->_left);
		int hRight = _MaxHeight(root->_right);
		return (hLeft > hRight ? hLeft : hRight) + 1;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	void RotateL(Node* parent)
	{
		Node* pRight = parent->_right;
		Node* pRLeft = pRight->_left;
		Node* ppNode = parent->_parent;

		parent->_right = pRLeft;
		if (pRLeft)
			pRLeft->_parent = parent;

		pRight->_left = parent;
		parent->_parent = pRight;

		if (ppNode)
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = pRight;
			}
			else
			{
				ppNode->_right = pRight;
			}
		}
		pRight->_parent = ppNode;
		if (parent == _root)
		{
			_root = pRight;
		}
	}

	void RotateR(Node* parent)
	{
		Node* pLeft = parent->_left;
		Node* pLRight = pLeft->_right;
		Node* ppNode = parent->_parent;

		parent->_left = pLRight;
		if (pLRight)
			pLRight->_parent = parent;

		pLeft->_right = parent;
		parent->_parent = pLeft;
		if (ppNode)
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = pLeft;
			}
			else
			{
				ppNode->_right = pLeft;
			}
		}
		pLeft->_parent = ppNode;
		if (_root == parent)
		{
			_root = pLeft;
		}
	}

	void RotateLR(Node* parent)
	{
		Node* pLeft = parent->_left;
		RotateL(pLeft);
		RotateR(parent);
	}

	void RotateRL(Node* parent)
	{
		Node* pRight = parent->_right;
		RotateR(pRight);
		RotateL(parent);
	}

	Node* _root = nullptr;
};