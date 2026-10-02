OBJ = src/stud_main.o src/stud_add.o src/stud_show.o src/stud_del.o
student: $(OBJ)
	cc $^ -o $@
%.o: %.c src/student.h
	cc -c $< -o $@

clean: 
	@rm -f src/*.o student
