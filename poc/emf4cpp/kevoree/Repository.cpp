// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/Repository.cpp
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

#include "Repository.hpp"
#include <kevoree/DeployUnit.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
Repository::Repository()
{

    m_units.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::DeployUnit, -1, false, false >(this, NULL));

    /*PROTECTED REGION ID(RepositoryImpl__RepositoryImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

Repository::~Repository()
{
}

/*PROTECTED REGION ID(Repository.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EString const& Repository::getUrl() const
{
    return m_url;
}

void Repository::setUrl(::ecore::EString const& _url)
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
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getRepository__url(),
                _old_url,
                m_url
        );
        eNotify(&notification);
    }
#endif
}

// References
::ecorecpp::mapping::EList< ::kevoree::DeployUnit >& Repository::getUnits()
{
    return *m_units;
}

