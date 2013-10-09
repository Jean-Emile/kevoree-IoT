// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/ContainerRoot.hpp
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

#ifndef KEVOREE_CONTAINERROOT_HPP
#define KEVOREE_CONTAINERROOT_HPP

#include <kevoree_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore/EObject.hpp>

/*PROTECTED REGION ID(ContainerRoot_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace kevoree
{

    class ContainerRoot: public virtual ::ecore::EObject

    {
    public:
        ContainerRoot();

        virtual ~ContainerRoot();

        virtual void _initialize();

        // Operations


        // Attributes

        // References
        ::ecorecpp::mapping::EList< ::kevoree::ContainerNode >& getNodes();

        ::ecorecpp::mapping::EList< ::kevoree::TypeDefinition >
                & getTypeDefinitions();

        ::ecorecpp::mapping::EList< ::kevoree::Repository >& getRepositories();

        ::ecorecpp::mapping::EList< ::kevoree::TypedElement >& getDataTypes();

        ::ecorecpp::mapping::EList< ::kevoree::TypeLibrary >& getLibraries();

        ::ecorecpp::mapping::EList< ::kevoree::Channel >& getHubs();

        ::ecorecpp::mapping::EList< ::kevoree::MBinding >& getMBindings();

        ::ecorecpp::mapping::EList< ::kevoree::DeployUnit >& getDeployUnits();

        ::ecorecpp::mapping::EList< ::kevoree::NodeNetwork >& getNodeNetworks();

        ::ecorecpp::mapping::EList< ::kevoree::Group >& getGroups();

        ::ecorecpp::mapping::EList< ::kevoree::AdaptationPrimitiveType >
                & getAdaptationPrimitiveTypes();

        /*PROTECTED REGION ID(ContainerRoot) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

        // EObjectImpl
        virtual ::ecore::EJavaObject eGet(::ecore::EInt _featureID,
                ::ecore::EBoolean _resolve);
        virtual void eSet(::ecore::EInt _featureID,
                ::ecore::EJavaObject const& _newValue);
        virtual ::ecore::EBoolean eIsSet(::ecore::EInt _featureID);
        virtual void eUnset(::ecore::EInt _featureID);
        virtual ::ecore::EClass_ptr _eClass();

        /*PROTECTED REGION ID(ContainerRootImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes


        // References

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::ContainerNode > > m_nodes;

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::TypeDefinition > > m_typeDefinitions;

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::Repository > > m_repositories;

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::TypedElement > > m_dataTypes;

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::TypeLibrary > > m_libraries;

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::Channel > > m_hubs;

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::MBinding > > m_mBindings;

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::DeployUnit > > m_deployUnits;

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::NodeNetwork > > m_nodeNetworks;

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::Group > > m_groups;

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::AdaptationPrimitiveType > >
                m_adaptationPrimitiveTypes;

    };

} // kevoree

#endif // KEVOREE_CONTAINERROOT_HPP
