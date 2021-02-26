
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s,char value){
  Node *new_node = (Node*)malloc(sizeof(Node));
  if(new_node){
    new_node->data = value;
    new_node->nextPtr= s->top;
    s->top=new_node;
    s->size++;
  }
}
char pop(StackPtr s){
  if(s->top == NULL) return '\0';
  NodePtr temp = s->top;
  char value = temp->data;
  s->top = temp->nextPtr;
  s->size--;
  free(temp);
  return value;
}
void pop_all(StackPtr s){
  while(s->size){
    NodePtr temp = s->top;
    s->top = temp->nextPtr;
    s->size--;
    free(temp);
  }
}
#endif
