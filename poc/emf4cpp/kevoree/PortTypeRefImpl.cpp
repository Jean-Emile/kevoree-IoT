// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/PortTypeRefImpl.cpp
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

#include "PortTypeRef.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/NamedElement.hpp>
#include <kevoree/PortType.hpp>
#include <kevoree/PortTypeMapping.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(PortTypeRefImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void PortTypeRef::_initialize()
{
    // Supertypes
    ::kevoree::NamedElement::_initialize();

    // Rerefences
    for (size_t i = 0; i < m_mappings->size(); i++)
    {
        (*m_mappings)[i]->_initialize();
        (*m_mappings)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getPortTypeRef__mappings());
    }

    /*PROTECTED REGION ID(PortTypeRefImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject PortTypeRef::eGet(::ecore::EInt _featureID,
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
    case ::kevoree::KevoreePackage::PORTTYPEREF__REF:
    {
        _any = static_cast< ::ecore::EObject* > (m_ref);
    }
        return _any;
    case ::kevoree::KevoreePackage::PORTTYPEREF__MAPPINGS:
    {
        _any = m_mappings->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::PORTTYPEREF__OPTIONAL:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBooleanObject >::toAny(_any,
                m_optional);
    }
        return _any;
    case ::kevoree::KevoreePackage::PORTTYPEREF__NODEPENDENCY:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBooleanObject >::toAny(_any,
                m_noDependency);
    }
        return _any;

    }
    throw "Error";
}

void PortTypeRef::eSet(::ecore::EInt _featureID,
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
    case ::kevoree::KevoreePackage::PORTTYPEREF__REF:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::kevoree::PortType_ptr _t1 =
                dynamic_cast< ::kevoree::PortType_ptr > (_t0);
        ::kevoree::PortTypeRef::setRef(_t1);
    }
        return;
    case ::kevoree::KevoreePackage::PORTTYPEREF__MAPPINGS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::PortTypeRef::getMappings().clear();
        ::kevoree::PortTypeRef::getMappings().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::PORTTYPEREF__OPTIONAL:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBooleanObject >::fromAny(
                _newValue, m_optional);
    }
        return;
    case ::kevoree::KevoreePackage::PORTTYPEREF__NODEPENDENCY:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EBooleanObject >::fromAny(
                _newValue, m_noDependency);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean PortTypeRef::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NAMEDELEMENT__NAME:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_name);
    case ::kevoree::KevoreePackage::PORTTYPEREF__REF:
        return m_ref;
    case ::kevoree::KevoreePackage::PORTTYPEREF__MAPPINGS:
        return m_mappings && m_mappings->size();
    case ::kevoree::KevoreePackage::PORTTYPEREF__OPTIONAL:
        return ::ecorecpp::mapping::set_traits< ::ecore::EBooleanObject >::is_set(
                m_optional);
    case ::kevoree::KevoreePackage::PORTTYPEREF__NODEPENDENCY:
        return ::ecorecpp::mapping::set_traits< ::ecore::EBooleanObject >::is_set(
                m_noDependency);

    }
    throw "Error";
}

void PortTypeRef::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr PortTypeRef::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getPortTypeRef();
    return _eclass;
}

