/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less=new ListNode();
        ListNode* dummy1=less;
        ListNode* more=new ListNode();
        ListNode* dummy2=more;
        while(head){
            if(head->val<x){
                dummy1->next=head;
                dummy1=dummy1->next;
            }
            else{
                dummy2->next=head;
                dummy2=dummy2->next;
            }
            head=head->next;
        }
        dummy1->next=more->next;
        dummy2->next=NULL;
        return less->next;
    }
};