// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/LifeCycleTypeDefinition.cpp
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

#include "LifeCycleTypeDefinition.hpp"
#include <kevoree/TypeDefinition.hpp>
#include <kevoree/DeployUnit.hpp>
#include <kevoree/DictionaryType.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
LifeCycleTypeDefinition::LifeCycleTypeDefinition()
{

    /*PROTECTED REGION ID(LifeCycleTypeDefinitionImpl__LifeCycleTypeDefinitionImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

LifeCycleTypeDefinition::~LifeCycleTypeDefinition()
{
}

/*PROTECTED REGION ID(LifeCycleTypeDefinition.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EString const& LifeCycleTypeDefinition::getStartMethod() const
{
    return m_startMethod;
}

void LifeCycleTypeDefinition::setStartMethod(
        ::ecore::EString const& _startMethod)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_startMethod = m_startMethod;
#endif
    m_startMethod = _startMethod;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getLifeCycleTypeDefinition__startMethod(),
                _old_startMethod,
                m_startMethod
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& LifeCycleTypeDefinition::getStopMethod() const
{
    return m_stopMethod;
}

void LifeCycleTypeDefinition::setStopMethod(::ecore::EString const& _stopMethod)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_stopMethod = m_stopMethod;
#endif
    m_stopMethod = _stopMethod;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getLifeCycleTypeDefinition__stopMethod(),
                _old_stopMethod,
                m_stopMethod
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& LifeCycleTypeDefinition::getUpdateMethod() const
{
    return m_updateMethod;
}

void LifeCycleTypeDefinition::setUpdateMethod(
        ::ecore::EString const& _updateMethod)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_updateMethod = m_updateMethod;
#endif
    m_updateMethod = _updateMethod;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getLifeCycleTypeDefinition__updateMethod(),
                _old_updateMethod,
                m_updateMethod
        );
        eNotify(&notification);
    }
#endif
}

// References

