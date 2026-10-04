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

void sort_record_name(student **head){
	if(!*head){
		printf("\033[31mRecord is empty\n");
		return;
	}
	student *node1 = *head, *node2, *tmp, dummy = {-1, "\0", -1.00, NULL};
	while(node1){
		tmp = node1->next;
		node2 = &dummy;
		while(node2->next && strcmp(node1->name, node2->next->name) > 0){
			node2 = node2->next;
		}
		
		node1->next = node2->next;
		node2->next = node1;
		node1 = tmp;
	}
	*head = dummy.next;
	printf("Record sorted successfully\n");
	show_all_records(*head);
}

void sort_record_percentage(student **head){
	if(!*head){
		printf("\033[31mRecord is empty\033[0m\n");
		return;
	}
	student *node1 = *head, *node2, *tmp;
	student dummy = {-1, "", -1.00, NULL};
	while(node1){
		tmp = node1->next;
		node2 = &dummy;
		while(node2->next && node1->percentage < node2->next->percentage)
			node2  = node2->next;
		node1->next = node2->next;
		node2->next = node1;
		node1 = tmp;
	}
	*head = dummy.next;
	printf("Record sorted successfully\n");
	show_all_records(*head);
}

void sort_record_rollno(student **head){
	if(!*head){
		printf("\033[31mRecord is empty\n");
		return;
	}
	student *node1 = *head, *node2, *tmp;
	student dummy ={-1, "", -1.0,  NULL };
	while(node1){
		tmp =  node1->next;
		node2 = &dummy;
		while(node2->next && node1->rollno > node2->next->rollno)
			node2 = node2->next;
		node1->next = node2->next;
		node2->next = node1;
		node1 = tmp;
	}
	*head = dummy.next;
	printf("Record sorted sucessfully\n");
	show_all_records(*head);
}

void reverse_record(student **head){
	if(!*head){
		printf("\033[31mRecord is empty\033[0m\n");
		return;
	}
	student *node = *head, *prev = NULL, *tmp;
	while(node){
		tmp = node->next;
		node->next = prev;
		prev = node;
		node = tmp;
	}
	*head = prev; 		
	printf("Record successfully reversed\n");
	show_all_records(*head);
}
