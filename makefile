strtest: Work2.c
	gcc Work2.c -o strtest

clean:
	rm *~

run: strtest
	./strtest
