/*===========================================================================
 *                              INCLUDES
 *===========================================================================*/

#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>

#include "UnitUnderTest.hpp"

#include "MockedClass_expect.hpp"

using CppUMockGen::IgnoreParameter;

/*===========================================================================
 *                      COMMON TEST DEFINES & MACROS
 *===========================================================================*/

/*===========================================================================
 *                          TEST GROUP DEFINITION
 *===========================================================================*/

TEST_GROUP( TestModule )
{
};

/*===========================================================================
 *                    TEST CASES IMPLEMENTATION
 *===========================================================================*/

TEST( TestModule, f1 )
{
    // Prepare
    ExamplePublicClass c;
    expect::ExamplePrivateClass$::f2( IgnoreParameter::YES, 5, 9, 25 );

    // Exercise
    int ret = c.f1( 5, 9 );

    // Verify
    CHECK_EQUAL( 50, ret );

    // Cleanup
}
