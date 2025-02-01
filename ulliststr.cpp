#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
#include <sstream>
using namespace std;
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// Adds a new value to the back of the list
void ULListStr::push_back(const std::string& val)
{
  //case 1: head and tail is a nullptr
  if(empty())
  {
    //create new Item
    Item * temp= new Item();
    tail_= temp;
    head_= temp;
    head_->val[0]=val;
    head_->last++;
  }
  else if(tail_->last==ARRSIZE)//if tail Item has no room to push back
  {
    //create new Item
    Item * temp= new Item();
    tail_->next = temp;
    temp->prev=tail_;
    tail_=temp;

    //update val
    temp->val[0]=val;
    temp->last++;
  }
  else//if there is room to pushback
  {
    tail_->val[tail_->last]=val;
    tail_->last++;
  }
  size_++;
  return;
}

//Removes a value from the back of the list
void ULListStr::pop_back()
{
  if (empty())
  {
    return;
  }
  tail_->last--;
  size_--;
  if (tail_->last==tail_->first)//one val left in item. delete item
  {
    if (head_ == tail_){//if there is one item left
      delete head_;
      tail_=nullptr;
      head_=nullptr;
      size_=0;
    } 
    else{
      Item* temp = tail_;
      tail_ = tail_->prev;
      tail_->next=nullptr;
      delete temp;
    }
  }
}

/**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
string const &ULListStr::back() const{
  if(empty()){
    throw std::invalid_argument("No Values");
  }
  else{
    return tail_->val[tail_->last-1];
  }
}

string const &ULListStr::front() const{
  if(empty()){
    throw std::invalid_argument("No values");
  }
  else{
    return head_->val[head_->first];
  }
}

/**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
void ULListStr::push_front(const std::string& val)
{
  //case 1: head and tail is a nullptr
  if(empty())
  {
    //create new Item
    Item * temp= new Item();
    tail_= temp;
    head_= temp;
    head_->last=ARRSIZE;//indice 10
    head_->first = ARRSIZE-1;//indice 9
    head_->val[head_->first]=val;
  }
  //case 2: if head Item has no room before the first Item
  else if (head_->first==0){
    //create new Item
    Item* p= new Item();
    head_->prev = p;
    p->next = head_;
    head_ = p;
    head_->prev=nullptr;

    //update val
    p->val[ARRSIZE-1]= val; //put it at the end
    p->last=ARRSIZE;
    p->first=ARRSIZE-1;
  }
  else{//case 3: first is not 0 
    head_->val[(head_->first)-1]=val;
    head_->first=(head_->first)-1;
  }
  //update size_
  size_++;
  return;
}

/**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front()
{
  if (empty())
  {
    return;
  }
  head_->first++;
  size_--;
  if (head_->first==head_->last)
  {
    if (head_ == tail_){//if there is one item left
      delete head_;
      tail_=nullptr;
      head_=nullptr;
      size_=0;
    } 
    else{
      Item* temp = head_;
      head_ = head_->next;
      head_->prev=nullptr;
      delete temp;
    }
  }
  //if first and last meet, eliminate that, when head = tail or change what the head is
  //normal case, move first pointer forward
}  


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

string* ULListStr::getValAtLoc(size_t loc) const {
  size_t index = head_->first;
 //check where index of first item is
  loc+=index; //if the first item is not at index 0, adjust loc accordingly
  size_t itemNum = loc/10; //which item its on
  size_t idxNum = loc%10;//which index of item to check
  if (loc<index || loc>=size_+index)//check if loc is out of bounds
  {
    return NULL;
  }
  else
  {
    Item* curr= head_;
    size_t count = 0;
    while (count<itemNum)
    {
      if (curr->next == nullptr)
      {
        return NULL;
      }
      curr = curr->next;
      count++;
    }
    if (curr->last<idxNum){
      return nullptr;
    }
    string *str = &curr->val[idxNum];
    return str;
}
}
