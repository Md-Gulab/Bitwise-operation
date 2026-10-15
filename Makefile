compile: main.c
	gcc -std=c2x -Wall -Wextra -Wpedantic -lucrt main.c -o main

run: main.exe
	./main.exe	

clean: main.exe
	rm main.exe
