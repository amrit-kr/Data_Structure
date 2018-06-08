//  Implementation of stack with array.
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define max 99
int ar[100];
int top = -1;
bool isempty()
{
    if(top==-1)
        return true;
    else
        return false;
}
bool isfull()
{
    if(top==max)
        return true;
    else
        return false;
}
void push(int data)
{
    if(isfull())
    {
        printf("overflow condition\n");
        return;
    }
    else{
        top++;
        ar[top]=data;
    }
}
int pop()
{
    if(isempty())
    {
        printf("underflow condition\n");
    }
    else{
        top--;
        return ar[top+1];
    }
}
int main()
{
    push(100);
    push(200);
    push(300);
    push(400);
    push(500);
    push(600);
    push(700);
    push(800);
    push(900);
    int temp = pop();
    printf("data which is popped from stack : %d\n",temp);
    return 0;
}
