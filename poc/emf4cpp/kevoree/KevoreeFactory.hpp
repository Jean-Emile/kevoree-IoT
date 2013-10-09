// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/KevoreeFactory.hpp
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

#ifndef _KEVOREEFACTORY_HPP
#define _KEVOREEFACTORY_HPP

#include <ecore/EFactory.hpp>
#include <kevoree.hpp>

namespace kevoree
{

    class KevoreeFactory: public virtual ::ecore::EFactory
    {
    public:

        static KevoreeFactory_ptr _instance();

        virtual ComponentInstance_ptr createComponentInstance();
        virtual ComponentType_ptr createComponentType();
        virtual ContainerNode_ptr createContainerNode();
        virtual ContainerRoot_ptr createContainerRoot();
        virtual PortType_ptr createPortType();
        virtual Port_ptr createPort();
        virtual Namespace_ptr createNamespace();
        virtual Dictionary_ptr createDictionary();
        virtual DictionaryType_ptr createDictionaryType();
        virtual DictionaryAttribute_ptr createDictionaryAttribute();
        virtual DictionaryValue_ptr createDictionaryValue();
        virtual CompositeType_ptr createCompositeType();
        virtual PortTypeRef_ptr createPortTypeRef();
        virtual Wire_ptr createWire();
        virtual ServicePortType_ptr createServicePortType();
        virtual Operation_ptr createOperation();
        virtual Parameter_ptr createParameter();
        virtual TypedElement_ptr createTypedElement();
        virtual MessagePortType_ptr createMessagePortType();
        virtual Repository_ptr createRepository();
        virtual DeployUnit_ptr createDeployUnit();
        virtual TypeLibrary_ptr createTypeLibrary();
        virtual NamedElement_ptr createNamedElement();
        virtual IntegrationPattern_ptr createIntegrationPattern();
        virtual ExtraFonctionalProperty_ptr createExtraFonctionalProperty();
        virtual PortTypeMapping_ptr createPortTypeMapping();
        virtual Channel_ptr createChannel();
        virtual MBinding_ptr createMBinding();
        virtual NodeNetwork_ptr createNodeNetwork();
        virtual NodeLink_ptr createNodeLink();
        virtual NetworkProperty_ptr createNetworkProperty();
        virtual ChannelType_ptr createChannelType();
        virtual TypeDefinition_ptr createTypeDefinition();
        virtual Instance_ptr createInstance();
        virtual LifeCycleTypeDefinition_ptr createLifeCycleTypeDefinition();
        virtual Group_ptr createGroup();
        virtual GroupType_ptr createGroupType();
        virtual NodeType_ptr createNodeType();
        virtual AdaptationPrimitiveType_ptr createAdaptationPrimitiveType();
        virtual AdaptationPrimitiveTypeRef_ptr
                createAdaptationPrimitiveTypeRef();

        virtual ::ecore::EObject_ptr create(::ecore::EClass_ptr _eClass);
        virtual ::ecore::EJavaObject createFromString(
                ::ecore::EDataType_ptr _eDataType,
                ::ecore::EString const& _literalValue);
        virtual ::ecore::EString convertToString(
                ::ecore::EDataType_ptr _eDataType,
                ::ecore::EJavaObject const& _instanceValue);

    protected:

        static std::auto_ptr< KevoreeFactory > s_instance;

        KevoreeFactory();

    };

} // kevoree


#endif // _KEVOREEFACTORY_HPP
