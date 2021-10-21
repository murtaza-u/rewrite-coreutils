PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
CC ?= gcc

all: mcat

mcat: mcat.o
	$(CC) -o $@ $^ $(LDFLAGS)

install: all
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 mcat $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/mcat

clean:
	rm -f mcat *.o

.PHONY: all install uninstall clean
