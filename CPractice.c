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

struct linkedList *createList(){
    struct linkedList* linked = (struct linkedList*)
    malloc(sizeof(struct linkedList));
    linked -> firstNode = NULL;
    linked -> lastNode = NULL;
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


struct Node *insertBefore(struct linkedList* linked, struct Node* node, struct Node* newNode){
    newNode -> next = node;
    if(node -> prev = NULL){
        newNode -> next = NULL;
        linked -> firstNode = newNode;
    }
    else{
        newNode -> prev = node -> prev;
        node -> prev -> next = newNode;
    }
    node -> prev = newNode;
}

struct Node *insertBeginning(struct linkedList* linked, struct Node* newNode){
    if(linked -> firstNode == NULL){
        linked -> firstNode = newNode;
        linked  -> lastNode = newNode;
        newNode -> prev = NULL;
        newNode -> next = NULL;
    }
    
    else{
        insertBefore(linked, linked -> firstNode, newNode);
    }
}

struct Node *insertEnd(struct linkedList* linked, struct Node* newNode){
    if(linked -> lastNode == NULL){
        insertBeginning(linked, newNode);
    }
    else{
        insertAfter(linked, linked -> lastNode, newNode);
    }
}

void removed(struct linkedList* linked, struct Node* node){
    if(node -> prev == NULL){
        linked -> firstNode = node -> next;
    }
    else{
        node -> prev -> next = node -> next;
    }
    if(node -> next == NULL){
        linked -> lastNode = node -> prev;
    }
    else{
        node -> next -> prev = node -> prev;
    }
}

int main(){
    struct Node* first = createNode("hello");
    struct linkedList* linked = createList();
    
    insertEnd(linked, first);
    struct Node* second = createNode("bye");
    insertEnd(linked, second);
    removed(linked, second);
    viewForwardList(linked);


    
}
