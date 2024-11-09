all: main-debug main-ndebug

main-ndebug: main.c
	gcc -DNDEBUG -o $@ $<

main-debug: main.c
	gcc -o $@ $<

clean:
	rm -f main-debug main-ndebug
