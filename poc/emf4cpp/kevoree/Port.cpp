// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/Port.cpp
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

#include "Port.hpp"
#include <kevoree/MBinding.hpp>
#include <kevoree/PortTypeRef.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
Port::Port() :
    m_portTypeRef(0)
{

    m_bindings.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::MBinding, -1, false, true >(this, NULL));

    /*PROTECTED REGION ID(PortImpl__PortImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

Port::~Port()
{
}

/*PROTECTED REGION ID(Port.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::ecorecpp::mapping::EList< ::kevoree::MBinding >& Port::getBindings()
{
    return *m_bindings;
}

::kevoree::PortTypeRef_ptr Port::getPortTypeRef()
{
    return m_portTypeRef;
}

void Port::setPortTypeRef(::kevoree::PortTypeRef_ptr _portTypeRef)
{
    ::kevoree::PortTypeRef_ptr _old_portTypeRef = m_portTypeRef;

    m_portTypeRef = _portTypeRef;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getPort__portTypeRef(),
                _old_portTypeRef,
                m_portTypeRef
        );
        eNotify(&notification);
    }
#endif

}

