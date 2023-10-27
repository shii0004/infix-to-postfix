#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

struct Stack {
  int size;
  int top;
  char * arr;
};

struct Stack * s;

int isEmpty() {
  if (s->top == -1) {
    return 1;
  } else {
    return 0;
  }
}

void push(char c) { // pushes into stack
  s->top++;
  s->arr[s->top] = c;
}

char pop() { // pops out of stack
  char popped = s->arr[s->top];
  s->top--;
  return popped;
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return 1;
    } else return 0;
}

int Prec(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

char stackTop() {
    if (s->top == -1) {
        return 0;
    }
    char c = s->arr[s->top];
    return c;
}

char * infixToPostfix (char inFix[]) {
    char * postFix;
    postFix = (char *) malloc((s->size + 1)*sizeof(char));
    int i = 0;
    int j = 0;
    while (inFix[i] != '\0') {
        if (isOperator(inFix[i])) {
            if (Prec(inFix[i]) > Prec(stackTop())) {
                push(inFix[i]);
                i++;
            } else {
                postFix[j] = pop();
                i++;
                j++;
            }
                
            }
        else {
            postFix[j] = inFix[i];
            i++;
            j++;
        }
        
        
    }
    
    while(!isEmpty()) {
        postFix[j] = pop();
        j++;
}

postFix[j] = '\0';
return postFix;
}

int main () {
  char exp[MAX_SIZE];
  printf("Write expression: ");
  scanf("%s", exp);
  
  s = (struct Stack *) malloc(sizeof(struct Stack));
  s->size = strlen(exp);
  s->top = -1;
  s->arr = (char *) malloc((s->size+1)*sizeof(char));
  
  char * c = infixToPostfix(exp);
  
  printf("Postfix expression is: %s", c);
  
}
