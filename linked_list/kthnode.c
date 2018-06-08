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
struct node * kthnodestart(struct node * head, int k)       // kth node from start
{
    if(k<=0)
        return NULL;
    if(k==1)
        return head;
    for(int i=1;i<k;i++)
    {
        if(head->next)
        {
            head=head->next;
        }
        else
            return NULL;
    }
    return head;
}
struct node * kthnodeend(struct node * head, int k)        // kth node from end
{
    struct node * temp = head;
    for(int i=1;i<k;i++)
    {
        if(temp->next)
        {
            temp = temp->next;
        }
        else
            return NULL;
    }
    while(temp->next)
    {
        temp = temp->next;
        head = head->next;
    }
    return head;
};
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
    struct node * temp = kthnodestart(head,4);
    printf("kth node from start : %d\n",temp->data);
    temp = kthnodeend(head,3);
    printf("kth node from end : %d\n",temp->data);
    return 0;
}
