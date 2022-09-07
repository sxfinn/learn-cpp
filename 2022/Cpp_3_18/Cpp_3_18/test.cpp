#include<iostream>

using namespace std;

struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

struct ListNode* middleNode(struct ListNode* head)
{
    int cnt = 1;
    struct ListNode* cur = head;
    while (cur->next)
    {
        cur = cur->next;
        ++cnt;
    }
    cnt /= 2;
    while (head->next)
    {
        head = head->next;
        --cnt;
        if (!cnt)
            break;
    }
    return head;
}

struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* cur = head->next;
    struct ListNode* prev = head;
    head->next = NULL;
    while (cur)
    {
        struct ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return cur;
}

class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* ret = NULL;
        ListNode* cur = head;
        ListNode* prev = head;
        while (cur->next)
        {
            cur = cur->next;
            if (cur->val == val)
            {
                prev->next = cur->next;
                delete(cur);
                cur = prev;
            }
            else
            {
                prev = cur;
            }
        }
        if (head->val == val)
        {
            ret = head->next;
            delete(head);
            return ret;
        }
        else
            return head;
    }
};

//int main()
//{
//    ListNode* node1 = (ListNode*)malloc(sizeof(List))
//    return 0;
//}
//class Solution
//{
//public:
//    ListNode* removeElements(ListNode* head, int val)
//    {
//        struct ListNode* cur = head;
//        struct ListNode* prev = head;
//        if (head == NULL)
//            return NULL;
//        struct ListNode* ret = NULL;
//
//        while (cur->next)
//        {
//            cur = cur->next;
//            if (cur->val == val)
//            {
//                prev->next = cur->next;
//                free(cur);
//                cur = prev;
//            }
//            else
//                prev = cur;
//        }
//        if (head->val == val)
//        {
//            ret = head->next;
//            free(head);
//            return ret;
//        }
//        return head;
//    }
//};
//
//

//�̳У�����δ��װ��һ����������
//��Ϊ�����޷�װЧ��������ֱ�ӿ�������ĳ�Ա����������ͻʱ����Ҫָ���̳еĸ������������ԭ����Ա
// ���Ҽ̳й�ϵ��ѭȨ����С���ܷŴ��ԭ��̳С�
//����Ĭ�Ϲ��캯����䱻����һ����������
//class S
//{
//public:
//	S()
//		:
//		a(1),
//		b(2)
//	{}
//protected:
//	int b;
//
//	int a;
//};
//class B:public S
//{
//public:
//	B()
//		:
//		b(7),
//		c(10)
//	{
//
//	}
//	void print()
//	{
//		cout << a << b << c;
//		
//	}
//	int c;
//
//};
//int main()
//{
//	B k;
//	k.c;
//	k.print();
//	return 0;
//}

//int main()
//{
//	printf("%c", "'");
//	print("%c", """);
//	return 0;
//}
//	

