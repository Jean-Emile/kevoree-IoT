#ifndef H_Dictionary
#define H_Dictionary
 #include <stdlib.h>
 #include <stdio.h>
#include "DictionaryValue.h"

typedef struct _Dictionary { 
	int count_values;
	struct DictionaryValue **values;
} Dictionary ;

#endif