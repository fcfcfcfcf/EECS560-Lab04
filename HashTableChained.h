// Jacob Marshall // 2876707 // EECS560 // Lab4 // 6 Oct 2018 //
#ifndef HASHTABLECHAINED_H
#define HASHTABLECHAINED_H

#include "Node.h"

#include<string>
#include<iostream>
using namespace std;
template <int M>
class HashTableChained{
  public:
    //Contrcutor of HashTable, creates a HashTable with the passed in size
    //@pre: hashTable object is created in another class
    //@post: a new hashTable object is created
    //@ret: none
    HashTableChained();

    //Destructor, deletes the HashTable
    //@pre: delete is called on this HashTable object
    //@post: the object is deleted
    //@ret: none
    ~HashTableChained();

    //inserts a given int into the hashTable, first checking to see if it already exists, and then hashes the int and inserts it into the correct list. Returns true if insetion is succesful
    //@pre: insert is called passing in an integer to be inserted
    //@post: the integer is inserted into its appropriate place in the HashTable
    //@ret: bool value equal to the success of the insertion
    bool insert(int x);

    //deletes a given int from the hashTable, returns true if deletion is succesful
    //@pre: deleteEntry is called passing in an integer to be deleted
    //@post: the integer is found and then if it exists, is deleted
    //@ret: bool value equal to the success of the deletion
    bool deleteEntry(int x);

    //finds an integer in a hashTable, returns true if it is found
    //@pre: find is called, passing in an integer 
    //@post: the function attempts to find the given integer
    //@ret:  true if the value is found in the hashTable
    bool find(int x);

    //finds the correct index to place the given integer
    //@pre: hash is called, passing in an integer
    //@post: the functions finds the correct place to put the integer
    //@ret: returns the index that the value is hashed to 
    int hash(int x);

    //prints out the values in the hashTable
    //@pre: printAll is called
    //@post: prints out all the values 
    //@ret: none
    void printAll();

  private:
    //array of buckets containing doubly-linked nodes
    Node* buckets[M];

  

};
#include"HashTableChained.hpp"
#endif
