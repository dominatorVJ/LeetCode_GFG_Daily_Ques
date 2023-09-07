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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr){
            return head;
        }
        ListNode *prev=nullptr;
        ListNode *curr=head;
        for(int i=1;curr!=nullptr && i<left;i++){
            prev=curr;
            curr=curr->next;
        }
        ListNode *last=prev;
        ListNode *newEnd=curr;
        for(int i=left;curr!=nullptr && i<=right;i++){
            ListNode* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        if(last!=nullptr){
            last->next=prev;
        }else{
            head=prev;
        }
        newEnd->next=curr;
        return head;
    }
};