#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// maximum of STACKSIZE
#define STACKSIZE 101

//stack to store numbers
char stack[STACKSIZE];
int topOfStack = -1;

//stack to store output of toPostfix
char output[STACKSIZE];
int topOfOutput = -1;

//stack to store calStack's number
float calStack[STACKSIZE];
int topCalStack = -1;

int toPostfix(char input[]);                     // function of infix to postfix
void calPostfix(char postfix[]);                 // function of calculate the result of postfix
void push(char token, char st[], int top);       //push numbers to stack
void pushNum(float number, float st[], int top); //push numbers to calStack
int priority(char token);                        // return token priority

int main()
{
    char input[101] = {'\0'}; //init input char array
    gets(input);              //gets input to char input[]

    if (toPostfix(input))   //if toPostfix success () pair
        calPostfix(output); // then call calPostfix function
    else
        exit(0);
    // init pointer of each stack
    topOfStack = -1;
    topOfOutput = -1;
    topCalStack = -1;
    return 0;
}

int toPostfix(char input[])
{
    int lparen = 0; // if meet '(' then lparen++ else lparen--
    char token;     // get the first character of input

    for (int i = 0; i < strlen(input); i++)
    {
        token = input[i];

        // if token(the first character) == numbers(0~9)
        if (isalnum(token))
        {
            push(token, output, topOfOutput); //push numbers(1~9) to stack through push function
            topOfOutput++;
        }
        //if token(the first character) == '('
        else if (token == '(')
        {
            push(token, stack, topOfStack); //push '(' to stack through push function
            topOfStack++;
            lparen++; //lparen += 1
        }
        //if token(the first character) == ')'
        else if (token == ')')
        {
            lparen--; //lparen -= 1

            while (stack[topOfStack] != '(') //if in stack, still not meet '('
            {
                push(stack[topOfStack], output, topOfOutput); //then keep push to output
                stack[topOfStack] = '\0';
                topOfOutput++;
                topOfStack--;
            }
            stack[topOfStack] = '\0';
            topOfStack--;
        }
        // left operators('+','-','*','/')
        else
        {

            while (priority(stack[topOfStack]) >= priority(token)) //if in stack operator('+','-','*','/')> input operator
            {
                push(stack[topOfStack], output, topOfOutput); // push to ouput array
                stack[topOfStack] = '\0';
                topOfStack--;
                topOfOutput++;
            }
            push(token, stack, topOfStack);
            topOfStack++;
        }
    }

    // if input array are empty, and stack not empty
    while (topOfStack != -1)
    {
        push(stack[topOfStack--], output, topOfOutput); //push to output array
        topOfOutput++;
    }
    // if () is not pair
    if (lparen != 0)

        return 0;
    else
    {
        //   print output result
        printf("> ");
        for (int i = 0; i <= topOfOutput; i++)
        {
            if (i != topOfOutput)
                printf("%c ", output[i]);
            else
                printf("%c", output[i]);
        }
        printf("\n");
        return 1;
    }
}

// calculate postfix to round number
void calPostfix(char postfix[])
{
    float tmp, res, o1, o2;
    char token;

    for (int i = 0; i < strlen(postfix); i++)
    {
        token = postfix[i];

        if (isalnum(token))
        {
            tmp = token - '0'; //change date type to int

            pushNum(tmp, calStack, topCalStack); //push tmp(int) to calStack
            topCalStack++;
        }
        else
        {
            o1 = calStack[topCalStack--]; //get the first top number of calStack
            o2 = calStack[topCalStack--]; //get the second top number of calStack
            // if postfix array meet '+'
            if (token == '+')
            {
                res = o2 + o1;

                pushNum(res, calStack, topCalStack); //push result to calStack
                topCalStack++;
            }
            // if postfix array meet '-'
            else if (token == '-')
            {
                res = o2 - o1;

                pushNum(res, calStack, topCalStack); //push result to calStack
                topCalStack++;
            }
            // if postfix array meet '*'
            else if (token == '*')
            {
                res = o2 * o1;

                pushNum(res, calStack, topCalStack); //push result to calStack
                topCalStack++;
            }
            // if postfix array meet '/'
            else if (token == '/')
            {
                res = o2 / o1;

                pushNum(res, calStack, topCalStack); //push result to calStack
                topCalStack++;
            }
        }
    }
    printf("> %d\n", (int)round(calStack[topCalStack--])); //print result
}
//operators priority
int priority(char token)
{
    if (token == '*' || token == '/')
        return 2;
    else if (token == '+' || token == '-')
        return 1;
    else
        return 0;
}
// push token to stack
void push(char token, char st[], int top)
{

    st[++top] = token;
}
// push token to calStack
void pushNum(float number, float st[], int top)
{
    st[++top] = number;
}