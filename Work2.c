#include <stdio.h>
#include <string.h>

struct node { int i; struct node *next };

int print_list(* a){
  
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
}
