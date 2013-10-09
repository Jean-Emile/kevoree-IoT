#ifndef H_GroupType
#define H_GroupType
 #include <stdlib.h>
 #include <stdio.h>
#include "DeployUnit.h"
#include "DictionaryType.h"
#include "TypeDefinition.h"

typedef struct _GroupType { 
	char * name;
	char * factoryBean;
	char * bean;
	short abstract;
	char * startMethod;
	char * stopMethod;
	char * updateMethod;
	int count_deployUnits;
	struct DeployUnit **deployUnits;
	struct DictionaryType *dictionaryType;
	int count_superTypes;
	struct TypeDefinition **superTypes;
} GroupType ;

#endif