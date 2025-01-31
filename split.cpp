/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */


void split(Node*& in, Node*& odds, Node*& evens)
{
  //base case, when end of in list is reached
  if (in==nullptr){
    return;
  }
  Node* nextNode = in->next; //preserve the list from second value
  in->next = nullptr; //set the in list to null pointer 
  if (in->value % 2 ==0)
  { //if the in value is even
    if (evens==nullptr)//if evens list is empty
    {
      evens = in; //point evens at the value
      evens->next = nullptr; //end the evens list after, set to null
    }
    else //if evens list is not empty
    {
      in->next = evens; //capture current evens list
      evens=in; //set evens to the current in value 
    }
  }
  else{ //if the in value is odd
    if (odds==nullptr) //if odds list is empty
    {
      odds = in;//point odds to current value
      odds -> next = nullptr; //end list by setting next to nullptr
    }
    else
    {//if odds is not empty
      in->next = odds; //point the next value at the odds list 
      odds=in; //set first value of odd to current in value
    }
  }
  in=nullptr; 
  split(nextNode, odds, evens);
}

/* If you needed a helper function, write it here */
