#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node { int i; struct node *next ;};

int print_list(struct node *a){
    struct node *pointer = a;
    printf("Printing list...\n");
    while(pointer->next){
        printf("%d\n",pointer->i);
        pointer = pointer->next;
    }
    printf("%d\n",pointer->i);
    return 0;
}

struct node * insert_front(struct node *a, int b){
  struct node *newnode;
  newnode = (struct node *) malloc(sizeof(struct node));
  newnode->i=b;
  newnode->next=a;
  return newnode;
}

struct node * free_list(struct node *a){
  struct node *copy = a;
  struct node *original = a;
  while (copy->next){
    copy= copy->next;
    free(a);
    a = copy;
  }
  free(a);
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
  print_list(free_list(head));

  return 0;
}
