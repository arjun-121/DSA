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
    void reorderList(ListNode* head) {

        ListNode* nextP = head;
        ListNode* prev = head;

        while(nextP -> next  && nextP -> next -> next) {
            nextP = nextP -> next -> next;
            prev = prev -> next;
        }

        ListNode* past = NULL;
        nextP = prev -> next;

        while(nextP) {
            prev -> next = past;
            past = prev;
            prev = nextP;
            nextP = nextP -> next;
        }
        prev -> next = past;
        nextP = head;
        ListNode* first = head;
        ListNode* second = prev;

        while(first && second) {
            ListNode* temp1 = first -> next;
            ListNode* temp2 = second -> next;
            first -> next = second;
            second -> next = temp1;
            first = temp1;
            second = temp2;
        }

        return;
    }
};