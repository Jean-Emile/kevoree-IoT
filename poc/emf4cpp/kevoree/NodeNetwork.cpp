// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/NodeNetwork.cpp
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

#include "NodeNetwork.hpp"
#include <kevoree/NodeLink.hpp>
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
NodeNetwork::NodeNetwork() :
    m_initBy(0), m_target(0)
{

    m_link.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::NodeLink, -1, true, false >(this, NULL));

    /*PROTECTED REGION ID(NodeNetworkImpl__NodeNetworkImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

NodeNetwork::~NodeNetwork()
{
}

/*PROTECTED REGION ID(NodeNetwork.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::ecorecpp::mapping::EList< ::kevoree::NodeLink >& NodeNetwork::getLink()
{
    return *m_link;
}

::kevoree::ContainerNode_ptr NodeNetwork::getInitBy()
{
    return m_initBy;
}

void NodeNetwork::setInitBy(::kevoree::ContainerNode_ptr _initBy)
{
    ::kevoree::ContainerNode_ptr _old_initBy = m_initBy;

    m_initBy = _initBy;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getNodeNetwork__initBy(),
                _old_initBy,
                m_initBy
        );
        eNotify(&notification);
    }
#endif

}

::kevoree::ContainerNode_ptr NodeNetwork::getTarget()
{
    return m_target;
}

void NodeNetwork::setTarget(::kevoree::ContainerNode_ptr _target)
{
    ::kevoree::ContainerNode_ptr _old_target = m_target;

    m_target = _target;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getNodeNetwork__target(),
                _old_target,
                m_target
        );
        eNotify(&notification);
    }
#endif

}

