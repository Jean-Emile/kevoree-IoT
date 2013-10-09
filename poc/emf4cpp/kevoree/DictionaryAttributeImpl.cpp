// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/DictionaryAttributeImpl.cpp
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

#include "DictionaryAttribute.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/TypedElement.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(DictionaryAttributeImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void DictionaryAttribute::_initialize()
{
    // Supertypes
    ::kevoree::TypedElement::_initialize();

    // Rerefences

    /*PROTECTED REGION ID(DictionaryAttributeImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject DictionaryAttribute::eGet(::ecore::EInt _featureID,
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
    case ::kevoree::KevoreePackage::TYPEDELEMENT__GENERICTYPES:
    {
        _any = m_genericTypes->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__OPTIONAL:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBoolean >::toAny(_any,
                m_optional);
    }
        return _any;
    case ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__STATE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBoolean >::toAny(_any,
                m_state);
    }
        return _any;
    case ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__DATATYPE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_datatype);
    }
        return _any;
    case ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__FRAGMENTDEPENDANT:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBoolean >::toAny(_any,
                m_fragmentDependant);
    }
        return _any;

    }
    throw "Error";
}

void DictionaryAttribute::eSet(::ecore::EInt _featureID,
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
    case ::kevoree::KevoreePackage::TYPEDELEMENT__GENERICTYPES:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::TypedElement::getGenericTypes().clear();
        ::kevoree::TypedElement::getGenericTypes().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__OPTIONAL:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBoolean >::fromAny(
                _newValue, m_optional);
    }
        return;
    case ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__STATE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBoolean >::fromAny(
                _newValue, m_state);
    }
        return;
    case ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__DATATYPE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_datatype);
    }
        return;
    case ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__FRAGMENTDEPENDANT:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBoolean >::fromAny(
                _newValue, m_fragmentDependant);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean DictionaryAttribute::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NAMEDELEMENT__NAME:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_name);
    case ::kevoree::KevoreePackage::TYPEDELEMENT__GENERICTYPES:
        return m_genericTypes && m_genericTypes->size();
    case ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__OPTIONAL:
        return ::ecorecpp::mapping::set_traits< ::ecore::EBoolean >::is_set(
                m_optional);
    case ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__STATE:
        return ::ecorecpp::mapping::set_traits< ::ecore::EBoolean >::is_set(
                m_state);
    case ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__DATATYPE:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_datatype);
    case ::kevoree::KevoreePackage::DICTIONARYATTRIBUTE__FRAGMENTDEPENDANT:
        return ::ecorecpp::mapping::set_traits< ::ecore::EBoolean >::is_set(
                m_fragmentDependant);

    }
    throw "Error";
}

void DictionaryAttribute::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr DictionaryAttribute::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getDictionaryAttribute();
    return _eclass;
}

