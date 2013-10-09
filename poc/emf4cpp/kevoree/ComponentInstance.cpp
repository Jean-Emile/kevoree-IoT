// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/ComponentInstance.cpp
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

#include "ComponentInstance.hpp"
#include <kevoree/NamedElement.hpp>
#include <kevoree/Instance.hpp>
#include <kevoree/TypeDefinition.hpp>
#include <kevoree/Dictionary.hpp>
#include <kevoree/Port.hpp>
#include <kevoree/Namespace.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
ComponentInstance::ComponentInstance() :
    m_namespace(0)
{

    m_provided.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::Port, -1, true, false >(this, NULL));
    m_required.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::Port, -1, true, false >(this, NULL));

    /*PROTECTED REGION ID(ComponentInstanceImpl__ComponentInstanceImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

ComponentInstance::~ComponentInstance()
{
}

/*PROTECTED REGION ID(ComponentInstance.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::ecorecpp::mapping::EList< ::kevoree::Port >& ComponentInstance::getProvided()
{
    return *m_provided;
}

::ecorecpp::mapping::EList< ::kevoree::Port >& ComponentInstance::getRequired()
{
    return *m_required;
}

::kevoree::Namespace_ptr ComponentInstance::getNamespace()
{
    return m_namespace;
}

void ComponentInstance::setNamespace(::kevoree::Namespace_ptr _namespace)
{
    ::kevoree::Namespace_ptr _old_namespace = m_namespace;

    m_namespace = _namespace;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getComponentInstance__namespace(),
                _old_namespace,
                m_namespace
        );
        eNotify(&notification);
    }
#endif

}

