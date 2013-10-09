// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/PortTypeMappingImpl.cpp
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

#include "PortTypeMapping.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(PortTypeMappingImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void PortTypeMapping::_initialize()
{
    // Supertypes

    // Rerefences

    /*PROTECTED REGION ID(PortTypeMappingImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject PortTypeMapping::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::PORTTYPEMAPPING__BEANMETHODNAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_beanMethodName);
    }
        return _any;
    case ::kevoree::KevoreePackage::PORTTYPEMAPPING__SERVICEMETHODNAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_serviceMethodName);
    }
        return _any;
    case ::kevoree::KevoreePackage::PORTTYPEMAPPING__PARAMTYPES:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_paramTypes);
    }
        return _any;

    }
    throw "Error";
}

void PortTypeMapping::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::PORTTYPEMAPPING__BEANMETHODNAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_beanMethodName);
    }
        return;
    case ::kevoree::KevoreePackage::PORTTYPEMAPPING__SERVICEMETHODNAME:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_serviceMethodName);
    }
        return;
    case ::kevoree::KevoreePackage::PORTTYPEMAPPING__PARAMTYPES:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_paramTypes);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean PortTypeMapping::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::PORTTYPEMAPPING__BEANMETHODNAME:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_beanMethodName);
    case ::kevoree::KevoreePackage::PORTTYPEMAPPING__SERVICEMETHODNAME:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_serviceMethodName);
    case ::kevoree::KevoreePackage::PORTTYPEMAPPING__PARAMTYPES:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_paramTypes);

    }
    throw "Error";
}

void PortTypeMapping::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr PortTypeMapping::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getPortTypeMapping();
    return _eclass;
}

