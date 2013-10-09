#ifndef H_ServicePortType
#define H_ServicePortType
 #include <stdlib.h>
 #include <stdio.h>
#include "DeployUnit.h"
#include "DictionaryType.h"
#include "TypeDefinition.h"
#include "Operation.h"

typedef struct _ServicePortType { 
	char * name;
	char * factoryBean;
	char * bean;
	short abstract;
	short synchrone;
	char * interface;
	int count_deployUnits;
	struct DeployUnit **deployUnits;
	struct DictionaryType *dictionaryType;
	int count_superTypes;
	struct TypeDefinition **superTypes;
	int count_operations;
	struct Operation **operations;
} ServicePortType ;

#endif