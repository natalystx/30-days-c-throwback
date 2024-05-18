#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *prev;
};

struct stack{
    struct node *head;
};


void push(struct stack *stack, int data){
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = stack->head;
    stack->head = new_node;
}

void pop(struct stack *stack){
    stack->head = stack->head->prev;
}

int size(struct stack *stack){
    int count = 0;
    struct node *current_node = stack->head;
    
    while (current_node != NULL)
    {
        count++;
        current_node = current_node->prev;
    }

    return count;
    
}

void show_stack_value(struct stack *stack){
    struct node *current_node = stack->head;
    
    while (current_node != NULL){
        printf("%d\n", current_node->data);
        current_node = current_node->prev;
    }
}


int main() {
    struct stack stack;
    stack.head = NULL;
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    show_stack_value(&stack);
    printf("size: %d\n", size(&stack));
    printf("pop\n");
    pop(&stack);
    show_stack_value(&stack);
    printf("size: %d\n", size(&stack));

    return 0;
}
