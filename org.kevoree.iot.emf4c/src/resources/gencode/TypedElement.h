#ifndef H_TypedElement
#define H_TypedElement
 #include <stdlib.h>
 #include <stdio.h>
#include "TypedElement.h"

typedef struct _TypedElement { 
	char * name;
	int count_genericTypes;
	struct TypedElement **genericTypes;
} TypedElement ;

#endif