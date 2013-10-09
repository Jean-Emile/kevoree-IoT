#ifndef H_DictionaryAttribute
#define H_DictionaryAttribute
 #include <stdlib.h>
 #include <stdio.h>
#include "TypedElement.h"

typedef struct _DictionaryAttribute { 
	char * name;
	short optional;
	short state;
	char * datatype;
	short fragmentDependant;
	int count_genericTypes;
	struct TypedElement **genericTypes;
} DictionaryAttribute ;

#endif