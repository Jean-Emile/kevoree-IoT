#ifndef H_ComponentType
#define H_ComponentType
 #include <stdlib.h>
 #include <stdio.h>
#include "DeployUnit.h"
#include "DictionaryType.h"
#include "TypeDefinition.h"
#include "PortTypeRef.h"
#include "IntegrationPattern.h"
#include "ExtraFonctionalProperty.h"
#include "PortTypeRef.h"

typedef struct _ComponentType { 
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
	int count_required;
	struct PortTypeRef **required;
	int count_integrationPatterns;
	struct IntegrationPattern **integrationPatterns;
	struct ExtraFonctionalProperty *extraFonctionalProperties;
	int count_provided;
	struct PortTypeRef **provided;
} ComponentType ;

#endif