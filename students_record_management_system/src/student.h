#ifndef STUDENT_H
#define STUDENT_H

typedef student {
	int rollno;
	char name[50];
	float percentage;
	struct student *next;
}student;

void add_new(student **);
void delete_record_rollno(student **, int);
void delete_record_name(student **, char *);
void delete_all(student **);
void show_all_records(student *);
void edit_record_rollno(student *, int);
void edit_record_name(student *, char *);
void save_record(student *);
void recover_record(void);
void sort_record(student **);
void reverse_record(student **);


#endif
