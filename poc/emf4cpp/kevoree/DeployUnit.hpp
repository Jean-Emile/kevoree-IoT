// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/DeployUnit.hpp
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

#ifndef KEVOREE_DEPLOYUNIT_HPP
#define KEVOREE_DEPLOYUNIT_HPP

#include <kevoree_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>

#include <ecore/EObject.hpp>

/*PROTECTED REGION ID(DeployUnit_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace kevoree
{

    class DeployUnit: public virtual ::ecore::EObject

    {
    public:
        DeployUnit();

        virtual ~DeployUnit();

        virtual void _initialize();

        // Operations


        // Attributes
        ::ecore::EString const& getName() const;
        void setName(::ecore::EString const& _name);

        ::ecore::EString const& getGroupName() const;
        void setGroupName(::ecore::EString const& _groupName);

        ::ecore::EString const& getUnitName() const;
        void setUnitName(::ecore::EString const& _unitName);

        ::ecore::EString const& getVersion() const;
        void setVersion(::ecore::EString const& _version);

        ::ecore::EString const& getUrl() const;
        void setUrl(::ecore::EString const& _url);

        ::ecore::EString const& getHashcode() const;
        void setHashcode(::ecore::EString const& _hashcode);

        ::ecore::EString const& getType() const;
        void setType(::ecore::EString const& _type);

        // References
        ::ecorecpp::mapping::EList< ::kevoree::DeployUnit >& getRequiredLibs();

        ::kevoree::NodeType_ptr getTargetNodeType();
        void setTargetNodeType(::kevoree::NodeType_ptr _targetNodeType);

        /*PROTECTED REGION ID(DeployUnit) START*/
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

        /*PROTECTED REGION ID(DeployUnitImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        ::ecore::EString m_name;

        ::ecore::EString m_groupName;

        ::ecore::EString m_unitName;

        ::ecore::EString m_version;

        ::ecore::EString m_url;

        ::ecore::EString m_hashcode;

        ::ecore::EString m_type;

        // References

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::DeployUnit > > m_requiredLibs;

        ::kevoree::NodeType_ptr m_targetNodeType;

    };

} // kevoree

#endif // KEVOREE_DEPLOYUNIT_HPP
