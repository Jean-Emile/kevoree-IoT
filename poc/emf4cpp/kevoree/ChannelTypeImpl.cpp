// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/ChannelTypeImpl.cpp
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

#include "ChannelType.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/LifeCycleTypeDefinition.hpp>
#include <kevoree/DeployUnit.hpp>
#include <kevoree/DictionaryType.hpp>
#include <kevoree/TypeDefinition.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(ChannelTypeImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void ChannelType::_initialize()
{
    // Supertypes
    ::kevoree::LifeCycleTypeDefinition::_initialize();

    // Rerefences

    /*PROTECTED REGION ID(ChannelTypeImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject ChannelType::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NAMEDELEMENT__NAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any, m_name);
    }
        return _any;
    case ::kevoree::KevoreePackage::TYPEDEFINITION__DEPLOYUNITS:
    {
        _any = m_deployUnits->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::TYPEDEFINITION__FACTORYBEAN:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_factoryBean);
    }
        return _any;
    case ::kevoree::KevoreePackage::TYPEDEFINITION__BEAN:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any, m_bean);
    }
        return _any;
    case ::kevoree::KevoreePackage::TYPEDEFINITION__DICTIONARYTYPE:
    {
        _any = static_cast< ::ecore::EObject* > (m_dictionaryType);
    }
        return _any;
    case ::kevoree::KevoreePackage::TYPEDEFINITION__SUPERTYPES:
    {
        _any = m_superTypes->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::TYPEDEFINITION__ABSTRACT:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBoolean >::toAny(_any,
                m_abstract);
    }
        return _any;
    case ::kevoree::KevoreePackage::LIFECYCLETYPEDEFINITION__STARTMETHOD:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_startMethod);
    }
        return _any;
    case ::kevoree::KevoreePackage::LIFECYCLETYPEDEFINITION__STOPMETHOD:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_stopMethod);
    }
        return _any;
    case ::kevoree::KevoreePackage::LIFECYCLETYPEDEFINITION__UPDATEMETHOD:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_updateMethod);
    }
        return _any;
    case ::kevoree::KevoreePackage::CHANNELTYPE__LOWERBINDINGS:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EIntegerObject >::toAny(_any,
                m_lowerBindings);
    }
        return _any;
    case ::kevoree::KevoreePackage::CHANNELTYPE__UPPERBINDINGS:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EIntegerObject >::toAny(_any,
                m_upperBindings);
    }
        return _any;
    case ::kevoree::KevoreePackage::CHANNELTYPE__LOWERFRAGMENTS:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EIntegerObject >::toAny(_any,
                m_lowerFragments);
    }
        return _any;
    case ::kevoree::KevoreePackage::CHANNELTYPE__UPPERFRAGMENTS:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EIntegerObject >::toAny(_any,
                m_upperFragments);
    }
        return _any;

    }
    throw "Error";
}

void ChannelType::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NAMEDELEMENT__NAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_name);
    }
        return;
    case ::kevoree::KevoreePackage::TYPEDEFINITION__DEPLOYUNITS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::TypeDefinition::getDeployUnits().clear();
        ::kevoree::TypeDefinition::getDeployUnits().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::TYPEDEFINITION__FACTORYBEAN:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_factoryBean);
    }
        return;
    case ::kevoree::KevoreePackage::TYPEDEFINITION__BEAN:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_bean);
    }
        return;
    case ::kevoree::KevoreePackage::TYPEDEFINITION__DICTIONARYTYPE:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::kevoree::DictionaryType_ptr _t1 =
                dynamic_cast< ::kevoree::DictionaryType_ptr > (_t0);
        ::kevoree::TypeDefinition::setDictionaryType(_t1);
    }
        return;
    case ::kevoree::KevoreePackage::TYPEDEFINITION__SUPERTYPES:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::TypeDefinition::getSuperTypes().clear();
        ::kevoree::TypeDefinition::getSuperTypes().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::TYPEDEFINITION__ABSTRACT:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBoolean >::fromAny(
                _newValue, m_abstract);
    }
        return;
    case ::kevoree::KevoreePackage::LIFECYCLETYPEDEFINITION__STARTMETHOD:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_startMethod);
    }
        return;
    case ::kevoree::KevoreePackage::LIFECYCLETYPEDEFINITION__STOPMETHOD:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_stopMethod);
    }
        return;
    case ::kevoree::KevoreePackage::LIFECYCLETYPEDEFINITION__UPDATEMETHOD:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_updateMethod);
    }
        return;
    case ::kevoree::KevoreePackage::CHANNELTYPE__LOWERBINDINGS:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EIntegerObject >::fromAny(
                _newValue, m_lowerBindings);
    }
        return;
    case ::kevoree::KevoreePackage::CHANNELTYPE__UPPERBINDINGS:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EIntegerObject >::fromAny(
                _newValue, m_upperBindings);
    }
        return;
    case ::kevoree::KevoreePackage::CHANNELTYPE__LOWERFRAGMENTS:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EIntegerObject >::fromAny(
                _newValue, m_lowerFragments);
    }
        return;
    case ::kevoree::KevoreePackage::CHANNELTYPE__UPPERFRAGMENTS:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EIntegerObject >::fromAny(
                _newValue, m_upperFragments);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean ChannelType::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NAMEDELEMENT__NAME:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_name);
    case ::kevoree::KevoreePackage::TYPEDEFINITION__DEPLOYUNITS:
        return m_deployUnits && m_deployUnits->size();
    case ::kevoree::KevoreePackage::TYPEDEFINITION__FACTORYBEAN:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_factoryBean);
    case ::kevoree::KevoreePackage::TYPEDEFINITION__BEAN:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_bean);
    case ::kevoree::KevoreePackage::TYPEDEFINITION__DICTIONARYTYPE:
        return m_dictionaryType;
    case ::kevoree::KevoreePackage::TYPEDEFINITION__SUPERTYPES:
        return m_superTypes && m_superTypes->size();
    case ::kevoree::KevoreePackage::TYPEDEFINITION__ABSTRACT:
        return ::ecorecpp::mapping::set_traits< ::ecore::EBoolean >::is_set(
                m_abstract);
    case ::kevoree::KevoreePackage::LIFECYCLETYPEDEFINITION__STARTMETHOD:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_startMethod);
    case ::kevoree::KevoreePackage::LIFECYCLETYPEDEFINITION__STOPMETHOD:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_stopMethod);
    case ::kevoree::KevoreePackage::LIFECYCLETYPEDEFINITION__UPDATEMETHOD:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_updateMethod);
    case ::kevoree::KevoreePackage::CHANNELTYPE__LOWERBINDINGS:
        return ::ecorecpp::mapping::set_traits< ::ecore::EIntegerObject >::is_set(
                m_lowerBindings);
    case ::kevoree::KevoreePackage::CHANNELTYPE__UPPERBINDINGS:
        return ::ecorecpp::mapping::set_traits< ::ecore::EIntegerObject >::is_set(
                m_upperBindings);
    case ::kevoree::KevoreePackage::CHANNELTYPE__LOWERFRAGMENTS:
        return ::ecorecpp::mapping::set_traits< ::ecore::EIntegerObject >::is_set(
                m_lowerFragments);
    case ::kevoree::KevoreePackage::CHANNELTYPE__UPPERFRAGMENTS:
        return ::ecorecpp::mapping::set_traits< ::ecore::EIntegerObject >::is_set(
                m_upperFragments);

    }
    throw "Error";
}

void ChannelType::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr ChannelType::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getChannelType();
    return _eclass;
}

