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
    ListNode*  merge(ListNode* l1, ListNode* l2) {
        ListNode *t1 = l1, *t2 = l2, *root = new ListNode(), *head = root;
        int n1 = 0, n2 = 0;
        while(t1) {
            t1 = t1->next;
            n1++;
        }
        while(t2) {
            t2 = t2->next;
            n2++;
        }
        
        int i = 0, j = 0;
        while(i < n1 && j < n2) {
            if(l1->val <= l2->val) {
                root->next = l1;
                root = root->next;
                l1 = l1->next;
                i++;
            } else {
                root->next = l2;
                root = root->next;
                l2 = l2->next;
                j++;
            }
        }
        // if the lengths are left
        if(i < n1) {
            root->next = l1;
        }
        if(j < n2) {
            root->next = l2;
        }
        
        return head->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0) return NULL;
        
        ListNode* root = lists[0];
        
        for(int i = 1; i < k; i++) {
            root = merge(root, lists[i]);
        }
        return root;
    }
};