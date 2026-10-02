student: src/stud_main.o src/stud_add.o src/stud_show.o src/stud_del.o
	cc  $^ -o $@
src/stud_main.o: src/stud_main.c src/student.h
	cc -c $< -o $@
src/stud_add.o: src/stud_add.c src/student.h
	cc -c $< -o $@
src/stud_show.o: src/stud_show.c src/student.h
	cc -c $< -o $@
src/stud_del.o: src/stud_del.c src/student.h
	cc -c $< -o $@

clean: 
	@rm -f src/*.o student
