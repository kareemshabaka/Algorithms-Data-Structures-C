#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct node *element(struct node *dll, int i) ;
struct node *add(struct node *dll, int i, int value) ;
struct node *delete(struct node *dll, int i);

typedef struct node Node;

struct node {
    int value;
    Node *next;
    Node *prev;
    
};

struct node *element(struct node *dll, int i) {
    Node* ptr=dll;
    if (i<0) {
        return ptr=NULL;
        
    } else {
        for (int j=0;j<i;j++) {
            ptr = ptr->next;
            if (ptr==NULL){
                return ptr;
            }
        }
    }
    
    return ptr;
}
struct node *add(struct node *dll, int i, int value) {
    Node *newNode;
    Node* tempb;
    Node* tempa;
    newNode = (Node*)malloc(sizeof(struct node));
    newNode->value=value;
    if (element(dll,i)==NULL) {
        tempa=dll;
        while (tempa->next!=NULL){
            tempa = tempa->next;
        }
        tempa->next=newNode;
        newNode->next=NULL;
        newNode->prev=tempa;
        return dll;
    } else if (i==0) {
        newNode->next = dll;
        newNode->prev = NULL;
        dll->prev=newNode->next;
        return newNode;
    } else if (i>0) {
        tempa=element(dll,i);
        tempb=element(dll,i-1);

        tempb->next=newNode;
        tempa->prev=newNode;
        newNode->prev=tempb;
        newNode->next=tempa;

        return dll;
    }

};

struct node *delete(struct node *dll, int i){
    struct node* ptr = element(dll,i);
    if (ptr!=NULL){
        if (i==0){
            struct node* head = element(dll,i+1);
            dll=head;
            head->prev=NULL;
            free(ptr);
        }else {
            Node* tempb=element(dll,i-1);
            Node* tempa=element(dll,i+1);
            tempb->next=tempa;
            tempa->prev=tempb;
        }

    }
    return dll;
};

void printNode (struct node *dll) {
    if (dll != NULL) {
        printf("< This: %p - %d - P : %p - N : %p >\n", dll, dll->value, dll->prev, dll->next);
    } else {
        printf("Null Pointer");
    }
}


void printLL (struct node *dll) {
    struct node* ptr = dll;
    printf("---\n");
    while (ptr != NULL) {
        printNode(ptr);
        ptr = ptr->next;
    }
    printf("---\n\n");
}

int main () {
 
    //Testing code! 
    struct node *dll = malloc(sizeof(struct node));
    dll->value = 1;
    dll->next = NULL;
    dll->prev = NULL;
    printLL(dll);
    dll = add(dll, -1, 3);
    printLL(dll);
    dll = add(dll, -1, 4);
    printLL(dll);
    dll = add(dll, 1, 2);
    printLL(dll);
    dll = add(dll, 2, 7);
    printLL(dll);
    dll = add(dll, 9, -1);
    printLL(dll);
    dll = delete(dll, 2);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 4);
    printLL(dll);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    dll = delete(dll, 0);
    printLL(dll);
}

/* Expected Output: 

---
< This: 0x1cf8590 - 1 - P : (nil) - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf8610 >
< This: 0x1cf8610 - 7 - P : 0x1cf85f0 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8610 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

*/ 