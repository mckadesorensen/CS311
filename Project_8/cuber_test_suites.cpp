// cuber_test_suites.cpp  INCOMPLETE
// Glenn G. Chappell
// 2019-11-22
//
// For CS 311 Fall 2019
// Tests for class Cuber: test suites
// For Project 8, Exercise B
// Uses the "Catch" unit-testing framework, version 2
// Requires cuber_test_main.cpp, catch.hpp, cuber.h

// Includes for code to be tested
#include "cuber.h"         // For class Cuber
#include "cuber.h"         // Double inclusion test

#define CATCH_CONFIG_FAST_COMPILE
                           // Disable some features for faster compile
#include "catch.hpp"       // For the "Catch" unit-testing framework

// Additional includes for this test program
#include "cuber.h"


// *********************************************************************
// Test Cases
// *********************************************************************
// Do both const & non-const Cuber objects work
TEST_CASE("Const and non-const cuber objects")
{
    Cuber x;
    const Cuber y;
    INFO("CONST OR NON-CONST CUBER OBJECT NOT PASSING");
    REQUIRE( x.operator()(2) == 8 );
    REQUIRE( y.operator()(2) == 8 );


}

// Does Cuber work properly for a wide range of values
TEST_CASE("Range of values", "[cuber]")
{
    Cuber x;
    INFO("FAILING ON A RANGE OF VALUES");
    REQUIRE( x.operator()(2) == 8 );
    REQUIRE( x.operator()(3) == 27 );
    REQUIRE( x.operator()(10) == 1000 );
}

// Does Cuber work properly for both positive and negative values
TEST_CASE("Positive and negative arguments")
{
    Cuber x;
    INFO("FAILING ON EITHER A NEGATIVE OR POSITIVE VALUE");
    REQUIRE( x.operator()(-2) == -8 );
    REQUIRE( x.operator()(-3) == -27 );
    REQUIRE( x.operator()(2) == 8 );
    REQUIRE( x.operator()(3) == 27 );
}

// Does Cuber work properly for both integer and floating-point arguments
TEST_CASE("Floating-point and integer arguments")
{
    Cuber x;
    INFO("FAILING ON EITHER A FLOAT OR INTEGER VALUE");
    REQUIRE( x.operator()(3.3) == 35.937 );
    REQUIRE( x.operator()(2.25) == 11.390625 );
    REQUIRE( x.operator()(25) == 15625 );
    REQUIRE( x.operator()(30) == 27000 );
}

// What about arguments of type cha
TEST_CASE("Char as arguments")
{
    Cuber x;
    INFO("FAILING ON CHAR A VALUE");
    REQUIRE( x.operator()('a') == '!' );
    REQUIRE( x.operator()('0') == 0 );
    REQUIRE( x.operator()('4') == '@' );
    REQUIRE( x.operator()('3') == '+' );
}

// Special cases of interest: the cubes of 0, 1, and -1 should be correct
TEST_CASE("Special cases")
{
    Cuber x;
    INFO("FAILING ON SPECIAL CASES (-1, 0, 1");
    REQUIRE( x.operator()(0) == 0 );
    REQUIRE( x.operator()(1) == 1 );
    REQUIRE( x.operator()(-1) == -1 );
}
