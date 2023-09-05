/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;

        unordered_map<Node*, Node*>oldNew;
        Node* curr=head;
        while(curr!=NULL){
            oldNew[curr] = new Node(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr!=NULL){
            oldNew[curr]->next = oldNew[curr->next];
            oldNew[curr]->random = oldNew[curr->random];
            curr=curr->next;
        }
        return oldNew[head];
    }
};