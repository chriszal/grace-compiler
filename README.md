## Execute
* Cleans up unwanted files.
```
make clean
```
* Builds the compiler and creates the parser executable
``` 
make 
```
* Replace your_input_file.txt with the name of the input file you want to use. This command runs the parser with the specified input file.
```
INPUT=your_input_file.txt make run
```
## Not finished on semantic

- checks for multiple dimention arrays
- scopes are messed up
- func calls
- multipe func defs
- ref
- blocks, else, do , then?



## Lexer

### 1. Header section:
Includes the parser.tab.h file which will grab the tokens from the parser.
### 2. Options:
These options configure the behavior of the lexer. ``debug`` enables debug mode, and ``noyywrap`` disables the default behavior of calling the ``yywrap`` function when the lexer encounters the end of the input file.
### 3. Start condition:
This declares an exclusive start condition named COMMENT, which is used to handle multi-line comments in the lexer.
### 4. Definitions:
* ``delim``: Matches a single whitespace character, which can be a space, tab, or newline. `[ \t\n]`
* ``ws``: Matches one or more whitespace characters (spaces, tabs, or newlines). `{delim}+`
* ``l``: Matches a single lowercase or uppercase letter. `[A-Za-z]`
* ``d``: Matches a single digit. `[0-9]`
* ``common_char``: Matches any character except backslash, single quote, double quote, or newline. `[^\\'"\n]`
* ``escape_seq``: Matches escape sequences like `\n, \t, \r, \0, \\, \', \", and \xnn` (where nn is a two-digit hexadecimal number). `(\\[ntr0'"]|\\x[a-fA-F0-9]{2})`
* ``fixed_char``: Matches a single character from a fixed character constant, which can be a common character or an escape sequence. `({common_char}|{escape_seq})`
* ``str_char``: Matches a single character from a string constant, which can be a common character or an escape sequence. `({common_char}|{escape_seq})`

### 5. Rules:
* Increment line number when a newline is encountered: `\n { ++yylineno; }`
* Match and return identifiers: `{l}({l}|{d}|_)* { return T_ID; }`
* Match and return numeric constants: `{d}+ { return T_NUM; }`
* Match and return fixed character constants: `' {fixed_char} ' { return T_FIXED_CHAR; }`
* Match and return string constants: `\" {str_char}* \" { return T_STR; }`
* Handle whitespace and increment line number for newlines: `{delim} { if (*yytext == '\n') { ++yylineno; } }`
* Discard single-line comments: `\$[^$\n]* { }`
* Handle multi-line comments:
    * Enter COMMENT start condition: `\$\$ { BEGIN(COMMENT); }`
    * Exit COMMENT start condition: `<COMMENT>\$\$ { BEGIN(INITIAL); }`
    * Discard any non-newline characters in a COMMENT: `<COMMENT>[^$\n]+ { }`
    * Discard a single $ followed by a non-newline character in a COMMENT
    * Increment line number for newlines in a COMMENT: `<COMMENT>\n { ++yylineno; }`
* Return 0 at the end of the file: `<<EOF>> { return 0; }`
* Print an error message and exit when an illegal token is encountered: `. { printf("Illegal token\n"); exit(1); }`
## Parser
### 1. Token Definitions:

These are the tokens defined by the lexer. They are matched in the parser rules.

### 2. Precedence and Associativity:

These directives define the precedence and associativity of the operators used in expressions.

1. `%left T_OR`: The T_OR token has left associativity.
2. `%left T_AND`: The T_AND token has left associativity.
3. `%right T_NOT`: The T_NOT token has right associativity.
4. `%left T_HASH T_EQUAL T_NOT_EQUAL T_LESS_THAN T_GREATER_THAN T_LESS_EQUAL 
T_GREATER_EQUAL`: All these tokens have left associativity.
5. `%left T_MOD T_DIV`: Both tokens have left associativity.
6. `%left T_PLUS T_MINUS`: Both tokens have left associativity.
7. `%left T_MULTIPLY`: The T_MULTIPLY token has left associativity.

### 3. Rules:

1. `program`: func_def;: A program consists of a single function definition.
2. `func_def`: header local_defs block;: A function definition consists of a header, local definitions, and a block.
3. `header: T_FUN T_ID "(" fpar_defs ")" ":" ret_type;`: The header of a function definition has the keyword fun, an identifier, a list of formal parameters, and a return type.
4. `fpar_defs, fpar_def, ref_opt, id_list, fpar_type, data_type, arr_opt, ret_type`: These rules define the structure of formal parameters, data types, and return types.
5. `local_defs, local_def`: These rules define local definitions within a function, which can be other function definitions, function declarations, or variable definitions.
6. `var_def, type`: These rules define variable definitions and their types.
7. `func_decl`: This rule defines function declarations.
8. `stmt, else_opt, expr_opt, block, stmts`: These rules define statements, such as assignments, blocks, function calls, conditionals, loops, and return statements.
9. `func_call, exprs, expr_list`: These rules define function calls and their argument expressions.
10. `l_value`: This rule defines l-values, which can be identifiers, string literals, or array elements.
11. `expr`: This rule defines expressions, including numeric and character literals, l-values, function calls, and various arithmetic operations.
12. `cond`: This rule defines conditions, including comparisons and logical operations.

### 4. Error Handling:

The `yyerror` function is called when the parser encounters a syntax error. It prints the line number, an error message, and the current token.

### 5. Main Function:

The main function calls the `yyparse` function to parse the input. If the parsing is successful, it prints "Success."