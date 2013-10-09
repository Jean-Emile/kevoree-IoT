// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/Instance.hpp
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

#ifndef KEVOREE_INSTANCE_HPP
#define KEVOREE_INSTANCE_HPP

#include <kevoree_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>
#include <kevoree/NamedElement.hpp>

/*PROTECTED REGION ID(Instance_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace kevoree
{

    class Instance: public virtual ::kevoree::NamedElement
    {
    public:
        Instance();

        virtual ~Instance();

        virtual void _initialize();

        // Operations


        // Attributes
        ::ecore::EString const& getMetaData() const;
        void setMetaData(::ecore::EString const& _metaData);

        ::ecore::EBoolean isStarted() const;
        void setStarted(::ecore::EBoolean _started);

        // References
        ::kevoree::TypeDefinition_ptr getTypeDefinition();
        void setTypeDefinition(::kevoree::TypeDefinition_ptr _typeDefinition);

        ::kevoree::Dictionary_ptr getDictionary();
        void setDictionary(::kevoree::Dictionary_ptr _dictionary);

        /*PROTECTED REGION ID(Instance) START*/
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

        /*PROTECTED REGION ID(InstanceImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        ::ecore::EString m_metaData;

        ::ecore::EBoolean m_started;

        // References

        ::kevoree::TypeDefinition_ptr m_typeDefinition;

        ::kevoree::Dictionary_ptr m_dictionary;

    };

} // kevoree

#endif // KEVOREE_INSTANCE_HPP
