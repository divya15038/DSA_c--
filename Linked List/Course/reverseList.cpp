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
    int len(ListNode* head){
        if(head == NULL){
            return 0;
        }
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    
    vector<ListNode*> reverseList(ListNode* head, ListNode* tail){
        vector<ListNode*> res;
        res.push_back(head);
        tail->next = NULL;
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* temp = current->next;
        while(current != NULL){
            current->next = prev;
            prev = current;
            current = temp;
            temp = temp!=NULL?temp->next:NULL;
        }
        head = prev;
        res.push_back(head);
        return res;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || len(head) == 1 || left == right){
            return head;
        }
        vector<ListNode*> res;
        int l = left;
        int r = right;
        ListNode* start = head;
        ListNode* prev;
        while(l>1 and start!=NULL){
            prev = start;
            start = start->next;
            l--;
        }
        l = left;
        ListNode* end = start;
        while(r>l and end!=NULL){
            end = end->next;
            r--;
        }
        if(left == 1 and right == len(head)){
            res = reverseList(start, end);
            return res[1];
        }
        if(right == len(head)){
            res = reverseList(start, end);
            prev->next = res[1];
            //cout << start->val;
            res[0]->next = NULL;
            return head;
        }
        ListNode* temp = end->next;
        if(left == 1){
            res = reverseList(head, end);
            res[0]->next = temp;
            return res[1];
        }
        res = reverseList(start, end);
        prev->next = res[1];
        res[0]->next = temp;
        return head;
    }
};