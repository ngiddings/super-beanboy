obj = tests.o
bin = beanboy-test

CFLAGS += -I../include/

all: $(obj)
	gcc -L../libbeanboy/ -lbeanboy $(obj) -o $(bin)

clean:
	rm -f $(obj)
	rm -f $(bin)
