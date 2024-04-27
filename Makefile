# -Wall sholls all the warnings
build:
	gcc -Wall -std=c99 -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 src/*.c -o renderer
debug:
	gcc -g -Wall -std=c99 -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 src/*.c -o renderer
# and f5 for debug
run:
	./renderer
clean:
	rm ./renderer
