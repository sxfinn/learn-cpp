#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//根据二叉树创建字符串
class Solution1
{
    void _tree2str(string& ret, TreeNode* root)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            ret += to_string(root->val);
        }
        else if (root->right == nullptr)
        {
            ret += to_string(root->val);
            ret += '(';
            _tree2str(ret, root->left);
            ret += ')';
        }
        else
        {
            ret += to_string(root->val);
            ret += '(';
            _tree2str(ret, root->left);
            ret += ')';
            ret += '(';
            _tree2str(ret, root->right);
            ret += ')';
        }
    }
public:
    string tree2str(TreeNode* root)
    {
        string ret;
        _tree2str(ret, root);
        return ret;
    }
};

class Solution2
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        vector<int> row;
        queue<TreeNode*> queCur;
        queue<TreeNode*> queIdle;
        queCur.push(root);

        while (!queCur.empty())
        {
            while (!queCur.empty())
            {
                TreeNode* top = queCur.front();
                queCur.pop();
                if (top)
                {
                    row.push_back(top->val);
                    queIdle.push(top->left);
                    queIdle.push(top->right);
                }
            }
            if (!row.empty())
            {
                ret.push_back(row);
                row.clear();
            }
            queCur.swap(queIdle);
        }
        return ret;
    }
};

class Solution3
{
public:

    bool in_the_subtree(TreeNode* root, TreeNode* node)
    {
        if (root == nullptr)
            return false;
        if (root == node)
        {
            return true;
        }
        return in_the_subtree(root->left, node) || in_the_subtree(root->right, node);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root->val == p->val || root->val == q->val)
            return root;
        bool pinLeft = in_the_subtree(root->left, p);
        bool pinRight = !pinLeft;

        bool qinLeft = in_the_subtree(root->left, q);
        bool qinRight = !qinLeft;

        if (pinLeft && qinRight || pinRight && qinLeft)
        {
            return root;
        }
        else if (pinRight && qinRight)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (pinLeft && qinLeft)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return nullptr;
        }

    }
};

//二叉搜索树与双向链表(中序)
class Solution4
{
public:
    void _Convert(TreeNode* root, TreeNode*& prev)
    {
        if (root->left)
            _Convert(root->left, prev);
        root->left = prev;
        if (prev)
            prev->right = root;
        prev = root;
        if (root->right)
            _Convert(root->right, prev);
    }

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr)
            return nullptr;
        TreeNode* prev = nullptr;
        _Convert(pRootOfTree, prev);
        TreeNode* head = pRootOfTree;
        while (head->left)
            head = head->left;
        return head;
    }
};

class Solution5
{
public:
    bool GetPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& st)
    {
        if (root == nullptr)
            return false;

        if (root == target)
        {
            st.push_back(root);
            return true;
        }
        else
        {
            bool PathExit = false;
            PathExit = GetPath(root->left, target, st);
            if (PathExit)
            {
                st.push_back(root);
                return true;
            }
            PathExit = GetPath(root->right, target, st);
            if (PathExit)
            {
                st.push_back(root);
                return true;
            }
            return false;
        }

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> pPath;
        vector<TreeNode*> qPath;
        GetPath(root, p, pPath);
        GetPath(root, q, qPath);

        reverse(pPath.begin(), pPath.end());
        reverse(qPath.begin(), qPath.end());

        while (qPath.size() > pPath.size())
        {
            qPath.pop_back();
        }
        while (qPath.size() < pPath.size())
        {
            pPath.pop_back();
        }

        while (qPath.back() != pPath.back())
        {
            qPath.pop_back();
            pPath.pop_back();
        }
        return pPath.back();
    }
};
//根据前序中序构建树
class Solution6
{
public:

    TreeNode* _buildtree(vector<int>& preorder, vector<int>& inorder, int inLeft, int inRight, int& pos)
    {
        if (inLeft > inRight)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[pos]);

        int parent = 0;
        while (parent < inorder.size())
        {
            if (inorder[parent] == preorder[pos])
            {
                break;
            }
            ++parent;
        }
        ++pos;
        root->left = _buildtree(preorder, inorder, inLeft, parent - 1, pos);
        root->right = _buildtree(preorder, inorder, parent + 1, inRight, pos);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int pos = 0;
        TreeNode* ret = _buildtree(preorder, inorder, 0, inorder.size() - 1, pos);
        return ret;
    }
};

//根据后序中序构建树
class Solution8
{
    map<int, int> index;
public:

    TreeNode* _buildtree(vector<int>& inorder, vector<int>& postorder, int in_left, int in_right, int po_left, int po_right)
    {
        if (in_left > in_right)
        {
            return nullptr;
        }
        int rootpos = index[postorder[po_right]];
        TreeNode* newtree = new TreeNode(postorder[po_right]);

        /*int size = rootpos - in_left;*/

        newtree->left = _buildtree(inorder, postorder, in_left, rootpos - 1, po_left, po_left - 1 - in_left + rootpos);
        newtree->right = _buildtree(inorder, postorder, rootpos + 1, in_right, po_left - in_left + rootpos, po_right - 1);

        return newtree;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            index[inorder[i]] = i;
        }

        TreeNode* ret = _buildtree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
        return ret;
    }
};

//非递归前序遍历
class Solution9
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        stack<TreeNode*> st;
        //TreeNode* r = root;
        //TreeNode* top = root;
        TreeNode* cur = root;
        while (true)
        {
            //左树
            while (cur)
            {
                ret.push_back(cur->val);
                //cout << cur->val << " ";
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = nullptr;
            if (!st.empty())
            {
                top = st.top();
                st.pop();
            }
            else
                break;
            cur = top->right;
        }
        return ret;
    }
};
//非递归后序遍历
class Solution10 {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (true)
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            
            TreeNode* top = nullptr;
            if (!st.empty())
            {
                top = st.top();
                st.pop();
            }
            else
                break;
            ret.push_back(top->val);
            cur = top->right;
        }
        return ret;
    }
};
//非递归后序遍历，使用vector或者stack标记右树是否已经遍历
class Solution11 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<TreeNode*> retNode;
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur)
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            TreeNode* top = nullptr;                        
            top = st.top();            
            if (retNode.empty() || retNode.back() != top)
            {
                retNode.push_back(top);
                cur = top->right;
            }
            else
            {
                ret.push_back(top->val);
                retNode.pop_back();
                st.pop();
            }
        }
        /*for (auto& e : retNode)
        {
            ret.push_back(e->val);
        }*/
        return ret;
    }
};
//非递归后序遍历，preb指针标记右树是否已经遍历
class Solution12
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        //vector<TreeNode*> retNode;
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (!st.empty() || cur)
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            TreeNode* top = nullptr;
            top = st.top();
            
            if (top->right == nullptr || prev == top->right)
            {
                ret.push_back(top->val);
                st.pop();
                prev = top;
            }
            else
            {
                cur = top->right;
                
            }
        }        
        return ret;
    }
};
//非递归后序遍历，map映射标记右树是否已经遍历
class Solution13
{
    map<TreeNode*, int> index;
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur)
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            TreeNode* top = nullptr;
            top = st.top();
            index[top]++;
            if (index[top] == 1)
            {
                cur = top->right;
            }
            else
            {
                ret.push_back(top->val);
                st.pop();
            }
        }
        return ret;
    }
};
void test_oj()
{
    //int arr1[] = { 9,3,15,20,7 };
    //int arr2[] = { 9,15,7, 20, 3 };
    //vector<int> v1(arr1, arr1 + 5);
    //vector<int> v2(arr2, arr2 + 5);
    //Solution8().buildTree(v1, v2);


    TreeNode* root = new TreeNode(1);
    TreeNode* r1 = new TreeNode(2);
    TreeNode* r2 = new TreeNode(3);
    TreeNode* r3 = new TreeNode(4); 
    TreeNode* r4 = new TreeNode(5);
    TreeNode* r5 = new TreeNode(6);
    TreeNode* r6 = new TreeNode(7);
    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r2->right = r6;

    vector<int> ret = Solution13().postorderTraversal(root);

    for (auto& e : ret)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
	test_oj();
	return 0;
}

//根据前序中序构建树
class Solution7 {
private:
    map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, 
        int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];

        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // 得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder,
            preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder,
            preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

