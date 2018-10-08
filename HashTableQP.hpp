// Jacob Marshall // 2876707 // EECS560 // Lab3 // 24 Sept 2018 //

#include<math.h>
#include "HashTableQP.h"
using namespace std;

template <int M>
HashTableQP<M>::HashTableQP(int kvalue){
    k = kvalue;
    for(int i =0; i < M; i++){
        buckets[i] = -1;
        flags[i] = false;
    }
}

template <int M>
HashTableQP<M>::~HashTableQP(){
    delete[] buckets;
}

template <int M>
double HashTableQP<M>::getLoadFactor(){
    double loadFactor = 0.0;
    for(int i =0; i < M; i++){
        if(buckets[i] != -1){
            loadFactor = loadFactor + 1.0;
        }
    }
    loadFactor = loadFactor/M;
    return loadFactor;
}

template <int M>
void HashTableQP<M>::deleteEntry(int x){
    int index = hash(x);
    if(find(x) == false){
     
    }
    else{
        buckets[index] = -1;
    }

}

template <int M>
void HashTableQP<M>::printAll(){
 
    for(int i =0; i < M; i++){
        if(buckets[i] != -1){
            cout<<i<<": "<<buckets[i]<<"\n";
        }
    }
}

template <int M>
void HashTableQP<M>::insert(int x){
    int index = hash(x);
    if(buckets[index] == -1){
        buckets[index] = x;
        flags[index] = true;
    }
  
}


template <int M>
bool HashTableQP<M>::find(int x){
    int index = hash(x);
    if(index == -1){
        return false;
    }
    else{
        if(buckets[index] == x){
            return true;
        }
        else{
            return false;
        }
    }



}


template <int M>
int HashTableQP<M>::hash(int x){
  int hashNum = 0;
  int hashed = x%M;
  int indexToSearch = hashed;
  for(int i = 0; i < k + 1; i++){
      if(i == k){
          indexToSearch = -1;
          break;
      }
      else if(buckets[indexToSearch] == -1){
          if(flags[indexToSearch] == false){
              break;
          }
      }
      else if(buckets[indexToSearch] == x){
          break;
      }
      else{
          indexToSearch = (int(hashed + pow(i, 2)))%M;
      }
  }
  return indexToSearch;
}
