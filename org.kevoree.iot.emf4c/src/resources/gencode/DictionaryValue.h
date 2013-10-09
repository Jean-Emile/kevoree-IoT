#ifndef H_DictionaryValue
#define H_DictionaryValue
 #include <stdlib.h>
 #include <stdio.h>
#include "DictionaryAttribute.h"
#include "ContainerNode.h"

typedef struct _DictionaryValue { 
	char * value;
	struct DictionaryAttribute *attribute;
	struct ContainerNode *targetNode;
} DictionaryValue ;

#endif