// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/PortImpl.cpp
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

#include "Port.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/MBinding.hpp>
#include <kevoree/PortTypeRef.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(PortImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void Port::_initialize()
{
    // Supertypes

    // Rerefences

    /*PROTECTED REGION ID(PortImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject Port::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::PORT__BINDINGS:
    {
        _any = m_bindings->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::PORT__PORTTYPEREF:
    {
        _any = static_cast< ::ecore::EObject* > (m_portTypeRef);
    }
        return _any;

    }
    throw "Error";
}

void Port::eSet(::ecore::EInt _featureID, ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::PORT__BINDINGS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::Port::getBindings().clear();
        ::kevoree::Port::getBindings().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::PORT__PORTTYPEREF:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::kevoree::PortTypeRef_ptr _t1 =
                dynamic_cast< ::kevoree::PortTypeRef_ptr > (_t0);
        ::kevoree::Port::setPortTypeRef(_t1);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean Port::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::PORT__BINDINGS:
        return m_bindings && m_bindings->size();
    case ::kevoree::KevoreePackage::PORT__PORTTYPEREF:
        return m_portTypeRef;

    }
    throw "Error";
}

void Port::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr Port::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getPort();
    return _eclass;
}

