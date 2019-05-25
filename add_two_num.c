#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int key;
	struct node *next;
}Node;

typedef struct{
	Node *head,*tail;
}List;

// Creates new list
List *list(){
	List* p = (List*)malloc(sizeof(List));
	p->head = p->tail = NULL;
	return p;
}

// Creates new node
Node *node(int key){
	Node *p = (Node*)malloc(sizeof(Node));
	p->key = key;
	p->next = NULL;
	return p;
}

// Pushes new node unto list
void push(List *ulist, int key){
	if(ulist->head == NULL){
		ulist->head = ulist->tail = node(key);
		return;
	}
	Node *p = node(key);
	p->next = ulist->head;
	ulist->head = p;

}

// Reverse linked list
void reverseList(List *ulist){
	Node *curr=ulist->head, *prev=NULL;
	Node *next = curr->next;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	ulist->head = prev;
}

// Adds two list
List *sum(List* ulist1, List *ulist2){
	Node *p,*q = ulist2->head;
	List *sum = list();
	int addition = 0;
	for(p = ulist1->head; p != NULL; p = p->next){
		addition = p->key + q->key;
		if( addition >= 10 && q->next != NULL){
			addition = addition%10;
			q->next->key += 1;
		}
		push(sum,addition);
		q = q->next;
	}
	return sum;
}

// Prints list
void print(List* ulist){
	Node *p;
	for(p = ulist->head; p != NULL; p = p->next){
		printf("%d ",p->key);
	}
	printf("\n");
}

void main(){
	List *temp = list();
	List *temp1 = list();
	if(temp){
		printf("List was successfully created.\n");
		push(temp,2);
		push(temp,4);
		push(temp,3);
		push(temp1,5);
		push(temp1,6);
		push(temp1,4);
		print(temp);
		print(temp1);
		reverseList(temp);
		reverseList(temp1);
		print(temp);
		print(temp1);
		List *add = sum(temp,temp1);
		print(add);
	}
	else{
		printf("List was not created.\n");
	}
}
