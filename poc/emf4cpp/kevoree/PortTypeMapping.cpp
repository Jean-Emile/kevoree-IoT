// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/PortTypeMapping.cpp
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

#include "PortTypeMapping.hpp"
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
PortTypeMapping::PortTypeMapping()
{

    /*PROTECTED REGION ID(PortTypeMappingImpl__PortTypeMappingImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

PortTypeMapping::~PortTypeMapping()
{
}

/*PROTECTED REGION ID(PortTypeMapping.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EString const& PortTypeMapping::getBeanMethodName() const
{
    return m_beanMethodName;
}

void PortTypeMapping::setBeanMethodName(::ecore::EString const& _beanMethodName)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_beanMethodName = m_beanMethodName;
#endif
    m_beanMethodName = _beanMethodName;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getPortTypeMapping__beanMethodName(),
                _old_beanMethodName,
                m_beanMethodName
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& PortTypeMapping::getServiceMethodName() const
{
    return m_serviceMethodName;
}

void PortTypeMapping::setServiceMethodName(
        ::ecore::EString const& _serviceMethodName)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_serviceMethodName = m_serviceMethodName;
#endif
    m_serviceMethodName = _serviceMethodName;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getPortTypeMapping__serviceMethodName(),
                _old_serviceMethodName,
                m_serviceMethodName
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& PortTypeMapping::getParamTypes() const
{
    return m_paramTypes;
}

void PortTypeMapping::setParamTypes(::ecore::EString const& _paramTypes)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_paramTypes = m_paramTypes;
#endif
    m_paramTypes = _paramTypes;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getPortTypeMapping__paramTypes(),
                _old_paramTypes,
                m_paramTypes
        );
        eNotify(&notification);
    }
#endif
}

// References

