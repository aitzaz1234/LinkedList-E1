#include "LinkedList.h"
#include <iostream>

Node::Node(int value) : data(value), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    while (!isEmpty()) {
        deleteNode(head->data);
    }
}

Node* LinkedList::getHead() {
    return head;
}

bool LinkedList::isEmpty() {
    return head == nullptr;
}

void LinkedList::insertAtHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::insert(int oldValue, int newValue) {
    Node* temp = head;
    while (temp != nullptr && temp->data != oldValue) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        Node* newNode = new Node(newValue);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else {
        insertAtEnd(newValue);
    }
}

void LinkedList::deleteNode(int value) {
    if (isEmpty()) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
}

void LinkedList::traverse() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
