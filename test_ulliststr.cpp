#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

	list.push_back("a");

	cout<<list.get(0);

	list.pop_front();  // prints 3 since there are 3 strings stored
}
