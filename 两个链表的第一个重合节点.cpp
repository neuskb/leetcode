
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 1. 保存hashset中再比较
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> compared;

        ListNode *temp = headA;
        while (nullptr != temp) {
            compared.insert(temp);
            temp = temp->next;
        }

        temp = headB;
        while (nullptr != temp) {
            if (compared.count(temp)) {
                return temp;
            }
            temp = temp->next;
        }

        return nullptr;
    }
};

// 2. a+b = b+a
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (nullptr != p1 || nullptr != p2) {
            if (p1 == p2) {
                return p1;
            }

            p1 = (p1 == nullptr) ? headB : p1->next;
            p2 = (p2 == nullptr) ? headA : p2->next;
        }

        return nullptr;
    }
};
