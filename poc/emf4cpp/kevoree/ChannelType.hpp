// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/ChannelType.hpp
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

#ifndef KEVOREE_CHANNELTYPE_HPP
#define KEVOREE_CHANNELTYPE_HPP

#include <kevoree_forward.hpp>
#include <ecorecpp/mapping_forward.hpp>

#include <ecore_forward.hpp>
#include <kevoree/LifeCycleTypeDefinition.hpp>

/*PROTECTED REGION ID(ChannelType_pre) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

namespace kevoree
{

    class ChannelType: public virtual ::kevoree::LifeCycleTypeDefinition
    {
    public:
        ChannelType();

        virtual ~ChannelType();

        virtual void _initialize();

        // Operations


        // Attributes
        ::ecore::EIntegerObject getLowerBindings() const;
        void setLowerBindings(::ecore::EIntegerObject _lowerBindings);

        ::ecore::EIntegerObject getUpperBindings() const;
        void setUpperBindings(::ecore::EIntegerObject _upperBindings);

        ::ecore::EIntegerObject getLowerFragments() const;
        void setLowerFragments(::ecore::EIntegerObject _lowerFragments);

        ::ecore::EIntegerObject getUpperFragments() const;
        void setUpperFragments(::ecore::EIntegerObject _upperFragments);

        // References


        /*PROTECTED REGION ID(ChannelType) START*/
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

        /*PROTECTED REGION ID(ChannelTypeImpl) START*/
        // Please, enable the protected region if you add manually written code.
        // To do this, add the keyword ENABLED before START.
        /*PROTECTED REGION END*/

    protected:
        // Attributes

        ::ecore::EIntegerObject m_lowerBindings;

        ::ecore::EIntegerObject m_upperBindings;

        ::ecore::EIntegerObject m_lowerFragments;

        ::ecore::EIntegerObject m_upperFragments;

        // References

    };

} // kevoree

#endif // KEVOREE_CHANNELTYPE_HPP
