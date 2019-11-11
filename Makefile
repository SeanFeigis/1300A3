all: removeCommas chop
	gcc -ansi -Wall -o babyQuery babyQuery.c removeCommas.o chop.o

clean:
	rm removeCommas.o
	rm babyQuery
	rm chop.o

babyQuery: 
	gcc -ansi -Wall -o babyQuery babyQuery.c

removeCommas:
	gcc -ansi -Wall -c removeCommas.c

chop: 
	gcc -ansi -Wall -c chop.c

