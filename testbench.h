#pragma once

#include "SMA_aver_calc.h"

const int N_MASS_STORAGE = 5000000;
const int MIN_WINDOW_SIZE = 4;
const int MAX_WINDOW_SIZE = 128;

void fill_arrays(const int N_MASS_STORAGE, double* Arr1, float* Arr1_f) {
    
    srand(time(NULL));
    double num;
     float num1;
    for (int i = 0; i < N_MASS_STORAGE; i++)
    {
        num = rand() % 200 + 1;         // random numbers from 0 to 200
        Arr1[i] = num;
        num1 = rand() % 200 + 1;        
        Arr1_f[i] = num1;
    }
}

void run(){
    
    double* Arr1;
    Arr1 = new double[N_MASS_STORAGE]; 
    srand(time(NULL));
    double num;

    double* Arr2;
    Arr2 = new double[N_MASS_STORAGE]; 

    float* Arr1_f;
    Arr1_f = new float[N_MASS_STORAGE]; 
    float num1;

    float* Arr2_f;
    Arr2_f = new float[N_MASS_STORAGE]; 

    //------------------------------------------------------------------------------

    fill_arrays(N_MASS_STORAGE, Arr1, Arr1_f);
    
    //------------------------------------------------------------------------------
    std::ofstream fout;
    fout.open("excell.txt"); 
    
    //Filling in run-time values with a different window for double and float

    for (int window_size = MIN_WINDOW_SIZE; window_size <= MAX_WINDOW_SIZE; window_size *= 2)
    {
        fout << productivity_time_measuring(Arr1, Arr2, N_MASS_STORAGE, window_size) << '\t' << window_size << std::endl;
    }
    std::cout << "_________" << std::endl;
    for (int window_size = MIN_WINDOW_SIZE; window_size <= MAX_WINDOW_SIZE; window_size *= 2)
    {
        fout << productivity_time_measuring(Arr1_f, Arr2_f, N_MASS_STORAGE, window_size) << '\t' << window_size << std::endl;      
    }

    fout.close();
    //------------------------------------------------------------------------------
    
    delete[]Arr1;
    delete[]Arr2;
    delete[]Arr1_f;
    delete[]Arr2_f;
}