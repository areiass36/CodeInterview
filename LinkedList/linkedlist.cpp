#include "linkedlist.h"

using namespace std;
void printList(node *head) {
    while(head != NULL){
        cout<<head->data<< "-->";
        head = head->next;
    }
    cout<<endl;
}

void insertAtHead(node *&head, int data){
    if (head == NULL){
        head = new node(data);
        return;
    }
    node *newNode = new node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtMiddle(node *&head, int data, int pos){
    if (pos == 0){
        insertAtHead(head,data);
        return;
    }
    node *dummyHead = head;
    int cnt=1;
    while(cnt < pos and dummyHead != NULL){
        dummyHead = dummyHead->next;
        cnt++;
    }
    if (dummyHead != NULL){       
        node *newNode = new node(data);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
    }
}

void insert(node *&head, int data){
    if (head == NULL){
        head = new node(data);
        return;
    }
    node *dummyHead = head;
    while(dummyHead->next != NULL){
        dummyHead = dummyHead->next;
    }
    node *newNode = new node(data);
    dummyHead->next = newNode;
}