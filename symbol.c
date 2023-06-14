
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol.h"
#include "error.h"
#include "type.h"

Scope* currentScope;

static unsigned int hashTableSize;
static SymbolEntry** hashTable;


typedef unsigned long int HashType;

static HashType PJW_hash (const char * key)
{
    /*
     *  P.J. Weinberger's hashing function. See also:
     *  Aho A.V., Sethi R. & Ullman J.D, "Compilers: Principles,
     *  Techniques and Tools", Addison Wesley, 1986, pp. 433-437.
     */

    const HashType PJW_OVERFLOW =
        (((HashType) 0xf) << (8 * sizeof(HashType) - 4));
    const int PJW_SHIFT = (8 * (sizeof(HashType) - 1));

    HashType h, g;

    for (h = 0; *key != '\0'; key++) {
        h = (h << 4) + (*key);
        if ((g = h & PJW_OVERFLOW) != 0) {
            h ^= g >> PJW_SHIFT;
            h ^= g;
        }
    }
    return h;
}

void * new (size_t size)
{
   void * result = malloc(size);

   if (result == NULL)
      fatal("\rOut of memory");
   return result;
}

void delete (void * p)
{
   if (p != NULL)
      free(p);
}


void initSymbolTable(unsigned int size)
{
    unsigned int i;

    currentScope = NULL;

    hashTableSize = size;
    hashTable = (SymbolEntry **) new(size * sizeof(SymbolEntry *));

    for (i = 0; i < size; i++)
        hashTable[i] = NULL;
}

void destroySymbolTable()
{
    unsigned int i;

    for (i = 0; i < hashTableSize; i++)
        if (hashTable[i] != NULL)
            destroyEntry(hashTable[i]);

    delete(hashTable);
}


void openScope()
{
    Scope * newScope = (Scope *) new(sizeof(Scope));

    // newScope->negOffset = START_NEGATIVE_OFFSET;
    newScope->parent    = currentScope;
    newScope->entries   = NULL;

    if (currentScope == NULL)
        newScope->nestingLevel = 1;
    else
        newScope->nestingLevel = currentScope->nestingLevel + 1;

    currentScope = newScope;
}


void closeScope()
{
    SymbolEntry* e = currentScope->entries;
    Scope* t = currentScope;

    while (e != NULL) {
        SymbolEntry* next = e->nextInScope;

        hashTable[e->hashValue] = e->nextHash;
        destroyEntry(e);
        e = next;
    }

    currentScope = currentScope->parent;
    delete(t);
}


static void insertEntry(SymbolEntry * e)
{
    e->nextHash             = hashTable[e->hashValue];
    hashTable[e->hashValue] = e;
    e->nextInScope          = currentScope->entries;
    currentScope->entries   = e;
}


SymbolEntry * newEntry(const char * name, Type type)
{
    SymbolEntry * e;

    /* Έλεγχος αν υπάρχει ήδη */

    for (e = currentScope->entries; e != NULL; e = e->nextInScope)
        if (strcmp(name, e->id) == 0) {
            error("Duplicate identifier: %s", name);
            return NULL;
        }

    /* Αρχικοποίηση όλων εκτός: entryType και u */

    e = (SymbolEntry *) new(sizeof(SymbolEntry));
    e->id = (const char *) new(strlen(name) + 1);

    strcpy((char *) (e->id), name);
    e->hashValue    = PJW_hash(name) % hashTableSize;
    e->nestingLevel = currentScope->nestingLevel;
    e->type = type;

    if (type->kind == TYPE_ARRAY_CHAR) {
       
        e->u.arraySize = type->u.arraySize;
        int arraySize =e->u.arraySize;
        printf("Array size on insert: %d\n",arraySize);
        
    }
    insertEntry(e);
    return e;
}



void destroyEntry(SymbolEntry* e)
{
    SymbolEntry* args;
    
    /*
    switch (e->entryType) {
        case ENTRY_VARIABLE:
            destroyType(e->u.eVariable.type);
            break;
        case ENTRY_CONSTANT:
            if (e->u.eConstant.type->kind == TYPE_ARRAY)
                delete((char *) (e->u.eConstant.value.vString));
            destroyType(e->u.eConstant.type);
            break;
        case ENTRY_FUNCTION:
            args = e->u.eFunction.firstArgument;
            while (args != NULL) {
                SymbolEntry * p = args;

                destroyType(args->u.eParameter.type);
                delete((char *) (args->id));
                args = args->u.eParameter.next;
                delete(p);
            }
            destroyType(e->u.eFunction.resultType);
            break;
        case ENTRY_PARAMETER:
            return;
        case ENTRY_TEMPORARY:
            destroyType(e->u.eTemporary.type);
            break;
    } */
    delete((char *) (e->id));
    delete(e);
}


SymbolEntry* lookupEntry (const char * name, int err)
{
    unsigned int  hashValue = PJW_hash(name) % hashTableSize;
    SymbolEntry* e         = hashTable[hashValue];

    while (e != NULL)
        if (strcmp(e->id, name) == 0)
            return e;
        else
            e = e->nextHash;

    if (err)
        error("Unknown identifier: %s", name);
    return NULL;
}
