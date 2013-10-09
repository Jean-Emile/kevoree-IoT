// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/DictionaryType.cpp
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

#include "DictionaryType.hpp"
#include <kevoree/DictionaryAttribute.hpp>
#include <kevoree/DictionaryValue.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
DictionaryType::DictionaryType()
{

    m_attributes.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::DictionaryAttribute, -1, true, false >(this, NULL));
    m_defaultValues.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::DictionaryValue, -1, true, false >(this, NULL));

    /*PROTECTED REGION ID(DictionaryTypeImpl__DictionaryTypeImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

DictionaryType::~DictionaryType()
{
}

/*PROTECTED REGION ID(DictionaryType.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

// References
::ecorecpp::mapping::EList< ::kevoree::DictionaryAttribute >& DictionaryType::getAttributes()
{
    return *m_attributes;
}

::ecorecpp::mapping::EList< ::kevoree::DictionaryValue >& DictionaryType::getDefaultValues()
{
    return *m_defaultValues;
}

