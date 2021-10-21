PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
CC ?= gcc

all: mtrue

mtrue: mtrue.o
	$(CC) -o $@ $^ $(LDFLAGS)

install: all
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 mtrue $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/mtrue

clean:
	rm -f mtrue *.o

.PHONY: all install uninstall clean
