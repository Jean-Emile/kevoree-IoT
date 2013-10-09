// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/KevoreePackageImpl.cpp
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

#include <kevoree/KevoreePackage.hpp>
#include <kevoree/KevoreeFactory.hpp>
#include <ecore.hpp>
#include <ecore/EcorePackage.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EAttribute.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EOperation.hpp>
#include <ecore/EParameter.hpp>
#include <ecore/EEnum.hpp>
#include <ecore/EEnumLiteral.hpp>
#include <ecore/EDataType.hpp>
#include <ecore/EGenericType.hpp>
#include <ecore/ETypeParameter.hpp>
#include <ecore/EcorePackage.hpp>

using namespace ::kevoree;

KevoreePackage::KevoreePackage()
{

    s_instance.reset(this);

    // Factory
    ::ecore::EFactory_ptr _fa = KevoreeFactory::_instance();
    setEFactoryInstance(_fa);
    _fa->setEPackage(this);

    // Create classes and their features

    // ComponentInstance
    m_ComponentInstanceEClass = new ::ecore::EClass();
    m_ComponentInstanceEClass->setClassifierID(COMPONENTINSTANCE);
    m_ComponentInstanceEClass->setEPackage(this);
    getEClassifiers().push_back(m_ComponentInstanceEClass);
    m_ComponentInstance__provided = new ::ecore::EReference();
    m_ComponentInstance__provided->setFeatureID(
            ::kevoree::KevoreePackage::COMPONENTINSTANCE__PROVIDED);
    m_ComponentInstanceEClass->getEStructuralFeatures().push_back(
            m_ComponentInstance__provided);
    m_ComponentInstance__required = new ::ecore::EReference();
    m_ComponentInstance__required->setFeatureID(
            ::kevoree::KevoreePackage::COMPONENTINSTANCE__REQUIRED);
    m_ComponentInstanceEClass->getEStructuralFeatures().push_back(
            m_ComponentInstance__required);
    m_ComponentInstance__namespace = new ::ecore::EReference();
    m_ComponentInstance__namespace->setFeatureID(
            ::kevoree::KevoreePackage::COMPONENTINSTANCE__NAMESPACE);
    m_ComponentInstanceEClass->getEStructuralFeatures().push_back(
            m_ComponentInstance__namespace);

    // ComponentType
    m_ComponentTypeEClass = new ::ecore::EClass();
    m_ComponentTypeEClass->setClassifierID(COMPONENTTYPE);
    m_ComponentTypeEClass->setEPackage(this);
    getEClassifiers().push_back(m_ComponentTypeEClass);
    m_ComponentType__required = new ::ecore::EReference();
    m_ComponentType__required->setFeatureID(
            ::kevoree::KevoreePackage::COMPONENTTYPE__REQUIRED);
    m_ComponentTypeEClass->getEStructuralFeatures().push_back(
            m_ComponentType__required);
    m_ComponentType__integrationPatterns = new ::ecore::EReference();
    m_ComponentType__integrationPatterns->setFeatureID(
            ::kevoree::KevoreePackage::COMPONENTTYPE__INTEGRATIONPATTERNS);
    m_ComponentTypeEClass->getEStructuralFeatures().push_back(
            m_ComponentType__integrationPatterns);
    m_ComponentType__extraFonctionalProperties = new ::ecore::EReference();
    m_ComponentType__extraFonctionalProperties->setFeatureID(
            ::kevoree::KevoreePackage::COMPONENTTYPE__EXTRAFONCTIONALPROPERTIES);
    m_ComponentTypeEClass->getEStructuralFeatures().push_back(
            m_ComponentType__extraFonctionalProperties);
    m_ComponentType__provided = new ::ecore::EReference();
    m_ComponentType__provided->setFeatureID(
            ::kevoree::KevoreePackage::COMPONENTTYPE__PROVIDED);
    m_ComponentTypeEClass->getEStructuralFeatures().push_back(
            m_ComponentType__provided);

    // ContainerNode
    m_ContainerNodeEClass = new ::ecore::EClass();
    m_ContainerNodeEClass->setClassifierID(CONTAINERNODE);
    m_ContainerNodeEClass->setEPackage(this);
    getEClassifiers().push_back(m_ContainerNodeEClass);
    m_ContainerNode__components = new ::ecore::EReference();
    m_ContainerNode__components->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERNODE__COMPONENTS);
    m_ContainerNodeEClass->getEStructuralFeatures().push_back(
            m_ContainerNode__components);
    m_ContainerNode__hosts = new ::ecore::EReference();
    m_ContainerNode__hosts->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERNODE__HOSTS);
    m_ContainerNodeEClass->getEStructuralFeatures().push_back(
            m_ContainerNode__hosts);
    m_ContainerNode__host = new ::ecore::EReference();
    m_ContainerNode__host->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERNODE__HOST);
    m_ContainerNodeEClass->getEStructuralFeatures().push_back(
            m_ContainerNode__host);

    // ContainerRoot
    m_ContainerRootEClass = new ::ecore::EClass();
    m_ContainerRootEClass->setClassifierID(CONTAINERROOT);
    m_ContainerRootEClass->setEPackage(this);
    getEClassifiers().push_back(m_ContainerRootEClass);
    m_ContainerRoot__nodes = new ::ecore::EReference();
    m_ContainerRoot__nodes->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERROOT__NODES);
    m_ContainerRootEClass->getEStructuralFeatures().push_back(
            m_ContainerRoot__nodes);
    m_ContainerRoot__typeDefinitions = new ::ecore::EReference();
    m_ContainerRoot__typeDefinitions->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERROOT__TYPEDEFINITIONS);
    m_ContainerRootEClass->getEStructuralFeatures().push_back(
            m_ContainerRoot__typeDefinitions);
    m_ContainerRoot__repositories = new ::ecore::EReference();
    m_ContainerRoot__repositories->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERROOT__REPOSITORIES);
    m_ContainerRootEClass->getEStructuralFeatures().push_back(
            m_ContainerRoot__repositories);
    m_ContainerRoot__dataTypes = new ::ecore::EReference();
    m_ContainerRoot__dataTypes->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERROOT__DATATYPES);
    m_ContainerRootEClass->getEStructuralFeatures().push_back(
            m_ContainerRoot__dataTypes);
    m_ContainerRoot__libraries = new ::ecore::EReference();
    m_ContainerRoot__libraries->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERROOT__LIBRARIES);
    m_ContainerRootEClass->getEStructuralFeatures().push_back(
            m_ContainerRoot__libraries);
    m_ContainerRoot__hubs = new ::ecore::EReference();
    m_ContainerRoot__hubs->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERROOT__HUBS);
    m_ContainerRootEClass->getEStructuralFeatures().push_back(
            m_ContainerRoot__hubs);
    m_ContainerRoot__mBindings = new ::ecore::EReference();
    m_ContainerRoot__mBindings->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERROOT__MBINDINGS);
    m_ContainerRootEClass->getEStructuralFeatures().push_back(
            m_ContainerRoot__mBindings);
    m_ContainerRoot__deployUnits = new ::ecore::EReference();
    m_ContainerRoot__deployUnits->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERROOT__DEPLOYUNITS);
    m_ContainerRootEClass->getEStructuralFeatures().push_back(
            m_ContainerRoot__deployUnits);
    m_ContainerRoot__nodeNetworks = new ::ecore::EReference();
    m_ContainerRoot__nodeNetworks->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERROOT__NODENETWORKS);
    m_ContainerRootEClass->getEStructuralFeatures().push_back(
            m_ContainerRoot__nodeNetworks);
    m_ContainerRoot__groups = new ::ecore::EReference();
    m_ContainerRoot__groups->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERROOT__GROUPS);
    m_ContainerRootEClass->getEStructuralFeatures().push_back(
            m_ContainerRoot__groups);
    m_ContainerRoot__adaptationPrimitiveTypes = new ::ecore::EReference();
    m_ContainerRoot__adaptationPrimitiveTypes->setFeatureID(
            ::kevoree::KevoreePackage::CONTAINERROOT__ADAPTATIONPRIMITIVETYPES);
    m_ContainerRootEClass->getEStructuralFeatures().push_back(
            m_ContainerRoot__adaptationPrimitiveTypes);

    // PortType
    m_PortTypeEClass = new ::ecore::EClass();
    m_PortTypeEClass->setClassifierID(PORTTYPE);
    m_PortTypeEClass->setEPackage(this);
    getEClassifiers().push_back(m_PortTypeEClass);
    m_PortType__synchrone = new ::ecore::EAttribute();
    m_PortType__synchrone->setFeatureID(
            ::kevoree::KevoreePackage::PORTTYPE__SYNCHRONE);
    m_PortTypeEClass->getEStructuralFeatures().push_back(m_PortType__synchrone);

    // Port
    m_PortEClass = new ::ecore::EClass();
    m_PortEClass->setClassifierID(PORT);
    m_PortEClass->setEPackage(this);
    getEClassifiers().push_back(m_PortEClass);
    m_Port__bindings = new ::ecore::EReference();
    m_Port__bindings->setFeatureID(::kevoree::KevoreePackage::PORT__BINDINGS);
    m_PortEClass->getEStructuralFeatures().push_back(m_Port__bindings);
    m_Port__portTypeRef = new ::ecore::EReference();
    m_Port__portTypeRef->setFeatureID(
            ::kevoree::KevoreePackage::PORT__PORTTYPEREF);
    m_PortEClass->getEStructuralFeatures().push_back(m_Port__portTypeRef);

    // Namespace
    m_NamespaceEClass = new ::ecore::EClass();
    m_NamespaceEClass->setClassifierID(NAMESPACE);
    m_NamespaceEClass->setEPackage(this);
    getEClassifiers().push_back(m_NamespaceEClass);
    m_Namespace__childs = new ::ecore::EReference();
    m_Namespace__childs->setFeatureID(
            ::kevoree::KevoreePackage::NAMESPACE__CHILDS);
    m_NamespaceEClass->getEStructuralFeatures().push_back(m_Namespace__childs);
    m_Namespace__parent = new ::ecore::EReference();
    m_Namespace__parent->setFeatureID(
            ::kevoree::KevoreePackage::NAMESPACE__PARENT);
    m_NamespaceEClass->getEStructuralFeatures().push_back(m_Namespace__parent);

    // Dictionary
    m_DictionaryEClass = new ::ecore::EClass();
    m_DictionaryEClass->setClassifierID(DICTIONARY);
    m_DictionaryEClass->setEPackage(this);
    getEClassifiers().push_back(m_DictionaryEClass);
    m_Dictionary__values = new ::ecore::EReference();
    m_Dictionary__values->setFeatureID(
            ::kevoree::KevoreePackage::DICTIONARY__VALUES);
    m_DictionaryEClass->getEStructuralFeatures().push_back(m_Dictionary__values);

    // DictionaryType
    m_DictionaryTypeEClass = new ::ecore::EClass();
    m_DictionaryTypeEClass->setClassifierID(DICTIONARYTYPE);
    m_DictionaryTypeEClass->setEPackage(this);
    getEClassifiers().push_back(m_DictionaryTypeEClass);
    m_DictionaryType__attributes = new ::ecore::EReference();
    m_DictionaryType__attributes->setFeatureID(
            ::kevoree::KevoreePackage::DICTIONARYTYPE__ATTRIBUTES);
    m_DictionaryTypeEClass->getEStructuralFeatures().push_back(
            m_DictionaryType__attributes);
    m_DictionaryType__defaultValues = new ::ecore::EReference();
    m_DictionaryType__defaultValues->setFeatureID(
            ::kevoree::KevoreePackage::DICTIONARYTYPE__DEFAULTVALUES);
    m_DictionaryTypeEClass->getEStructuralFeatures().push_back(
            m_DictionaryType__defaultValues);

    // DictionaryAttribute
    m_DictionaryAttributeEClass = new ::ecore::EClass();
    m_DictionaryAttributeEClass->setClassifierID(DICTIONARYATTRIBUTE);
    m_DictionaryAttributeEClass->setEPackage(this);
    getEClassifiers().push_back(m_DictionaryAttributeEClass);
    m_DictionaryAttribute__optional = new ::ecore::EAttribute();
    m_DictionaryAttribute__optional->setFeatureID(
            ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__OPTIONAL);
    m_DictionaryAttributeEClass->getEStructuralFeatures().push_back(
            m_DictionaryAttribute__optional);
    m_DictionaryAttribute__state = new ::ecore::EAttribute();
    m_DictionaryAttribute__state->setFeatureID(
            ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__STATE);
    m_DictionaryAttributeEClass->getEStructuralFeatures().push_back(
            m_DictionaryAttribute__state);
    m_DictionaryAttribute__datatype = new ::ecore::EAttribute();
    m_DictionaryAttribute__datatype->setFeatureID(
            ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__DATATYPE);
    m_DictionaryAttributeEClass->getEStructuralFeatures().push_back(
            m_DictionaryAttribute__datatype);
    m_DictionaryAttribute__fragmentDependant = new ::ecore::EAttribute();
    m_DictionaryAttribute__fragmentDependant->setFeatureID(
            ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__FRAGMENTDEPENDANT);
    m_DictionaryAttributeEClass->getEStructuralFeatures().push_back(
            m_DictionaryAttribute__fragmentDependant);

    // DictionaryValue
    m_DictionaryValueEClass = new ::ecore::EClass();
    m_DictionaryValueEClass->setClassifierID(DICTIONARYVALUE);
    m_DictionaryValueEClass->setEPackage(this);
    getEClassifiers().push_back(m_DictionaryValueEClass);
    m_DictionaryValue__value = new ::ecore::EAttribute();
    m_DictionaryValue__value->setFeatureID(
            ::kevoree::KevoreePackage::DICTIONARYVALUE__VALUE);
    m_DictionaryValueEClass->getEStructuralFeatures().push_back(
            m_DictionaryValue__value);
    m_DictionaryValue__attribute = new ::ecore::EReference();
    m_DictionaryValue__attribute->setFeatureID(
            ::kevoree::KevoreePackage::DICTIONARYVALUE__ATTRIBUTE);
    m_DictionaryValueEClass->getEStructuralFeatures().push_back(
            m_DictionaryValue__attribute);
    m_DictionaryValue__targetNode = new ::ecore::EReference();
    m_DictionaryValue__targetNode->setFeatureID(
            ::kevoree::KevoreePackage::DICTIONARYVALUE__TARGETNODE);
    m_DictionaryValueEClass->getEStructuralFeatures().push_back(
            m_DictionaryValue__targetNode);

    // CompositeType
    m_CompositeTypeEClass = new ::ecore::EClass();
    m_CompositeTypeEClass->setClassifierID(COMPOSITETYPE);
    m_CompositeTypeEClass->setEPackage(this);
    getEClassifiers().push_back(m_CompositeTypeEClass);
    m_CompositeType__childs = new ::ecore::EReference();
    m_CompositeType__childs->setFeatureID(
            ::kevoree::KevoreePackage::COMPOSITETYPE__CHILDS);
    m_CompositeTypeEClass->getEStructuralFeatures().push_back(
            m_CompositeType__childs);
    m_CompositeType__wires = new ::ecore::EReference();
    m_CompositeType__wires->setFeatureID(
            ::kevoree::KevoreePackage::COMPOSITETYPE__WIRES);
    m_CompositeTypeEClass->getEStructuralFeatures().push_back(
            m_CompositeType__wires);

    // PortTypeRef
    m_PortTypeRefEClass = new ::ecore::EClass();
    m_PortTypeRefEClass->setClassifierID(PORTTYPEREF);
    m_PortTypeRefEClass->setEPackage(this);
    getEClassifiers().push_back(m_PortTypeRefEClass);
    m_PortTypeRef__optional = new ::ecore::EAttribute();
    m_PortTypeRef__optional->setFeatureID(
            ::kevoree::KevoreePackage::PORTTYPEREF__OPTIONAL);
    m_PortTypeRefEClass->getEStructuralFeatures().push_back(
            m_PortTypeRef__optional);
    m_PortTypeRef__noDependency = new ::ecore::EAttribute();
    m_PortTypeRef__noDependency->setFeatureID(
            ::kevoree::KevoreePackage::PORTTYPEREF__NODEPENDENCY);
    m_PortTypeRefEClass->getEStructuralFeatures().push_back(
            m_PortTypeRef__noDependency);
    m_PortTypeRef__ref = new ::ecore::EReference();
    m_PortTypeRef__ref->setFeatureID(
            ::kevoree::KevoreePackage::PORTTYPEREF__REF);
    m_PortTypeRefEClass->getEStructuralFeatures().push_back(m_PortTypeRef__ref);
    m_PortTypeRef__mappings = new ::ecore::EReference();
    m_PortTypeRef__mappings->setFeatureID(
            ::kevoree::KevoreePackage::PORTTYPEREF__MAPPINGS);
    m_PortTypeRefEClass->getEStructuralFeatures().push_back(
            m_PortTypeRef__mappings);

    // Wire
    m_WireEClass = new ::ecore::EClass();
    m_WireEClass->setClassifierID(WIRE);
    m_WireEClass->setEPackage(this);
    getEClassifiers().push_back(m_WireEClass);
    m_Wire__ports = new ::ecore::EReference();
    m_Wire__ports->setFeatureID(::kevoree::KevoreePackage::WIRE__PORTS);
    m_WireEClass->getEStructuralFeatures().push_back(m_Wire__ports);

    // ServicePortType
    m_ServicePortTypeEClass = new ::ecore::EClass();
    m_ServicePortTypeEClass->setClassifierID(SERVICEPORTTYPE);
    m_ServicePortTypeEClass->setEPackage(this);
    getEClassifiers().push_back(m_ServicePortTypeEClass);
    m_ServicePortType__interface = new ::ecore::EAttribute();
    m_ServicePortType__interface->setFeatureID(
            ::kevoree::KevoreePackage::SERVICEPORTTYPE__INTERFACE);
    m_ServicePortTypeEClass->getEStructuralFeatures().push_back(
            m_ServicePortType__interface);
    m_ServicePortType__operations = new ::ecore::EReference();
    m_ServicePortType__operations->setFeatureID(
            ::kevoree::KevoreePackage::SERVICEPORTTYPE__OPERATIONS);
    m_ServicePortTypeEClass->getEStructuralFeatures().push_back(
            m_ServicePortType__operations);

    // Operation
    m_OperationEClass = new ::ecore::EClass();
    m_OperationEClass->setClassifierID(OPERATION);
    m_OperationEClass->setEPackage(this);
    getEClassifiers().push_back(m_OperationEClass);
    m_Operation__parameters = new ::ecore::EReference();
    m_Operation__parameters->setFeatureID(
            ::kevoree::KevoreePackage::OPERATION__PARAMETERS);
    m_OperationEClass->getEStructuralFeatures().push_back(
            m_Operation__parameters);
    m_Operation__returnType = new ::ecore::EReference();
    m_Operation__returnType->setFeatureID(
            ::kevoree::KevoreePackage::OPERATION__RETURNTYPE);
    m_OperationEClass->getEStructuralFeatures().push_back(
            m_Operation__returnType);

    // Parameter
    m_ParameterEClass = new ::ecore::EClass();
    m_ParameterEClass->setClassifierID(PARAMETER);
    m_ParameterEClass->setEPackage(this);
    getEClassifiers().push_back(m_ParameterEClass);
    m_Parameter__order = new ::ecore::EAttribute();
    m_Parameter__order->setFeatureID(
            ::kevoree::KevoreePackage::PARAMETER__ORDER);
    m_ParameterEClass->getEStructuralFeatures().push_back(m_Parameter__order);
    m_Parameter__type = new ::ecore::EReference();
    m_Parameter__type->setFeatureID(::kevoree::KevoreePackage::PARAMETER__TYPE);
    m_ParameterEClass->getEStructuralFeatures().push_back(m_Parameter__type);

    // TypedElement
    m_TypedElementEClass = new ::ecore::EClass();
    m_TypedElementEClass->setClassifierID(TYPEDELEMENT);
    m_TypedElementEClass->setEPackage(this);
    getEClassifiers().push_back(m_TypedElementEClass);
    m_TypedElement__genericTypes = new ::ecore::EReference();
    m_TypedElement__genericTypes->setFeatureID(
            ::kevoree::KevoreePackage::TYPEDELEMENT__GENERICTYPES);
    m_TypedElementEClass->getEStructuralFeatures().push_back(
            m_TypedElement__genericTypes);

    // MessagePortType
    m_MessagePortTypeEClass = new ::ecore::EClass();
    m_MessagePortTypeEClass->setClassifierID(MESSAGEPORTTYPE);
    m_MessagePortTypeEClass->setEPackage(this);
    getEClassifiers().push_back(m_MessagePortTypeEClass);
    m_MessagePortType__filters = new ::ecore::EReference();
    m_MessagePortType__filters->setFeatureID(
            ::kevoree::KevoreePackage::MESSAGEPORTTYPE__FILTERS);
    m_MessagePortTypeEClass->getEStructuralFeatures().push_back(
            m_MessagePortType__filters);

    // Repository
    m_RepositoryEClass = new ::ecore::EClass();
    m_RepositoryEClass->setClassifierID(REPOSITORY);
    m_RepositoryEClass->setEPackage(this);
    getEClassifiers().push_back(m_RepositoryEClass);
    m_Repository__url = new ::ecore::EAttribute();
    m_Repository__url->setFeatureID(::kevoree::KevoreePackage::REPOSITORY__URL);
    m_RepositoryEClass->getEStructuralFeatures().push_back(m_Repository__url);
    m_Repository__units = new ::ecore::EReference();
    m_Repository__units->setFeatureID(
            ::kevoree::KevoreePackage::REPOSITORY__UNITS);
    m_RepositoryEClass->getEStructuralFeatures().push_back(m_Repository__units);

    // DeployUnit
    m_DeployUnitEClass = new ::ecore::EClass();
    m_DeployUnitEClass->setClassifierID(DEPLOYUNIT);
    m_DeployUnitEClass->setEPackage(this);
    getEClassifiers().push_back(m_DeployUnitEClass);
    m_DeployUnit__name = new ::ecore::EAttribute();
    m_DeployUnit__name->setFeatureID(
            ::kevoree::KevoreePackage::DEPLOYUNIT__NAME);
    m_DeployUnitEClass->getEStructuralFeatures().push_back(m_DeployUnit__name);
    m_DeployUnit__groupName = new ::ecore::EAttribute();
    m_DeployUnit__groupName->setFeatureID(
            ::kevoree::KevoreePackage::DEPLOYUNIT__GROUPNAME);
    m_DeployUnitEClass->getEStructuralFeatures().push_back(
            m_DeployUnit__groupName);
    m_DeployUnit__unitName = new ::ecore::EAttribute();
    m_DeployUnit__unitName->setFeatureID(
            ::kevoree::KevoreePackage::DEPLOYUNIT__UNITNAME);
    m_DeployUnitEClass->getEStructuralFeatures().push_back(
            m_DeployUnit__unitName);
    m_DeployUnit__version = new ::ecore::EAttribute();
    m_DeployUnit__version->setFeatureID(
            ::kevoree::KevoreePackage::DEPLOYUNIT__VERSION);
    m_DeployUnitEClass->getEStructuralFeatures().push_back(
            m_DeployUnit__version);
    m_DeployUnit__url = new ::ecore::EAttribute();
    m_DeployUnit__url->setFeatureID(::kevoree::KevoreePackage::DEPLOYUNIT__URL);
    m_DeployUnitEClass->getEStructuralFeatures().push_back(m_DeployUnit__url);
    m_DeployUnit__hashcode = new ::ecore::EAttribute();
    m_DeployUnit__hashcode->setFeatureID(
            ::kevoree::KevoreePackage::DEPLOYUNIT__HASHCODE);
    m_DeployUnitEClass->getEStructuralFeatures().push_back(
            m_DeployUnit__hashcode);
    m_DeployUnit__type = new ::ecore::EAttribute();
    m_DeployUnit__type->setFeatureID(
            ::kevoree::KevoreePackage::DEPLOYUNIT__TYPE);
    m_DeployUnitEClass->getEStructuralFeatures().push_back(m_DeployUnit__type);
    m_DeployUnit__requiredLibs = new ::ecore::EReference();
    m_DeployUnit__requiredLibs->setFeatureID(
            ::kevoree::KevoreePackage::DEPLOYUNIT__REQUIREDLIBS);
    m_DeployUnitEClass->getEStructuralFeatures().push_back(
            m_DeployUnit__requiredLibs);
    m_DeployUnit__targetNodeType = new ::ecore::EReference();
    m_DeployUnit__targetNodeType->setFeatureID(
            ::kevoree::KevoreePackage::DEPLOYUNIT__TARGETNODETYPE);
    m_DeployUnitEClass->getEStructuralFeatures().push_back(
            m_DeployUnit__targetNodeType);

    // TypeLibrary
    m_TypeLibraryEClass = new ::ecore::EClass();
    m_TypeLibraryEClass->setClassifierID(TYPELIBRARY);
    m_TypeLibraryEClass->setEPackage(this);
    getEClassifiers().push_back(m_TypeLibraryEClass);
    m_TypeLibrary__subTypes = new ::ecore::EReference();
    m_TypeLibrary__subTypes->setFeatureID(
            ::kevoree::KevoreePackage::TYPELIBRARY__SUBTYPES);
    m_TypeLibraryEClass->getEStructuralFeatures().push_back(
            m_TypeLibrary__subTypes);

    // NamedElement
    m_NamedElementEClass = new ::ecore::EClass();
    m_NamedElementEClass->setClassifierID(NAMEDELEMENT);
    m_NamedElementEClass->setEPackage(this);
    getEClassifiers().push_back(m_NamedElementEClass);
    m_NamedElement__name = new ::ecore::EAttribute();
    m_NamedElement__name->setFeatureID(
            ::kevoree::KevoreePackage::NAMEDELEMENT__NAME);
    m_NamedElementEClass->getEStructuralFeatures().push_back(
            m_NamedElement__name);

    // IntegrationPattern
    m_IntegrationPatternEClass = new ::ecore::EClass();
    m_IntegrationPatternEClass->setClassifierID(INTEGRATIONPATTERN);
    m_IntegrationPatternEClass->setEPackage(this);
    getEClassifiers().push_back(m_IntegrationPatternEClass);
    m_IntegrationPattern__extraFonctionalProperties = new ::ecore::EReference();
    m_IntegrationPattern__extraFonctionalProperties->setFeatureID(
            ::kevoree::KevoreePackage::INTEGRATIONPATTERN__EXTRAFONCTIONALPROPERTIES);
    m_IntegrationPatternEClass->getEStructuralFeatures().push_back(
            m_IntegrationPattern__extraFonctionalProperties);
    m_IntegrationPattern__portTypes = new ::ecore::EReference();
    m_IntegrationPattern__portTypes->setFeatureID(
            ::kevoree::KevoreePackage::INTEGRATIONPATTERN__PORTTYPES);
    m_IntegrationPatternEClass->getEStructuralFeatures().push_back(
            m_IntegrationPattern__portTypes);

    // ExtraFonctionalProperty
    m_ExtraFonctionalPropertyEClass = new ::ecore::EClass();
    m_ExtraFonctionalPropertyEClass->setClassifierID(EXTRAFONCTIONALPROPERTY);
    m_ExtraFonctionalPropertyEClass->setEPackage(this);
    getEClassifiers().push_back(m_ExtraFonctionalPropertyEClass);
    m_ExtraFonctionalProperty__portTypes = new ::ecore::EReference();
    m_ExtraFonctionalProperty__portTypes->setFeatureID(
            ::kevoree::KevoreePackage::EXTRAFONCTIONALPROPERTY__PORTTYPES);
    m_ExtraFonctionalPropertyEClass->getEStructuralFeatures().push_back(
            m_ExtraFonctionalProperty__portTypes);

    // PortTypeMapping
    m_PortTypeMappingEClass = new ::ecore::EClass();
    m_PortTypeMappingEClass->setClassifierID(PORTTYPEMAPPING);
    m_PortTypeMappingEClass->setEPackage(this);
    getEClassifiers().push_back(m_PortTypeMappingEClass);
    m_PortTypeMapping__beanMethodName = new ::ecore::EAttribute();
    m_PortTypeMapping__beanMethodName->setFeatureID(
            ::kevoree::KevoreePackage::PORTTYPEMAPPING__BEANMETHODNAME);
    m_PortTypeMappingEClass->getEStructuralFeatures().push_back(
            m_PortTypeMapping__beanMethodName);
    m_PortTypeMapping__serviceMethodName = new ::ecore::EAttribute();
    m_PortTypeMapping__serviceMethodName->setFeatureID(
            ::kevoree::KevoreePackage::PORTTYPEMAPPING__SERVICEMETHODNAME);
    m_PortTypeMappingEClass->getEStructuralFeatures().push_back(
            m_PortTypeMapping__serviceMethodName);
    m_PortTypeMapping__paramTypes = new ::ecore::EAttribute();
    m_PortTypeMapping__paramTypes->setFeatureID(
            ::kevoree::KevoreePackage::PORTTYPEMAPPING__PARAMTYPES);
    m_PortTypeMappingEClass->getEStructuralFeatures().push_back(
            m_PortTypeMapping__paramTypes);

    // Channel
    m_ChannelEClass = new ::ecore::EClass();
    m_ChannelEClass->setClassifierID(CHANNEL);
    m_ChannelEClass->setEPackage(this);
    getEClassifiers().push_back(m_ChannelEClass);
    m_Channel__bindings = new ::ecore::EReference();
    m_Channel__bindings->setFeatureID(
            ::kevoree::KevoreePackage::CHANNEL__BINDINGS);
    m_ChannelEClass->getEStructuralFeatures().push_back(m_Channel__bindings);

    // MBinding
    m_MBindingEClass = new ::ecore::EClass();
    m_MBindingEClass->setClassifierID(MBINDING);
    m_MBindingEClass->setEPackage(this);
    getEClassifiers().push_back(m_MBindingEClass);
    m_MBinding__port = new ::ecore::EReference();
    m_MBinding__port->setFeatureID(::kevoree::KevoreePackage::MBINDING__PORT);
    m_MBindingEClass->getEStructuralFeatures().push_back(m_MBinding__port);
    m_MBinding__hub = new ::ecore::EReference();
    m_MBinding__hub->setFeatureID(::kevoree::KevoreePackage::MBINDING__HUB);
    m_MBindingEClass->getEStructuralFeatures().push_back(m_MBinding__hub);

    // NodeNetwork
    m_NodeNetworkEClass = new ::ecore::EClass();
    m_NodeNetworkEClass->setClassifierID(NODENETWORK);
    m_NodeNetworkEClass->setEPackage(this);
    getEClassifiers().push_back(m_NodeNetworkEClass);
    m_NodeNetwork__link = new ::ecore::EReference();
    m_NodeNetwork__link->setFeatureID(
            ::kevoree::KevoreePackage::NODENETWORK__LINK);
    m_NodeNetworkEClass->getEStructuralFeatures().push_back(m_NodeNetwork__link);
    m_NodeNetwork__initBy = new ::ecore::EReference();
    m_NodeNetwork__initBy->setFeatureID(
            ::kevoree::KevoreePackage::NODENETWORK__INITBY);
    m_NodeNetworkEClass->getEStructuralFeatures().push_back(
            m_NodeNetwork__initBy);
    m_NodeNetwork__target = new ::ecore::EReference();
    m_NodeNetwork__target->setFeatureID(
            ::kevoree::KevoreePackage::NODENETWORK__TARGET);
    m_NodeNetworkEClass->getEStructuralFeatures().push_back(
            m_NodeNetwork__target);

    // NodeLink
    m_NodeLinkEClass = new ::ecore::EClass();
    m_NodeLinkEClass->setClassifierID(NODELINK);
    m_NodeLinkEClass->setEPackage(this);
    getEClassifiers().push_back(m_NodeLinkEClass);
    m_NodeLink__networkType = new ::ecore::EAttribute();
    m_NodeLink__networkType->setFeatureID(
            ::kevoree::KevoreePackage::NODELINK__NETWORKTYPE);
    m_NodeLinkEClass->getEStructuralFeatures().push_back(
            m_NodeLink__networkType);
    m_NodeLink__estimatedRate = new ::ecore::EAttribute();
    m_NodeLink__estimatedRate->setFeatureID(
            ::kevoree::KevoreePackage::NODELINK__ESTIMATEDRATE);
    m_NodeLinkEClass->getEStructuralFeatures().push_back(
            m_NodeLink__estimatedRate);
    m_NodeLink__lastCheck = new ::ecore::EAttribute();
    m_NodeLink__lastCheck->setFeatureID(
            ::kevoree::KevoreePackage::NODELINK__LASTCHECK);
    m_NodeLinkEClass->getEStructuralFeatures().push_back(m_NodeLink__lastCheck);
    m_NodeLink__zoneID = new ::ecore::EAttribute();
    m_NodeLink__zoneID->setFeatureID(
            ::kevoree::KevoreePackage::NODELINK__ZONEID);
    m_NodeLinkEClass->getEStructuralFeatures().push_back(m_NodeLink__zoneID);
    m_NodeLink__networkProperties = new ::ecore::EReference();
    m_NodeLink__networkProperties->setFeatureID(
            ::kevoree::KevoreePackage::NODELINK__NETWORKPROPERTIES);
    m_NodeLinkEClass->getEStructuralFeatures().push_back(
            m_NodeLink__networkProperties);

    // NetworkProperty
    m_NetworkPropertyEClass = new ::ecore::EClass();
    m_NetworkPropertyEClass->setClassifierID(NETWORKPROPERTY);
    m_NetworkPropertyEClass->setEPackage(this);
    getEClassifiers().push_back(m_NetworkPropertyEClass);
    m_NetworkProperty__value = new ::ecore::EAttribute();
    m_NetworkProperty__value->setFeatureID(
            ::kevoree::KevoreePackage::NETWORKPROPERTY__VALUE);
    m_NetworkPropertyEClass->getEStructuralFeatures().push_back(
            m_NetworkProperty__value);
    m_NetworkProperty__lastCheck = new ::ecore::EAttribute();
    m_NetworkProperty__lastCheck->setFeatureID(
            ::kevoree::KevoreePackage::NETWORKPROPERTY__LASTCHECK);
    m_NetworkPropertyEClass->getEStructuralFeatures().push_back(
            m_NetworkProperty__lastCheck);

    // ChannelType
    m_ChannelTypeEClass = new ::ecore::EClass();
    m_ChannelTypeEClass->setClassifierID(CHANNELTYPE);
    m_ChannelTypeEClass->setEPackage(this);
    getEClassifiers().push_back(m_ChannelTypeEClass);
    m_ChannelType__lowerBindings = new ::ecore::EAttribute();
    m_ChannelType__lowerBindings->setFeatureID(
            ::kevoree::KevoreePackage::CHANNELTYPE__LOWERBINDINGS);
    m_ChannelTypeEClass->getEStructuralFeatures().push_back(
            m_ChannelType__lowerBindings);
    m_ChannelType__upperBindings = new ::ecore::EAttribute();
    m_ChannelType__upperBindings->setFeatureID(
            ::kevoree::KevoreePackage::CHANNELTYPE__UPPERBINDINGS);
    m_ChannelTypeEClass->getEStructuralFeatures().push_back(
            m_ChannelType__upperBindings);
    m_ChannelType__lowerFragments = new ::ecore::EAttribute();
    m_ChannelType__lowerFragments->setFeatureID(
            ::kevoree::KevoreePackage::CHANNELTYPE__LOWERFRAGMENTS);
    m_ChannelTypeEClass->getEStructuralFeatures().push_back(
            m_ChannelType__lowerFragments);
    m_ChannelType__upperFragments = new ::ecore::EAttribute();
    m_ChannelType__upperFragments->setFeatureID(
            ::kevoree::KevoreePackage::CHANNELTYPE__UPPERFRAGMENTS);
    m_ChannelTypeEClass->getEStructuralFeatures().push_back(
            m_ChannelType__upperFragments);

    // TypeDefinition
    m_TypeDefinitionEClass = new ::ecore::EClass();
    m_TypeDefinitionEClass->setClassifierID(TYPEDEFINITION);
    m_TypeDefinitionEClass->setEPackage(this);
    getEClassifiers().push_back(m_TypeDefinitionEClass);
    m_TypeDefinition__factoryBean = new ::ecore::EAttribute();
    m_TypeDefinition__factoryBean->setFeatureID(
            ::kevoree::KevoreePackage::TYPEDEFINITION__FACTORYBEAN);
    m_TypeDefinitionEClass->getEStructuralFeatures().push_back(
            m_TypeDefinition__factoryBean);
    m_TypeDefinition__bean = new ::ecore::EAttribute();
    m_TypeDefinition__bean->setFeatureID(
            ::kevoree::KevoreePackage::TYPEDEFINITION__BEAN);
    m_TypeDefinitionEClass->getEStructuralFeatures().push_back(
            m_TypeDefinition__bean);
    m_TypeDefinition__abstract = new ::ecore::EAttribute();
    m_TypeDefinition__abstract->setFeatureID(
            ::kevoree::KevoreePackage::TYPEDEFINITION__ABSTRACT);
    m_TypeDefinitionEClass->getEStructuralFeatures().push_back(
            m_TypeDefinition__abstract);
    m_TypeDefinition__deployUnits = new ::ecore::EReference();
    m_TypeDefinition__deployUnits->setFeatureID(
            ::kevoree::KevoreePackage::TYPEDEFINITION__DEPLOYUNITS);
    m_TypeDefinitionEClass->getEStructuralFeatures().push_back(
            m_TypeDefinition__deployUnits);
    m_TypeDefinition__dictionaryType = new ::ecore::EReference();
    m_TypeDefinition__dictionaryType->setFeatureID(
            ::kevoree::KevoreePackage::TYPEDEFINITION__DICTIONARYTYPE);
    m_TypeDefinitionEClass->getEStructuralFeatures().push_back(
            m_TypeDefinition__dictionaryType);
    m_TypeDefinition__superTypes = new ::ecore::EReference();
    m_TypeDefinition__superTypes->setFeatureID(
            ::kevoree::KevoreePackage::TYPEDEFINITION__SUPERTYPES);
    m_TypeDefinitionEClass->getEStructuralFeatures().push_back(
            m_TypeDefinition__superTypes);

    // Instance
    m_InstanceEClass = new ::ecore::EClass();
    m_InstanceEClass->setClassifierID(INSTANCE);
    m_InstanceEClass->setEPackage(this);
    getEClassifiers().push_back(m_InstanceEClass);
    m_Instance__metaData = new ::ecore::EAttribute();
    m_Instance__metaData->setFeatureID(
            ::kevoree::KevoreePackage::INSTANCE__METADATA);
    m_InstanceEClass->getEStructuralFeatures().push_back(m_Instance__metaData);
    m_Instance__started = new ::ecore::EAttribute();
    m_Instance__started->setFeatureID(
            ::kevoree::KevoreePackage::INSTANCE__STARTED);
    m_InstanceEClass->getEStructuralFeatures().push_back(m_Instance__started);
    m_Instance__typeDefinition = new ::ecore::EReference();
    m_Instance__typeDefinition->setFeatureID(
            ::kevoree::KevoreePackage::INSTANCE__TYPEDEFINITION);
    m_InstanceEClass->getEStructuralFeatures().push_back(
            m_Instance__typeDefinition);
    m_Instance__dictionary = new ::ecore::EReference();
    m_Instance__dictionary->setFeatureID(
            ::kevoree::KevoreePackage::INSTANCE__DICTIONARY);
    m_InstanceEClass->getEStructuralFeatures().push_back(m_Instance__dictionary);

    // LifeCycleTypeDefinition
    m_LifeCycleTypeDefinitionEClass = new ::ecore::EClass();
    m_LifeCycleTypeDefinitionEClass->setClassifierID(LIFECYCLETYPEDEFINITION);
    m_LifeCycleTypeDefinitionEClass->setEPackage(this);
    getEClassifiers().push_back(m_LifeCycleTypeDefinitionEClass);
    m_LifeCycleTypeDefinition__startMethod = new ::ecore::EAttribute();
    m_LifeCycleTypeDefinition__startMethod->setFeatureID(
            ::kevoree::KevoreePackage::LIFECYCLETYPEDEFINITION__STARTMETHOD);
    m_LifeCycleTypeDefinitionEClass->getEStructuralFeatures().push_back(
            m_LifeCycleTypeDefinition__startMethod);
    m_LifeCycleTypeDefinition__stopMethod = new ::ecore::EAttribute();
    m_LifeCycleTypeDefinition__stopMethod->setFeatureID(
            ::kevoree::KevoreePackage::LIFECYCLETYPEDEFINITION__STOPMETHOD);
    m_LifeCycleTypeDefinitionEClass->getEStructuralFeatures().push_back(
            m_LifeCycleTypeDefinition__stopMethod);
    m_LifeCycleTypeDefinition__updateMethod = new ::ecore::EAttribute();
    m_LifeCycleTypeDefinition__updateMethod->setFeatureID(
            ::kevoree::KevoreePackage::LIFECYCLETYPEDEFINITION__UPDATEMETHOD);
    m_LifeCycleTypeDefinitionEClass->getEStructuralFeatures().push_back(
            m_LifeCycleTypeDefinition__updateMethod);

    // Group
    m_GroupEClass = new ::ecore::EClass();
    m_GroupEClass->setClassifierID(GROUP);
    m_GroupEClass->setEPackage(this);
    getEClassifiers().push_back(m_GroupEClass);
    m_Group__subNodes = new ::ecore::EReference();
    m_Group__subNodes->setFeatureID(::kevoree::KevoreePackage::GROUP__SUBNODES);
    m_GroupEClass->getEStructuralFeatures().push_back(m_Group__subNodes);

    // GroupType
    m_GroupTypeEClass = new ::ecore::EClass();
    m_GroupTypeEClass->setClassifierID(GROUPTYPE);
    m_GroupTypeEClass->setEPackage(this);
    getEClassifiers().push_back(m_GroupTypeEClass);

    // NodeType
    m_NodeTypeEClass = new ::ecore::EClass();
    m_NodeTypeEClass->setClassifierID(NODETYPE);
    m_NodeTypeEClass->setEPackage(this);
    getEClassifiers().push_back(m_NodeTypeEClass);
    m_NodeType__managedPrimitiveTypes = new ::ecore::EReference();
    m_NodeType__managedPrimitiveTypes->setFeatureID(
            ::kevoree::KevoreePackage::NODETYPE__MANAGEDPRIMITIVETYPES);
    m_NodeTypeEClass->getEStructuralFeatures().push_back(
            m_NodeType__managedPrimitiveTypes);
    m_NodeType__managedPrimitiveTypeRefs = new ::ecore::EReference();
    m_NodeType__managedPrimitiveTypeRefs->setFeatureID(
            ::kevoree::KevoreePackage::NODETYPE__MANAGEDPRIMITIVETYPEREFS);
    m_NodeTypeEClass->getEStructuralFeatures().push_back(
            m_NodeType__managedPrimitiveTypeRefs);

    // AdaptationPrimitiveType
    m_AdaptationPrimitiveTypeEClass = new ::ecore::EClass();
    m_AdaptationPrimitiveTypeEClass->setClassifierID(ADAPTATIONPRIMITIVETYPE);
    m_AdaptationPrimitiveTypeEClass->setEPackage(this);
    getEClassifiers().push_back(m_AdaptationPrimitiveTypeEClass);

    // AdaptationPrimitiveTypeRef
    m_AdaptationPrimitiveTypeRefEClass = new ::ecore::EClass();
    m_AdaptationPrimitiveTypeRefEClass->setClassifierID(
            ADAPTATIONPRIMITIVETYPEREF);
    m_AdaptationPrimitiveTypeRefEClass->setEPackage(this);
    getEClassifiers().push_back(m_AdaptationPrimitiveTypeRefEClass);
    m_AdaptationPrimitiveTypeRef__maxTime = new ::ecore::EAttribute();
    m_AdaptationPrimitiveTypeRef__maxTime->setFeatureID(
            ::kevoree::KevoreePackage::ADAPTATIONPRIMITIVETYPEREF__MAXTIME);
    m_AdaptationPrimitiveTypeRefEClass->getEStructuralFeatures().push_back(
            m_AdaptationPrimitiveTypeRef__maxTime);
    m_AdaptationPrimitiveTypeRef__ref = new ::ecore::EReference();
    m_AdaptationPrimitiveTypeRef__ref->setFeatureID(
            ::kevoree::KevoreePackage::ADAPTATIONPRIMITIVETYPEREF__REF);
    m_AdaptationPrimitiveTypeRefEClass->getEStructuralFeatures().push_back(
            m_AdaptationPrimitiveTypeRef__ref);

    // Create enums


    // Create data types


    // Initialize package
    setName("kevoree");
    setNsPrefix("kevoree");
    setNsURI("http://kevoree/1.0");

    // TODO: bounds for type parameters

    // Add supertypes to classes
    m_ComponentInstanceEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_ComponentInstanceEClass->getESuperTypes().push_back(m_InstanceEClass);
    m_ComponentTypeEClass->getESuperTypes().push_back(
            m_LifeCycleTypeDefinitionEClass);
    m_ContainerNodeEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_ContainerNodeEClass->getESuperTypes().push_back(m_InstanceEClass);
    m_PortTypeEClass->getESuperTypes().push_back(m_TypeDefinitionEClass);
    m_NamespaceEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_DictionaryAttributeEClass->getESuperTypes().push_back(
            m_TypedElementEClass);
    m_CompositeTypeEClass->getESuperTypes().push_back(m_ComponentTypeEClass);
    m_PortTypeRefEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_ServicePortTypeEClass->getESuperTypes().push_back(m_PortTypeEClass);
    m_OperationEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_ParameterEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_TypedElementEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_MessagePortTypeEClass->getESuperTypes().push_back(m_PortTypeEClass);
    m_TypeLibraryEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_IntegrationPatternEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_ChannelEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_ChannelEClass->getESuperTypes().push_back(m_InstanceEClass);
    m_NetworkPropertyEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_ChannelTypeEClass->getESuperTypes().push_back(
            m_LifeCycleTypeDefinitionEClass);
    m_TypeDefinitionEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_InstanceEClass->getESuperTypes().push_back(m_NamedElementEClass);
    m_LifeCycleTypeDefinitionEClass->getESuperTypes().push_back(
            m_TypeDefinitionEClass);
    m_GroupEClass->getESuperTypes().push_back(m_InstanceEClass);
    m_GroupTypeEClass->getESuperTypes().push_back(
            m_LifeCycleTypeDefinitionEClass);
    m_NodeTypeEClass->getESuperTypes().push_back(
            m_LifeCycleTypeDefinitionEClass);
    m_AdaptationPrimitiveTypeEClass->getESuperTypes().push_back(
            m_NamedElementEClass);

    // TODO: Initialize classes and features; add operations and parameters
    // TODO: GenericTypes
    // ComponentInstance
    m_ComponentInstanceEClass->setName("ComponentInstance");
    m_ComponentInstanceEClass->setAbstract(false);
    m_ComponentInstanceEClass->setInterface(false);
    m_ComponentInstance__provided->setEType(m_PortEClass);
    m_ComponentInstance__provided->setName("provided");
    m_ComponentInstance__provided->setDefaultValueLiteral("");
    m_ComponentInstance__provided->setLowerBound(0);
    m_ComponentInstance__provided->setUpperBound(-1);
    m_ComponentInstance__provided->setTransient(false);
    m_ComponentInstance__provided->setVolatile(false);
    m_ComponentInstance__provided->setChangeable(true);
    m_ComponentInstance__provided->setContainment(true);
    m_ComponentInstance__provided->setResolveProxies(true);
    m_ComponentInstance__provided->setUnique(true);
    m_ComponentInstance__provided->setDerived(false);
    m_ComponentInstance__provided->setOrdered(true);
    m_ComponentInstance__required->setEType(m_PortEClass);
    m_ComponentInstance__required->setName("required");
    m_ComponentInstance__required->setDefaultValueLiteral("");
    m_ComponentInstance__required->setLowerBound(0);
    m_ComponentInstance__required->setUpperBound(-1);
    m_ComponentInstance__required->setTransient(false);
    m_ComponentInstance__required->setVolatile(false);
    m_ComponentInstance__required->setChangeable(true);
    m_ComponentInstance__required->setContainment(true);
    m_ComponentInstance__required->setResolveProxies(true);
    m_ComponentInstance__required->setUnique(true);
    m_ComponentInstance__required->setDerived(false);
    m_ComponentInstance__required->setOrdered(true);
    m_ComponentInstance__namespace->setEType(m_NamespaceEClass);
    m_ComponentInstance__namespace->setName("namespace");
    m_ComponentInstance__namespace->setDefaultValueLiteral("");
    m_ComponentInstance__namespace->setLowerBound(0);
    m_ComponentInstance__namespace->setUpperBound(1);
    m_ComponentInstance__namespace->setTransient(false);
    m_ComponentInstance__namespace->setVolatile(false);
    m_ComponentInstance__namespace->setChangeable(true);
    m_ComponentInstance__namespace->setContainment(false);
    m_ComponentInstance__namespace->setResolveProxies(true);
    m_ComponentInstance__namespace->setUnique(true);
    m_ComponentInstance__namespace->setDerived(false);
    m_ComponentInstance__namespace->setOrdered(true);
    // ComponentType
    m_ComponentTypeEClass->setName("ComponentType");
    m_ComponentTypeEClass->setAbstract(false);
    m_ComponentTypeEClass->setInterface(false);
    m_ComponentType__required->setEType(m_PortTypeRefEClass);
    m_ComponentType__required->setName("required");
    m_ComponentType__required->setDefaultValueLiteral("");
    m_ComponentType__required->setLowerBound(0);
    m_ComponentType__required->setUpperBound(-1);
    m_ComponentType__required->setTransient(false);
    m_ComponentType__required->setVolatile(false);
    m_ComponentType__required->setChangeable(true);
    m_ComponentType__required->setContainment(true);
    m_ComponentType__required->setResolveProxies(true);
    m_ComponentType__required->setUnique(true);
    m_ComponentType__required->setDerived(false);
    m_ComponentType__required->setOrdered(true);
    m_ComponentType__integrationPatterns->setEType(m_IntegrationPatternEClass);
    m_ComponentType__integrationPatterns->setName("integrationPatterns");
    m_ComponentType__integrationPatterns->setDefaultValueLiteral("");
    m_ComponentType__integrationPatterns->setLowerBound(0);
    m_ComponentType__integrationPatterns->setUpperBound(-1);
    m_ComponentType__integrationPatterns->setTransient(false);
    m_ComponentType__integrationPatterns->setVolatile(false);
    m_ComponentType__integrationPatterns->setChangeable(true);
    m_ComponentType__integrationPatterns->setContainment(true);
    m_ComponentType__integrationPatterns->setResolveProxies(true);
    m_ComponentType__integrationPatterns->setUnique(true);
    m_ComponentType__integrationPatterns->setDerived(false);
    m_ComponentType__integrationPatterns->setOrdered(true);
    m_ComponentType__extraFonctionalProperties->setEType(
            m_ExtraFonctionalPropertyEClass);
    m_ComponentType__extraFonctionalProperties->setName(
            "extraFonctionalProperties");
    m_ComponentType__extraFonctionalProperties->setDefaultValueLiteral("");
    m_ComponentType__extraFonctionalProperties->setLowerBound(0);
    m_ComponentType__extraFonctionalProperties->setUpperBound(1);
    m_ComponentType__extraFonctionalProperties->setTransient(false);
    m_ComponentType__extraFonctionalProperties->setVolatile(false);
    m_ComponentType__extraFonctionalProperties->setChangeable(true);
    m_ComponentType__extraFonctionalProperties->setContainment(true);
    m_ComponentType__extraFonctionalProperties->setResolveProxies(true);
    m_ComponentType__extraFonctionalProperties->setUnique(true);
    m_ComponentType__extraFonctionalProperties->setDerived(false);
    m_ComponentType__extraFonctionalProperties->setOrdered(true);
    m_ComponentType__provided->setEType(m_PortTypeRefEClass);
    m_ComponentType__provided->setName("provided");
    m_ComponentType__provided->setDefaultValueLiteral("");
    m_ComponentType__provided->setLowerBound(0);
    m_ComponentType__provided->setUpperBound(-1);
    m_ComponentType__provided->setTransient(false);
    m_ComponentType__provided->setVolatile(false);
    m_ComponentType__provided->setChangeable(true);
    m_ComponentType__provided->setContainment(true);
    m_ComponentType__provided->setResolveProxies(true);
    m_ComponentType__provided->setUnique(true);
    m_ComponentType__provided->setDerived(false);
    m_ComponentType__provided->setOrdered(true);
    // ContainerNode
    m_ContainerNodeEClass->setName("ContainerNode");
    m_ContainerNodeEClass->setAbstract(false);
    m_ContainerNodeEClass->setInterface(false);
    m_ContainerNode__components->setEType(m_ComponentInstanceEClass);
    m_ContainerNode__components->setName("components");
    m_ContainerNode__components->setDefaultValueLiteral("");
    m_ContainerNode__components->setLowerBound(0);
    m_ContainerNode__components->setUpperBound(-1);
    m_ContainerNode__components->setTransient(false);
    m_ContainerNode__components->setVolatile(false);
    m_ContainerNode__components->setChangeable(true);
    m_ContainerNode__components->setContainment(true);
    m_ContainerNode__components->setResolveProxies(true);
    m_ContainerNode__components->setUnique(true);
    m_ContainerNode__components->setDerived(false);
    m_ContainerNode__components->setOrdered(true);
    m_ContainerNode__hosts->setEType(m_ContainerNodeEClass);
    m_ContainerNode__hosts->setName("hosts");
    m_ContainerNode__hosts->setDefaultValueLiteral("");
    m_ContainerNode__hosts->setLowerBound(0);
    m_ContainerNode__hosts->setUpperBound(-1);
    m_ContainerNode__hosts->setTransient(false);
    m_ContainerNode__hosts->setVolatile(false);
    m_ContainerNode__hosts->setChangeable(true);
    m_ContainerNode__hosts->setContainment(false);
    m_ContainerNode__hosts->setResolveProxies(true);
    m_ContainerNode__hosts->setUnique(true);
    m_ContainerNode__hosts->setDerived(false);
    m_ContainerNode__hosts->setOrdered(true);
    m_ContainerNode__hosts->setEOpposite(::ecore::instanceOf<
            ::ecore::EReference >(
            m_ContainerNodeEClass->getEStructuralFeatures()[2]));
    m_ContainerNode__host->setEType(m_ContainerNodeEClass);
    m_ContainerNode__host->setName("host");
    m_ContainerNode__host->setDefaultValueLiteral("");
    m_ContainerNode__host->setLowerBound(0);
    m_ContainerNode__host->setUpperBound(1);
    m_ContainerNode__host->setTransient(false);
    m_ContainerNode__host->setVolatile(false);
    m_ContainerNode__host->setChangeable(true);
    m_ContainerNode__host->setContainment(false);
    m_ContainerNode__host->setResolveProxies(true);
    m_ContainerNode__host->setUnique(true);
    m_ContainerNode__host->setDerived(false);
    m_ContainerNode__host->setOrdered(true);
    m_ContainerNode__host->setEOpposite(::ecore::instanceOf<
            ::ecore::EReference >(
            m_ContainerNodeEClass->getEStructuralFeatures()[1]));
    // ContainerRoot
    m_ContainerRootEClass->setName("ContainerRoot");
    m_ContainerRootEClass->setAbstract(false);
    m_ContainerRootEClass->setInterface(false);
    m_ContainerRoot__nodes->setEType(m_ContainerNodeEClass);
    m_ContainerRoot__nodes->setName("nodes");
    m_ContainerRoot__nodes->setDefaultValueLiteral("");
    m_ContainerRoot__nodes->setLowerBound(0);
    m_ContainerRoot__nodes->setUpperBound(-1);
    m_ContainerRoot__nodes->setTransient(false);
    m_ContainerRoot__nodes->setVolatile(false);
    m_ContainerRoot__nodes->setChangeable(true);
    m_ContainerRoot__nodes->setContainment(true);
    m_ContainerRoot__nodes->setResolveProxies(true);
    m_ContainerRoot__nodes->setUnique(true);
    m_ContainerRoot__nodes->setDerived(false);
    m_ContainerRoot__nodes->setOrdered(true);
    m_ContainerRoot__typeDefinitions->setEType(m_TypeDefinitionEClass);
    m_ContainerRoot__typeDefinitions->setName("typeDefinitions");
    m_ContainerRoot__typeDefinitions->setDefaultValueLiteral("");
    m_ContainerRoot__typeDefinitions->setLowerBound(0);
    m_ContainerRoot__typeDefinitions->setUpperBound(-1);
    m_ContainerRoot__typeDefinitions->setTransient(false);
    m_ContainerRoot__typeDefinitions->setVolatile(false);
    m_ContainerRoot__typeDefinitions->setChangeable(true);
    m_ContainerRoot__typeDefinitions->setContainment(true);
    m_ContainerRoot__typeDefinitions->setResolveProxies(true);
    m_ContainerRoot__typeDefinitions->setUnique(true);
    m_ContainerRoot__typeDefinitions->setDerived(false);
    m_ContainerRoot__typeDefinitions->setOrdered(true);
    m_ContainerRoot__repositories->setEType(m_RepositoryEClass);
    m_ContainerRoot__repositories->setName("repositories");
    m_ContainerRoot__repositories->setDefaultValueLiteral("");
    m_ContainerRoot__repositories->setLowerBound(0);
    m_ContainerRoot__repositories->setUpperBound(-1);
    m_ContainerRoot__repositories->setTransient(false);
    m_ContainerRoot__repositories->setVolatile(false);
    m_ContainerRoot__repositories->setChangeable(true);
    m_ContainerRoot__repositories->setContainment(true);
    m_ContainerRoot__repositories->setResolveProxies(true);
    m_ContainerRoot__repositories->setUnique(true);
    m_ContainerRoot__repositories->setDerived(false);
    m_ContainerRoot__repositories->setOrdered(true);
    m_ContainerRoot__dataTypes->setEType(m_TypedElementEClass);
    m_ContainerRoot__dataTypes->setName("dataTypes");
    m_ContainerRoot__dataTypes->setDefaultValueLiteral("");
    m_ContainerRoot__dataTypes->setLowerBound(0);
    m_ContainerRoot__dataTypes->setUpperBound(-1);
    m_ContainerRoot__dataTypes->setTransient(false);
    m_ContainerRoot__dataTypes->setVolatile(false);
    m_ContainerRoot__dataTypes->setChangeable(true);
    m_ContainerRoot__dataTypes->setContainment(true);
    m_ContainerRoot__dataTypes->setResolveProxies(true);
    m_ContainerRoot__dataTypes->setUnique(true);
    m_ContainerRoot__dataTypes->setDerived(false);
    m_ContainerRoot__dataTypes->setOrdered(true);
    m_ContainerRoot__libraries->setEType(m_TypeLibraryEClass);
    m_ContainerRoot__libraries->setName("libraries");
    m_ContainerRoot__libraries->setDefaultValueLiteral("");
    m_ContainerRoot__libraries->setLowerBound(0);
    m_ContainerRoot__libraries->setUpperBound(-1);
    m_ContainerRoot__libraries->setTransient(false);
    m_ContainerRoot__libraries->setVolatile(false);
    m_ContainerRoot__libraries->setChangeable(true);
    m_ContainerRoot__libraries->setContainment(true);
    m_ContainerRoot__libraries->setResolveProxies(true);
    m_ContainerRoot__libraries->setUnique(true);
    m_ContainerRoot__libraries->setDerived(false);
    m_ContainerRoot__libraries->setOrdered(true);
    m_ContainerRoot__hubs->setEType(m_ChannelEClass);
    m_ContainerRoot__hubs->setName("hubs");
    m_ContainerRoot__hubs->setDefaultValueLiteral("");
    m_ContainerRoot__hubs->setLowerBound(0);
    m_ContainerRoot__hubs->setUpperBound(-1);
    m_ContainerRoot__hubs->setTransient(false);
    m_ContainerRoot__hubs->setVolatile(false);
    m_ContainerRoot__hubs->setChangeable(true);
    m_ContainerRoot__hubs->setContainment(true);
    m_ContainerRoot__hubs->setResolveProxies(true);
    m_ContainerRoot__hubs->setUnique(true);
    m_ContainerRoot__hubs->setDerived(false);
    m_ContainerRoot__hubs->setOrdered(true);
    m_ContainerRoot__mBindings->setEType(m_MBindingEClass);
    m_ContainerRoot__mBindings->setName("mBindings");
    m_ContainerRoot__mBindings->setDefaultValueLiteral("");
    m_ContainerRoot__mBindings->setLowerBound(0);
    m_ContainerRoot__mBindings->setUpperBound(-1);
    m_ContainerRoot__mBindings->setTransient(false);
    m_ContainerRoot__mBindings->setVolatile(false);
    m_ContainerRoot__mBindings->setChangeable(true);
    m_ContainerRoot__mBindings->setContainment(true);
    m_ContainerRoot__mBindings->setResolveProxies(true);
    m_ContainerRoot__mBindings->setUnique(true);
    m_ContainerRoot__mBindings->setDerived(false);
    m_ContainerRoot__mBindings->setOrdered(true);
    m_ContainerRoot__deployUnits->setEType(m_DeployUnitEClass);
    m_ContainerRoot__deployUnits->setName("deployUnits");
    m_ContainerRoot__deployUnits->setDefaultValueLiteral("");
    m_ContainerRoot__deployUnits->setLowerBound(0);
    m_ContainerRoot__deployUnits->setUpperBound(-1);
    m_ContainerRoot__deployUnits->setTransient(false);
    m_ContainerRoot__deployUnits->setVolatile(false);
    m_ContainerRoot__deployUnits->setChangeable(true);
    m_ContainerRoot__deployUnits->setContainment(true);
    m_ContainerRoot__deployUnits->setResolveProxies(true);
    m_ContainerRoot__deployUnits->setUnique(true);
    m_ContainerRoot__deployUnits->setDerived(false);
    m_ContainerRoot__deployUnits->setOrdered(true);
    m_ContainerRoot__nodeNetworks->setEType(m_NodeNetworkEClass);
    m_ContainerRoot__nodeNetworks->setName("nodeNetworks");
    m_ContainerRoot__nodeNetworks->setDefaultValueLiteral("");
    m_ContainerRoot__nodeNetworks->setLowerBound(0);
    m_ContainerRoot__nodeNetworks->setUpperBound(-1);
    m_ContainerRoot__nodeNetworks->setTransient(false);
    m_ContainerRoot__nodeNetworks->setVolatile(false);
    m_ContainerRoot__nodeNetworks->setChangeable(true);
    m_ContainerRoot__nodeNetworks->setContainment(true);
    m_ContainerRoot__nodeNetworks->setResolveProxies(true);
    m_ContainerRoot__nodeNetworks->setUnique(true);
    m_ContainerRoot__nodeNetworks->setDerived(false);
    m_ContainerRoot__nodeNetworks->setOrdered(true);
    m_ContainerRoot__groups->setEType(m_GroupEClass);
    m_ContainerRoot__groups->setName("groups");
    m_ContainerRoot__groups->setDefaultValueLiteral("");
    m_ContainerRoot__groups->setLowerBound(0);
    m_ContainerRoot__groups->setUpperBound(-1);
    m_ContainerRoot__groups->setTransient(false);
    m_ContainerRoot__groups->setVolatile(false);
    m_ContainerRoot__groups->setChangeable(true);
    m_ContainerRoot__groups->setContainment(true);
    m_ContainerRoot__groups->setResolveProxies(true);
    m_ContainerRoot__groups->setUnique(true);
    m_ContainerRoot__groups->setDerived(false);
    m_ContainerRoot__groups->setOrdered(true);
    m_ContainerRoot__adaptationPrimitiveTypes->setEType(
            m_AdaptationPrimitiveTypeEClass);
    m_ContainerRoot__adaptationPrimitiveTypes->setName(
            "adaptationPrimitiveTypes");
    m_ContainerRoot__adaptationPrimitiveTypes->setDefaultValueLiteral("");
    m_ContainerRoot__adaptationPrimitiveTypes->setLowerBound(0);
    m_ContainerRoot__adaptationPrimitiveTypes->setUpperBound(-1);
    m_ContainerRoot__adaptationPrimitiveTypes->setTransient(false);
    m_ContainerRoot__adaptationPrimitiveTypes->setVolatile(false);
    m_ContainerRoot__adaptationPrimitiveTypes->setChangeable(true);
    m_ContainerRoot__adaptationPrimitiveTypes->setContainment(true);
    m_ContainerRoot__adaptationPrimitiveTypes->setResolveProxies(true);
    m_ContainerRoot__adaptationPrimitiveTypes->setUnique(true);
    m_ContainerRoot__adaptationPrimitiveTypes->setDerived(false);
    m_ContainerRoot__adaptationPrimitiveTypes->setOrdered(true);
    // PortType
    m_PortTypeEClass->setName("PortType");
    m_PortTypeEClass->setAbstract(true);
    m_PortTypeEClass->setInterface(false);
    m_PortType__synchrone->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEBoolean());
    m_PortType__synchrone->setName("synchrone");
    m_PortType__synchrone->setDefaultValueLiteral("");
    m_PortType__synchrone->setLowerBound(0);
    m_PortType__synchrone->setUpperBound(1);
    m_PortType__synchrone->setTransient(false);
    m_PortType__synchrone->setVolatile(false);
    m_PortType__synchrone->setChangeable(true);
    m_PortType__synchrone->setUnsettable(false);
    m_PortType__synchrone->setID(false);
    m_PortType__synchrone->setUnique(true);
    m_PortType__synchrone->setDerived(false);
    m_PortType__synchrone->setOrdered(true);
    // Port
    m_PortEClass->setName("Port");
    m_PortEClass->setAbstract(false);
    m_PortEClass->setInterface(false);
    m_Port__bindings->setEType(m_MBindingEClass);
    m_Port__bindings->setName("bindings");
    m_Port__bindings->setDefaultValueLiteral("");
    m_Port__bindings->setLowerBound(0);
    m_Port__bindings->setUpperBound(-1);
    m_Port__bindings->setTransient(false);
    m_Port__bindings->setVolatile(false);
    m_Port__bindings->setChangeable(true);
    m_Port__bindings->setContainment(false);
    m_Port__bindings->setResolveProxies(true);
    m_Port__bindings->setUnique(true);
    m_Port__bindings->setDerived(false);
    m_Port__bindings->setOrdered(true);
    m_Port__bindings->setEOpposite(::ecore::instanceOf< ::ecore::EReference >(
            m_MBindingEClass->getEStructuralFeatures()[0]));
    m_Port__portTypeRef->setEType(m_PortTypeRefEClass);
    m_Port__portTypeRef->setName("portTypeRef");
    m_Port__portTypeRef->setDefaultValueLiteral("");
    m_Port__portTypeRef->setLowerBound(1);
    m_Port__portTypeRef->setUpperBound(1);
    m_Port__portTypeRef->setTransient(false);
    m_Port__portTypeRef->setVolatile(false);
    m_Port__portTypeRef->setChangeable(true);
    m_Port__portTypeRef->setContainment(false);
    m_Port__portTypeRef->setResolveProxies(true);
    m_Port__portTypeRef->setUnique(true);
    m_Port__portTypeRef->setDerived(false);
    m_Port__portTypeRef->setOrdered(true);
    // Namespace
    m_NamespaceEClass->setName("Namespace");
    m_NamespaceEClass->setAbstract(false);
    m_NamespaceEClass->setInterface(false);
    m_Namespace__childs->setEType(m_NamespaceEClass);
    m_Namespace__childs->setName("childs");
    m_Namespace__childs->setDefaultValueLiteral("");
    m_Namespace__childs->setLowerBound(0);
    m_Namespace__childs->setUpperBound(-1);
    m_Namespace__childs->setTransient(false);
    m_Namespace__childs->setVolatile(false);
    m_Namespace__childs->setChangeable(true);
    m_Namespace__childs->setContainment(true);
    m_Namespace__childs->setResolveProxies(true);
    m_Namespace__childs->setUnique(true);
    m_Namespace__childs->setDerived(false);
    m_Namespace__childs->setOrdered(true);
    m_Namespace__parent->setEType(m_NamespaceEClass);
    m_Namespace__parent->setName("parent");
    m_Namespace__parent->setDefaultValueLiteral("");
    m_Namespace__parent->setLowerBound(0);
    m_Namespace__parent->setUpperBound(1);
    m_Namespace__parent->setTransient(false);
    m_Namespace__parent->setVolatile(false);
    m_Namespace__parent->setChangeable(true);
    m_Namespace__parent->setContainment(false);
    m_Namespace__parent->setResolveProxies(true);
    m_Namespace__parent->setUnique(true);
    m_Namespace__parent->setDerived(false);
    m_Namespace__parent->setOrdered(true);
    // Dictionary
    m_DictionaryEClass->setName("Dictionary");
    m_DictionaryEClass->setAbstract(false);
    m_DictionaryEClass->setInterface(false);
    m_Dictionary__values->setEType(m_DictionaryValueEClass);
    m_Dictionary__values->setName("values");
    m_Dictionary__values->setDefaultValueLiteral("");
    m_Dictionary__values->setLowerBound(0);
    m_Dictionary__values->setUpperBound(-1);
    m_Dictionary__values->setTransient(false);
    m_Dictionary__values->setVolatile(false);
    m_Dictionary__values->setChangeable(true);
    m_Dictionary__values->setContainment(true);
    m_Dictionary__values->setResolveProxies(true);
    m_Dictionary__values->setUnique(true);
    m_Dictionary__values->setDerived(false);
    m_Dictionary__values->setOrdered(true);
    // DictionaryType
    m_DictionaryTypeEClass->setName("DictionaryType");
    m_DictionaryTypeEClass->setAbstract(false);
    m_DictionaryTypeEClass->setInterface(false);
    m_DictionaryType__attributes->setEType(m_DictionaryAttributeEClass);
    m_DictionaryType__attributes->setName("attributes");
    m_DictionaryType__attributes->setDefaultValueLiteral("");
    m_DictionaryType__attributes->setLowerBound(0);
    m_DictionaryType__attributes->setUpperBound(-1);
    m_DictionaryType__attributes->setTransient(false);
    m_DictionaryType__attributes->setVolatile(false);
    m_DictionaryType__attributes->setChangeable(true);
    m_DictionaryType__attributes->setContainment(true);
    m_DictionaryType__attributes->setResolveProxies(true);
    m_DictionaryType__attributes->setUnique(true);
    m_DictionaryType__attributes->setDerived(false);
    m_DictionaryType__attributes->setOrdered(true);
    m_DictionaryType__defaultValues->setEType(m_DictionaryValueEClass);
    m_DictionaryType__defaultValues->setName("defaultValues");
    m_DictionaryType__defaultValues->setDefaultValueLiteral("");
    m_DictionaryType__defaultValues->setLowerBound(0);
    m_DictionaryType__defaultValues->setUpperBound(-1);
    m_DictionaryType__defaultValues->setTransient(false);
    m_DictionaryType__defaultValues->setVolatile(false);
    m_DictionaryType__defaultValues->setChangeable(true);
    m_DictionaryType__defaultValues->setContainment(true);
    m_DictionaryType__defaultValues->setResolveProxies(true);
    m_DictionaryType__defaultValues->setUnique(true);
    m_DictionaryType__defaultValues->setDerived(false);
    m_DictionaryType__defaultValues->setOrdered(true);
    // DictionaryAttribute
    m_DictionaryAttributeEClass->setName("DictionaryAttribute");
    m_DictionaryAttributeEClass->setAbstract(false);
    m_DictionaryAttributeEClass->setInterface(false);
    m_DictionaryAttribute__optional->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEBoolean());
    m_DictionaryAttribute__optional->setName("optional");
    m_DictionaryAttribute__optional->setDefaultValueLiteral("");
    m_DictionaryAttribute__optional->setLowerBound(0);
    m_DictionaryAttribute__optional->setUpperBound(1);
    m_DictionaryAttribute__optional->setTransient(false);
    m_DictionaryAttribute__optional->setVolatile(false);
    m_DictionaryAttribute__optional->setChangeable(true);
    m_DictionaryAttribute__optional->setUnsettable(false);
    m_DictionaryAttribute__optional->setID(false);
    m_DictionaryAttribute__optional->setUnique(true);
    m_DictionaryAttribute__optional->setDerived(false);
    m_DictionaryAttribute__optional->setOrdered(true);
    m_DictionaryAttribute__state->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEBoolean());
    m_DictionaryAttribute__state->setName("state");
    m_DictionaryAttribute__state->setDefaultValueLiteral("");
    m_DictionaryAttribute__state->setLowerBound(0);
    m_DictionaryAttribute__state->setUpperBound(1);
    m_DictionaryAttribute__state->setTransient(false);
    m_DictionaryAttribute__state->setVolatile(false);
    m_DictionaryAttribute__state->setChangeable(true);
    m_DictionaryAttribute__state->setUnsettable(false);
    m_DictionaryAttribute__state->setID(false);
    m_DictionaryAttribute__state->setUnique(true);
    m_DictionaryAttribute__state->setDerived(false);
    m_DictionaryAttribute__state->setOrdered(true);
    m_DictionaryAttribute__datatype->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_DictionaryAttribute__datatype->setName("datatype");
    m_DictionaryAttribute__datatype->setDefaultValueLiteral("");
    m_DictionaryAttribute__datatype->setLowerBound(0);
    m_DictionaryAttribute__datatype->setUpperBound(1);
    m_DictionaryAttribute__datatype->setTransient(false);
    m_DictionaryAttribute__datatype->setVolatile(false);
    m_DictionaryAttribute__datatype->setChangeable(true);
    m_DictionaryAttribute__datatype->setUnsettable(false);
    m_DictionaryAttribute__datatype->setID(false);
    m_DictionaryAttribute__datatype->setUnique(true);
    m_DictionaryAttribute__datatype->setDerived(false);
    m_DictionaryAttribute__datatype->setOrdered(true);
    m_DictionaryAttribute__fragmentDependant->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEBoolean());
    m_DictionaryAttribute__fragmentDependant->setName("fragmentDependant");
    m_DictionaryAttribute__fragmentDependant->setDefaultValueLiteral("");
    m_DictionaryAttribute__fragmentDependant->setLowerBound(0);
    m_DictionaryAttribute__fragmentDependant->setUpperBound(1);
    m_DictionaryAttribute__fragmentDependant->setTransient(false);
    m_DictionaryAttribute__fragmentDependant->setVolatile(false);
    m_DictionaryAttribute__fragmentDependant->setChangeable(true);
    m_DictionaryAttribute__fragmentDependant->setUnsettable(false);
    m_DictionaryAttribute__fragmentDependant->setID(false);
    m_DictionaryAttribute__fragmentDependant->setUnique(true);
    m_DictionaryAttribute__fragmentDependant->setDerived(false);
    m_DictionaryAttribute__fragmentDependant->setOrdered(true);
    // DictionaryValue
    m_DictionaryValueEClass->setName("DictionaryValue");
    m_DictionaryValueEClass->setAbstract(false);
    m_DictionaryValueEClass->setInterface(false);
    m_DictionaryValue__value->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_DictionaryValue__value->setName("value");
    m_DictionaryValue__value->setDefaultValueLiteral("");
    m_DictionaryValue__value->setLowerBound(0);
    m_DictionaryValue__value->setUpperBound(1);
    m_DictionaryValue__value->setTransient(false);
    m_DictionaryValue__value->setVolatile(false);
    m_DictionaryValue__value->setChangeable(true);
    m_DictionaryValue__value->setUnsettable(false);
    m_DictionaryValue__value->setID(false);
    m_DictionaryValue__value->setUnique(true);
    m_DictionaryValue__value->setDerived(false);
    m_DictionaryValue__value->setOrdered(true);
    m_DictionaryValue__attribute->setEType(m_DictionaryAttributeEClass);
    m_DictionaryValue__attribute->setName("attribute");
    m_DictionaryValue__attribute->setDefaultValueLiteral("");
    m_DictionaryValue__attribute->setLowerBound(1);
    m_DictionaryValue__attribute->setUpperBound(1);
    m_DictionaryValue__attribute->setTransient(false);
    m_DictionaryValue__attribute->setVolatile(false);
    m_DictionaryValue__attribute->setChangeable(true);
    m_DictionaryValue__attribute->setContainment(false);
    m_DictionaryValue__attribute->setResolveProxies(true);
    m_DictionaryValue__attribute->setUnique(true);
    m_DictionaryValue__attribute->setDerived(false);
    m_DictionaryValue__attribute->setOrdered(true);
    m_DictionaryValue__targetNode->setEType(m_ContainerNodeEClass);
    m_DictionaryValue__targetNode->setName("targetNode");
    m_DictionaryValue__targetNode->setDefaultValueLiteral("");
    m_DictionaryValue__targetNode->setLowerBound(0);
    m_DictionaryValue__targetNode->setUpperBound(1);
    m_DictionaryValue__targetNode->setTransient(false);
    m_DictionaryValue__targetNode->setVolatile(false);
    m_DictionaryValue__targetNode->setChangeable(true);
    m_DictionaryValue__targetNode->setContainment(false);
    m_DictionaryValue__targetNode->setResolveProxies(true);
    m_DictionaryValue__targetNode->setUnique(true);
    m_DictionaryValue__targetNode->setDerived(false);
    m_DictionaryValue__targetNode->setOrdered(true);
    // CompositeType
    m_CompositeTypeEClass->setName("CompositeType");
    m_CompositeTypeEClass->setAbstract(false);
    m_CompositeTypeEClass->setInterface(false);
    m_CompositeType__childs->setEType(m_ComponentTypeEClass);
    m_CompositeType__childs->setName("childs");
    m_CompositeType__childs->setDefaultValueLiteral("");
    m_CompositeType__childs->setLowerBound(0);
    m_CompositeType__childs->setUpperBound(-1);
    m_CompositeType__childs->setTransient(false);
    m_CompositeType__childs->setVolatile(false);
    m_CompositeType__childs->setChangeable(true);
    m_CompositeType__childs->setContainment(false);
    m_CompositeType__childs->setResolveProxies(true);
    m_CompositeType__childs->setUnique(true);
    m_CompositeType__childs->setDerived(false);
    m_CompositeType__childs->setOrdered(true);
    m_CompositeType__wires->setEType(m_WireEClass);
    m_CompositeType__wires->setName("wires");
    m_CompositeType__wires->setDefaultValueLiteral("");
    m_CompositeType__wires->setLowerBound(0);
    m_CompositeType__wires->setUpperBound(-1);
    m_CompositeType__wires->setTransient(false);
    m_CompositeType__wires->setVolatile(false);
    m_CompositeType__wires->setChangeable(true);
    m_CompositeType__wires->setContainment(true);
    m_CompositeType__wires->setResolveProxies(true);
    m_CompositeType__wires->setUnique(true);
    m_CompositeType__wires->setDerived(false);
    m_CompositeType__wires->setOrdered(true);
    // PortTypeRef
    m_PortTypeRefEClass->setName("PortTypeRef");
    m_PortTypeRefEClass->setAbstract(false);
    m_PortTypeRefEClass->setInterface(false);
    m_PortTypeRef__optional->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEBooleanObject());
    m_PortTypeRef__optional->setName("optional");
    m_PortTypeRef__optional->setDefaultValueLiteral("");
    m_PortTypeRef__optional->setLowerBound(0);
    m_PortTypeRef__optional->setUpperBound(1);
    m_PortTypeRef__optional->setTransient(false);
    m_PortTypeRef__optional->setVolatile(false);
    m_PortTypeRef__optional->setChangeable(true);
    m_PortTypeRef__optional->setUnsettable(false);
    m_PortTypeRef__optional->setID(false);
    m_PortTypeRef__optional->setUnique(true);
    m_PortTypeRef__optional->setDerived(false);
    m_PortTypeRef__optional->setOrdered(true);
    m_PortTypeRef__noDependency->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEBooleanObject());
    m_PortTypeRef__noDependency->setName("noDependency");
    m_PortTypeRef__noDependency->setDefaultValueLiteral("");
    m_PortTypeRef__noDependency->setLowerBound(0);
    m_PortTypeRef__noDependency->setUpperBound(1);
    m_PortTypeRef__noDependency->setTransient(false);
    m_PortTypeRef__noDependency->setVolatile(false);
    m_PortTypeRef__noDependency->setChangeable(true);
    m_PortTypeRef__noDependency->setUnsettable(false);
    m_PortTypeRef__noDependency->setID(false);
    m_PortTypeRef__noDependency->setUnique(true);
    m_PortTypeRef__noDependency->setDerived(false);
    m_PortTypeRef__noDependency->setOrdered(true);
    m_PortTypeRef__ref->setEType(m_PortTypeEClass);
    m_PortTypeRef__ref->setName("ref");
    m_PortTypeRef__ref->setDefaultValueLiteral("");
    m_PortTypeRef__ref->setLowerBound(1);
    m_PortTypeRef__ref->setUpperBound(1);
    m_PortTypeRef__ref->setTransient(false);
    m_PortTypeRef__ref->setVolatile(false);
    m_PortTypeRef__ref->setChangeable(true);
    m_PortTypeRef__ref->setContainment(false);
    m_PortTypeRef__ref->setResolveProxies(true);
    m_PortTypeRef__ref->setUnique(true);
    m_PortTypeRef__ref->setDerived(false);
    m_PortTypeRef__ref->setOrdered(true);
    m_PortTypeRef__mappings->setEType(m_PortTypeMappingEClass);
    m_PortTypeRef__mappings->setName("mappings");
    m_PortTypeRef__mappings->setDefaultValueLiteral("");
    m_PortTypeRef__mappings->setLowerBound(0);
    m_PortTypeRef__mappings->setUpperBound(-1);
    m_PortTypeRef__mappings->setTransient(false);
    m_PortTypeRef__mappings->setVolatile(false);
    m_PortTypeRef__mappings->setChangeable(true);
    m_PortTypeRef__mappings->setContainment(true);
    m_PortTypeRef__mappings->setResolveProxies(true);
    m_PortTypeRef__mappings->setUnique(true);
    m_PortTypeRef__mappings->setDerived(false);
    m_PortTypeRef__mappings->setOrdered(true);
    // Wire
    m_WireEClass->setName("Wire");
    m_WireEClass->setAbstract(false);
    m_WireEClass->setInterface(false);
    m_Wire__ports->setEType(m_PortTypeRefEClass);
    m_Wire__ports->setName("ports");
    m_Wire__ports->setDefaultValueLiteral("");
    m_Wire__ports->setLowerBound(2);
    m_Wire__ports->setUpperBound(2);
    m_Wire__ports->setTransient(false);
    m_Wire__ports->setVolatile(false);
    m_Wire__ports->setChangeable(true);
    m_Wire__ports->setContainment(false);
    m_Wire__ports->setResolveProxies(true);
    m_Wire__ports->setUnique(true);
    m_Wire__ports->setDerived(false);
    m_Wire__ports->setOrdered(true);
    // ServicePortType
    m_ServicePortTypeEClass->setName("ServicePortType");
    m_ServicePortTypeEClass->setAbstract(false);
    m_ServicePortTypeEClass->setInterface(false);
    m_ServicePortType__interface->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_ServicePortType__interface->setName("interface");
    m_ServicePortType__interface->setDefaultValueLiteral("");
    m_ServicePortType__interface->setLowerBound(0);
    m_ServicePortType__interface->setUpperBound(1);
    m_ServicePortType__interface->setTransient(false);
    m_ServicePortType__interface->setVolatile(false);
    m_ServicePortType__interface->setChangeable(true);
    m_ServicePortType__interface->setUnsettable(false);
    m_ServicePortType__interface->setID(false);
    m_ServicePortType__interface->setUnique(true);
    m_ServicePortType__interface->setDerived(false);
    m_ServicePortType__interface->setOrdered(true);
    m_ServicePortType__operations->setEType(m_OperationEClass);
    m_ServicePortType__operations->setName("operations");
    m_ServicePortType__operations->setDefaultValueLiteral("");
    m_ServicePortType__operations->setLowerBound(0);
    m_ServicePortType__operations->setUpperBound(-1);
    m_ServicePortType__operations->setTransient(false);
    m_ServicePortType__operations->setVolatile(false);
    m_ServicePortType__operations->setChangeable(true);
    m_ServicePortType__operations->setContainment(true);
    m_ServicePortType__operations->setResolveProxies(true);
    m_ServicePortType__operations->setUnique(true);
    m_ServicePortType__operations->setDerived(false);
    m_ServicePortType__operations->setOrdered(true);
    // Operation
    m_OperationEClass->setName("Operation");
    m_OperationEClass->setAbstract(false);
    m_OperationEClass->setInterface(false);
    m_Operation__parameters->setEType(m_ParameterEClass);
    m_Operation__parameters->setName("parameters");
    m_Operation__parameters->setDefaultValueLiteral("");
    m_Operation__parameters->setLowerBound(0);
    m_Operation__parameters->setUpperBound(-1);
    m_Operation__parameters->setTransient(false);
    m_Operation__parameters->setVolatile(false);
    m_Operation__parameters->setChangeable(true);
    m_Operation__parameters->setContainment(true);
    m_Operation__parameters->setResolveProxies(true);
    m_Operation__parameters->setUnique(true);
    m_Operation__parameters->setDerived(false);
    m_Operation__parameters->setOrdered(true);
    m_Operation__returnType->setEType(m_TypedElementEClass);
    m_Operation__returnType->setName("returnType");
    m_Operation__returnType->setDefaultValueLiteral("");
    m_Operation__returnType->setLowerBound(0);
    m_Operation__returnType->setUpperBound(1);
    m_Operation__returnType->setTransient(false);
    m_Operation__returnType->setVolatile(false);
    m_Operation__returnType->setChangeable(true);
    m_Operation__returnType->setContainment(false);
    m_Operation__returnType->setResolveProxies(true);
    m_Operation__returnType->setUnique(true);
    m_Operation__returnType->setDerived(false);
    m_Operation__returnType->setOrdered(true);
    // Parameter
    m_ParameterEClass->setName("Parameter");
    m_ParameterEClass->setAbstract(false);
    m_ParameterEClass->setInterface(false);
    m_Parameter__order->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEIntegerObject());
    m_Parameter__order->setName("order");
    m_Parameter__order->setDefaultValueLiteral("");
    m_Parameter__order->setLowerBound(0);
    m_Parameter__order->setUpperBound(1);
    m_Parameter__order->setTransient(false);
    m_Parameter__order->setVolatile(false);
    m_Parameter__order->setChangeable(true);
    m_Parameter__order->setUnsettable(false);
    m_Parameter__order->setID(false);
    m_Parameter__order->setUnique(true);
    m_Parameter__order->setDerived(false);
    m_Parameter__order->setOrdered(true);
    m_Parameter__type->setEType(m_TypedElementEClass);
    m_Parameter__type->setName("type");
    m_Parameter__type->setDefaultValueLiteral("");
    m_Parameter__type->setLowerBound(0);
    m_Parameter__type->setUpperBound(1);
    m_Parameter__type->setTransient(false);
    m_Parameter__type->setVolatile(false);
    m_Parameter__type->setChangeable(true);
    m_Parameter__type->setContainment(false);
    m_Parameter__type->setResolveProxies(true);
    m_Parameter__type->setUnique(true);
    m_Parameter__type->setDerived(false);
    m_Parameter__type->setOrdered(true);
    // TypedElement
    m_TypedElementEClass->setName("TypedElement");
    m_TypedElementEClass->setAbstract(false);
    m_TypedElementEClass->setInterface(false);
    m_TypedElement__genericTypes->setEType(m_TypedElementEClass);
    m_TypedElement__genericTypes->setName("genericTypes");
    m_TypedElement__genericTypes->setDefaultValueLiteral("");
    m_TypedElement__genericTypes->setLowerBound(0);
    m_TypedElement__genericTypes->setUpperBound(-1);
    m_TypedElement__genericTypes->setTransient(false);
    m_TypedElement__genericTypes->setVolatile(false);
    m_TypedElement__genericTypes->setChangeable(true);
    m_TypedElement__genericTypes->setContainment(false);
    m_TypedElement__genericTypes->setResolveProxies(true);
    m_TypedElement__genericTypes->setUnique(true);
    m_TypedElement__genericTypes->setDerived(false);
    m_TypedElement__genericTypes->setOrdered(true);
    // MessagePortType
    m_MessagePortTypeEClass->setName("MessagePortType");
    m_MessagePortTypeEClass->setAbstract(false);
    m_MessagePortTypeEClass->setInterface(false);
    m_MessagePortType__filters->setEType(m_TypedElementEClass);
    m_MessagePortType__filters->setName("filters");
    m_MessagePortType__filters->setDefaultValueLiteral("");
    m_MessagePortType__filters->setLowerBound(0);
    m_MessagePortType__filters->setUpperBound(-1);
    m_MessagePortType__filters->setTransient(false);
    m_MessagePortType__filters->setVolatile(false);
    m_MessagePortType__filters->setChangeable(true);
    m_MessagePortType__filters->setContainment(false);
    m_MessagePortType__filters->setResolveProxies(true);
    m_MessagePortType__filters->setUnique(true);
    m_MessagePortType__filters->setDerived(false);
    m_MessagePortType__filters->setOrdered(true);
    // Repository
    m_RepositoryEClass->setName("Repository");
    m_RepositoryEClass->setAbstract(false);
    m_RepositoryEClass->setInterface(false);
    m_Repository__url->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_Repository__url->setName("url");
    m_Repository__url->setDefaultValueLiteral("");
    m_Repository__url->setLowerBound(0);
    m_Repository__url->setUpperBound(1);
    m_Repository__url->setTransient(false);
    m_Repository__url->setVolatile(false);
    m_Repository__url->setChangeable(true);
    m_Repository__url->setUnsettable(false);
    m_Repository__url->setID(true);
    m_Repository__url->setUnique(true);
    m_Repository__url->setDerived(false);
    m_Repository__url->setOrdered(true);
    m_Repository__units->setEType(m_DeployUnitEClass);
    m_Repository__units->setName("units");
    m_Repository__units->setDefaultValueLiteral("");
    m_Repository__units->setLowerBound(0);
    m_Repository__units->setUpperBound(-1);
    m_Repository__units->setTransient(false);
    m_Repository__units->setVolatile(false);
    m_Repository__units->setChangeable(true);
    m_Repository__units->setContainment(false);
    m_Repository__units->setResolveProxies(true);
    m_Repository__units->setUnique(true);
    m_Repository__units->setDerived(false);
    m_Repository__units->setOrdered(true);
    // DeployUnit
    m_DeployUnitEClass->setName("DeployUnit");
    m_DeployUnitEClass->setAbstract(false);
    m_DeployUnitEClass->setInterface(false);
    m_DeployUnit__name->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_DeployUnit__name->setName("name");
    m_DeployUnit__name->setDefaultValueLiteral("");
    m_DeployUnit__name->setLowerBound(1);
    m_DeployUnit__name->setUpperBound(1);
    m_DeployUnit__name->setTransient(false);
    m_DeployUnit__name->setVolatile(false);
    m_DeployUnit__name->setChangeable(true);
    m_DeployUnit__name->setUnsettable(false);
    m_DeployUnit__name->setID(false);
    m_DeployUnit__name->setUnique(true);
    m_DeployUnit__name->setDerived(false);
    m_DeployUnit__name->setOrdered(true);
    m_DeployUnit__groupName->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_DeployUnit__groupName->setName("groupName");
    m_DeployUnit__groupName->setDefaultValueLiteral("");
    m_DeployUnit__groupName->setLowerBound(0);
    m_DeployUnit__groupName->setUpperBound(1);
    m_DeployUnit__groupName->setTransient(false);
    m_DeployUnit__groupName->setVolatile(false);
    m_DeployUnit__groupName->setChangeable(true);
    m_DeployUnit__groupName->setUnsettable(false);
    m_DeployUnit__groupName->setID(false);
    m_DeployUnit__groupName->setUnique(true);
    m_DeployUnit__groupName->setDerived(false);
    m_DeployUnit__groupName->setOrdered(true);
    m_DeployUnit__unitName->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_DeployUnit__unitName->setName("unitName");
    m_DeployUnit__unitName->setDefaultValueLiteral("");
    m_DeployUnit__unitName->setLowerBound(0);
    m_DeployUnit__unitName->setUpperBound(1);
    m_DeployUnit__unitName->setTransient(false);
    m_DeployUnit__unitName->setVolatile(false);
    m_DeployUnit__unitName->setChangeable(true);
    m_DeployUnit__unitName->setUnsettable(false);
    m_DeployUnit__unitName->setID(false);
    m_DeployUnit__unitName->setUnique(true);
    m_DeployUnit__unitName->setDerived(false);
    m_DeployUnit__unitName->setOrdered(true);
    m_DeployUnit__version->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_DeployUnit__version->setName("version");
    m_DeployUnit__version->setDefaultValueLiteral("");
    m_DeployUnit__version->setLowerBound(0);
    m_DeployUnit__version->setUpperBound(1);
    m_DeployUnit__version->setTransient(false);
    m_DeployUnit__version->setVolatile(false);
    m_DeployUnit__version->setChangeable(true);
    m_DeployUnit__version->setUnsettable(false);
    m_DeployUnit__version->setID(false);
    m_DeployUnit__version->setUnique(true);
    m_DeployUnit__version->setDerived(false);
    m_DeployUnit__version->setOrdered(true);
    m_DeployUnit__url->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_DeployUnit__url->setName("url");
    m_DeployUnit__url->setDefaultValueLiteral("");
    m_DeployUnit__url->setLowerBound(0);
    m_DeployUnit__url->setUpperBound(1);
    m_DeployUnit__url->setTransient(false);
    m_DeployUnit__url->setVolatile(false);
    m_DeployUnit__url->setChangeable(true);
    m_DeployUnit__url->setUnsettable(false);
    m_DeployUnit__url->setID(false);
    m_DeployUnit__url->setUnique(true);
    m_DeployUnit__url->setDerived(false);
    m_DeployUnit__url->setOrdered(true);
    m_DeployUnit__hashcode->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_DeployUnit__hashcode->setName("hashcode");
    m_DeployUnit__hashcode->setDefaultValueLiteral("");
    m_DeployUnit__hashcode->setLowerBound(0);
    m_DeployUnit__hashcode->setUpperBound(1);
    m_DeployUnit__hashcode->setTransient(false);
    m_DeployUnit__hashcode->setVolatile(false);
    m_DeployUnit__hashcode->setChangeable(true);
    m_DeployUnit__hashcode->setUnsettable(false);
    m_DeployUnit__hashcode->setID(false);
    m_DeployUnit__hashcode->setUnique(true);
    m_DeployUnit__hashcode->setDerived(false);
    m_DeployUnit__hashcode->setOrdered(true);
    m_DeployUnit__type->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_DeployUnit__type->setName("type");
    m_DeployUnit__type->setDefaultValueLiteral("");
    m_DeployUnit__type->setLowerBound(0);
    m_DeployUnit__type->setUpperBound(1);
    m_DeployUnit__type->setTransient(false);
    m_DeployUnit__type->setVolatile(false);
    m_DeployUnit__type->setChangeable(true);
    m_DeployUnit__type->setUnsettable(false);
    m_DeployUnit__type->setID(false);
    m_DeployUnit__type->setUnique(true);
    m_DeployUnit__type->setDerived(false);
    m_DeployUnit__type->setOrdered(true);
    m_DeployUnit__requiredLibs->setEType(m_DeployUnitEClass);
    m_DeployUnit__requiredLibs->setName("requiredLibs");
    m_DeployUnit__requiredLibs->setDefaultValueLiteral("");
    m_DeployUnit__requiredLibs->setLowerBound(0);
    m_DeployUnit__requiredLibs->setUpperBound(-1);
    m_DeployUnit__requiredLibs->setTransient(false);
    m_DeployUnit__requiredLibs->setVolatile(false);
    m_DeployUnit__requiredLibs->setChangeable(true);
    m_DeployUnit__requiredLibs->setContainment(false);
    m_DeployUnit__requiredLibs->setResolveProxies(true);
    m_DeployUnit__requiredLibs->setUnique(true);
    m_DeployUnit__requiredLibs->setDerived(false);
    m_DeployUnit__requiredLibs->setOrdered(true);
    m_DeployUnit__targetNodeType->setEType(m_NodeTypeEClass);
    m_DeployUnit__targetNodeType->setName("targetNodeType");
    m_DeployUnit__targetNodeType->setDefaultValueLiteral("");
    m_DeployUnit__targetNodeType->setLowerBound(0);
    m_DeployUnit__targetNodeType->setUpperBound(1);
    m_DeployUnit__targetNodeType->setTransient(false);
    m_DeployUnit__targetNodeType->setVolatile(false);
    m_DeployUnit__targetNodeType->setChangeable(true);
    m_DeployUnit__targetNodeType->setContainment(false);
    m_DeployUnit__targetNodeType->setResolveProxies(true);
    m_DeployUnit__targetNodeType->setUnique(true);
    m_DeployUnit__targetNodeType->setDerived(false);
    m_DeployUnit__targetNodeType->setOrdered(true);
    // TypeLibrary
    m_TypeLibraryEClass->setName("TypeLibrary");
    m_TypeLibraryEClass->setAbstract(false);
    m_TypeLibraryEClass->setInterface(false);
    m_TypeLibrary__subTypes->setEType(m_TypeDefinitionEClass);
    m_TypeLibrary__subTypes->setName("subTypes");
    m_TypeLibrary__subTypes->setDefaultValueLiteral("");
    m_TypeLibrary__subTypes->setLowerBound(0);
    m_TypeLibrary__subTypes->setUpperBound(-1);
    m_TypeLibrary__subTypes->setTransient(false);
    m_TypeLibrary__subTypes->setVolatile(false);
    m_TypeLibrary__subTypes->setChangeable(true);
    m_TypeLibrary__subTypes->setContainment(false);
    m_TypeLibrary__subTypes->setResolveProxies(true);
    m_TypeLibrary__subTypes->setUnique(true);
    m_TypeLibrary__subTypes->setDerived(false);
    m_TypeLibrary__subTypes->setOrdered(true);
    // NamedElement
    m_NamedElementEClass->setName("NamedElement");
    m_NamedElementEClass->setAbstract(false);
    m_NamedElementEClass->setInterface(false);
    m_NamedElement__name->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_NamedElement__name->setName("name");
    m_NamedElement__name->setDefaultValueLiteral("");
    m_NamedElement__name->setLowerBound(1);
    m_NamedElement__name->setUpperBound(1);
    m_NamedElement__name->setTransient(false);
    m_NamedElement__name->setVolatile(false);
    m_NamedElement__name->setChangeable(true);
    m_NamedElement__name->setUnsettable(false);
    m_NamedElement__name->setID(true);
    m_NamedElement__name->setUnique(true);
    m_NamedElement__name->setDerived(false);
    m_NamedElement__name->setOrdered(true);
    // IntegrationPattern
    m_IntegrationPatternEClass->setName("IntegrationPattern");
    m_IntegrationPatternEClass->setAbstract(false);
    m_IntegrationPatternEClass->setInterface(false);
    m_IntegrationPattern__extraFonctionalProperties->setEType(
            m_ExtraFonctionalPropertyEClass);
    m_IntegrationPattern__extraFonctionalProperties->setName(
            "extraFonctionalProperties");
    m_IntegrationPattern__extraFonctionalProperties->setDefaultValueLiteral("");
    m_IntegrationPattern__extraFonctionalProperties->setLowerBound(0);
    m_IntegrationPattern__extraFonctionalProperties->setUpperBound(-1);
    m_IntegrationPattern__extraFonctionalProperties->setTransient(false);
    m_IntegrationPattern__extraFonctionalProperties->setVolatile(false);
    m_IntegrationPattern__extraFonctionalProperties->setChangeable(true);
    m_IntegrationPattern__extraFonctionalProperties->setContainment(true);
    m_IntegrationPattern__extraFonctionalProperties->setResolveProxies(true);
    m_IntegrationPattern__extraFonctionalProperties->setUnique(true);
    m_IntegrationPattern__extraFonctionalProperties->setDerived(false);
    m_IntegrationPattern__extraFonctionalProperties->setOrdered(true);
    m_IntegrationPattern__portTypes->setEType(m_PortTypeRefEClass);
    m_IntegrationPattern__portTypes->setName("portTypes");
    m_IntegrationPattern__portTypes->setDefaultValueLiteral("");
    m_IntegrationPattern__portTypes->setLowerBound(0);
    m_IntegrationPattern__portTypes->setUpperBound(-1);
    m_IntegrationPattern__portTypes->setTransient(false);
    m_IntegrationPattern__portTypes->setVolatile(false);
    m_IntegrationPattern__portTypes->setChangeable(true);
    m_IntegrationPattern__portTypes->setContainment(false);
    m_IntegrationPattern__portTypes->setResolveProxies(true);
    m_IntegrationPattern__portTypes->setUnique(true);
    m_IntegrationPattern__portTypes->setDerived(false);
    m_IntegrationPattern__portTypes->setOrdered(true);
    // ExtraFonctionalProperty
    m_ExtraFonctionalPropertyEClass->setName("ExtraFonctionalProperty");
    m_ExtraFonctionalPropertyEClass->setAbstract(false);
    m_ExtraFonctionalPropertyEClass->setInterface(false);
    m_ExtraFonctionalProperty__portTypes->setEType(m_PortTypeRefEClass);
    m_ExtraFonctionalProperty__portTypes->setName("portTypes");
    m_ExtraFonctionalProperty__portTypes->setDefaultValueLiteral("");
    m_ExtraFonctionalProperty__portTypes->setLowerBound(0);
    m_ExtraFonctionalProperty__portTypes->setUpperBound(-1);
    m_ExtraFonctionalProperty__portTypes->setTransient(false);
    m_ExtraFonctionalProperty__portTypes->setVolatile(false);
    m_ExtraFonctionalProperty__portTypes->setChangeable(true);
    m_ExtraFonctionalProperty__portTypes->setContainment(false);
    m_ExtraFonctionalProperty__portTypes->setResolveProxies(true);
    m_ExtraFonctionalProperty__portTypes->setUnique(true);
    m_ExtraFonctionalProperty__portTypes->setDerived(false);
    m_ExtraFonctionalProperty__portTypes->setOrdered(true);
    // PortTypeMapping
    m_PortTypeMappingEClass->setName("PortTypeMapping");
    m_PortTypeMappingEClass->setAbstract(false);
    m_PortTypeMappingEClass->setInterface(false);
    m_PortTypeMapping__beanMethodName->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_PortTypeMapping__beanMethodName->setName("beanMethodName");
    m_PortTypeMapping__beanMethodName->setDefaultValueLiteral("");
    m_PortTypeMapping__beanMethodName->setLowerBound(0);
    m_PortTypeMapping__beanMethodName->setUpperBound(1);
    m_PortTypeMapping__beanMethodName->setTransient(false);
    m_PortTypeMapping__beanMethodName->setVolatile(false);
    m_PortTypeMapping__beanMethodName->setChangeable(true);
    m_PortTypeMapping__beanMethodName->setUnsettable(false);
    m_PortTypeMapping__beanMethodName->setID(false);
    m_PortTypeMapping__beanMethodName->setUnique(true);
    m_PortTypeMapping__beanMethodName->setDerived(false);
    m_PortTypeMapping__beanMethodName->setOrdered(true);
    m_PortTypeMapping__serviceMethodName->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_PortTypeMapping__serviceMethodName->setName("serviceMethodName");
    m_PortTypeMapping__serviceMethodName->setDefaultValueLiteral("");
    m_PortTypeMapping__serviceMethodName->setLowerBound(0);
    m_PortTypeMapping__serviceMethodName->setUpperBound(1);
    m_PortTypeMapping__serviceMethodName->setTransient(false);
    m_PortTypeMapping__serviceMethodName->setVolatile(false);
    m_PortTypeMapping__serviceMethodName->setChangeable(true);
    m_PortTypeMapping__serviceMethodName->setUnsettable(false);
    m_PortTypeMapping__serviceMethodName->setID(false);
    m_PortTypeMapping__serviceMethodName->setUnique(true);
    m_PortTypeMapping__serviceMethodName->setDerived(false);
    m_PortTypeMapping__serviceMethodName->setOrdered(true);
    m_PortTypeMapping__paramTypes->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_PortTypeMapping__paramTypes->setName("paramTypes");
    m_PortTypeMapping__paramTypes->setDefaultValueLiteral("");
    m_PortTypeMapping__paramTypes->setLowerBound(0);
    m_PortTypeMapping__paramTypes->setUpperBound(1);
    m_PortTypeMapping__paramTypes->setTransient(false);
    m_PortTypeMapping__paramTypes->setVolatile(false);
    m_PortTypeMapping__paramTypes->setChangeable(true);
    m_PortTypeMapping__paramTypes->setUnsettable(false);
    m_PortTypeMapping__paramTypes->setID(false);
    m_PortTypeMapping__paramTypes->setUnique(true);
    m_PortTypeMapping__paramTypes->setDerived(false);
    m_PortTypeMapping__paramTypes->setOrdered(true);
    // Channel
    m_ChannelEClass->setName("Channel");
    m_ChannelEClass->setAbstract(false);
    m_ChannelEClass->setInterface(false);
    m_Channel__bindings->setEType(m_MBindingEClass);
    m_Channel__bindings->setName("bindings");
    m_Channel__bindings->setDefaultValueLiteral("");
    m_Channel__bindings->setLowerBound(0);
    m_Channel__bindings->setUpperBound(-1);
    m_Channel__bindings->setTransient(false);
    m_Channel__bindings->setVolatile(false);
    m_Channel__bindings->setChangeable(true);
    m_Channel__bindings->setContainment(false);
    m_Channel__bindings->setResolveProxies(true);
    m_Channel__bindings->setUnique(true);
    m_Channel__bindings->setDerived(false);
    m_Channel__bindings->setOrdered(true);
    m_Channel__bindings->setEOpposite(
            ::ecore::instanceOf< ::ecore::EReference >(
                    m_MBindingEClass->getEStructuralFeatures()[1]));
    // MBinding
    m_MBindingEClass->setName("MBinding");
    m_MBindingEClass->setAbstract(false);
    m_MBindingEClass->setInterface(false);
    m_MBinding__port->setEType(m_PortEClass);
    m_MBinding__port->setName("port");
    m_MBinding__port->setDefaultValueLiteral("");
    m_MBinding__port->setLowerBound(1);
    m_MBinding__port->setUpperBound(1);
    m_MBinding__port->setTransient(false);
    m_MBinding__port->setVolatile(false);
    m_MBinding__port->setChangeable(true);
    m_MBinding__port->setContainment(false);
    m_MBinding__port->setResolveProxies(true);
    m_MBinding__port->setUnique(true);
    m_MBinding__port->setDerived(false);
    m_MBinding__port->setOrdered(true);
    m_MBinding__port->setEOpposite(::ecore::instanceOf< ::ecore::EReference >(
            m_PortEClass->getEStructuralFeatures()[0]));
    m_MBinding__hub->setEType(m_ChannelEClass);
    m_MBinding__hub->setName("hub");
    m_MBinding__hub->setDefaultValueLiteral("");
    m_MBinding__hub->setLowerBound(1);
    m_MBinding__hub->setUpperBound(1);
    m_MBinding__hub->setTransient(false);
    m_MBinding__hub->setVolatile(false);
    m_MBinding__hub->setChangeable(true);
    m_MBinding__hub->setContainment(false);
    m_MBinding__hub->setResolveProxies(true);
    m_MBinding__hub->setUnique(true);
    m_MBinding__hub->setDerived(false);
    m_MBinding__hub->setOrdered(true);
    m_MBinding__hub->setEOpposite(::ecore::instanceOf< ::ecore::EReference >(
            m_ChannelEClass->getEStructuralFeatures()[0]));
    // NodeNetwork
    m_NodeNetworkEClass->setName("NodeNetwork");
    m_NodeNetworkEClass->setAbstract(false);
    m_NodeNetworkEClass->setInterface(false);
    m_NodeNetwork__link->setEType(m_NodeLinkEClass);
    m_NodeNetwork__link->setName("link");
    m_NodeNetwork__link->setDefaultValueLiteral("");
    m_NodeNetwork__link->setLowerBound(0);
    m_NodeNetwork__link->setUpperBound(-1);
    m_NodeNetwork__link->setTransient(false);
    m_NodeNetwork__link->setVolatile(false);
    m_NodeNetwork__link->setChangeable(true);
    m_NodeNetwork__link->setContainment(true);
    m_NodeNetwork__link->setResolveProxies(true);
    m_NodeNetwork__link->setUnique(true);
    m_NodeNetwork__link->setDerived(false);
    m_NodeNetwork__link->setOrdered(true);
    m_NodeNetwork__initBy->setEType(m_ContainerNodeEClass);
    m_NodeNetwork__initBy->setName("initBy");
    m_NodeNetwork__initBy->setDefaultValueLiteral("");
    m_NodeNetwork__initBy->setLowerBound(0);
    m_NodeNetwork__initBy->setUpperBound(1);
    m_NodeNetwork__initBy->setTransient(false);
    m_NodeNetwork__initBy->setVolatile(false);
    m_NodeNetwork__initBy->setChangeable(true);
    m_NodeNetwork__initBy->setContainment(false);
    m_NodeNetwork__initBy->setResolveProxies(true);
    m_NodeNetwork__initBy->setUnique(true);
    m_NodeNetwork__initBy->setDerived(false);
    m_NodeNetwork__initBy->setOrdered(true);
    m_NodeNetwork__target->setEType(m_ContainerNodeEClass);
    m_NodeNetwork__target->setName("target");
    m_NodeNetwork__target->setDefaultValueLiteral("");
    m_NodeNetwork__target->setLowerBound(1);
    m_NodeNetwork__target->setUpperBound(1);
    m_NodeNetwork__target->setTransient(false);
    m_NodeNetwork__target->setVolatile(false);
    m_NodeNetwork__target->setChangeable(true);
    m_NodeNetwork__target->setContainment(false);
    m_NodeNetwork__target->setResolveProxies(true);
    m_NodeNetwork__target->setUnique(true);
    m_NodeNetwork__target->setDerived(false);
    m_NodeNetwork__target->setOrdered(true);
    // NodeLink
    m_NodeLinkEClass->setName("NodeLink");
    m_NodeLinkEClass->setAbstract(false);
    m_NodeLinkEClass->setInterface(false);
    m_NodeLink__networkType->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_NodeLink__networkType->setName("networkType");
    m_NodeLink__networkType->setDefaultValueLiteral("");
    m_NodeLink__networkType->setLowerBound(0);
    m_NodeLink__networkType->setUpperBound(1);
    m_NodeLink__networkType->setTransient(false);
    m_NodeLink__networkType->setVolatile(false);
    m_NodeLink__networkType->setChangeable(true);
    m_NodeLink__networkType->setUnsettable(false);
    m_NodeLink__networkType->setID(false);
    m_NodeLink__networkType->setUnique(true);
    m_NodeLink__networkType->setDerived(false);
    m_NodeLink__networkType->setOrdered(true);
    m_NodeLink__estimatedRate->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEIntegerObject());
    m_NodeLink__estimatedRate->setName("estimatedRate");
    m_NodeLink__estimatedRate->setDefaultValueLiteral("");
    m_NodeLink__estimatedRate->setLowerBound(0);
    m_NodeLink__estimatedRate->setUpperBound(1);
    m_NodeLink__estimatedRate->setTransient(false);
    m_NodeLink__estimatedRate->setVolatile(false);
    m_NodeLink__estimatedRate->setChangeable(true);
    m_NodeLink__estimatedRate->setUnsettable(false);
    m_NodeLink__estimatedRate->setID(false);
    m_NodeLink__estimatedRate->setUnique(true);
    m_NodeLink__estimatedRate->setDerived(false);
    m_NodeLink__estimatedRate->setOrdered(true);
    m_NodeLink__lastCheck->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_NodeLink__lastCheck->setName("lastCheck");
    m_NodeLink__lastCheck->setDefaultValueLiteral("");
    m_NodeLink__lastCheck->setLowerBound(0);
    m_NodeLink__lastCheck->setUpperBound(1);
    m_NodeLink__lastCheck->setTransient(false);
    m_NodeLink__lastCheck->setVolatile(false);
    m_NodeLink__lastCheck->setChangeable(true);
    m_NodeLink__lastCheck->setUnsettable(false);
    m_NodeLink__lastCheck->setID(false);
    m_NodeLink__lastCheck->setUnique(true);
    m_NodeLink__lastCheck->setDerived(false);
    m_NodeLink__lastCheck->setOrdered(true);
    m_NodeLink__zoneID->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_NodeLink__zoneID->setName("zoneID");
    m_NodeLink__zoneID->setDefaultValueLiteral("");
    m_NodeLink__zoneID->setLowerBound(0);
    m_NodeLink__zoneID->setUpperBound(1);
    m_NodeLink__zoneID->setTransient(false);
    m_NodeLink__zoneID->setVolatile(false);
    m_NodeLink__zoneID->setChangeable(true);
    m_NodeLink__zoneID->setUnsettable(false);
    m_NodeLink__zoneID->setID(false);
    m_NodeLink__zoneID->setUnique(true);
    m_NodeLink__zoneID->setDerived(false);
    m_NodeLink__zoneID->setOrdered(true);
    m_NodeLink__networkProperties->setEType(m_NetworkPropertyEClass);
    m_NodeLink__networkProperties->setName("networkProperties");
    m_NodeLink__networkProperties->setDefaultValueLiteral("");
    m_NodeLink__networkProperties->setLowerBound(0);
    m_NodeLink__networkProperties->setUpperBound(-1);
    m_NodeLink__networkProperties->setTransient(false);
    m_NodeLink__networkProperties->setVolatile(false);
    m_NodeLink__networkProperties->setChangeable(true);
    m_NodeLink__networkProperties->setContainment(true);
    m_NodeLink__networkProperties->setResolveProxies(true);
    m_NodeLink__networkProperties->setUnique(true);
    m_NodeLink__networkProperties->setDerived(false);
    m_NodeLink__networkProperties->setOrdered(true);
    // NetworkProperty
    m_NetworkPropertyEClass->setName("NetworkProperty");
    m_NetworkPropertyEClass->setAbstract(false);
    m_NetworkPropertyEClass->setInterface(false);
    m_NetworkProperty__value->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_NetworkProperty__value->setName("value");
    m_NetworkProperty__value->setDefaultValueLiteral("");
    m_NetworkProperty__value->setLowerBound(0);
    m_NetworkProperty__value->setUpperBound(1);
    m_NetworkProperty__value->setTransient(false);
    m_NetworkProperty__value->setVolatile(false);
    m_NetworkProperty__value->setChangeable(true);
    m_NetworkProperty__value->setUnsettable(false);
    m_NetworkProperty__value->setID(false);
    m_NetworkProperty__value->setUnique(true);
    m_NetworkProperty__value->setDerived(false);
    m_NetworkProperty__value->setOrdered(true);
    m_NetworkProperty__lastCheck->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_NetworkProperty__lastCheck->setName("lastCheck");
    m_NetworkProperty__lastCheck->setDefaultValueLiteral("");
    m_NetworkProperty__lastCheck->setLowerBound(0);
    m_NetworkProperty__lastCheck->setUpperBound(1);
    m_NetworkProperty__lastCheck->setTransient(false);
    m_NetworkProperty__lastCheck->setVolatile(false);
    m_NetworkProperty__lastCheck->setChangeable(true);
    m_NetworkProperty__lastCheck->setUnsettable(false);
    m_NetworkProperty__lastCheck->setID(false);
    m_NetworkProperty__lastCheck->setUnique(true);
    m_NetworkProperty__lastCheck->setDerived(false);
    m_NetworkProperty__lastCheck->setOrdered(true);
    // ChannelType
    m_ChannelTypeEClass->setName("ChannelType");
    m_ChannelTypeEClass->setAbstract(false);
    m_ChannelTypeEClass->setInterface(false);
    m_ChannelType__lowerBindings->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEIntegerObject());
    m_ChannelType__lowerBindings->setName("lowerBindings");
    m_ChannelType__lowerBindings->setDefaultValueLiteral("");
    m_ChannelType__lowerBindings->setLowerBound(0);
    m_ChannelType__lowerBindings->setUpperBound(1);
    m_ChannelType__lowerBindings->setTransient(false);
    m_ChannelType__lowerBindings->setVolatile(false);
    m_ChannelType__lowerBindings->setChangeable(true);
    m_ChannelType__lowerBindings->setUnsettable(false);
    m_ChannelType__lowerBindings->setID(false);
    m_ChannelType__lowerBindings->setUnique(true);
    m_ChannelType__lowerBindings->setDerived(false);
    m_ChannelType__lowerBindings->setOrdered(true);
    m_ChannelType__upperBindings->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEIntegerObject());
    m_ChannelType__upperBindings->setName("upperBindings");
    m_ChannelType__upperBindings->setDefaultValueLiteral("");
    m_ChannelType__upperBindings->setLowerBound(0);
    m_ChannelType__upperBindings->setUpperBound(1);
    m_ChannelType__upperBindings->setTransient(false);
    m_ChannelType__upperBindings->setVolatile(false);
    m_ChannelType__upperBindings->setChangeable(true);
    m_ChannelType__upperBindings->setUnsettable(false);
    m_ChannelType__upperBindings->setID(false);
    m_ChannelType__upperBindings->setUnique(true);
    m_ChannelType__upperBindings->setDerived(false);
    m_ChannelType__upperBindings->setOrdered(true);
    m_ChannelType__lowerFragments->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEIntegerObject());
    m_ChannelType__lowerFragments->setName("lowerFragments");
    m_ChannelType__lowerFragments->setDefaultValueLiteral("");
    m_ChannelType__lowerFragments->setLowerBound(0);
    m_ChannelType__lowerFragments->setUpperBound(1);
    m_ChannelType__lowerFragments->setTransient(false);
    m_ChannelType__lowerFragments->setVolatile(false);
    m_ChannelType__lowerFragments->setChangeable(true);
    m_ChannelType__lowerFragments->setUnsettable(false);
    m_ChannelType__lowerFragments->setID(false);
    m_ChannelType__lowerFragments->setUnique(true);
    m_ChannelType__lowerFragments->setDerived(false);
    m_ChannelType__lowerFragments->setOrdered(true);
    m_ChannelType__upperFragments->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEIntegerObject());
    m_ChannelType__upperFragments->setName("upperFragments");
    m_ChannelType__upperFragments->setDefaultValueLiteral("");
    m_ChannelType__upperFragments->setLowerBound(0);
    m_ChannelType__upperFragments->setUpperBound(1);
    m_ChannelType__upperFragments->setTransient(false);
    m_ChannelType__upperFragments->setVolatile(false);
    m_ChannelType__upperFragments->setChangeable(true);
    m_ChannelType__upperFragments->setUnsettable(false);
    m_ChannelType__upperFragments->setID(false);
    m_ChannelType__upperFragments->setUnique(true);
    m_ChannelType__upperFragments->setDerived(false);
    m_ChannelType__upperFragments->setOrdered(true);
    // TypeDefinition
    m_TypeDefinitionEClass->setName("TypeDefinition");
    m_TypeDefinitionEClass->setAbstract(true);
    m_TypeDefinitionEClass->setInterface(true);
    m_TypeDefinition__factoryBean->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_TypeDefinition__factoryBean->setName("factoryBean");
    m_TypeDefinition__factoryBean->setDefaultValueLiteral("");
    m_TypeDefinition__factoryBean->setLowerBound(0);
    m_TypeDefinition__factoryBean->setUpperBound(1);
    m_TypeDefinition__factoryBean->setTransient(false);
    m_TypeDefinition__factoryBean->setVolatile(false);
    m_TypeDefinition__factoryBean->setChangeable(true);
    m_TypeDefinition__factoryBean->setUnsettable(false);
    m_TypeDefinition__factoryBean->setID(false);
    m_TypeDefinition__factoryBean->setUnique(true);
    m_TypeDefinition__factoryBean->setDerived(false);
    m_TypeDefinition__factoryBean->setOrdered(true);
    m_TypeDefinition__bean->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_TypeDefinition__bean->setName("bean");
    m_TypeDefinition__bean->setDefaultValueLiteral("");
    m_TypeDefinition__bean->setLowerBound(0);
    m_TypeDefinition__bean->setUpperBound(1);
    m_TypeDefinition__bean->setTransient(false);
    m_TypeDefinition__bean->setVolatile(false);
    m_TypeDefinition__bean->setChangeable(true);
    m_TypeDefinition__bean->setUnsettable(false);
    m_TypeDefinition__bean->setID(false);
    m_TypeDefinition__bean->setUnique(true);
    m_TypeDefinition__bean->setDerived(false);
    m_TypeDefinition__bean->setOrdered(true);
    m_TypeDefinition__abstract->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEBoolean());
    m_TypeDefinition__abstract->setName("abstract");
    m_TypeDefinition__abstract->setDefaultValueLiteral("");
    m_TypeDefinition__abstract->setLowerBound(0);
    m_TypeDefinition__abstract->setUpperBound(1);
    m_TypeDefinition__abstract->setTransient(false);
    m_TypeDefinition__abstract->setVolatile(false);
    m_TypeDefinition__abstract->setChangeable(true);
    m_TypeDefinition__abstract->setUnsettable(false);
    m_TypeDefinition__abstract->setID(false);
    m_TypeDefinition__abstract->setUnique(true);
    m_TypeDefinition__abstract->setDerived(false);
    m_TypeDefinition__abstract->setOrdered(true);
    m_TypeDefinition__deployUnits->setEType(m_DeployUnitEClass);
    m_TypeDefinition__deployUnits->setName("deployUnits");
    m_TypeDefinition__deployUnits->setDefaultValueLiteral("");
    m_TypeDefinition__deployUnits->setLowerBound(1);
    m_TypeDefinition__deployUnits->setUpperBound(-1);
    m_TypeDefinition__deployUnits->setTransient(false);
    m_TypeDefinition__deployUnits->setVolatile(false);
    m_TypeDefinition__deployUnits->setChangeable(true);
    m_TypeDefinition__deployUnits->setContainment(false);
    m_TypeDefinition__deployUnits->setResolveProxies(true);
    m_TypeDefinition__deployUnits->setUnique(true);
    m_TypeDefinition__deployUnits->setDerived(false);
    m_TypeDefinition__deployUnits->setOrdered(true);
    m_TypeDefinition__dictionaryType->setEType(m_DictionaryTypeEClass);
    m_TypeDefinition__dictionaryType->setName("dictionaryType");
    m_TypeDefinition__dictionaryType->setDefaultValueLiteral("");
    m_TypeDefinition__dictionaryType->setLowerBound(0);
    m_TypeDefinition__dictionaryType->setUpperBound(1);
    m_TypeDefinition__dictionaryType->setTransient(false);
    m_TypeDefinition__dictionaryType->setVolatile(false);
    m_TypeDefinition__dictionaryType->setChangeable(true);
    m_TypeDefinition__dictionaryType->setContainment(true);
    m_TypeDefinition__dictionaryType->setResolveProxies(true);
    m_TypeDefinition__dictionaryType->setUnique(true);
    m_TypeDefinition__dictionaryType->setDerived(false);
    m_TypeDefinition__dictionaryType->setOrdered(true);
    m_TypeDefinition__superTypes->setEType(m_TypeDefinitionEClass);
    m_TypeDefinition__superTypes->setName("superTypes");
    m_TypeDefinition__superTypes->setDefaultValueLiteral("");
    m_TypeDefinition__superTypes->setLowerBound(0);
    m_TypeDefinition__superTypes->setUpperBound(-1);
    m_TypeDefinition__superTypes->setTransient(false);
    m_TypeDefinition__superTypes->setVolatile(false);
    m_TypeDefinition__superTypes->setChangeable(true);
    m_TypeDefinition__superTypes->setContainment(false);
    m_TypeDefinition__superTypes->setResolveProxies(true);
    m_TypeDefinition__superTypes->setUnique(true);
    m_TypeDefinition__superTypes->setDerived(false);
    m_TypeDefinition__superTypes->setOrdered(true);
    // Instance
    m_InstanceEClass->setName("Instance");
    m_InstanceEClass->setAbstract(false);
    m_InstanceEClass->setInterface(false);
    m_Instance__metaData->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_Instance__metaData->setName("metaData");
    m_Instance__metaData->setDefaultValueLiteral("");
    m_Instance__metaData->setLowerBound(0);
    m_Instance__metaData->setUpperBound(1);
    m_Instance__metaData->setTransient(false);
    m_Instance__metaData->setVolatile(false);
    m_Instance__metaData->setChangeable(true);
    m_Instance__metaData->setUnsettable(false);
    m_Instance__metaData->setID(false);
    m_Instance__metaData->setUnique(true);
    m_Instance__metaData->setDerived(false);
    m_Instance__metaData->setOrdered(true);
    m_Instance__started->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEBoolean());
    m_Instance__started->setName("started");
    m_Instance__started->setDefaultValueLiteral("true");
    m_Instance__started->setLowerBound(0);
    m_Instance__started->setUpperBound(1);
    m_Instance__started->setTransient(false);
    m_Instance__started->setVolatile(false);
    m_Instance__started->setChangeable(true);
    m_Instance__started->setUnsettable(false);
    m_Instance__started->setID(false);
    m_Instance__started->setUnique(true);
    m_Instance__started->setDerived(false);
    m_Instance__started->setOrdered(true);
    m_Instance__typeDefinition->setEType(m_TypeDefinitionEClass);
    m_Instance__typeDefinition->setName("typeDefinition");
    m_Instance__typeDefinition->setDefaultValueLiteral("");
    m_Instance__typeDefinition->setLowerBound(1);
    m_Instance__typeDefinition->setUpperBound(1);
    m_Instance__typeDefinition->setTransient(false);
    m_Instance__typeDefinition->setVolatile(false);
    m_Instance__typeDefinition->setChangeable(true);
    m_Instance__typeDefinition->setContainment(false);
    m_Instance__typeDefinition->setResolveProxies(true);
    m_Instance__typeDefinition->setUnique(true);
    m_Instance__typeDefinition->setDerived(false);
    m_Instance__typeDefinition->setOrdered(true);
    m_Instance__dictionary->setEType(m_DictionaryEClass);
    m_Instance__dictionary->setName("dictionary");
    m_Instance__dictionary->setDefaultValueLiteral("");
    m_Instance__dictionary->setLowerBound(0);
    m_Instance__dictionary->setUpperBound(1);
    m_Instance__dictionary->setTransient(false);
    m_Instance__dictionary->setVolatile(false);
    m_Instance__dictionary->setChangeable(true);
    m_Instance__dictionary->setContainment(true);
    m_Instance__dictionary->setResolveProxies(true);
    m_Instance__dictionary->setUnique(true);
    m_Instance__dictionary->setDerived(false);
    m_Instance__dictionary->setOrdered(true);
    // LifeCycleTypeDefinition
    m_LifeCycleTypeDefinitionEClass->setName("LifeCycleTypeDefinition");
    m_LifeCycleTypeDefinitionEClass->setAbstract(true);
    m_LifeCycleTypeDefinitionEClass->setInterface(true);
    m_LifeCycleTypeDefinition__startMethod->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_LifeCycleTypeDefinition__startMethod->setName("startMethod");
    m_LifeCycleTypeDefinition__startMethod->setDefaultValueLiteral("");
    m_LifeCycleTypeDefinition__startMethod->setLowerBound(0);
    m_LifeCycleTypeDefinition__startMethod->setUpperBound(1);
    m_LifeCycleTypeDefinition__startMethod->setTransient(false);
    m_LifeCycleTypeDefinition__startMethod->setVolatile(false);
    m_LifeCycleTypeDefinition__startMethod->setChangeable(true);
    m_LifeCycleTypeDefinition__startMethod->setUnsettable(false);
    m_LifeCycleTypeDefinition__startMethod->setID(false);
    m_LifeCycleTypeDefinition__startMethod->setUnique(true);
    m_LifeCycleTypeDefinition__startMethod->setDerived(false);
    m_LifeCycleTypeDefinition__startMethod->setOrdered(true);
    m_LifeCycleTypeDefinition__stopMethod->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_LifeCycleTypeDefinition__stopMethod->setName("stopMethod");
    m_LifeCycleTypeDefinition__stopMethod->setDefaultValueLiteral("");
    m_LifeCycleTypeDefinition__stopMethod->setLowerBound(0);
    m_LifeCycleTypeDefinition__stopMethod->setUpperBound(1);
    m_LifeCycleTypeDefinition__stopMethod->setTransient(false);
    m_LifeCycleTypeDefinition__stopMethod->setVolatile(false);
    m_LifeCycleTypeDefinition__stopMethod->setChangeable(true);
    m_LifeCycleTypeDefinition__stopMethod->setUnsettable(false);
    m_LifeCycleTypeDefinition__stopMethod->setID(false);
    m_LifeCycleTypeDefinition__stopMethod->setUnique(true);
    m_LifeCycleTypeDefinition__stopMethod->setDerived(false);
    m_LifeCycleTypeDefinition__stopMethod->setOrdered(true);
    m_LifeCycleTypeDefinition__updateMethod->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_LifeCycleTypeDefinition__updateMethod->setName("updateMethod");
    m_LifeCycleTypeDefinition__updateMethod->setDefaultValueLiteral("");
    m_LifeCycleTypeDefinition__updateMethod->setLowerBound(0);
    m_LifeCycleTypeDefinition__updateMethod->setUpperBound(1);
    m_LifeCycleTypeDefinition__updateMethod->setTransient(false);
    m_LifeCycleTypeDefinition__updateMethod->setVolatile(false);
    m_LifeCycleTypeDefinition__updateMethod->setChangeable(true);
    m_LifeCycleTypeDefinition__updateMethod->setUnsettable(false);
    m_LifeCycleTypeDefinition__updateMethod->setID(false);
    m_LifeCycleTypeDefinition__updateMethod->setUnique(true);
    m_LifeCycleTypeDefinition__updateMethod->setDerived(false);
    m_LifeCycleTypeDefinition__updateMethod->setOrdered(true);
    // Group
    m_GroupEClass->setName("Group");
    m_GroupEClass->setAbstract(false);
    m_GroupEClass->setInterface(false);
    m_Group__subNodes->setEType(m_ContainerNodeEClass);
    m_Group__subNodes->setName("subNodes");
    m_Group__subNodes->setDefaultValueLiteral("");
    m_Group__subNodes->setLowerBound(0);
    m_Group__subNodes->setUpperBound(-1);
    m_Group__subNodes->setTransient(false);
    m_Group__subNodes->setVolatile(false);
    m_Group__subNodes->setChangeable(true);
    m_Group__subNodes->setContainment(false);
    m_Group__subNodes->setResolveProxies(true);
    m_Group__subNodes->setUnique(true);
    m_Group__subNodes->setDerived(false);
    m_Group__subNodes->setOrdered(true);
    // GroupType
    m_GroupTypeEClass->setName("GroupType");
    m_GroupTypeEClass->setAbstract(false);
    m_GroupTypeEClass->setInterface(false);
    // NodeType
    m_NodeTypeEClass->setName("NodeType");
    m_NodeTypeEClass->setAbstract(false);
    m_NodeTypeEClass->setInterface(false);
    m_NodeType__managedPrimitiveTypes->setEType(m_AdaptationPrimitiveTypeEClass);
    m_NodeType__managedPrimitiveTypes->setName("managedPrimitiveTypes");
    m_NodeType__managedPrimitiveTypes->setDefaultValueLiteral("");
    m_NodeType__managedPrimitiveTypes->setLowerBound(0);
    m_NodeType__managedPrimitiveTypes->setUpperBound(-1);
    m_NodeType__managedPrimitiveTypes->setTransient(false);
    m_NodeType__managedPrimitiveTypes->setVolatile(false);
    m_NodeType__managedPrimitiveTypes->setChangeable(true);
    m_NodeType__managedPrimitiveTypes->setContainment(false);
    m_NodeType__managedPrimitiveTypes->setResolveProxies(true);
    m_NodeType__managedPrimitiveTypes->setUnique(true);
    m_NodeType__managedPrimitiveTypes->setDerived(false);
    m_NodeType__managedPrimitiveTypes->setOrdered(true);
    m_NodeType__managedPrimitiveTypeRefs->setEType(
            m_AdaptationPrimitiveTypeRefEClass);
    m_NodeType__managedPrimitiveTypeRefs->setName("managedPrimitiveTypeRefs");
    m_NodeType__managedPrimitiveTypeRefs->setDefaultValueLiteral("");
    m_NodeType__managedPrimitiveTypeRefs->setLowerBound(0);
    m_NodeType__managedPrimitiveTypeRefs->setUpperBound(-1);
    m_NodeType__managedPrimitiveTypeRefs->setTransient(false);
    m_NodeType__managedPrimitiveTypeRefs->setVolatile(false);
    m_NodeType__managedPrimitiveTypeRefs->setChangeable(true);
    m_NodeType__managedPrimitiveTypeRefs->setContainment(true);
    m_NodeType__managedPrimitiveTypeRefs->setResolveProxies(true);
    m_NodeType__managedPrimitiveTypeRefs->setUnique(true);
    m_NodeType__managedPrimitiveTypeRefs->setDerived(false);
    m_NodeType__managedPrimitiveTypeRefs->setOrdered(true);
    // AdaptationPrimitiveType
    m_AdaptationPrimitiveTypeEClass->setName("AdaptationPrimitiveType");
    m_AdaptationPrimitiveTypeEClass->setAbstract(false);
    m_AdaptationPrimitiveTypeEClass->setInterface(false);
    // AdaptationPrimitiveTypeRef
    m_AdaptationPrimitiveTypeRefEClass->setName("AdaptationPrimitiveTypeRef");
    m_AdaptationPrimitiveTypeRefEClass->setAbstract(false);
    m_AdaptationPrimitiveTypeRefEClass->setInterface(false);
    m_AdaptationPrimitiveTypeRef__maxTime->setEType(
            dynamic_cast< ::ecore::EcorePackage* > (::ecore::EcorePackage::_instance())->getEString());
    m_AdaptationPrimitiveTypeRef__maxTime->setName("maxTime");
    m_AdaptationPrimitiveTypeRef__maxTime->setDefaultValueLiteral("");
    m_AdaptationPrimitiveTypeRef__maxTime->setLowerBound(0);
    m_AdaptationPrimitiveTypeRef__maxTime->setUpperBound(1);
    m_AdaptationPrimitiveTypeRef__maxTime->setTransient(false);
    m_AdaptationPrimitiveTypeRef__maxTime->setVolatile(false);
    m_AdaptationPrimitiveTypeRef__maxTime->setChangeable(true);
    m_AdaptationPrimitiveTypeRef__maxTime->setUnsettable(false);
    m_AdaptationPrimitiveTypeRef__maxTime->setID(false);
    m_AdaptationPrimitiveTypeRef__maxTime->setUnique(true);
    m_AdaptationPrimitiveTypeRef__maxTime->setDerived(false);
    m_AdaptationPrimitiveTypeRef__maxTime->setOrdered(true);
    m_AdaptationPrimitiveTypeRef__ref->setEType(m_AdaptationPrimitiveTypeEClass);
    m_AdaptationPrimitiveTypeRef__ref->setName("ref");
    m_AdaptationPrimitiveTypeRef__ref->setDefaultValueLiteral("");
    m_AdaptationPrimitiveTypeRef__ref->setLowerBound(1);
    m_AdaptationPrimitiveTypeRef__ref->setUpperBound(1);
    m_AdaptationPrimitiveTypeRef__ref->setTransient(false);
    m_AdaptationPrimitiveTypeRef__ref->setVolatile(false);
    m_AdaptationPrimitiveTypeRef__ref->setChangeable(true);
    m_AdaptationPrimitiveTypeRef__ref->setContainment(false);
    m_AdaptationPrimitiveTypeRef__ref->setResolveProxies(true);
    m_AdaptationPrimitiveTypeRef__ref->setUnique(true);
    m_AdaptationPrimitiveTypeRef__ref->setDerived(false);
    m_AdaptationPrimitiveTypeRef__ref->setOrdered(true);

    // TODO: Initialize data types


    _initialize();
}

::ecore::EClass_ptr KevoreePackage::getComponentInstance()
{
    return m_ComponentInstanceEClass;
}
::ecore::EClass_ptr KevoreePackage::getComponentType()
{
    return m_ComponentTypeEClass;
}
::ecore::EClass_ptr KevoreePackage::getContainerNode()
{
    return m_ContainerNodeEClass;
}
::ecore::EClass_ptr KevoreePackage::getContainerRoot()
{
    return m_ContainerRootEClass;
}
::ecore::EClass_ptr KevoreePackage::getPortType()
{
    return m_PortTypeEClass;
}
::ecore::EClass_ptr KevoreePackage::getPort()
{
    return m_PortEClass;
}
::ecore::EClass_ptr KevoreePackage::getNamespace()
{
    return m_NamespaceEClass;
}
::ecore::EClass_ptr KevoreePackage::getDictionary()
{
    return m_DictionaryEClass;
}
::ecore::EClass_ptr KevoreePackage::getDictionaryType()
{
    return m_DictionaryTypeEClass;
}
::ecore::EClass_ptr KevoreePackage::getDictionaryAttribute()
{
    return m_DictionaryAttributeEClass;
}
::ecore::EClass_ptr KevoreePackage::getDictionaryValue()
{
    return m_DictionaryValueEClass;
}
::ecore::EClass_ptr KevoreePackage::getCompositeType()
{
    return m_CompositeTypeEClass;
}
::ecore::EClass_ptr KevoreePackage::getPortTypeRef()
{
    return m_PortTypeRefEClass;
}
::ecore::EClass_ptr KevoreePackage::getWire()
{
    return m_WireEClass;
}
::ecore::EClass_ptr KevoreePackage::getServicePortType()
{
    return m_ServicePortTypeEClass;
}
::ecore::EClass_ptr KevoreePackage::getOperation()
{
    return m_OperationEClass;
}
::ecore::EClass_ptr KevoreePackage::getParameter()
{
    return m_ParameterEClass;
}
::ecore::EClass_ptr KevoreePackage::getTypedElement()
{
    return m_TypedElementEClass;
}
::ecore::EClass_ptr KevoreePackage::getMessagePortType()
{
    return m_MessagePortTypeEClass;
}
::ecore::EClass_ptr KevoreePackage::getRepository()
{
    return m_RepositoryEClass;
}
::ecore::EClass_ptr KevoreePackage::getDeployUnit()
{
    return m_DeployUnitEClass;
}
::ecore::EClass_ptr KevoreePackage::getTypeLibrary()
{
    return m_TypeLibraryEClass;
}
::ecore::EClass_ptr KevoreePackage::getNamedElement()
{
    return m_NamedElementEClass;
}
::ecore::EClass_ptr KevoreePackage::getIntegrationPattern()
{
    return m_IntegrationPatternEClass;
}
::ecore::EClass_ptr KevoreePackage::getExtraFonctionalProperty()
{
    return m_ExtraFonctionalPropertyEClass;
}
::ecore::EClass_ptr KevoreePackage::getPortTypeMapping()
{
    return m_PortTypeMappingEClass;
}
::ecore::EClass_ptr KevoreePackage::getChannel()
{
    return m_ChannelEClass;
}
::ecore::EClass_ptr KevoreePackage::getMBinding()
{
    return m_MBindingEClass;
}
::ecore::EClass_ptr KevoreePackage::getNodeNetwork()
{
    return m_NodeNetworkEClass;
}
::ecore::EClass_ptr KevoreePackage::getNodeLink()
{
    return m_NodeLinkEClass;
}
::ecore::EClass_ptr KevoreePackage::getNetworkProperty()
{
    return m_NetworkPropertyEClass;
}
::ecore::EClass_ptr KevoreePackage::getChannelType()
{
    return m_ChannelTypeEClass;
}
::ecore::EClass_ptr KevoreePackage::getTypeDefinition()
{
    return m_TypeDefinitionEClass;
}
::ecore::EClass_ptr KevoreePackage::getInstance()
{
    return m_InstanceEClass;
}
::ecore::EClass_ptr KevoreePackage::getLifeCycleTypeDefinition()
{
    return m_LifeCycleTypeDefinitionEClass;
}
::ecore::EClass_ptr KevoreePackage::getGroup()
{
    return m_GroupEClass;
}
::ecore::EClass_ptr KevoreePackage::getGroupType()
{
    return m_GroupTypeEClass;
}
::ecore::EClass_ptr KevoreePackage::getNodeType()
{
    return m_NodeTypeEClass;
}
::ecore::EClass_ptr KevoreePackage::getAdaptationPrimitiveType()
{
    return m_AdaptationPrimitiveTypeEClass;
}
::ecore::EClass_ptr KevoreePackage::getAdaptationPrimitiveTypeRef()
{
    return m_AdaptationPrimitiveTypeRefEClass;
}

::ecore::EAttribute_ptr KevoreePackage::getNamedElement__name()
{
    return m_NamedElement__name;
}
::ecore::EReference_ptr KevoreePackage::getInstance__typeDefinition()
{
    return m_Instance__typeDefinition;
}
::ecore::EReference_ptr KevoreePackage::getInstance__dictionary()
{
    return m_Instance__dictionary;
}
::ecore::EAttribute_ptr KevoreePackage::getInstance__metaData()
{
    return m_Instance__metaData;
}
::ecore::EAttribute_ptr KevoreePackage::getInstance__started()
{
    return m_Instance__started;
}
::ecore::EReference_ptr KevoreePackage::getComponentInstance__provided()
{
    return m_ComponentInstance__provided;
}
::ecore::EReference_ptr KevoreePackage::getComponentInstance__required()
{
    return m_ComponentInstance__required;
}
::ecore::EReference_ptr KevoreePackage::getComponentInstance__namespace()
{
    return m_ComponentInstance__namespace;
}
::ecore::EReference_ptr KevoreePackage::getTypeDefinition__deployUnits()
{
    return m_TypeDefinition__deployUnits;
}
::ecore::EAttribute_ptr KevoreePackage::getTypeDefinition__factoryBean()
{
    return m_TypeDefinition__factoryBean;
}
::ecore::EAttribute_ptr KevoreePackage::getTypeDefinition__bean()
{
    return m_TypeDefinition__bean;
}
::ecore::EReference_ptr KevoreePackage::getTypeDefinition__dictionaryType()
{
    return m_TypeDefinition__dictionaryType;
}
::ecore::EReference_ptr KevoreePackage::getTypeDefinition__superTypes()
{
    return m_TypeDefinition__superTypes;
}
::ecore::EAttribute_ptr KevoreePackage::getTypeDefinition__abstract()
{
    return m_TypeDefinition__abstract;
}
::ecore::EAttribute_ptr KevoreePackage::getLifeCycleTypeDefinition__startMethod()
{
    return m_LifeCycleTypeDefinition__startMethod;
}
::ecore::EAttribute_ptr KevoreePackage::getLifeCycleTypeDefinition__stopMethod()
{
    return m_LifeCycleTypeDefinition__stopMethod;
}
::ecore::EAttribute_ptr KevoreePackage::getLifeCycleTypeDefinition__updateMethod()
{
    return m_LifeCycleTypeDefinition__updateMethod;
}
::ecore::EReference_ptr KevoreePackage::getComponentType__required()
{
    return m_ComponentType__required;
}
::ecore::EReference_ptr KevoreePackage::getComponentType__integrationPatterns()
{
    return m_ComponentType__integrationPatterns;
}
::ecore::EReference_ptr KevoreePackage::getComponentType__extraFonctionalProperties()
{
    return m_ComponentType__extraFonctionalProperties;
}
::ecore::EReference_ptr KevoreePackage::getComponentType__provided()
{
    return m_ComponentType__provided;
}
::ecore::EReference_ptr KevoreePackage::getContainerNode__components()
{
    return m_ContainerNode__components;
}
::ecore::EReference_ptr KevoreePackage::getContainerNode__hosts()
{
    return m_ContainerNode__hosts;
}
::ecore::EReference_ptr KevoreePackage::getContainerNode__host()
{
    return m_ContainerNode__host;
}
::ecore::EReference_ptr KevoreePackage::getContainerRoot__nodes()
{
    return m_ContainerRoot__nodes;
}
::ecore::EReference_ptr KevoreePackage::getContainerRoot__typeDefinitions()
{
    return m_ContainerRoot__typeDefinitions;
}
::ecore::EReference_ptr KevoreePackage::getContainerRoot__repositories()
{
    return m_ContainerRoot__repositories;
}
::ecore::EReference_ptr KevoreePackage::getContainerRoot__dataTypes()
{
    return m_ContainerRoot__dataTypes;
}
::ecore::EReference_ptr KevoreePackage::getContainerRoot__libraries()
{
    return m_ContainerRoot__libraries;
}
::ecore::EReference_ptr KevoreePackage::getContainerRoot__hubs()
{
    return m_ContainerRoot__hubs;
}
::ecore::EReference_ptr KevoreePackage::getContainerRoot__mBindings()
{
    return m_ContainerRoot__mBindings;
}
::ecore::EReference_ptr KevoreePackage::getContainerRoot__deployUnits()
{
    return m_ContainerRoot__deployUnits;
}
::ecore::EReference_ptr KevoreePackage::getContainerRoot__nodeNetworks()
{
    return m_ContainerRoot__nodeNetworks;
}
::ecore::EReference_ptr KevoreePackage::getContainerRoot__groups()
{
    return m_ContainerRoot__groups;
}
::ecore::EReference_ptr KevoreePackage::getContainerRoot__adaptationPrimitiveTypes()
{
    return m_ContainerRoot__adaptationPrimitiveTypes;
}
::ecore::EAttribute_ptr KevoreePackage::getPortType__synchrone()
{
    return m_PortType__synchrone;
}
::ecore::EReference_ptr KevoreePackage::getPort__bindings()
{
    return m_Port__bindings;
}
::ecore::EReference_ptr KevoreePackage::getPort__portTypeRef()
{
    return m_Port__portTypeRef;
}
::ecore::EReference_ptr KevoreePackage::getNamespace__childs()
{
    return m_Namespace__childs;
}
::ecore::EReference_ptr KevoreePackage::getNamespace__parent()
{
    return m_Namespace__parent;
}
::ecore::EReference_ptr KevoreePackage::getDictionary__values()
{
    return m_Dictionary__values;
}
::ecore::EReference_ptr KevoreePackage::getDictionaryType__attributes()
{
    return m_DictionaryType__attributes;
}
::ecore::EReference_ptr KevoreePackage::getDictionaryType__defaultValues()
{
    return m_DictionaryType__defaultValues;
}
::ecore::EReference_ptr KevoreePackage::getTypedElement__genericTypes()
{
    return m_TypedElement__genericTypes;
}
::ecore::EAttribute_ptr KevoreePackage::getDictionaryAttribute__optional()
{
    return m_DictionaryAttribute__optional;
}
::ecore::EAttribute_ptr KevoreePackage::getDictionaryAttribute__state()
{
    return m_DictionaryAttribute__state;
}
::ecore::EAttribute_ptr KevoreePackage::getDictionaryAttribute__datatype()
{
    return m_DictionaryAttribute__datatype;
}
::ecore::EAttribute_ptr KevoreePackage::getDictionaryAttribute__fragmentDependant()
{
    return m_DictionaryAttribute__fragmentDependant;
}
::ecore::EReference_ptr KevoreePackage::getDictionaryValue__attribute()
{
    return m_DictionaryValue__attribute;
}
::ecore::EAttribute_ptr KevoreePackage::getDictionaryValue__value()
{
    return m_DictionaryValue__value;
}
::ecore::EReference_ptr KevoreePackage::getDictionaryValue__targetNode()
{
    return m_DictionaryValue__targetNode;
}
::ecore::EReference_ptr KevoreePackage::getCompositeType__childs()
{
    return m_CompositeType__childs;
}
::ecore::EReference_ptr KevoreePackage::getCompositeType__wires()
{
    return m_CompositeType__wires;
}
::ecore::EReference_ptr KevoreePackage::getPortTypeRef__ref()
{
    return m_PortTypeRef__ref;
}
::ecore::EReference_ptr KevoreePackage::getPortTypeRef__mappings()
{
    return m_PortTypeRef__mappings;
}
::ecore::EAttribute_ptr KevoreePackage::getPortTypeRef__optional()
{
    return m_PortTypeRef__optional;
}
::ecore::EAttribute_ptr KevoreePackage::getPortTypeRef__noDependency()
{
    return m_PortTypeRef__noDependency;
}
::ecore::EReference_ptr KevoreePackage::getWire__ports()
{
    return m_Wire__ports;
}
::ecore::EReference_ptr KevoreePackage::getServicePortType__operations()
{
    return m_ServicePortType__operations;
}
::ecore::EAttribute_ptr KevoreePackage::getServicePortType__interface()
{
    return m_ServicePortType__interface;
}
::ecore::EReference_ptr KevoreePackage::getOperation__parameters()
{
    return m_Operation__parameters;
}
::ecore::EReference_ptr KevoreePackage::getOperation__returnType()
{
    return m_Operation__returnType;
}
::ecore::EReference_ptr KevoreePackage::getParameter__type()
{
    return m_Parameter__type;
}
::ecore::EAttribute_ptr KevoreePackage::getParameter__order()
{
    return m_Parameter__order;
}
::ecore::EReference_ptr KevoreePackage::getMessagePortType__filters()
{
    return m_MessagePortType__filters;
}
::ecore::EReference_ptr KevoreePackage::getRepository__units()
{
    return m_Repository__units;
}
::ecore::EAttribute_ptr KevoreePackage::getRepository__url()
{
    return m_Repository__url;
}
::ecore::EAttribute_ptr KevoreePackage::getDeployUnit__name()
{
    return m_DeployUnit__name;
}
::ecore::EAttribute_ptr KevoreePackage::getDeployUnit__groupName()
{
    return m_DeployUnit__groupName;
}
::ecore::EAttribute_ptr KevoreePackage::getDeployUnit__unitName()
{
    return m_DeployUnit__unitName;
}
::ecore::EAttribute_ptr KevoreePackage::getDeployUnit__version()
{
    return m_DeployUnit__version;
}
::ecore::EAttribute_ptr KevoreePackage::getDeployUnit__url()
{
    return m_DeployUnit__url;
}
::ecore::EAttribute_ptr KevoreePackage::getDeployUnit__hashcode()
{
    return m_DeployUnit__hashcode;
}
::ecore::EReference_ptr KevoreePackage::getDeployUnit__requiredLibs()
{
    return m_DeployUnit__requiredLibs;
}
::ecore::EReference_ptr KevoreePackage::getDeployUnit__targetNodeType()
{
    return m_DeployUnit__targetNodeType;
}
::ecore::EAttribute_ptr KevoreePackage::getDeployUnit__type()
{
    return m_DeployUnit__type;
}
::ecore::EReference_ptr KevoreePackage::getTypeLibrary__subTypes()
{
    return m_TypeLibrary__subTypes;
}
::ecore::EReference_ptr KevoreePackage::getIntegrationPattern__extraFonctionalProperties()
{
    return m_IntegrationPattern__extraFonctionalProperties;
}
::ecore::EReference_ptr KevoreePackage::getIntegrationPattern__portTypes()
{
    return m_IntegrationPattern__portTypes;
}
::ecore::EReference_ptr KevoreePackage::getExtraFonctionalProperty__portTypes()
{
    return m_ExtraFonctionalProperty__portTypes;
}
::ecore::EAttribute_ptr KevoreePackage::getPortTypeMapping__beanMethodName()
{
    return m_PortTypeMapping__beanMethodName;
}
::ecore::EAttribute_ptr KevoreePackage::getPortTypeMapping__serviceMethodName()
{
    return m_PortTypeMapping__serviceMethodName;
}
::ecore::EAttribute_ptr KevoreePackage::getPortTypeMapping__paramTypes()
{
    return m_PortTypeMapping__paramTypes;
}
::ecore::EReference_ptr KevoreePackage::getChannel__bindings()
{
    return m_Channel__bindings;
}
::ecore::EReference_ptr KevoreePackage::getMBinding__port()
{
    return m_MBinding__port;
}
::ecore::EReference_ptr KevoreePackage::getMBinding__hub()
{
    return m_MBinding__hub;
}
::ecore::EReference_ptr KevoreePackage::getNodeNetwork__link()
{
    return m_NodeNetwork__link;
}
::ecore::EReference_ptr KevoreePackage::getNodeNetwork__initBy()
{
    return m_NodeNetwork__initBy;
}
::ecore::EReference_ptr KevoreePackage::getNodeNetwork__target()
{
    return m_NodeNetwork__target;
}
::ecore::EAttribute_ptr KevoreePackage::getNodeLink__networkType()
{
    return m_NodeLink__networkType;
}
::ecore::EAttribute_ptr KevoreePackage::getNodeLink__estimatedRate()
{
    return m_NodeLink__estimatedRate;
}
::ecore::EReference_ptr KevoreePackage::getNodeLink__networkProperties()
{
    return m_NodeLink__networkProperties;
}
::ecore::EAttribute_ptr KevoreePackage::getNodeLink__lastCheck()
{
    return m_NodeLink__lastCheck;
}
::ecore::EAttribute_ptr KevoreePackage::getNodeLink__zoneID()
{
    return m_NodeLink__zoneID;
}
::ecore::EAttribute_ptr KevoreePackage::getNetworkProperty__value()
{
    return m_NetworkProperty__value;
}
::ecore::EAttribute_ptr KevoreePackage::getNetworkProperty__lastCheck()
{
    return m_NetworkProperty__lastCheck;
}
::ecore::EAttribute_ptr KevoreePackage::getChannelType__lowerBindings()
{
    return m_ChannelType__lowerBindings;
}
::ecore::EAttribute_ptr KevoreePackage::getChannelType__upperBindings()
{
    return m_ChannelType__upperBindings;
}
::ecore::EAttribute_ptr KevoreePackage::getChannelType__lowerFragments()
{
    return m_ChannelType__lowerFragments;
}
::ecore::EAttribute_ptr KevoreePackage::getChannelType__upperFragments()
{
    return m_ChannelType__upperFragments;
}
::ecore::EReference_ptr KevoreePackage::getGroup__subNodes()
{
    return m_Group__subNodes;
}
::ecore::EReference_ptr KevoreePackage::getNodeType__managedPrimitiveTypes()
{
    return m_NodeType__managedPrimitiveTypes;
}
::ecore::EReference_ptr KevoreePackage::getNodeType__managedPrimitiveTypeRefs()
{
    return m_NodeType__managedPrimitiveTypeRefs;
}
::ecore::EReference_ptr KevoreePackage::getAdaptationPrimitiveTypeRef__ref()
{
    return m_AdaptationPrimitiveTypeRef__ref;
}
::ecore::EAttribute_ptr KevoreePackage::getAdaptationPrimitiveTypeRef__maxTime()
{
    return m_AdaptationPrimitiveTypeRef__maxTime;
}

