#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACKSIZE 100
// store operand from user
char stack[100];
int topOfStack = -1;

// store final output
char output[100];
int topOfOutput = -1;

// store after calculate
float calStack[100];
int topCalStack = -1;

void toPostfix(char *input); // change string to postfix
void calPostfix(char *postfix); // calculate postfix
                    
// stack implement
void push(char token, char *st, int *top);
void pushNum(float number, float *st, int *top);
int priority(char token); // token priority

char output[100];

int main() {
  int res;
  char input[100] = {'\0'};
  
  gets(input);    //get input line

  // generate posfix
  toPostfix(&input);
  calPostfix(&output);
  topOfStack = -1;
  topOfOutput = -1;
  topCalStack = -1;
  return 0;
}

void toPostfix(char *input) {
  int i, lparen =0;
  char token,x;

  for (i = 0; i < strlen(input); i++) {
    token = input[i];


    if (isalnum(token)) {
      push(token, &output, &topOfOutput);
    } else if (token == '(') {
      push(token, &stack, &topOfStack);
      lparen++;
    } else if (token == ')') {
      lparen--;

      while (stack[topOfStack] != '(') {
        push(stack[topOfStack], &output, &topOfOutput);
        topOfStack--;
      }
      topOfStack--;
    }
    else {
      while (priority(stack[topOfStack] > priority(token))) {
        push(stack[topOfStack--], &output, &topOfOutput);
      }
      push(token, &stack, &topOfStack);
    }

  }
  // 剩下的印出
  while (topOfStack != -1) {
    push(stack[topOfStack--], &output, &topOfOutput);
  }

  if (lparen != 0) {
    
  } else {
    for (int i = 0; i <= topOfOutput; i++) {
      printf("%c ", output[i]);
    }
    printf("\n");
  }
    
 
  
}
void calPostfix(char *postfix) {
  float tmp,res,o1, o2;
  char token;

  for (int i = 0; i < strlen(postfix); i++) {
    token = postfix[i];

    if (isalnum(token)) {
      tmp = token - '0';
   
      
      pushNum(tmp, &calStack, &topCalStack);
    } else {
    

      o1 = calStack[topCalStack--];
      o2 = calStack[topCalStack--];

      if (token == '+') {
        res =  o2+ o1;

        pushNum(res, &calStack, &topCalStack);
      } else if (token == '-') {
        res = o2 - o1;

        pushNum(res, &calStack, &topCalStack);
      } else if (token == '*') {
        res = o2 *o1 ;
        pushNum(res, &calStack, &topCalStack);
      } else if (token == '/') {
        res = o2 / o1;
        pushNum(res, &calStack, &topCalStack);
      }
    }

  }
  printf("%d\n", (int)round(calStack[topCalStack--]));
}

// int calPostfix(char *postfix) { return postfix; }

int priority(char token) {
  if (token == '*' || token == '/') {
    return 2;
  } else if (token == '+' || token == '-') {
    return 1;
  } else {
    return 0;
  }
}


// push token to stack 
void push(char token, char *st, int *top) { st[++*top] = token; }

// push number to calStack
void pushNum(float number, float *st, int *top) {
  st[++*top] = number;
}