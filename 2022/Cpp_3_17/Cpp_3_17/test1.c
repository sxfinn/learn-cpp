//#include<stdio.h>
//struct ListNode
//{
//    int val;
//    struct ListNode* next;
//};

//
//
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//    struct ListNode* l = list1;
//    struct ListNode* r = list2;
//    struct ListNode* cur = NULL;
//    struct ListNode* ret = NULL;
//
//    if (l == NULL || r == NULL)
//    {
//        if (l)
//            return l;
//        else
//            return r;
//    }
//    while (l && r)
//    {
//        if (cur == NULL)
//        {
//            if (l->val > r->val)
//            {
//                cur = r;
//                r = r->next;
//            }
//            else
//            {
//                cur = l;
//                l = l->next;
//            }
//            ret = cur;
//        }
//        else
//        {
//            if (l->val > r->val)
//            {
//                cur->next = r;
//                r = r->next;
//            }
//            else
//            {
//                cur->next = l;
//                l = l->next;
//            }
//            cur = cur->next;
//        }
//    }
//    if (r != NULL)
//        cur->next = r;
//    else
//        cur->next = l;
//    return ret;
//}
//
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//    if (pListHead == NULL)
//        return NULL;
//    int cnt = 1;
//    struct ListNode* cur = pListHead;
//    struct ListNode* ret = cur;
//    while (cur->next)
//    {
//        cur = cur->next;
//        ++cnt;
//    }
//    cnt -= k;
//    if (cnt > 0)
//    {
//        while (ret)
//        {
//            ret = ret->next;
//            --cnt;
//            if (!cnt)
//                break;
//        }
//    }
//    else if (cnt == 0)
//        return ret;
//    else
//        return NULL;
//    return ret;
//}
// 
//struct ListNode* middleNode(struct ListNode* head) 
//{
//    int cnt = 1;
//    struct ListNode* cur = head;
//    while (cur->next)
//    {
//        cur = cur->next;
//        ++cnt;
//    }
//    cnt /= 2;
//    while (head->next)
//    {
//        head = head->next;
//        --cnt;
//        if (!cnt)
//            break;
//    }
//    return head;
//}

  //Definition for singly-linked list.

//
//
//struct ListNode* removeElements(struct ListNode* head, int val) 
//{
//    struct ListNode* cur = head;
//    struct ListNode* prev = head;
//    if (head == NULL)
//        return NULL;
//    struct ListNode* ret = head->next;
//    
//    while (cur->next)
//    {
//        cur = cur->next;
//        if (cur->val == val)
//        {
//            prev->next = cur -> next;
//            free(cur);
//            cur = prev->next;
//        }
//        else
//            prev = cur;
//    }
//    if (head->val == val)
//    {
//        free(head);
//    }
//    return ret;
//}
////int main()
////{
////    removeElements(NULL, 7);
////    return 0;
////}
//
//void swap(struct ListNode* l, struct ListNode* r)
//{
//    int tmp = l->val;
//    l->val = r->val;
//    r->val = tmp;
//}
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* left = head;
//    struct ListNode* right = NULL;
//    struct ListNode* pos = head;
//    while (left!= right)
//    {
//        while (pos->next != right)
//        {
//            pos = pos->next;
//        }
//        right = pos;
//        swap(left, right);
//        left = left->next;
//    }
//}