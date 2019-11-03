obj = main.o
bin = beanboy-emul

CFLAGS += -I../include/

all: $(obj)
	gcc -L../libbeanboy/ -lbeanboy $(obj) -o $(bin)

install:
	cp $(bin) $(PREFIX)/bin

uninstall:
	rm -f $(PREFIX)/bin/$(bin)

clean:
	rm -f $(obj)
	rm -f $(bin)
