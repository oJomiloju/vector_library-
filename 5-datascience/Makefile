all:
	@gcc -std=c11 -g -Wall -I../include src/* -o ./mysolution -lm

clean:
	rm ./mysolution
	@echo Cleanup complete!
run: all
	@./mysolution mean ../data/a.dat 
test:
	python tests/sanitycheck.py 
	