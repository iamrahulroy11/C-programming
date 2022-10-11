
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
typedef struct node{
	int data;
	struct node *prev;
	struct node *next;
}node;
node *start=NULL,*tail=NULL;
void insertfront();
void insertend();
void insertpos();
void display();
void deletend();
void deletfront();
void deletpos();
void linear_search();
//display funcs//
void last_to_first();
void first_to_last();
//
void linear_search();
int main()
{
	int ch;
	time_t now =time(NULL);
	char *str=ctime(&now);
	printf("\t\t\tDOUBLY LINKED LIST\t\t\t\n");
	printf("\nGMT +5.30hrs\n");
	printf("%s\n",str);
	while(1)
	{
		printf("\n1.Insert front\n");
		printf("\n2.Insert End\n");
		printf("\n3.Insert at position\n");
		printf("\n4.Display\n");
		printf("\n5.Delete end\n");
		printf("\n6.Delete front\n");
		printf("\n7.Delete any position\n");
		printf("\n8.Linear Search\n");
		printf("\n9.Exit code\n");
		printf("\nEnter any option:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insertfront();
				break;
			case 2:
				insertend();
				break;
			case 3:
				insertpos();
				break;
			case 4:
				display();
				break;
			case 5:
				deletend();
				break;
			case 6:
				deletfront();
				break;
			case 7:
				deletpos();
				break;
			case 8:
				linear_search();
				break;
			case 9:
				sleep(1);
				printf("\nExititng the code:\n");
				exit(0);
			default:
				printf("\nWrong option\n");
				sleep(2);
				break;
				
		}
	}
	return 0;
}
void insertfront()
{
	node *ptr,*temp;
	ptr=(node *)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("\nMemory allocation failure\n");
		exit(0);	
	}	
	printf("\nEnter the data for node:\n");
	scanf("%d",&ptr->data);
	ptr->next=NULL;
	ptr->prev=NULL;
	if(tail==NULL)
	{
		tail=ptr;	
	}
	if(start==NULL)
	{
		start=ptr;
	}
	else
	{
		temp=start;
		while(temp->prev!=NULL)
		{
			temp=temp->prev;
		}
		ptr->next=temp;
		temp->prev=ptr;
		start=ptr;
	}
}
void insertend()
{
	node *ptr,*temp;
	ptr=(node *)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("\nMemory allocation failure\n");
		exit(0);	
	}	
	printf("\nEnter the data for node:\n");
	scanf("%d",&ptr->data);
	ptr->next=NULL;
	ptr->prev=NULL;
	if(tail==NULL)
	{
		tail=ptr;
	}
	if(start==NULL)
	{
		start=ptr;
	}
	else
	{
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->prev=temp;
		tail=ptr;
	}
}
void display()
{
	if(start==NULL)
	{
		int x;
		printf("\nNo elements in the list\n");
		printf("\n1.Insert front\n");
		printf("\n2.Insert end\n");
		printf("\nEnter your choice:\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				insertfront();
				break;
			case 2:
				insertend();
				break;
			default:
				printf("Wrong option, exiting code\n");
				exit(0);
		}
	}
	else
	{
		int ch;
		printf("\t\n1.Traverse from first to last.\n");
		printf("\t\n2.Traverse from last to first.\n");
		printf("\t\nEnter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				first_to_last();
				break;
			case 2:
				last_to_first();
				break;
			default:
				printf("Wrong option taken\n");
				break;
		}
	}
}
void last_to_first()
{
	node *ptr;
	ptr=tail;
	printf("\nTAIL-->%d",ptr->data);
	printf("\nList of elements are:\n");
	while(ptr->prev!=NULL)
	{
	 	printf("%d\n",ptr->data);
	 	ptr=ptr->prev;
	}
	printf("%d\n",ptr->data);
}
void first_to_last()
{
	node *ptr;
	ptr=start;
	printf("\nSTART-->%d",ptr->data);
	printf("\nList of elements are:\n");
	while(ptr->next!=NULL)
	{
	    printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
	printf("%d\n",ptr->data);
}
void linear_search()
{
	node *ptr;
	if(start==NULL)
	{
		int x;
		printf("\nNo elements in the list\n");
		printf("\n1.Insert front\n");
		printf("\n2.Insert end\n");
		printf("\nEnter your choice:\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				insertfront();
				break;
			case 2:
				insertend();
				break;
			default:
				printf("Wrong option, exiting code\n");
				exit(0);
		}
	}
	int data,flag=0;
	printf("\nEnter the data you want to look for:\n");
	scanf("%d",&data);
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->data==data)
		{
			flag++;
		}
		ptr=ptr->next;
	}
	if(flag==1)
	{
		printf("\nData was found in the list\n");	
	}
	else if(flag>1)
	{
		printf("\nData was found more than once in the list\n");
	}
	else
	{
		printf("\nData was not found in the list\n");
	 }
}
void insertpos()
{
	node *ptr,*temp;
	int pos;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter the position you want to insert in:\n");
	scanf("%d",&pos);
	node *traverse=start;
	int num=0;
	while(traverse!=NULL)
	{
		num++;
		traverse=traverse->next;
	}
	if(pos>num)
	{
		printf("\nOperation not allowed\n");
		return;
	}
	if(pos==0||pos==1)
	{
		insertfront();
	}
	else if(pos==num)
	{
		insertend();
	}
	else
	{
		printf("\nEnter the data you want to insert:\n");
		scanf("%d",&temp->data);
		temp->next=NULL;
		temp->prev=NULL;
		ptr=start;
		int i;
	for( i=2;i<=pos-1;i++)
		{
			ptr=ptr->next;
		}
		temp->next=ptr->next;
		ptr->next->prev=temp;
		ptr->next=temp;
		temp->prev=ptr;		
	}
}
void deletend()
{
	if(start==NULL)
	{
		int x;
		printf("\nNo elements in the list\n");
		printf("\n1.Insert front\n");
		printf("\n2.Insert end\n");
		printf("\nEnter your choice:\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				insertfront();
				break;
			case 2:
				insertend();
				break;
			default:
				printf("Wrong option, exiting code\n");
				exit(0);
		}
	}
	else
	{
		node *ptr;
		ptr=tail;
		tail=tail->prev;
		tail->next=NULL;//tail ko ek peeche bheje and uske next me NULL//
		free(ptr);
		printf("\nNode deleted\n");
	}
}
void deletfront()
{
	if(start==NULL)
	{
		int x;
		printf("\nNo elements in the list\n");
		printf("\n1.Insert front\n");
		printf("\n2.Insert end\n");
		printf("\nEnter your choice:\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				insertfront();
				break;
			case 2:
				insertend();
				break;
			default:
				printf("Wrong option, exiting code\n");
				exit(0);
		}
	}
	else
	{
		node *ptr;
		ptr=start;
		start=start->next; //strt ek aage and uske nxt me NULL//
		start->prev=NULL;
		free(ptr);
		printf("\nNode deleted\n");
	}	
}
void deletpos()
{
	if(start==NULL)
	{
		int x;
		printf("\nNo elements in the list\n");
		printf("\n1.Insert front\n");
		printf("\n2.Insert end\n");
		printf("\nEnter your choice:\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				insertfront();
				break;
			case 2:
				insertend();
				break;
			default:
				printf("Wrong option, exiting code\n");
				exit(0);
		}
	}
	else
	{
		int place,count=0;
		node *ptr,*ptr2,*temp;
		printf("\nEnter the place you want to delete: \n");
		scanf("%d",&place);
		if(place==1||place==0)
		{
			deletfront();
		}
		else
		{
			ptr=start;
			while(ptr!=NULL)
			{
				count++;
				ptr=ptr->next;
			}
			if(place==count)
			{
				deletend();
			}
			else
			{
				ptr2=start;
				int i;
				for( i=1;i<place-1;i++)
				{
					ptr2=ptr2->next;
				}
				temp=ptr2->next;
				ptr2->next=ptr2->next->next;
				ptr2->next->prev=ptr2;
				free(temp);
				printf("\nNode Deleted\n");
			}
		}
	}
	printf("\nNode deleted\n");
	printf("\nUpdated list is:\n");
	display();
}
