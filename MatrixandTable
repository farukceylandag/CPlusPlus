#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <math.h>


using namespace std;


template <class M>
class Matrix {

protected:

    int satir ;
    int sutun ;
    M deger;
    int *elemanlist;
    char c;
    int **matris;

public:

    Matrix();
    Matrix(int _satir, int _sutun, int _deger);
    Matrix(int _satir, int _sutun, char _deger);
    void MatrixSet(int _satir, int _sutun,  int _deger);
    int MatrixGet(int _satir, int _sutun);
    void re_size(int _satir, int _sutun);
    void print();
    void print(string _file);
    Matrix<M> operator+(Matrix<int> x);
    Matrix<M> operator-(Matrix<int> x);
    Matrix<M> operator*(Matrix<int> x);
    Matrix<M> operator+(int _scaler);
    Matrix<M> operator-(int _scaler);
    Matrix<M> operator*(int _scaler);
    Matrix<M> operator/(int _scaler);
    Matrix<M> operator%(int _scaler);
    Matrix<M> operator^(int _scaler);
    void T();
    void emul(Matrix<int> *x);
	void inv();
    void det();


};

template <class M>
Matrix<M>::Matrix(){ //Constructor

    satir = 10;
    sutun = 10;
    deger = 0;
    elemanlist= new int [satir * sutun];
    for(int i = 0; i < satir; i++){
        for(int j = 0; j < sutun ; j++){
            elemanlist[i * sutun + j] = deger ;
        }
    }
}

template <class M>
Matrix<M>::Matrix(int _satir , int _sutun , int _deger){ //İnt Parametreli Constructor

    satir = _satir;
    sutun = _sutun;
    deger = _deger;
    elemanlist = new int [satir*sutun];
    for(int i = 0; i < satir; i++){
        for(int j = 0; j < sutun ; j++){
            elemanlist[i * sutun + j] = deger;
        }
    }
}

template <class M>
Matrix<M>::Matrix(int _satir , int _sutun , char _deger){ //Char Parametreli Constructor

    satir = _satir;
    sutun = _sutun;
    elemanlist = new int [satir*sutun];
    c = _deger;
    if(c == 'e' && satir == sutun){  //Birim Matris İse
        for(int i = 0; i < satir; i++){
            for(int j = 0; j < sutun ; j++){
                if(i==j){
                    deger = 1;
                    elemanlist[i * sutun + j] = deger;
                }
                else {
                    deger = 0;
                    elemanlist[i * sutun + j] = deger;
                }
            }
        }
    }
    else if(c == 'e' && satir != sutun){ //Satır ve Sutun Eşit Değilse

        cout << "\nBirim matris olabilmesi icin satir ve sutun birbirine esit olmalidir!\n" << endl;
        exit(0);
    }
    else if(c == 'r'){ //Random Değerli Matris

        srand(time(NULL));
        for(int i = 0; i < satir; i++){
            for(int j = 0; j < sutun ; j++){
                deger = rand() % 256;
                elemanlist[i * sutun + j] = deger;
            }
        }
    }
}

template <class M>
void Matrix<M>::MatrixSet(int _satir,int _sutun, int _deger){ //Setter

    elemanlist[_satir * sutun + _sutun] = deger;
}

template <class M>
int Matrix<M>::MatrixGet(int _satir,int _sutun){ //Getter

    return elemanlist[_satir * sutun + _sutun];
}

template <class M>
void Matrix<M>::re_size(int _satir , int _sutun){ //Yeniden Boyutlandırma

    satir = _satir;
    sutun = _sutun;
    elemanlist = new int [satir*sutun] ;
    if(c== 'e'){
        for(int i = 0; i < satir; i++){
            for(int j = 0; j < sutun ; j++){
                if(i==j){
                    elemanlist[i * sutun + j] = 1;
                }
                else elemanlist[i * sutun + j] = 0;
            }
        }
    }
    else if(c=='r'){
        srand(time(NULL));
        for(int i = 0; i < satir; i++){
            for(int j = 0; j < sutun ; j++){
                deger = rand() % 256;
                elemanlist[i * sutun + j] = deger;
            }
        }
    }
    else {
        for(int i = 0; i < satir; i++){
            for(int j = 0; j < sutun ; j++){
                elemanlist[i * sutun + j] = deger;
            }
        }
    }
}

template <class M>
void Matrix<M>::print(){ //Ekrana Yazdırma

    for(int i = 0; i < satir; i++){
        for(int j = 0; j < sutun ; j++){
            cout << setw(5) <<elemanlist[i*sutun +j] << setw(3);
        }
        cout << endl;
    }
}

template <class M>
void Matrix<M>::print(string _file){ //Ekrana Yazdırma

    ofstream dosya;
    dosya.open(_file.c_str());
    for(int i = 0; i < satir; i++){
        for(int j = 0; j < sutun ; j++){
            dosya << setw(5) << elemanlist[i*sutun +j] << setw(3);
        }
        dosya << endl;
    }
    dosya.close();
    cout << "\nDosyaya Yazıldı.\n"<<endl;
    exit(0);

}


//-------- Matris - Matris İşlemleri ------------//

template <class M>
Matrix<M> Matrix<M>::operator+(Matrix<int> x){ //Matrisleri Toplama

    Matrix<int> toplam;
    toplam.satir = satir;
    toplam.sutun = sutun;
    if(satir == x.satir && sutun == x.sutun){
        for(int i = 0; i < satir; i++){
            for(int j = 0; j < sutun ; j++){
                toplam.elemanlist[i*sutun+j] = elemanlist[i*sutun+ j] + x.elemanlist[i*sutun + j];
            }
        }
        return toplam;
    }
    else{
        cout << "\nBu Matrisler Toplanamaz!\n" << endl;
        exit(0);
    }
}

template <class M>
Matrix<M> Matrix<M>::operator-(Matrix<int> x){ //Matris Farkı

    Matrix<int> fark;
    fark.satir = satir;
    fark.sutun = sutun;
    if(satir == x.satir && sutun == x.sutun){
        for(int i = 0; i < satir; i++){
            for(int j = 0; j < sutun ; j++){
                fark.elemanlist[i*sutun+j] = elemanlist[i*sutun + j] - x.elemanlist[i*sutun + j];
            }
        }
        return fark;
    }
    else{
        cout << "\nBu Matrisler Çıkarılamaz!\n" << endl;
        exit(0);
    }
}

template <class M>
Matrix<M> Matrix<M>::operator*(Matrix<int> x){ //Matris Çarpımı

    Matrix<int> carpim;
    carpim.satir = satir;
    carpim.sutun = x.sutun;
    if(sutun == x.satir){
        for(int i = 0; i < satir; i++){
            for(int j = 0; j < x.sutun; j++){
                carpim.elemanlist[i*x.sutun+j] = 0;
                for(int k=0 ; k< sutun; k++){
                    carpim.elemanlist[i*x.sutun+j] += elemanlist[i*satir +k] * x.elemanlist[k*x.sutun+j];
                }
            }
        }
        return carpim;
    }
    else{
        cout << "\nBu Matrisler Çarpılamaz!\n" << endl;
        exit(0);
    }
}


//-------- Matris - Matris İşlemleri ------------//

template <class M>
Matrix<M> Matrix<M>::operator+(int _scaler){ //Matris-Skaler Toplamı

    Matrix<int> toplam;
    toplam.satir = satir;
    toplam.sutun = sutun;
    for(int i = 0; i < satir; i++){
        for(int j = 0; j < sutun ; j++){
            toplam.elemanlist[i*sutun+j] = elemanlist[i*sutun + j] + _scaler;
        }
    }
    return toplam;
}

template <class M>
Matrix<M> Matrix<M>::operator-(int _scaler){ //Matris - Skaler Fark

    Matrix<int> fark;
    fark.satir = satir;
    fark.sutun = sutun;
    for(int i = 0; i < satir; i++){
        for(int j = 0; j < sutun ; j++){
            fark.elemanlist[i*sutun+j] = elemanlist[i*sutun+ j] - _scaler;
        }
    }
    return fark;
}

template <class M>
Matrix<M> Matrix<M>::operator*(int _scaler){ //Matris - Skaler Çarpım

    Matrix<int> carpim;
    carpim.satir = satir;
    carpim.sutun = sutun;
    for(int i = 0; i < satir; i++){
        for(int j = 0; j < sutun ; j++){
            carpim.elemanlist[i*sutun+j] = elemanlist[i*sutun+ j] * _scaler;
        }
    }
    return carpim;
}

template <class M>
Matrix<M> Matrix<M>::operator/(int _scaler){ //Matris - Skaler Bölme

    Matrix<int> bolme;
    bolme.satir = satir;
    bolme.sutun = sutun;
    for(int i = 0; i < satir; i++){
        for(int j = 0; j < sutun ; j++){
            bolme.elemanlist[i*sutun+j] = elemanlist[i*sutun + j] / _scaler;
        }
    }
    return bolme;
}

template <class M>
Matrix<M> Matrix<M>::operator%(int _scaler){ //Matris - Skaler Mod

    Matrix<int> mod;
    mod.satir = satir;
    mod.sutun = sutun;
    for(int i = 0; i < satir; i++){
        for(int j = 0; j < sutun ; j++){
            mod.elemanlist[i*sutun+j] = elemanlist[i*sutun + j] % _scaler;
        }
    }
    return mod;
}

template <class M>
Matrix<M> Matrix<M>::operator^(int _scaler){ //Matris - Skaler Üs

    Matrix<int> power;
    power.satir = satir;
    power.sutun = sutun;
    for(int i = 0; i < satir; i++){
        for(int j = 0; j < sutun ; j++){
            power.elemanlist[i*sutun+j] = pow(elemanlist[i*sutun+ j],_scaler);
        }
    }
    return power;
}


//-------- Matris İşlemleri ------------//

template <class M>
void Matrix<M>::T(){ //Transpoz

    int temp;
    temp = satir;
    satir = sutun;
    sutun = temp;
    for(int i = 0; i < satir; i++){
        for(int j = 0; j < sutun ; j++){
            cout << elemanlist[i*sutun+j] << " ";
        }
    cout << endl;
    }
}

template <class M>
void Matrix<M>::emul(Matrix<int> *x){  //Eleman Düzeyinde Çarpma

    Matrix<int> emul;
    emul.satir = satir;
    emul.sutun = sutun;
    if(satir == x->satir && sutun == x->sutun){
        for(int i = 0; i < satir; i++){
            for(int j = 0; j < sutun ; j++){
                emul.elemanlist[i*sutun+j] = elemanlist[i*sutun + j] * x->elemanlist[i*sutun +j];
                cout << emul.elemanlist[i*sutun+j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "\nBu Matrisler Eleman Duzeyinde Carpilamaz!\n" << endl;
        exit(0);
    }
}

template <class M>
void Matrix<M>::inv(){

    int d;

    //Eşelon Matris

    for (int i = 0; i < satir; i++){
        for (int j = 0; j < 2 * sutun; j++){
            if (j == (i + satir)-1){
                elemanlist[i*sutun+j] = 1;
            }
        }
    }

    for (int i = satir; i >= 0; i--){
        if (elemanlist[(i-1)*sutun] < elemanlist[(i)*sutun]){
            for(int j = 0; j < sutun * 2; j++){
                d = elemanlist[i*sutun+j];
                elemanlist[i*sutun+j] = elemanlist[(i-1)*sutun+j];
                elemanlist[(i-1)*sutun+j] =d;
            }
        }
    }

        //Matrisin Tersi

    for (int i = 0; i < satir; i++){
        for (int j = 0; j < sutun * 2; j++){
            if (j != i){
            d = elemanlist[j*sutun+i] / elemanlist[i*sutun+i];
                for (int k = 0; k < sutun * 2; k++){
                    elemanlist[j*sutun+k] = elemanlist[j*sutun+k] - (elemanlist[i*sutun+k] * d);
                }
            }
        }
    }
    for(int i = 0; i < satir; i++){
        d=elemanlist[i*sutun+i];
        for (int j = 0; j < (sutun * 2); j++){
            elemanlist[i*sutun+j] = elemanlist[i*sutun+j] / d;
        }
    }
    cout<<"Matrisin Tersi\n"<<endl;

    for (int i = 0; i < satir; i++){
        for (int j = sutun; j < (sutun * 2); j++){
            cout<<setw(5) << elemanlist[i*sutun+j]<<setw(10);
        }
    cout<<endl;
    }
}

template <class M>
void Matrix<M>::det(){ //Determinant

    float oran,det;
    if(satir == sutun){
        for(int i=0;i<satir;i++){
            for(int j=0;j<sutun;j++){
                if(j>i){
                    oran = elemanlist[j*sutun+i] / elemanlist[i*sutun+i];
                    for(int k=0; k < satir;k++){
                        elemanlist[j*sutun+k] -= oran * elemanlist[i*sutun+k];;
                    }
                }
            }
        }
        det=1;
        for(int i=0;i <satir;i++){
            det *= elemanlist[i*sutun+i];
        }
        cout << "Determinant : "<< det;
    }
    else cout << "Determinantı Yoktur.!\n" << endl;
}


//  ----------- Table ------------ //


template <class M>
class Table :public Matrix<int> {

protected:
 string *row;
 string *col;

public:

    Table<M>() : Matrix<int>() {}
    Table<M>(int _satir,int _sutun,char _deger) : Matrix<int>(_satir,_sutun,_deger) {TableSet();}
    Table<M>(int _satir,int _sutun,int _deger) : Matrix<int>(_satir,_sutun,_deger) {TableSet();}
    void itemAt(int _satir,int _sutun);
    void itemAt(string s);
    void itemAt(string rs,string cs);
    void print();
    void TableSet();
    void setRowNames(string s[],int n);
    void setColNames(string s[],int n);


};

template <class M>
void Table<M>::itemAt(int _satir,int _sutun){  //Çağrılan Noktadaki Değeri Döndürür.

    matris = new int *[sutun];
    for(int i=0;i< satir;i++){
        matris[i] = new int[satir];
        for(int j=0;j<sutun;j++){
            matris[i][j] = elemanlist[i*sutun+j];
        }
    }
    if(satir == 0 || sutun ==0){
        cout << "Satir ve sutun degerleri 1'den başlamalidir." << endl;
    }
    else cout<< _satir+1<<".satır" <<" - " <<_sutun+1<< ".sutun : "<< matris[_satir][_sutun];
}

template <class M>
void Table<M>::itemAt(string rs,string cs){  //Verieln Stringe Göre Değer Döndürür.

    row = new string[satir];
	for(int i = 0; i < satir; i++)
		row[i] =  to_string(i);
    col = new string[sutun];
	for(int i = 0; i < sutun; i++)
		col[i] = (char)i+65;

    int _satir = rs[0]%48;
    int _sutun = cs[0]%65;

    for(int a=0;a<satir;a++){
        if(row[a] == rs){
            _satir=a;
        }
    }
    for(int b=0;b<satir;b++){
        if(col[b] == cs){
            _sutun=b;
        }
    }
    cout << elemanlist[_satir*sutun+_sutun];
}

template <class M>
void Table<M>::itemAt(string s){  //Tek Stringte Döndürür.

    int _satir =s[0]%65;
    int _sutun =s[1]%48;
    if(_satir <= satir &&  _sutun <= sutun){
        cout << elemanlist[_satir*sutun+_sutun];
    }
}

template <class M>
void Table<M>::print(){ //Ekrana Yazdırma


    cout << "  ";
    for(int i=0;i < sutun ;i++){
        cout << " "<<col[i] ;
    }
    cout <<"\n"<< endl;

    for(int j=0;j < satir ;j++){
        cout << row[j] << "  ";
        for(int k=0 ;k< sutun;k++){
            cout << elemanlist[j*sutun+k] << " " ;
        }
        cout << "  "<<endl;
    }
}

template <class M>
void Table<M>::TableSet(){

    row = new string[satir];
	for(int i = 0; i < satir; i++){
		row[i] =  to_string(i);
    }
	col = new string[sutun];
	for(int j = 0; j < sutun; j++){
		col[j] = (char)j+65;
    }
}

template <class M>
void Table<M>::setRowNames(string s[],int n){

    for(int j=0; j<n; j++){
         row[j] = s[j];
      }
}

template <class M>
void Table<M>::setColNames(string s[],int n){

    for(int j=0; j<n; j++){
         col[j] = s[j];
      }
}


int main() {

Table<int> *m1 = new Table<int>(7,6,'r');
Matrix<int> *m2 = new Matrix<int>(2,2,'r');

return 0;

}
