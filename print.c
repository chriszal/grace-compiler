#include "ast.h"
#include <stdio.h>

void print_ast(ast a) {
    if (a == NULL){
        printf("AST NOT COMPLETE\n");
        return;
    }

    switch (a->type) {
        case ID:
            printf("ID(%c)", a->data.id);
            return;
        case NUM:
            printf("NUM(%d)", a->data.num);
            return;
        case STR:
            printf("STR(%s)",a->data.str);
            return;
        case PLUS:
            printf("Plus(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        case MINUS:
            printf("Minus(");
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
        case DIVIDE:
            printf("DIVIDE(");
            print_ast(a->left);
            printf(",");
            print_ast(a->right);
            printf(")");
            return;
        // Add cases for other node types
        default:
            printf("Unknown AST node\n");
    }

}
