/*===========================================================================
 *                              INCLUDES
 *===========================================================================*/

#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

extern "C" {
#include "main.h"
}

#include "ExampleModule_expect.hpp"
#include "ExamplePeripheral_expect.hpp"

using CppUMockGen::IgnoreParameter;

/*===========================================================================
 *                      COMMON TEST DEFINES & MACROS
 *===========================================================================*/

/*===========================================================================
 *                          TEST GROUP DEFINITION
 *===========================================================================*/

TEST_GROUP( main )
{
};

/*===========================================================================
 *                    TEST CASES IMPLEMENTATION
 *===========================================================================*/

TEST( main, main )
{
    // Prepare
    expect::ExampleModule_f1( 20, 55, 25 );
    expect::configure_example_peripheral( 50 );

    // Exercise
    main();

    // Verify
    mock().checkExpectations();

    // Cleanup
}
