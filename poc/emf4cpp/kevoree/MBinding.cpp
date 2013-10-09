// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/MBinding.cpp
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

#include "MBinding.hpp"
#include <kevoree/Port.hpp>
#include <kevoree/Channel.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
MBinding::MBinding() :
    m_port(0), m_hub(0)
{

    /*PROTECTED REGION ID(MBindingImpl__MBindingImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

MBinding::~MBinding()
{
}

/*PROTECTED REGION ID(MBinding.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::kevoree::Port_ptr MBinding::getPort()
{
    return m_port;
}

void MBinding::setPort(::kevoree::Port_ptr _port)
{
    ::kevoree::Port_ptr _old_port = m_port;

    m_port = _port;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getMBinding__port(),
                _old_port,
                m_port
        );
        eNotify(&notification);
    }
#endif

}

::kevoree::Channel_ptr MBinding::getHub()
{
    return m_hub;
}

void MBinding::setHub(::kevoree::Channel_ptr _hub)
{
    ::kevoree::Channel_ptr _old_hub = m_hub;

    m_hub = _hub;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getMBinding__hub(),
                _old_hub,
                m_hub
        );
        eNotify(&notification);
    }
#endif

}

