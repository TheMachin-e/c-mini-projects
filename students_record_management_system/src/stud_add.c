#include<stdio.h>
#include<stdlib.h>
#include "student.h"
void add_new(student **head){
	student *node  = *head;
	student *new = calloc(1, sizeof(student));
	if(!new){
		printf("\033[31mCalloc failed\033[0m\n");
		return;
	}
	char op;
	printf("Student name: "	);
	scanf(" %49[^\n]", new->name);
	while(!is_name_valid(new->name)){
		printf("q/Q : Quit without adding new student\n");
		printf("c/C : Try again\n");
		scanf(" %c", &op);
		op |= 32;
		switch(op){
			case 'q':
				free(new);
				return;
			case 'c':
				printf("Student name: "	);
				scanf("%49[^\n]", new->name); 
				break;
			default:printf("\033[31mInvalid input\033[0m\n");
		}
	}
	printf("Student percentage: ");
	scanf("%f", &new->percentage);
	while(!is_percentage_valid(new->percentage)){
		printf("b/B : Go back without adding new student\n");
		printf("c/C : Try again\n");
		scanf(" %c", &op);
		op |= 32;
		switch(op){
			case 'b':
				free(new);
				return;
			case 'c':
				printf("Student percentage: ");
				scanf("%f", &new->percentage);
				 break;
			default:printf("\033[31mInvalid input\033[0m\n");
		}
	}
	new->rollno = get_rollno(*head);
	if(!node){
		*head = new;
		return;
	}
	while(node->next)
		node = node->next;
	node->next = new;
}

int is_name_valid(char *name){
	char ch = name[0] | 32;
	if(ch < 'a'|| ch > 'z'){
		printf("\033[31mInvalid name\033[0m\n");
		return 0;
	}
	return 1;
}

int is_percentage_valid(float percentage){
	if(percentage >= 0 && percentage <= 100)
		return 1;
	printf("\033[31mInvalid mark percentage!!\n\033[0m");
	return 0;
}

int get_rollno(student *head){
	int num = 1;
	while(1){
		student *node = head;
		while(node){
			if(node->rollno == num)
				break;
			node =  node->next;	
		}
		if(!node)
			return num;

		num++;
	}
}

