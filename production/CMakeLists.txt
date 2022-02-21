cmake_minimum_required( VERSION 3.13 )

#>>> Edit the project name
project( ProjectTemplateEmbeddedC VERSION 1.0.0 )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/" )

if( MSVC )
    include( VisualStudioHelper )

    generate_groups( ${CMAKE_CURRENT_SOURCE_DIR} sources )
    generate_groups( ${CMAKE_CURRENT_SOURCE_DIR} include )
endif( MSVC )

#
# Source files
#

#>>> Add your source files to the following list
set( SRC_LIST
#     sources/ExampleModule.c
#     sources/main.c
)

#
# Header files
#

#>>> Add your header files to the following list
set( INC_LIST
#     sources/ExampleModule.h
#     include/ExamplePeripheral.h
)

#
# Project information
#

if( NOT PROJECT_VERSION_BUILD )
    set( PROJECT_VERSION_BUILD ${PROJECT_VERSION_TWEAK} )
endif()

#
# Library definition
#

if( MSVC )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc" )
endif()

#
# Static library definition
#

add_library( ${PROJECT_NAME} STATIC ${SRC_LIST} ${INC_LIST} )

target_include_directories( ${PROJECT_NAME} PUBLIC include )
target_include_directories( ${PROJECT_NAME} PUBLIC sources )

target_compile_definitions( ${PROJECT_NAME} PUBLIC _UNITTEST_ )

#>>> Uncomment and edit the following commands to add compile definitions
#target_compile_definitions( ${PROJECT_NAME} PUBLIC "${PROJECT_NAME}_MY_DEFINITION" )

#
# C++ standard
#

#>>> Uncomment and edit the following commands to set an specific C++ standard
#set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11 )
#set_property( TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED 1 )

#
# External libraries
#

#>>> Uncomment and edit the following commands to add external libraries
#target_include_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/ExternalLib/include )
#target_link_directories( ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/ExternalLib/lib )
#target_link_libraries( ${PROJECT_NAME} ExternalLib.lib )

#
# Static library properties
#

set_target_properties( ${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_dbg" )
set_target_properties( ${PROJECT_NAME} PROPERTIES COVERAGE_POSTFIX "_cov" )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION} )
