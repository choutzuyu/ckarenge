#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}node;

node* createnode(int x){
	node* temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = NULL;
	return temp;
}

void add(node** head_ref, int x){
	node* new = createnode(x);
	node* temp = *head_ref;
	if(*head_ref==NULL){
		*head_ref = new;
		return;
	}

	while(temp->next != NULL){
		temp=temp->next;
	}
	temp->next=new;
}

void print(node* head){
	int i=1;
	node* temp = head;
	while(temp!=NULL){
		printf("\nTCP Port Number %d: %d",i,temp->data);
		i++;
		temp=temp->next;
	}
}

int main()
{
	node* head = NULL;
	FILE* fo = fopen("portnumber.txt","r");
	if(fo==NULL)
	{
		printf("\n NA challe thaari filee");
		exit(1);
	}
	int data = 0;
	while((fscanf(fo,"%d\n",&data)==1))
	{
		add(&head,data);
	}
	print(head);
	puts("");
}