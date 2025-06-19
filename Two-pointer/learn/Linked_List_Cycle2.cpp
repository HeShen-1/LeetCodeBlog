#include "pch.h"
#include <iostream>
#include <unordered_set>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head)
{
    /*
        我们遍历链表中的每个节点，并将它记录下来；
        一旦遇到了此前遍历过的节点，就可以判定链表中存在环。
        借助哈希表可以很方便地实现。
    */

    // unordered_set<ListNode *> seen;
    // while (head != nullptr) {
    //     if (seen.count(head)) {
    //         return head;
    //     }
    //     seen.insert(head);
    //     head = head->next;
    // }
    // return nullptr;

    ListNode *slow = head, *fast = head;
    // 判断是否存在环路
    do
    {
        if (!fast || !fast->next)
        {
            return nullptr;
        }
        fast = fast->next->next;
        slow = slow->next;

    } while (fast != slow);

    fast = head;
    while (fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
}

/*
    找到给定链表环路的开始点，如果没有环路，返回空指针
    Floyd判圈法：给定两个指针——slow、fast，都在链表的开头。
    fast前进两步、slow前进一步。如果fast可以无限走下去，那么说明一定有环路，
    且存在一个时刻fast和slow相遇。fast和slow第一次相遇时，将fast重新移动到链表开头，
    并让fast和slow每次前进一步。当fast和slow第二次相遇时，相遇的节点就是环路的开始点
*/

int main()
{
    // 创建链表 3 -> 2 -> 0 -> -4
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // 形成环，-4 指向 2

    ListNode *cycleNode = detectCycle(head);
    if (cycleNode)
        std::cout << "环的起始节点值为: " << cycleNode->val << std::endl;
    else
        std::cout << "链表无环" << std::endl;

    // 释放内存（由于有环，手动断开环再释放）
    node4->next = nullptr;
    delete node4;
    delete node3;
    delete node2;
    delete head;

    // 测试无环链表
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    ListNode *noCycleNode = detectCycle(head2);
    if (noCycleNode)
        std::cout << "环的起始节点值为: " << noCycleNode->val << std::endl;
    else
        std::cout << "链表无环" << std::endl;
    delete head2->next;
    delete head2;

    return 0;
}
