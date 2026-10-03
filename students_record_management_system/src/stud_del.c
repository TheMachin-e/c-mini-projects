#include<stdio.h>
#include "student.h"
#include<stdlib.h>
#include<string.h>
void delete_all(student **head){
	if(!*head){
		printf("\033[031Record is empty\033[0m\n");
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
		printf("\033[031Record is empty\033[0m\n");
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
	printf("\033[31mNo record with this roll number\033[0m\n");
}

void delete_record_name(student **head, char *name){
	if(!*head){
		printf("\033[031Record is empty\033[0m\n");
		return;
	}
	student *node = *head, *prev;
	int f = 0, rollno;
	while(node){
		if(strcmp(node->name, name) == 0){
			if(!f){
				printf("┌───────────────┬───────────────────────────────────┬───────────────┐\n");
				printf("│ %-13s │ %-33s │ %-13s │\n", "Roll Number", "Name", "Percentage");
				printf("├───────────────┼───────────────────────────────────┼───────────────┤\n");
			}
			f = 1;
			printf("│ %-13d │ %-33s │ %-13.2f │\n", node->rollno, node->name, node->percentage);
		}
		node = node->next;
	}
	if(f){
		printf("└───────────────┴───────────────────────────────────┴───────────────┘\n");
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
		printf("\033[31mInvalid roll number\033[0m\n");
	}
	else
		printf("\033[031No matching name in record\033[0m\n");
}
