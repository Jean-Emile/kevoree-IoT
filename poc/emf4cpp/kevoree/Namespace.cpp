// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/Namespace.cpp
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

#include "Namespace.hpp"
#include <kevoree/NamedElement.hpp>
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
Namespace::Namespace() :
    m_parent(0)
{

    m_childs.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::Namespace, -1, true, false >(this, NULL));

    /*PROTECTED REGION ID(NamespaceImpl__NamespaceImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

Namespace::~Namespace()
{
}

/*PROTECTED REGION ID(Namespace.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::ecorecpp::mapping::EList< ::kevoree::Namespace >& Namespace::getChilds()
{
    return *m_childs;
}

::kevoree::Namespace_ptr Namespace::getParent()
{
    return m_parent;
}

void Namespace::setParent(::kevoree::Namespace_ptr _parent)
{
    ::kevoree::Namespace_ptr _old_parent = m_parent;

    m_parent = _parent;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getNamespace__parent(),
                _old_parent,
                m_parent
        );
        eNotify(&notification);
    }
#endif

}

