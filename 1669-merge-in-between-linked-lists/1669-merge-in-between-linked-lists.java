/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode curr = list1,it=list1;
        for(int i=0;i<a-1;i++){
            curr = curr.next;
        }
        ListNode mid = curr;
       for(int i=0;i<b;i++){
            it = it.next;
        }
        ListNode tail = it.next;
        it.next = null;
        
        ListNode itr = list2;
        while(itr.next!=null){
            itr = itr.next;
        }
        mid.next = list2;
        itr.next = tail;
        return list1;
    }
}