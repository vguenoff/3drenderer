# -Wall sholls all the warnings
build:
	gcc -Wall -std=c99 src/*.c -o src/main
run:
	./src/main
clean:
	rm ./main 
