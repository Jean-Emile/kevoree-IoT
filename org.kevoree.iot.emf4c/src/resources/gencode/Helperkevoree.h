void addprovidedComponentInstance(ComponentInstance*root,Port *val){
if(root->provided== NULL){
root->count_provided=0;
root->provided = malloc(sizeof(Port*));
root->provided[0] =(Port*)val;
root->count_provided++;
} else {
root->provided = realloc(root->provided,(root->count_provided+1)*sizeof(Port*));
root->provided[root->count_provided] =(Port*)val;root->count_provided++;
}}
void addrequiredComponentInstance(ComponentInstance*root,Port *val){
if(root->required== NULL){
root->count_required=0;
root->required = malloc(sizeof(Port*));
root->required[0] =(Port*)val;
root->count_required++;
} else {
root->required = realloc(root->required,(root->count_required+1)*sizeof(Port*));
root->required[root->count_required] =(Port*)val;root->count_required++;
}}
void adddeployUnitsComponentType(ComponentType*root,DeployUnit *val){
if(root->deployUnits== NULL){
root->count_deployUnits=0;
root->deployUnits = malloc(sizeof(DeployUnit*));
root->deployUnits[0] =(DeployUnit*)val;
root->count_deployUnits++;
} else {
root->deployUnits = realloc(root->deployUnits,(root->count_deployUnits+1)*sizeof(DeployUnit*));
root->deployUnits[root->count_deployUnits] =(DeployUnit*)val;root->count_deployUnits++;
}}
void addsuperTypesComponentType(ComponentType*root,TypeDefinition *val){
if(root->superTypes== NULL){
root->count_superTypes=0;
root->superTypes = malloc(sizeof(TypeDefinition*));
root->superTypes[0] =(TypeDefinition*)val;
root->count_superTypes++;
} else {
root->superTypes = realloc(root->superTypes,(root->count_superTypes+1)*sizeof(TypeDefinition*));
root->superTypes[root->count_superTypes] =(TypeDefinition*)val;root->count_superTypes++;
}}
void addrequiredComponentType(ComponentType*root,PortTypeRef *val){
if(root->required== NULL){
root->count_required=0;
root->required = malloc(sizeof(PortTypeRef*));
root->required[0] =(PortTypeRef*)val;
root->count_required++;
} else {
root->required = realloc(root->required,(root->count_required+1)*sizeof(PortTypeRef*));
root->required[root->count_required] =(PortTypeRef*)val;root->count_required++;
}}
void addintegrationPatternsComponentType(ComponentType*root,IntegrationPattern *val){
if(root->integrationPatterns== NULL){
root->count_integrationPatterns=0;
root->integrationPatterns = malloc(sizeof(IntegrationPattern*));
root->integrationPatterns[0] =(IntegrationPattern*)val;
root->count_integrationPatterns++;
} else {
root->integrationPatterns = realloc(root->integrationPatterns,(root->count_integrationPatterns+1)*sizeof(IntegrationPattern*));
root->integrationPatterns[root->count_integrationPatterns] =(IntegrationPattern*)val;root->count_integrationPatterns++;
}}
void addprovidedComponentType(ComponentType*root,PortTypeRef *val){
if(root->provided== NULL){
root->count_provided=0;
root->provided = malloc(sizeof(PortTypeRef*));
root->provided[0] =(PortTypeRef*)val;
root->count_provided++;
} else {
root->provided = realloc(root->provided,(root->count_provided+1)*sizeof(PortTypeRef*));
root->provided[root->count_provided] =(PortTypeRef*)val;root->count_provided++;
}}
void addcomponentsContainerNode(ContainerNode*root,ComponentInstance *val){
if(root->components== NULL){
root->count_components=0;
root->components = malloc(sizeof(ComponentInstance*));
root->components[0] =(ComponentInstance*)val;
root->count_components++;
} else {
root->components = realloc(root->components,(root->count_components+1)*sizeof(ComponentInstance*));
root->components[root->count_components] =(ComponentInstance*)val;root->count_components++;
}}
void addhostsContainerNode(ContainerNode*root,ContainerNode *val){
if(root->hosts== NULL){
root->count_hosts=0;
root->hosts = malloc(sizeof(ContainerNode*));
root->hosts[0] =(ContainerNode*)val;
root->count_hosts++;
} else {
root->hosts = realloc(root->hosts,(root->count_hosts+1)*sizeof(ContainerNode*));
root->hosts[root->count_hosts] =(ContainerNode*)val;root->count_hosts++;
}}
void addnodesContainerRoot(ContainerRoot*root,ContainerNode *val){
if(root->nodes== NULL){
root->count_nodes=0;
root->nodes = malloc(sizeof(ContainerNode*));
root->nodes[0] =(ContainerNode*)val;
root->count_nodes++;
} else {
root->nodes = realloc(root->nodes,(root->count_nodes+1)*sizeof(ContainerNode*));
root->nodes[root->count_nodes] =(ContainerNode*)val;root->count_nodes++;
}}
void addtypeDefinitionsContainerRoot(ContainerRoot*root,TypeDefinition *val){
if(root->typeDefinitions== NULL){
root->count_typeDefinitions=0;
root->typeDefinitions = malloc(sizeof(TypeDefinition*));
root->typeDefinitions[0] =(TypeDefinition*)val;
root->count_typeDefinitions++;
} else {
root->typeDefinitions = realloc(root->typeDefinitions,(root->count_typeDefinitions+1)*sizeof(TypeDefinition*));
root->typeDefinitions[root->count_typeDefinitions] =(TypeDefinition*)val;root->count_typeDefinitions++;
}}
void addrepositoriesContainerRoot(ContainerRoot*root,Repository *val){
if(root->repositories== NULL){
root->count_repositories=0;
root->repositories = malloc(sizeof(Repository*));
root->repositories[0] =(Repository*)val;
root->count_repositories++;
} else {
root->repositories = realloc(root->repositories,(root->count_repositories+1)*sizeof(Repository*));
root->repositories[root->count_repositories] =(Repository*)val;root->count_repositories++;
}}
void adddataTypesContainerRoot(ContainerRoot*root,TypedElement *val){
if(root->dataTypes== NULL){
root->count_dataTypes=0;
root->dataTypes = malloc(sizeof(TypedElement*));
root->dataTypes[0] =(TypedElement*)val;
root->count_dataTypes++;
} else {
root->dataTypes = realloc(root->dataTypes,(root->count_dataTypes+1)*sizeof(TypedElement*));
root->dataTypes[root->count_dataTypes] =(TypedElement*)val;root->count_dataTypes++;
}}
void addlibrariesContainerRoot(ContainerRoot*root,TypeLibrary *val){
if(root->libraries== NULL){
root->count_libraries=0;
root->libraries = malloc(sizeof(TypeLibrary*));
root->libraries[0] =(TypeLibrary*)val;
root->count_libraries++;
} else {
root->libraries = realloc(root->libraries,(root->count_libraries+1)*sizeof(TypeLibrary*));
root->libraries[root->count_libraries] =(TypeLibrary*)val;root->count_libraries++;
}}
void addhubsContainerRoot(ContainerRoot*root,Channel *val){
if(root->hubs== NULL){
root->count_hubs=0;
root->hubs = malloc(sizeof(Channel*));
root->hubs[0] =(Channel*)val;
root->count_hubs++;
} else {
root->hubs = realloc(root->hubs,(root->count_hubs+1)*sizeof(Channel*));
root->hubs[root->count_hubs] =(Channel*)val;root->count_hubs++;
}}
void addmBindingsContainerRoot(ContainerRoot*root,MBinding *val){
if(root->mBindings== NULL){
root->count_mBindings=0;
root->mBindings = malloc(sizeof(MBinding*));
root->mBindings[0] =(MBinding*)val;
root->count_mBindings++;
} else {
root->mBindings = realloc(root->mBindings,(root->count_mBindings+1)*sizeof(MBinding*));
root->mBindings[root->count_mBindings] =(MBinding*)val;root->count_mBindings++;
}}
void adddeployUnitsContainerRoot(ContainerRoot*root,DeployUnit *val){
if(root->deployUnits== NULL){
root->count_deployUnits=0;
root->deployUnits = malloc(sizeof(DeployUnit*));
root->deployUnits[0] =(DeployUnit*)val;
root->count_deployUnits++;
} else {
root->deployUnits = realloc(root->deployUnits,(root->count_deployUnits+1)*sizeof(DeployUnit*));
root->deployUnits[root->count_deployUnits] =(DeployUnit*)val;root->count_deployUnits++;
}}
void addnodeNetworksContainerRoot(ContainerRoot*root,NodeNetwork *val){
if(root->nodeNetworks== NULL){
root->count_nodeNetworks=0;
root->nodeNetworks = malloc(sizeof(NodeNetwork*));
root->nodeNetworks[0] =(NodeNetwork*)val;
root->count_nodeNetworks++;
} else {
root->nodeNetworks = realloc(root->nodeNetworks,(root->count_nodeNetworks+1)*sizeof(NodeNetwork*));
root->nodeNetworks[root->count_nodeNetworks] =(NodeNetwork*)val;root->count_nodeNetworks++;
}}
void addgroupsContainerRoot(ContainerRoot*root,Group *val){
if(root->groups== NULL){
root->count_groups=0;
root->groups = malloc(sizeof(Group*));
root->groups[0] =(Group*)val;
root->count_groups++;
} else {
root->groups = realloc(root->groups,(root->count_groups+1)*sizeof(Group*));
root->groups[root->count_groups] =(Group*)val;root->count_groups++;
}}
void addadaptationPrimitiveTypesContainerRoot(ContainerRoot*root,AdaptationPrimitiveType *val){
if(root->adaptationPrimitiveTypes== NULL){
root->count_adaptationPrimitiveTypes=0;
root->adaptationPrimitiveTypes = malloc(sizeof(AdaptationPrimitiveType*));
root->adaptationPrimitiveTypes[0] =(AdaptationPrimitiveType*)val;
root->count_adaptationPrimitiveTypes++;
} else {
root->adaptationPrimitiveTypes = realloc(root->adaptationPrimitiveTypes,(root->count_adaptationPrimitiveTypes+1)*sizeof(AdaptationPrimitiveType*));
root->adaptationPrimitiveTypes[root->count_adaptationPrimitiveTypes] =(AdaptationPrimitiveType*)val;root->count_adaptationPrimitiveTypes++;
}}
void adddeployUnitsPortType(PortType*root,DeployUnit *val){
if(root->deployUnits== NULL){
root->count_deployUnits=0;
root->deployUnits = malloc(sizeof(DeployUnit*));
root->deployUnits[0] =(DeployUnit*)val;
root->count_deployUnits++;
} else {
root->deployUnits = realloc(root->deployUnits,(root->count_deployUnits+1)*sizeof(DeployUnit*));
root->deployUnits[root->count_deployUnits] =(DeployUnit*)val;root->count_deployUnits++;
}}
void addsuperTypesPortType(PortType*root,TypeDefinition *val){
if(root->superTypes== NULL){
root->count_superTypes=0;
root->superTypes = malloc(sizeof(TypeDefinition*));
root->superTypes[0] =(TypeDefinition*)val;
root->count_superTypes++;
} else {
root->superTypes = realloc(root->superTypes,(root->count_superTypes+1)*sizeof(TypeDefinition*));
root->superTypes[root->count_superTypes] =(TypeDefinition*)val;root->count_superTypes++;
}}
void addbindingsPort(Port*root,MBinding *val){
if(root->bindings== NULL){
root->count_bindings=0;
root->bindings = malloc(sizeof(MBinding*));
root->bindings[0] =(MBinding*)val;
root->count_bindings++;
} else {
root->bindings = realloc(root->bindings,(root->count_bindings+1)*sizeof(MBinding*));
root->bindings[root->count_bindings] =(MBinding*)val;root->count_bindings++;
}}
void addchildsNamespace(Namespace*root,Namespace *val){
if(root->childs== NULL){
root->count_childs=0;
root->childs = malloc(sizeof(Namespace*));
root->childs[0] =(Namespace*)val;
root->count_childs++;
} else {
root->childs = realloc(root->childs,(root->count_childs+1)*sizeof(Namespace*));
root->childs[root->count_childs] =(Namespace*)val;root->count_childs++;
}}
void addvaluesDictionary(Dictionary*root,DictionaryValue *val){
if(root->values== NULL){
root->count_values=0;
root->values = malloc(sizeof(DictionaryValue*));
root->values[0] =(DictionaryValue*)val;
root->count_values++;
} else {
root->values = realloc(root->values,(root->count_values+1)*sizeof(DictionaryValue*));
root->values[root->count_values] =(DictionaryValue*)val;root->count_values++;
}}
void addattributesDictionaryType(DictionaryType*root,DictionaryAttribute *val){
if(root->attributes== NULL){
root->count_attributes=0;
root->attributes = malloc(sizeof(DictionaryAttribute*));
root->attributes[0] =(DictionaryAttribute*)val;
root->count_attributes++;
} else {
root->attributes = realloc(root->attributes,(root->count_attributes+1)*sizeof(DictionaryAttribute*));
root->attributes[root->count_attributes] =(DictionaryAttribute*)val;root->count_attributes++;
}}
void adddefaultValuesDictionaryType(DictionaryType*root,DictionaryValue *val){
if(root->defaultValues== NULL){
root->count_defaultValues=0;
root->defaultValues = malloc(sizeof(DictionaryValue*));
root->defaultValues[0] =(DictionaryValue*)val;
root->count_defaultValues++;
} else {
root->defaultValues = realloc(root->defaultValues,(root->count_defaultValues+1)*sizeof(DictionaryValue*));
root->defaultValues[root->count_defaultValues] =(DictionaryValue*)val;root->count_defaultValues++;
}}
void addgenericTypesDictionaryAttribute(DictionaryAttribute*root,TypedElement *val){
if(root->genericTypes== NULL){
root->count_genericTypes=0;
root->genericTypes = malloc(sizeof(TypedElement*));
root->genericTypes[0] =(TypedElement*)val;
root->count_genericTypes++;
} else {
root->genericTypes = realloc(root->genericTypes,(root->count_genericTypes+1)*sizeof(TypedElement*));
root->genericTypes[root->count_genericTypes] =(TypedElement*)val;root->count_genericTypes++;
}}
void adddeployUnitsCompositeType(CompositeType*root,DeployUnit *val){
if(root->deployUnits== NULL){
root->count_deployUnits=0;
root->deployUnits = malloc(sizeof(DeployUnit*));
root->deployUnits[0] =(DeployUnit*)val;
root->count_deployUnits++;
} else {
root->deployUnits = realloc(root->deployUnits,(root->count_deployUnits+1)*sizeof(DeployUnit*));
root->deployUnits[root->count_deployUnits] =(DeployUnit*)val;root->count_deployUnits++;
}}
void addsuperTypesCompositeType(CompositeType*root,TypeDefinition *val){
if(root->superTypes== NULL){
root->count_superTypes=0;
root->superTypes = malloc(sizeof(TypeDefinition*));
root->superTypes[0] =(TypeDefinition*)val;
root->count_superTypes++;
} else {
root->superTypes = realloc(root->superTypes,(root->count_superTypes+1)*sizeof(TypeDefinition*));
root->superTypes[root->count_superTypes] =(TypeDefinition*)val;root->count_superTypes++;
}}
void addrequiredCompositeType(CompositeType*root,PortTypeRef *val){
if(root->required== NULL){
root->count_required=0;
root->required = malloc(sizeof(PortTypeRef*));
root->required[0] =(PortTypeRef*)val;
root->count_required++;
} else {
root->required = realloc(root->required,(root->count_required+1)*sizeof(PortTypeRef*));
root->required[root->count_required] =(PortTypeRef*)val;root->count_required++;
}}
void addintegrationPatternsCompositeType(CompositeType*root,IntegrationPattern *val){
if(root->integrationPatterns== NULL){
root->count_integrationPatterns=0;
root->integrationPatterns = malloc(sizeof(IntegrationPattern*));
root->integrationPatterns[0] =(IntegrationPattern*)val;
root->count_integrationPatterns++;
} else {
root->integrationPatterns = realloc(root->integrationPatterns,(root->count_integrationPatterns+1)*sizeof(IntegrationPattern*));
root->integrationPatterns[root->count_integrationPatterns] =(IntegrationPattern*)val;root->count_integrationPatterns++;
}}
void addprovidedCompositeType(CompositeType*root,PortTypeRef *val){
if(root->provided== NULL){
root->count_provided=0;
root->provided = malloc(sizeof(PortTypeRef*));
root->provided[0] =(PortTypeRef*)val;
root->count_provided++;
} else {
root->provided = realloc(root->provided,(root->count_provided+1)*sizeof(PortTypeRef*));
root->provided[root->count_provided] =(PortTypeRef*)val;root->count_provided++;
}}
void addchildsCompositeType(CompositeType*root,ComponentType *val){
if(root->childs== NULL){
root->count_childs=0;
root->childs = malloc(sizeof(ComponentType*));
root->childs[0] =(ComponentType*)val;
root->count_childs++;
} else {
root->childs = realloc(root->childs,(root->count_childs+1)*sizeof(ComponentType*));
root->childs[root->count_childs] =(ComponentType*)val;root->count_childs++;
}}
void addwiresCompositeType(CompositeType*root,Wire *val){
if(root->wires== NULL){
root->count_wires=0;
root->wires = malloc(sizeof(Wire*));
root->wires[0] =(Wire*)val;
root->count_wires++;
} else {
root->wires = realloc(root->wires,(root->count_wires+1)*sizeof(Wire*));
root->wires[root->count_wires] =(Wire*)val;root->count_wires++;
}}
void addmappingsPortTypeRef(PortTypeRef*root,PortTypeMapping *val){
if(root->mappings== NULL){
root->count_mappings=0;
root->mappings = malloc(sizeof(PortTypeMapping*));
root->mappings[0] =(PortTypeMapping*)val;
root->count_mappings++;
} else {
root->mappings = realloc(root->mappings,(root->count_mappings+1)*sizeof(PortTypeMapping*));
root->mappings[root->count_mappings] =(PortTypeMapping*)val;root->count_mappings++;
}}
void adddeployUnitsServicePortType(ServicePortType*root,DeployUnit *val){
if(root->deployUnits== NULL){
root->count_deployUnits=0;
root->deployUnits = malloc(sizeof(DeployUnit*));
root->deployUnits[0] =(DeployUnit*)val;
root->count_deployUnits++;
} else {
root->deployUnits = realloc(root->deployUnits,(root->count_deployUnits+1)*sizeof(DeployUnit*));
root->deployUnits[root->count_deployUnits] =(DeployUnit*)val;root->count_deployUnits++;
}}
void addsuperTypesServicePortType(ServicePortType*root,TypeDefinition *val){
if(root->superTypes== NULL){
root->count_superTypes=0;
root->superTypes = malloc(sizeof(TypeDefinition*));
root->superTypes[0] =(TypeDefinition*)val;
root->count_superTypes++;
} else {
root->superTypes = realloc(root->superTypes,(root->count_superTypes+1)*sizeof(TypeDefinition*));
root->superTypes[root->count_superTypes] =(TypeDefinition*)val;root->count_superTypes++;
}}
void addoperationsServicePortType(ServicePortType*root,Operation *val){
if(root->operations== NULL){
root->count_operations=0;
root->operations = malloc(sizeof(Operation*));
root->operations[0] =(Operation*)val;
root->count_operations++;
} else {
root->operations = realloc(root->operations,(root->count_operations+1)*sizeof(Operation*));
root->operations[root->count_operations] =(Operation*)val;root->count_operations++;
}}
void addparametersOperation(Operation*root,Parameter *val){
if(root->parameters== NULL){
root->count_parameters=0;
root->parameters = malloc(sizeof(Parameter*));
root->parameters[0] =(Parameter*)val;
root->count_parameters++;
} else {
root->parameters = realloc(root->parameters,(root->count_parameters+1)*sizeof(Parameter*));
root->parameters[root->count_parameters] =(Parameter*)val;root->count_parameters++;
}}
void addgenericTypesTypedElement(TypedElement*root,TypedElement *val){
if(root->genericTypes== NULL){
root->count_genericTypes=0;
root->genericTypes = malloc(sizeof(TypedElement*));
root->genericTypes[0] =(TypedElement*)val;
root->count_genericTypes++;
} else {
root->genericTypes = realloc(root->genericTypes,(root->count_genericTypes+1)*sizeof(TypedElement*));
root->genericTypes[root->count_genericTypes] =(TypedElement*)val;root->count_genericTypes++;
}}
void adddeployUnitsMessagePortType(MessagePortType*root,DeployUnit *val){
if(root->deployUnits== NULL){
root->count_deployUnits=0;
root->deployUnits = malloc(sizeof(DeployUnit*));
root->deployUnits[0] =(DeployUnit*)val;
root->count_deployUnits++;
} else {
root->deployUnits = realloc(root->deployUnits,(root->count_deployUnits+1)*sizeof(DeployUnit*));
root->deployUnits[root->count_deployUnits] =(DeployUnit*)val;root->count_deployUnits++;
}}
void addsuperTypesMessagePortType(MessagePortType*root,TypeDefinition *val){
if(root->superTypes== NULL){
root->count_superTypes=0;
root->superTypes = malloc(sizeof(TypeDefinition*));
root->superTypes[0] =(TypeDefinition*)val;
root->count_superTypes++;
} else {
root->superTypes = realloc(root->superTypes,(root->count_superTypes+1)*sizeof(TypeDefinition*));
root->superTypes[root->count_superTypes] =(TypeDefinition*)val;root->count_superTypes++;
}}
void addfiltersMessagePortType(MessagePortType*root,TypedElement *val){
if(root->filters== NULL){
root->count_filters=0;
root->filters = malloc(sizeof(TypedElement*));
root->filters[0] =(TypedElement*)val;
root->count_filters++;
} else {
root->filters = realloc(root->filters,(root->count_filters+1)*sizeof(TypedElement*));
root->filters[root->count_filters] =(TypedElement*)val;root->count_filters++;
}}
void addunitsRepository(Repository*root,DeployUnit *val){
if(root->units== NULL){
root->count_units=0;
root->units = malloc(sizeof(DeployUnit*));
root->units[0] =(DeployUnit*)val;
root->count_units++;
} else {
root->units = realloc(root->units,(root->count_units+1)*sizeof(DeployUnit*));
root->units[root->count_units] =(DeployUnit*)val;root->count_units++;
}}
void addrequiredLibsDeployUnit(DeployUnit*root,DeployUnit *val){
if(root->requiredLibs== NULL){
root->count_requiredLibs=0;
root->requiredLibs = malloc(sizeof(DeployUnit*));
root->requiredLibs[0] =(DeployUnit*)val;
root->count_requiredLibs++;
} else {
root->requiredLibs = realloc(root->requiredLibs,(root->count_requiredLibs+1)*sizeof(DeployUnit*));
root->requiredLibs[root->count_requiredLibs] =(DeployUnit*)val;root->count_requiredLibs++;
}}
void addsubTypesTypeLibrary(TypeLibrary*root,TypeDefinition *val){
if(root->subTypes== NULL){
root->count_subTypes=0;
root->subTypes = malloc(sizeof(TypeDefinition*));
root->subTypes[0] =(TypeDefinition*)val;
root->count_subTypes++;
} else {
root->subTypes = realloc(root->subTypes,(root->count_subTypes+1)*sizeof(TypeDefinition*));
root->subTypes[root->count_subTypes] =(TypeDefinition*)val;root->count_subTypes++;
}}
void addextraFonctionalPropertiesIntegrationPattern(IntegrationPattern*root,ExtraFonctionalProperty *val){
if(root->extraFonctionalProperties== NULL){
root->count_extraFonctionalProperties=0;
root->extraFonctionalProperties = malloc(sizeof(ExtraFonctionalProperty*));
root->extraFonctionalProperties[0] =(ExtraFonctionalProperty*)val;
root->count_extraFonctionalProperties++;
} else {
root->extraFonctionalProperties = realloc(root->extraFonctionalProperties,(root->count_extraFonctionalProperties+1)*sizeof(ExtraFonctionalProperty*));
root->extraFonctionalProperties[root->count_extraFonctionalProperties] =(ExtraFonctionalProperty*)val;root->count_extraFonctionalProperties++;
}}
void addportTypesIntegrationPattern(IntegrationPattern*root,PortTypeRef *val){
if(root->portTypes== NULL){
root->count_portTypes=0;
root->portTypes = malloc(sizeof(PortTypeRef*));
root->portTypes[0] =(PortTypeRef*)val;
root->count_portTypes++;
} else {
root->portTypes = realloc(root->portTypes,(root->count_portTypes+1)*sizeof(PortTypeRef*));
root->portTypes[root->count_portTypes] =(PortTypeRef*)val;root->count_portTypes++;
}}
void addportTypesExtraFonctionalProperty(ExtraFonctionalProperty*root,PortTypeRef *val){
if(root->portTypes== NULL){
root->count_portTypes=0;
root->portTypes = malloc(sizeof(PortTypeRef*));
root->portTypes[0] =(PortTypeRef*)val;
root->count_portTypes++;
} else {
root->portTypes = realloc(root->portTypes,(root->count_portTypes+1)*sizeof(PortTypeRef*));
root->portTypes[root->count_portTypes] =(PortTypeRef*)val;root->count_portTypes++;
}}
void addbindingsChannel(Channel*root,MBinding *val){
if(root->bindings== NULL){
root->count_bindings=0;
root->bindings = malloc(sizeof(MBinding*));
root->bindings[0] =(MBinding*)val;
root->count_bindings++;
} else {
root->bindings = realloc(root->bindings,(root->count_bindings+1)*sizeof(MBinding*));
root->bindings[root->count_bindings] =(MBinding*)val;root->count_bindings++;
}}
void addlinkNodeNetwork(NodeNetwork*root,NodeLink *val){
if(root->link== NULL){
root->count_link=0;
root->link = malloc(sizeof(NodeLink*));
root->link[0] =(NodeLink*)val;
root->count_link++;
} else {
root->link = realloc(root->link,(root->count_link+1)*sizeof(NodeLink*));
root->link[root->count_link] =(NodeLink*)val;root->count_link++;
}}
void addnetworkPropertiesNodeLink(NodeLink*root,NetworkProperty *val){
if(root->networkProperties== NULL){
root->count_networkProperties=0;
root->networkProperties = malloc(sizeof(NetworkProperty*));
root->networkProperties[0] =(NetworkProperty*)val;
root->count_networkProperties++;
} else {
root->networkProperties = realloc(root->networkProperties,(root->count_networkProperties+1)*sizeof(NetworkProperty*));
root->networkProperties[root->count_networkProperties] =(NetworkProperty*)val;root->count_networkProperties++;
}}
void adddeployUnitsChannelType(ChannelType*root,DeployUnit *val){
if(root->deployUnits== NULL){
root->count_deployUnits=0;
root->deployUnits = malloc(sizeof(DeployUnit*));
root->deployUnits[0] =(DeployUnit*)val;
root->count_deployUnits++;
} else {
root->deployUnits = realloc(root->deployUnits,(root->count_deployUnits+1)*sizeof(DeployUnit*));
root->deployUnits[root->count_deployUnits] =(DeployUnit*)val;root->count_deployUnits++;
}}
void addsuperTypesChannelType(ChannelType*root,TypeDefinition *val){
if(root->superTypes== NULL){
root->count_superTypes=0;
root->superTypes = malloc(sizeof(TypeDefinition*));
root->superTypes[0] =(TypeDefinition*)val;
root->count_superTypes++;
} else {
root->superTypes = realloc(root->superTypes,(root->count_superTypes+1)*sizeof(TypeDefinition*));
root->superTypes[root->count_superTypes] =(TypeDefinition*)val;root->count_superTypes++;
}}
void adddeployUnitsTypeDefinition(TypeDefinition*root,DeployUnit *val){
if(root->deployUnits== NULL){
root->count_deployUnits=0;
root->deployUnits = malloc(sizeof(DeployUnit*));
root->deployUnits[0] =(DeployUnit*)val;
root->count_deployUnits++;
} else {
root->deployUnits = realloc(root->deployUnits,(root->count_deployUnits+1)*sizeof(DeployUnit*));
root->deployUnits[root->count_deployUnits] =(DeployUnit*)val;root->count_deployUnits++;
}}
void addsuperTypesTypeDefinition(TypeDefinition*root,TypeDefinition *val){
if(root->superTypes== NULL){
root->count_superTypes=0;
root->superTypes = malloc(sizeof(TypeDefinition*));
root->superTypes[0] =(TypeDefinition*)val;
root->count_superTypes++;
} else {
root->superTypes = realloc(root->superTypes,(root->count_superTypes+1)*sizeof(TypeDefinition*));
root->superTypes[root->count_superTypes] =(TypeDefinition*)val;root->count_superTypes++;
}}
void adddeployUnitsLifeCycleTypeDefinition(LifeCycleTypeDefinition*root,DeployUnit *val){
if(root->deployUnits== NULL){
root->count_deployUnits=0;
root->deployUnits = malloc(sizeof(DeployUnit*));
root->deployUnits[0] =(DeployUnit*)val;
root->count_deployUnits++;
} else {
root->deployUnits = realloc(root->deployUnits,(root->count_deployUnits+1)*sizeof(DeployUnit*));
root->deployUnits[root->count_deployUnits] =(DeployUnit*)val;root->count_deployUnits++;
}}
void addsuperTypesLifeCycleTypeDefinition(LifeCycleTypeDefinition*root,TypeDefinition *val){
if(root->superTypes== NULL){
root->count_superTypes=0;
root->superTypes = malloc(sizeof(TypeDefinition*));
root->superTypes[0] =(TypeDefinition*)val;
root->count_superTypes++;
} else {
root->superTypes = realloc(root->superTypes,(root->count_superTypes+1)*sizeof(TypeDefinition*));
root->superTypes[root->count_superTypes] =(TypeDefinition*)val;root->count_superTypes++;
}}
void addsubNodesGroup(Group*root,ContainerNode *val){
if(root->subNodes== NULL){
root->count_subNodes=0;
root->subNodes = malloc(sizeof(ContainerNode*));
root->subNodes[0] =(ContainerNode*)val;
root->count_subNodes++;
} else {
root->subNodes = realloc(root->subNodes,(root->count_subNodes+1)*sizeof(ContainerNode*));
root->subNodes[root->count_subNodes] =(ContainerNode*)val;root->count_subNodes++;
}}
void adddeployUnitsGroupType(GroupType*root,DeployUnit *val){
if(root->deployUnits== NULL){
root->count_deployUnits=0;
root->deployUnits = malloc(sizeof(DeployUnit*));
root->deployUnits[0] =(DeployUnit*)val;
root->count_deployUnits++;
} else {
root->deployUnits = realloc(root->deployUnits,(root->count_deployUnits+1)*sizeof(DeployUnit*));
root->deployUnits[root->count_deployUnits] =(DeployUnit*)val;root->count_deployUnits++;
}}
void addsuperTypesGroupType(GroupType*root,TypeDefinition *val){
if(root->superTypes== NULL){
root->count_superTypes=0;
root->superTypes = malloc(sizeof(TypeDefinition*));
root->superTypes[0] =(TypeDefinition*)val;
root->count_superTypes++;
} else {
root->superTypes = realloc(root->superTypes,(root->count_superTypes+1)*sizeof(TypeDefinition*));
root->superTypes[root->count_superTypes] =(TypeDefinition*)val;root->count_superTypes++;
}}
void adddeployUnitsNodeType(NodeType*root,DeployUnit *val){
if(root->deployUnits== NULL){
root->count_deployUnits=0;
root->deployUnits = malloc(sizeof(DeployUnit*));
root->deployUnits[0] =(DeployUnit*)val;
root->count_deployUnits++;
} else {
root->deployUnits = realloc(root->deployUnits,(root->count_deployUnits+1)*sizeof(DeployUnit*));
root->deployUnits[root->count_deployUnits] =(DeployUnit*)val;root->count_deployUnits++;
}}
void addsuperTypesNodeType(NodeType*root,TypeDefinition *val){
if(root->superTypes== NULL){
root->count_superTypes=0;
root->superTypes = malloc(sizeof(TypeDefinition*));
root->superTypes[0] =(TypeDefinition*)val;
root->count_superTypes++;
} else {
root->superTypes = realloc(root->superTypes,(root->count_superTypes+1)*sizeof(TypeDefinition*));
root->superTypes[root->count_superTypes] =(TypeDefinition*)val;root->count_superTypes++;
}}
void addmanagedPrimitiveTypesNodeType(NodeType*root,AdaptationPrimitiveType *val){
if(root->managedPrimitiveTypes== NULL){
root->count_managedPrimitiveTypes=0;
root->managedPrimitiveTypes = malloc(sizeof(AdaptationPrimitiveType*));
root->managedPrimitiveTypes[0] =(AdaptationPrimitiveType*)val;
root->count_managedPrimitiveTypes++;
} else {
root->managedPrimitiveTypes = realloc(root->managedPrimitiveTypes,(root->count_managedPrimitiveTypes+1)*sizeof(AdaptationPrimitiveType*));
root->managedPrimitiveTypes[root->count_managedPrimitiveTypes] =(AdaptationPrimitiveType*)val;root->count_managedPrimitiveTypes++;
}}
void addmanagedPrimitiveTypeRefsNodeType(NodeType*root,AdaptationPrimitiveTypeRef *val){
if(root->managedPrimitiveTypeRefs== NULL){
root->count_managedPrimitiveTypeRefs=0;
root->managedPrimitiveTypeRefs = malloc(sizeof(AdaptationPrimitiveTypeRef*));
root->managedPrimitiveTypeRefs[0] =(AdaptationPrimitiveTypeRef*)val;
root->count_managedPrimitiveTypeRefs++;
} else {
root->managedPrimitiveTypeRefs = realloc(root->managedPrimitiveTypeRefs,(root->count_managedPrimitiveTypeRefs+1)*sizeof(AdaptationPrimitiveTypeRef*));
root->managedPrimitiveTypeRefs[root->count_managedPrimitiveTypeRefs] =(AdaptationPrimitiveTypeRef*)val;root->count_managedPrimitiveTypeRefs++;
}}
