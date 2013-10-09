// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/DictionaryAttribute.hpp
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

#ifndef KEVOREE_DICTIONARYATTRIBUTE_HPP
#define KEVOREE_DICTIONARYATTRIBUTE_HPP

#include <kevoree_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>
#include <kevoree/TypedElement.hpp>

/*PROTECTED REGION ID(DictionaryAttribute_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace kevoree
{

    class DictionaryAttribute: public virtual ::kevoree::TypedElement
    {
    public:
        DictionaryAttribute();

        virtual ~DictionaryAttribute();

        virtual void _initialize();

        // Operations


        // Attributes
        ::ecore::EBoolean isOptional() const;
        void setOptional(::ecore::EBoolean _optional);

        ::ecore::EBoolean isState() const;
        void setState(::ecore::EBoolean _state);

        ::ecore::EString const& getDatatype() const;
        void setDatatype(::ecore::EString const& _datatype);

        ::ecore::EBoolean isFragmentDependant() const;
        void setFragmentDependant(::ecore::EBoolean _fragmentDependant);

        // References


        /*PROTECTED REGION ID(DictionaryAttribute) START*/
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

        /*PROTECTED REGION ID(DictionaryAttributeImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        ::ecore::EBoolean m_optional;

        ::ecore::EBoolean m_state;

        ::ecore::EString m_datatype;

        ::ecore::EBoolean m_fragmentDependant;

        // References

    };

} // kevoree

#endif // KEVOREE_DICTIONARYATTRIBUTE_HPP
