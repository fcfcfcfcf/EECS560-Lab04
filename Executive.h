// Jacob Marshall // 2876707 // EECS560 // Lab4 // 6 Oct 2018 //
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include<string>
#include"HashTableDH.h"
#include"HashTableQP.h"
using namespace std;

class Executive{
  public:
    //creates a new Executive object
    //@pre: executive constructor is called from main
    //@post: passes control to run()
    //@ret: none
    Executive(string filename);
    //runs user interface and manages hash tables
    //@pre: run is called from executive constructor
    //@post: executes program with input from the user
    //@ret: none
    void run();
  private:
    //filename for the file to open
    string fileToOpen;
    

};

#endif
