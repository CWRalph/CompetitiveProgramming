struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int, int> mmap;
        ListNode* H1 = nullptr, *head = nullptr;
        for (auto i : lists) for (ListNode* current = i; current; current = current->next) ++mmap[current->val];
        for (auto i : mmap)
        {
            while (i.second--)
            {
                if (H1 != nullptr) { H1->next = new ListNode(i.first); H1 = H1->next; }
                else { H1 = new ListNode(i.first); head = H1; }
            }
        }
        return head;
    }
};