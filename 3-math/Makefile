all:
	@gcc -std=c11 -g -Wall -I../include src/* -o ./mysolution -lm

clean:
	rm ./mysolution
	@echo Cleanup complete!

run: all
	@./mysolution add ../data/a.dat ../data/b.dat 1
test:
	python tests/sanitycheck.py 
	