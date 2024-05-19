#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front, *rear;
};

struct queue* create_queue(){
     struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct queue *queue, int data){
    struct node *current_node =  (struct node*)malloc(sizeof(struct node));
    current_node->data = data;
    current_node->next = NULL;

    if(queue->front == NULL){
        queue->front = queue->rear = current_node;
    }else{
        queue->rear->next = current_node;
        queue->rear = current_node;
    }
}

void dequeue(struct queue *queue){
    if(queue->front != NULL){
        struct node *temp = queue->front;
        queue->front = queue->front->next;
        if(queue->front == NULL){
            queue->rear = NULL;
        }
        free(temp);
    }
}

void display_queue(struct queue *queue){
    struct node *current_node = queue->front;
     
    while (current_node != NULL) {
       printf("%d\n",current_node->data);
       current_node = current_node->next;
    }
    
}

int queue_size(struct queue *queue){
    int count = 0;
     struct node *current_node = queue->front;
     
    while (current_node != NULL) {
      count++;
       current_node = current_node->next;
    }

    return count;
}

int main(){
    
    struct queue *q = create_queue();
    
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    dequeue(q);
    display_queue(q);
    printf("size: %d\n", queue_size(q));

    return 0;
}
