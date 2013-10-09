// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/PortTypeRef.hpp
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

#ifndef KEVOREE_PORTTYPEREF_HPP
#define KEVOREE_PORTTYPEREF_HPP

#include <kevoree_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>
#include <kevoree/NamedElement.hpp>

/*PROTECTED REGION ID(PortTypeRef_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace kevoree
{

    class PortTypeRef: public virtual ::kevoree::NamedElement
    {
    public:
        PortTypeRef();

        virtual ~PortTypeRef();

        virtual void _initialize();

        // Operations


        // Attributes
        ::ecore::EBooleanObject getOptional() const;
        void setOptional(::ecore::EBooleanObject _optional);

        ::ecore::EBooleanObject getNoDependency() const;
        void setNoDependency(::ecore::EBooleanObject _noDependency);

        // References
        ::kevoree::PortType_ptr getRef();
        void setRef(::kevoree::PortType_ptr _ref);

        ::ecorecpp::mapping::EList< ::kevoree::PortTypeMapping >& getMappings();

        /*PROTECTED REGION ID(PortTypeRef) START*/
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

        /*PROTECTED REGION ID(PortTypeRefImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        ::ecore::EBooleanObject m_optional;

        ::ecore::EBooleanObject m_noDependency;

        // References

        ::kevoree::PortType_ptr m_ref;

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::PortTypeMapping > > m_mappings;

    };

} // kevoree

#endif // KEVOREE_PORTTYPEREF_HPP
