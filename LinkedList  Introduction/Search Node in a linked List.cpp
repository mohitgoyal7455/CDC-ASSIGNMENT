struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() {
        head = nullptr;
    }

    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = head;
        head = node;
    }

    bool search(int val) {
        ListNode* curr = head;
        while (curr) {
            if (curr->val == val) return true;
            curr = curr->next;
        }
        return false;
    }
};
