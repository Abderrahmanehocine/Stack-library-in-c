#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <string.h>

#define DATATYPE TYPE

typedef enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE
}DATATYPE;

int MAXSIZE=0;

void* head=NULL;
TYPE stackType;

void stack(int size_of_stack, TYPE t){
  stackType=t;
  MAXSIZE=size_of_stack;
  if(t == CHAR){
    char *a=(char*)calloc(MAXSIZE,sizeof(char));
    head=a;
  }
  else if(t == INT){
    int *a=(int*)calloc(MAXSIZE,sizeof(int));
    head=a;
  }
  else if(t == FLOAT){
    float *a=(float*)calloc(MAXSIZE,sizeof(float));
    head=a;
  }
  else if(t == DOUBLE){
    double *a=(double*)calloc(MAXSIZE,sizeof(double));
    head=a;
  }
}

int Top=-1;

int isempty() {
  if(Top == -1){
    return 1;
  }
  return 0;
}

int isfull() {
 if(Top == MAXSIZE){
   return 1;
 }
 return 0;
}

void* top() {
  if(stackType == INT){
    return *((int*)head+Top);
  }
  else if(stackType == CHAR){
    return *((char*)head+Top);
  }
  /*else if(stackType == FLOAT){
    return *((float*)head+Top);
  }
  else if(stackType == DOUBLE){
    return *((double*)head+Top);
  }*/
  return stackType;
}

void push(int data) {
   if(!isfull()) {
      Top = Top + 1;  
     if(stackType == INT){
       *((int*)head+Top)=data;
     }
     else if(stackType == CHAR){
       strcpy(data,*((char*)head+Top));
     }
   } 
}

void pop() {
   int data;
	
   if(!isempty()) {
      data = *((int*)head+Top);
      free(data);
      Top = Top-1;   
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}
#endif
