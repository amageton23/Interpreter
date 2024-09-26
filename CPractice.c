#include <stdio.h>
#include <stdlib.h>
#include <string.h>






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
    struct Node* new_node = (struct Node*)
    malloc(sizeof(struct Node));
    
    strncpy(new_node -> data,new_data,100);
    new_node -> next = NULL;
    new_node -> prev = NULL;    
    return new_node;
}

struct linkedList *createList(struct Node* first, struct Node* last){
    struct linkedList* linked = (struct linkedList*)
    malloc(sizeof(struct linkedList));
    linked -> firstNode = first;
    linked -> lastNode = last;
    return linked;

}
void viewForwardList( struct linkedList* linked){
    
    struct Node* curr = (*linked).firstNode;
    while(curr != NULL){
        printf("%s\n",curr -> data);

        curr = (*curr).next;
    }
}

void viewForwardNodes( struct Node* current){
    struct Node* curr = current;
    while(curr != NULL){
        printf("%s\n",curr -> data);

        curr = (*curr).next;
    }
}

void viewBackwardsList(struct linkedList* linked){
    struct Node* curr = (*linked).lastNode;
    while(curr != NULL){
        printf("%s\n",curr -> data);

        curr = (*curr).prev;
    }
}

void viewBackwardNodes( struct Node* current){
    struct Node* curr = current;
    while(curr != NULL){
        printf("%s\n",curr -> data);

        curr = (*curr).prev;
    }
}

struct Node *insertAfter(struct linkedList* linked, struct Node* node, struct Node* newNode){
    newNode -> prev = node;
    if(node->next == NULL){
        newNode -> next = NULL;
        linked -> lastNode = newNode;
    } 
    else{
        newNode -> next = node->next;
        node -> next -> prev = newNode;
    }
    node -> next = newNode;
}

int main(){
    struct Node* first = createNode("hello");
    struct linkedList* listy = createList(first, first);
    struct Node* second = createNode("bye");
    insertAfter(listy, first, second);

    viewForwardList(listy);
    
}
