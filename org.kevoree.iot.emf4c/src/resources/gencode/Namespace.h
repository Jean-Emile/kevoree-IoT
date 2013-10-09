#ifndef H_Namespace
#define H_Namespace
 #include <stdlib.h>
 #include <stdio.h>
#include "Namespace.h"
#include "Namespace.h"

typedef struct _Namespace { 
	char * name;
	int count_childs;
	struct Namespace **childs;
	struct Namespace *parent;
} Namespace ;

#endif