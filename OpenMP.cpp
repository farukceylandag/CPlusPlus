#include <omp.h>
#include <ctime>
#include <iostream>

using namespace std;

#define N 1000
#define thread_num 8 

float A[N][N];
float B[N][N];
float C[N][N];

double D[N][N];
double E[N][N];
double F[N][N];

void matrix();

void float_matmul();
void float_parallel_matmul();

void double_matmul();
void double_parallel_matmul();

int i, j, k,counter;

int main()
{
    omp_set_num_threads(thread_num);
    cout << "\nThread Sayisi = " << omp_get_max_threads() << "\n" << endl;
    cout << N << "x" << N << " icin;\n----------------" << endl;
    float_matmul();
    float_parallel_matmul();
    cout << endl;
    double_matmul();
    double_parallel_matmul();
}

void matrix() {
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
        {
            A[i][j] = 1.0;
            B[i][j] = 1.0;
            D[i][j] = 1.0;
            E[i][j] = 1.0;  
        }
    }
}

void float_matmul() {
    
    matrix();
    clock_t start = clock(), finish;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    finish = clock();
    cout << "Float Seri Kosma Suresi = " << float(finish - start) / CLOCKS_PER_SEC << " sn" << endl;

    /*for (i= 0; i< N; i++){
         for (j= 0; j< N; j++){
             printf("%.1f\t",C[i][j]);
         }
         printf("\n");
     }*/
}

void float_parallel_matmul() {

    matrix();
    clock_t pstart = clock(), pend;
    #pragma omp parallel for private(i,j,k) shared(A,B,C)
        for (i =0; i < N; i++) {
            for (j = 0; j < N ; j++) {
                for (k = 0; k < N; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

    pend = clock();

   cout << "Float Paralel Kosma Suresi = " << (float(pend - pstart) / (CLOCKS_PER_SEC*thread_num)) << " sn" << endl;
}


void double_matmul() {
    
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

    /*for (i= 0; i< N; i++){
         for (j= 0; j< N; j++){
             printf("%.1f\t",F[i][j]);
         }
         printf("\n");
     }*/
}

void double_parallel_matmul() {
    
    matrix();
    clock_t pstart = clock(), pend;
    #pragma omp parallel for private(i,j,k) shared(D,E,F)
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