// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree.hpp
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

#ifndef KEVOREE_HPP
#define KEVOREE_HPP

#include "kevoree_forward.hpp"
#include <ecorecpp/mapping.hpp>

// EPackage


// EClass
#include "kevoree/ComponentInstance.hpp"
#include "kevoree/ComponentType.hpp"
#include "kevoree/ContainerNode.hpp"
#include "kevoree/ContainerRoot.hpp"
#include "kevoree/PortType.hpp"
#include "kevoree/Port.hpp"
#include "kevoree/Namespace.hpp"
#include "kevoree/Dictionary.hpp"
#include "kevoree/DictionaryType.hpp"
#include "kevoree/DictionaryAttribute.hpp"
#include "kevoree/DictionaryValue.hpp"
#include "kevoree/CompositeType.hpp"
#include "kevoree/PortTypeRef.hpp"
#include "kevoree/Wire.hpp"
#include "kevoree/ServicePortType.hpp"
#include "kevoree/Operation.hpp"
#include "kevoree/Parameter.hpp"
#include "kevoree/TypedElement.hpp"
#include "kevoree/MessagePortType.hpp"
#include "kevoree/Repository.hpp"
#include "kevoree/DeployUnit.hpp"
#include "kevoree/TypeLibrary.hpp"
#include "kevoree/NamedElement.hpp"
#include "kevoree/IntegrationPattern.hpp"
#include "kevoree/ExtraFonctionalProperty.hpp"
#include "kevoree/PortTypeMapping.hpp"
#include "kevoree/Channel.hpp"
#include "kevoree/MBinding.hpp"
#include "kevoree/NodeNetwork.hpp"
#include "kevoree/NodeLink.hpp"
#include "kevoree/NetworkProperty.hpp"
#include "kevoree/ChannelType.hpp"
#include "kevoree/TypeDefinition.hpp"
#include "kevoree/Instance.hpp"
#include "kevoree/LifeCycleTypeDefinition.hpp"
#include "kevoree/Group.hpp"
#include "kevoree/GroupType.hpp"
#include "kevoree/NodeType.hpp"
#include "kevoree/AdaptationPrimitiveType.hpp"
#include "kevoree/AdaptationPrimitiveTypeRef.hpp"

// Package & Factory
#include "kevoree/KevoreePackage.hpp"
#include "kevoree/KevoreeFactory.hpp"

#endif // KEVOREE_HPP
