class Solution:
    def getLinkedSum(self, l1: ListNode):
        l = list(); total = 0
        while(l1 != None):
            l.append(l1.val)
            l1 = l1.next
        for index, elem in enumerate(l):
            total += elem * (10 ** index)
        return total
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        total = self.getLinkedSum(l1) + self.getLinkedSum(l2)
        result = [int(x) for x in str(total)]
        current = None; previous = None
        for elem in result:
            current = ListNode(elem,previous)
            previous = current
        return current