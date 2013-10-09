// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree_forward.hpp
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

#ifndef _KEVOREE_FORWARD_HPP
#define _KEVOREE_FORWARD_HPP

#include <ecorecpp/mapping_forward.hpp>

/*PROTECTED REGION ID(kevoree_forward) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
// Additional headers here
/*PROTECTED REGION END*/

// EPackage


#include <ecore_forward.hpp> // for EDataTypes
namespace kevoree
{

    // EDataType


    // EClass

    // ComponentInstance
    class ComponentInstance;
    typedef ComponentInstance* ComponentInstance_ptr;

    // ComponentType
    class ComponentType;
    typedef ComponentType* ComponentType_ptr;

    // ContainerNode
    class ContainerNode;
    typedef ContainerNode* ContainerNode_ptr;

    // ContainerRoot
    class ContainerRoot;
    typedef ContainerRoot* ContainerRoot_ptr;

    // PortType
    class PortType;
    typedef PortType* PortType_ptr;

    // Port
    class Port;
    typedef Port* Port_ptr;

    // Namespace
    class Namespace;
    typedef Namespace* Namespace_ptr;

    // Dictionary
    class Dictionary;
    typedef Dictionary* Dictionary_ptr;

    // DictionaryType
    class DictionaryType;
    typedef DictionaryType* DictionaryType_ptr;

    // DictionaryAttribute
    class DictionaryAttribute;
    typedef DictionaryAttribute* DictionaryAttribute_ptr;

    // DictionaryValue
    class DictionaryValue;
    typedef DictionaryValue* DictionaryValue_ptr;

    // CompositeType
    class CompositeType;
    typedef CompositeType* CompositeType_ptr;

    // PortTypeRef
    class PortTypeRef;
    typedef PortTypeRef* PortTypeRef_ptr;

    // Wire
    class Wire;
    typedef Wire* Wire_ptr;

    // ServicePortType
    class ServicePortType;
    typedef ServicePortType* ServicePortType_ptr;

    // Operation
    class Operation;
    typedef Operation* Operation_ptr;

    // Parameter
    class Parameter;
    typedef Parameter* Parameter_ptr;

    // TypedElement
    class TypedElement;
    typedef TypedElement* TypedElement_ptr;

    // MessagePortType
    class MessagePortType;
    typedef MessagePortType* MessagePortType_ptr;

    // Repository
    class Repository;
    typedef Repository* Repository_ptr;

    // DeployUnit
    class DeployUnit;
    typedef DeployUnit* DeployUnit_ptr;

    // TypeLibrary
    class TypeLibrary;
    typedef TypeLibrary* TypeLibrary_ptr;

    // NamedElement
    class NamedElement;
    typedef NamedElement* NamedElement_ptr;

    // IntegrationPattern
    class IntegrationPattern;
    typedef IntegrationPattern* IntegrationPattern_ptr;

    // ExtraFonctionalProperty
    class ExtraFonctionalProperty;
    typedef ExtraFonctionalProperty* ExtraFonctionalProperty_ptr;

    // PortTypeMapping
    class PortTypeMapping;
    typedef PortTypeMapping* PortTypeMapping_ptr;

    // Channel
    class Channel;
    typedef Channel* Channel_ptr;

    // MBinding
    class MBinding;
    typedef MBinding* MBinding_ptr;

    // NodeNetwork
    class NodeNetwork;
    typedef NodeNetwork* NodeNetwork_ptr;

    // NodeLink
    class NodeLink;
    typedef NodeLink* NodeLink_ptr;

    // NetworkProperty
    class NetworkProperty;
    typedef NetworkProperty* NetworkProperty_ptr;

    // ChannelType
    class ChannelType;
    typedef ChannelType* ChannelType_ptr;

    // TypeDefinition
    class TypeDefinition;
    typedef TypeDefinition* TypeDefinition_ptr;

    // Instance
    class Instance;
    typedef Instance* Instance_ptr;

    // LifeCycleTypeDefinition
    class LifeCycleTypeDefinition;
    typedef LifeCycleTypeDefinition* LifeCycleTypeDefinition_ptr;

    // Group
    class Group;
    typedef Group* Group_ptr;

    // GroupType
    class GroupType;
    typedef GroupType* GroupType_ptr;

    // NodeType
    class NodeType;
    typedef NodeType* NodeType_ptr;

    // AdaptationPrimitiveType
    class AdaptationPrimitiveType;
    typedef AdaptationPrimitiveType* AdaptationPrimitiveType_ptr;

    // AdaptationPrimitiveTypeRef
    class AdaptationPrimitiveTypeRef;
    typedef AdaptationPrimitiveTypeRef* AdaptationPrimitiveTypeRef_ptr;

    // Package & Factory
    class KevoreeFactory;
    typedef KevoreeFactory * KevoreeFactory_ptr;
    class KevoreePackage;
    typedef KevoreePackage * KevoreePackage_ptr;

    template< typename T, typename S >
    inline T* instanceOf(S* _s)
    {
        return dynamic_cast< T* > (_s);
    }

} // kevoree


#endif // _KEVOREE_FORWARD_HPP
