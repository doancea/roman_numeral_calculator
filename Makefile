IDIR=includes
CC=gcc
CFLAGS=-I$(IDIR)

OBJDIR=obj
SRCDIR=src
TESTDIR=tests

LDFLAGS = `pkg-config --libs check`

_DEPS = roman_calculator.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = roman_calculator.o roman_calculator_test.o 
OBJ=$(patsubst %, $(OBJDIR)/%, $(_OBJ))

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJDIR)/%.o: $(TESTDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)
	./test

clean: 
	rm -f $(OBJDIR)/*.o
	rm -f ./test

testAll: clean test memcheck

memcheck: test
	valgrind ./test