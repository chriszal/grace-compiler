
#ifndef __SYMBOL_H__
#define __SYMBOL_H__

#include "type.h"

typedef enum {
   ENTRY_VARIABLE,
   ENTRY_CONSTANT,
   ENTRY_FUNCTION,
   ENTRY_PARAMETER,
   ENTRY_TEMPORARY
} EntryType; 

typedef struct SymbolEntry_tag SymbolEntry;

typedef union EntryDetails_tag {
    int arraySize; // Used when the symbol represents an array
    int functionParameters; // Used when the symbol represents a function
    // ... other fields, as needed
} EntryDetails;


struct SymbolEntry_tag {
        const char* id;
        EntryType entryType;
        unsigned int nestingLevel;
        unsigned int hashValue;
        SymbolEntry* nextHash;
        SymbolEntry* nextInScope;

        Type type;
        EntryDetails u;

};

typedef struct Scope_tag Scope;

struct Scope_tag {
        unsigned int nestingLevel;
        unsigned int negOffset;
        Scope* parent;
        SymbolEntry* entries;
};


extern Scope* currentScope;

void initSymbolTable(unsigned int size);
void destroySymbolTable();

void openScope();
void closeScope();

SymbolEntry * newEntry(const char * name, Type type);
void destroyEntry(SymbolEntry* e);
SymbolEntry* lookupEntry(const char* name, int err);

SymbolEntry* newVariable(const char* name, Type type);

#endif
