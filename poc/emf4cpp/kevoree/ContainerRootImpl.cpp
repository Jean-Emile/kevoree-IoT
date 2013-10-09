// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/ContainerRootImpl.cpp
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

#include "ContainerRoot.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/ContainerNode.hpp>
#include <kevoree/TypeDefinition.hpp>
#include <kevoree/Repository.hpp>
#include <kevoree/TypedElement.hpp>
#include <kevoree/TypeLibrary.hpp>
#include <kevoree/Channel.hpp>
#include <kevoree/MBinding.hpp>
#include <kevoree/DeployUnit.hpp>
#include <kevoree/NodeNetwork.hpp>
#include <kevoree/Group.hpp>
#include <kevoree/AdaptationPrimitiveType.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(ContainerRootImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void ContainerRoot::_initialize()
{
    // Supertypes

    // Rerefences
    for (size_t i = 0; i < m_nodes->size(); i++)
    {
        (*m_nodes)[i]->_initialize();
        (*m_nodes)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getContainerRoot__nodes());
    }
    for (size_t i = 0; i < m_typeDefinitions->size(); i++)
    {
        (*m_typeDefinitions)[i]->_initialize();
        (*m_typeDefinitions)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getContainerRoot__typeDefinitions());
    }
    for (size_t i = 0; i < m_repositories->size(); i++)
    {
        (*m_repositories)[i]->_initialize();
        (*m_repositories)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getContainerRoot__repositories());
    }
    for (size_t i = 0; i < m_dataTypes->size(); i++)
    {
        (*m_dataTypes)[i]->_initialize();
        (*m_dataTypes)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getContainerRoot__dataTypes());
    }
    for (size_t i = 0; i < m_libraries->size(); i++)
    {
        (*m_libraries)[i]->_initialize();
        (*m_libraries)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getContainerRoot__libraries());
    }
    for (size_t i = 0; i < m_hubs->size(); i++)
    {
        (*m_hubs)[i]->_initialize();
        (*m_hubs)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getContainerRoot__hubs());
    }
    for (size_t i = 0; i < m_mBindings->size(); i++)
    {
        (*m_mBindings)[i]->_initialize();
        (*m_mBindings)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getContainerRoot__mBindings());
    }
    for (size_t i = 0; i < m_deployUnits->size(); i++)
    {
        (*m_deployUnits)[i]->_initialize();
        (*m_deployUnits)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getContainerRoot__deployUnits());
    }
    for (size_t i = 0; i < m_nodeNetworks->size(); i++)
    {
        (*m_nodeNetworks)[i]->_initialize();
        (*m_nodeNetworks)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getContainerRoot__nodeNetworks());
    }
    for (size_t i = 0; i < m_groups->size(); i++)
    {
        (*m_groups)[i]->_initialize();
        (*m_groups)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getContainerRoot__groups());
    }
    for (size_t i = 0; i < m_adaptationPrimitiveTypes->size(); i++)
    {
        (*m_adaptationPrimitiveTypes)[i]->_initialize();
        (*m_adaptationPrimitiveTypes)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getContainerRoot__adaptationPrimitiveTypes());
    }

    /*PROTECTED REGION ID(ContainerRootImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject ContainerRoot::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::CONTAINERROOT__NODES:
    {
        _any = m_nodes->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::CONTAINERROOT__TYPEDEFINITIONS:
    {
        _any = m_typeDefinitions->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::CONTAINERROOT__REPOSITORIES:
    {
        _any = m_repositories->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::CONTAINERROOT__DATATYPES:
    {
        _any = m_dataTypes->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::CONTAINERROOT__LIBRARIES:
    {
        _any = m_libraries->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::CONTAINERROOT__HUBS:
    {
        _any = m_hubs->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::CONTAINERROOT__MBINDINGS:
    {
        _any = m_mBindings->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::CONTAINERROOT__DEPLOYUNITS:
    {
        _any = m_deployUnits->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::CONTAINERROOT__NODENETWORKS:
    {
        _any = m_nodeNetworks->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::CONTAINERROOT__GROUPS:
    {
        _any = m_groups->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::CONTAINERROOT__ADAPTATIONPRIMITIVETYPES:
    {
        _any = m_adaptationPrimitiveTypes->asEListOf< ::ecore::EObject > ();
    }
        return _any;

    }
    throw "Error";
}

void ContainerRoot::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::CONTAINERROOT__NODES:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::ContainerRoot::getNodes().clear();
        ::kevoree::ContainerRoot::getNodes().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::CONTAINERROOT__TYPEDEFINITIONS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::ContainerRoot::getTypeDefinitions().clear();
        ::kevoree::ContainerRoot::getTypeDefinitions().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::CONTAINERROOT__REPOSITORIES:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::ContainerRoot::getRepositories().clear();
        ::kevoree::ContainerRoot::getRepositories().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::CONTAINERROOT__DATATYPES:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::ContainerRoot::getDataTypes().clear();
        ::kevoree::ContainerRoot::getDataTypes().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::CONTAINERROOT__LIBRARIES:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::ContainerRoot::getLibraries().clear();
        ::kevoree::ContainerRoot::getLibraries().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::CONTAINERROOT__HUBS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::ContainerRoot::getHubs().clear();
        ::kevoree::ContainerRoot::getHubs().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::CONTAINERROOT__MBINDINGS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::ContainerRoot::getMBindings().clear();
        ::kevoree::ContainerRoot::getMBindings().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::CONTAINERROOT__DEPLOYUNITS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::ContainerRoot::getDeployUnits().clear();
        ::kevoree::ContainerRoot::getDeployUnits().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::CONTAINERROOT__NODENETWORKS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::ContainerRoot::getNodeNetworks().clear();
        ::kevoree::ContainerRoot::getNodeNetworks().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::CONTAINERROOT__GROUPS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::ContainerRoot::getGroups().clear();
        ::kevoree::ContainerRoot::getGroups().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::CONTAINERROOT__ADAPTATIONPRIMITIVETYPES:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::ContainerRoot::getAdaptationPrimitiveTypes().clear();
        ::kevoree::ContainerRoot::getAdaptationPrimitiveTypes().insert_all(*_t0);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean ContainerRoot::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::CONTAINERROOT__NODES:
        return m_nodes && m_nodes->size();
    case ::kevoree::KevoreePackage::CONTAINERROOT__TYPEDEFINITIONS:
        return m_typeDefinitions && m_typeDefinitions->size();
    case ::kevoree::KevoreePackage::CONTAINERROOT__REPOSITORIES:
        return m_repositories && m_repositories->size();
    case ::kevoree::KevoreePackage::CONTAINERROOT__DATATYPES:
        return m_dataTypes && m_dataTypes->size();
    case ::kevoree::KevoreePackage::CONTAINERROOT__LIBRARIES:
        return m_libraries && m_libraries->size();
    case ::kevoree::KevoreePackage::CONTAINERROOT__HUBS:
        return m_hubs && m_hubs->size();
    case ::kevoree::KevoreePackage::CONTAINERROOT__MBINDINGS:
        return m_mBindings && m_mBindings->size();
    case ::kevoree::KevoreePackage::CONTAINERROOT__DEPLOYUNITS:
        return m_deployUnits && m_deployUnits->size();
    case ::kevoree::KevoreePackage::CONTAINERROOT__NODENETWORKS:
        return m_nodeNetworks && m_nodeNetworks->size();
    case ::kevoree::KevoreePackage::CONTAINERROOT__GROUPS:
        return m_groups && m_groups->size();
    case ::kevoree::KevoreePackage::CONTAINERROOT__ADAPTATIONPRIMITIVETYPES:
        return m_adaptationPrimitiveTypes && m_adaptationPrimitiveTypes->size();

    }
    throw "Error";
}

void ContainerRoot::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr ContainerRoot::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getContainerRoot();
    return _eclass;
}

