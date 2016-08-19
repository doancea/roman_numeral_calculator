IDIR=includes
CC=gcc
CFLAGS=-I$(IDIR)

OBJDIR=obj
SRCDIR=src
TESTDIR=tests

LDFLAGS = `pkg-config --libs check`

_DEPS = numeral_compressor.h roman_calculator.h numeral_compressor_tests.h roman_calculator_tests.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = numeral_compressor.o roman_calculator.o numeral_compressor_tests.o roman_calculator_tests.o test_runner.o
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