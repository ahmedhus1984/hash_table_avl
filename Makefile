hash:main.o main_lib.o user_interface_lib.o hash_table_lib.o avl_lib.o
	gcc -g3 -Wall main.o user_interface_lib.o main_lib.o hash_table_lib.o avl_lib.o -o hashtableavl.exe

avl_lib.o:avl_lib.c
	gcc -g3 -Wall -c avl_lib.c -o avl_lib.o

hash_table_lib.o:hash_table_lib.c
	gcc -g3 -Wall -c hash_table_lib.c -o hash_table_lib.o

user_interface_lib.o:user_interface_lib.c
	gcc -g3 -Wall -c user_interface_lib.c -o user_interface_lib.o

main.o:main.c
	gcc -g3 -Wall -c main.c -o main.o

main_lib.o:main_lib.c
	gcc -g3 -Wall -c main_lib.c -o main_lib.o

clear:
	rm *.o
clean:
	rm *.o *.exe