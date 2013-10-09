// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kevoree/ChannelType.cpp
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

#include "ChannelType.hpp"
#include <kevoree/LifeCycleTypeDefinition.hpp>
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
ChannelType::ChannelType()
{

    /*PROTECTED REGION ID(ChannelTypeImpl__ChannelTypeImpl) START*/
    // Please, enable the protected region if you add manually written code.
    // To do this, add the keyword ENABLED before START.
    /*PROTECTED REGION END*/
}

ChannelType::~ChannelType()
{
}

/*PROTECTED REGION ID(ChannelType.cpp) START*/
// Please, enable the protected region if you add manually written code.
// To do this, add the keyword ENABLED before START.
/*PROTECTED REGION END*/

// Attributes

::ecore::EIntegerObject ChannelType::getLowerBindings() const
{
    return m_lowerBindings;
}

void ChannelType::setLowerBindings(::ecore::EIntegerObject _lowerBindings)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EIntegerObject _old_lowerBindings = m_lowerBindings;
#endif
    m_lowerBindings = _lowerBindings;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getChannelType__lowerBindings(),
                _old_lowerBindings,
                m_lowerBindings
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EIntegerObject ChannelType::getUpperBindings() const
{
    return m_upperBindings;
}

void ChannelType::setUpperBindings(::ecore::EIntegerObject _upperBindings)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EIntegerObject _old_upperBindings = m_upperBindings;
#endif
    m_upperBindings = _upperBindings;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getChannelType__upperBindings(),
                _old_upperBindings,
                m_upperBindings
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EIntegerObject ChannelType::getLowerFragments() const
{
    return m_lowerFragments;
}

void ChannelType::setLowerFragments(::ecore::EIntegerObject _lowerFragments)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EIntegerObject _old_lowerFragments = m_lowerFragments;
#endif
    m_lowerFragments = _lowerFragments;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getChannelType__lowerFragments(),
                _old_lowerFragments,
                m_lowerFragments
        );
        eNotify(&notification);
    }
#endif
}

::ecore::EIntegerObject ChannelType::getUpperFragments() const
{
    return m_upperFragments;
}

void ChannelType::setUpperFragments(::ecore::EIntegerObject _upperFragments)
{
#ifdef ECORECPP_NOTIFICATION_API
    ::ecore::EIntegerObject _old_upperFragments = m_upperFragments;
#endif
    m_upperFragments = _upperFragments;
#ifdef ECORECPP_NOTIFICATION_API
    if (eNotificationRequired())
    {
        ::ecorecpp::notify::Notification notification(
                ::ecorecpp::notify::Notification::SET,
                (::ecore::EObject_ptr) this,
                (::ecore::EStructuralFeature_ptr) ::kevoree::KevoreePackage::_instance()->getChannelType__upperFragments(),
                _old_upperFragments,
                m_upperFragments
        );
        eNotify(&notification);
    }
#endif
}

// References

