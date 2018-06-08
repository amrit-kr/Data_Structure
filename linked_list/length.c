#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
struct list{
	int data;
	struct list * next;
};
void appendNode(int val,struct list* head)
{
	struct list * temp = (struct list *)malloc(sizeof(struct list));
	temp->data= val;
	while(head->next!= NULL)
	{
		head=head->next;
	}
	head->next=temp;
	temp->next= NULL;
}
int length_itr(struct list * head)
{
	int count = 0;
	while(head!= NULL)
	{
		count++;
		head=head->next;
	}
	return count;
}
int length_recr(struct list * head)
{
	int count = 0;
	if(head == NULL)
	return 0;
	else
	return 1 + length_recr(head->next);
}
void print(struct list * head)
{
	while(head!= NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}
int main()
{
	struct list * head = (struct list *)malloc(sizeof(struct list));
	head->data = 1;
	head->next = NULL;
	appendNode(2,head);
	appendNode(3,head);
	appendNode(4,head);
	appendNode(5,head);
	appendNode(6,head);
	appendNode(7,head);
	appendNode(8,head);
	appendNode(9,head);

	print(head);

	int count1 = length_itr(head);
	int count2 = length_recr(head);

	printf("Length of Linked list from iterative method : %d\n",count1);
	printf("Length of Linked list from recursive method : %d",count2);
	return 0;
}
