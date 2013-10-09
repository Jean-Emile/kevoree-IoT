#ifndef H_TypeDefinition
#define H_TypeDefinition
 #include <stdlib.h>
 #include <stdio.h>
#include "DeployUnit.h"
#include "DictionaryType.h"
#include "TypeDefinition.h"

typedef struct _TypeDefinition { 
	char * name;
	char * factoryBean;
	char * bean;
	short abstract;
	int count_deployUnits;
	struct DeployUnit **deployUnits;
	struct DictionaryType *dictionaryType;
	int count_superTypes;
	struct TypeDefinition **superTypes;
} TypeDefinition ;

#endif