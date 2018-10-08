// Jacob Marshall // 2876707 // EECS560 // Lab4 // 6 Oct 2018 //
#ifndef HASHTABLEDH_H
#define HASHTABLEDH_H
#include<string>
#include<iostream>
using namespace std;
template<int M>
class HashTableDH{
  public:
    //Contrcutor of HashTable, creates a HashTable with the passed in size, k value, and p value
    //@pre: hashTable object is created in another class
    //@post: a new hashTable object is created
    //@ret: none
    HashTableDH(int kvalue, int pvalue);

    //Destructor, deletes the HashTable
    //@pre: delete is called on this HashTable object
    //@post: the object is deleted
    //@ret: none
    ~HashTableDH();

    //inserts a given int into the hashTable, first checking to see if it already exists, and then hashes the int and inserts it into the correct list. 
    //@pre: insert is called passing in an integer to be inserted
    //@post: the integer is inserted into its appropriate place in the HashTable
    //@ret: none
    void insert(int x);

    //deletes a given int from the hashTable, returns true if deletion is succesful
    //@pre: deleteEntry is called passing in an integer to be deleted
    //@post: the integer is found and then if it exists, is deleted
    //@ret: none
    void deleteEntry(int x);

    
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

    //gets the loadFactor of the give
    //@pre: getLoadFactor is called
    //@post: returns the loadFactor
    //@ret: returns a double value for the loadFactor
    double getLoadFactor();

  private:
    //k value for double hashing
    int k;

    //p value for double hashing
    int p;

    //array that stores ints, each indice is an indice of the hashTable
    int buckets[M];

    //mirrors the HashTable, each index corresponds to an index in the HashTable, flag ticks from 0 to 1 when an int is inseted into that index of the hashTable for the first time
    bool flags[M];
    

};
#include"HashTableDH.hpp"
#endif
