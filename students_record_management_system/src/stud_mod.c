#include<stdio.h>
#include<string.h>
#include"student.h"

void edit_record_rollno(student *node, int rollno){
	if(!node){
		printf("\033[31mRecord is empty\033[0m\n");
		return;
	}
	char name[50];
	float percentage;
	while(node){
		if(node->rollno == rollno){
			printf("┌───────────────┬───────────────────────────────────┬───────────────┐\n");
			printf("│ %-13s │ %-33s │ %-13s │\n", "Roll Number", "Name", "Percentage");
			printf("├───────────────┼───────────────────────────────────┼───────────────┤\n");
			printf("│ %-13d │ %-33s │ %-13.2f │\n", node->rollno, node->name, node->percentage);
			printf("└───────────────┴───────────────────────────────────┴───────────────┘\n");
			printf("Edit name: ");
			scanf(" %49[^\n]",name);
			while(!is_name_valid(name)){
				printf("Edit name: ");
				scanf(" %49[^\n]",name);
			}
			strcpy(node->name, name);
			printf("Name edited successfully\n");
			printf("Edit percentage: ");
			scanf("%f", &percentage);
			while(!is_percentage_valid(percentage)){
				printf("Edit percentage: ");
				scanf("%f", &percentage);
			}
			node->percentage = percentage;
			printf("Percentage edited successfully\n");
			return;
		}
		node = node->next;
	}
	printf("\033[31mNo record with matching rollno\033[0m\n");
}

void edit_record_name(student *head, char *name){
	if(!head){
		printf("\033[31mRecord is empty\033[0m\n");
		return;
	}
	student *node = head, *tmp;
	int rollno;
	char new_name[50];
	float percentage;
	int f = 0;
	while(node){
		if(strcmp(name, node->name) == 0){
			if(!f){
				printf("┌───────────────┬───────────────────────────────────┬───────────────┐\n");
				printf("│ %-13s │ %-33s │ %-13s │\n", "Roll Number", "Name", "Percentage");
				printf("├───────────────┼───────────────────────────────────┼───────────────┤\n");
				tmp = node;
			}
			printf("│ %-13d │ %-33s │ %-13.2f │\n", node->rollno, node->name, node->percentage);
			f++;
		}
		node = node->next;	
	}
	if(f == 1){
		printf("└───────────────┴───────────────────────────────────┴───────────────┘\n");
		printf("Edit name: ");
		scanf(" %49[^\n]", new_name);
		while(!is_name_valid(new_name)){
			printf("Edit name: ");
			scanf(" %49[^\n]", new_name);
		}
		strcpy(tmp->name, new_name);
		printf("Edit percentage: ");
		scanf("%f", &percentage);
		while(!is_percentage_valid(percentage)){
			printf("Edit percentage: ");
			scanf("%f", &percentage);
		}
		tmp->percentage = percentage;
		return;
	}
	else if(f > 1){
		printf("└───────────────┴───────────────────────────────────┴───────────────┘\n");
		printf("Enter rollno: ");
		scanf("%d", &rollno);
		node = head;
		while(node){
			if(node->rollno == rollno && (strcmp(node->name, name) == 0)){
				printf("┌───────────────┬───────────────────────────────────┬───────────────┐\n");
				printf("│ %-13s │ %-33s │ %-13s │\n", "Roll Number", "Name", "Percentage");
				printf("├───────────────┼───────────────────────────────────┼───────────────┤\n");
				printf("│ %-13d │ %-33s │ %-13.2f │\n", node->rollno, node->name, node->percentage);
				printf("└───────────────┴───────────────────────────────────┴───────────────┘\n");
				printf("Edit name: ");
				scanf(" %49[^\n]",new_name);
				while(!is_name_valid(new_name)){
					printf("Edit name: ");
					scanf(" %49[^\n]",new_name);
				}
				strcpy(node->name, new_name);
				printf("Name edited successfully\n");
				printf("Edit percentage: ");
				scanf("%f", &percentage);
				while(!is_percentage_valid(percentage)){
					printf("Edit percentage: ");
					scanf("%f", &percentage);
				}
				node->percentage = percentage;
				printf("Percentage edited successfully\n");
				return;
			}
			node = node->next;
		}
		printf("\033[31mInvalid roll number\033[0m\n");
	}	
	else
		printf("\033[31mNo records with matching name\033[0m\n");
}
void edit_record_percentage(student *head, float percentage){
	if(!head){
		printf("\033[31mRecord is empty\033[0m\n");
		return;
	}
	student *node = head, *tmp;
	int rollno;
	char new_name[50];
	float new_percentage;
	int f = 0;
	while(node){
		if(percentage == node->percentage){
			if(!f){
				printf("┌───────────────┬───────────────────────────────────┬───────────────┐\n");
				printf("│ %-13s │ %-33s │ %-13s │\n", "Roll Number", "Name", "Percentage");
				printf("├───────────────┼───────────────────────────────────┼───────────────┤\n");
				tmp = node;
			}
			printf("│ %-13d │ %-33s │ %-13.2f │\n", node->rollno, node->name, node->percentage);
			f++;
		}
		node = node->next;	
	}
	if(f == 1){
		printf("└───────────────┴───────────────────────────────────┴───────────────┘\n");
		printf("Edit name: ");
		scanf(" %49[^\n]", new_name);
		while(!is_name_valid(new_name)){
			printf("Edit name: ");
			scanf(" %49[^\n]", new_name);
		}
		strcpy(tmp->name, new_name);
		printf("Edit percentage: ");
		scanf("%f", &new_percentage);
		while(!is_percentage_valid(new_percentage)){
			printf("Edit percentage: ");
			scanf("%f", &new_percentage);
		}
		tmp->percentage = new_percentage;
		return;
	}
	else if(f > 1){
		printf("└───────────────┴───────────────────────────────────┴───────────────┘\n");
		printf("Enter rollno: ");
		scanf("%d", &rollno);
		node = head;
		while(node){
			if(node->rollno == rollno && node->percentage == percentage){
				printf("┌───────────────┬───────────────────────────────────┬───────────────┐\n");
				printf("│ %-13s │ %-33s │ %-13s │\n", "Roll Number", "Name", "Percentage");
				printf("├───────────────┼───────────────────────────────────┼───────────────┤\n");
				printf("│ %-13d │ %-33s │ %-13.2f │\n", node->rollno, node->name, node->percentage);
				printf("└───────────────┴───────────────────────────────────┴───────────────┘\n");
				printf("Edit name: ");
				scanf(" %49[^\n]",new_name);
				while(!is_name_valid(new_name)){
					printf("Edit name: ");
					scanf(" %49[^\n]",new_name);
				}
				strcpy(node->name, new_name);
				printf("Name edited successfully\n");
				printf("Edit percentage: ");
				scanf("%f", &new_percentage);
				while(!is_percentage_valid(new_percentage)){
					printf("Edit percentage: ");
					scanf("%f", &new_percentage);
				}
				node->percentage = new_percentage;
				printf("Percentage edited successfully\n");
				return;
			}
			node = node->next;
		}
		printf("\033[31mInvalid roll number\033[0m\n");
	}	
	else
		printf("\033[31mNo records with matching percentage\033[0m\n");
}
