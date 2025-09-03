// Problem-1: Flatten multilevel doubly linked list.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        stack<Node*> stk;
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                if (curr->next) {
                    stk.push(curr->next);
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            if (!curr->next && !stk.empty()) {
                Node* nextNode = stk.top();
                stk.pop();
                curr->next = nextNode;
                nextNode->prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};

void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->child = new Node(4);
    head->next->child->next = new Node(5);
    head->next->child->next->prev = head->next->child;
    head->next->child->child = new Node(6);

    Solution solution;
    Node* flattenedHead = solution.flatten(head);
    printList(flattenedHead);

    return 0;
}