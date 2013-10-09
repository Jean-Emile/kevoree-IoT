// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/PortTypeMapping.hpp
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

#ifndef KEVOREE_PORTTYPEMAPPING_HPP
#define KEVOREE_PORTTYPEMAPPING_HPP

#include <kevoree_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>

#include <ecore/EObject.hpp>

/*PROTECTED REGION ID(PortTypeMapping_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace kevoree
{

    class PortTypeMapping: public virtual ::ecore::EObject

    {
    public:
        PortTypeMapping();

        virtual ~PortTypeMapping();

        virtual void _initialize();

        // Operations


        // Attributes
        ::ecore::EString const& getBeanMethodName() const;
        void setBeanMethodName(::ecore::EString const& _beanMethodName);

        ::ecore::EString const& getServiceMethodName() const;
        void setServiceMethodName(::ecore::EString const& _serviceMethodName);

        ::ecore::EString const& getParamTypes() const;
        void setParamTypes(::ecore::EString const& _paramTypes);

        // References


        /*PROTECTED REGION ID(PortTypeMapping) START*/
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

        /*PROTECTED REGION ID(PortTypeMappingImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        ::ecore::EString m_beanMethodName;

        ::ecore::EString m_serviceMethodName;

        ::ecore::EString m_paramTypes;

        // References

    };

} // kevoree

#endif // KEVOREE_PORTTYPEMAPPING_HPP
