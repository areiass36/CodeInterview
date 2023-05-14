#include <bits/stdc++.h>
#include "../linkedlist.h"

using namespace std;

//Time - O(n)
//Space - O(n)
node *recursiveReverse(node *head){
    if (head == NULL){
        return NULL;
    }
    node *newHead = head;
    if (head->next){
        newHead = recursiveReverse(head->next);
        head->next->next = head;
    }
    head->next = NULL;

    return newHead;
}

int main() {
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insertAtHead(head, 5);
    printList(head); // 5-->1-->2-->3-->4-->

    head = recursiveReverse(head);

    printList(head); // 4-->3-->2-->1-->5-->

    return 0;
}