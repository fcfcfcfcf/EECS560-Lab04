// Jacob Marshall // 2876707 // EECS560 // Lab4 // 6 Oct 2018 //
#include<iostream>
#include<fstream>
#include<string>
#include"HashTableDH.h"
#include"HashTableQP.h"
#include"HashTableChained.h"
#include"Executive.h"
#include"time.h"
#include<stdlib.h>
using namespace std;


Executive::Executive(string filename){
  fileToOpen = filename;
  run();

}


void Executive::run(){
  
  bool quit;
  quit = false;
  while(quit == false){
    cout<<"\nPlease choose one of the following commands: \n";
    cout<<"1-Test HashTables\n";
    cout<<"2-Performance Comparison\n";
    cout<<"3-Exit\n";
    cout<<">";
    string command; 
    cin>>command;
    if(command == "1"){
      ifstream inFile;
      inFile.open(fileToOpen);  
      HashTableDH<11>* htdh = new HashTableDH<11> (4 , 5);
      HashTableQP<11>* htqp = new HashTableQP<11> (4);
      HashTableChained<11>* htc = new HashTableChained<11> ();
      string newData;
      int intnewData;
      while (inFile >> newData) {
        intnewData = stoi(newData);
        htqp->insert(intnewData);
        htdh->insert(intnewData);
        htc->insert(intnewData);
      }
      cout<<"Open Hashing: \n";
      htc->printAll();
      cout<<"Hash Table with Quadratic Probing: \n";
      htqp->printAll();
      cout<<"Hash Table with Double Hashing: \n";
      htdh->printAll();
      inFile.close();\ 
    }
    if(command == "2"){

      float openHash[3][5];
      float doubleHash[3][5];
      float quadHash[3][5];
      for(int x = 0; x<3; x++){
        for(int y=0; y<5; y++){
          openHash[x][y] = 0.0;
          doubleHash[x][y] = 0.0;
          quadHash[x][y] = 0.0;
        }
      } 

      const int hashTableSize = 1000003;
      clock_t t;
        
      for(int size = 1; size < 6; size++){
        int column = size -1;
        for(int trials= 1; trials < 6; trials++){
              srand(time(NULL)); 
              HashTableDH<hashTableSize>* htdh = new HashTableDH<hashTableSize> (20 , 997);
              HashTableQP<hashTableSize>* htqp = new HashTableQP<hashTableSize> (20);
              HashTableChained<hashTableSize>* htc = new HashTableChained<hashTableSize> ();

              t = clock();
              for(int i = 0; i < (100000*size); i++ ){
                  int newInt = rand() % (5*hashTableSize) + 1;
                  htdh->insert(newInt); 
              }
              t = clock() -t;
              doubleHash[0][column] = doubleHash[0][column] + ((float)t /CLOCKS_PER_SEC); 

              t = clock();
              for(int i = 0; i < (100000*size); i++ ){
                  int newInt = rand() % (5*hashTableSize) + 1;
                  htqp->insert(newInt); 
              }
              t = clock() -t;
              quadHash[0][column] = quadHash[0][column] + ((float)t /CLOCKS_PER_SEC); 

              t = clock();
              for(int i = 0; i < (100000*size); i++ ){
                  int newInt = rand() % (5*hashTableSize) + 1;
                  htc->insert(newInt); 
              }
              t = clock() -t;
              openHash[0][column] = openHash[0][column] + ((float)t /CLOCKS_PER_SEC); 

              
              
                for(int i = 0; i < (10000*size); i++){
                  
                    int newInt = rand() % (5*hashTableSize) + 1;
                    
                    t = clock();
                    bool found = htdh->find(newInt);
                    t = clock() -t;
                    if(found == true){
                      doubleHash[1][column] = doubleHash[1][column] + ((float)t /CLOCKS_PER_SEC);
                    }
                    else{
                      doubleHash[2][column] = doubleHash[2][column] + ((float)t /CLOCKS_PER_SEC);
                    }

                }
                for(int i = 0; i < (10000*size); i++){
                  
                    int newInt = rand() % (5*hashTableSize) + 1;
                    t = clock();
                    if(htqp->find(newInt)){
                      t = clock() -t;
                      quadHash[1][column] = quadHash[1][column] + ((float)t /CLOCKS_PER_SEC);
                    }
                    else{
                      t = clock() -t;
                      quadHash[2][column] = quadHash[2][column] + ((float)t /CLOCKS_PER_SEC);
                    }

                }
                for(int i = 0; i < (10000*size); i++){
                  
                    int newInt = rand() % (5*hashTableSize) + 1;
                    t = clock();
                    if(htc->find(newInt)){
                      t = clock() -t;
                      openHash[1][column] = openHash[1][column] + ((float)t /CLOCKS_PER_SEC);
                    }
                    else{
                      t = clock() -t;
                      openHash[2][column] = openHash[2][column] + ((float)t /CLOCKS_PER_SEC);
                    }

                }
        }
      }

      for(int x = 0; x < 3; x++){
        for(int y=0; y <5; y++){
          if(x == 0){
            cout<<"BUILD FOR OPEN HASHING SIZE = "<<(y+1)*(100000)<<":    "<<openHash[x][y]/(5.0)<<"\n";
            cout<<"BUILD FOR DOUBLE HASHING SIZE = "<<(y+1)*(100000)<<":    "<<doubleHash[x][y]/(5.0)<<"\n";
            cout<<"BUILD FOR QUADRATIC PROBING SIZE = "<<(y+1)*(100000)<<":    "<<quadHash[x][y]/(5.0)<<"\n";

          }
          else if (x == 1){
            cout<<"FOUND FOR OPEN HASHING SIZE = "<<(y+1)*(100000)<<":    "<<openHash[x][y]/(5.0)<<"\n";
            cout<<"FOUND FOR DOUBLE HASHING SIZE = "<<(y+1)*(100000)<<":    "<<doubleHash[x][y]/(5.0)<<"\n";
            cout<<"FOUND FOR QUADRATIC PROBING SIZE = "<<(y+1)*(100000)<<":    "<<quadHash[x][y]/(5.0)<<"\n";
          }
          else{
            cout<<"NOT FOUND FOR OPEN HASHING SIZE = "<<(y+1)*(100000)<<":    "<<openHash[x][y]/(5.0)<<"\n";
            cout<<"NOT FOUND FOR DOUBLE HASHING SIZE = "<<(y+1)*(100000)<<":    "<<doubleHash[x][y]/(5.0)<<"\n";
            cout<<"NOT FOUND FOR QUADRATIC PROBING SIZE = "<<(y+1)*(100000)<<":    "<<quadHash[x][y]/(5.0)<<"\n";

          }
          cout<<"\n";
        }
      }

        



    }
    
    if(command == "3"){
      cout<<"Byebye! \n\n\n\n\n\n\n\n\n\n\n";
      quit = true;
    }

  }
  


}


