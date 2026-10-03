#include<stdio.h>
#include "student.h"


void show_all_records(student *head){
        if(!head){
		printf("No records yet\n");
		return; 
	}
	printf("┌───────────────┬───────────────────────────────────┬───────────────┐\n");
	printf("│ %-13s │ %-33s │ %-13s │\n", "Roll Number", "Name", "Percentage");
	printf("├───────────────┼───────────────────────────────────┼───────────────┤\n");
	while(head){
		printf("│ %-13d │ %-33s │ %-13.2f │\n", head->rollno, head->name, head->percentage);
		head = head->next;
	}
	printf("└───────────────┴───────────────────────────────────┴───────────────┘\n");    

}

