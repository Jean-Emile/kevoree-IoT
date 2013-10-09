// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/NodeLink.cpp
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
#include <kevoree/NetworkProperty.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
NodeLink::NodeLink()
{

    m_networkProperties.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::NetworkProperty, -1, true, false >(this, NULL));

    /*PROTECTED REGION ID(NodeLinkImpl__NodeLinkImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

NodeLink::~NodeLink()
{
}

/*PROTECTED REGION ID(NodeLink.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EString const& NodeLink::getNetworkType() const
{
    return m_networkType;
}

void NodeLink::setNetworkType(::ecore::EString const& _networkType)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_networkType = m_networkType;
#endif
    m_networkType = _networkType;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getNodeLink__networkType(),
                _old_networkType,
                m_networkType
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EIntegerObject NodeLink::getEstimatedRate() const
{
    return m_estimatedRate;
}

void NodeLink::setEstimatedRate(::ecore::EIntegerObject _estimatedRate)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EIntegerObject _old_estimatedRate = m_estimatedRate;
#endif
    m_estimatedRate = _estimatedRate;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getNodeLink__estimatedRate(),
                _old_estimatedRate,
                m_estimatedRate
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& NodeLink::getLastCheck() const
{
    return m_lastCheck;
}

void NodeLink::setLastCheck(::ecore::EString const& _lastCheck)
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
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getNodeLink__lastCheck(),
                _old_lastCheck,
                m_lastCheck
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& NodeLink::getZoneID() const
{
    return m_zoneID;
}

void NodeLink::setZoneID(::ecore::EString const& _zoneID)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_zoneID = m_zoneID;
#endif
    m_zoneID = _zoneID;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getNodeLink__zoneID(),
                _old_zoneID,
                m_zoneID
        );
        eNotify(&notification);
    }
#endif
}

// References
::ecorecpp::mapping::EList< ::kevoree::NetworkProperty >& NodeLink::getNetworkProperties()
{
    return *m_networkProperties;
}

