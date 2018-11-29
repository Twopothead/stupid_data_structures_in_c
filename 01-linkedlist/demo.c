#include <stdio.h>
#include <stdlib.h>
struct node *head,*z;
struct node{
	int key;
	struct node *next;
};

void list_initialize(){
	head = (struct node *) malloc(sizeof *head);
	z = (struct node *) malloc(sizeof *z);
	head->next = z;
	z->next = z;
}

void delete_next(struct node *t){
	t->next = t->next->next;
}

struct node *insert_after(int v,struct node *t){
	struct node *x;
	x = (struct node *) malloc (sizeof *x);
	x->key = v;
	t->next = x;
	return x; 
}

int main(){
	list_initialize();
	insert_after(2,insert_after(1,head));
	printf("%d",head->next->key);printf("%d",head->next->next->key);
	return 0;
}