// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/DeployUnitImpl.cpp
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

#include "DeployUnit.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/DeployUnit.hpp>
#include <kevoree/NodeType.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(DeployUnitImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void DeployUnit::_initialize()
{
    // Supertypes

    // Rerefences

    /*PROTECTED REGION ID(DeployUnitImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject DeployUnit::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::DEPLOYUNIT__NAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any, m_name);
    }
        return _any;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__GROUPNAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_groupName);
    }
        return _any;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__UNITNAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_unitName);
    }
        return _any;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__VERSION:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_version);
    }
        return _any;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__URL:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any, m_url);
    }
        return _any;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__HASHCODE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_hashcode);
    }
        return _any;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__REQUIREDLIBS:
    {
        _any = m_requiredLibs->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__TARGETNODETYPE:
    {
        _any = static_cast< ::ecore::EObject* > (m_targetNodeType);
    }
        return _any;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__TYPE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any, m_type);
    }
        return _any;

    }
    throw "Error";
}

void DeployUnit::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::DEPLOYUNIT__NAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_name);
    }
        return;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__GROUPNAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_groupName);
    }
        return;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__UNITNAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_unitName);
    }
        return;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__VERSION:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_version);
    }
        return;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__URL:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_url);
    }
        return;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__HASHCODE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_hashcode);
    }
        return;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__REQUIREDLIBS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::DeployUnit::getRequiredLibs().clear();
        ::kevoree::DeployUnit::getRequiredLibs().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__TARGETNODETYPE:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::kevoree::NodeType_ptr _t1 =
                dynamic_cast< ::kevoree::NodeType_ptr > (_t0);
        ::kevoree::DeployUnit::setTargetNodeType(_t1);
    }
        return;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__TYPE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_type);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean DeployUnit::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::DEPLOYUNIT__NAME:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_name);
    case ::kevoree::KevoreePackage::DEPLOYUNIT__GROUPNAME:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_groupName);
    case ::kevoree::KevoreePackage::DEPLOYUNIT__UNITNAME:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_unitName);
    case ::kevoree::KevoreePackage::DEPLOYUNIT__VERSION:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_version);
    case ::kevoree::KevoreePackage::DEPLOYUNIT__URL:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_url);
    case ::kevoree::KevoreePackage::DEPLOYUNIT__HASHCODE:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_hashcode);
    case ::kevoree::KevoreePackage::DEPLOYUNIT__REQUIREDLIBS:
        return m_requiredLibs && m_requiredLibs->size();
    case ::kevoree::KevoreePackage::DEPLOYUNIT__TARGETNODETYPE:
        return m_targetNodeType;
    case ::kevoree::KevoreePackage::DEPLOYUNIT__TYPE:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_type);

    }
    throw "Error";
}

void DeployUnit::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr DeployUnit::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getDeployUnit();
    return _eclass;
}

