compile: src/main.c src/bit_manipulation.c
	gcc -std=c2x -Wall -Wextra -Wpedantic -lucrt 	src/main.c	 src/bit_manipulation.c	 -o main

run: main.exe
	./main.exe	

test: test/test_bit_manipulation.c src/bit_manipulation.c unity/src/unity.c
	gcc -std=c2x -Wall -Wextra -Wpedantic -Iunity/src -Isrc test/test_bit_manipulation.c src/bit_manipulation.c unity/src/unity.c -o test_bit_manipulation.exe -lucrt
	./test_bit_manipulation.exe	

clean: main.exe
	rm main.exe	test_bit_manipulation.exe



