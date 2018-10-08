// Jacob Marshall // 2876707 // EECS560 // Lab2 // 17 Sept 2018 //
#include<string>
#include<math.h>
#include "HashTableChained.h"

#include "Node.h"
using namespace std;



template <int M>
HashTableChained<M>::HashTableChained(){

    
    for(int i =0; i < M; i++){
        buckets[i] = new Node();
    }
}

template <int M>
HashTableChained<M>::~HashTableChained(){
    delete[] buckets;
}

template <int M>
bool HashTableChained<M>::deleteEntry(int x){
  int index = hash(x);
  if(buckets[index] == nullptr){
    return false;
  }
  else{
    Node* nodeToDelete = buckets[index];
    bool searching = true;
    bool found = false;
    while(searching == true){
      if(nodeToDelete->getData() == x){
        if(nodeToDelete->getNext() != nullptr){
          nodeToDelete->getNext()->setPrev(nodeToDelete->getPrev());
        }
        if(nodeToDelete->getPrev() != nullptr){
          nodeToDelete->getPrev()->setNext(nodeToDelete->getNext());
        }
        else{
          buckets[index] = nodeToDelete->getNext();
        }

        searching = false;
        found = true;
      }
      else{
        if(nodeToDelete->getNext() != nullptr){
              nodeToDelete = nodeToDelete->getNext();
        }
        else{
          searching = false;
        }
      }
    }
    return found;

  }


}

template <int M>
void HashTableChained<M>::printAll(){
  for(int i =0; i < M; i++){
    
    if(buckets[i]->getData() != -1){
      cout<<i<<": ";
      Node* nodeToPrint = buckets[i];
      while((nodeToPrint != nullptr) && (nodeToPrint->getData() != -1)){
        cout<<nodeToPrint->getData()<<" ";
        nodeToPrint = nodeToPrint->getNext();
      }
      cout<<"\n";
    }
    
  }
}

template <int M>
bool HashTableChained<M>::insert(int x){
  if(find(x) == true){
    return false;
  }
  int index = hash(x);

  if(buckets[index] == nullptr){
    Node* newHead = new Node();
    newHead->setData(x);
    buckets[index] = newHead;

  }
  
  else{
    Node* newHead = new Node();
    newHead -> setData(x);
    buckets[index]->setPrev(newHead);
    newHead->setNext(buckets[index]);
    buckets[index] = newHead;

  }

  return true;

}

template <int M>
bool HashTableChained<M>::find(int x){
  int index = hash(x);

  if(buckets[index] == nullptr){
    return false;
  }
  else{
    Node* nodeToFind = buckets[index];
    bool searching = true;
    bool found = false;
    while(searching == true){
      if(nodeToFind->getData() == x){
        searching = false;
        found = true;
      }
      else{
        if(nodeToFind->getNext() != nullptr){
          nodeToFind = nodeToFind->getNext();
        }
        else{
          searching = false;
        }
      }

    }
    return found;
  }


}

template <int M>
int HashTableChained<M>::hash(int x){
  return x%M;

}
