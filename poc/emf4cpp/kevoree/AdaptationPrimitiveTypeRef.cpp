// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/AdaptationPrimitiveTypeRef.cpp
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

#include "AdaptationPrimitiveTypeRef.hpp"
#include <kevoree/AdaptationPrimitiveType.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
AdaptationPrimitiveTypeRef::AdaptationPrimitiveTypeRef() :
    m_ref(0)
{

    /*PROTECTED REGION ID(AdaptationPrimitiveTypeRefImpl__AdaptationPrimitiveTypeRefImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

AdaptationPrimitiveTypeRef::~AdaptationPrimitiveTypeRef()
{
}

/*PROTECTED REGION ID(AdaptationPrimitiveTypeRef.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EString const& AdaptationPrimitiveTypeRef::getMaxTime() const
{
    return m_maxTime;
}

void AdaptationPrimitiveTypeRef::setMaxTime(::ecore::EString const& _maxTime)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_maxTime = m_maxTime;
#endif
    m_maxTime = _maxTime;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getAdaptationPrimitiveTypeRef__maxTime(),
                _old_maxTime,
                m_maxTime
        );
        eNotify(&notification);
    }
#endif
}

// References
::kevoree::AdaptationPrimitiveType_ptr AdaptationPrimitiveTypeRef::getRef()
{
    return m_ref;
}

void AdaptationPrimitiveTypeRef::setRef(
        ::kevoree::AdaptationPrimitiveType_ptr _ref)
{
    ::kevoree::AdaptationPrimitiveType_ptr _old_ref = m_ref;

    m_ref = _ref;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getAdaptationPrimitiveTypeRef__ref(),
                _old_ref,
                m_ref
        );
        eNotify(&notification);
    }
#endif

}

