all:
	clang second.c -o bin -g
	valgrind --leak-check=full ./bin
