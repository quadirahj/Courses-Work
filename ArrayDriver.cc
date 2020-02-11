/*
  Filename   : ArrayDriver.cc
  Author     : Quadirah N. Jones
  Course     : CSCI 362
  Assignment : 3
  Description: Test some, but NOT ALL, methods of the Array class.
*/   

/************************************************************/
// System includes

#include <cstdlib>
#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <cassert>

/************************************************************/
// Local includes

#include "Array.hpp"

/************************************************************/
// Using declarations

using std::cin;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::string;
using std::ostringstream;

/************************************************************/
// Function prototypes/global vars/typedefs

void
printTestResult (const string& test,
		 const string& expected,
		 const ostringstream& actual);

/************************************************************/

int      
main (int argc, char* argv[]) 
{        
  Array<int> A;

  // For holding the actual result
  ostringstream output;
  // Put the actual result into the output stream
  output << A;
  printTestResult ("no-arg ctor", "[ ]", output);

  // Must clear the output stream each time
  output.str ("");
  output << A.empty ();
  // "1" for true, "0" for false
  printTestResult ("empty", "1", output);
  
  A.push_back (5);
  A.push_back (10);
  A.push_back (15);

  output.str ("");
  output << A;
  printTestResult ("push_back", "[ 5 10 15 ]", output);

  output.str ("");
  output << A.size ();
  printTestResult ("size", "3", output);
  
  A.pop_back ();
  A.pop_back ();

  output.str ("");
  output << A;
  printTestResult ("pop_back", "[ 5 ]", output);

  /************************************************************/
  // Convert the following tests to use printTestResult
  /************************************************************/
  for (int i = 0; i < 10; ++i)
  {
   A.insert (A.begin (), i);
  }
  
  output.str ("");
  output << A;
  printTestResult ("insert", "[ 9 8 7 6 5 4 3 2 1 0 5 ]", output);

    for (Array<int>::iterator i = A.begin (); i != A.end (); )
    {
        i = A.erase (i);
    }
    output.str ("");
    output << A;
    printTestResult ("Erase", "[ ]", output);
  
    // Size ctor, with a fill value. 
    Array<int> B (3, 9);
    output.str ("");
    output << B;
    printTestResult ("Size", "[ 9 9 9 ]", output);

    // Range ctor. 
    Array<int> C (B.begin (), B.begin () + 2);
    output.str ("");
    output << C;
    printTestResult ("Range", "[ 9 9 ]", output);
   
    // Assignment operator. 
    B = A;
    output.str ("");
    output << B;
    printTestResult ("Assignment", "[ ]", output);

    for (int i = 0; i < 5; ++i) 
    {
      B.insert (B.begin (), i);
    } 
    output.str ("");
    output << B;
    printTestResult ("Insert", "[ 4 3 2 1 0 ]", output);
  
  /************************************************************/
  // START WRITING YOUR TESTS HERE
  /************************************************************/
  Array<int> Q;
  for (int i = 1; i < 12; ++i)
  {
   Q.insert (Q.begin (), i);
  }
  
  output.str ("");
  output << Q;
  printTestResult (" My Insert Test", "[ 11 10 9 8 7 6 5 4 3 2 1 ]", output);

  Q.resize (5);
  output.str ("");
  output << Q;
  printTestResult (" My Resize Test", "[ 11 10 9 8 7 ]", output);

  Array<int> N (Q.begin () + 2, Q.begin () + 8);
  // Range ctor. 
  output.str ("");
  output << N;
  printTestResult (" My Range Test", "[ 9 8 7 6 5 4 ]", output);

  Array<int> z (N);
  output.str ("");
  output << z;
  printTestResult (" My Copy Test", "[ 9 8 7 6 5 4 ]", output);

  output.str ("");
  output << N.capacity ();
  printTestResult (" My Capacity Test", "6", output); 


  output.str ("");
  output << Q [7];
  printTestResult (" My Subscript Test", "4", output);

  Q.insert( Q.begin(), 12);
  output.str ("");
  output << Q.size();
  printTestResult (" My Double capacity Test", "6", output);
  
  Array<int> e;
  output.str ("");
  output << e;
  printTestResult (" no arg ctor", "[ ]", output);

  return EXIT_SUCCESS;
}
/************************************************************/

void
printTestResult (const string& test,
		 const string& expected,
		 const ostringstream& actual)
{
  cout << "Test: " << test << endl;
  cout << "==========================" << endl;
  cout << "Expected: " << expected << endl;
  cout << "Actual  : " << actual.str () << endl;
  cout << "==========================" << endl << endl;

  // Ensure the two results are the same
  assert (expected == actual.str ());
}

/************************************************************/