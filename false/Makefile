PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
CC ?= gcc

all: mfalse

mfalse: mfalse.o
	$(CC) -o $@ $^ $(LDFLAGS)

install: all
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 mfalse $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/mfalse

clean:
	rm -f mfalse *.o

.PHONY: all install uninstall clean
