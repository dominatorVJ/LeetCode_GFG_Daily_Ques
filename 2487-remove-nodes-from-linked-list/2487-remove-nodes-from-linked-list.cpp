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
    ListNode* removeNodes(ListNode* head) {
        vector<int> data;
        ListNode* curr = head;
        while(curr){
            data.push_back(curr->val);
            curr = curr->next;
        }
        curr = head;
        vector<int> rg(data.size());
        rg[rg.size()-1] = data[data.size()-1];
        for(int i=rg.size()-2;i>=0;i--){
            rg[i] = max(data[i],rg[i+1]);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* itr = dummy;
        int i = 0;
        while(curr){
            if(curr->val == rg[i]){
                itr->next = curr;
                itr = curr;
                curr = curr->next;
                i++;
            }else{
                curr = curr->next;
                i++;
            }
        }
        return dummy->next;
    }
};