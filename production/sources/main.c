#include "main.h"
#include "ExamplePeripheral.h"
#include "ExampleModule.h"

void main()
{
    int a = 20;
    int b = 55;

    configure_example_peripheral( 2 * ExampleModule_f1( a, b ) );
}
