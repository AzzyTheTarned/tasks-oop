#include <iostream>
#include <ostream>
#include <RingBuff.h>

List::List() {
    head = NULL;
    tmp = head;
};

void List::init(int length) {
    head = new Node;
    tmp = head;
    Node* current = head;
    for (int i = 0; i < length - 1; i++) {
        current->next = new Node;
        current = current->next;
    }
    current->next = head;
};

void List::Print(std::ostream& os) {
    Node* current = head;
    do {
        if (current->value == NULL) {
            os << " " << "#" << std::endl;
        }
        else {
            os << " " << current->value << std::endl;
        }
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}

void List::add(char x) {
    tmp->value = x;
    tmp = tmp->next;
};
