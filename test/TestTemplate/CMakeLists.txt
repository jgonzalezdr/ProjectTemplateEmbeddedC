cmake_minimum_required( VERSION 3.3 )

project( ProjectTemplateEmbeddedC.Test.TestModule )

#
# Test configuration
#

include_directories(
    ${PROD_SOURCE_DIR}/sources
    ${PROD_SOURCE_DIR}/include
    ${MOCKS_DIR}
)

#
# Production source files
#

#>>> Add your production source files to the following list
set( PROD_SRC_FILES
     ${PROD_SOURCE_DIR}/sources/UnitUnderTest.cpp
)

#
# Test source files
#

#>>> Add your test source files to the following list
set( TEST_SRC_FILES
     TestModule_test.cpp
     ${MOCKS_DIR}/MockedUnit_mock.cpp
     ${MOCKS_DIR}/MockedUnit_expect.cpp
)

#
# Generate test target
#

include( ${TEST_BASE_DIR}/GenerateTest.cmake )
