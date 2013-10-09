// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/DeployUnit.cpp
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

#include "DeployUnit.hpp"
#include <kevoree/DeployUnit.hpp>
#include <kevoree/NodeType.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
DeployUnit::DeployUnit() :
    m_targetNodeType(0)
{

    m_requiredLibs.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::DeployUnit, -1, false, false >(this, NULL));

    /*PROTECTED REGION ID(DeployUnitImpl__DeployUnitImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

DeployUnit::~DeployUnit()
{
}

/*PROTECTED REGION ID(DeployUnit.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EString const& DeployUnit::getName() const
{
    return m_name;
}

void DeployUnit::setName(::ecore::EString const& _name)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_name = m_name;
#endif
    m_name = _name;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDeployUnit__name(),
                _old_name,
                m_name
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& DeployUnit::getGroupName() const
{
    return m_groupName;
}

void DeployUnit::setGroupName(::ecore::EString const& _groupName)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_groupName = m_groupName;
#endif
    m_groupName = _groupName;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDeployUnit__groupName(),
                _old_groupName,
                m_groupName
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& DeployUnit::getUnitName() const
{
    return m_unitName;
}

void DeployUnit::setUnitName(::ecore::EString const& _unitName)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_unitName = m_unitName;
#endif
    m_unitName = _unitName;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDeployUnit__unitName(),
                _old_unitName,
                m_unitName
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& DeployUnit::getVersion() const
{
    return m_version;
}

void DeployUnit::setVersion(::ecore::EString const& _version)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_version = m_version;
#endif
    m_version = _version;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDeployUnit__version(),
                _old_version,
                m_version
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& DeployUnit::getUrl() const
{
    return m_url;
}

void DeployUnit::setUrl(::ecore::EString const& _url)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_url = m_url;
#endif
    m_url = _url;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDeployUnit__url(),
                _old_url,
                m_url
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& DeployUnit::getHashcode() const
{
    return m_hashcode;
}

void DeployUnit::setHashcode(::ecore::EString const& _hashcode)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_hashcode = m_hashcode;
#endif
    m_hashcode = _hashcode;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDeployUnit__hashcode(),
                _old_hashcode,
                m_hashcode
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& DeployUnit::getType() const
{
    return m_type;
}

void DeployUnit::setType(::ecore::EString const& _type)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_type = m_type;
#endif
    m_type = _type;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDeployUnit__type(),
                _old_type,
                m_type
        );
        eNotify(&notification);
    }
#endif
}

// References
::ecorecpp::mapping::EList< ::kevoree::DeployUnit >& DeployUnit::getRequiredLibs()
{
    return *m_requiredLibs;
}

::kevoree::NodeType_ptr DeployUnit::getTargetNodeType()
{
    return m_targetNodeType;
}

void DeployUnit::setTargetNodeType(::kevoree::NodeType_ptr _targetNodeType)
{
    ::kevoree::NodeType_ptr _old_targetNodeType = m_targetNodeType;

    m_targetNodeType = _targetNodeType;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getDeployUnit__targetNodeType(),
                _old_targetNodeType,
                m_targetNodeType
        );
        eNotify(&notification);
    }
#endif

}

