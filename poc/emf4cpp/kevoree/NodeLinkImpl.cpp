// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/NodeLinkImpl.cpp
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

#include "NodeLink.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/NetworkProperty.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(NodeLinkImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void NodeLink::_initialize()
{
    // Supertypes

    // Rerefences
    for (size_t i = 0; i < m_networkProperties->size(); i++)
    {
        (*m_networkProperties)[i]->_initialize();
        (*m_networkProperties)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getNodeLink__networkProperties());
    }

    /*PROTECTED REGION ID(NodeLinkImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject NodeLink::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NODELINK__NETWORKTYPE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_networkType);
    }
        return _any;
    case ::kevoree::KevoreePackage::NODELINK__ESTIMATEDRATE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EIntegerObject >::toAny(_any,
                m_estimatedRate);
    }
        return _any;
    case ::kevoree::KevoreePackage::NODELINK__NETWORKPROPERTIES:
    {
        _any = m_networkProperties->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::NODELINK__LASTCHECK:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_lastCheck);
    }
        return _any;
    case ::kevoree::KevoreePackage::NODELINK__ZONEID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::toAny(_any,
                m_zoneID);
    }
        return _any;

    }
    throw "Error";
}

void NodeLink::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NODELINK__NETWORKTYPE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_networkType);
    }
        return;
    case ::kevoree::KevoreePackage::NODELINK__ESTIMATEDRATE:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EIntegerObject >::fromAny(
                _newValue, m_estimatedRate);
    }
        return;
    case ::kevoree::KevoreePackage::NODELINK__NETWORKPROPERTIES:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::NodeLink::getNetworkProperties().clear();
        ::kevoree::NodeLink::getNetworkProperties().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::NODELINK__LASTCHECK:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_lastCheck);
    }
        return;
    case ::kevoree::KevoreePackage::NODELINK__ZONEID:
    {
        ::ecorecpp::mapping::any_traits< ::ecore::EString >::fromAny(_newValue,
                m_zoneID);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean NodeLink::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NODELINK__NETWORKTYPE:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_networkType);
    case ::kevoree::KevoreePackage::NODELINK__ESTIMATEDRATE:
        return ::ecorecpp::mapping::set_traits< ::ecore::EIntegerObject >::is_set(
                m_estimatedRate);
    case ::kevoree::KevoreePackage::NODELINK__NETWORKPROPERTIES:
        return m_networkProperties && m_networkProperties->size();
    case ::kevoree::KevoreePackage::NODELINK__LASTCHECK:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_lastCheck);
    case ::kevoree::KevoreePackage::NODELINK__ZONEID:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_zoneID);

    }
    throw "Error";
}

void NodeLink::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr NodeLink::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getNodeLink();
    return _eclass;
}

