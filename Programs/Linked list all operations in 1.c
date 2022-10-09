#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head;
void insert(){
	struct node *ptr,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data you want to insert:\n");
	scanf("%d",&temp->data);
	printf("You inserted:%d\n",temp->data);
	temp->next=NULL;
	if(head==NULL){
		head=temp;
	}
	else{
	ptr=head;
	while(ptr->next != NULL){
		ptr=ptr->next;
	}
	ptr->next=temp;
}
}
void display(){
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
		if(head==NULL){
		printf("Empty linklist.");
	}
	ptr=head;
	while(ptr !=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
void del(){
	if(head==NULL){
		printf("Blank linked list.");
	}
	else if(head->next==NULL){
		free(head);
		head=NULL;
	}
	else{
		struct node *temp, *ptr;
		ptr=head;
		while(ptr->next !=NULL){
			temp=ptr;
			ptr=ptr->next;
		}
		free(ptr);
		ptr=NULL;
		temp->next=NULL;
	}
}
void insert_from_begining(){
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("Enter data you wanna add:\n");
	scanf("%d",&ptr->data);
	printf("You inserted:%d\n",ptr->data);
	ptr->next=NULL;
	ptr->next=head;
	head=ptr;
	while(ptr->next !=NULL){
			ptr=ptr->next;
		}
	
}

int main(){
	int n;
	while(1){
		printf("\n1.INSERT\n");
		printf("\n2.Dislay\n");
		printf("\n3.Delete\n");
		printf("\n3.Insert from front:\n");
		printf("\nChoose option:\n");
		scanf("%d",&n);
		switch(n){
		
		case 1:insert();
		break;
		case 2:display();
		break;
		case 3:del();
		break;
		case 4:insert_from_begining();
		break;


}
}
}

