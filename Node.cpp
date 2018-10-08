// Jacob Marshall // 2876707 // EECS560 // Lab2 // 17 Sept 2018 //
#include"Node.h"
#include<string>
using namespace std;





Node::Node(){
  next = nullptr;
  prev = nullptr;
  data = -1;
}

Node::Node(int theData, Node* thePrev, Node* theNext){
  setData(theData);
  setPrev(thePrev);
  setNext(theNext);
}


void Node::setData(int newData){
  data = newData;
}

int Node::getData(){
  return data;
}

void Node::setNext(Node* theNext){
  next = theNext;
}

Node* Node::getNext(){
  return next;
}

void Node::setPrev(Node* thePrev){
  prev = thePrev;
}

Node* Node::getPrev(){
  return prev;
}
