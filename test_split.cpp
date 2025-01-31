/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
using namespace std;
#include <iostream>

int main(int argc, char* argv[])
{
  Node* li = new Node(1,nullptr);
  li->next = new Node (2, nullptr);
  li->next->next = new Node (3, nullptr);
  li->next->next->next = new Node (4, nullptr);
  li->next->next->next->next = new Node (5, nullptr);
  Node* odds = nullptr;
  Node* evens = nullptr;
  split(li, odds, evens);
  //printList(odds);
  cout<<endl;
  return 0;
}
