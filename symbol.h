
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

struct SymbolEntry_tag {
        const char* id;
        EntryType entryType;
        unsigned int nestingLevel;
        unsigned int hashValue;
        SymbolEntry* nextHash;
        SymbolEntry* nextInScope;

        Type type;
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
