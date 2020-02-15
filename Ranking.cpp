#include <iostream>
#include <string>

using namespace std;


void sirala(int x,int y);

int main() {

int dizi[] = {32,43,56,12,43,7,21};

  for(int i=0; i<=7 ;i++){
    for(int j=0;j<=7;j++){
      
     sirala(i,j);

    }
  }
  
}

void sirala(int x,int y) {

   int temp,dizi1[x];
   temp = dizi1[x]; 
   dizi1[x] = dizi1[y]; 
   dizi1[y] = temp;
   cout << dizi1 << endl;
   return;
}