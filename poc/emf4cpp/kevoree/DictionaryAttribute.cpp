// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/DictionaryAttribute.cpp
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

#include "DictionaryAttribute.hpp"
#include <kevoree/TypedElement.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
DictionaryAttribute::DictionaryAttribute()
{

    /*PROTECTED REGION ID(DictionaryAttributeImpl__DictionaryAttributeImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

DictionaryAttribute::~DictionaryAttribute()
{
}

/*PROTECTED REGION ID(DictionaryAttribute.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EBoolean DictionaryAttribute::isOptional() const
{
    return m_optional;
}

void DictionaryAttribute::setOptional(::ecore::EBoolean _optional)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBoolean _old_optional = m_optional;
#endif
    m_optional = _optional;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDictionaryAttribute__optional(),
                _old_optional,
                m_optional
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EBoolean DictionaryAttribute::isState() const
{
    return m_state;
}

void DictionaryAttribute::setState(::ecore::EBoolean _state)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBoolean _old_state = m_state;
#endif
    m_state = _state;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDictionaryAttribute__state(),
                _old_state,
                m_state
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& DictionaryAttribute::getDatatype() const
{
    return m_datatype;
}

void DictionaryAttribute::setDatatype(::ecore::EString const& _datatype)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_datatype = m_datatype;
#endif
    m_datatype = _datatype;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDictionaryAttribute__datatype(),
                _old_datatype,
                m_datatype
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EBoolean DictionaryAttribute::isFragmentDependant() const
{
    return m_fragmentDependant;
}

void DictionaryAttribute::setFragmentDependant(
        ::ecore::EBoolean _fragmentDependant)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBoolean _old_fragmentDependant = m_fragmentDependant;
#endif
    m_fragmentDependant = _fragmentDependant;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDictionaryAttribute__fragmentDependant(),
                _old_fragmentDependant,
                m_fragmentDependant
        );
        eNotify(&notification);
    }
#endif
}

// References

