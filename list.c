// gcc -g list.c -o list
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node_t;

int main(){
    printf("Linked list demo\n");

    // Stack allocated data
    node_t one;
           one.data = 1;
    node_t two;
           two.data = 2;
    node_t three;
           three.data = 3;
    
    one.next = &two;
    two.next = &three;
    three.next = NULL;

    // Loop through list
    node_t* iter = &one;
    while(iter!=NULL){
        printf("data=%d\n",iter->data);
        iter=iter->next;
    }

    return 0;
}
