#include "type.h"
#include <stdio.h>
#include <stdlib.h>

static struct Type_tag typeConst[] = {
    { .kind = TYPE_INT },
    { .kind = TYPE_CHAR },
    { .kind = TYPE_ARRAY_INT, .u.arraySize = 0 },
    { .kind = TYPE_ARRAY_CHAR, .u.arraySize = 0 },
    { .kind = TYPE_NOTHING }
};

const Type tyINT = &(typeConst[0]);
const Type tyCHAR = &(typeConst[1]);
const Type tyARRAY_INT = &(typeConst[2]);
const Type tyARRAY_CHAR = &(typeConst[3]);
const Type tyNOTHING = &(typeConst[4]);

Type newFunctionType(TypeList params, Type returnType) {
    Type newType = (Type) malloc(sizeof(struct Type_tag));
    newType->kind = TYPE_FUNCTION;
    newType->u.function.params = params;
    newType->u.function.returnType = returnType;
    return newType;
}

void freeFunctionType(Type type) {
    if (type->kind != TYPE_FUNCTION) return;
    TypeList curr = type->u.function.params, next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(type);
}

int equalType(Type type1, Type type2) {
    if (type1->kind != type2->kind) {
        return 0;
    }
    if (type1->kind == TYPE_ARRAY_INT || type1->kind == TYPE_ARRAY_CHAR) {
        return type1->u.arraySize == type2->u.arraySize;
    }
    if (type1->kind == TYPE_FUNCTION) {
        // Here you should implement your own logic for comparing function types.
        // You should check if the argument types and the return types are the same.
        // This is not implemented here because it depends on how you decide to manage the TypeList.
    }
    return 1;
}

void printType(Type type) {
    if (type == NULL) {
        printf("<undefined>");
        return;
    }
    switch (type->kind) {
        case TYPE_INT:
            printf("int");
            break;
        case TYPE_CHAR:
            printf("char");
            break;
        case TYPE_ARRAY_INT:
            printf("int[%d]", type->u.arraySize);
            break;
        case TYPE_ARRAY_CHAR:
            printf("char[%d]", type->u.arraySize);
            break;
        case TYPE_NOTHING:
            printf("nothing");
            break;
        case TYPE_FUNCTION:
            printf("Function(");
            printType(type->u.function.returnType);
            printf(")(");
            TypeList param = type->u.function.params;
            while (param != NULL) {
                printType(param->type);
                if (param->next != NULL) printf(", ");
                param = param->next;
            }
            printf(")");
            break;
        default:
            printf("unknown");
            break;
    }
}
