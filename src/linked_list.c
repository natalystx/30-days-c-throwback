#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;    
};


struct linked_list{
    struct node *head;    
};


void add_node(struct linked_list *list, int data){
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

   if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
   
}

void insert_at_beginning(struct linked_list *list, int data){
 struct node *new_node = malloc(sizeof(struct node));
 new_node->data = data;
  struct node *prev = list->head;
  list->head = new_node;
  new_node->next = prev;
}

struct node* get_node(struct linked_list *list, int index){  
    struct node *current = list->head;

    if( list->head == NULL){
        return  list->head;
    }


    int currentIndex = 0;

    while (currentIndex <= index) {             
        if(currentIndex == index){            
            if( current == NULL){
                current = current;
            }
            break;
        }
        current = current->next;
        currentIndex++;
    }
    

    return current;
}

 void insert_at(struct linked_list *list, int index, int data) {
      struct node *new_node = malloc(sizeof(struct node));
       new_node->data = data;
    if( list->head == NULL || index == 0){
        new_node->next = list->head;
       list->head = new_node;       
    }


   
   if(index > 0){

    struct node *current = list->head;
    struct node *prev = NULL;

    int currentIndex = 0;
    while (currentIndex <= index) {
     
        if(currentIndex == index -1){
            prev = current;        
        }             
        if(currentIndex == index ){
            prev->next = new_node;
            new_node->next = current;          
            break;
        }
        current = current->next;
        currentIndex++;
    }

   }


 

}


bool delete_node(struct linked_list *list, int index) {
    if( list->head == NULL){
        return  false;
    }


    if(index == 0){
        list->head = list->head->next;
        return true;
    }

    struct node *current = list->head;
    struct node *prev = NULL;

    int currentIndex = 0;
    while (currentIndex <= index) {
        if(current == NULL){
            break;
        }

        if(currentIndex == index -1){
            prev = current;        
        }             
        if(currentIndex == index ){
            prev->next = current->next;
            break;
        }
        current = current->next;
        currentIndex++;
    }

    return true;

}




void show_list_data(struct linked_list *list){
    struct node *current_node;
    current_node = list->head;

    while (current_node != NULL)
    {
        printf("%d\n",current_node->data);
        current_node = current_node->next;
    }
    
}


int get_list_size(struct linked_list *list){
    int count = 0;
    struct node *currentNode = list->head;

    while (currentNode != NULL)
    {
        count++;
        currentNode = currentNode->next;
    }

    return count;
    
}



int  main(){
    struct linked_list list;     
    list.head = NULL;

    add_node(&list, 1);
    add_node(&list, 2);
    add_node(&list, 3);
    add_node(&list, 4);
    insert_at_beginning(&list, 100);
    insert_at(&list, 3,99);
    delete_node(&list, 3);
    printf("node %dth: %d\n", 2, get_node(&list,2)->data);
    printf("node size: %d\n", get_list_size(&list));
    
    show_list_data(&list);

    return -1;
}