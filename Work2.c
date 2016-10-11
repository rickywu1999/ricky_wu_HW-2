#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node { int i; struct node *next ;};

void print_list(struct node *a){
    printf("Printing list...\n");
    while(a){
        printf("%d\n",a->i);
        a = a->next;
    }
}

struct node * insert_front(struct node *a, int b){
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->i=b;
    newnode->next=a;
    return newnode;
}

struct node * free_list(struct node *a){
    struct node *copy,*original = a;
    while(a){
        copy = a->next;
        free(a);
        a = copy;
    }
    return original;
}
    
    
int main(){
    struct node *node1;
    struct node *node2;
    struct node *node3;
    node1 = (struct node *) malloc(sizeof(struct node));
    node2 = (struct node *) malloc(sizeof(struct node));
    node3 = (struct node *) malloc(sizeof(struct node));
    node1->i = 2;
    node2->i = 3;
    node3->i = 4;
    node1->next = node2;
    node2->next = node3;
    node3->next = 0;
    struct node *head = node1;
  
    print_list(head);

    printf("Adding 1 to the front...\n");
    head = insert_front(head, 1);
    print_list(head);

    printf("Freeing...\n");
    free_list(head);
    printf("Completed!\n");
    return 0;
}
