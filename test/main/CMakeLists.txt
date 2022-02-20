cmake_minimum_required( VERSION 3.3 )

project( ProjectTemplateEmbeddedC.Test.main )

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

set( PROD_SRC_FILES
     ${PROD_SOURCE_DIR}/sources/main.c
)

#
# Test source files
#

set( TEST_SRC_FILES
     main_test.cpp
     ${MOCKS_DIR}/ExampleModule_mock.cpp
     ${MOCKS_DIR}/ExampleModule_expect.cpp
     ${MOCKS_DIR}/ExamplePeripheral_mock.cpp
     ${MOCKS_DIR}/ExamplePeripheral_expect.cpp
)

#
# Generate test target
#

include( ${TEST_BASE_DIR}/GenerateTest.cmake )
