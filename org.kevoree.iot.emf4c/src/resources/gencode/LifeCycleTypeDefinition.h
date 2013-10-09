#ifndef H_LifeCycleTypeDefinition
#define H_LifeCycleTypeDefinition
 #include <stdlib.h>
 #include <stdio.h>
#include "DeployUnit.h"
#include "DictionaryType.h"
#include "TypeDefinition.h"

typedef struct _LifeCycleTypeDefinition { 
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
} LifeCycleTypeDefinition ;

#endif