#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

using namespace std;

class node {
public:
    int data;
    node *next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

void printList(node *head);
void insertAtHead(node *&head, int data);
void insertAtMiddle(node *&head, int data, int pos);
void insert(node *&head, int data);

#endif /* LINKEDLIST_H */