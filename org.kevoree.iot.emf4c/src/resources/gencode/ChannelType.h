#ifndef H_ChannelType
#define H_ChannelType
 #include <stdlib.h>
 #include <stdio.h>
#include "DeployUnit.h"
#include "DictionaryType.h"
#include "TypeDefinition.h"

typedef struct _ChannelType { 
	char * name;
	char * factoryBean;
	char * bean;
	short abstract;
	char * startMethod;
	char * stopMethod;
	char * updateMethod;
	int lowerBindings;
	int upperBindings;
	int lowerFragments;
	int upperFragments;
	int count_deployUnits;
	struct DeployUnit **deployUnits;
	struct DictionaryType *dictionaryType;
	int count_superTypes;
	struct TypeDefinition **superTypes;
} ChannelType ;

#endif