#include<stdio.h>
#include "student.h"
#include<stdlib.h>
#include<string.h>
void delete_all(student **head){
	if(!*head){
		printf("No records to delete\n");
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

void delete_record_rollno(student **head, int rollno){
	if(!*head){
		printf("Not reord yet\n");
		return;
	}
	student *node = *head, *prev = NULL;
	while(node){
		if(node->rollno == rollno){
			if(node == *head)
				*head = node->next;
			else
				prev->next = node->next;
			free(node);
			printf("Deleted record having rollno %d\n", rollno);
			return;
		}
		prev = node;
		node = node->next;	
	}
	printf("No record with this roll number\n");
}

void delete_record_name(student **head, char *name){
	if(!*head){
		printf("No records to delete\n");
		return;
	}
	student *node = *head, *prev;
	int f = 0, rollno;
	while(node){
		if(strcmp(node->name, name) == 0){
			if(!f)
				printf("┌──────────┬─────────────────────────┬──────────┐\n");
			f = 1;
			printf("│ %-8d │ %-23s │ %-8.2f │\n", node->rollno, node->name, node->percentage);
		}
		node = node->next;
	}
	if(f){
		printf("└──────────┴─────────────────────────┴──────────┘\n");
		printf("\nEnter roll number to delete that record: ");
		scanf("%d", &rollno);
		node = *head;
		while(node){
			if(node->rollno == rollno && (strcmp(node->name, name) == 0)){
				if(node == *head)
					*head = node->next;
				else
					prev->next = node->next;
				free(node);
				printf("Deleted record having rollno %d\n", rollno);
				return;		
			}
			prev = node;
			node = node->next;
		}
		printf("Invalid roll number\n");
	}
	else
		printf("No matching name in record\n");
}
