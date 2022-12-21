all:
	clang function.c task.c -o bin -g
	valgrind --leak-check=full ./bin
