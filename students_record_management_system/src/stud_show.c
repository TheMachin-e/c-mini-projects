#include<stdio.h>
#include "student.h"


void show_all_records(student *head){
        if(!head){
                printf("No records yet\n");
                return; 
        }
        printf("┌──────────┬─────────────────────────┬──────────┐\n");
        while(head){
                printf("│ %-8d │ %-23s │ %-8.2f │\n", head->rollno, head->name, head->percentage);
                head = head->next;
        }
        printf("└──────────┴─────────────────────────┴──────────┘\n");    
    
}

