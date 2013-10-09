// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/NodeNetworkImpl.cpp
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

#include "NodeNetwork.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/NodeLink.hpp>
#include <kevoree/ContainerNode.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(NodeNetworkImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void NodeNetwork::_initialize()
{
    // Supertypes

    // Rerefences
    for (size_t i = 0; i < m_link->size(); i++)
    {
        (*m_link)[i]->_initialize();
        (*m_link)[i]->_setEContainer(this,
                ::kevoree::KevoreePackage::_instance()->getNodeNetwork__link());
    }

    /*PROTECTED REGION ID(NodeNetworkImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject NodeNetwork::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NODENETWORK__LINK:
    {
        _any = m_link->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::NODENETWORK__INITBY:
    {
        _any = static_cast< ::ecore::EObject* > (m_initBy);
    }
        return _any;
    case ::kevoree::KevoreePackage::NODENETWORK__TARGET:
    {
        _any = static_cast< ::ecore::EObject* > (m_target);
    }
        return _any;

    }
    throw "Error";
}

void NodeNetwork::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NODENETWORK__LINK:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::NodeNetwork::getLink().clear();
        ::kevoree::NodeNetwork::getLink().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::NODENETWORK__INITBY:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::kevoree::ContainerNode_ptr _t1 =
                dynamic_cast< ::kevoree::ContainerNode_ptr > (_t0);
        ::kevoree::NodeNetwork::setInitBy(_t1);
    }
        return;
    case ::kevoree::KevoreePackage::NODENETWORK__TARGET:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::kevoree::ContainerNode_ptr _t1 =
                dynamic_cast< ::kevoree::ContainerNode_ptr > (_t0);
        ::kevoree::NodeNetwork::setTarget(_t1);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean NodeNetwork::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NODENETWORK__LINK:
        return m_link && m_link->size();
    case ::kevoree::KevoreePackage::NODENETWORK__INITBY:
        return m_initBy;
    case ::kevoree::KevoreePackage::NODENETWORK__TARGET:
        return m_target;

    }
    throw "Error";
}

void NodeNetwork::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr NodeNetwork::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getNodeNetwork();
    return _eclass;
}

