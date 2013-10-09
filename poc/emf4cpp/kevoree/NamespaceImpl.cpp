// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/NamespaceImpl.cpp
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

#include "Namespace.hpp"
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/NamedElement.hpp>
#include <kevoree/Namespace.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(NamespaceImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void Namespace::_initialize()
{
    // Supertypes
    ::kevoree::NamedElement::_initialize();

    // Rerefences
    for (size_t i = 0; i < m_childs->size(); i++)
    {
        (*m_childs)[i]->_initialize();
        (*m_childs)[i]->_setEContainer(this,
                ::kevoree::KevoreePackage::_instance()->getNamespace__childs());
    }

    /*PROTECTED REGION ID(NamespaceImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject Namespace::eGet(::ecore::EInt _featureID,
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
    case ::kevoree::KevoreePackage::NAMESPACE__CHILDS:
    {
        _any = m_childs->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::NAMESPACE__PARENT:
    {
        _any = static_cast< ::ecore::EObject* > (m_parent);
    }
        return _any;

    }
    throw "Error";
}

void Namespace::eSet(::ecore::EInt _featureID,
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
    case ::kevoree::KevoreePackage::NAMESPACE__CHILDS:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::Namespace::getChilds().clear();
        ::kevoree::Namespace::getChilds().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::NAMESPACE__PARENT:
    {
        ::ecore::EObject_ptr _t0 = ::ecorecpp::mapping::any::any_cast<
                ::ecore::EObject_ptr >(_newValue);
        ::kevoree::Namespace_ptr _t1 =
                dynamic_cast< ::kevoree::Namespace_ptr > (_t0);
        ::kevoree::Namespace::setParent(_t1);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean Namespace::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::NAMEDELEMENT__NAME:
        return ::ecorecpp::mapping::set_traits< ::ecore::EString >::is_set(
                m_name);
    case ::kevoree::KevoreePackage::NAMESPACE__CHILDS:
        return m_childs && m_childs->size();
    case ::kevoree::KevoreePackage::NAMESPACE__PARENT:
        return m_parent;

    }
    throw "Error";
}

void Namespace::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr Namespace::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getNamespace();
    return _eclass;
}

