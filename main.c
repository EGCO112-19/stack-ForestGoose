#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc,char** argv){
  printf("Checking the parentheses in argv arguments\n");
  int i,N,j;
  
  Stack s;
  s.top = NULL;
  s.size = 0;

  for(i=1;i<argc;i++){
    for(j=0;j<strlen(argv[i]);j++){
      char c = argv[i][j];
      if(c == '(' || c == '{' || c == '[')
        push(&s,c);
      if(c == ')' && pop(&s) != '(') break;
      if(c == '}' && pop(&s) != '{') break;
      if(c == ']' && pop(&s) != '[') break;
    }
    if(j == strlen(argv[i]) && s.size == 0) printf("True\n");
    else printf("False\n");
    pop_all(&s);
  }
  return 0;
}
