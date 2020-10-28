CC=g++

all:
	$(CC) main.cpp -lboost_program_options

clean:
	rm -rf generated.txt a.out
