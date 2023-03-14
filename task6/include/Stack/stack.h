#include <ostream>
#include <iostream>
struct Node {
    Node *next = nullptr;
    char val;
};

struct Stack {
    Node *head = nullptr;
    Node *last = nullptr;
    int size = 0;
};

Stack *Create();

void Push(Stack *stack, char val);

char Top(Stack *stack);

void Pop(Stack *stack);

int sizeOfStk(Stack *stack);

bool Empty(Stack *stack);
