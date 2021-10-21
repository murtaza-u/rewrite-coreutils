PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
CC ?= gcc

all: mrmdir

mrmdir: mrmdir.o
	$(CC) -o $@ $^ $(LDFLAGS)

install: all
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 mrmdir $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/mrmdir

clean:
	rm -f mrmdir *.o

.PHONY: all install uninstall clean
