/************************************************************************
	filename: 	CEGUIPropertySet.h
	created:	21/2/2004
	author:		Paul D Turner
	
	purpose:	Defines interface for the PropertySet class
*************************************************************************/
/*************************************************************************
    Crazy Eddie's GUI System (http://crayzedsgui.sourceforge.net)
    Copyright (C)2004 Paul D Turner (crayzed@users.sourceforge.net)

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*************************************************************************/
#ifndef _CEGUIPropertySet_h_
#define _CEGUIPropertySet_h_

#include "CEGUIBase.h"
#include "CEGUIString.h"
#include <map>

// Start of CEGUI namespace section
namespace CEGUI
{
/*!
\brief
	Class that contains a collection of Property objects.
*/
class CEGUIBASE_API PropertySet
{
public:
	/*!
	\brief
		Constructs a new PropertySet object
	*/
	PropertySet(void) {}


	/*!
	\brief
		Destructor for PropertySet objects.
	*/
	virtual ~PropertySet(void) {}


	/*!
	\brief
		Adds a new Property to the PropertySet

	\param property
		Pointer to the Property object to be added to the PropertySet.

	\return
		Nothing.

	\exception NullObjectException		Thrown if \a property is NULL.
	\exception AlreadyExistsException	Thrown if a Property with the same name as \a property already exists in the PropertySet
	*/
	void	addProperty(Property* property);


	/*!
	\brief
		Removes a Property from the PropertySet.

	\param name
		String containing the name of the Property to be removed.  If Property \a name is not in the set, nothing happens.

	\return
		Nothing.
	*/
	void	removeProperty(const String& name);


	/*!
	\brief
		Removes all Property objects from the PropertySet.

	\return
		Nothing.
	*/
	void	clearProperties(void);


	/*!
	\brief
		Checks to see if a Property with the given name is in the PropertySet

	\param name
		String containing the name of the Property to check for.

	\return
		true if a Property named \a name is in the PropertySet.  false if no Property named \a name is in the PropertySet.
	*/
	bool	isPropertyPresent(const String& name) const;


	/*!
	\brief
		Return the help text for the specified Property.

	\param name
		String holding the name of the Property who's help text is to be returned.

	\return
		String object containing the help text for the Property \a name.

	\exception UnknownObjectException	Thrown if no Property named \a name is in the PropertySet.
	*/
	const String&	getPropertyHelp(const String& name) const;


	/*!
	\brief
		Gets the current value of the specified Property.

	\param name
		String containing the name of the Property who's value is to be returned.

	\return
		String object containing a textual representation of the requested Property.

	\exception UnknownObjectException	Thrown if no Property named \a name is in the PropertySet.
	*/
	String	getProperty(const String& name) const;


	/*!
	\brief
		Sets the current value of a Property.

	\param name
		String containing the name of the Property who's value is to be set.

	\param value
		String containing a textual representation of the new value for the Property

	\return
		Nothing

	\exception UnknownObjectException	Thrown if no Property named \a name is in the PropertySet.
	\exception InvalidRequestException	Thrown when the Property was unable to interpret the content of \a value.
	*/
	void	setProperty(const String& name, const String& value);

private:
	typedef std::map<String, Property*>	PropertyRegistry;
	PropertyRegistry	d_properties;
};

} // End of  CEGUI namespace section

#endif	// end of guard _CEGUIPropertySet_h_
