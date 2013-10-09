// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/IntegrationPattern.cpp
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

#include "IntegrationPattern.hpp"
#include <kevoree/NamedElement.hpp>
#include <kevoree/ExtraFonctionalProperty.hpp>
#include <kevoree/PortTypeRef.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
IntegrationPattern::IntegrationPattern()
{

    m_extraFonctionalProperties.reset(
            new ::ecorecpp::mapping::ReferenceEListImpl<
                    ::kevoree::ExtraFonctionalProperty, -1, true, false >(this,
                    NULL));
    m_portTypes.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::PortTypeRef, -1, false, false >(this, NULL));

    /*PROTECTED REGION ID(IntegrationPatternImpl__IntegrationPatternImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

IntegrationPattern::~IntegrationPattern()
{
}

/*PROTECTED REGION ID(IntegrationPattern.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::ecorecpp::mapping::EList< ::kevoree::ExtraFonctionalProperty >& IntegrationPattern::getExtraFonctionalProperties()
{
    return *m_extraFonctionalProperties;
}

::ecorecpp::mapping::EList< ::kevoree::PortTypeRef >& IntegrationPattern::getPortTypes()
{
    return *m_portTypes;
}

