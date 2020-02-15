#include <iostream>
#include <iomanip>
/* 
 class Ogrenci
 . as -> int
 . fn -> int
 . ort -> double
 . harf -> string
 ()ortalamaBul()
 ()haftNotHesapla()
*/

class Ogrenci{
  public:
   Ogrenci(){

     as = 50;
     fn = 45;
     ad = "Anıl Altundağ";
     ders = "C++";
   }
   ~Ogrenci(){

     std::cout << ad <<" "<< "öldü\n";
   }
   Ogrenci(Ogrenci &a){

     ad ="Anıl";
     soyad = "Altundağ";
     as=10;
     fn=10;

   }
    double OrtalamaBul();
    std::string harfNotHesapla();
    void yaz();
    void setAS(int _as);
    int getAS();
    void setFN(int _fn);
    int getFN();
    void setAdSoyad(std::string _ad,std::string _soyad);
    std::string getAdSoyad();
    void setDers(std::string _ders);
    std::string getDers();
  private:
    std::string ad;
    std::string soyad;
    std::string ders;
    int as;
    int fn;
    double ort;
    std::string harf;
};



int main(){
  std::cout << "Durum" <<std::setw(26) <<  "Ad Soyad"<<std::setw(9) << "Ders" <<std::setw(8)  << "    Vize" <<std::setw(8) << "Final"  << " Ort." << " Harf\n-------------------------------------------------------------------\n";
  Ogrenci selim,busra;
  selim.setAdSoyad("Selim","Ağlak");
  selim.setDers("Matematik");
  selim.setAS(100);
  selim.setFN(85);
  selim.OrtalamaBul();
  selim.harfNotHesapla();
  selim.yaz();

  busra.setAdSoyad("Busra","Zırlak");
  busra.setDers("Matematik");
  busra.setAS(76);
  busra.setFN(65);
  busra.OrtalamaBul();
  busra.harfNotHesapla();
  busra.yaz();

  


  // referans kullanımı
  //Ogrenci &rS = selim;
  //rS.yaz();

  return 0;
}
double Ogrenci::OrtalamaBul(){
      return (ort = (as + fn) / 2.0);
    }
std::string Ogrenci::harfNotHesapla(){
      if(ort>=0 && ort<39){ harf = "FF";  }
      else if(ort<=45)    { harf = "DC";  }
      else if(ort<55)     { harf = "CC";  }
      else if(ort<65)     { harf = "CB";  }
      else if(ort<75)     { harf = "BB";  }
      else if(ort<85)     { harf = "BA";  }
      else if(ort<=100)   { harf = "AA";  }
      else                { harf = "G";   }
      return harf;
    }
    void Ogrenci::yaz(){
      std::cout 
                <<"Tramessi Oluşturuldu  "   
                <<std::setw(5) <<ad << " " <<soyad << "\t"
                << ders
                <<std::setw(5)<<as
                <<std::setw(5)<<fn
                <<std::fixed<<std::setprecision(2)
                <<std::setw(7)<<ort
                <<std::setw(4)<<harf
                <<std::endl;
    }
    void Ogrenci::setAS(int _as){
      as = _as;
    }
    void Ogrenci::setFN(int _fn){
      fn = _fn;  
    }
     void Ogrenci::setAdSoyad(std::string _ad,std::string _soyad){
      ad = _ad;
      soyad = _soyad;
    }

     void Ogrenci::setDers(std::string _ders){
      ders = _ders;
    }
    int Ogrenci::getAS(){

      return as;
    }

    int Ogrenci::getFN(){

      return fn;
    }

    std::string Ogrenci::getAdSoyad(){

      return ad;
      return soyad;
    }

    std::string Ogrenci::getDers(){

      return ders;
    }