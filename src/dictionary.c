#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

struct DataItem {
   char* key;
   char* data;   
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(char* key) {
   int value = 0, i;
   for (i = 0; i < strlen(key); i++)
      value += key[i];
   return value % SIZE;
}

struct DataItem *search(char* key) {
   //get the hash 
   int hashIndex = hashCode(key);  
    
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
    
      if(strcmp(hashArray[hashIndex]->key, key) == 0)
         return hashArray[hashIndex]; 
            
      //go to next cell
      ++hashIndex;
        
      //wrap around the table
      hashIndex %= SIZE;
   }        
    
   return NULL;        
}

void insert(char* key,char* data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   item->key = key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && strcmp(hashArray[hashIndex]->key, " ") != 0) {
      //go to next cell
      ++hashIndex;
        
      //wrap around the table
      hashIndex %= SIZE;
   }
    
   hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
   char* key = item->key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
    
      if(strcmp(hashArray[hashIndex]->key, key) == 0) {
         struct DataItem* temp = hashArray[hashIndex]; 
            
         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
        
      //go to next cell
      ++hashIndex;
        
      //wrap around the table
      hashIndex %= SIZE;
   }      
    
   return NULL;        
}

void display() {
   int i = 0;
    
   for(i = 0; i<SIZE; i++) {
    
      if(hashArray[i] != NULL)
         printf(" (%s,%s)",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~~ ");
   }
    
   printf("\n");
}

int main() {
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = " ";  
   dummyItem->key = " "; 

   insert("name", "John");
   insert("age", "25");
   insert("day", "monday");
   insert("phone", "1234567890");
   insert("address", "123 Street");

   display();
   item = search("age");

   if(item != NULL) {
      printf("Element found: %s\n", item->data);
   } else {
      printf("Element not found\n");
   }

   delete(item);
   item = search("phone");

   if(item != NULL) {
      printf("Element found: %s\n", item->data);
   } else {
      printf("Element not found\n");
   }
}