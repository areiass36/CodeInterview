#include <bits/stdc++.h>
#include "../linkedlist.h"

using namespace std;

node *kReverse(node *head, int k){
    //base case
    if (head == NULL){
        return NULL;
    }
    //reverse first k nodes
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;

    int cnt = 1;

    while(curr != NULL and cnt <= k){
        //save the next node
        next = curr->next;
        //reverse the pointer of current node
        curr->next = prev;
        //update prev and curr
        prev = curr;
        curr = next;
        cnt++;
    }

    //If there are more than k nodes in the list
    if (next != NULL){
        head->next = kReverse(next, k);
    }

    return prev;
}

int main() {
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insertAtHead(head, 0);
    printList(head); // 0-->1-->2-->3-->4-->5-->

    head = kReverse(head, 3);

    printList(head); // 2-->1-->0-->5-->4-->3-->

    return 0;
}