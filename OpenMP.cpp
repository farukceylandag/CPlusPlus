#include <omp.h> //OpenMP kütüphanesi
#include <ctime> //Süreleri oşup hesaplatmak için gerekli kütüphane
#include <iostream>

using namespace std;

#define N 1000 //NxN matris için gerekli büyüklüğünü tanımlama
#define thread_num 8 //Thread sayısı tanımlama

//Float Matrisler
float A[N][N];
float B[N][N];
float C[N][N];

//Double Matrisler
double D[N][N];
double E[N][N];
double F[N][N];

void matrix(); //Matris Fonk. Referans

void float_matmul(); //Float Seri Matris Çarpım Fonk. Referans
void float_parallel_matmul(); //Float Paralel Matris Çarpım Fonk. Referans

void double_matmul(); //Double Seri Matris Çarpım Fonk. Referans
void double_parallel_matmul(); //Double Paralel Matris Çarpım Fonk. Referans

int i, j, k;

int main()
{
    omp_set_num_threads(thread_num);  //Thread Sayısını Setleme.
    cout << "\nThread Sayisi = " << omp_get_max_threads() << "\n" << endl; //Setlenen Thread Sayısının Ekrena YAzılması
    cout << N << "x" << N << " icin;\n----------------" << endl;
    float_matmul(); //Float Seri Matris Çarpım Fonk. Çağırımı
    float_parallel_matmul(); //Float Paralel Matris Çarpım Fonk. Çağırımı
    cout << endl;
    double_matmul();  //Double Seri Matris Çarpım Fonk. Çağırımı
    double_parallel_matmul(); //Double Paralel Matris Çarpım Fonk. Çağırımı
}

void matrix() { //Matris Fonk.
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
        {
            A[i][j] = 1.0;
            B[i][j] = 1.0;
            D[i][j] = 1.0;
            E[i][j] = 1.0;  
        }
    }
    
    /*
    Burada çarpılacak olan matrislerin içini 1.0 değeriyle dolduruyoruz.
    */
}

void float_matmul() { //Float Seri Matris Çarpım Fonk.
    
    matrix(); //İçini 1.0 ile doldurduğumuz matris fonk. çağırıyoruz.
    clock_t start = clock(), finish; //Koşma Süresini başlatıyoruz.
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j]; //Float için matris çarpımlarını yaptık.
            }
        }
    }
    finish = clock(); //Koşma Süresini Bitiriyoruz.
    cout << "Float Seri Kosma Suresi = " << float(finish - start) / CLOCKS_PER_SEC << " sn" << endl;
    //Bitiş Süresinden Başlangıç Süresini çıkartıp float seri koşma süresini ekrana yazdırıyoruz.
}

void float_parallel_matmul() { //Float Paralel Matris Çarpım Fonk.

    matrix(); 
    clock_t pstart = clock(), pend; 
    //Yine serideki gibi içini doldurduğumuz matrislerimizi çekip paralel koşmak için süremizi başlatıyoruz.
    #pragma omp parallel for private(i,j,k) shared(A,B,C) //Paralel Koşmak için openMP kodu
    //Burada shared(A,B,C) = A,B,C matrislerini threadlere paylaştırmaya yarıyo.
        for (i =0; i < N; i++) {
            for (j = 0; j < N ; j++) {
                for (k = 0; k < N; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

    pend = clock();

   cout << "Float Paralel Kosma Suresi = " << (float(pend - pstart) / (CLOCKS_PER_SEC*thread_num)) << " sn" << endl;
    /*
    Serideki gibi yine koşma süresini hesapladık.Burada seriden tek farkı koşma süresini thread sayısına bölüp
    birbiriyle paralel koşan threadlerden bir tanesinin süresini erana yazdırmak.
   */
}


void double_matmul() { //Double Seri Matris Çarpım Fonk.
    
    //Float Seriyle aynı.Tek fark bu sefer yıkarıda tanımladığımız double matrisleri kullanıyoruz.
    matrix();
    clock_t start = clock(), finish;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                F[i][j] += D[i][k] * E[k][j];
            }
        }
    }
    finish = clock();
    cout << "Double Seri Kosma Suresi = " << float(finish - start) / CLOCKS_PER_SEC << " sn" << endl;
}

void double_parallel_matmul() { //Double Paralel Matris Çarpım Fonk.
    
    //Float Seriyle aynı.Tek fark bu sefer yıkarıda tanımladığımız double matrisleri kullanıyoruz.
    matrix();
    clock_t pstart = clock(), pend;
    #pragma omp parallel for private(i,j,k) shared(D,E,F) 
    //Bu sefer paylaşılan matrisler double veri tipli D , E, F matrisleri
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                for (k = 0; k < N; k++) {
                    F[i][j] += D[i][k] * E[k][j];   
                }
            }
        }

    pend = clock();

    cout << "Double Paralel Kosma Suresi = " << (float(pend - pstart) / (CLOCKS_PER_SEC* thread_num)) << " sn" << endl;
}
