#include<stdio.h>
#include "student.h"

int main(){
	student *head = NULL;
	char op, sub_op, name[50];
	int rollno;
	float percentage;
	recover_record(&head);
	while(1){
		printf("************************** STUDENT RECORD MENU *************************\n\n\n");
		printf("a/A : Add new record\n");
		printf("d/D : Delete a record\n");
		printf("v/V : Show the list\n");
		printf("m/M : Modify a record\n");
		printf("s/S : Save records\n");
		printf("t/T : Sort the records\n");
		printf("r/R : Reverse the record\n");
		printf("l/L : Delete all the records\n");
		printf("e/E : Exit\n");		
		scanf(" %c", &op);	
		op |= 32;
		switch(op){
			case 'a': add_new(&head); break;
			case 'd':
				printf("r/R : Roll number based deletion\n");
				printf("n/N : Name base deletion\n"); 
				scanf(" %c", &sub_op);
				sub_op |= 32;
				switch(sub_op){
					case 'r':
						printf("Enter roll number: ");
						scanf("%d",&rollno);
						delete_record_rollno(&head, rollno);
						break;	
					case 'n':
						printf("Enter name: ");
						scanf("%s49",name);
						delete_record_name(&head, name);
						break;
					default: printf("Invalid input\n");
				}
				break;
			case 'v': show_all_records(head); break;
			case 'm': 
				printf("r/R : Search record to modify using roll number\n");
				printf("n/N : Search record to modify using name\n");
				printf("p/P : Search record to modify using percentage\n");
				
				scanf(" %c", &sub_op);
				sub_op |= 32;
				switch(sub_op){
					case 'r':
						printf("Enter roll number: ");
						scanf("%d",&rollno);
						edit_record_rollno(head, rollno);
						break;	
					case 'n':
						printf("Enter name: ");
						scanf("%49s",name);
						edit_record_name(head, name);
						break;
					case 'p': 
						printf("Enter percentage: ");
						scanf("%f",percentage);
						edit_record_percentage(head, percentage);
						break;

					default: printf("Invalid input\n");
				}
				break;
			case 's': save_record(head); break;
			case 't': sort_record(&head); break;
			case 'r': reverse_record(&head); break;
			case 'l': delete_all(&head); break;
			case 'e': 
				printf("s/S : Save and exit\n");
				printf("e/E : Exit without saving\n");
				scanf(" %c", &sub_op);
				sub_op |= 32;
				if(sub_op == 's'){
		 			save_record(head);
					return 0;
				}
				else if(sub_op == 'e')
					return 0;
				else
					printf("Invalid input\n");
				break;
			default: printf("Inalid input\n");
				 
		}
	}
}
