// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/IntegrationPatternImpl.cpp
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

#include "IntegrationPattern.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/NamedElement.hpp>
#include <kevoree/ExtraFonctionalProperty.hpp>
#include <kevoree/PortTypeRef.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(IntegrationPatternImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void IntegrationPattern::_initialize()
{
    // Supertypes
    ::kevoree::NamedElement::_initialize();

    // Rerefences
    for (size_t i = 0; i < m_extraFonctionalProperties->size(); i++)
    {
        (*m_extraFonctionalProperties)[i]->_initialize();
        (*m_extraFonctionalProperties)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getIntegrationPattern__extraFonctionalProperties());
    }

    /*PROTECTED REGION ID(IntegrationPatternImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject IntegrationPattern::eGet(::ecore::EInt _featureID,
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
    case ::kevoree::KevoreePackage::INTEGRATIONPATTERN__EXTRAFONCTIONALPROPERTIES:
    {
        _any = m_extraFonctionalProperties->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::INTEGRATIONPATTERN__PORTTYPES:
    {
        _any = m_portTypes->asEListOf< ::ecore::EObject > ();
    }
        return _any;

    }
    throw "Error";
}

void IntegrationPattern::eSet(::ecore::EInt _featureID,
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
    case ::kevoree::KevoreePackage::INTEGRATIONPATTERN__EXTRAFONCTIONALPROPERTIES:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::IntegrationPattern::getExtraFonctionalProperties().clear();
        ::kevoree::IntegrationPattern::getExtraFonctionalProperties().insert_all(
                *_t0);
    }
        return;
    case ::kevoree::KevoreePackage::INTEGRATIONPATTERN__PORTTYPES:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::IntegrationPattern::getPortTypes().clear();
        ::kevoree::IntegrationPattern::getPortTypes().insert_all(*_t0);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean IntegrationPattern::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NAMEDELEMENT__NAME:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_name);
    case ::kevoree::KevoreePackage::INTEGRATIONPATTERN__EXTRAFONCTIONALPROPERTIES:
        return m_extraFonctionalProperties
                && m_extraFonctionalProperties->size();
    case ::kevoree::KevoreePackage::INTEGRATIONPATTERN__PORTTYPES:
        return m_portTypes && m_portTypes->size();

    }
    throw "Error";
}

void IntegrationPattern::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr IntegrationPattern::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getIntegrationPattern();
    return _eclass;
}

