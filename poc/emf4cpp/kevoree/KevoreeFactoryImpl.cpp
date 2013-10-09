// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/KevoreeFactoryImpl.cpp
 * Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
 *
 * EMF4CPP is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EMF4CPP is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <kevoree/KevoreeFactory.hpp>
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/ComponentInstance.hpp>
#include <kevoree/ComponentType.hpp>
#include <kevoree/ContainerNode.hpp>
#include <kevoree/ContainerRoot.hpp>
#include <kevoree/PortType.hpp>
#include <kevoree/Port.hpp>
#include <kevoree/Namespace.hpp>
#include <kevoree/Dictionary.hpp>
#include <kevoree/DictionaryType.hpp>
#include <kevoree/DictionaryAttribute.hpp>
#include <kevoree/DictionaryValue.hpp>
#include <kevoree/CompositeType.hpp>
#include <kevoree/PortTypeRef.hpp>
#include <kevoree/Wire.hpp>
#include <kevoree/ServicePortType.hpp>
#include <kevoree/Operation.hpp>
#include <kevoree/Parameter.hpp>
#include <kevoree/TypedElement.hpp>
#include <kevoree/MessagePortType.hpp>
#include <kevoree/Repository.hpp>
#include <kevoree/DeployUnit.hpp>
#include <kevoree/TypeLibrary.hpp>
#include <kevoree/NamedElement.hpp>
#include <kevoree/IntegrationPattern.hpp>
#include <kevoree/ExtraFonctionalProperty.hpp>
#include <kevoree/PortTypeMapping.hpp>
#include <kevoree/Channel.hpp>
#include <kevoree/MBinding.hpp>
#include <kevoree/NodeNetwork.hpp>
#include <kevoree/NodeLink.hpp>
#include <kevoree/NetworkProperty.hpp>
#include <kevoree/ChannelType.hpp>
#include <kevoree/TypeDefinition.hpp>
#include <kevoree/Instance.hpp>
#include <kevoree/LifeCycleTypeDefinition.hpp>
#include <kevoree/Group.hpp>
#include <kevoree/GroupType.hpp>
#include <kevoree/NodeType.hpp>
#include <kevoree/AdaptationPrimitiveType.hpp>
#include <kevoree/AdaptationPrimitiveTypeRef.hpp>

#include <ecore.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

KevoreeFactory::KevoreeFactory()
{
    s_instance.reset(this);
}

::ecore::EObject_ptr KevoreeFactory::create(::ecore::EClass_ptr _eClass)
{
    switch (_eClass->getClassifierID())
    {
    case KevoreePackage::COMPONENTINSTANCE:
        return createComponentInstance();
    case KevoreePackage::COMPONENTTYPE:
        return createComponentType();
    case KevoreePackage::CONTAINERNODE:
        return createContainerNode();
    case KevoreePackage::CONTAINERROOT:
        return createContainerRoot();
    case KevoreePackage::PORTTYPE:
        return createPortType();
    case KevoreePackage::PORT:
        return createPort();
    case KevoreePackage::NAMESPACE:
        return createNamespace();
    case KevoreePackage::DICTIONARY:
        return createDictionary();
    case KevoreePackage::DICTIONARYTYPE:
        return createDictionaryType();
    case KevoreePackage::DICTIONARYATTRIBUTE:
        return createDictionaryAttribute();
    case KevoreePackage::DICTIONARYVALUE:
        return createDictionaryValue();
    case KevoreePackage::COMPOSITETYPE:
        return createCompositeType();
    case KevoreePackage::PORTTYPEREF:
        return createPortTypeRef();
    case KevoreePackage::WIRE:
        return createWire();
    case KevoreePackage::SERVICEPORTTYPE:
        return createServicePortType();
    case KevoreePackage::OPERATION:
        return createOperation();
    case KevoreePackage::PARAMETER:
        return createParameter();
    case KevoreePackage::TYPEDELEMENT:
        return createTypedElement();
    case KevoreePackage::MESSAGEPORTTYPE:
        return createMessagePortType();
    case KevoreePackage::REPOSITORY:
        return createRepository();
    case KevoreePackage::DEPLOYUNIT:
        return createDeployUnit();
    case KevoreePackage::TYPELIBRARY:
        return createTypeLibrary();
    case KevoreePackage::NAMEDELEMENT:
        return createNamedElement();
    case KevoreePackage::INTEGRATIONPATTERN:
        return createIntegrationPattern();
    case KevoreePackage::EXTRAFONCTIONALPROPERTY:
        return createExtraFonctionalProperty();
    case KevoreePackage::PORTTYPEMAPPING:
        return createPortTypeMapping();
    case KevoreePackage::CHANNEL:
        return createChannel();
    case KevoreePackage::MBINDING:
        return createMBinding();
    case KevoreePackage::NODENETWORK:
        return createNodeNetwork();
    case KevoreePackage::NODELINK:
        return createNodeLink();
    case KevoreePackage::NETWORKPROPERTY:
        return createNetworkProperty();
    case KevoreePackage::CHANNELTYPE:
        return createChannelType();
    case KevoreePackage::TYPEDEFINITION:
        return createTypeDefinition();
    case KevoreePackage::INSTANCE:
        return createInstance();
    case KevoreePackage::LIFECYCLETYPEDEFINITION:
        return createLifeCycleTypeDefinition();
    case KevoreePackage::GROUP:
        return createGroup();
    case KevoreePackage::GROUPTYPE:
        return createGroupType();
    case KevoreePackage::NODETYPE:
        return createNodeType();
    case KevoreePackage::ADAPTATIONPRIMITIVETYPE:
        return createAdaptationPrimitiveType();
    case KevoreePackage::ADAPTATIONPRIMITIVETYPEREF:
        return createAdaptationPrimitiveTypeRef();
    default:
        throw "IllegalArgumentException";
    }
}

::ecore::EJavaObject KevoreeFactory::createFromString(
        ::ecore::EDataType_ptr _eDataType,
        ::ecore::EString const& _literalValue)
{
    switch (_eDataType->getClassifierID())
    {
    default:
        throw "IllegalArgumentException";
    }
}

::ecore::EString KevoreeFactory::convertToString(
        ::ecore::EDataType_ptr _eDataType,
        ::ecore::EJavaObject const& _instanceValue)
{
    switch (_eDataType->getClassifierID())
    {
    default:
        throw "IllegalArgumentException";
    }
}

ComponentInstance_ptr KevoreeFactory::createComponentInstance()
{
    return new ComponentInstance();
}
ComponentType_ptr KevoreeFactory::createComponentType()
{
    return new ComponentType();
}
ContainerNode_ptr KevoreeFactory::createContainerNode()
{
    return new ContainerNode();
}
ContainerRoot_ptr KevoreeFactory::createContainerRoot()
{
    return new ContainerRoot();
}
PortType_ptr KevoreeFactory::createPortType()
{
    return new PortType();
}
Port_ptr KevoreeFactory::createPort()
{
    return new Port();
}
Namespace_ptr KevoreeFactory::createNamespace()
{
    return new Namespace();
}
Dictionary_ptr KevoreeFactory::createDictionary()
{
    return new Dictionary();
}
DictionaryType_ptr KevoreeFactory::createDictionaryType()
{
    return new DictionaryType();
}
DictionaryAttribute_ptr KevoreeFactory::createDictionaryAttribute()
{
    return new DictionaryAttribute();
}
DictionaryValue_ptr KevoreeFactory::createDictionaryValue()
{
    return new DictionaryValue();
}
CompositeType_ptr KevoreeFactory::createCompositeType()
{
    return new CompositeType();
}
PortTypeRef_ptr KevoreeFactory::createPortTypeRef()
{
    return new PortTypeRef();
}
Wire_ptr KevoreeFactory::createWire()
{
    return new Wire();
}
ServicePortType_ptr KevoreeFactory::createServicePortType()
{
    return new ServicePortType();
}
Operation_ptr KevoreeFactory::createOperation()
{
    return new Operation();
}
Parameter_ptr KevoreeFactory::createParameter()
{
    return new Parameter();
}
TypedElement_ptr KevoreeFactory::createTypedElement()
{
    return new TypedElement();
}
MessagePortType_ptr KevoreeFactory::createMessagePortType()
{
    return new MessagePortType();
}
Repository_ptr KevoreeFactory::createRepository()
{
    return new Repository();
}
DeployUnit_ptr KevoreeFactory::createDeployUnit()
{
    return new DeployUnit();
}
TypeLibrary_ptr KevoreeFactory::createTypeLibrary()
{
    return new TypeLibrary();
}
NamedElement_ptr KevoreeFactory::createNamedElement()
{
    return new NamedElement();
}
IntegrationPattern_ptr KevoreeFactory::createIntegrationPattern()
{
    return new IntegrationPattern();
}
ExtraFonctionalProperty_ptr KevoreeFactory::createExtraFonctionalProperty()
{
    return new ExtraFonctionalProperty();
}
PortTypeMapping_ptr KevoreeFactory::createPortTypeMapping()
{
    return new PortTypeMapping();
}
Channel_ptr KevoreeFactory::createChannel()
{
    return new Channel();
}
MBinding_ptr KevoreeFactory::createMBinding()
{
    return new MBinding();
}
NodeNetwork_ptr KevoreeFactory::createNodeNetwork()
{
    return new NodeNetwork();
}
NodeLink_ptr KevoreeFactory::createNodeLink()
{
    return new NodeLink();
}
NetworkProperty_ptr KevoreeFactory::createNetworkProperty()
{
    return new NetworkProperty();
}
ChannelType_ptr KevoreeFactory::createChannelType()
{
    return new ChannelType();
}
TypeDefinition_ptr KevoreeFactory::createTypeDefinition()
{
    return new TypeDefinition();
}
Instance_ptr KevoreeFactory::createInstance()
{
    return new Instance();
}
LifeCycleTypeDefinition_ptr KevoreeFactory::createLifeCycleTypeDefinition()
{
    return new LifeCycleTypeDefinition();
}
Group_ptr KevoreeFactory::createGroup()
{
    return new Group();
}
GroupType_ptr KevoreeFactory::createGroupType()
{
    return new GroupType();
}
NodeType_ptr KevoreeFactory::createNodeType()
{
    return new NodeType();
}
AdaptationPrimitiveType_ptr KevoreeFactory::createAdaptationPrimitiveType()
{
    return new AdaptationPrimitiveType();
}
AdaptationPrimitiveTypeRef_ptr KevoreeFactory::createAdaptationPrimitiveTypeRef()
{
    return new AdaptationPrimitiveTypeRef();
}

