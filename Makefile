CC=g++
CFLAGS=-I./include -L./lib -l:json.o

main: object-definition-example file-dump-example data-accessing-example easy-data-accessing-example

object-definition-example: json.o
	$(CC) $(CFLAGS) -o ./bin/object-definition-example ./examples/object-definition-example.cpp

file-dump-example: json.o
	$(CC) $(CFLAGS) -o ./bin/file-dump-example ./examples/file-dump-example.cpp

data-accessing-example: json.o
	$(CC) $(CFLAGS) -o ./bin/data-accessing-example ./examples/data-accessing-example.cpp

easy-data-accessing-example: json.o
	$(CC) $(CFLAGS) -o ./bin/easy-data-accessing-example ./examples/easy-data-accessing-example.cpp

json.o:
	g++ -I./include -c -o ./lib/json.o ./src/json.cpp 