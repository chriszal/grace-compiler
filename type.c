#include "type.h"
#include <stdio.h>

static struct Type_tag typeConst[] = {
    { TYPE_INT, 0 },
    { TYPE_CHAR, 0 },
    { TYPE_ARRAY_INT, 0 },
    { TYPE_ARRAY_CHAR, 0 },
    { TYPE_NOTHING, 0 }
};

const Type tyINT = &(typeConst[0]);
const Type tyCHAR = &(typeConst[1]);
const Type tyARRAY_INT = &(typeConst[2]);
const Type tyARRAY_CHAR = &(typeConst[3]);
const Type tyNOTHING = &(typeConst[4]);

int equalType(Type type1, Type type2) {
    if (type1->kind != type2->kind) {
        return 0;
    }
    if (type1->kind == TYPE_ARRAY_INT || type1->kind == TYPE_ARRAY_CHAR) {
        return type1->arraySize == type2->arraySize;
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
            printf("int[%d]", type->arraySize);
            break;
        case TYPE_ARRAY_CHAR:
            printf("char[%d]", type->arraySize);
            break;
        case TYPE_NOTHING:
            printf("nothing");
            break;
        default:
            printf("unknown");
            break;
    }
}
