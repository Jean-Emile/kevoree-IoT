// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/AdaptationPrimitiveTypeRef.hpp
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

#ifndef KEVOREE_ADAPTATIONPRIMITIVETYPEREF_HPP
#define KEVOREE_ADAPTATIONPRIMITIVETYPEREF_HPP

#include <kevoree_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>

#include <ecore/EObject.hpp>

/*PROTECTED REGION ID(AdaptationPrimitiveTypeRef_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace kevoree
{

    class AdaptationPrimitiveTypeRef: public virtual ::ecore::EObject

    {
    public:
        AdaptationPrimitiveTypeRef();

        virtual ~AdaptationPrimitiveTypeRef();

        virtual void _initialize();

        // Operations


        // Attributes
        ::ecore::EString const& getMaxTime() const;
        void setMaxTime(::ecore::EString const& _maxTime);

        // References
        ::kevoree::AdaptationPrimitiveType_ptr getRef();
        void setRef(::kevoree::AdaptationPrimitiveType_ptr _ref);

        /*PROTECTED REGION ID(AdaptationPrimitiveTypeRef) START*/
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

        /*PROTECTED REGION ID(AdaptationPrimitiveTypeRefImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        ::ecore::EString m_maxTime;

        // References

        ::kevoree::AdaptationPrimitiveType_ptr m_ref;

    };

} // kevoree

#endif // KEVOREE_ADAPTATIONPRIMITIVETYPEREF_HPP
