compile: src/main.c src/bit_manipulation.c
	gcc -std=c2x -Wall -Wextra -Wpedantic -lucrt 	src/main.c	 src/bit_manipulation.c	 -o main

run: main.exe
	./main.exe	

clean: main.exe
	rm main.exe
