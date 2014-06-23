// This file has been generated by Py++.

#include "boost/python.hpp"
#include "generators/include/python_CEGUIOpenGLRenderer.h"
#include "OpenGL3StateChangeWrapper.pypp.hpp"

namespace bp = boost::python;

void register_OpenGL3StateChangeWrapper_class(){

    { //::CEGUI::OpenGL3StateChangeWrapper
        typedef bp::class_< CEGUI::OpenGL3StateChangeWrapper, boost::noncopyable > OpenGL3StateChangeWrapper_exposer_t;
        OpenGL3StateChangeWrapper_exposer_t OpenGL3StateChangeWrapper_exposer = OpenGL3StateChangeWrapper_exposer_t( "OpenGL3StateChangeWrapper", bp::init< CEGUI::OpenGL3Renderer & >(( bp::arg("owner") ), "! constructor.\n") );
        bp::scope OpenGL3StateChangeWrapper_scope( OpenGL3StateChangeWrapper_exposer );
        bp::implicitly_convertible< CEGUI::OpenGL3Renderer &, CEGUI::OpenGL3StateChangeWrapper >();
        { //::CEGUI::OpenGL3StateChangeWrapper::bindBuffer
        
            typedef void ( ::CEGUI::OpenGL3StateChangeWrapper::*bindBuffer_function_type )( ::GLenum,::GLuint ) ;
            
            OpenGL3StateChangeWrapper_exposer.def( 
                "bindBuffer"
                , bindBuffer_function_type( &::CEGUI::OpenGL3StateChangeWrapper::bindBuffer )
                , ( bp::arg("target"), bp::arg("buffer") ) );
        
        }
        { //::CEGUI::OpenGL3StateChangeWrapper::bindVertexArray
        
            typedef void ( ::CEGUI::OpenGL3StateChangeWrapper::*bindVertexArray_function_type )( ::GLuint ) ;
            
            OpenGL3StateChangeWrapper_exposer.def( 
                "bindVertexArray"
                , bindVertexArray_function_type( &::CEGUI::OpenGL3StateChangeWrapper::bindVertexArray )
                , ( bp::arg("vertexArray") ) );
        
        }
        { //::CEGUI::OpenGL3StateChangeWrapper::blendFunc
        
            typedef void ( ::CEGUI::OpenGL3StateChangeWrapper::*blendFunc_function_type )( ::GLenum,::GLenum ) ;
            
            OpenGL3StateChangeWrapper_exposer.def( 
                "blendFunc"
                , blendFunc_function_type( &::CEGUI::OpenGL3StateChangeWrapper::blendFunc )
                , ( bp::arg("sfactor"), bp::arg("dfactor") ) );
        
        }
        { //::CEGUI::OpenGL3StateChangeWrapper::blendFuncSeparate
        
            typedef void ( ::CEGUI::OpenGL3StateChangeWrapper::*blendFuncSeparate_function_type )( ::GLenum,::GLenum,::GLenum,::GLenum ) ;
            
            OpenGL3StateChangeWrapper_exposer.def( 
                "blendFuncSeparate"
                , blendFuncSeparate_function_type( &::CEGUI::OpenGL3StateChangeWrapper::blendFuncSeparate )
                , ( bp::arg("sfactorRGB"), bp::arg("dfactorRGB"), bp::arg("sfactorAlpha"), bp::arg("dfactorAlpha") ) );
        
        }
        { //::CEGUI::OpenGL3StateChangeWrapper::reset
        
            typedef void ( ::CEGUI::OpenGL3StateChangeWrapper::*reset_function_type )(  ) ;
            
            OpenGL3StateChangeWrapper_exposer.def( 
                "reset"
                , reset_function_type( &::CEGUI::OpenGL3StateChangeWrapper::reset ) );
        
        }
        { //::CEGUI::OpenGL3StateChangeWrapper::scissor
        
            typedef void ( ::CEGUI::OpenGL3StateChangeWrapper::*scissor_function_type )( ::GLint,::GLint,::GLsizei,::GLsizei ) ;
            
            OpenGL3StateChangeWrapper_exposer.def( 
                "scissor"
                , scissor_function_type( &::CEGUI::OpenGL3StateChangeWrapper::scissor )
                , ( bp::arg("x"), bp::arg("y"), bp::arg("width"), bp::arg("height") ) );
        
        }
        { //::CEGUI::OpenGL3StateChangeWrapper::viewport
        
            typedef void ( ::CEGUI::OpenGL3StateChangeWrapper::*viewport_function_type )( ::GLint,::GLint,::GLsizei,::GLsizei ) ;
            
            OpenGL3StateChangeWrapper_exposer.def( 
                "viewport"
                , viewport_function_type( &::CEGUI::OpenGL3StateChangeWrapper::viewport )
                , ( bp::arg("x"), bp::arg("y"), bp::arg("width"), bp::arg("height") ) );
        
        }
    }

}
