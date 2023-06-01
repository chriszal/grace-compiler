#include "ast.h"
#include <stdio.h>

void print_ast(ast a) {
    if (a == NULL) {
        printf("AST NOT COMPLETE\n");
        return;
    }

    switch (a->k) {
        case ID:
            printf("ID(%s)", a->data.str);
            return;
        case NUM:
            printf("NUM(%d)", a->data.num);
            return;
        case STR:
            printf("STR(%s)", a->data.str);
            return;
        case PLUS:
            printf("PLUS(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case MINUS:
            printf("MINUS(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case MULTIPLY:
            printf("MULTIPLY(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case DIV:
            printf("DIVIDE(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case MOD:
            printf("MOD(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case NEGATIVE:
            printf("NEGATIVE(");
            print_ast(a->left);
            printf(")");
            return;
        case POSITIVE:
            printf("POSITIVE(");
            print_ast(a->left);
            printf(")");
            return;
        case VAR:
            printf("VAR(");
            print_ast(a->left);  
            printf(",");
            print_ast(a->right); 
            printf(")");
            return;
        case FUNC_CALL:
            printf("FUNC_CALL(%s,", a->data.str);
            if (a->left->k == EMPTY_STMTS) {
                printf("NO_PARAMS");
            } else {
                print_ast(a->left);
            }
            printf(")");
            return;

        case FUNCTION_DEF:
            printf("FUNCTION_DEF(");
            print_ast(a->left); // Prints function header
            printf(",");
            if (a->middle != NULL) {
                print_ast(a->middle); // Prints local definitions (if any)
                printf(",");
            }
            if (a->right != NULL) {
                print_ast(a->right); // Prints function body (if any)
            }
            printf(")");
            return;

        case ARG_LIST:
            printf("ARG_LIST(");
            print_ast(a->left);
            ast next_arg = a->right;
            while (next_arg != NULL) {
                printf(",");
                print_ast(next_arg->left);
                next_arg = next_arg->right;
            }
            printf(")");
            return;



        case SEMICOLON:
        case COMMA:
        case COLON:
            printf("(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case INT:
            printf("INT");
            return;
        case CHAR:
            printf("CHAR");
            return;
        case NOTHING:
            printf("NOTHING");
            return;
        case FUN:
            printf("FUN(%s,", a->data.str);
            if (a->left->k == EMPTY_STMTS) {
                printf("NO_PARAMS,");
            } else {
                print_ast(a->left);
                printf(",");
            }
            print_ast(a->right);
            printf(")");
            return;
        case REF:
            printf("REF()");
            return;

        case ARRAY:
            printf("ARRAY(");
            printf("Size: %d", a->data.num);
            printf(")");
            return;
        case TYPE:
            printf("TYPE(");
            print_ast(a->left); // data type
            if (a->middle != NULL) {
                printf(", ");
                print_ast(a->middle); // array type
            }
            printf(")");
            return;



        case ARRAY_INDEX:
            printf("ARRAY_INDEX(");
            print_ast(a->left); // Array Variable
            printf(", ");
            print_ast(a->right); // Index
            printf(")");
            return;


        case FOR:
            printf("FOR(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case RETURN:
            printf("RETURN(");
            print_ast(a->left);
            printf(")");
            return;
        case IF:
            printf("IF(");
            print_ast(a->left);
            printf(",");
            print_ast(a->middle);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case ELSE:
            printf("ELSE(");
            print_ast(a->left);
            printf(")");
            return;

        case BLOCK:
            printf("BLOCK(");
            if (a->left != NULL) {
                print_ast(a->left);
            }
            printf(")");
            return;
        case DECL:
            printf("DECL(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case LOCAL_DEFS:
            printf("LOCAL_DEFS(");
            print_ast(a->left);
            if (a->right != NULL) {
                printf(",");
                print_ast(a->right);
            }
            printf(")");
            return;

        case LOCAL_DEF:
            printf("LOCAL_DEF(");
            print_ast(a->left);
            printf(")");
            return;
        
        case FPAR_DEF:
            if (a->left != NULL) {
                printf("REF(");
            }
            print_ast(a->middle);
            printf(":");
            print_ast(a->right);
            if (a->left != NULL) {
                printf(")");
            }
            return;


        case FPAR_DEFS:
            printf("FPAR_DEFS(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case ASSIGN:
            printf("ASSIGN(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case EMPTY_STMTS:
            printf("EMPTY_STMTS");
            return;
        case STMTS:
            printf("STMTS(");
            print_ast(a->left);
            ast next_stmts = a->right;
            while (next_stmts != NULL) {
                printf(",");
                print_ast(next_stmts->left);
                next_stmts = next_stmts->right;
            }
            printf(")");
            return;

        case ID_LIST:
            printf("ID_LIST(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case WHILE:
            printf("WHILE(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case AND:
            printf("AND(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case OR:
            printf("OR(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case EQUAL:
            printf("EQUAL(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case NOT_EQUAL:
            printf("NOT_EQUAL(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case LESS_THAN:
            printf("LESS_THAN(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case GREATER_THAN:
            printf("GREATER_THAN(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case LESS_EQUAL:
            printf("LESS_EQUAL(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case GREATER_EQUAL:
            printf("GREATER_EQUAL(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case NOT:
            printf("NOT(");
            print_ast(a->left);
            printf(")");
            return;


        // Add cases for other node types
        default:
            printf("Unknown AST node with type %d\n", a->k);

    }
}
