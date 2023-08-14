//
// Created by eduar on 01/02/2023.
//
#include <stdlib.h>

#ifndef C_STACK_H
#define C_STACK_H

typedef void* Item;

typedef struct NODE {
    Item item;
    struct NODE* down;
} Node;

typedef struct {
    Node* top;
    int len;
} Stack;

Node* create_node(Item item, Node* down) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->item = item;
    node->down = down;
    return node;
}

Stack* create_stack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->len = 0;
    return stack;
}

int stack(Stack* stack, Item item) {
    Node* new = create_node(item, stack->top);
    stack->top = new;
    stack->len++;
    return 1;
}

int unstack(Stack* stack) {
    if (!stack->len)
        return 0;
    Node* aux = stack->top;
    stack->top = aux->down;
    free(aux);
    stack->len--;
    return 1;
}

Item get_top(Stack* stack) {
    if (!stack->len)
        return NULL;
    return stack->top->item;
}

int empty(Stack* stack) {
    return stack->len == 0;
}

void delete(Stack* stack) {
    Node* aux;
    for (Node* i = stack->top; i != NULL; ) {
        aux = i;
        i = i->down;
        free(aux);
    }

    free(stack);
}
#endif //C_STACK_H
