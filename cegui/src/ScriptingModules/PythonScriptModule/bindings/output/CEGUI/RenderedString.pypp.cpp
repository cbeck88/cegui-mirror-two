// This file has been generated by Py++.

#include "boost/python.hpp"
#include "python_CEGUI.h"
#include "RenderedString.pypp.hpp"

namespace bp = boost::python;

void register_RenderedString_class(){

    { //::CEGUI::RenderedString
        typedef bp::class_< CEGUI::RenderedString > RenderedString_exposer_t;
        RenderedString_exposer_t RenderedString_exposer = RenderedString_exposer_t( "RenderedString", bp::init< >("! Constructor.\n") );
        bp::scope RenderedString_scope( RenderedString_exposer );
        RenderedString_exposer.def( bp::init< CEGUI::RenderedString const & >(( bp::arg("other") ), "! Copy constructor.\n") );
        { //::CEGUI::RenderedString::appendComponent
        
            typedef void ( ::CEGUI::RenderedString::*appendComponent_function_type )( ::CEGUI::RenderedStringComponent const & ) ;
            
            RenderedString_exposer.def( 
                "appendComponent"
                , appendComponent_function_type( &::CEGUI::RenderedString::appendComponent )
                , ( bp::arg("component") )
                , "! append  component to the list of components drawn for this string.\n" );
        
        }
        { //::CEGUI::RenderedString::appendLineBreak
        
            typedef void ( ::CEGUI::RenderedString::*appendLineBreak_function_type )(  ) ;
            
            RenderedString_exposer.def( 
                "appendLineBreak"
                , appendLineBreak_function_type( &::CEGUI::RenderedString::appendLineBreak )
                , "! linebreak the rendered string at the present position.\n" );
        
        }
        { //::CEGUI::RenderedString::clearComponents
        
            typedef void ( ::CEGUI::RenderedString::*clearComponents_function_type )(  ) ;
            
            RenderedString_exposer.def( 
                "clearComponents"
                , clearComponents_function_type( &::CEGUI::RenderedString::clearComponents )
                , "! clear the list of components drawn for this string.\n" );
        
        }
        { //::CEGUI::RenderedString::draw
        
            typedef void ( ::CEGUI::RenderedString::*draw_function_type )( ::size_t const,::CEGUI::GeometryBuffer &,::CEGUI::Vector2< float > const &,::CEGUI::ColourRect const *,::CEGUI::Rect< float > const *,float const ) const;
            
            RenderedString_exposer.def( 
                "draw"
                , draw_function_type( &::CEGUI::RenderedString::draw )
                , ( bp::arg("line"), bp::arg("buffer"), bp::arg("position"), bp::arg("mod_colours"), bp::arg("clip_rect"), bp::arg("space_extra") ) );
        
        }
        { //::CEGUI::RenderedString::getComponentCount
        
            typedef ::size_t ( ::CEGUI::RenderedString::*getComponentCount_function_type )(  ) const;
            
            RenderedString_exposer.def( 
                "getComponentCount"
                , getComponentCount_function_type( &::CEGUI::RenderedString::getComponentCount )
                , "! return the number of components that make up this string.\n" );
        
        }
        { //::CEGUI::RenderedString::getLineCount
        
            typedef ::size_t ( ::CEGUI::RenderedString::*getLineCount_function_type )(  ) const;
            
            RenderedString_exposer.def( 
                "getLineCount"
                , getLineCount_function_type( &::CEGUI::RenderedString::getLineCount )
                , "! return number of lines in this string.\n" );
        
        }
        { //::CEGUI::RenderedString::getPixelSize
        
            typedef ::CEGUI::Size< float > ( ::CEGUI::RenderedString::*getPixelSize_function_type )( ::size_t const ) const;
            
            RenderedString_exposer.def( 
                "getPixelSize"
                , getPixelSize_function_type( &::CEGUI::RenderedString::getPixelSize )
                , ( bp::arg("line") )
                , "*!\n\
                \n\
                    Return the pixel size of a specified line for the RenderedString.\n\
            \n\
                @param line\n\
                    The line number whose size is to be returned.\n\
            \n\
                @return\n\
                    Size object describing the size of the rendered output of the specified\n\
                    line of this RenderedString, in pixels.\n\
            \n\
                @exception InvalidRequestException\n\
                    thrown if  line is out of range.\n\
                *\n" );
        
        }
        { //::CEGUI::RenderedString::getSpaceCount
        
            typedef ::size_t ( ::CEGUI::RenderedString::*getSpaceCount_function_type )( ::size_t const ) const;
            
            RenderedString_exposer.def( 
                "getSpaceCount"
                , getSpaceCount_function_type( &::CEGUI::RenderedString::getSpaceCount )
                , ( bp::arg("line") )
                , "! return the total number of spacing characters in the specified line.\n" );
        
        }
        { //::CEGUI::RenderedString::operator=
        
            typedef ::CEGUI::RenderedString & ( ::CEGUI::RenderedString::*assign_function_type )( ::CEGUI::RenderedString const & ) ;
            
            RenderedString_exposer.def( 
                "assign"
                , assign_function_type( &::CEGUI::RenderedString::operator= )
                , ( bp::arg("rhs") )
                , bp::return_self< >()
                , "! Copy constructor.\n\
            ! Assignment.\n" );
        
        }
        { //::CEGUI::RenderedString::split
        
            typedef void ( ::CEGUI::RenderedString::*split_function_type )( ::size_t const,float,::CEGUI::RenderedString & ) ;
            
            RenderedString_exposer.def( 
                "split"
                , split_function_type( &::CEGUI::RenderedString::split )
                , ( bp::arg("line"), bp::arg("split_point"), bp::arg("left") )
                , "*!\n\
                \n\
                    split the string in line  line as close to  split_point as possible.\n\
            \n\
                    The RenderedString  left will receive the left portion of the split,\n\
                    while the right portion of the split will remain in this RenderedString.\n\
            \n\
                @param line\n\
                    The line number on which the split is to occur.\n\
            \n\
                @param split_point\n\
                    float value specifying the pixel location where the split should occur.\n\
                    The actual split will occur as close to this point as possible, though\n\
                    preferring a shorter 'left' portion when the split can not be made\n\
                    exactly at the requested point.\n\
            \n\
                @param left\n\
                    RenderedString object that will receieve the left portion of the split.\n\
                    Any existing content in the RenderedString is replaced.\n\
            \n\
                @exception InvalidRequestException\n\
                    thrown if  line is out of range.\n\
                *\n" );
        
        }
    }

}
