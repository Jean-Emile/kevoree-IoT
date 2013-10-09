// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/PortTypeRef.cpp
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

#include "PortTypeRef.hpp"
#include <kevoree/NamedElement.hpp>
#include <kevoree/PortType.hpp>
#include <kevoree/PortTypeMapping.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
PortTypeRef::PortTypeRef() :
    m_ref(0)
{

    m_mappings.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::PortTypeMapping, -1, true, false >(this, NULL));

    /*PROTECTED REGION ID(PortTypeRefImpl__PortTypeRefImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

PortTypeRef::~PortTypeRef()
{
}

/*PROTECTED REGION ID(PortTypeRef.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EBooleanObject PortTypeRef::getOptional() const
{
    return m_optional;
}

void PortTypeRef::setOptional(::ecore::EBooleanObject _optional)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBooleanObject _old_optional = m_optional;
#endif
    m_optional = _optional;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getPortTypeRef__optional(),
                _old_optional,
                m_optional
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EBooleanObject PortTypeRef::getNoDependency() const
{
    return m_noDependency;
}

void PortTypeRef::setNoDependency(::ecore::EBooleanObject _noDependency)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBooleanObject _old_noDependency = m_noDependency;
#endif
    m_noDependency = _noDependency;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getPortTypeRef__noDependency(),
                _old_noDependency,
                m_noDependency
        );
        eNotify(&notification);
    }
#endif
}

// References
::kevoree::PortType_ptr PortTypeRef::getRef()
{
    return m_ref;
}

void PortTypeRef::setRef(::kevoree::PortType_ptr _ref)
{
    ::kevoree::PortType_ptr _old_ref = m_ref;

    m_ref = _ref;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getPortTypeRef__ref(),
                _old_ref,
                m_ref
        );
        eNotify(&notification);
    }
#endif

}

::ecorecpp::mapping::EList< ::kevoree::PortTypeMapping >& PortTypeRef::getMappings()
{
    return *m_mappings;
}

