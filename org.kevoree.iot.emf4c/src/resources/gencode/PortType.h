#ifndef H_PortType
#define H_PortType
 #include <stdlib.h>
 #include <stdio.h>
#include "DeployUnit.h"
#include "DictionaryType.h"
#include "TypeDefinition.h"

typedef struct _PortType { 
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
} PortType ;

#endif