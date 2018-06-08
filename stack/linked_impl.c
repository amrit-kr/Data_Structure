#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
   int data;
   struct node * next;
};
void push(struct node ** top,int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *top;
    *top = temp;
}
bool isempty(struct node * top)
{
    if(top == NULL)
    {
        return true;
    }
    else
        return false;
}
int pop(struct node ** top)
{
    if(isempty(*top))
    {
        printf("stack empty\n");
        return -100;
    }
    else
    {
        int data = (*top)->data;
        *top = (*top)->next;
        return data;
    }
}
int main()
{
    struct node * top = NULL;
    push(&top,10);
    push(&top,20);
    push(&top,30);
    push(&top,40);
    push(&top,50);
    push(&top,60);
    push(&top,70);
    printf("Element which is popped : %d",pop(&top));
    return 0;
}
