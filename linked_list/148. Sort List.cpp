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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* temp = head, *root = new ListNode(), *t;
        t = root;
        vector<int> res;
        while(temp) {
            res.push_back(temp->val);
            temp = temp->next;
        }
        sort(res.begin(), res.end()); // O(nlogn)
        int n = res.size();
        for(int i = 0; i < n; i++) {
            root->next = new ListNode(res[i]);
            root=root->next;
        }
    }
};