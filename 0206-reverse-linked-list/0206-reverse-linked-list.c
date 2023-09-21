/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL) return NULL;
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    
    while(curr != NULL){
       struct ListNode* fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    
    return prev;
}