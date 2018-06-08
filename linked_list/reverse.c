#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node * next;
};

void append(int data, struct node * head)
{
    if(!head)
    {
       head = (struct node *)malloc(sizeof(struct node));
       head->data = data;
       head->next = NULL;
       return;
    }
    while(head->next)
    {
        head = head->next;
    }
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    head->next = temp;
    temp->data = data;
    temp->next = NULL;
}
void print_list(struct node * head)
{
    while(head!= NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}
void reverse(struct node ** head)       // iterator method.
{
    struct node * current = *head;
    struct node * prev = NULL;
    struct node * next;
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
int main()
{
    struct node * head = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;
    append(2,head);
    append(3,head);
    append(4,head);
    append(5,head);
    append(6,head);
    append(7,head);
    append(8,head);
    append(9,head);
    append(10,head);
    print_list(head);
    reverse(&head);
    printf("After reverse list : ");
    print_list(head);
    return 0;
}
