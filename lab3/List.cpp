//
// Created by Szilárd on 10/12/2023.
//

#include "List.h"
#include <iostream>

List::List() {
    first = nullptr;
    nodeCounter = 0;
}

List::~List() {
    while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }
}
bool List::exists(int d) const {
    Node* temp = first;
    while (temp != nullptr) {
        if (temp->value == d) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    return (nodeCounter == 0);
}

void List::insertFirst(int d) {
    Node* newNode = new Node(d, first);
    first = newNode;
    nodeCounter++;
}

int List::removeFirst() {
    Node* temp = first;
    int value = temp->value;
    first = first->next;
    delete temp;
    nodeCounter--;
    return value;
}

void List::remove(int d, DeleteFlag df) {
    Node* current = first;
    Node* previous = nullptr;

    while (current != nullptr) {
        if ((df == DeleteFlag::LESS && current->value < d) ||
            (df == DeleteFlag::EQUAL && current->value == d) ||
            (df == DeleteFlag::GREATER && current->value > d)) {
            if (previous == nullptr) {
                first = current->next;
            } else {
                previous->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            delete temp;
            nodeCounter--;
        } else {
            previous = current;
            current = current->next;
        }
    }
}

void List::print() const {
    Node* current = first;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
}