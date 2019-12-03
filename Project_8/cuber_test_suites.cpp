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
TEST_CASE("Do both const & non-const Cuber objects work")
{
    Cuber x;
    const Cuber y;
    REQUIRE( x.operator()(2) == 8 );
    REQUIRE( y.operator()(2) == 8 );


}

TEST_CASE("Does Cuber work properly for a wide range of values", "[cuber]")
{
    Cuber x;
    REQUIRE( x.operator()(2) == 8 );
    REQUIRE( x.operator()(3) == 27 );
    REQUIRE( x.operator()(10) == 1000 );
}

TEST_CASE("Does Cuber work properly for both positive and negative values")
{
    Cuber x;
    REQUIRE( x.operator()(-2) == -8 );
    REQUIRE( x.operator()(-3) == -27 );
    REQUIRE( x.operator()(2) == 8 );
    REQUIRE( x.operator()(3) == 27 );
}

TEST_CASE("Does Cuber work properly for both integer and floating-point arguments")
{
    Cuber x;
    REQUIRE( x.operator()(3.3) == 35.937 );
    REQUIRE( x.operator()(2.25) == 11.390625 );
    REQUIRE( x.operator()(25) == 15625 );
    REQUIRE( x.operator()(30) == 27000 );
}

TEST_CASE("What about arguments of type char")
{
    Cuber x;
    REQUIRE( x.operator()('a') == '!' );
    REQUIRE( x.operator()('0') == 0 );
    REQUIRE( x.operator()('4') == '@' );
    REQUIRE( x.operator()('3') == '+' );
}

TEST_CASE("Special cases of interest: the cubes of 0, 1, and -1 should be correct")
{
    Cuber x;
    REQUIRE( x.operator()(0) == 0 );
    REQUIRE( x.operator()(1) == 1 );
    REQUIRE( x.operator()(-1) == -1 );
}
