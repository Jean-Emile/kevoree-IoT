#ifndef H_DefaultFactory
#define H_DefaultFactory
#include "kevoree.h"

#include <stdlib.h>
struct ComponentInstance * createComponentInstance(void){
return (struct ComponentInstance*)malloc(sizeof(ComponentInstance));
}
void freeComponentInstance(void){
}
struct ComponentType * createComponentType(void){
return (struct ComponentType*)malloc(sizeof(ComponentType));
}
void freeComponentType(void){
}
struct ContainerNode * createContainerNode(void){
return (struct ContainerNode*)malloc(sizeof(ContainerNode));
}
void freeContainerNode(void){
}
struct ContainerRoot * createContainerRoot(void){
return (struct ContainerRoot*)malloc(sizeof(ContainerRoot));
}
void freeContainerRoot(void){
}
struct PortType * createPortType(void){
return (struct PortType*)malloc(sizeof(PortType));
}
void freePortType(void){
}
struct Port * createPort(void){
return (struct Port*)malloc(sizeof(Port));
}
void freePort(void){
}
struct Namespace * createNamespace(void){
return (struct Namespace*)malloc(sizeof(Namespace));
}
void freeNamespace(void){
}
struct Dictionary * createDictionary(void){
return (struct Dictionary*)malloc(sizeof(Dictionary));
}
void freeDictionary(void){
}
struct DictionaryType * createDictionaryType(void){
return (struct DictionaryType*)malloc(sizeof(DictionaryType));
}
void freeDictionaryType(void){
}
struct DictionaryAttribute * createDictionaryAttribute(void){
return (struct DictionaryAttribute*)malloc(sizeof(DictionaryAttribute));
}
void freeDictionaryAttribute(void){
}
struct DictionaryValue * createDictionaryValue(void){
return (struct DictionaryValue*)malloc(sizeof(DictionaryValue));
}
void freeDictionaryValue(void){
}
struct CompositeType * createCompositeType(void){
return (struct CompositeType*)malloc(sizeof(CompositeType));
}
void freeCompositeType(void){
}
struct PortTypeRef * createPortTypeRef(void){
return (struct PortTypeRef*)malloc(sizeof(PortTypeRef));
}
void freePortTypeRef(void){
}
struct Wire * createWire(void){
return (struct Wire*)malloc(sizeof(Wire));
}
void freeWire(void){
}
struct ServicePortType * createServicePortType(void){
return (struct ServicePortType*)malloc(sizeof(ServicePortType));
}
void freeServicePortType(void){
}
struct Operation * createOperation(void){
return (struct Operation*)malloc(sizeof(Operation));
}
void freeOperation(void){
}
struct Parameter * createParameter(void){
return (struct Parameter*)malloc(sizeof(Parameter));
}
void freeParameter(void){
}
struct TypedElement * createTypedElement(void){
return (struct TypedElement*)malloc(sizeof(TypedElement));
}
void freeTypedElement(void){
}
struct MessagePortType * createMessagePortType(void){
return (struct MessagePortType*)malloc(sizeof(MessagePortType));
}
void freeMessagePortType(void){
}
struct Repository * createRepository(void){
return (struct Repository*)malloc(sizeof(Repository));
}
void freeRepository(void){
}
struct DeployUnit * createDeployUnit(void){
return (struct DeployUnit*)malloc(sizeof(DeployUnit));
}
void freeDeployUnit(void){
}
struct TypeLibrary * createTypeLibrary(void){
return (struct TypeLibrary*)malloc(sizeof(TypeLibrary));
}
void freeTypeLibrary(void){
}
struct NamedElement * createNamedElement(void){
return (struct NamedElement*)malloc(sizeof(NamedElement));
}
void freeNamedElement(void){
}
struct IntegrationPattern * createIntegrationPattern(void){
return (struct IntegrationPattern*)malloc(sizeof(IntegrationPattern));
}
void freeIntegrationPattern(void){
}
struct ExtraFonctionalProperty * createExtraFonctionalProperty(void){
return (struct ExtraFonctionalProperty*)malloc(sizeof(ExtraFonctionalProperty));
}
void freeExtraFonctionalProperty(void){
}
struct PortTypeMapping * createPortTypeMapping(void){
return (struct PortTypeMapping*)malloc(sizeof(PortTypeMapping));
}
void freePortTypeMapping(void){
}
struct Channel * createChannel(void){
return (struct Channel*)malloc(sizeof(Channel));
}
void freeChannel(void){
}
struct MBinding * createMBinding(void){
return (struct MBinding*)malloc(sizeof(MBinding));
}
void freeMBinding(void){
}
struct NodeNetwork * createNodeNetwork(void){
return (struct NodeNetwork*)malloc(sizeof(NodeNetwork));
}
void freeNodeNetwork(void){
}
struct NodeLink * createNodeLink(void){
return (struct NodeLink*)malloc(sizeof(NodeLink));
}
void freeNodeLink(void){
}
struct NetworkProperty * createNetworkProperty(void){
return (struct NetworkProperty*)malloc(sizeof(NetworkProperty));
}
void freeNetworkProperty(void){
}
struct ChannelType * createChannelType(void){
return (struct ChannelType*)malloc(sizeof(ChannelType));
}
void freeChannelType(void){
}
struct TypeDefinition * createTypeDefinition(void){
return (struct TypeDefinition*)malloc(sizeof(TypeDefinition));
}
void freeTypeDefinition(void){
}
struct Instance * createInstance(void){
return (struct Instance*)malloc(sizeof(Instance));
}
void freeInstance(void){
}
struct LifeCycleTypeDefinition * createLifeCycleTypeDefinition(void){
return (struct LifeCycleTypeDefinition*)malloc(sizeof(LifeCycleTypeDefinition));
}
void freeLifeCycleTypeDefinition(void){
}
struct Group * createGroup(void){
return (struct Group*)malloc(sizeof(Group));
}
void freeGroup(void){
}
struct GroupType * createGroupType(void){
return (struct GroupType*)malloc(sizeof(GroupType));
}
void freeGroupType(void){
}
struct NodeType * createNodeType(void){
return (struct NodeType*)malloc(sizeof(NodeType));
}
void freeNodeType(void){
}
struct AdaptationPrimitiveType * createAdaptationPrimitiveType(void){
return (struct AdaptationPrimitiveType*)malloc(sizeof(AdaptationPrimitiveType));
}
void freeAdaptationPrimitiveType(void){
}
struct AdaptationPrimitiveTypeRef * createAdaptationPrimitiveTypeRef(void){
return (struct AdaptationPrimitiveTypeRef*)malloc(sizeof(AdaptationPrimitiveTypeRef));
}
void freeAdaptationPrimitiveTypeRef(void){
}

#endif