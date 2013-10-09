#ifndef H_DictionaryType
#define H_DictionaryType
 #include <stdlib.h>
 #include <stdio.h>
#include "DictionaryAttribute.h"
#include "DictionaryValue.h"

typedef struct _DictionaryType { 
	int count_attributes;
	struct DictionaryAttribute **attributes;
	int count_defaultValues;
	struct DictionaryValue **defaultValues;
} DictionaryType ;

#endif