// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/ComponentInstance.hpp
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

#ifndef KEVOREE_COMPONENTINSTANCE_HPP
#define KEVOREE_COMPONENTINSTANCE_HPP

#include <kevoree_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>
#include <kevoree/NamedElement.hpp>
#include <kevoree/Instance.hpp>

/*PROTECTED REGION ID(ComponentInstance_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace kevoree
{

    class ComponentInstance: public virtual ::kevoree::NamedElement,
            public virtual ::kevoree::Instance
    {
    public:
        ComponentInstance();

        virtual ~ComponentInstance();

        virtual void _initialize();

        // Operations


        // Attributes

        // References
        ::ecorecpp::mapping::EList< ::kevoree::Port >& getProvided();

        ::ecorecpp::mapping::EList< ::kevoree::Port >& getRequired();

        ::kevoree::Namespace_ptr getNamespace();
        void setNamespace(::kevoree::Namespace_ptr _namespace);

        /*PROTECTED REGION ID(ComponentInstance) START*/
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

        /*PROTECTED REGION ID(ComponentInstanceImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes


        // References

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::Port > > m_provided;

        ::ecorecpp::mapping::out_ptr< ::ecorecpp::mapping::EList<
                ::kevoree::Port > > m_required;

        ::kevoree::Namespace_ptr m_namespace;

    };

} // kevoree

#endif // KEVOREE_COMPONENTINSTANCE_HPP
