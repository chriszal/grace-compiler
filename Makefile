.PHONY: minibasic

CFLAGS  = `llvm-config --cflags`
LDFLAGS = `llvm-config --libs --cflags --ldflags all`

minibasic: lexer.o parser.o ast.o irgen.o print.o
	$(CC) $^ -o $@ $(LDFLAGS)

libminibasic:

lexer.o: ast.h
parser.o: ast.h
irgen.o: irgen.h

lexer.c: lexer.l parser.h
	flex -o lexer.c lexer.l

parser.c parser.h: parser.y
	bison -d -o parser.c parser.y

clean:
	rm -f *.o

distclean: clean
	rm -f minibasic lexer.c parser.c parser.h


run: minibasic
	./minibasic < $(INPUT)
