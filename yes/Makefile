PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
CC ?= gcc

all: myes

myes: myes.o
	$(CC) -o $@ $^ $(LDFLAGS)

install: all
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 myes $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/myes

clean:
	rm -f myes *.o

.PHONY: all install uninstall clean
