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

Type createFunctionType(Type returnType, TypeList params) {
    Type t = (Type)malloc(sizeof(struct Type_tag));
    t->kind = TYPE_FUNCTION;
    t->u.function.returnType = returnType;
    t->u.function.params = params;
    return t;
}
TypeList addTypeToList(TypeList list, Type type) {
    TypeList newNode = malloc(sizeof(struct TypeList_tag));
    newNode->type = type;
    newNode->next = list;
    return newNode;
}


int equalType(Type type1, Type type2) {
     if (type1->kind == type2->kind) {
        if (type1->kind == TYPE_ARRAY_INT || type1->kind == TYPE_ARRAY_CHAR) {
            return type1->u.arraySize == type2->u.arraySize;
        }
        if (type1->kind == TYPE_FUNCTION) {
            // Here you should implement your own logic for comparing function types.
            // You should check if the argument types and the return types are the same.
            // This is not implemented here because it depends on how you decide to manage the TypeList.
        }
        return 1;
    } else if ((type1->kind == TYPE_ARRAY_INT && type2->kind == TYPE_INT) || 
               (type1->kind == TYPE_INT && type2->kind == TYPE_ARRAY_INT) ||
               (type1->kind == TYPE_ARRAY_CHAR && type2->kind == TYPE_CHAR) ||
               (type1->kind == TYPE_CHAR && type2->kind == TYPE_ARRAY_CHAR)) {
        return 1;
    }
    return 0;
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
            printf("Function(Return Type: ");
            printType(type->u.function.returnType);
            printf(", Parameter Types: ");
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

