#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;
// sabit (6) haneli palindrom testi

string palindromTest1(int n){
  int b,o,y,bn,ob,yb;
  b = n%10; n /= 10;
  o = n%10; n /= 10;
  y = n%10; n /= 10;
  bn= n%10; n /= 10;
  ob= n%10; n /= 10;
  yb= n%10; n /= 10;
  if(b==yb && o==ob && y==bn)
    return "Bu Sayi Palindrom Bir Sayidir.\n";
  else
    return "Bu Sayi Palindrom Degil.\n";
}

int main() {

  int sayi,i=0,a;

 cout << "Lutfen 6 Haneli Bir Sayi Giriniz : " ;
 baslangic:
 cin >> sayi ;
 cout << endl ;

  while(sayi > 0)
    {
        sayi=sayi/10;
        i++;
        a=i;

if(sayi<0){
cout << "Lutfen Pozitif Bir Deger Giriniz : " ;
goto baslangic;
}
  if(a==6){
 cout << palindromTest1(sayi) ;
}
else
cout << "Lütfen Geçerli Bir Deger Giriniz : ";
goto baslangic;
    }

}

