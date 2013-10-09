// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/NodeType.cpp
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

#include "NodeType.hpp"
#include <kevoree/LifeCycleTypeDefinition.hpp>
#include <kevoree/DeployUnit.hpp>
#include <kevoree/DictionaryType.hpp>
#include <kevoree/TypeDefinition.hpp>
#include <kevoree/AdaptationPrimitiveType.hpp>
#include <kevoree/AdaptationPrimitiveTypeRef.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
NodeType::NodeType()
{

    m_managedPrimitiveTypes.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::AdaptationPrimitiveType, -1, false, false >(this, NULL));
    m_managedPrimitiveTypeRefs.reset(
            new ::ecorecpp::mapping::ReferenceEListImpl<
                    ::kevoree::AdaptationPrimitiveTypeRef, -1, true, false >(
                    this, NULL));

    /*PROTECTED REGION ID(NodeTypeImpl__NodeTypeImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

NodeType::~NodeType()
{
}

/*PROTECTED REGION ID(NodeType.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::ecorecpp::mapping::EList< ::kevoree::AdaptationPrimitiveType >& NodeType::getManagedPrimitiveTypes()
{
    return *m_managedPrimitiveTypes;
}

::ecorecpp::mapping::EList< ::kevoree::AdaptationPrimitiveTypeRef >& NodeType::getManagedPrimitiveTypeRefs()
{
    return *m_managedPrimitiveTypeRefs;
}

