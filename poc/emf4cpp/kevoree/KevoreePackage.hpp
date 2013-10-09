// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/KevoreePackage.hpp
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

#ifndef _KEVOREEPACKAGE_HPP
#define _KEVOREEPACKAGE_HPP

#include <ecore/EPackage.hpp>
#include <kevoree_forward.hpp>

namespace kevoree
{

    class KevoreePackage: public virtual ::ecore::EPackage
    {
    public:

        static KevoreePackage_ptr _instance();

        // IDs for classifiers

        static const int ADAPTATIONPRIMITIVETYPE = 0;

        static const int ADAPTATIONPRIMITIVETYPEREF = 1;

        static const int CHANNEL = 2;

        static const int CHANNELTYPE = 3;

        static const int COMPONENTINSTANCE = 4;

        static const int COMPONENTTYPE = 5;

        static const int COMPOSITETYPE = 6;

        static const int CONTAINERNODE = 7;

        static const int CONTAINERROOT = 8;

        static const int DEPLOYUNIT = 9;

        static const int DICTIONARY = 10;

        static const int DICTIONARYATTRIBUTE = 11;

        static const int DICTIONARYTYPE = 12;

        static const int DICTIONARYVALUE = 13;

        static const int EXTRAFONCTIONALPROPERTY = 14;

        static const int GROUP = 15;

        static const int GROUPTYPE = 16;

        static const int INSTANCE = 17;

        static const int INTEGRATIONPATTERN = 18;

        static const int LIFECYCLETYPEDEFINITION = 19;

        static const int MBINDING = 20;

        static const int MESSAGEPORTTYPE = 21;

        static const int NAMEDELEMENT = 22;

        static const int NAMESPACE = 23;

        static const int NETWORKPROPERTY = 24;

        static const int NODELINK = 25;

        static const int NODENETWORK = 26;

        static const int NODETYPE = 27;

        static const int OPERATION = 28;

        static const int PARAMETER = 29;

        static const int PORT = 30;

        static const int PORTTYPE = 31;

        static const int PORTTYPEMAPPING = 32;

        static const int PORTTYPEREF = 33;

        static const int REPOSITORY = 34;

        static const int SERVICEPORTTYPE = 35;

        static const int TYPEDEFINITION = 36;

        static const int TYPEDELEMENT = 37;

        static const int TYPELIBRARY = 38;

        static const int WIRE = 39;

        static const int COMPONENTINSTANCE__PROVIDED = 0;

        static const int COMPONENTINSTANCE__REQUIRED = 1;

        static const int COMPONENTINSTANCE__NAMESPACE = 2;

        static const int COMPONENTTYPE__REQUIRED = 3;

        static const int COMPONENTTYPE__INTEGRATIONPATTERNS = 4;

        static const int COMPONENTTYPE__EXTRAFONCTIONALPROPERTIES = 5;

        static const int COMPONENTTYPE__PROVIDED = 6;

        static const int CONTAINERNODE__COMPONENTS = 7;

        static const int CONTAINERNODE__HOSTS = 8;

        static const int CONTAINERNODE__HOST = 9;

        static const int CONTAINERROOT__NODES = 10;

        static const int CONTAINERROOT__TYPEDEFINITIONS = 11;

        static const int CONTAINERROOT__REPOSITORIES = 12;

        static const int CONTAINERROOT__DATATYPES = 13;

        static const int CONTAINERROOT__LIBRARIES = 14;

        static const int CONTAINERROOT__HUBS = 15;

        static const int CONTAINERROOT__MBINDINGS = 16;

        static const int CONTAINERROOT__DEPLOYUNITS = 17;

        static const int CONTAINERROOT__NODENETWORKS = 18;

        static const int CONTAINERROOT__GROUPS = 19;

        static const int CONTAINERROOT__ADAPTATIONPRIMITIVETYPES = 20;

        static const int PORTTYPE__SYNCHRONE = 21;

        static const int PORT__BINDINGS = 22;

        static const int PORT__PORTTYPEREF = 23;

        static const int NAMESPACE__CHILDS = 24;

        static const int NAMESPACE__PARENT = 25;

        static const int DICTIONARY__VALUES = 26;

        static const int DICTIONARYTYPE__ATTRIBUTES = 27;

        static const int DICTIONARYTYPE__DEFAULTVALUES = 28;

        static const int DICTIONARYATTRIBUTE__OPTIONAL = 29;

        static const int DICTIONARYATTRIBUTE__STATE = 30;

        static const int DICTIONARYATTRIBUTE__DATATYPE = 31;

        static const int DICTIONARYATTRIBUTE__FRAGMENTDEPENDANT = 32;

        static const int DICTIONARYVALUE__ATTRIBUTE = 33;

        static const int DICTIONARYVALUE__VALUE = 34;

        static const int DICTIONARYVALUE__TARGETNODE = 35;

        static const int COMPOSITETYPE__CHILDS = 36;

        static const int COMPOSITETYPE__WIRES = 37;

        static const int PORTTYPEREF__REF = 38;

        static const int PORTTYPEREF__MAPPINGS = 39;

        static const int PORTTYPEREF__OPTIONAL = 40;

        static const int PORTTYPEREF__NODEPENDENCY = 41;

        static const int WIRE__PORTS = 42;

        static const int SERVICEPORTTYPE__OPERATIONS = 43;

        static const int SERVICEPORTTYPE__INTERFACE = 44;

        static const int OPERATION__PARAMETERS = 45;

        static const int OPERATION__RETURNTYPE = 46;

        static const int PARAMETER__TYPE = 47;

        static const int PARAMETER__ORDER = 48;

        static const int TYPEDELEMENT__GENERICTYPES = 49;

        static const int MESSAGEPORTTYPE__FILTERS = 50;

        static const int REPOSITORY__UNITS = 51;

        static const int REPOSITORY__URL = 52;

        static const int DEPLOYUNIT__NAME = 53;

        static const int DEPLOYUNIT__GROUPNAME = 54;

        static const int DEPLOYUNIT__UNITNAME = 55;

        static const int DEPLOYUNIT__VERSION = 56;

        static const int DEPLOYUNIT__URL = 57;

        static const int DEPLOYUNIT__HASHCODE = 58;

        static const int DEPLOYUNIT__REQUIREDLIBS = 59;

        static const int DEPLOYUNIT__TARGETNODETYPE = 60;

        static const int DEPLOYUNIT__TYPE = 61;

        static const int TYPELIBRARY__SUBTYPES = 62;

        static const int NAMEDELEMENT__NAME = 63;

        static const int INTEGRATIONPATTERN__EXTRAFONCTIONALPROPERTIES = 64;

        static const int INTEGRATIONPATTERN__PORTTYPES = 65;

        static const int EXTRAFONCTIONALPROPERTY__PORTTYPES = 66;

        static const int PORTTYPEMAPPING__BEANMETHODNAME = 67;

        static const int PORTTYPEMAPPING__SERVICEMETHODNAME = 68;

        static const int PORTTYPEMAPPING__PARAMTYPES = 69;

        static const int CHANNEL__BINDINGS = 70;

        static const int MBINDING__PORT = 71;

        static const int MBINDING__HUB = 72;

        static const int NODENETWORK__LINK = 73;

        static const int NODENETWORK__INITBY = 74;

        static const int NODENETWORK__TARGET = 75;

        static const int NODELINK__NETWORKTYPE = 76;

        static const int NODELINK__ESTIMATEDRATE = 77;

        static const int NODELINK__NETWORKPROPERTIES = 78;

        static const int NODELINK__LASTCHECK = 79;

        static const int NODELINK__ZONEID = 80;

        static const int NETWORKPROPERTY__VALUE = 81;

        static const int NETWORKPROPERTY__LASTCHECK = 82;

        static const int CHANNELTYPE__LOWERBINDINGS = 83;

        static const int CHANNELTYPE__UPPERBINDINGS = 84;

        static const int CHANNELTYPE__LOWERFRAGMENTS = 85;

        static const int CHANNELTYPE__UPPERFRAGMENTS = 86;

        static const int TYPEDEFINITION__DEPLOYUNITS = 87;

        static const int TYPEDEFINITION__FACTORYBEAN = 88;

        static const int TYPEDEFINITION__BEAN = 89;

        static const int TYPEDEFINITION__DICTIONARYTYPE = 90;

        static const int TYPEDEFINITION__SUPERTYPES = 91;

        static const int TYPEDEFINITION__ABSTRACT = 92;

        static const int INSTANCE__TYPEDEFINITION = 93;

        static const int INSTANCE__DICTIONARY = 94;

        static const int INSTANCE__METADATA = 95;

        static const int INSTANCE__STARTED = 96;

        static const int LIFECYCLETYPEDEFINITION__STARTMETHOD = 97;

        static const int LIFECYCLETYPEDEFINITION__STOPMETHOD = 98;

        static const int LIFECYCLETYPEDEFINITION__UPDATEMETHOD = 99;

        static const int GROUP__SUBNODES = 100;

        static const int NODETYPE__MANAGEDPRIMITIVETYPES = 101;

        static const int NODETYPE__MANAGEDPRIMITIVETYPEREFS = 102;

        static const int ADAPTATIONPRIMITIVETYPEREF__REF = 103;

        static const int ADAPTATIONPRIMITIVETYPEREF__MAXTIME = 104;

        // IDs for classifiers for class AdaptationPrimitiveType 

        static const int ADAPTATIONPRIMITIVETYPE__NAME = NAMEDELEMENT__NAME;

        // IDs for classifiers for class AdaptationPrimitiveTypeRef 


        // IDs for classifiers for class Channel 

        static const int CHANNEL__NAME = NAMEDELEMENT__NAME;

        static const int CHANNEL__TYPEDEFINITION = INSTANCE__TYPEDEFINITION;

        static const int CHANNEL__DICTIONARY = INSTANCE__DICTIONARY;

        static const int CHANNEL__METADATA = INSTANCE__METADATA;

        static const int CHANNEL__STARTED = INSTANCE__STARTED;

        // IDs for classifiers for class ChannelType 

        static const int CHANNELTYPE__NAME = NAMEDELEMENT__NAME;

        static const int CHANNELTYPE__DEPLOYUNITS = TYPEDEFINITION__DEPLOYUNITS;

        static const int CHANNELTYPE__FACTORYBEAN = TYPEDEFINITION__FACTORYBEAN;

        static const int CHANNELTYPE__BEAN = TYPEDEFINITION__BEAN;

        static const int CHANNELTYPE__DICTIONARYTYPE =
                TYPEDEFINITION__DICTIONARYTYPE;

        static const int CHANNELTYPE__SUPERTYPES = TYPEDEFINITION__SUPERTYPES;

        static const int CHANNELTYPE__ABSTRACT = TYPEDEFINITION__ABSTRACT;

        static const int CHANNELTYPE__STARTMETHOD =
                LIFECYCLETYPEDEFINITION__STARTMETHOD;

        static const int CHANNELTYPE__STOPMETHOD =
                LIFECYCLETYPEDEFINITION__STOPMETHOD;

        static const int CHANNELTYPE__UPDATEMETHOD =
                LIFECYCLETYPEDEFINITION__UPDATEMETHOD;

        // IDs for classifiers for class ComponentInstance 

        static const int COMPONENTINSTANCE__NAME = NAMEDELEMENT__NAME;

        static const int COMPONENTINSTANCE__TYPEDEFINITION =
                INSTANCE__TYPEDEFINITION;

        static const int COMPONENTINSTANCE__DICTIONARY = INSTANCE__DICTIONARY;

        static const int COMPONENTINSTANCE__METADATA = INSTANCE__METADATA;

        static const int COMPONENTINSTANCE__STARTED = INSTANCE__STARTED;

        // IDs for classifiers for class ComponentType 

        static const int COMPONENTTYPE__NAME = NAMEDELEMENT__NAME;

        static const int COMPONENTTYPE__DEPLOYUNITS =
                TYPEDEFINITION__DEPLOYUNITS;

        static const int COMPONENTTYPE__FACTORYBEAN =
                TYPEDEFINITION__FACTORYBEAN;

        static const int COMPONENTTYPE__BEAN = TYPEDEFINITION__BEAN;

        static const int COMPONENTTYPE__DICTIONARYTYPE =
                TYPEDEFINITION__DICTIONARYTYPE;

        static const int COMPONENTTYPE__SUPERTYPES = TYPEDEFINITION__SUPERTYPES;

        static const int COMPONENTTYPE__ABSTRACT = TYPEDEFINITION__ABSTRACT;

        static const int COMPONENTTYPE__STARTMETHOD =
                LIFECYCLETYPEDEFINITION__STARTMETHOD;

        static const int COMPONENTTYPE__STOPMETHOD =
                LIFECYCLETYPEDEFINITION__STOPMETHOD;

        static const int COMPONENTTYPE__UPDATEMETHOD =
                LIFECYCLETYPEDEFINITION__UPDATEMETHOD;

        // IDs for classifiers for class CompositeType 

        static const int COMPOSITETYPE__NAME = NAMEDELEMENT__NAME;

        static const int COMPOSITETYPE__DEPLOYUNITS =
                TYPEDEFINITION__DEPLOYUNITS;

        static const int COMPOSITETYPE__FACTORYBEAN =
                TYPEDEFINITION__FACTORYBEAN;

        static const int COMPOSITETYPE__BEAN = TYPEDEFINITION__BEAN;

        static const int COMPOSITETYPE__DICTIONARYTYPE =
                TYPEDEFINITION__DICTIONARYTYPE;

        static const int COMPOSITETYPE__SUPERTYPES = TYPEDEFINITION__SUPERTYPES;

        static const int COMPOSITETYPE__ABSTRACT = TYPEDEFINITION__ABSTRACT;

        static const int COMPOSITETYPE__STARTMETHOD =
                LIFECYCLETYPEDEFINITION__STARTMETHOD;

        static const int COMPOSITETYPE__STOPMETHOD =
                LIFECYCLETYPEDEFINITION__STOPMETHOD;

        static const int COMPOSITETYPE__UPDATEMETHOD =
                LIFECYCLETYPEDEFINITION__UPDATEMETHOD;

        static const int COMPOSITETYPE__REQUIRED = COMPONENTTYPE__REQUIRED;

        static const int COMPOSITETYPE__INTEGRATIONPATTERNS =
                COMPONENTTYPE__INTEGRATIONPATTERNS;

        static const int COMPOSITETYPE__EXTRAFONCTIONALPROPERTIES =
                COMPONENTTYPE__EXTRAFONCTIONALPROPERTIES;

        static const int COMPOSITETYPE__PROVIDED = COMPONENTTYPE__PROVIDED;

        // IDs for classifiers for class ContainerNode 

        static const int CONTAINERNODE__NAME = NAMEDELEMENT__NAME;

        static const int CONTAINERNODE__TYPEDEFINITION =
                INSTANCE__TYPEDEFINITION;

        static const int CONTAINERNODE__DICTIONARY = INSTANCE__DICTIONARY;

        static const int CONTAINERNODE__METADATA = INSTANCE__METADATA;

        static const int CONTAINERNODE__STARTED = INSTANCE__STARTED;

        // IDs for classifiers for class ContainerRoot 


        // IDs for classifiers for class DeployUnit 


        // IDs for classifiers for class Dictionary 


        // IDs for classifiers for class DictionaryAttribute 

        static const int DICTIONARYATTRIBUTE__NAME = NAMEDELEMENT__NAME;

        static const int DICTIONARYATTRIBUTE__GENERICTYPES =
                TYPEDELEMENT__GENERICTYPES;

        // IDs for classifiers for class DictionaryType 


        // IDs for classifiers for class DictionaryValue 


        // IDs for classifiers for class ExtraFonctionalProperty 


        // IDs for classifiers for class Group 

        static const int GROUP__NAME = NAMEDELEMENT__NAME;

        static const int GROUP__TYPEDEFINITION = INSTANCE__TYPEDEFINITION;

        static const int GROUP__DICTIONARY = INSTANCE__DICTIONARY;

        static const int GROUP__METADATA = INSTANCE__METADATA;

        static const int GROUP__STARTED = INSTANCE__STARTED;

        // IDs for classifiers for class GroupType 

        static const int GROUPTYPE__NAME = NAMEDELEMENT__NAME;

        static const int GROUPTYPE__DEPLOYUNITS = TYPEDEFINITION__DEPLOYUNITS;

        static const int GROUPTYPE__FACTORYBEAN = TYPEDEFINITION__FACTORYBEAN;

        static const int GROUPTYPE__BEAN = TYPEDEFINITION__BEAN;

        static const int GROUPTYPE__DICTIONARYTYPE =
                TYPEDEFINITION__DICTIONARYTYPE;

        static const int GROUPTYPE__SUPERTYPES = TYPEDEFINITION__SUPERTYPES;

        static const int GROUPTYPE__ABSTRACT = TYPEDEFINITION__ABSTRACT;

        static const int GROUPTYPE__STARTMETHOD =
                LIFECYCLETYPEDEFINITION__STARTMETHOD;

        static const int GROUPTYPE__STOPMETHOD =
                LIFECYCLETYPEDEFINITION__STOPMETHOD;

        static const int GROUPTYPE__UPDATEMETHOD =
                LIFECYCLETYPEDEFINITION__UPDATEMETHOD;

        // IDs for classifiers for class Instance 

        static const int INSTANCE__NAME = NAMEDELEMENT__NAME;

        // IDs for classifiers for class IntegrationPattern 

        static const int INTEGRATIONPATTERN__NAME = NAMEDELEMENT__NAME;

        // IDs for classifiers for class LifeCycleTypeDefinition 

        static const int LIFECYCLETYPEDEFINITION__NAME = NAMEDELEMENT__NAME;

        static const int LIFECYCLETYPEDEFINITION__DEPLOYUNITS =
                TYPEDEFINITION__DEPLOYUNITS;

        static const int LIFECYCLETYPEDEFINITION__FACTORYBEAN =
                TYPEDEFINITION__FACTORYBEAN;

        static const int LIFECYCLETYPEDEFINITION__BEAN = TYPEDEFINITION__BEAN;

        static const int LIFECYCLETYPEDEFINITION__DICTIONARYTYPE =
                TYPEDEFINITION__DICTIONARYTYPE;

        static const int LIFECYCLETYPEDEFINITION__SUPERTYPES =
                TYPEDEFINITION__SUPERTYPES;

        static const int LIFECYCLETYPEDEFINITION__ABSTRACT =
                TYPEDEFINITION__ABSTRACT;

        // IDs for classifiers for class MBinding 


        // IDs for classifiers for class MessagePortType 

        static const int MESSAGEPORTTYPE__NAME = NAMEDELEMENT__NAME;

        static const int MESSAGEPORTTYPE__DEPLOYUNITS =
                TYPEDEFINITION__DEPLOYUNITS;

        static const int MESSAGEPORTTYPE__FACTORYBEAN =
                TYPEDEFINITION__FACTORYBEAN;

        static const int MESSAGEPORTTYPE__BEAN = TYPEDEFINITION__BEAN;

        static const int MESSAGEPORTTYPE__DICTIONARYTYPE =
                TYPEDEFINITION__DICTIONARYTYPE;

        static const int MESSAGEPORTTYPE__SUPERTYPES =
                TYPEDEFINITION__SUPERTYPES;

        static const int MESSAGEPORTTYPE__ABSTRACT = TYPEDEFINITION__ABSTRACT;

        static const int MESSAGEPORTTYPE__SYNCHRONE = PORTTYPE__SYNCHRONE;

        // IDs for classifiers for class NamedElement 


        // IDs for classifiers for class Namespace 

        static const int NAMESPACE__NAME = NAMEDELEMENT__NAME;

        // IDs for classifiers for class NetworkProperty 

        static const int NETWORKPROPERTY__NAME = NAMEDELEMENT__NAME;

        // IDs for classifiers for class NodeLink 


        // IDs for classifiers for class NodeNetwork 


        // IDs for classifiers for class NodeType 

        static const int NODETYPE__NAME = NAMEDELEMENT__NAME;

        static const int NODETYPE__DEPLOYUNITS = TYPEDEFINITION__DEPLOYUNITS;

        static const int NODETYPE__FACTORYBEAN = TYPEDEFINITION__FACTORYBEAN;

        static const int NODETYPE__BEAN = TYPEDEFINITION__BEAN;

        static const int NODETYPE__DICTIONARYTYPE =
                TYPEDEFINITION__DICTIONARYTYPE;

        static const int NODETYPE__SUPERTYPES = TYPEDEFINITION__SUPERTYPES;

        static const int NODETYPE__ABSTRACT = TYPEDEFINITION__ABSTRACT;

        static const int NODETYPE__STARTMETHOD =
                LIFECYCLETYPEDEFINITION__STARTMETHOD;

        static const int NODETYPE__STOPMETHOD =
                LIFECYCLETYPEDEFINITION__STOPMETHOD;

        static const int NODETYPE__UPDATEMETHOD =
                LIFECYCLETYPEDEFINITION__UPDATEMETHOD;

        // IDs for classifiers for class Operation 

        static const int OPERATION__NAME = NAMEDELEMENT__NAME;

        // IDs for classifiers for class Parameter 

        static const int PARAMETER__NAME = NAMEDELEMENT__NAME;

        // IDs for classifiers for class Port 


        // IDs for classifiers for class PortType 

        static const int PORTTYPE__NAME = NAMEDELEMENT__NAME;

        static const int PORTTYPE__DEPLOYUNITS = TYPEDEFINITION__DEPLOYUNITS;

        static const int PORTTYPE__FACTORYBEAN = TYPEDEFINITION__FACTORYBEAN;

        static const int PORTTYPE__BEAN = TYPEDEFINITION__BEAN;

        static const int PORTTYPE__DICTIONARYTYPE =
                TYPEDEFINITION__DICTIONARYTYPE;

        static const int PORTTYPE__SUPERTYPES = TYPEDEFINITION__SUPERTYPES;

        static const int PORTTYPE__ABSTRACT = TYPEDEFINITION__ABSTRACT;

        // IDs for classifiers for class PortTypeMapping 


        // IDs for classifiers for class PortTypeRef 

        static const int PORTTYPEREF__NAME = NAMEDELEMENT__NAME;

        // IDs for classifiers for class Repository 


        // IDs for classifiers for class ServicePortType 

        static const int SERVICEPORTTYPE__NAME = NAMEDELEMENT__NAME;

        static const int SERVICEPORTTYPE__DEPLOYUNITS =
                TYPEDEFINITION__DEPLOYUNITS;

        static const int SERVICEPORTTYPE__FACTORYBEAN =
                TYPEDEFINITION__FACTORYBEAN;

        static const int SERVICEPORTTYPE__BEAN = TYPEDEFINITION__BEAN;

        static const int SERVICEPORTTYPE__DICTIONARYTYPE =
                TYPEDEFINITION__DICTIONARYTYPE;

        static const int SERVICEPORTTYPE__SUPERTYPES =
                TYPEDEFINITION__SUPERTYPES;

        static const int SERVICEPORTTYPE__ABSTRACT = TYPEDEFINITION__ABSTRACT;

        static const int SERVICEPORTTYPE__SYNCHRONE = PORTTYPE__SYNCHRONE;

        // IDs for classifiers for class TypeDefinition 

        static const int TYPEDEFINITION__NAME = NAMEDELEMENT__NAME;

        // IDs for classifiers for class TypedElement 

        static const int TYPEDELEMENT__NAME = NAMEDELEMENT__NAME;

        // IDs for classifiers for class TypeLibrary 

        static const int TYPELIBRARY__NAME = NAMEDELEMENT__NAME;

        // IDs for classifiers for class Wire 


        // EClassifiers methods

        virtual ::ecore::EClass_ptr getComponentInstance();

        virtual ::ecore::EClass_ptr getComponentType();

        virtual ::ecore::EClass_ptr getContainerNode();

        virtual ::ecore::EClass_ptr getContainerRoot();

        virtual ::ecore::EClass_ptr getPortType();

        virtual ::ecore::EClass_ptr getPort();

        virtual ::ecore::EClass_ptr getNamespace();

        virtual ::ecore::EClass_ptr getDictionary();

        virtual ::ecore::EClass_ptr getDictionaryType();

        virtual ::ecore::EClass_ptr getDictionaryAttribute();

        virtual ::ecore::EClass_ptr getDictionaryValue();

        virtual ::ecore::EClass_ptr getCompositeType();

        virtual ::ecore::EClass_ptr getPortTypeRef();

        virtual ::ecore::EClass_ptr getWire();

        virtual ::ecore::EClass_ptr getServicePortType();

        virtual ::ecore::EClass_ptr getOperation();

        virtual ::ecore::EClass_ptr getParameter();

        virtual ::ecore::EClass_ptr getTypedElement();

        virtual ::ecore::EClass_ptr getMessagePortType();

        virtual ::ecore::EClass_ptr getRepository();

        virtual ::ecore::EClass_ptr getDeployUnit();

        virtual ::ecore::EClass_ptr getTypeLibrary();

        virtual ::ecore::EClass_ptr getNamedElement();

        virtual ::ecore::EClass_ptr getIntegrationPattern();

        virtual ::ecore::EClass_ptr getExtraFonctionalProperty();

        virtual ::ecore::EClass_ptr getPortTypeMapping();

        virtual ::ecore::EClass_ptr getChannel();

        virtual ::ecore::EClass_ptr getMBinding();

        virtual ::ecore::EClass_ptr getNodeNetwork();

        virtual ::ecore::EClass_ptr getNodeLink();

        virtual ::ecore::EClass_ptr getNetworkProperty();

        virtual ::ecore::EClass_ptr getChannelType();

        virtual ::ecore::EClass_ptr getTypeDefinition();

        virtual ::ecore::EClass_ptr getInstance();

        virtual ::ecore::EClass_ptr getLifeCycleTypeDefinition();

        virtual ::ecore::EClass_ptr getGroup();

        virtual ::ecore::EClass_ptr getGroupType();

        virtual ::ecore::EClass_ptr getNodeType();

        virtual ::ecore::EClass_ptr getAdaptationPrimitiveType();

        virtual ::ecore::EClass_ptr getAdaptationPrimitiveTypeRef();

        // EStructuralFeatures methods

        virtual ::ecore::EAttribute_ptr getNamedElement__name();

        virtual ::ecore::EReference_ptr getInstance__typeDefinition();

        virtual ::ecore::EReference_ptr getInstance__dictionary();

        virtual ::ecore::EAttribute_ptr getInstance__metaData();

        virtual ::ecore::EAttribute_ptr getInstance__started();

        virtual ::ecore::EReference_ptr getComponentInstance__provided();

        virtual ::ecore::EReference_ptr getComponentInstance__required();

        virtual ::ecore::EReference_ptr getComponentInstance__namespace();

        virtual ::ecore::EReference_ptr getTypeDefinition__deployUnits();

        virtual ::ecore::EAttribute_ptr getTypeDefinition__factoryBean();

        virtual ::ecore::EAttribute_ptr getTypeDefinition__bean();

        virtual ::ecore::EReference_ptr getTypeDefinition__dictionaryType();

        virtual ::ecore::EReference_ptr getTypeDefinition__superTypes();

        virtual ::ecore::EAttribute_ptr getTypeDefinition__abstract();

        virtual ::ecore::EAttribute_ptr
                getLifeCycleTypeDefinition__startMethod();

        virtual ::ecore::EAttribute_ptr
                getLifeCycleTypeDefinition__stopMethod();

        virtual ::ecore::EAttribute_ptr
                getLifeCycleTypeDefinition__updateMethod();

        virtual ::ecore::EReference_ptr getComponentType__required();

        virtual ::ecore::EReference_ptr getComponentType__integrationPatterns();

        virtual ::ecore::EReference_ptr
                getComponentType__extraFonctionalProperties();

        virtual ::ecore::EReference_ptr getComponentType__provided();

        virtual ::ecore::EReference_ptr getContainerNode__components();

        virtual ::ecore::EReference_ptr getContainerNode__hosts();

        virtual ::ecore::EReference_ptr getContainerNode__host();

        virtual ::ecore::EReference_ptr getContainerRoot__nodes();

        virtual ::ecore::EReference_ptr getContainerRoot__typeDefinitions();

        virtual ::ecore::EReference_ptr getContainerRoot__repositories();

        virtual ::ecore::EReference_ptr getContainerRoot__dataTypes();

        virtual ::ecore::EReference_ptr getContainerRoot__libraries();

        virtual ::ecore::EReference_ptr getContainerRoot__hubs();

        virtual ::ecore::EReference_ptr getContainerRoot__mBindings();

        virtual ::ecore::EReference_ptr getContainerRoot__deployUnits();

        virtual ::ecore::EReference_ptr getContainerRoot__nodeNetworks();

        virtual ::ecore::EReference_ptr getContainerRoot__groups();

        virtual ::ecore::EReference_ptr
                getContainerRoot__adaptationPrimitiveTypes();

        virtual ::ecore::EAttribute_ptr getPortType__synchrone();

        virtual ::ecore::EReference_ptr getPort__bindings();

        virtual ::ecore::EReference_ptr getPort__portTypeRef();

        virtual ::ecore::EReference_ptr getNamespace__childs();

        virtual ::ecore::EReference_ptr getNamespace__parent();

        virtual ::ecore::EReference_ptr getDictionary__values();

        virtual ::ecore::EReference_ptr getDictionaryType__attributes();

        virtual ::ecore::EReference_ptr getDictionaryType__defaultValues();

        virtual ::ecore::EReference_ptr getTypedElement__genericTypes();

        virtual ::ecore::EAttribute_ptr getDictionaryAttribute__optional();

        virtual ::ecore::EAttribute_ptr getDictionaryAttribute__state();

        virtual ::ecore::EAttribute_ptr getDictionaryAttribute__datatype();

        virtual ::ecore::EAttribute_ptr
                getDictionaryAttribute__fragmentDependant();

        virtual ::ecore::EReference_ptr getDictionaryValue__attribute();

        virtual ::ecore::EAttribute_ptr getDictionaryValue__value();

        virtual ::ecore::EReference_ptr getDictionaryValue__targetNode();

        virtual ::ecore::EReference_ptr getCompositeType__childs();

        virtual ::ecore::EReference_ptr getCompositeType__wires();

        virtual ::ecore::EReference_ptr getPortTypeRef__ref();

        virtual ::ecore::EReference_ptr getPortTypeRef__mappings();

        virtual ::ecore::EAttribute_ptr getPortTypeRef__optional();

        virtual ::ecore::EAttribute_ptr getPortTypeRef__noDependency();

        virtual ::ecore::EReference_ptr getWire__ports();

        virtual ::ecore::EReference_ptr getServicePortType__operations();

        virtual ::ecore::EAttribute_ptr getServicePortType__interface();

        virtual ::ecore::EReference_ptr getOperation__parameters();

        virtual ::ecore::EReference_ptr getOperation__returnType();

        virtual ::ecore::EReference_ptr getParameter__type();

        virtual ::ecore::EAttribute_ptr getParameter__order();

        virtual ::ecore::EReference_ptr getMessagePortType__filters();

        virtual ::ecore::EReference_ptr getRepository__units();

        virtual ::ecore::EAttribute_ptr getRepository__url();

        virtual ::ecore::EAttribute_ptr getDeployUnit__name();

        virtual ::ecore::EAttribute_ptr getDeployUnit__groupName();

        virtual ::ecore::EAttribute_ptr getDeployUnit__unitName();

        virtual ::ecore::EAttribute_ptr getDeployUnit__version();

        virtual ::ecore::EAttribute_ptr getDeployUnit__url();

        virtual ::ecore::EAttribute_ptr getDeployUnit__hashcode();

        virtual ::ecore::EReference_ptr getDeployUnit__requiredLibs();

        virtual ::ecore::EReference_ptr getDeployUnit__targetNodeType();

        virtual ::ecore::EAttribute_ptr getDeployUnit__type();

        virtual ::ecore::EReference_ptr getTypeLibrary__subTypes();

        virtual ::ecore::EReference_ptr
                getIntegrationPattern__extraFonctionalProperties();

        virtual ::ecore::EReference_ptr getIntegrationPattern__portTypes();

        virtual ::ecore::EReference_ptr getExtraFonctionalProperty__portTypes();

        virtual ::ecore::EAttribute_ptr getPortTypeMapping__beanMethodName();

        virtual ::ecore::EAttribute_ptr getPortTypeMapping__serviceMethodName();

        virtual ::ecore::EAttribute_ptr getPortTypeMapping__paramTypes();

        virtual ::ecore::EReference_ptr getChannel__bindings();

        virtual ::ecore::EReference_ptr getMBinding__port();

        virtual ::ecore::EReference_ptr getMBinding__hub();

        virtual ::ecore::EReference_ptr getNodeNetwork__link();

        virtual ::ecore::EReference_ptr getNodeNetwork__initBy();

        virtual ::ecore::EReference_ptr getNodeNetwork__target();

        virtual ::ecore::EAttribute_ptr getNodeLink__networkType();

        virtual ::ecore::EAttribute_ptr getNodeLink__estimatedRate();

        virtual ::ecore::EReference_ptr getNodeLink__networkProperties();

        virtual ::ecore::EAttribute_ptr getNodeLink__lastCheck();

        virtual ::ecore::EAttribute_ptr getNodeLink__zoneID();

        virtual ::ecore::EAttribute_ptr getNetworkProperty__value();

        virtual ::ecore::EAttribute_ptr getNetworkProperty__lastCheck();

        virtual ::ecore::EAttribute_ptr getChannelType__lowerBindings();

        virtual ::ecore::EAttribute_ptr getChannelType__upperBindings();

        virtual ::ecore::EAttribute_ptr getChannelType__lowerFragments();

        virtual ::ecore::EAttribute_ptr getChannelType__upperFragments();

        virtual ::ecore::EReference_ptr getGroup__subNodes();

        virtual ::ecore::EReference_ptr getNodeType__managedPrimitiveTypes();

        virtual ::ecore::EReference_ptr getNodeType__managedPrimitiveTypeRefs();

        virtual ::ecore::EReference_ptr getAdaptationPrimitiveTypeRef__ref();

        virtual ::ecore::EAttribute_ptr
                getAdaptationPrimitiveTypeRef__maxTime();

    protected:

        static std::auto_ptr< KevoreePackage > s_instance;

        KevoreePackage();

        // EClass instances 

        ::ecore::EClass_ptr m_ComponentInstanceEClass;

        ::ecore::EClass_ptr m_ComponentTypeEClass;

        ::ecore::EClass_ptr m_ContainerNodeEClass;

        ::ecore::EClass_ptr m_ContainerRootEClass;

        ::ecore::EClass_ptr m_PortTypeEClass;

        ::ecore::EClass_ptr m_PortEClass;

        ::ecore::EClass_ptr m_NamespaceEClass;

        ::ecore::EClass_ptr m_DictionaryEClass;

        ::ecore::EClass_ptr m_DictionaryTypeEClass;

        ::ecore::EClass_ptr m_DictionaryAttributeEClass;

        ::ecore::EClass_ptr m_DictionaryValueEClass;

        ::ecore::EClass_ptr m_CompositeTypeEClass;

        ::ecore::EClass_ptr m_PortTypeRefEClass;

        ::ecore::EClass_ptr m_WireEClass;

        ::ecore::EClass_ptr m_ServicePortTypeEClass;

        ::ecore::EClass_ptr m_OperationEClass;

        ::ecore::EClass_ptr m_ParameterEClass;

        ::ecore::EClass_ptr m_TypedElementEClass;

        ::ecore::EClass_ptr m_MessagePortTypeEClass;

        ::ecore::EClass_ptr m_RepositoryEClass;

        ::ecore::EClass_ptr m_DeployUnitEClass;

        ::ecore::EClass_ptr m_TypeLibraryEClass;

        ::ecore::EClass_ptr m_NamedElementEClass;

        ::ecore::EClass_ptr m_IntegrationPatternEClass;

        ::ecore::EClass_ptr m_ExtraFonctionalPropertyEClass;

        ::ecore::EClass_ptr m_PortTypeMappingEClass;

        ::ecore::EClass_ptr m_ChannelEClass;

        ::ecore::EClass_ptr m_MBindingEClass;

        ::ecore::EClass_ptr m_NodeNetworkEClass;

        ::ecore::EClass_ptr m_NodeLinkEClass;

        ::ecore::EClass_ptr m_NetworkPropertyEClass;

        ::ecore::EClass_ptr m_ChannelTypeEClass;

        ::ecore::EClass_ptr m_TypeDefinitionEClass;

        ::ecore::EClass_ptr m_InstanceEClass;

        ::ecore::EClass_ptr m_LifeCycleTypeDefinitionEClass;

        ::ecore::EClass_ptr m_GroupEClass;

        ::ecore::EClass_ptr m_GroupTypeEClass;

        ::ecore::EClass_ptr m_NodeTypeEClass;

        ::ecore::EClass_ptr m_AdaptationPrimitiveTypeEClass;

        ::ecore::EClass_ptr m_AdaptationPrimitiveTypeRefEClass;

        // EEnuminstances 


        // EDataType instances 


        // EStructuralFeatures instances

        ::ecore::EAttribute_ptr m_NamedElement__name;

        ::ecore::EReference_ptr m_Instance__typeDefinition;

        ::ecore::EReference_ptr m_Instance__dictionary;

        ::ecore::EAttribute_ptr m_Instance__metaData;

        ::ecore::EAttribute_ptr m_Instance__started;

        ::ecore::EReference_ptr m_ComponentInstance__provided;

        ::ecore::EReference_ptr m_ComponentInstance__required;

        ::ecore::EReference_ptr m_ComponentInstance__namespace;

        ::ecore::EReference_ptr m_TypeDefinition__deployUnits;

        ::ecore::EAttribute_ptr m_TypeDefinition__factoryBean;

        ::ecore::EAttribute_ptr m_TypeDefinition__bean;

        ::ecore::EReference_ptr m_TypeDefinition__dictionaryType;

        ::ecore::EReference_ptr m_TypeDefinition__superTypes;

        ::ecore::EAttribute_ptr m_TypeDefinition__abstract;

        ::ecore::EAttribute_ptr m_LifeCycleTypeDefinition__startMethod;

        ::ecore::EAttribute_ptr m_LifeCycleTypeDefinition__stopMethod;

        ::ecore::EAttribute_ptr m_LifeCycleTypeDefinition__updateMethod;

        ::ecore::EReference_ptr m_ComponentType__required;

        ::ecore::EReference_ptr m_ComponentType__integrationPatterns;

        ::ecore::EReference_ptr m_ComponentType__extraFonctionalProperties;

        ::ecore::EReference_ptr m_ComponentType__provided;

        ::ecore::EReference_ptr m_ContainerNode__components;

        ::ecore::EReference_ptr m_ContainerNode__hosts;

        ::ecore::EReference_ptr m_ContainerNode__host;

        ::ecore::EReference_ptr m_ContainerRoot__nodes;

        ::ecore::EReference_ptr m_ContainerRoot__typeDefinitions;

        ::ecore::EReference_ptr m_ContainerRoot__repositories;

        ::ecore::EReference_ptr m_ContainerRoot__dataTypes;

        ::ecore::EReference_ptr m_ContainerRoot__libraries;

        ::ecore::EReference_ptr m_ContainerRoot__hubs;

        ::ecore::EReference_ptr m_ContainerRoot__mBindings;

        ::ecore::EReference_ptr m_ContainerRoot__deployUnits;

        ::ecore::EReference_ptr m_ContainerRoot__nodeNetworks;

        ::ecore::EReference_ptr m_ContainerRoot__groups;

        ::ecore::EReference_ptr m_ContainerRoot__adaptationPrimitiveTypes;

        ::ecore::EAttribute_ptr m_PortType__synchrone;

        ::ecore::EReference_ptr m_Port__bindings;

        ::ecore::EReference_ptr m_Port__portTypeRef;

        ::ecore::EReference_ptr m_Namespace__childs;

        ::ecore::EReference_ptr m_Namespace__parent;

        ::ecore::EReference_ptr m_Dictionary__values;

        ::ecore::EReference_ptr m_DictionaryType__attributes;

        ::ecore::EReference_ptr m_DictionaryType__defaultValues;

        ::ecore::EReference_ptr m_TypedElement__genericTypes;

        ::ecore::EAttribute_ptr m_DictionaryAttribute__optional;

        ::ecore::EAttribute_ptr m_DictionaryAttribute__state;

        ::ecore::EAttribute_ptr m_DictionaryAttribute__datatype;

        ::ecore::EAttribute_ptr m_DictionaryAttribute__fragmentDependant;

        ::ecore::EReference_ptr m_DictionaryValue__attribute;

        ::ecore::EAttribute_ptr m_DictionaryValue__value;

        ::ecore::EReference_ptr m_DictionaryValue__targetNode;

        ::ecore::EReference_ptr m_CompositeType__childs;

        ::ecore::EReference_ptr m_CompositeType__wires;

        ::ecore::EReference_ptr m_PortTypeRef__ref;

        ::ecore::EReference_ptr m_PortTypeRef__mappings;

        ::ecore::EAttribute_ptr m_PortTypeRef__optional;

        ::ecore::EAttribute_ptr m_PortTypeRef__noDependency;

        ::ecore::EReference_ptr m_Wire__ports;

        ::ecore::EReference_ptr m_ServicePortType__operations;

        ::ecore::EAttribute_ptr m_ServicePortType__interface;

        ::ecore::EReference_ptr m_Operation__parameters;

        ::ecore::EReference_ptr m_Operation__returnType;

        ::ecore::EReference_ptr m_Parameter__type;

        ::ecore::EAttribute_ptr m_Parameter__order;

        ::ecore::EReference_ptr m_MessagePortType__filters;

        ::ecore::EReference_ptr m_Repository__units;

        ::ecore::EAttribute_ptr m_Repository__url;

        ::ecore::EAttribute_ptr m_DeployUnit__name;

        ::ecore::EAttribute_ptr m_DeployUnit__groupName;

        ::ecore::EAttribute_ptr m_DeployUnit__unitName;

        ::ecore::EAttribute_ptr m_DeployUnit__version;

        ::ecore::EAttribute_ptr m_DeployUnit__url;

        ::ecore::EAttribute_ptr m_DeployUnit__hashcode;

        ::ecore::EReference_ptr m_DeployUnit__requiredLibs;

        ::ecore::EReference_ptr m_DeployUnit__targetNodeType;

        ::ecore::EAttribute_ptr m_DeployUnit__type;

        ::ecore::EReference_ptr m_TypeLibrary__subTypes;

        ::ecore::EReference_ptr m_IntegrationPattern__extraFonctionalProperties;

        ::ecore::EReference_ptr m_IntegrationPattern__portTypes;

        ::ecore::EReference_ptr m_ExtraFonctionalProperty__portTypes;

        ::ecore::EAttribute_ptr m_PortTypeMapping__beanMethodName;

        ::ecore::EAttribute_ptr m_PortTypeMapping__serviceMethodName;

        ::ecore::EAttribute_ptr m_PortTypeMapping__paramTypes;

        ::ecore::EReference_ptr m_Channel__bindings;

        ::ecore::EReference_ptr m_MBinding__port;

        ::ecore::EReference_ptr m_MBinding__hub;

        ::ecore::EReference_ptr m_NodeNetwork__link;

        ::ecore::EReference_ptr m_NodeNetwork__initBy;

        ::ecore::EReference_ptr m_NodeNetwork__target;

        ::ecore::EAttribute_ptr m_NodeLink__networkType;

        ::ecore::EAttribute_ptr m_NodeLink__estimatedRate;

        ::ecore::EReference_ptr m_NodeLink__networkProperties;

        ::ecore::EAttribute_ptr m_NodeLink__lastCheck;

        ::ecore::EAttribute_ptr m_NodeLink__zoneID;

        ::ecore::EAttribute_ptr m_NetworkProperty__value;

        ::ecore::EAttribute_ptr m_NetworkProperty__lastCheck;

        ::ecore::EAttribute_ptr m_ChannelType__lowerBindings;

        ::ecore::EAttribute_ptr m_ChannelType__upperBindings;

        ::ecore::EAttribute_ptr m_ChannelType__lowerFragments;

        ::ecore::EAttribute_ptr m_ChannelType__upperFragments;

        ::ecore::EReference_ptr m_Group__subNodes;

        ::ecore::EReference_ptr m_NodeType__managedPrimitiveTypes;

        ::ecore::EReference_ptr m_NodeType__managedPrimitiveTypeRefs;

        ::ecore::EReference_ptr m_AdaptationPrimitiveTypeRef__ref;

        ::ecore::EAttribute_ptr m_AdaptationPrimitiveTypeRef__maxTime;

    };

} // kevoree


#endif // _KEVOREEPACKAGE_HPP
