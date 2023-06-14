.PHONY: minibasic

minibasic: lexer.o parser.o ast.o sem.o symbol.o type.o error.o 
	$(CC) $^ -o $@

lexer.o: ast.h
parser.o: ast.h sem.h symbol.h type.h
sem.o: ast.h sem.h
symbol.o: symbol.h 
type.o:  type.h
error.o: error.h

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
