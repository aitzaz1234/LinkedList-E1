#pragma once

class Node {
public:
    int data;
    Node* next;
    Node(int value);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();
    Node* getHead();
    bool isEmpty();
    void insertAtHead(int value);
    void insertAtEnd(int value);
    void insert(int oldValue, int newValue);
    void deleteNode(int value);
    void traverse();
};

