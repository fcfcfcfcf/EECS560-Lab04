// Jacob Marshall // 2876707 // EECS560 // Lab3 // 24 Sept 2018 //
#include <iostream>
#include"Executive.h"
#include<string>
#include<iostream>
int main(int argc, char* argv[])
{
  if(argc < 2) //checks to make sure the user has passed a correct number of parameters
  {
    cout << "Incorrect number of parameters!\n";
  }
  else
  {
     cout<<"Welcome!";
     Executive exec(argv[1]);
        //creation of executive object

  }

  return(0);
}
