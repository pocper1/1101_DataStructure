#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACKSIZE 100

struct stack{
  int top;
  int items[STACKSIZE];
};

struct stack st;
st.top = -1;

char output[100+1];
int top = -1;

void toPostfix(char*, char*);   //change string to postfix
int calPostfix(char*);   //calculate postfix
int isEmpty();
void push(int);
int pop();
int priority(char); //token priority


int main() {
  int res;
  char input[100] = {'\0'};
  char output[100] = {'\0'};
  
  while (gets(input) != EOF) {
  // gets(input);

    // generate posfix
    toPostfix(input, output);
    printf("%s\n", output);

    // calculate result
    res = calPostfix(output);
    printf("res %d", res);
    top = -1;
  }
  
   return 0;
}

void toPostfix(char* input, char* postfix) {
  int i=0,j=0;

  while (input[i] != '\0') {
    printf("i: %d\n", i);
    switch (input[i]) {
      case '+':
      case '-':
      case '*':
      case '/':
        while (priority(stack[top] >= priority(input[i]))) {
          // char token = pop();
          // push(token);
          postfix[j] = stack[top--];
        }
        stack[++top] = input[i];
        break;
      case ')':
        while (stack[top] != '(') {
          postfix[j++] = stack[top--];
        }
        top--;
        break;
      default:
        postfix[j++] = input[i];
        break;
      }
      i++;
  }
  while(top != -1) {
    postfix[j++] = stack[top--];
  }
  
}
int calPostfix(char *postfix) {
  int i=0,j=0;
  int res;
  char token1, token2, tmp;
  int token1_val, token2_val,tmp_val;
  int top =-1;
  double dstack[STACKSIZE] = {0.0};

  if (!strlen(postfix))
    return -1;

  while (postfix[i] != '\0') {
    // printf("top %d",top);
    if (isdigit(postfix[i])) {
      dstack[++top] = postfix[i] - '0';
    }
    else {
      switch (postfix[i]) {
        case '+':
          token1 = dstack[top--];
          token2 = dstack[top--];
          printf("%s %s\n", token1, token2);
          token1_val = (int)(token1 - '0');
          token2_val = (int)(token2 - '0');
          tmp_val = token1_val + token2_val;

          
          printf("tmp:%d token1:%d token2:%d\n",tmp_val,token1_val,token2_val);
          dstack[++top] = tmp;
          break;
        case '-':
          token1 = dstack[top--];
          token2 = dstack[top--];
          tmp = (token1 - '0') - (token2 - '0');
          dstack[++top] = tmp;
          break;
        case '*':
          token1 = dstack[top--];
          token2 = dstack[top--];
          tmp = (token1 - '0') - (token2 - '0');
          dstack[++top] = tmp;
          break;
        case '/':
          token1 = dstack[top--];
          token2 = dstack[top--];
          tmp = (token1 - '0') - (token2 - '0');
          dstack[++top] = tmp;
          break;
        default:
          break;
      }
    }
    i++;
  }
  printf("stack top %.2f\n",dstack[top]);
  printf("stack %.2f",dstack[top]);
  res = (double)(dstack[top--]-'0');


  return res;
}

int isEmpty() {


  return 0;
}
int priority(char x) {
  switch (x) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    default:
      return 0;
  }
  
}