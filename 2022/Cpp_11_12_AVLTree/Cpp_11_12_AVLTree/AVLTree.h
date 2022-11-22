#pragma once
#include<utility>//pairͷ�ļ�
#include<iostream>
#include<assert.h>
using namespace std;
namespace sx
{
	template<class K, class V>
	struct AVLTreeNode
	{
		AVLTreeNode(const pair<K, V> kv)
			:
			_kv(kv),
			_left(nullptr),
			_right(nullptr),
			_parent(nullptr),
			_bf(0)
		{}
		pair<K, V> _kv;
		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;
		int _bf;//balance factor
	};

	template<class K, class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> Node;
	public:
		AVLTree() = default;

		AVLTree(const AVLTree<K, V>& tree)
		{
			_root = _CopyTree(tree._root);
		}

		~AVLTree()
		{
			_DestroyTree(_root);
			_root = nullptr;
		}

		AVLTree<K, V>& operator=(AVLTree<K, V> tree)
		{
			swap(tree);
			return *this;
		}

		void swap(AVLTree<K, V>& tree)
		{
			std::swap(_root, tree._root);
		}

		bool Insert(const pair<K, V> kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_bf = 0;
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
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
			while (parent)
			{
				if (parent->_left == cur)
				{
					parent->_bf--;
				}
				else
				{
					parent->_bf++;
				}
				if (parent->_bf == 2 || parent->_bf == -2)
				{
					//�Ѿ�Υ��AVLTree������Ҫͨ����ת���е����߶�
					if (parent->_bf == 2)
					{
						if (cur->_bf == 1)
						{
							//����
							RotateL(parent);
						}
						else if(cur->_bf == -1)
						{
							//����˫��
							RotateRL(parent);
						}
						else
						{
							cout << "error" << endl;
							assert(false);
						}
					}
					else
					{
						if (cur->_bf == -1)
						{
							//����
							RotateR(parent);
						}
						else if (cur->_bf == 1)
						{
							//����˫��
							RotateLR(parent);
						}
						else
						{
							cout << "error" << endl;
							assert(false);
						}
					}
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					//����ڵ�ı��������߶ȣ����ϸ���balance factor
					cur = parent;
					parent = parent->_parent;
				}
				else if(parent->_bf == 0)
				{
					//����ڵ�Ը��ڵ�balance factor��Ӱ��
					break;
				}
				else
				{
					cout << "error" << endl;
					assert(false);
				}
			}
			return true;
		}

		bool IsBLTree()
		{
			return _IsBLTree(_root);
		}

		bool IsBalanceTree()
		{
			return _IsBalanceTree(_root);
		}

		size_t Height()
		{
			return _Height(_root);
		}
		
		void InOrder()
		{
			_InOrder(_root);
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
			newroot->_bf = root->_bf;
			Node* pl = _CopyTree(root->_left);
			newroot->_left = pl;
			if (pl)
				pl->_parent = newroot;
			Node* pr = _CopyTree(root->_right);
			newroot->_right = pr;
			if (pr)
				pr->_parent = newroot;
			return newroot;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_kv.first << " ";
			_InOrder(root->_right);
		}

		bool _IsBLTree(Node* root)
		{
			if (root == nullptr)
				return true;
			size_t hRight = _Height(root->_right);
			size_t hLeft = _Height(root->_left);
			return true;
			
			if ((abs((int)(hRight - hLeft))) > 1)
			{
				cout << "��BLTree" << endl;
				return false;
			}

			return _IsBLTree(root->_left) && _IsBLTree(root->_right);
		}

		int _Height(Node* root)
		{
			if (root == nullptr)
				return 0;

			int lh = _Height(root->_left);
			int rh = _Height(root->_right);

			return lh > rh ? lh + 1 : rh + 1;
		}

		bool _IsBalanceTree(Node* root)
		{
			// ����Ҳ��AVL��
			if (nullptr == root)
				return true;
			// ����pRoot�ڵ��ƽ�����ӣ���pRoot���������ĸ߶Ȳ�
			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);
			int diff = rightHeight - leftHeight;

			// ����������ƽ��������pRoot��ƽ�����Ӳ���ȣ�����
			// pRootƽ�����ӵľ���ֵ����1����һ������AVL��
			if (abs(diff) >= 2)
			{
				cout << root->_kv.first << "�ڵ����������߶��쳣��������Ч��Χ��" << endl;
				return false;
			}

			if (diff != root->_bf)
			{
				cout << root->_kv.first << "�ڵ�ƽ������ʵ�ʵ����������߶Ȳһ��" << endl;
				return false;
			}
			// pRoot��������������AVL���������һ����AVL��
			return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
		}

		//size_t _Height(Node* root)
		//{
		//	if (root == nullptr)
		//		return 0;
		//	size_t right = _Height(root->_right);
		//	size_t left = _Height(root->_left);
		//	return 1 + (left > right ? left : right);
		//}

		void RotateL(Node* parent)
		{
			Node* pRight = parent->_right;
			Node* pRLeft = pRight->_left;
			Node* ppNode = parent->_parent;

			parent->_right = pRLeft;
			if(pRLeft)
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
			pRight->_bf = 0;
			parent->_bf = 0;
		}

		void RotateR(Node* parent)
		{
			Node* pLeft = parent->_left;
			Node* pLRight = pLeft->_right;
			Node* ppNode = parent->_parent;

			parent->_left = pLRight;
			if(pLRight)
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
			parent->_bf = 0;
			pLeft->_bf = 0;
		}

		void RotateLR(Node* parent)
		{
			Node* pLeft = parent->_left;
			Node* pLRight = pLeft->_right;

			bool inRight = false;
			bool inLeft = false;
			if (pLRight->_bf == 1)
			{
				inRight = true;
			}
			else if (pLRight->_bf == -1)
			{
				inLeft = true;
			}
			else if(pLRight->_bf == 0)
			{
				inLeft = inRight = false;
			}
			else
			{
				//֮ǰ�Ѿ����ִ���
				assert(false);
			}
			RotateL(pLeft);
			RotateR(parent);
			pLRight->_bf = 0;
			if (inRight)
			{
				parent->_bf = 0;
				pLeft->_bf = -1;
			}
			else if(inLeft)
			{
				pLeft->_bf = 0;
				parent->_bf = 1;
			}
			else
			{
				pLeft->_bf = 0;
				parent->_bf = 0;
			}
		}

		void RotateRL(Node* parent)
		{
			Node* pRight = parent->_right;
			Node* pRLeft = pRight->_left;

			bool inRight = false;
			bool inLeft = false;
			if (pRLeft->_bf == 1)
			{
				inRight = true;
			}
			else if (pRLeft->_bf == -1)
			{
				inLeft = true;
			}
			else if(pRLeft->_bf == 0)
			{ 
				inLeft = inRight = false;
			}
			else
			{
				//֮ǰ�Ѿ����ִ���
				assert(false);
			}
			RotateR(pRight);
			RotateL(parent);
			pRLeft->_bf = 0;
			if (inRight)
			{
				pRight->_bf = 0;
				parent->_bf = -1;
			}
			else if(inLeft)
			{
				pRight->_bf = 1;
				parent->_bf = 0;
			}
			else
			{
				pRight->_bf = 0;
				parent->_bf = 0;
			}
		}
		Node* _root = nullptr;
	};
}