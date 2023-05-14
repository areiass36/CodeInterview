#include <bits/stdc++.h>
#include "../linkedlist.h"

using namespace std;

//Time - O(n)
//Space - O(1)
node *iterativeReverse(node *head){
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;

    while(curr != NULL){
        //save the next node
        next = curr->next;
        //reverse the pointer of current node
        curr->next = prev;
        //update prev and curr
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

int main() {
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insertAtHead(head, 5);
    printList(head); // 5-->1-->2-->3-->4-->

    head = iterativeReverse(head);

    printList(head); // 4-->3-->2-->1-->5-->

    return 0;
}