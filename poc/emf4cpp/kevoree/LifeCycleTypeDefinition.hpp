// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/LifeCycleTypeDefinition.hpp
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

#ifndef KEVOREE_LIFECYCLETYPEDEFINITION_HPP
#define KEVOREE_LIFECYCLETYPEDEFINITION_HPP

#include <kevoree_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>
#include <kevoree/TypeDefinition.hpp>

/*PROTECTED REGION ID(LifeCycleTypeDefinition_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace kevoree
{

    class LifeCycleTypeDefinition: public virtual ::kevoree::TypeDefinition
    {
    public:
        LifeCycleTypeDefinition();

        virtual ~LifeCycleTypeDefinition();

        virtual void _initialize();

        // Operations


        // Attributes
        ::ecore::EString const& getStartMethod() const;
        void setStartMethod(::ecore::EString const& _startMethod);

        ::ecore::EString const& getStopMethod() const;
        void setStopMethod(::ecore::EString const& _stopMethod);

        ::ecore::EString const& getUpdateMethod() const;
        void setUpdateMethod(::ecore::EString const& _updateMethod);

        // References


        /*PROTECTED REGION ID(LifeCycleTypeDefinition) START*/
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

        /*PROTECTED REGION ID(LifeCycleTypeDefinitionImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        ::ecore::EString m_startMethod;

        ::ecore::EString m_stopMethod;

        ::ecore::EString m_updateMethod;

        // References

    };

} // kevoree

#endif // KEVOREE_LIFECYCLETYPEDEFINITION_HPP
