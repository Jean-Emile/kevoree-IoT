#
# kevoree.cmake
# Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
#
# EMF4CPP is free software: you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# EMF4CPP is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#

set(CMAKE_CXX_FLAGS "")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O3 -funroll-loops")

set(kevoree_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/KevoreePackage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/KevoreeFactory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/KevoreePackageImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/KevoreeFactoryImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ComponentInstance.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ComponentInstanceImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ComponentType.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ComponentTypeImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ContainerNode.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ContainerNodeImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ContainerRoot.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ContainerRootImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/PortType.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/PortTypeImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Port.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/PortImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Namespace.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NamespaceImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Dictionary.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DictionaryImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DictionaryType.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DictionaryTypeImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DictionaryAttribute.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DictionaryAttributeImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DictionaryValue.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DictionaryValueImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/CompositeType.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/CompositeTypeImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/PortTypeRef.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/PortTypeRefImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Wire.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/WireImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ServicePortType.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ServicePortTypeImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Operation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/OperationImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Parameter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ParameterImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/TypedElement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/TypedElementImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/MessagePortType.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/MessagePortTypeImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Repository.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/RepositoryImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DeployUnit.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DeployUnitImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/TypeLibrary.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/TypeLibraryImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NamedElement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NamedElementImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/IntegrationPattern.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/IntegrationPatternImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ExtraFonctionalProperty.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ExtraFonctionalPropertyImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/PortTypeMapping.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/PortTypeMappingImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Channel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ChannelImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/MBinding.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/MBindingImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NodeNetwork.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NodeNetworkImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NodeLink.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NodeLinkImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NetworkProperty.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NetworkPropertyImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ChannelType.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ChannelTypeImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/TypeDefinition.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/TypeDefinitionImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Instance.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/InstanceImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/LifeCycleTypeDefinition.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/LifeCycleTypeDefinitionImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Group.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/GroupImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/GroupType.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/GroupTypeImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NodeType.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NodeTypeImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/AdaptationPrimitiveType.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/AdaptationPrimitiveTypeImpl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/AdaptationPrimitiveTypeRef.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/AdaptationPrimitiveTypeRefImpl.cpp
   )
   
set(kevoree_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree_forward.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/KevoreePackage.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/KevoreeFactory.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ComponentInstance.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ComponentType.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ContainerNode.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ContainerRoot.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/PortType.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Port.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Namespace.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Dictionary.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DictionaryType.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DictionaryAttribute.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DictionaryValue.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/CompositeType.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/PortTypeRef.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Wire.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ServicePortType.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Operation.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Parameter.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/TypedElement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/MessagePortType.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Repository.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DeployUnit.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/TypeLibrary.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NamedElement.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/IntegrationPattern.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ExtraFonctionalProperty.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/PortTypeMapping.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Channel.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/MBinding.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NodeNetwork.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NodeLink.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NetworkProperty.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ChannelType.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/TypeDefinition.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Instance.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/LifeCycleTypeDefinition.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Group.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/GroupType.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NodeType.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/AdaptationPrimitiveType.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/AdaptationPrimitiveTypeRef.hpp
   )

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree.hpp DESTINATION include/emf4cpp/)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree_forward.hpp DESTINATION include/emf4cpp/)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/KevoreeFactory.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/KevoreePackage.hpp DESTINATION include/emf4cpp/kevoree)   
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ComponentInstance.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ComponentType.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ContainerNode.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ContainerRoot.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/PortType.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Port.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Namespace.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Dictionary.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DictionaryType.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DictionaryAttribute.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DictionaryValue.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/CompositeType.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/PortTypeRef.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Wire.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ServicePortType.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Operation.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Parameter.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/TypedElement.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/MessagePortType.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Repository.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/DeployUnit.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/TypeLibrary.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NamedElement.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/IntegrationPattern.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ExtraFonctionalProperty.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/PortTypeMapping.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Channel.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/MBinding.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NodeNetwork.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NodeLink.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NetworkProperty.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/ChannelType.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/TypeDefinition.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Instance.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/LifeCycleTypeDefinition.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/Group.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/GroupType.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/NodeType.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/AdaptationPrimitiveType.hpp DESTINATION include/emf4cpp/kevoree)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/kevoree/AdaptationPrimitiveTypeRef.hpp DESTINATION include/emf4cpp/kevoree)
   
include_directories(${CMAKE_CURRENT_SOURCE_DIR} /opt/emf4cpp-0.0.2/bin/../include/emf4cpp /opt/emf4cpp-0.0.2/bin/../include/emf4cpp)

add_library(emf4cpp-kevoree SHARED ${kevoree_HEADERS} ${kevoree_SOURCES})
set_target_properties(emf4cpp-kevoree PROPERTIES VERSION 0.0.1 SOVERSION 1)

install(TARGETS emf4cpp-kevoree DESTINATION lib)

