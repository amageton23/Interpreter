#include <stdio.h>
#include <stdlib.h>



int main(){

}



struct Node {    
    char data[100];
    struct Node* prev;

    struct Node* next;
};

struct linkedList{
    struct Node* firstNode;
    struct Node* lastNode;
};

struct Node *createNode(char new_data[100]){
    struct Node* new_node = (struct Node *)
    malloc(sizeof(struct Node));
    struct linkedList* linked = (struct linkedList *)
    malloc(sizeof(struct linkedList));
    new_node -> data[100] = new_data[100];
    new_node -> next = NULL;
    new_node -> prev = NULL;
    linked ->firstNode = new_node;
    linked ->lastNode = new_node;
    
    return new_node;
}
void viewNodes( struct linkedList* linked){
   
   
    struct Node* curr = (*linked).firstNode;
    while(curr != NULL){
        printf("&d",curr -> data[100]);

        curr = curr.next;
    }
}

struct Node *insertNode(int new_data){
    struct 
}

