// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/ContainerNode.cpp
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

#include "ContainerNode.hpp"
#include <kevoree/NamedElement.hpp>
#include <kevoree/Instance.hpp>
#include <kevoree/TypeDefinition.hpp>
#include <kevoree/Dictionary.hpp>
#include <kevoree/ComponentInstance.hpp>
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
ContainerNode::ContainerNode() :
    m_host(0)
{

    m_components.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::ComponentInstance, -1, true, false >(this, NULL));
    m_hosts.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::ContainerNode, -1, false, true >(this, NULL));

    /*PROTECTED REGION ID(ContainerNodeImpl__ContainerNodeImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

ContainerNode::~ContainerNode()
{
}

/*PROTECTED REGION ID(ContainerNode.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::ecorecpp::mapping::EList< ::kevoree::ComponentInstance >& ContainerNode::getComponents()
{
    return *m_components;
}

::ecorecpp::mapping::EList< ::kevoree::ContainerNode >& ContainerNode::getHosts()
{
    return *m_hosts;
}

::kevoree::ContainerNode_ptr ContainerNode::getHost()
{
    return m_host;
}

void ContainerNode::setHost(::kevoree::ContainerNode_ptr _host)
{
    ::kevoree::ContainerNode_ptr _old_host = m_host;

    m_host = _host;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getContainerNode__host(),
                _old_host,
                m_host
        );
        eNotify(&notification);
    }
#endif

}

