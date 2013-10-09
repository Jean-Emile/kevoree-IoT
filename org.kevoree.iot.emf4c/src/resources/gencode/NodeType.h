#ifndef H_NodeType
#define H_NodeType
 #include <stdlib.h>
 #include <stdio.h>
#include "DeployUnit.h"
#include "DictionaryType.h"
#include "TypeDefinition.h"
#include "AdaptationPrimitiveType.h"
#include "AdaptationPrimitiveTypeRef.h"

typedef struct _NodeType { 
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
	int count_managedPrimitiveTypes;
	struct AdaptationPrimitiveType **managedPrimitiveTypes;
	int count_managedPrimitiveTypeRefs;
	struct AdaptationPrimitiveTypeRef **managedPrimitiveTypeRefs;
} NodeType ;

#endif