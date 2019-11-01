all:
	make -C libbeanboy
	make -C beanboy-emul
	make -C tests

install:
	mkdir -p /usr/include/beanboy
	cp include/*.h $(PREFIX)/usr/include/beanboy
	make -C libbeanboy install
	make -C beanboy-emul install

uninstall:
	rm -f $(PREFIX)/usr/include/beanboy/*
	make -C libbeanboy uninstall
	make -C beanboy-emul uninstall

clean:
	make -C libbeanboy clean
	make -C libbeanboy clean
