#include <bits/stdc++.h>
#include "../linkedlist.h"

//https://leetcode.com/problems/linked-list-cycle/
//furthur reading: https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/

using namespace std;

bool containsCycle(node *head){
    if (head == NULL)
        return false;
    node *slow = head;
    node *fast = head->next;

    while(fast != NULL and fast->next != NULL){
        if (slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
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
    insert(head, 8);
    
    //do the last node point to third node
    node *temp = head;
    node *tempToPoint;
    int cnt = 3;
    while(temp->next != NULL){
        if (cnt-- == 1)
            tempToPoint = temp;
        temp = temp->next;
    }
    temp->next = tempToPoint;
    

    cout << containsCycle(head) << endl; // 4

    return 0;
}