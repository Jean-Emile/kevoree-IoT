// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/ComponentType.cpp
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

#include "ComponentType.hpp"
#include <kevoree/LifeCycleTypeDefinition.hpp>
#include <kevoree/DeployUnit.hpp>
#include <kevoree/DictionaryType.hpp>
#include <kevoree/TypeDefinition.hpp>
#include <kevoree/PortTypeRef.hpp>
#include <kevoree/IntegrationPattern.hpp>
#include <kevoree/ExtraFonctionalProperty.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
ComponentType::ComponentType() :
    m_extraFonctionalProperties(0)
{

    m_required.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::PortTypeRef, -1, true, false >(this, NULL));
    m_integrationPatterns.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::IntegrationPattern, -1, true, false >(this, NULL));
    m_provided.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::PortTypeRef, -1, true, false >(this, NULL));

    /*PROTECTED REGION ID(ComponentTypeImpl__ComponentTypeImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

ComponentType::~ComponentType()
{
    if (m_extraFonctionalProperties)
    {
        delete m_extraFonctionalProperties;
    }
}

/*PROTECTED REGION ID(ComponentType.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::ecorecpp::mapping::EList< ::kevoree::PortTypeRef >& ComponentType::getRequired()
{
    return *m_required;
}

::ecorecpp::mapping::EList< ::kevoree::IntegrationPattern >& ComponentType::getIntegrationPatterns()
{
    return *m_integrationPatterns;
}

::kevoree::ExtraFonctionalProperty_ptr ComponentType::getExtraFonctionalProperties()
{
    return m_extraFonctionalProperties;
}

void ComponentType::setExtraFonctionalProperties(
        ::kevoree::ExtraFonctionalProperty_ptr _extraFonctionalProperties)
{
    ::kevoree::ExtraFonctionalProperty_ptr _old_extraFonctionalProperties =
            m_extraFonctionalProperties;

    m_extraFonctionalProperties = _extraFonctionalProperties;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getComponentType__extraFonctionalProperties(),
                _old_extraFonctionalProperties,
                m_extraFonctionalProperties
        );
        eNotify(&notification);
    }
#endif

    delete _old_extraFonctionalProperties;
}

::ecorecpp::mapping::EList< ::kevoree::PortTypeRef >& ComponentType::getProvided()
{
    return *m_provided;
}

