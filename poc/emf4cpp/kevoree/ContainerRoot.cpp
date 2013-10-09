// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/ContainerRoot.cpp
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

#include "ContainerRoot.hpp"
#include <kevoree/ContainerNode.hpp>
#include <kevoree/TypeDefinition.hpp>
#include <kevoree/Repository.hpp>
#include <kevoree/TypedElement.hpp>
#include <kevoree/TypeLibrary.hpp>
#include <kevoree/Channel.hpp>
#include <kevoree/MBinding.hpp>
#include <kevoree/DeployUnit.hpp>
#include <kevoree/NodeNetwork.hpp>
#include <kevoree/Group.hpp>
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
ContainerRoot::ContainerRoot()
{

    m_nodes.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::ContainerNode, -1, true, false >(this, NULL));
    m_typeDefinitions.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::TypeDefinition, -1, true, false >(this, NULL));
    m_repositories.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::Repository, -1, true, false >(this, NULL));
    m_dataTypes.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::TypedElement, -1, true, false >(this, NULL));
    m_libraries.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::TypeLibrary, -1, true, false >(this, NULL));
    m_hubs.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::Channel, -1, true, false >(this, NULL));
    m_mBindings.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::MBinding, -1, true, false >(this, NULL));
    m_deployUnits.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::DeployUnit, -1, true, false >(this, NULL));
    m_nodeNetworks.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::NodeNetwork, -1, true, false >(this, NULL));
    m_groups.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::Group, -1, true, false >(this, NULL));
    m_adaptationPrimitiveTypes.reset(
            new ::ecorecpp::mapping::ReferenceEListImpl<
                    ::kevoree::AdaptationPrimitiveType, -1, true, false >(this,
                    NULL));

    /*PROTECTED REGION ID(ContainerRootImpl__ContainerRootImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

ContainerRoot::~ContainerRoot()
{
}

/*PROTECTED REGION ID(ContainerRoot.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::ecorecpp::mapping::EList< ::kevoree::ContainerNode >& ContainerRoot::getNodes()
{
    return *m_nodes;
}

::ecorecpp::mapping::EList< ::kevoree::TypeDefinition >& ContainerRoot::getTypeDefinitions()
{
    return *m_typeDefinitions;
}

::ecorecpp::mapping::EList< ::kevoree::Repository >& ContainerRoot::getRepositories()
{
    return *m_repositories;
}

::ecorecpp::mapping::EList< ::kevoree::TypedElement >& ContainerRoot::getDataTypes()
{
    return *m_dataTypes;
}

::ecorecpp::mapping::EList< ::kevoree::TypeLibrary >& ContainerRoot::getLibraries()
{
    return *m_libraries;
}

::ecorecpp::mapping::EList< ::kevoree::Channel >& ContainerRoot::getHubs()
{
    return *m_hubs;
}

::ecorecpp::mapping::EList< ::kevoree::MBinding >& ContainerRoot::getMBindings()
{
    return *m_mBindings;
}

::ecorecpp::mapping::EList< ::kevoree::DeployUnit >& ContainerRoot::getDeployUnits()
{
    return *m_deployUnits;
}

::ecorecpp::mapping::EList< ::kevoree::NodeNetwork >& ContainerRoot::getNodeNetworks()
{
    return *m_nodeNetworks;
}

::ecorecpp::mapping::EList< ::kevoree::Group >& ContainerRoot::getGroups()
{
    return *m_groups;
}

::ecorecpp::mapping::EList< ::kevoree::AdaptationPrimitiveType >& ContainerRoot::getAdaptationPrimitiveTypes()
{
    return *m_adaptationPrimitiveTypes;
}

