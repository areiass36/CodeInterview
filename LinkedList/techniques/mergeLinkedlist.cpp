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

int main() {
    node *a = NULL;
    insert(a,1);
    insert(a,5);
    insert(a,7);
    insert(a,10);
    insert(a,23);
    printList(a); // 1-->5-->7-->10-->23-->

    node *b = NULL;
    insert(b,2);
    insert(b,3);
    insert(b,6);
    printList(b); // 2-->3-->6-->

    node * head = merge(a, b);

    printList(head); // 1-->2-->3-->5-->6-->7-->10-->23-->

    return 0;
}