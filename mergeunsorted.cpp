//merge two sorted  linkedlist
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
void merge(struct node **start1,struct node **start2,struct node **start3);
int main()
{
	struct node *start1=NULL,*start2=NULL,*start3=NULL;
	int data,ch=1,choice;
	while(ch==1)
	{
		printf("1.Create for linked list first\n2.Create for linked list second\n3.Display\n4.Length of list\n5.exit\n6.Merge two linked list\n");
		scanf("%d",&choice);
		switch(choice)
		{
			
			case 1:
				{
					printf("Enter the data\n");
					scanf("%d",&data);
					create(&start1,data);
					break;
				}
				case 2:
				{
					printf("Enter the data\n");
					scanf("%d",&data);
					create(&start2,data);
					break;
				}
			case 3:
				{
					printf("do you want to display first or second linked list\n");
					scanf("%d",&data);
					if (data==1)
					display(&start1);
					else 
					display(&start2);
					printf("\n");
					break;
				}
			case 4:
				{
					//lengthoflist(&start);
					break;
				}
			case 5:
				{
					ch=0;
					break;
				}
				case 6:
					{
						merge(&start1,&start2,&start3);
						display(&start3);
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
void merge(struct node **start1,struct node **start2,struct node **start3)
{
	struct node *tmp1=*start1,*tmp2=*start2;
while (tmp1 !=NULL && tmp2 !=NULL)
	{
		if ((tmp1->data) > (tmp2->data))
		{
			create(start3,tmp1->data);
			tmp1=tmp1->next;
		}
		else if ((tmp2->data) > (tmp1->data))
		{
			create(start3,tmp2->data);
			tmp2=tmp2->next;
		}
		else 
		{
			create(start3,tmp1->data);
			tmp1=tmp1->next;
			tmp2=tmp2->next;
		}
	}
	while (tmp1 !=NULL)
	{
		create(start3,tmp1->data);
		tmp1=tmp1->next;
	}
	while (tmp2 !=NULL)
	{
		create(start3,tmp2->data);
		tmp2=tmp2->next;
	}
}
