#include<stdio.h>
#include"student.h"
#include<stdlib.h>

void save_record(student *head){
	if(!head){
		printf("\033[31mNo records yet\033[0m\n");
		return;
	}
	FILE *fp = fopen("student.dat", "w");
	if(!fp){
		printf("\033[31mFailed to open student.dat\033[0m\n");
		return;
	}
	while(head){
		fprintf(fp,"%d|%s|%f\n", head->rollno, head->name, head->percentage);
		head = head->next;
	}
	printf("Record saved\n");
	fclose(fp);		
}

void load_record(student **head){
	FILE *fp = fopen("student.dat", "r");
	if(!fp){
		printf("No saved records\n");
		return;
	}
	student *node = *head;
	student st;
	while(fscanf(fp, "%d|%49[^|]|%f", &st.rollno, st.name, &st.percentage) != EOF){
		student *new = calloc(1, sizeof(student));
		if(!new){
			printf("\033[31mCalloc failed\033[0m\n");
			fclose(fp);
			return;
		}
		*new = st;
		new->next = NULL;
		if(!*head){
			*head = new;
			node = new;
			continue;
		}
		node->next = new;
		node = new;
	}
	fclose(fp);
	printf("Data loaded successfully");
}
