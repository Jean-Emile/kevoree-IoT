// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/NetworkProperty.cpp
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

#include "NetworkProperty.hpp"
#include <kevoree/NamedElement.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
NetworkProperty::NetworkProperty()
{

    /*PROTECTED REGION ID(NetworkPropertyImpl__NetworkPropertyImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

NetworkProperty::~NetworkProperty()
{
}

/*PROTECTED REGION ID(NetworkProperty.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EString const& NetworkProperty::getValue() const
{
    return m_value;
}

void NetworkProperty::setValue(::ecore::EString const& _value)
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
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getNetworkProperty__value(),
                _old_value,
                m_value
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& NetworkProperty::getLastCheck() const
{
    return m_lastCheck;
}

void NetworkProperty::setLastCheck(::ecore::EString const& _lastCheck)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_lastCheck = m_lastCheck;
#endif
    m_lastCheck = _lastCheck;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getNetworkProperty__lastCheck(),
                _old_lastCheck,
                m_lastCheck
        );
        eNotify(&notification);
    }
#endif
}

// References

