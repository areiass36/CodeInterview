#include <bits/stdc++.h>
#include "../linkedlist.h"

//Little different on Leetcode
//Remove Nth Node From End of List
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

using namespace std;

//Time O(2n) -> could be better
int kthLastElement(node *head, int k){
    if (head == NULL){
        return -1;
    }
    node *slow = head;
    node *faster = head->next;
    int listSize = 1;
    while (faster != NULL and faster->next != NULL){
        faster = faster->next->next;
        listSize += 2;
    }
    //corner case when list has even nodes
    if (faster != NULL) listSize++;
    
    int needWalk = listSize - k;
    while(needWalk > 0){
        slow = slow->next;
        needWalk--;
    }
    return slow->data;
}

//Solving in one pass
//Time O(n)
int kthLastElement2(node *head, int k){
    if (head == NULL){
        return -1;
    }
    node *tail = head;
    while(k--){
        tail = tail->next;
    }

    node *kthNode = head;

    while(tail){
        kthNode = kthNode->next;
        tail = tail->next;
    }

    return kthNode->data;
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

    cout << kthLastElement(head,3) << endl; // 5

    return 0;
}