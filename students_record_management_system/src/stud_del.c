#include<stdio.h>
#include "student.h"
#include<stdlib.h>
void delete_all(student **head){
	if(!*head){
		printf("NO records to delete\n");
		return;
	}
	student *node = *head;
	while(node){
		*head = node->next;
		free(node);
		node = *head; 
	}
	printf("All records deleted\n");
}
