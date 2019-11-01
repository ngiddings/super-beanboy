objects = machine.o
main = main.o
test = tests.o
beanboy_bin = beanboy64
test_bin = beanboy-test

all: quark tests

install:
	cp beanboy64 $(PREFIX)/bin

uninstall:
	rm $(PREFIX)/bin

clean:
	rm $(objects)

quark: $(objects) $(main)
	gcc $(objects) $(main) -o $(beanboy_bin)

tests: $(objects) $(test)
	gcc $(objects) $(test) -o $(test_bin)
