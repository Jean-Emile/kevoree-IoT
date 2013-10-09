// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/Instance.cpp
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

#include "Instance.hpp"
#include <kevoree/NamedElement.hpp>
#include <kevoree/TypeDefinition.hpp>
#include <kevoree/Dictionary.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
Instance::Instance() :
    m_started(true), m_typeDefinition(0), m_dictionary(0)
{

    /*PROTECTED REGION ID(InstanceImpl__InstanceImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

Instance::~Instance()
{
    if (m_dictionary)
    {
        delete m_dictionary;
    }
}

/*PROTECTED REGION ID(Instance.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EString const& Instance::getMetaData() const
{
    return m_metaData;
}

void Instance::setMetaData(::ecore::EString const& _metaData)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_metaData = m_metaData;
#endif
    m_metaData = _metaData;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getInstance__metaData(),
                _old_metaData,
                m_metaData
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EBoolean Instance::isStarted() const
{
    return m_started;
}

void Instance::setStarted(::ecore::EBoolean _started)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBoolean _old_started = m_started;
#endif
    m_started = _started;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getInstance__started(),
                _old_started,
                m_started
        );
        eNotify(&notification);
    }
#endif
}

// References
::kevoree::TypeDefinition_ptr Instance::getTypeDefinition()
{
    return m_typeDefinition;
}

void Instance::setTypeDefinition(::kevoree::TypeDefinition_ptr _typeDefinition)
{
    ::kevoree::TypeDefinition_ptr _old_typeDefinition = m_typeDefinition;

    m_typeDefinition = _typeDefinition;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getInstance__typeDefinition(),
                _old_typeDefinition,
                m_typeDefinition
        );
        eNotify(&notification);
    }
#endif

}

::kevoree::Dictionary_ptr Instance::getDictionary()
{
    return m_dictionary;
}

void Instance::setDictionary(::kevoree::Dictionary_ptr _dictionary)
{
    ::kevoree::Dictionary_ptr _old_dictionary = m_dictionary;

    m_dictionary = _dictionary;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getInstance__dictionary(),
                _old_dictionary,
                m_dictionary
        );
        eNotify(&notification);
    }
#endif

    delete _old_dictionary;
}

