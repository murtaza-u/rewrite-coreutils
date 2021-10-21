PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
CC ?= gcc

all: mecho

mecho: mecho.o
	$(CC) -o $@ $^ $(LDFLAGS)

install: all
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 mecho $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/mecho

clean:
	rm -f mecho *.o

.PHONY: all install uninstall clean
