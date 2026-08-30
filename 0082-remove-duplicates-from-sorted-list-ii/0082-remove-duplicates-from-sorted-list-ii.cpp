class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* curr = NULL;
        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {

            if (temp->val == temp->next->val) {

                int value = temp->val;

                while (temp != NULL && temp->val == value) {
                    ListNode* toDelete = temp;
                    temp = temp->next;
                    delete toDelete;
                }

                if (curr == NULL) {
                    head = temp;
                } else {
                    curr->next = temp;
                }

            } else {

                curr = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};