// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/MBindingImpl.cpp
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

#include "MBinding.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/Port.hpp>
#include <kevoree/Channel.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(MBindingImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void MBinding::_initialize()
{
    // Supertypes

    // Rerefences

    /*PROTECTED REGION ID(MBindingImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject MBinding::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::MBINDING__PORT:
    {
        _any = static_cast< ::ecore::EObject* > (m_port);
    }
        return _any;
    case ::kevoree::KevoreePackage::MBINDING__HUB:
    {
        _any = static_cast< ::ecore::EObject* > (m_hub);
    }
        return _any;

    }
    throw "Error";
}

void MBinding::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::MBINDING__PORT:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::kevoree::Port_ptr _t1 = dynamic_cast< ::kevoree::Port_ptr > (_t0);
        ::kevoree::MBinding::setPort(_t1);
    }
        return;
    case ::kevoree::KevoreePackage::MBINDING__HUB:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::kevoree::Channel_ptr _t1 =
                dynamic_cast< ::kevoree::Channel_ptr > (_t0);
        ::kevoree::MBinding::setHub(_t1);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean MBinding::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::MBINDING__PORT:
        return m_port;
    case ::kevoree::KevoreePackage::MBINDING__HUB:
        return m_hub;

    }
    throw "Error";
}

void MBinding::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr MBinding::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getMBinding();
    return _eclass;
}

