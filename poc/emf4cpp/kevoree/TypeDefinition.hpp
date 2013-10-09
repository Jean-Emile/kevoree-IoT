// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/TypeDefinition.hpp
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

#ifndef KEVOREE_TYPEDEFINITION_HPP
#define KEVOREE_TYPEDEFINITION_HPP

#include <kevoree_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>
#include <kevoree/NamedElement.hpp>

/*PROTECTED REGION ID(TypeDefinition_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace kevoree
{

    class TypeDefinition: public virtual ::kevoree::NamedElement
    {
    public:
        TypeDefinition();

        virtual ~TypeDefinition();

        virtual void _initialize();

        // Operations


        // Attributes
        ::ecore::EString const& getFactoryBean() const;
        void setFactoryBean(::ecore::EString const& _factoryBean);

        ::ecore::EString const& getBean() const;
        void setBean(::ecore::EString const& _bean);

        ::ecore::EBoolean isAbstract() const;
        void setAbstract(::ecore::EBoolean _abstract);

        // References
        ::ecorecpp::mapping::EList< ::kevoree::DeployUnit >& getDeployUnits();

        ::kevoree::DictionaryType_ptr getDictionaryType();
        void setDictionaryType(::kevoree::DictionaryType_ptr _dictionaryType);

        ::ecorecpp::mapping::EList< ::kevoree::TypeDefinition >
                & getSuperTypes();

        /*PROTECTED REGION ID(TypeDefinition) START*/
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

        /*PROTECTED REGION ID(TypeDefinitionImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        ::ecore::EString m_factoryBean;

        ::ecore::EString m_bean;

        ::ecore::EBoolean m_abstract;

        // References

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::DeployUnit > > m_deployUnits;

        ::kevoree::DictionaryType_ptr m_dictionaryType;

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::TypeDefinition > > m_superTypes;

    };

} // kevoree

#endif // KEVOREE_TYPEDEFINITION_HPP
