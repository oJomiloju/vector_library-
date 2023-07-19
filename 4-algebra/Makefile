all:
	@gcc -std=c11 -g -Wall -I../include src/* -o ./mysolution -lm

clean:
	rm ./mysolution
	@echo Cleanup complete!
run: all
	@./mysolution dot ../data/a.dat ../data/b.dat
test:
	python tests/sanitycheck.py 
	