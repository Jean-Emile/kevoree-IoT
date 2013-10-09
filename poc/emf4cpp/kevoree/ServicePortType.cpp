// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/ServicePortType.cpp
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

#include "ServicePortType.hpp"
#include <kevoree/PortType.hpp>
#include <kevoree/DeployUnit.hpp>
#include <kevoree/DictionaryType.hpp>
#include <kevoree/TypeDefinition.hpp>
#include <kevoree/Operation.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
ServicePortType::ServicePortType()
{

    m_operations.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::Operation, -1, true, false >(this, NULL));

    /*PROTECTED REGION ID(ServicePortTypeImpl__ServicePortTypeImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

ServicePortType::~ServicePortType()
{
}

/*PROTECTED REGION ID(ServicePortType.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EString const& ServicePortType::getInterface() const
{
    return m_interface;
}

void ServicePortType::setInterface(::ecore::EString const& _interface)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_interface = m_interface;
#endif
    m_interface = _interface;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getServicePortType__interface(),
                _old_interface,
                m_interface
        );
        eNotify(&notification);
    }
#endif
}

// References
::ecorecpp::mapping::EList< ::kevoree::Operation >& ServicePortType::getOperations()
{
    return *m_operations;
}

