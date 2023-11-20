#pragma once


#include "Smooth.h"




const int n_mass_storage = 5000000;


void fill_arrays(const int n_mass_storage, double* Arr1, float* Arr1_f) {
    
    srand(time(NULL));
    double num;
     float num1;
    for (int i = 0; i < n_mass_storage; i++)
    {
        num = rand() % 200 + 1;         // случайные числа от 0 до 200
        Arr1[i] = num;
        num1 = rand() % 200 + 1;        
        Arr1_f[i] = num1;
    }
}

void run(){
    
    double* Arr1;
    Arr1 = new double[n_mass_storage]; 
    srand(time(NULL));
    double num;

    double* Arr2;
    Arr2 = new double[n_mass_storage]; 

    float* Arr1_f;
    Arr1_f = new float[n_mass_storage]; 
    srand(time(NULL));
    float num1;

    float* Arr2_f;
    Arr2_f = new float[n_mass_storage]; 

    //------------------------------------------------------------------------------

    fill_arrays(n_mass_storage, Arr1, Arr1_f);
    
    //------------------------------------------------------------------------------
    std::ofstream fout;
    fout.open("excell.txt");
    for (int window_size = 4; window_size < 129; window_size *= 2)
    {
        fout << productivity_time_measuring(Arr1, Arr2, n_mass_storage, window_size) << '\t' << window_size << std::endl;
    }
    std::cout << "_________" << std::endl;
    for (int window_size = 4; window_size < 129; window_size *= 2)
    {
        fout << productivity_time_measuring(Arr1_f, Arr2_f, n_mass_storage, window_size) << '\t' << window_size << std::endl;      
    }

    fout.close();
    //------------------------------------------------------------------------------
    


    //------------------------------------------------------------------------------
    delete[]Arr1;
    delete[]Arr2;
    
}