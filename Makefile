.PHONY: minibasic

minibasic: lexer.o parser.o ast.o compile.o print.o
	$(CC) $^ -o $@

lexer.o: ast.h
parser.o: ast.h 
compile.o: ast.h

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
