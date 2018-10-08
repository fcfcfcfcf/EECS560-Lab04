#ifndef NODE_H
#define NODE_H
#include<string>
using namespace std;



class Node {


private:
  int data;
  Node* next;
  Node* prev;


public:
  Node();
  Node(int theData, Node* thePrev, Node* theNext);
  void setData(int newData);
  int getData();
  void setNext(Node* theNext);
  Node* getNext();
  void setPrev(Node* thePrev);
  Node* getPrev();



};

#endif
