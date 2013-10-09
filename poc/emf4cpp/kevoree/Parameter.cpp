// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/Parameter.cpp
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

#include "Parameter.hpp"
#include <kevoree/NamedElement.hpp>
#include <kevoree/TypedElement.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
Parameter::Parameter() :
    m_type(0)
{

    /*PROTECTED REGION ID(ParameterImpl__ParameterImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

Parameter::~Parameter()
{
}

/*PROTECTED REGION ID(Parameter.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EIntegerObject Parameter::getOrder() const
{
    return m_order;
}

void Parameter::setOrder(::ecore::EIntegerObject _order)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EIntegerObject _old_order = m_order;
#endif
    m_order = _order;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getParameter__order(),
                _old_order,
                m_order
        );
        eNotify(&notification);
    }
#endif
}

// References
::kevoree::TypedElement_ptr Parameter::getType()
{
    return m_type;
}

void Parameter::setType(::kevoree::TypedElement_ptr _type)
{
    ::kevoree::TypedElement_ptr _old_type = m_type;

    m_type = _type;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getParameter__type(),
                _old_type,
                m_type
        );
        eNotify(&notification);
    }
#endif

}

