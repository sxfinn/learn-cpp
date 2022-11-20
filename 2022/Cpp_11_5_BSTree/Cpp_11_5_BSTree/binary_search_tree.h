#pragma once
#include<iostream>
using namespace std;

namespace sx
{
	template<class K, class V>
	struct BSTree_Node
	{
		BSTree_Node(const K key = K(), const V val = V())
			:
			_key(key),
			_val(val),
			_left(nullptr),
			_right(nullptr)
		{}
		K _key;
		V _val;
		BSTree_Node* _left;
		BSTree_Node* _right;
	};

	template<class K, class V>
	class BSTree
	{
		typedef BSTree_Node<K, V> Node;
		
	public:
		BSTree() = default;

		BSTree(const BSTree& tree)
		{
			_root = _copy_tree(tree._root);
		}

		BSTree& operator=(BSTree tree)
		{
			swap(tree);
			return *this;
		}

		~BSTree()
		{			
			_destroy_tree(_root);
			_root = nullptr;
		}

		void swap(BSTree& tree)
		{
			std::swap(_root, tree._root);
		}

		void in_order()
		{
			_in_order(_root);
			cout << endl;
		}

		bool insert(const K& key, const V& val)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, val);
				return true;
			}
			Node* prev = nullptr;
			Node* cur = _root;
			bool isLeft = true;
			while (cur)
			{
				if (cur->_key > key)
				{
					prev = cur;
					cur = cur->_left;
					isLeft = true;
				}
				else if (cur->_key < key)
				{
					prev = cur;
					cur = cur->_right;
					isLeft = false;
				}
				else
					return false;
			}
			cur = new Node(key, val);
			if (isLeft)
				prev->_left = cur;
			else
				prev->_right = cur;
			return true;
		}

		Node* find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else
					return cur;
			}
			return nullptr;
		}

		bool erase(const K& key)
		{
			Node* prev = nullptr;
			Node* cur = _root;
			if (cur == nullptr)
				return false;

			while (cur)
			{
				if (key < cur->_key)
				{
					prev = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)
				{
					prev = cur;
					cur = cur->_right;
				}
				else
				{
					if (cur->_left && cur->_right)
					{
						//被删除的节点左右子树都不为空
						Node* minParent = cur;
						Node* minRight = cur->_right;
						while (minRight->_left)
						{
							minParent = minRight;
							minRight = minRight->_left;
						}
						std::swap(cur->_key, minRight->_key);
						std::swap(cur->_val, minRight->_val);
						if (minParent->_left == minRight)
						{
							minParent->_left = minRight->_right;
						}
						else
						{
							minParent->_right = minRight->_left;
						}
						delete minRight;
						return true;
					}
					else
					{
						if (cur->_left)
						{
							if (prev == nullptr)//删除的节点是根节点单独处理
							{
								_root = cur->_left;
							}
							else
							{
								if (prev->_left == cur)
									prev->_left = cur->_left;
								else
									prev->_right = cur->_left;
							}
							delete cur;
						}
						else
						{
							if (prev == nullptr)
							{
								_root = cur->_right;
							}
							else
							{
								if (prev->_left == cur)
									prev->_left = cur->_right;
								else
									prev->_right = cur->_right;
							}
							delete cur;
						}
					}
					return true;
				}
			}
			return false;
		}

		void erase_r(const K& key)
		{
			_erase_r(_root, key);
		}

		void insert_r(const K& key, const V& val)
		{
			_insert_r(_root, key, val);
		}

		Node* find_r(const K& key)
		{
			return _find_r(_root, key);
		}

	private:
		bool _erase_r(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;

			if (root->_key == key)
			{
				if (root->_left && root->_right)
				{
					Node* cur = root;
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						minRight = minRight->_left;
					}
					std::swap(cur->_key, minRight->_key);
					std::swap(cur->_val, minRight->_val);
					return _erase_r(cur->_right, key);
				}
				else
				{
					Node* del = root;
					if (root->_left && root->_right == nullptr)
					{
						root = root->_left;
					}
					else
					{
						root = root->_right;
					}
					delete del;
					return true;
				}
			}
			else if (root->_key > key)
				return _erase_r(root->_left, key);
			else
				return _erase_r(root->_right, key);
		}

		Node* _find_r(Node* root, const K& key)
		{
			if (root == nullptr)
				return nullptr;
			if (root->_key == key)
				return root;
			else if (root->_key < key)
			{
				return _find_r(root->_right, key);
			}
			else
			{
				return _find_r(root->_left, key);
			}
		}

		bool _insert_r(Node*& root, const K& key, const V& val)
		{
			if (root == nullptr)
			{
				root = new Node(key, val);
				return true;
;			}
			if (root->_key < key)
			{
				return _insert_r(root->_right, key, val);
			}
			else if (root->_key > key)
			{
				return _insert_r(root->_left, key, val);
			}
			else
				return false;
		}

		Node* _copy_tree(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* newroot = new Node(root->_key, root->_val);
			newroot->_left = _copy_tree(root->_left);
			newroot->_right = _copy_tree(root->_right);
			return newroot;
		}
		void _in_order(Node* root)
		{
			if (root == nullptr)
				return;
			_in_order(root->_left);
			cout << root->_key << ":" << root->_val << endl;
			_in_order(root->_right);
		}

		void _destroy_tree(Node* root)
		{
			if (root == nullptr)
				return;
			_destroy_tree(root->_left);
			_destroy_tree(root->_right);
			delete root;
		}
		Node* _root = nullptr;
	};
}

