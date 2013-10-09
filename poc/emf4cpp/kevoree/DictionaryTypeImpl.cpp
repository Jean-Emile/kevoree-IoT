// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/DictionaryTypeImpl.cpp
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
#include <kevoree/KevoreePackage.hpp>
#include <kevoree/DictionaryAttribute.hpp>
#include <kevoree/DictionaryValue.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include <ecore/EStructuralFeature.hpp>
#include <ecore/EReference.hpp>
#include <ecore/EObject.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kevoree;

/*PROTECTED REGION ID(DictionaryTypeImpl.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

void DictionaryType::_initialize()
{
    // Supertypes

    // Rerefences
    for (size_t i = 0; i < m_attributes->size(); i++)
    {
        (*m_attributes)[i]->_initialize();
        (*m_attributes)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getDictionaryType__attributes());
    }
    for (size_t i = 0; i < m_defaultValues->size(); i++)
    {
        (*m_defaultValues)[i]->_initialize();
        (*m_defaultValues)[i]->_setEContainer(
                this,
                ::kevoree::KevoreePackage::_instance()->getDictionaryType__defaultValues());
    }

    /*PROTECTED REGION ID(DictionaryTypeImpl__initialize) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

// Operations


// EObject
::ecore::EJavaObject DictionaryType::eGet(::ecore::EInt _featureID,
        ::ecore::EBoolean _resolve)
{
    ::ecore::EJavaObject _any;
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::DICTIONARYTYPE__ATTRIBUTES:
    {
        _any = m_attributes->asEListOf< ::ecore::EObject > ();
    }
        return _any;
    case ::kevoree::KevoreePackage::DICTIONARYTYPE__DEFAULTVALUES:
    {
        _any = m_defaultValues->asEListOf< ::ecore::EObject > ();
    }
        return _any;

    }
    throw "Error";
}

void DictionaryType::eSet(::ecore::EInt _featureID,
        ::ecore::EJavaObject const& _newValue)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::DICTIONARYTYPE__ATTRIBUTES:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::DictionaryType::getAttributes().clear();
        ::kevoree::DictionaryType::getAttributes().insert_all(*_t0);
    }
        return;
    case ::kevoree::KevoreePackage::DICTIONARYTYPE__DEFAULTVALUES:
    {
        ::ecorecpp::mapping::EList_ptr _t0 =
                ::ecorecpp::mapping::any::any_cast<
                        ::ecorecpp::mapping::EList_ptr >(_newValue);
        ::kevoree::DictionaryType::getDefaultValues().clear();
        ::kevoree::DictionaryType::getDefaultValues().insert_all(*_t0);
    }
        return;

    }
    throw "Error";
}

::ecore::EBoolean DictionaryType::eIsSet(::ecore::EInt _featureID)
{
    switch (_featureID)
    {
    case ::kevoree::KevoreePackage::DICTIONARYTYPE__ATTRIBUTES:
        return m_attributes && m_attributes->size();
    case ::kevoree::KevoreePackage::DICTIONARYTYPE__DEFAULTVALUES:
        return m_defaultValues && m_defaultValues->size();

    }
    throw "Error";
}

void DictionaryType::eUnset(::ecore::EInt _featureID)
{
    switch (_featureID)
    {

    }
    throw "Error";
}

::ecore::EClass_ptr DictionaryType::_eClass()
{
    static ::ecore::EClass_ptr
            _eclass =
                    dynamic_cast< ::kevoree::KevoreePackage_ptr > (::kevoree::KevoreePackage::_instance())->getDictionaryType();
    return _eclass;
}

