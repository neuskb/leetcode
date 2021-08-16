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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 哨兵节点
        ListNode *preHead = new ListNode(-1);
        
        ListNode *pre = preHead;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }

            pre = pre->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完
        pre->next = (l1 == nullptr) ? l2 : l1;

        return preHead->next;
    }
};