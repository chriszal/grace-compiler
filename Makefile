.PHONY: all clean run

all: parser

parser: lex.yy.c parser.tab.c
	gcc  lex.yy.c parser.tab.c -o parser

lex.yy.c: lexer.l
	flex lexer.l

parser.tab.c: parser.y
	bison -d parser.y

clean:
	rm -f parser lex.yy.c parser.tab.c parser.tab.h parser.output

run: parser
	./parser < $(INPUT)
