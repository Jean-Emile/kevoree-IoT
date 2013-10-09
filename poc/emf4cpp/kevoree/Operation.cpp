// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/Operation.cpp
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

#include "Operation.hpp"
#include <kevoree/NamedElement.hpp>
#include <kevoree/Parameter.hpp>
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
Operation::Operation() :
    m_returnType(0)
{

    m_parameters.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::Parameter, -1, true, false >(this, NULL));

    /*PROTECTED REGION ID(OperationImpl__OperationImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

Operation::~Operation()
{
}

/*PROTECTED REGION ID(Operation.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::ecorecpp::mapping::EList< ::kevoree::Parameter >& Operation::getParameters()
{
    return *m_parameters;
}

::kevoree::TypedElement_ptr Operation::getReturnType()
{
    return m_returnType;
}

void Operation::setReturnType(::kevoree::TypedElement_ptr _returnType)
{
    ::kevoree::TypedElement_ptr _old_returnType = m_returnType;

    m_returnType = _returnType;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getOperation__returnType(),
                _old_returnType,
                m_returnType
        );
        eNotify(&notification);
    }
#endif

}

