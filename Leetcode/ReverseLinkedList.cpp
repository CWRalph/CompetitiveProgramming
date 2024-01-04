#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * current, * next, * prev;
        if(!head) return head;
        current = head->next;
        head->next = nullptr;
        prev = head;
        while(current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            head = prev;
            current = next;
        }
        return head;
    }
};