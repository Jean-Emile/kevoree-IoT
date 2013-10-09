// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/ChannelImpl.cpp
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

#include "Channel.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/NamedElement.hpp>
#include <kevoree/Instance.hpp>
#include <kevoree/TypeDefinition.hpp>
#include <kevoree/Dictionary.hpp>
#include <kevoree/MBinding.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(ChannelImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void Channel::_initialize()
{
    // Supertypes
    ::kevoree::NamedElement::_initialize();
    ::kevoree::Instance::_initialize();

    // Rerefences

    /*PROTECTED REGION ID(ChannelImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject Channel::eGet(::ecore::EInt _featureID,
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
    case ::kevoree::KevoreePackage::INSTANCE__TYPEDEFINITION:
    {
        _any = static_cast< ::ecore::EObject* > (m_typeDefinition);
    }
        return _any;
    case ::kevoree::KevoreePackage::INSTANCE__DICTIONARY:
    {
        _any = static_cast< ::ecore::EObject* > (m_dictionary);
    }
        return _any;
    case ::kevoree::KevoreePackage::INSTANCE__METADATA:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_metaData);
    }
        return _any;
    case ::kevoree::KevoreePackage::INSTANCE__STARTED:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBoolean >::toAny(_any,
                m_started);
    }
        return _any;
    case ::kevoree::KevoreePackage::CHANNEL__BINDINGS:
    {
        _any = m_bindings->asEListOf< ::ecore::EObject > ();
    }
        return _any;

    }
    throw "Error";
}

void Channel::eSet(::ecore::EInt _featureID,
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
    case ::kevoree::KevoreePackage::INSTANCE__TYPEDEFINITION:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::kevoree::TypeDefinition_ptr _t1 =
                dynamic_cast< ::kevoree::TypeDefinition_ptr > (_t0);
        ::kevoree::Instance::setTypeDefinition(_t1);
    }
        return;
    case ::kevoree::KevoreePackage::INSTANCE__DICTIONARY:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::kevoree::Dictionary_ptr _t1 =
                dynamic_cast< ::kevoree::Dictionary_ptr > (_t0);
        ::kevoree::Instance::setDictionary(_t1);
    }
        return;
    case ::kevoree::KevoreePackage::INSTANCE__METADATA:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_metaData);
    }
        return;
    case ::kevoree::KevoreePackage::INSTANCE__STARTED:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBoolean >::fromAny(
                _newValue, m_started);
    }
        return;
    case ::kevoree::KevoreePackage::CHANNEL__BINDINGS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::Channel::getBindings().clear();
        ::kevoree::Channel::getBindings().insert_all(*_t0);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean Channel::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NAMEDELEMENT__NAME:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_name);
    case ::kevoree::KevoreePackage::INSTANCE__TYPEDEFINITION:
        return m_typeDefinition;
    case ::kevoree::KevoreePackage::INSTANCE__DICTIONARY:
        return m_dictionary;
    case ::kevoree::KevoreePackage::INSTANCE__METADATA:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_metaData);
    case ::kevoree::KevoreePackage::INSTANCE__STARTED:
        return m_started != true;
    case ::kevoree::KevoreePackage::CHANNEL__BINDINGS:
        return m_bindings && m_bindings->size();

    }
    throw "Error";
}

void Channel::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr Channel::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getChannel();
    return _eclass;
}

