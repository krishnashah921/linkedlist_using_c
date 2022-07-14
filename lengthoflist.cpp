#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
void lengthoflist(struct node **start);
void create(struct node **start,int data);
void display(struct node **start);
int main()
{
	struct node *start=NULL;
	int data,ch=1,choice;
	while(ch==1)
	{
		printf("1.exit\n2.Create\n3.Display\n4.Length of list\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					ch=0;
					break;
				}
			case 2:
				{
					printf("Enter the data\n");
					scanf("%d",&data);
					create(&start,data);
					break;
				}
			case 3:
				{
					display(&start);
					printf("\n");
					break;
				}
			case 4:
				{
					lengthoflist(&start);
					break;
				}
			default:
				{
					printf("Invalid choice\n");
					break;
				}
		}
	}
}
void create(struct node **start,int data)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	struct node *temp=*start;
	newnode->data=data;
	newnode->next=NULL;
	if (*start==NULL)
	{
		*start=newnode;
	}
	else 
	{
		while (temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void display(struct node **start)
{
	struct node *temp=*start;
	while (temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
void lengthoflist(struct node **start)
{
	struct node *temp=*start;
	int count=0;
	while (temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	printf("%d\n",count);
}
