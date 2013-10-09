// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/NodeLink.hpp
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

#ifndef KEVOREE_NODELINK_HPP
#define KEVOREE_NODELINK_HPP

#include <kevoree_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>

#include <ecore/EObject.hpp>

/*PROTECTED REGION ID(NodeLink_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace kevoree
{

    class NodeLink: public virtual ::ecore::EObject

    {
    public:
        NodeLink();

        virtual ~NodeLink();

        virtual void _initialize();

        // Operations


        // Attributes
        ::ecore::EString const& getNetworkType() const;
        void setNetworkType(::ecore::EString const& _networkType);

        ::ecore::EIntegerObject getEstimatedRate() const;
        void setEstimatedRate(::ecore::EIntegerObject _estimatedRate);

        ::ecore::EString const& getLastCheck() const;
        void setLastCheck(::ecore::EString const& _lastCheck);

        ::ecore::EString const& getZoneID() const;
        void setZoneID(::ecore::EString const& _zoneID);

        // References
        ::ecorecpp::mapping::EList< ::kevoree::NetworkProperty >
                & getNetworkProperties();

        /*PROTECTED REGION ID(NodeLink) START*/
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

        /*PROTECTED REGION ID(NodeLinkImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        ::ecore::EString m_networkType;

        ::ecore::EIntegerObject m_estimatedRate;

        ::ecore::EString m_lastCheck;

        ::ecore::EString m_zoneID;

        // References

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::NetworkProperty > > m_networkProperties;

    };

} // kevoree

#endif // KEVOREE_NODELINK_HPP
