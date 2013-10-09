// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/NodeNetwork.hpp
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

#ifndef KEVOREE_NODENETWORK_HPP
#define KEVOREE_NODENETWORK_HPP

#include <kevoree_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore/EObject.hpp>

/*PROTECTED REGION ID(NodeNetwork_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace kevoree
{

    class NodeNetwork: public virtual ::ecore::EObject

    {
    public:
        NodeNetwork();

        virtual ~NodeNetwork();

        virtual void _initialize();

        // Operations


        // Attributes

        // References
        ::ecorecpp::mapping::EList< ::kevoree::NodeLink >& getLink();

        ::kevoree::ContainerNode_ptr getInitBy();
        void setInitBy(::kevoree::ContainerNode_ptr _initBy);

        ::kevoree::ContainerNode_ptr getTarget();
        void setTarget(::kevoree::ContainerNode_ptr _target);

        /*PROTECTED REGION ID(NodeNetwork) START*/
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

        /*PROTECTED REGION ID(NodeNetworkImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes


        // References

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::NodeLink > > m_link;

        ::kevoree::ContainerNode_ptr m_initBy;

        ::kevoree::ContainerNode_ptr m_target;

    };

} // kevoree

#endif // KEVOREE_NODENETWORK_HPP
