
## 解题思路:
* 先出一个指针，运行到第n个节点
* 然后两个指针同时后移
* 后一个指针到达链表尾时，则前一个节点到了该被删除的节点前，进行节点删除

代码如下：
```
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (nullptr == head) {
            return nullptr;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        // 快指针先走n步
        while ( n > 0) {
            fast = fast->next;
            n--;
        }

        // 如果n就是链表长度
        if (nullptr == fast) {
            return head->next;
        }

        // 快慢同时走
        while (nullptr != fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // 做删除动作
        slow->next = slow->next->next;
        return head;
    }
};
```
