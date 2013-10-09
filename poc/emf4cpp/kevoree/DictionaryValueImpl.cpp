// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/DictionaryValueImpl.cpp
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

#include "DictionaryValue.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/DictionaryAttribute.hpp>
#include <kevoree/ContainerNode.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(DictionaryValueImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void DictionaryValue::_initialize()
{
    // Supertypes

    // Rerefences

    /*PROTECTED REGION ID(DictionaryValueImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject DictionaryValue::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::DICTIONARYVALUE__ATTRIBUTE:
    {
        _any = static_cast< ::ecore::EObject* > (m_attribute);
    }
        return _any;
    case ::kevoree::KevoreePackage::DICTIONARYVALUE__VALUE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_value);
    }
        return _any;
    case ::kevoree::KevoreePackage::DICTIONARYVALUE__TARGETNODE:
    {
        _any = static_cast< ::ecore::EObject* > (m_targetNode);
    }
        return _any;

    }
    throw "Error";
}

void DictionaryValue::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::DICTIONARYVALUE__ATTRIBUTE:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::kevoree::DictionaryAttribute_ptr _t1 =
                dynamic_cast< ::kevoree::DictionaryAttribute_ptr > (_t0);
        ::kevoree::DictionaryValue::setAttribute(_t1);
    }
        return;
    case ::kevoree::KevoreePackage::DICTIONARYVALUE__VALUE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_value);
    }
        return;
    case ::kevoree::KevoreePackage::DICTIONARYVALUE__TARGETNODE:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::kevoree::ContainerNode_ptr _t1 =
                dynamic_cast< ::kevoree::ContainerNode_ptr > (_t0);
        ::kevoree::DictionaryValue::setTargetNode(_t1);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean DictionaryValue::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::DICTIONARYVALUE__ATTRIBUTE:
        return m_attribute;
    case ::kevoree::KevoreePackage::DICTIONARYVALUE__VALUE:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_value);
    case ::kevoree::KevoreePackage::DICTIONARYVALUE__TARGETNODE:
        return m_targetNode;

    }
    throw "Error";
}

void DictionaryValue::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr DictionaryValue::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getDictionaryValue();
    return _eclass;
}

