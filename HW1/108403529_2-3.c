#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACKSIZE 100
//stack
char stack[STACKSIZE];
int topOfStack = -1;
//output stack
char output[100];
int topOfOutput = -1;
//cal stack
char calStack[100];
int topCalStack = -1;

void toPostfix(char input[]);    // change string to postfix
void calPostfix(char postfix[]); // calculate postfix

void push(char token, char st[], int top);
void pushNum(char number, char st[], int top);
int priority(char token); // token priority

int main()
{ //((8*6)+(9/(7+2)))
    int res;
    char input[100] = {'\0'};

    gets(input); //get input line
    // generate posfix
    toPostfix(input);
    calPostfix(output);
    // topOfStack = -1;
    // topOfOutput = -1;
    // topCalStack = -1;
    return 0;
}

void toPostfix(char input[])
{
    int i, lparen = 0;
    char token, x;
    for (i = 0; i < strlen(input); i++)
    {
        token = input[i];

        if (isalnum(token))
        {
            push(token, output, topOfOutput);
            topOfOutput++;
        }
        else if (token == '(')
        {
            push(token, stack, topOfStack);
            topOfStack++;
            lparen++;
        }
        else if (token == ')')
        {
            lparen--;

            while (stack[topOfStack] != '(')
            {
                push(stack[topOfStack], output, topOfOutput);
                topOfOutput++;
                topOfStack--;
            }
            topOfStack--;
        }
        else
        {
            while (priority(stack[topOfStack] > priority(token)))
            {
                push(stack[topOfStack--], output, topOfOutput);
                topOfOutput++;
            }
            push(token, stack, topOfStack);
            topOfStack++;
        }
    }
    // 剩下的印出
    while (topOfStack != -1)
    {
        push(stack[topOfStack--], output, topOfOutput);
        topOfOutput++;
    }

    if (lparen != 0) {
      exit(0);
    } else {
        printf("> ");
        for (int i = 0; i <= topOfOutput; i++)
        {
          
          if (i == topOfOutput) {
            printf("%c", output[i]);
          } else {
            printf("%c ", output[i]);
          }
        }
        printf("\n");
    }
}

void calPostfix(char postfix[])
{
    float tmp, res, o1, o2;
    char token;

    for (int i = 0; i < strlen(postfix); i++)
    {
        token = postfix[i];

        if (isalnum(token))
        {
            tmp = token - '0';

            pushNum(tmp, calStack, topCalStack);
            topCalStack++;
        }
        else
        {

            o1 = calStack[topCalStack--];
            o2 = calStack[topCalStack--];

            if (token == '+')
            {
                res = o2 + o1;

                pushNum(res, calStack, topCalStack);
                topCalStack++;
            }
            else if (token == '-')
            {
                res = o2 - o1;

                pushNum(res, calStack, topCalStack);
                topCalStack++;
            }
            else if (token == '*')
            {
                res = o2 * o1;
                pushNum(res, calStack, topCalStack);
                topCalStack++;
            }
            else if (token == '/')
            {
                res = o2 / o1;
                pushNum(res, calStack, topCalStack);
                topCalStack++;
            }
        }
    }
    printf("> %d\n", (int)round(calStack[topCalStack--]));
}
//priority
int priority(char token)
{
    if (token == '*' || token == '/')
    {
        return 2;
    }
    else if (token == '+' || token == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// push token to stack
void push(char token, char st[], int top)
{
    top++;
    st[top] = token;
}
// push token to numstack
void pushNum(char number, char st[], int top)
{
    top++;
    st[top] = number;
}