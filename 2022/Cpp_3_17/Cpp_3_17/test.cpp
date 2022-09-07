#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode* next;
};

class PalindromeList
{
public:
    bool chkPalindrome(ListNode* A)
    {
        if (A == NULL)
            return true;
        int cnt = 1;
        struct ListNode* head1 = A;
        struct ListNode* head2 = A;
        struct ListNode* prev = A;
        struct ListNode* cur = A;
        struct ListNode* next = A->next;
        while (head1->next)
        {
            ++cnt;
            head1 = head1->next;
        }
        cnt /= 2;
        while (head2->next)
        {
            head2 = head2->next;
            --cnt;
            if (!cnt)
                break;
        }
        next = head2->next;
        head2->next = NULL;
        prev = head2;
        while (next)
        {
            cur = next;
            next = cur->next;
            cur->next = prev;
            prev = cur;
        }
        while (cur->next && A->next)
        {
            if (cur->val != A->val)
                return false;
            cur = cur->next;
            A = A->next;
        }
        return true;
    }
};

class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
    {
        struct ListNode* A = headA, * B = headB;
        while (A != B)
        {
            A = A == nullptr ? headB : A->next;
            B = B == nullptr ? headA : B->next;
        }
        return A;
    }
};

class Partition 
{
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        struct ListNode* newhead = NULL;
        struct ListNode* pre = pHead;
        struct ListNode* cur = NULL;
        struct ListNode* prev = pre;
        while (pre->next)
        {
            pre = pre->next;
            if (pre->val < x)
            {
                if (newhead == NULL)
                {
                    newhead = pre;
                    cur = newhead;
                }
                else
                {
                    cur->next = pre;
                    cur = pre;
                }
                prev->next = pre->next;
                pre = prev;
            }
            else
                prev = pre;
        }
        if (newhead == NULL)
            return pHead;
        if (pHead->val < x)
        {
            cur->next = pHead->next;
            pHead->next = newhead;
            return pHead;
        }
        else
            cur->next = pHead;
        return newhead;
    }
};
//class Partition 
//{
//public:
//    
//    ListNode* partition(ListNode* pHead, int x) 
//    {
//        ListNode* cur = pHead;
//        ListNode* pre = pHead;
//        while (pre)
//        {
//            if (pre->val < x)
//            {
//                swap(cur->val, pre->val);
//                cur = cur->next;
//            }
//            pre = pre->next;
//        }
//    }
//};

int main()
{

	return 0;
}