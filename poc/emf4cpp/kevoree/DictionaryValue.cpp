// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/DictionaryValue.cpp
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
#include <kevoree/DictionaryAttribute.hpp>
#include <kevoree/ContainerNode.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
DictionaryValue::DictionaryValue() :
    m_attribute(0), m_targetNode(0)
{

    /*PROTECTED REGION ID(DictionaryValueImpl__DictionaryValueImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

DictionaryValue::~DictionaryValue()
{
}

/*PROTECTED REGION ID(DictionaryValue.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EString const& DictionaryValue::getValue() const
{
    return m_value;
}

void DictionaryValue::setValue(::ecore::EString const& _value)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_value = m_value;
#endif
    m_value = _value;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDictionaryValue__value(),
                _old_value,
                m_value
        );
        eNotify(&notification);
    }
#endif
}

// References
::kevoree::DictionaryAttribute_ptr DictionaryValue::getAttribute()
{
    return m_attribute;
}

void DictionaryValue::setAttribute(
        ::kevoree::DictionaryAttribute_ptr _attribute)
{
    ::kevoree::DictionaryAttribute_ptr _old_attribute = m_attribute;

    m_attribute = _attribute;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDictionaryValue__attribute(),
                _old_attribute,
                m_attribute
        );
        eNotify(&notification);
    }
#endif

}

::kevoree::ContainerNode_ptr DictionaryValue::getTargetNode()
{
    return m_targetNode;
}

void DictionaryValue::setTargetNode(::kevoree::ContainerNode_ptr _targetNode)
{
    ::kevoree::ContainerNode_ptr _old_targetNode = m_targetNode;

    m_targetNode = _targetNode;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDictionaryValue__targetNode(),
                _old_targetNode,
                m_targetNode
        );
        eNotify(&notification);
    }
#endif

}

