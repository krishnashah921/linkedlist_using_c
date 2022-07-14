//get nth node from last of the linked list
//input:-1-2-3-4-5-N
//input nth node=2 then output =4 ,,,if input nth node =4 then output=2
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
void getnthnode(struct node **start,int num);
int main()
{
	struct node *start=NULL;
	int data,ch=1,choice,num;
	while(ch==1)
	{
		printf("1.exit\n2.Create\n3.Display\n4.Length of list\n5.Get nth node\n");
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
			case 5:
				{
					printf("enter the nth node\n");
					scanf("%d",&num);
					 getnthnode(&start,num);
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
void getnthnode(struct node **start,int num)
{
	struct node *ptr,*temp=*start;
	ptr=*start;
	int count=1;
	while (temp!=NULL && count<=num-1)
	{
		count=count+1;
		temp=temp->next;
	}
	while (temp->next!=NULL)
	{
		ptr=ptr->next;
		temp=temp->next;
	}
	printf("%d\n",ptr->data);
}
