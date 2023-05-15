#include <bits/stdc++.h>
#include "../linkedlist.h"

//https://leetcode.com/problems/middle-of-the-linked-list/description/

using namespace std;

int getMid(node *head){
    if (head == NULL) return -1;

    node *slow = head;
    node *fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}


int main() {
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    printList(head); // 1-->2-->3-->4-->5-->6-->7-->

    cout << getMid(head) << endl; // 4

    insert(head, 8);
    printList(head); // 1-->2-->3-->4-->5-->6-->7-->8-->

    cout << getMid(head) << endl; // 4

    return 0;
}