all:
	clang main_task.c -o bin -g
	valgrind --leak-check=full ./bin
