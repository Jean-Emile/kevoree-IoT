#ifndef H_ContainerRoot
#define H_ContainerRoot
 #include <stdlib.h>
 #include <stdio.h>
#include "ContainerNode.h"
#include "TypeDefinition.h"
#include "Repository.h"
#include "TypedElement.h"
#include "TypeLibrary.h"
#include "Channel.h"
#include "MBinding.h"
#include "DeployUnit.h"
#include "NodeNetwork.h"
#include "Group.h"
#include "AdaptationPrimitiveType.h"

typedef struct _ContainerRoot { 
	int count_nodes;
	struct ContainerNode **nodes;
	int count_typeDefinitions;
	struct TypeDefinition **typeDefinitions;
	int count_repositories;
	struct Repository **repositories;
	int count_dataTypes;
	struct TypedElement **dataTypes;
	int count_libraries;
	struct TypeLibrary **libraries;
	int count_hubs;
	struct Channel **hubs;
	int count_mBindings;
	struct MBinding **mBindings;
	int count_deployUnits;
	struct DeployUnit **deployUnits;
	int count_nodeNetworks;
	struct NodeNetwork **nodeNetworks;
	int count_groups;
	struct Group **groups;
	int count_adaptationPrimitiveTypes;
	struct AdaptationPrimitiveType **adaptationPrimitiveTypes;
} ContainerRoot ;

#endif