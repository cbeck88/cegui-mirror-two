/***********************************************************************
    created:    Mon Jun 13 2005
    author:     Paul D Turner <paul@cegui.org.uk>
                edited by Lukas E Meindl in Jul 2014
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2010 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#ifndef _CEGUIFalWidgetLookFeel_h_
#define _CEGUIFalWidgetLookFeel_h_

#include "./StateImagery.h"
#include "./WidgetComponent.h"
#include "./ImagerySection.h"
#include "./PropertyInitialiser.h"
#include "./PropertyDefinition.h"
#include "./PropertyLinkDefinition.h"
#include "./EventLinkDefinition.h"
#include "./NamedArea.h"
#include "./NamedDefinitionCollator.h"
#include <map>

#if defined(_MSC_VER)
#   pragma warning(push)
#   pragma warning(disable : 4251)
#endif


namespace CEGUI
{
/*!
\brief
    Class that encapsulates Look N' Feel information for a widget.
*/
class CEGUIEXPORT WidgetLookFeel :
    public AllocatedObject<WidgetLookFeel>
{
public:
    WidgetLookFeel(const String& name, const String& inheritedLookName);
    WidgetLookFeel() {}
    WidgetLookFeel(const WidgetLookFeel& other);

    WidgetLookFeel& operator=(const WidgetLookFeel& other);

    virtual ~WidgetLookFeel();

    /*!
    \brief
        Return a const reference to the StateImagery object for the specified
        state.

    \param name
        String object holding the name of the StateImagery to be returned.

    \return
        StateImagery object for the requested state.

    \exception UnknownObjectException
        Thrown if a StateImagery with the given name could not be found.
    */
    const StateImagery& getStateImagery(const CEGUI::String& stateName, bool includeInheritedLook = false) const;

    /*!
    \brief
        Return a const reference to the ImagerySection object with the
        specified name.

    \param name
        String object holding the name of the ImagerySection to be returned.

    \return
        ImagerySection object with the specified name.

    \exception UnknownObjectException
        Thrown if a ImagerySection with the given name could not be found.
    */
    const ImagerySection& getImagerySection(const CEGUI::String& sectionName, bool includeInheritedLook = false) const;

    /*!
    \brief
        Return the NamedArea with the specified name.

    \param name
        String object holding the name of the NamedArea to be returned.

    \return
        The requested NamedArea object.

    \exception UnknownObjectException
        Thrown if a NamedArea with the given name could not be found.
    */
    const NamedArea& getNamedArea(const String& name, bool includeInheritedLook = false) const;

    /*!
    \brief
        Return the PropertyInitialiser with the specified name.

    \param name
        String object holding the name of the PropertyInitialiser to be returned.

    \return
        The requested PropertyInitialiser object.
 
    \exception UnknownObjectException
        Thrown if a PropertyInitialiser with the given name could not be found.
    */
    const PropertyInitialiser& getPropertyInitialiser(const String& name, bool includeInheritedLook = false) const;

    /*!
    \brief
        Return the PropertyDefinition with the specified name.

    \param name
        String object holding the name of the PropertyDefinition to be returned.

    \return
        The requested PropertyDefinitionBase object.

    \exception UnknownObjectException
        Thrown if a PropertyDefinition with the given name could not be found.
    */
    const PropertyDefinitionBase& getPropertyDefinition(const String& name, bool includeInheritedLook = false) const;

    /*!
    \brief
        Return the PropertyLinkDefinition with the specified name.

    \param name
        String object holding the name of the PropertyLinkDefinition to be returned.

    \return
        The requested PropertyDefinitionBase object.

    \exception UnknownObjectException
        Thrown if a PropertyLinkDefinition with the given name could not be found.
    */
    const PropertyDefinitionBase& getPropertyLinkDefinition(const String& name, bool includeInheritedLook = false) const;

    /*!
    \brief
        Return the WidgetComponent with the specified name.

    \param name
        String object holding the name of the WidgetComponent to be returned.

    \return
        The requested WidgetComponent object.

    \exception UnknownObjectException
        Thrown if a WidgetComponent with the given name could not be found.
    */
    const WidgetComponent& getWidgetComponent(const String& name, bool includeInheritedLook = false) const;

    /*!
    \brief
        Return the EventLinkDefinition with the specified name.

    \param name
        String object holding the name of the EventLinkDefinition to be returned.

    \return
        The requested EventLinkDefinition object.

    \exception UnknownObjectException
        Thrown if a EventLinkDefinition with the given name could not be found.
    */
    const EventLinkDefinition& getEventLinkDefinition(const String& name, bool includeInheritedLook = false) const;

    /*!
    \brief
        Return the name of the widget look.

    \return
        String object holding the name of the WidgetLookFeel.
    */
    const String& getName() const;

    /*!
    \brief
        Add an ImagerySection to the WidgetLookFeel.

    \param section
        ImagerySection object to be added.
    */
    void addImagerySection(const ImagerySection& section);

    //! \deprecated This function is to be replaced by a new renameImagerySection function in the new version, which considers inheritance and accepts more appropriate parameters.
    void renameImagerySection(const String& oldName, const String& newName);

    /*!
    \brief
        Add a WidgetComponent to the WidgetLookFeel.

    \param widget
        WidgetComponent object to be added.
    */
    void addWidgetComponent(const WidgetComponent& widget);

    /*!
    \brief
        Add a state specification (StateImagery object) to the WidgetLookFeel.

    \param section
        StateImagery object to be added.
    */
    void addStateImagery(const StateImagery& state);

    /*!
    \brief
        Add a property initialiser to the WidgetLookFeel.

    \param initialiser
        PropertyInitialiser object to be added.
    */
    void addPropertyInitialiser(const PropertyInitialiser& initialiser);

    /*!
    \brief
        Clear all ImagerySections from the WidgetLookFeel.
    */
    void clearImagerySections();

    /*!
    \brief
        Clear all WidgetComponents from the WidgetLookFeel.
    */
    void clearWidgetComponents();

    /*!
    \brief
        Clear all StateImagery objects from the WidgetLookFeel.
    */
    void clearStateSpecifications();

    /*!
    \brief
        Clear all PropertyInitialiser objects from the WidgetLookFeel.
    */
    void clearPropertyInitialisers();

    /*!
    \brief
        Clears the map of added PropertyDefinitions of this WidgetLookFeel and destroys the PropertyDefinitions.
    */
    void clearPropertyDefinitions();

    /*!
    \brief
        Clears the map of added PropertyLinkDefinitions of this WidgetLookFeel and destroys the PropertyLinkDefinitions.
    */
    void clearPropertyLinkDefinitions();

    /*!
    \brief
        Initialise the given window using PropertyInitialsers and component
        widgets specified for this WidgetLookFeel.

    \param widget
        Window based object to be initialised.

    \return
        Nothing.
    */
    void initialiseWidget(Window& widget) const;

    /*!
    \brief
        Clean up the given window from all properties and component widgets
        created by this WidgetLookFeel

    \param widget
        Window based object to be cleaned up.

    \return
        Nothing.
    */
    void cleanUpWidget(Window& widget) const;

    /*!
    \brief
        Return whether imagery is defined for the given state.

    \param state
        String object containing name of state to look for.

    \return
        - true if imagery exists for the specified state,
        - false if no imagery exists for the specified state.
    */
    bool isStateImageryPresent(const String& state) const;

    /*!
    \brief
        Adds a named area to the WidgetLookFeel.

    \param area
        NamedArea to be added.

    \return
        Nothing.
    */
    void addNamedArea(const NamedArea& area);

    /*!
    \brief
        Clear all defined named areas from the WidgetLookFeel

    \return
        Nothing.
    */
    void clearNamedAreas();

    //! \deprecated This function is to be replaced by a new renameNamedArea function in the new version, which considers inheritance and accepts more appropriate parameters.
    void renameNamedArea(const String& oldName, const String& newName);

    /*!
    \brief
        return whether a NamedArea object with the specified name exists for
        this WidgetLookFeel.

    \param name
        String holding the name of the NamedArea to check for.

    \return
        - true if a named area with the requested name is defined for this
          WidgetLookFeel.
        - false if no such named area is defined for this WidgetLookFeel.
    */
    bool isNamedAreaDefined(const String& name) const;

    /*!
    \brief
        Layout the child widgets defined for this WidgetLookFeel which are
        attached to the given window.

    \param owner
        Window object that has the child widgets that require laying out.

    \return
        Nothing.
    */
    void layoutChildWidgets(const Window& owner) const;

    /*!
    \brief
        Adds a PropertyDefinition to the WidgetLookFeel. The WidgetLookFeel takes over the ownership of the object.

    \param propdef
        PropertyDefinition object to be added.
    */
    void addPropertyDefinition(PropertyDefinitionBase* propertyDefiniton);

    /*!
    \brief
        Adds a PropertyLinkDefinition to the WidgetLookFeel. The WidgetLookFeel takes over the ownership of the object.

    \param propdef
        PropertyLinkDefinition object to be added.
    */
    void addPropertyLinkDefinition(PropertyDefinitionBase* propertyLinkDefiniton);

    /*!
    \brief
        Add the name of an animation that is associated with the
        WidgetLookFeel.

    \param anim_name
        Reference to a String object that contains the name of the animation
        to be associated with this WidgetLookFeel.
    */
    void addAnimationName(const String& anim_name);

    //! adds an event link definition to the WidgetLookFeel.
    void addEventLinkDefinition(const EventLinkDefinition& evtdef); 

    //! clear all defined event link definitions from the WidgetLookFeel.
    void clearEventLinkDefinitions();

    /*!
    \brief
        Writes an xml representation of this WidgetLookFeel to \a out_stream.

    \param xml_stream
        Stream where xml data should be output.

    \return
        Nothing.
    */
    void writeXMLToStream(XMLSerializer& xml_stream) const;

    /*!
    \brief
        Takes the name of a property and returns a pointer to the last
        PropertyInitialiser for this property or 0 if the is no
        PropertyInitialiser for this property in the WidgetLookFeel

    \param propertyName
        The name of the property to look for.
    */
    const PropertyInitialiser* findPropertyInitialiser(const String& propertyName) const;

    /*!
    \brief
        Takes the name for a WidgetComponent and returns a pointer to
        it if it exists or a null pointer if it doesn't.

    \param name
        The name of the Child component to look for.

    \deprecated
        This function will be replaced by getWidgetComponent in the next version.
    */
    const WidgetComponent* findWidgetComponent(const String& name) const;



    typedef std::set<String, StringFastLessCompare
        CEGUI_SET_ALLOC(String)> StringSet;

    /** Typedefs for maps of Falagard elements this WidgetLookFeel owns. */
    //! Map of Strings to StateImagery pointers
    typedef std::map<String, StateImagery*, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, StateImagery*)> StateImageryPointerMap;
    //! Map of Strings to ImagerySection pointers
    typedef std::map<String, ImagerySection*, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, ImagerySection*)> ImagerySectionPointerMap;
    //! Map of Strings to NamedArea pointers
    typedef std::map<String, NamedArea*, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, NamedArea*)> NamedAreaPointerMap;
    //! Map of Strings to WidgetComponent pointers
    typedef std::map<String, WidgetComponent*, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, WidgetComponent*)> WidgetComponentPointerMap;
    //! Map of Strings to AnimationInstance pointers
    typedef std::map<String, AnimationInstance*, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, AnimationInstance*)> AnimationInstancePointerMap;
    //! Map of Strings to EventLinkDefinition pointers
    typedef std::map<String, EventLinkDefinition*, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, EventLinkDefinition*)> EventLinkDefinitionPointerMap;

    /** Typedefs for maps of property related elements this WidgetLookFeel owns. */
    //! Map of Strings to PropertyInitialiser pointers
    typedef std::map<String, PropertyInitialiser*, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, PropertyInitialiser*)> PropertyInitialiserPointerMap;
    //! Map of Strings to PropertyDefinitionBase pointers
    typedef std::map<String, PropertyDefinitionBase*, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, PropertyDefinitionBase*)> PropertyDefinitionBasePointerMap;


    //! perform any processing required due to the given font having changed.
    bool handleFontRenderSizeChange(Window& window, const Font* font) const;



    /*!
    \brief
        Returns a map of names to pointers for all StateImagery elements this WidgetLookFeel owns.

    \param includeInheritedElements
        If set to true, this function will try to also include elements from the inherited WidgetLookFeel.

    \return
        A map of names to StateImagery pointers.
    */
    StateImageryPointerMap getStateImageryMap(bool includeInheritedElements = false);
    
    /*!
    \brief
        Returns a map of names to pointers for all ImagerySection elements this WidgetLookFeel owns.

    \param includeInheritedElements
        If set to true, this function will try to also include elements from the inherited WidgetLookFeel.

    \return
        A map of names to ImagerySection pointers.
    */
    ImagerySectionPointerMap getImagerySectionMap(bool includeInheritedElements = false);

    /*!
    \brief
        Returns a map of names to pointers for all NamedArea elements this WidgetLookFeel owns.

    \param includeInheritedElements
        If set to true, this function will try to also include elements from the inherited WidgetLookFeel.

    \return
        A map of names to NamedArea pointers.
    */
    NamedAreaPointerMap getNamedAreaMap(bool includeInheritedElements = false);

    /*!
    \brief
        Returns a map of names to pointers for all WidgetComponent elements this WidgetLookFeel owns.

    \param includeInheritedElements
        If set to true, this function will try to also include elements from the inherited WidgetLookFeel.

    \return
        A map of names to WidgetComponent pointers.
    */
    WidgetComponentPointerMap getWidgetComponentMap(bool includeInheritedElements = false);
  
    /*!
    \brief
        Returns a map of names to pointers for all PropertyInitialiser elements this WidgetLookFeel owns.

    \param includeInheritedElements
        If set to true, this function will try to also include elements from the inherited WidgetLookFeel.

    \return
        A map of names to PropertyInitialiser pointers.
    */
    PropertyInitialiserPointerMap getPropertyInitialiserMap(bool includeInheritedElements = false);

    /*!
    \brief
        Returns a map of names to pointers for all PropertyDefinition elements this WidgetLookFeel owns.

    \param includeInheritedElements
        If set to true, this function will try to also include elements from the inherited WidgetLookFeel.

    \return
        A map of names to PropertyDefinition pointers.
    */
    PropertyDefinitionBasePointerMap getPropertyDefinitionMap(bool includeInheritedElements = false);

    /*!
    \brief
        Returns a map of names to pointers for all PropertyLinkDefinition elements this WidgetLookFeel owns.

    \param includeInheritedElements
        If set to true, this function will try to also include elements from the inherited WidgetLookFeel.

    \return
        A map of names to PropertyLinkDefinition pointers.
    */
    PropertyDefinitionBasePointerMap getPropertyLinkDefinitionMap(bool includeInheritedElements = false);

    /*!
    \brief
        Returns a map of names to pointers for all EventLinkDefinition elements this WidgetLookFeel owns.

    \param includeInheritedElements
        If set to true, this function will try to also include elements from the inherited WidgetLookFeel.

    \return
        A map of names to EventLinkDefinition pointers.
    */
    EventLinkDefinitionPointerMap getEventLinkDefinitionMap(bool includeInheritedElements = false);

    /*!
    \brief
        Returns a String containing the name of the inherited WidgetLookFeel.

    \return
        A String containing the name of the inherited WidgetLookFeel.
    */
    const CEGUI::String& getInheritedWidgetLookName() const;

    /*!
    \brief
        Returns a String-Set of StateImagery names.

    \param includeInheritedLook
        If true, this will also add the names from the inherited WidgetLook.

    \return
        A StringSet containing the StateImagery names.
    */
    StringSet getStateImageryNames(bool includeInheritedLook = false) const;

    /*!
    \brief
        Returns a String-Set of ImagerySection names.

    \param includeInheritedLook
        If true, this will also add the names from the inherited WidgetLook.

    \return
        A StringSet containing the ImagerySection names.
    */
    StringSet getImagerySectionNames(bool includeInheritedLook = false) const;

    /*!
    \brief
        Returns a String-Set of NamedArea names.

    \param includeInheritedLook
        If true, this will also add the names from the inherited WidgetLook.

    \return
        A StringSet containing the NamedArea names.
    */
    StringSet getNamedAreaNames(bool includeInheritedLook = false) const;

    /*!
    \brief
        Returns a String-Set of WidgetComponent (Child Widget) names.

    \param includeInheritedLook
        If true, this will also add the names from the inherited WidgetLook.

    \return
        A StringSet containing the WidgetComponent (Child Widget) names.
    */
    StringSet getWidgetComponentNames(bool includeInheritedLook = false) const;

    /*!
    \brief
        Returns a String-Set of PropertyInitialiser (Property) names.

    \param includeInheritedLook
        If true, this will also add the names from the inherited WidgetLook.

    \return
        A StringSet containing the PropertyInitialiser (Property) names.
    */
    StringSet getPropertyInitialiserNames(bool includeInheritedLook = false) const;

    /*!
    \brief
        Returns a String-Set of PropertyDefinition names.

    \param includeInheritedLook
        If true, this will also add the names from the inherited WidgetLook.

    \return
        A StringSet containing the PropertyDefinition names.
    */
    StringSet getPropertyDefinitionNames(bool includeInheritedLook = false) const;

    /*!
    \brief
        Returns a String-Set of PropertyLinkDefinition names.

    \param includeInheritedLook
        If true, this will also add the names from the inherited WidgetLook.

    \return
        A StringSet containing the PropertyLinkDefinition names.
    */
    StringSet getPropertyLinkDefinitionNames(bool includeInheritedLook = false) const;

    /*!
    \brief
        Returns a String-Set of EventLinkDefinition names.

    \param includeInheritedLook
        If true, this will also add the names from the inherited WidgetLook.

    \return
        A StringSet containing the EventLinkDefinition names.
    */
    StringSet getEventLinkDefinitionNames(bool includeInheritedLook = false) const;

    /*!
    \brief
        Returns a String-Set of Animation names.

    \param includeInheritedLook
        If true, this will also add the names from the inherited WidgetLook.

    \return
        A StringSet containing the Animation names.
    */
    StringSet getAnimationNames(bool includeInheritedLook = false) const;

private:

    /*!
    \brief
        Returns a pointer to the inherited WidgetLookFeel. If this WidgetLookFeel does not inherit from another, the function returns 0.

    \return
        A pointer to the inherited WidgetLookFeel.
    */
    WidgetLookFeel* getInheritedWidgetLookFeel();

    /*!
    \brief
        Copies the PropertyDefinitions from another WidgetLookFeel.

    \param widgetLook
        WidgetLookFeel object to copy the PropertyDefinitions from.
    */
    void copyPropertyDefinitionsFrom(const WidgetLookFeel& widgetLook);

    /*!
    \brief
        Copies the PropertyLinkDefinitions from another WidgetLookFeel.

    \param widgetLook
        WidgetLookFeel object to copy the PropertyLinkDefinitions from.
    */
    void copyPropertyLinkDefinitionsFrom(const WidgetLookFeel& widgetLook);


    //! Map types for the Falagard elements that this WidgetLookFeel can own. The keys are the names of the corresponding elements, as CEGUI::String.
    typedef std::map<String, StateImagery, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, StateImagery)> StateImageryMap;
    typedef std::map<String, ImagerySection, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, ImagerySection)> ImagerySectionMap;
    typedef std::map<String, NamedArea, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, NamedArea)> NamedAreaMap;

    typedef std::map<String, PropertyInitialiser, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, PropertyInitialiser)> PropertyInitialiserMap;
    typedef std::map<String, PropertyDefinitionBase*, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, PropertyDefinitionBase*)> PropertyDefinitionMap;
    typedef std::map<String, PropertyDefinitionBase*, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, PropertyDefinitionBase*)> PropertyLinkDefinitionMap;

    typedef std::map<String, WidgetComponent, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, WidgetComponent)> WidgetComponentMap;
    typedef std::map<String, EventLinkDefinition, StringFastLessCompare
        CEGUI_MAP_ALLOC(String, EventLinkDefinition)> EventLinkDefinitionMap;

    //! List of animation names
    typedef std::vector<String
        CEGUI_VECTOR_ALLOC(String)> AnimationList;
    //! Map of Windows to AnimationInstances
    typedef std::multimap<Window*, AnimationInstance*
        CEGUI_MULTIMAP_ALLOC(Window*, AnimationInstance*)> AnimationInstanceMap;

    //! Name of this WidgetLookFeel.
    CEGUI::String d_lookName;
    //! Name of a WidgetLookFeel inherited by this WidgetLookFeel.
    CEGUI::String d_inheritedLookName;
    //! Map of ImagerySection objects.
    ImagerySectionMap d_imagerySectionMap;
    //! Map of WidgetComponent objects.
    WidgetComponentMap d_widgetComponentMap;
    //! Map of StateImagery objects.
    StateImageryMap d_stateImageryMap;
    //! Map of PropertyInitialser objects.
    PropertyInitialiserMap d_propertyInitialiserMap;
    //! Map of NamedArea objects.
    NamedAreaMap d_namedAreaMap;
    //! Map of PropertyDefinition objects.
    mutable PropertyDefinitionMap d_propertyDefinitionMap;
    //! Map of PropertyLinkDefinition objects.
    mutable PropertyLinkDefinitionMap d_propertyLinkDefinitionMap;
    //! List of animation names associated with this WidgetLookFeel.
    AnimationList d_animations;
    //! Map of windows and their associated animation instances
    mutable AnimationInstanceMap d_animationInstances;
    //! Collection of EventLinkDefinition objects.
    EventLinkDefinitionMap d_eventLinkDefinitionMap;

    // these are container types used when composing final collections of
    // objects that come via inheritence.
    typedef NamedDefinitionCollator<String, const WidgetComponent*> WidgetComponentCollator;
    typedef NamedDefinitionCollator<String, PropertyDefinitionBase*> PropertyDefinitionCollator;
    typedef NamedDefinitionCollator<String, PropertyDefinitionBase*> PropertyLinkDefinitionCollator;
    typedef NamedDefinitionCollator<String, const PropertyInitialiser*> PropertyInitialiserCollator;
    typedef NamedDefinitionCollator<String, const EventLinkDefinition*> EventLinkDefinitionCollator;
    typedef std::set<String, StringFastLessCompare
        CEGUI_SET_ALLOC(String)> AnimationNameSet;

    // functions to populate containers with collections of objects that we
    // gain through inheritence.
    void appendChildWidgetComponents(WidgetComponentCollator& col, bool inherits = true) const;
    void appendPropertyDefinitions(PropertyDefinitionCollator& col, bool inherits = true) const;
    void appendPropertyLinkDefinitions(PropertyLinkDefinitionCollator& col, bool inherits = true) const;
    void appendPropertyInitialisers(PropertyInitialiserCollator& col, bool inherits = true) const;
    void appendEventLinkDefinitions(EventLinkDefinitionCollator& col, bool inherits = true) const;
    void appendAnimationNames(AnimationNameSet& set, bool inherits = true) const;

    void swap(WidgetLookFeel& other);
};

}


#if defined(_MSC_VER)
#   pragma warning(pop)
#endif

#endif

