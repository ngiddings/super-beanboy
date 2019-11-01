obj = instructions.o machine.o
bin = libbeanboy.so

CFLAGS += -fpic -I../include/

all: $(obj)
	gcc -shared $(obj) -o $(bin)

install:
	cp $(bin) $(PREFIX)/lib

uninstall:
	rm -f $(PREFIX)/lib/$(bin)

clean:
	rm -f $(obj)
	rm -f $(bin)
