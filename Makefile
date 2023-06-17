LLVM_CONFIG ?= llvm-config

CFLAGS := $(shell $(LLVM_CONFIG) --cflags)
LDFLAGS := $(shell $(LLVM_CONFIG) --ldflags --system-libs --libs core)

.PHONY: minibasic

minibasic: lexer.o parser.o ast.o irgen.o print.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

lexer.o: ast.h

parser.o: ast.h

irgen.o: irgen.h

lexer.c: lexer.l parser.h
	flex -o lexer.c lexer.l

parser.c parser.h: parser.y
	bison -d -o parser.c parser.y

clean:
	rm -f *.o lexer.c parser.c parser.h

distclean: clean
	rm -f minibasic

run: minibasic
	./minibasic < $(INPUT)
