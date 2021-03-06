/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *slow=head,*fast=head,*pre=head;
        while(fast&&fast->next) {
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=NULL;
        return mergeTwoLists(sortList(head),sortList(slow));
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* dummy=new ListNode(-1),*cur=dummy;
            while(l1 && l2) {
                if(l1->val < l2->val) {
                    cur->next = l1;
                    l1 = l1->next;
                }
                else {
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }
            if(l1) cur->next=l1;
            if(l2) cur->next=l2;
            return dummy->next;
        }
};

