# -Wall sholls all the warnings
build:
	gcc -Wall -std=c99 src/*.c -o renderer
debug:
	gcc -g -Wall -std=c99 src/*.c -o renderer 
# and f5 for debug
run:
	./renderer
clean:
	rm ./renderer
