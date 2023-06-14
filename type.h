#ifndef __TYPE_H__
#define __TYPE_H__

typedef struct Type_tag *Type;

typedef struct TypeList_tag {
    Type type;
    struct TypeList_tag* next;
} *TypeList;

struct Type_tag {
    enum {
        TYPE_INT,
        TYPE_CHAR,
        TYPE_ARRAY_INT,
        TYPE_ARRAY_CHAR,
        TYPE_NOTHING,
        TYPE_FUNCTION
    } kind;
    
    union {
        int arraySize; 
        struct {
            TypeList params;
            Type returnType;
        } function;
    } u;
};

extern const Type tyINT;
extern const Type tyCHAR;
extern const Type tyARRAY_INT;
extern const Type tyARRAY_CHAR;
extern const Type tyNOTHING;

int equalType(Type type1, Type type2);
void printType(Type type);

#endif
