#ifndef H_MessagePortType
#define H_MessagePortType
 #include <stdlib.h>
 #include <stdio.h>
#include "DeployUnit.h"
#include "DictionaryType.h"
#include "TypeDefinition.h"
#include "TypedElement.h"

typedef struct _MessagePortType { 
	char * name;
	char * factoryBean;
	char * bean;
	short abstract;
	short synchrone;
	int count_deployUnits;
	struct DeployUnit **deployUnits;
	struct DictionaryType *dictionaryType;
	int count_superTypes;
	struct TypeDefinition **superTypes;
	int count_filters;
	struct TypedElement **filters;
} MessagePortType ;

#endif