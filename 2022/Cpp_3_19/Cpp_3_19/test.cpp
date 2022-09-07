#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	struct ListNode* next;
};


class Partition
{
public:
	ListNode* partition(ListNode* pHead, int x)
	{
		if (pHead == nullptr)
			return nullptr;
		ListNode* cur = pHead;
		ListNode* prev = pHead;
		ListNode* lesshead = nullptr;
		ListNode* lesscur = nullptr;
		while (cur)
		{
			if (cur->val < x)
			{
				if (lesshead == nullptr)
				{														
					lesshead = cur;
					lesscur = cur;									
				}
				else
				{
					lesscur->next = cur;
					lesscur = cur;
				}
				if (cur == pHead)		
					pHead = pHead->next;
				else
				{
					prev->next = cur->next;
					cur = prev;
				}
			}
			prev = cur;
			cur = cur->next;	
		}
		if (lesshead == nullptr)
			return pHead;
		else
		{
			lesscur->next = pHead;
			return lesshead;
		}
	}
};
//class Partition
//{
//public:
//	ListNode* partition(ListNode* pHead, int x)
//	{
//		ListNode* lesshead = (ListNode*)malloc(sizeof(ListNode));
//		ListNode* greater = (ListNode*)malloc(sizeof(ListNode));
//		ListNode* cur = pHead;
//		ListNode* lesscur = lesshead;
//		ListNode* greatcur = greater;
//		while (cur)
//		{
//			if (cur->val < x)
//			{
//				lesscur->next = cur;
//				lesscur = cur;
//			}
//			else
//			{
//				greatcur->next = cur;
//				greatcur = cur;
//			}
//			cur = cur->next;
//		}
//		greatcur->next = nullptr;
//		greatcur = greater;
//		lesscur->next = greater->next;
//		delete(greatcur);
//		lesscur = lesshead;
//		lesshead = lesshead->next;
//		delete(lesscur);
//		return lesshead;
//	}
//};

class Solution 
{
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		ListNode* ret = NULL;
		ListNode* cur = NULL;
		if (list1->val > list2->val)
		{
			ret = list2;
			list2 = list2->next;
		}
		else
		{
			ret = list1;
			list1 = list1->next;
		}
		cur = ret;
		while (list1 && list2)
		{
			if (list1->val > list2->val)
			{
				cur->next = list2;
				cur = list2;
				list2 = list2->next;
			}
			else
			{
				cur->next = list1;
				cur = list1;
				list1 = list1->next;
			}
		}
		if (list1)
			cur->next = list1;
		else
			cur->next = list2;
		return ret;
	}
};

//class Solution
//{
//public:
//	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
//	{
//		if (!k)
//			return nullptr;
//		ListNode* fast = pListHead;
//		ListNode* slow = pListHead;
//		while (k-- && fast->next)
//		{
//			fast = fast->next;
//		}
//		if (k)
//			return NULL;
//		while (fast->next)
//		{
//			slow = slow->next;
//			fast = fast->next;
//		}
//		return slow;
//	}
//};

struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	while (cur)
	{
		struct ListNode* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

int main()
{

	return 0;
}