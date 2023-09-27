#include<bits/stdc++.h>
using namespace std;

//

class node{
public:  
    int data;
    node * next;

    node(int data){
        this->data = data;
    }
};

// Time - O(n)
// Space - O(n)
node * breakChain(node * head){
    unordered_set<node*> s;

    node *dummyHead = head;
    node *prev = NULL;
    while(dummyHead != NULL){
        if (s.find(dummyHead) != s.end()) {
            if (prev != NULL) prev->next = NULL;
            break;
        }

        s.insert(dummyHead);
        prev = dummyHead;
        dummyHead = dummyHead->next;
    }

    return head;
}

int main() {
    node *head = new node(1);
    node *cycleNode = new node(2);
    head->next = cycleNode;
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = cycleNode;

    auto newHead = breakChain(head);

    while(newHead != NULL){
        cout << newHead->data << "->";
        newHead = newHead->next;
    }
    cout << endl;
}



