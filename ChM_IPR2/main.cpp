
#include <stdio.h>
#include <iostream>
#include "math.h"
#include <fstream>
#include <iomanip>
#include <cstdlib> 
using namespace std;

//Якоби1
void yakobi1()
{
    double** Matrix;
    Matrix = new double*[3];
    for (int i = 0; i < 3; i++)
        Matrix[i] = new double[3];
    double* x = new double[3]; 
    ifstream arr("array.txt");
    cout << "Матрица:\n";
    while (!arr.eof())
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
               arr >> Matrix[i][j];
               cout << Matrix[i][j] << " ";
            }
            cout << endl;
        }
       
    }
    double b[3] = { -4.0, 7.2, -2.4 };
    for (int i = 0; i < 3; i++)
        x[i] = 0.0;



    double e;
    cout << "Точность eps=";
    cin >> e;
    double norm, * TempX = new double[3];

   
    int cnt = 0;

    do {
        for (int i = 0; i < 3; i++)
        {
            TempX[i] = b[i];
            for (int j = 0; j < 3; j++)
                if (i != j)
                    TempX[i] -= Matrix[i][j] * x[j];
            TempX[i] /= Matrix[i][i];
        }
        norm = abs(x[0] - TempX[0]);
        for (int h = 0; h < 3; h++)
        {
            if (abs(x[h] - TempX[h]) > norm)
                norm = abs(x[h] - TempX[h]);
            x[h] = TempX[h];
        }
        cnt++;
    } while (norm > e);
    cout << "Количество итераций = " << cnt << endl;
  
    delete[] TempX;
    cout << "Результат: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "x" << i + 1 << "=" <<setprecision(13)<< x[i] << endl;
    }
  
}

void zeydel1()
{
    double** Matrix;
    Matrix = new double* [3];
    for (int i = 0; i < 3; i++)
        Matrix[i] = new double[3];
    double* x = new double[3];
    ifstream arr("array.txt");
    cout << "Матрица:\n";
    while (!arr.eof())
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                arr >> Matrix[i][j];
                cout << Matrix[i][j] << " ";
            }
            cout << endl;
        }

    }
    double b[3] = { -4.0, 7.2, -2.4 };
    for (int i = 0; i < 3; i++)
        x[i] = 0.0;



    double e;
    cout << "Точность eps= ";
    cin >> e;
    double rez, norm, * TempX = new double[3];
    for (int k = 0; k < 3; k++)
        TempX[k] = x[k];
    int cnt = 0;
    
    do {
       
        for (int i = 0; i < 3; i++)
        {
            TempX[i] = b[i];

            for (int j = 0; j < 3; j++)
            {
                if (j < i)
                {
                    TempX[i] -= Matrix[i][j] * TempX[j];
                }
                if (j > i)
                {
                    TempX[i] -= Matrix[i][j] * x[j];
                }
                
            }
            TempX[i] /= Matrix[i][i];
        }
        norm = abs(x[0] - TempX[0]);
        for (int h = 0; h < 3; h++)
        {
            if (abs(x[h] - TempX[h]) > norm)
                norm = abs(x[h] - TempX[h]);
            x[h] = TempX[h];
        }
        cnt++;
    } while (norm > e);
    //  end = omp_get_wtime();
    cout << "Количество итераций = " << cnt << endl;
    //  printf_s("Затрачено %f сек\n", (end - start));
    delete[] TempX;
    cout << "Результат: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "x" << i + 1 << "=" << setprecision(13) << x[i] << endl;
    }
}

void zeydel2()
{
    setlocale(LC_ALL, "Rus");
    int n;
    cout << "Введите n=";
    cin >> n;
    double** Matrix, * b, * x;
    x = new double[n];
    b = new double[n];
    Matrix = new double* [n];
    for (int i = 0; i < n; i++)
        Matrix[i] = new double[n];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                Matrix[i-1][j-1] = 2 * n;
            if (i != j)
                Matrix[i-1][j-1] = 1;
            cout << Matrix[i-1][j-1] << " ";
        }
        b[i-1] = ((2 * n - 1) * i + n * (n + 1) / 2 + 12*n - 4);
        cout << b[i-1]<<endl;
    }
    for (int i = 0; i < n; i++)
        x[i] = 0.0;



    double e;
    cout << "Точность eps= ";
    cin >> e;
    double rez, norm, * TempX = new double[n];
   
    int cnt = 0;

    do
    {

        for (int i = 0; i < n; i++)
        {
            TempX[i] = b[i];

            for (int j = 0; j < n; j++)
            {
                if (j < i)
                {
                    TempX[i] -= Matrix[i][j] * TempX[j];
                }
                if (j > i)
                {
                    TempX[i] -= Matrix[i][j] * x[j];
                }

            }
            TempX[i] /= Matrix[i][i];
        }
        norm = abs(x[0] - TempX[0]);
        for (int h = 0; h < n; h++)
        {
            if (abs(x[h] - TempX[h]) > norm)
                norm = abs(x[h] - TempX[h]);
            x[h] = TempX[h];
        }
        cnt++;
    } while (norm > e);
    //  end = omp_get_wtime();
    cout << "Количество итераций = " << cnt << endl;
    //  printf_s("Затрачено %f сек\n", (end - start));
  
    cout << "Результат: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << "=" << setprecision(13) << x[i] << endl;
    }
}

void yakobi2()
{
    int n;
    cout << "Введите n=";
    cin >> n;
    double** Matrix, * b, * x;
    x = new double[n];
    b = new double[n];
    Matrix = new double* [n];
    for (int i = 0; i < n; i++)
        Matrix[i] = new double[n];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                Matrix[i - 1][j - 1] = 2 * n;
            if (i != j)
                Matrix[i - 1][j - 1] = 1;
            cout << Matrix[i - 1][j - 1] << " ";
        }
        b[i - 1] = ((2 * n - 1) * i + n * (n + 1) / 2 + 12 * n - 4);
        cout << b[i - 1] << endl;
    }
    for (int i = 0; i < n; i++)
        x[i] = 0.0;



    double e;
    cout << "Точность eps= ";
    cin >> e;
    double rez, norm, * TempX = new double[n];

    int cnt = 0;
    do {
        for (int i = 0; i < n; i++)
        {
            TempX[i] = b[i];
            for (int j = 0; j < n; j++)
                if (i != j)
                    TempX[i] -= Matrix[i][j] * x[j];
            TempX[i] /= Matrix[i][i];
        }
        norm = abs(x[0] - TempX[0]);
        for (int h = 0; h < n; h++)
        {
            if (abs(x[h] - TempX[h]) > norm)
                norm = abs(x[h] - TempX[h]);
            x[h] = TempX[h];
        }
        cnt++;
    } while (norm > e);
    cout << "Количество итераций = " << cnt << endl;

    delete[] TempX;
    cout << "Результат: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << "=" << setprecision(13) << x[i] << endl;
    }
}

int main(){
    setlocale(LC_ALL, "Rus");
    yakobi1();
    zeydel1();
}