/************************************************************************
	filename: 	CEGUIWindowManager.h
	created:	21/2/2004
	author:		Paul D Turner
	
	purpose:	Defines the interface for the WindowManager object
*************************************************************************/
/*************************************************************************
    Crazy Eddie's GUI System (http://www.cegui.org.uk)
    Copyright (C)2004 - 2005 Paul D Turner (paul@cegui.org.uk)

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
#ifndef _CEGUIWindowManager_h_
#define _CEGUIWindowManager_h_

#include "CEGUIBase.h"
#include "CEGUIString.h"
#include "CEGUISingleton.h"
#include "CEGUILogger.h"
#include "CEGUIIteratorBase.h"
#include <map>

#if defined(_MSC_VER)
#	pragma warning(push)
#	pragma warning(disable : 4275)
#	pragma warning(disable : 4251)
#endif


// Start of CEGUI namespace section
namespace CEGUI
{
/*!
\brief
	The WindowManager class describes an object that manages creation and lifetime of Window objects.

	The WindowManager is the means by which Window objects are created and destroyed.  For each sub-class
	of Window that is to be created, there must exist a WindowFactory object which is registered with the
	WindowFactoryManager.  Additionally, the WindowManager tracks every Window object created, and can be
	used to access those Window objects by name.
*/
class CEGUIBASE_API WindowManager : public Singleton <WindowManager>
{
public:
	/*!
	\brief
		Function type that is used as a callback when loading layouts from XML; the function is called
		for each <Property> element encountered.

	\param window
		Window object that the property is to be applied to.

	\param propname
		String holding the name of the property that is being set.

	\param propvalue
		String holding the new value that will be applied to the property specified by /a propname.

	\param userdata
		Some client code supplied data.

	\return
		- true if the property should be set.
		- false if the property should not be set,
	*/
	typedef bool PropertyCallback(Window* window, String& propname, String& propvalue, void* userdata);
	
	/*************************************************************************
		Construction and Destruction
	*************************************************************************/
	/*!
	\brief
		Constructs a new WindowManager object.

		NB: Client code should not create WindowManager objects - they are of limited use to you!  The
		intended pattern of access is to get a pointer to the GUI system's WindowManager via the System
		object, and use that.
	*/
	WindowManager(void) { Logger::getSingleton().logEvent((utf8*)"CEGUI::WindowManager singleton created"); }


	/*!
	\brief
		Destructor for WindowManager objects

		This will properly destry all remaining Window objects.  Note that WindowFactory objects will not
		be destroyed (since they are owned by whoever created them).
	*/
	~WindowManager(void);


	/*!
	\brief
		Return singleton WindowManager object

	\return
		Singleton WindowManager object
	*/
	static	WindowManager&	getSingleton(void);


	/*!
	\brief
		Return pointer to singleton WindowManager object

	\return
		Pointer to singleton WindowManager object
	*/
	static	WindowManager*	getSingletonPtr(void);


	/*************************************************************************
		Window Related Methods
	*************************************************************************/
	/*!
	\brief
		Creates a new Window object of the specified type, and gives it the specified unique name.

	\param type
		String that describes the type of Window to be created.  A valid WindowFactory for the specified type must be registered.

	\param name
		String that holds a unique name that is to be given to the new window.

	\return
		Pointer to the newly created Window object.

	\exception	AlreadyExistsException		A Window object with the name \a name already exists.
	\exception	UnknownObjectException		No WindowFactory is registered for \a type Window objects.
	\exception	GenericException			Some other error occurred (Exception message has details).
	*/
	Window*	createWindow(const String& type, const String& name);


	/*!
	\brief
		Destroy the specified Window object.

	\param window
		Pointer to the Window object to be destroyed.  If the \a window is null, or is not recognised, nothing happens.

	\return
		Nothing

	\exception	InvalidRequestException		Can be thrown if the WindowFactory for \a window's object type was removed.
	*/
	void	destroyWindow(Window* window);


	/*!
	\brief
		Destroy the specified Window object.

	\param
		window	String containing the name of the Window object to be destroyed.  If \a window is not recognised, nothing happens.

	\return
		Nothing.

	\exception	InvalidRequestException		Can be thrown if the WindowFactory for \a window's object type was removed.
	*/
	void	destroyWindow(const String& window);


	/*!
	\brief
		Return a pointer to the specified Window object.

	\param name
		String holding the name of the Window object to be returned.

	\return
		Pointer to the Window object with the name \a name.

	\exception UnknownObjectException	No Window object with a name matching \a name was found.
	*/
	Window*	getWindow(const String& name) const;


	/*!
	\brief
		Examines the list of Window objects to see if one exists with the given name

	\param name
		String holding the name of the Window object to look for.

	\return
		true if a Window object was found with a name matching \a name.  false if no matching Window object was found.
	*/
	bool	isWindowPresent(const String& name) const;


	/*!
	\brief
		Destroys all Window objects within the system

	\return
		Nothing.

	\exception	InvalidRequestException		Thrown if the WindowFactory for any Window object type has been removed.
	*/
	void	destroyAllWindows(void);


	/*!
	\brief
		Creates a set of windows (a Gui layout) from the information in the specified XML file.	

	\param filename
		String object holding the filename of the XML file to be processed.

	\param name_prefix
		String object holding the prefix that is to be used when creating the windows in the layout file, this
		function allows a layout to be loaded multiple times without having name clashes.

	\param callback
		PropertyCallback function to be called for each <Property> element loaded from the layout.  This is
		called prior to the property value being applied to the window enabling client code manipulation of
		properties.

	\userdata
		Client code data pointer passed to the PropertyCallback function.

	\return
		Pointer to the root Window object defined in the layout.

	\exception FileIOException			thrown if something goes wrong while processing the file \a filename.
	\exception InvalidRequestException	thrown if \a filename appears to be invalid.
	*/
	Window*	loadWindowLayout(const String& filename, const String& name_prefix = (utf8*)"", PropertyCallback* callback = NULL, void* userdata = NULL);


private:
	/*************************************************************************
		Implementation Constants
	*************************************************************************/
	static const char	GUILayoutSchemaName[];			//!< Filename of the XML schema used for validating GUILayout files.


	/*************************************************************************
		Implementation Data
	*************************************************************************/
	typedef std::map<String, Window*>			WindowRegistry;				//!< Type used to implement registry of Window objects

	WindowRegistry			d_windowRegistry;			//!< The container that forms the Window registry


public:
	/*************************************************************************
		Iterator stuff
	*************************************************************************/
	typedef	ConstBaseIterator<WindowRegistry>	WindowIterator;

	/*!
	\brief
		Return a WindowManager::WindowIterator object to iterate over the currently defined Windows.
	*/
	WindowIterator	getIterator(void) const;
};

} // End of  CEGUI namespace section

#if defined(_MSC_VER)
#	pragma warning(pop)
#endif

#endif	// end of guard _CEGUIWindowManager_h_
