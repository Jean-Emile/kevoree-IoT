// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/TypeDefinition.cpp
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

#include "TypeDefinition.hpp"
#include <kevoree/NamedElement.hpp>
#include <kevoree/DeployUnit.hpp>
#include <kevoree/DictionaryType.hpp>
#include <kevoree/TypeDefinition.hpp>
#include <ecore/EObject.hpp>
#include <ecore/EClass.hpp>
#include "kevoree/KevoreePackage.hpp"
#include <ecorecpp/mapping.hpp>

#ifdef ECORECPP_NOTIFICATION_API
#include <ecorecpp/notify.hpp>
#endif

using namespace ::kevoree;

// Default constructor
TypeDefinition::TypeDefinition() :
    m_dictionaryType(0)
{

    m_deployUnits.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::DeployUnit, -1, false, false >(this, NULL));
    m_superTypes.reset(new ::ecorecpp::mapping::ReferenceEListImpl<
            ::kevoree::TypeDefinition, -1, false, false >(this, NULL));

    /*PROTECTED REGION ID(TypeDefinitionImpl__TypeDefinitionImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

TypeDefinition::~TypeDefinition()
{
    if (m_dictionaryType)
    {
        delete m_dictionaryType;
    }
}

/*PROTECTED REGION ID(TypeDefinition.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EString const& TypeDefinition::getFactoryBean() const
{
    return m_factoryBean;
}

void TypeDefinition::setFactoryBean(::ecore::EString const& _factoryBean)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_factoryBean = m_factoryBean;
#endif
    m_factoryBean = _factoryBean;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getTypeDefinition__factoryBean(),
                _old_factoryBean,
                m_factoryBean
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EString const& TypeDefinition::getBean() const
{
    return m_bean;
}

void TypeDefinition::setBean(::ecore::EString const& _bean)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EString _old_bean = m_bean;
#endif
    m_bean = _bean;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getTypeDefinition__bean(),
                _old_bean,
                m_bean
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EBoolean TypeDefinition::isAbstract() const
{
    return m_abstract;
}

void TypeDefinition::setAbstract(::ecore::EBoolean _abstract)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EBoolean _old_abstract = m_abstract;
#endif
    m_abstract = _abstract;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getTypeDefinition__abstract(),
                _old_abstract,
                m_abstract
        );
        eNotify(&notification);
    }
#endif
}

// References
::ecorecpp::mapping::EList< ::kevoree::DeployUnit >& TypeDefinition::getDeployUnits()
{
    return *m_deployUnits;
}

::kevoree::DictionaryType_ptr TypeDefinition::getDictionaryType()
{
    return m_dictionaryType;
}

void TypeDefinition::setDictionaryType(
        ::kevoree::DictionaryType_ptr _dictionaryType)
{
    ::kevoree::DictionaryType_ptr _old_dictionaryType = m_dictionaryType;

    m_dictionaryType = _dictionaryType;

#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getTypeDefinition__dictionaryType(),
                _old_dictionaryType,
                m_dictionaryType
        );
        eNotify(&notification);
    }
#endif

    delete _old_dictionaryType;
}

::ecorecpp::mapping::EList< ::kevoree::TypeDefinition >& TypeDefinition::getSuperTypes()
{
    return *m_superTypes;
}

