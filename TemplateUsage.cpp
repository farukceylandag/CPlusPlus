#include <iostream>
using namespace std;


/* Template Kullanmadan

int Max(int _num1, int _num2){
  
   return (_num1 > _num2)? _num1 : _num2; 
   // _num1 büyükse _num1 ,değilse _num2 döndür.
}

float Max(float _num1, float _num2){

   return (_num1 > _num2)? _num1 : _num2;
}

*/

//------------------------------------------------//

  // Template Kullanarak
 
  template <typename Tip> 
  Tip Max(Tip _num1,Tip _num2){

   return (_num1 > _num2)? _num1 : _num2;
  }

  
  // Class Template 

  template <class Tip>
  
  class Stack{
    
    public:
    Stack(Tip _size=10){


     size = _size;
     data = new Tip[size];
     ptr = 0;
    }

    void push(Tip _elem){
      
      data[ptr] = _elem;
      ptr++;
      if(ptr>size) ptr=size-1;
    }

    Tip pop(){
      if(ptr>0) ptr--;
      return data[ptr];
    }
    
    void resize (int _newsize){

      Tip *newdata;
      newdata = new Tip[_newsize];
      for(int i=0;i<ptr;i++){
        newdata[i] = data[i];
      }
      delete data;
      data = newdata;
      size = _newsize;
    }

    void print(){
      
      for(int i=0;i<ptr;i++){
        cout << data[i] << " ";
      }
      
      cout << endl;

    }

    protected: 
    Tip *data; 
    int size;
    int ptr;

  };


int main() {
  

  //------------ Template -----------//
  cout << "\nMax String : " << Max("ayse","ali") << endl;
  cout << "\nMax Float: " << Max(7.23,6.02) << endl;
  cout << endl;

  //-------------- Class Template Char ------------//
  
 Stack <char> ss(20);

  
  ss.push('F');
  ss.push('A');
  ss.push('R');
  ss.push('U');
  ss.push('K');
  ss.push('C');
  ss.print();
  ss.pop();
  ss.print();



    return 0;
}


