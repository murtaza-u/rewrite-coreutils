PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin
CC ?= gcc

all: muname

muname: muname.o
	$(CC) -o $@ $^ $(LDFLAGS)

install: all
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 muname $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/muname

clean:
	rm -f muname *.o

.PHONY: all install uninstall clean
