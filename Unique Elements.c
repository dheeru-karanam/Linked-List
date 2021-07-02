/*

Removes duplicates elements from the Linked list (sorted or Unsorted) 
Time Complexity : O(n^2)

*/
#include "stdio.h"
#include "stdlib.h"


//Structure Node 
struct Node{
	int data;
	struct Node *next;
}*head=NULL;

//Function to Insert data into Linked List

void Insert(int data){
	struct Node * p, *ptr;
	p = (struct Node *)malloc(sizeof(struct Node));
	ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr = head;
	p->data = data;
	p->next = NULL;
	if(head==NULL){
		head = p;
		return;
	}
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = p;
	return;
}

//Function to Display data in Linked List

void Display(){
	struct Node * ptr;
	ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr = head;
	while(ptr){
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	
}

//Function to remove duplicate elements in Linked List

void Remove_Duplicates(){
	int dup;
	struct Node *ptr, *qtr, *marker;
	ptr = (struct Node *)malloc(sizeof(struct Node));
	qtr = (struct Node *)malloc(sizeof(struct Node));
	marker = (struct Node *)malloc(sizeof(struct Node));
	ptr = qtr = marker = head;
	dup = ptr->data;
	ptr = ptr->next;
	marker = marker->next;
	while(marker != NULL){
		while(qtr->next!= NULL){
			if(ptr->data==dup){
				ptr = ptr->next;
				qtr->next = ptr;
			}
			else{
				ptr = ptr->next;
				qtr = qtr->next;
			}
		}
		qtr = ptr = marker;
		ptr = ptr->next;
		dup = marker->data;
		marker = marker->next;
	}
	
}


//Main Function

int main(){
	
	int a[]={1,3,2,1,2,5,4,1,3,12,11,10},size = 12;
	int i=0,j,k,data;
	for(i=0;i<size;i++){
		Insert(a[i]);
	}
	printf("Elements in Linked List:  ");
	Display();
	Remove_Duplicates();
	printf("\n");
	printf("Elements in Linked List after removing Duplicates:  ");
	display();
	return 0;
}