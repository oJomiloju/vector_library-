all:
	gcc -std=c11 -g -Wall -I../include src/*.c -o ./mysolution -lm
clean:
	rm ./mysolution
	@echo Cleanup complete!
run: all
	@./mysolution 3 5 2
test:
	python tests/sanitycheck.py 
	