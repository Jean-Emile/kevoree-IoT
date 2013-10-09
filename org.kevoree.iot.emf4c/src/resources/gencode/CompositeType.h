#ifndef H_CompositeType
#define H_CompositeType
 #include <stdlib.h>
 #include <stdio.h>
#include "DeployUnit.h"
#include "DictionaryType.h"
#include "TypeDefinition.h"
#include "PortTypeRef.h"
#include "IntegrationPattern.h"
#include "ExtraFonctionalProperty.h"
#include "PortTypeRef.h"
#include "ComponentType.h"
#include "Wire.h"

typedef struct _CompositeType { 
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
	int count_childs;
	struct ComponentType **childs;
	int count_wires;
	struct Wire **wires;
} CompositeType ;

#endif