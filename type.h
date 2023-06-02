#ifndef __TYPE_H__
#define __TYPE_H__

typedef struct Type_tag *Type;

struct Type_tag {
    enum {
        TYPE_INT,
        TYPE_CHAR,//ref function
        TYPE_ARRAY_INT,
        TYPE_ARRAY_CHAR,
        TYPE_NOTHING
    } kind;

    int arraySize; // Valid only when kind == TYPE_ARRAY_INT or TYPE_ARRAY_CHAR
};

extern const Type tyINT;
extern const Type tyCHAR;
extern const Type tyARRAY_INT;
extern const Type tyARRAY_CHAR;
extern const Type tyNOTHING;

int equalType(Type type1, Type type2);
void printType(Type type);

#endif
