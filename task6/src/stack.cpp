#include <string>
#include <Stack/stack.h>

Stack *Create() {
    return new Stack;
}

void Push(Stack *stack, char val) {
    Node *node = new Node;
    node->val = val;

    if (stack->head == nullptr) {
        stack->head = node;
    }
    else {
        node->next = stack->head;
        stack->head = node;
    }
    stack->size++;
}

char Top(Stack *stack) {
    if (stack->head == nullptr) {
        return -1;
    }
    return stack->head->val;
}

void Pop(Stack *stack) {
    if (stack->head == nullptr) {
        return;
    }
    Node *current = stack->head;
    stack->head = stack->head->next;
    delete current;
    stack->size--;
}

int sizeOfStk(Stack *stack) {
    return stack->size;
}

bool Empty(Stack *stack) {
    return stack->size == 0;
}
