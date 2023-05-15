#include <bits/stdc++.h>
#include "../linkedlist.h"

using namespace std;

//Time - O(n+m)
//Space - O(n+m)
node *merge(node *a, node *b){
    if (a == NULL) return b;
    if (b == NULL) return a;

    node *dummyNode;

    if (a->data < b->data){
        dummyNode = a;
        dummyNode->next = merge(a->next, b);
    }else{
        dummyNode = b;
        dummyNode->next = merge(a, b->next);
    }
    return dummyNode;
}

node *getMidPoint(node *head){
    node *slow = head;
    node *fast = head->next;

    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

//Time O(n log n)
node *mergeSort(node *head){
    if (head == NULL or head->next == NULL){
        return head;
    }

    node *mid = getMidPoint(head);

    node *a = head;
    node *b = mid->next;
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a,b);
}

int main() {
    node *head = NULL;
    insert(head,10);
    insert(head,7);
    insert(head,5);
    insert(head,17);
    insert(head,14);
    insert(head,23);
    insert(head,21);
    printList(head); // 10-->7-->5-->17-->14-->23-->21-->

    head = mergeSort(head);

    printList(head); // 5-->7-->10-->14-->17-->21-->23-->

    return 0;
}