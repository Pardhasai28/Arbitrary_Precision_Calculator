result.exe: main.o validation.o compare_list.o compare.o create_list.o print_list.o add.o sub.o mul.o div.o
	gcc -o result.exe main.c validation.c compare_list.c compare.c create_list.c print_list.c add.c sub.c mul.c div.c
main.o: main.c
	gcc -c main.c
validation.o: validation.c
	gcc -c validation.c
compare_list.o: compare_list.c
	gcc -c compare_list.c
compare.o: compare.c
	gcc -c compare.c
create_list.o: create_list.c
	gcc -c create_list.c
print_list.o: print_list.c
	gcc -c print_list.c
add.o: add.c
	gcc -c add.c
sub.o: sub.c
	gcc -c sub.c
mul.o: mul.c
	gcc -c mul.c
div.o: div.c
	gcc -c div.c
clean:
	rm *.exe *.o