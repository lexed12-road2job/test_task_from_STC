// STC_v1_1.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>


#include "math.h"
#include <stdio.h> 
#include <chrono>
#include "fstream"

void SMA_aver_calc(const double* input, double* output, const int n, const int window);
void SMA_aver_calc(const float* input, float* output, const int n, const int window);

double  productivity_time_measuring(const float* input, float* output, const int n, const int window);
double  productivity_time_measuring(const double* input, double* output, const int n, const int window);

double productivity_time_measuring(const float* input, float* output, const int n, const int window)
{
    
    auto start = std::chrono::steady_clock::now();
    SMA_aver_calc(input, output, n, window);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    
    std::cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;
    
    return std::chrono::duration <double, std::milli>(diff).count();
}
double productivity_time_measuring(const double* input, double* output, const int n, const int window)
{
    auto start = std::chrono::steady_clock::now();
    SMA_aver_calc(input, output, n, window);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    
    std::cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;

    return std::chrono::duration <double, std::milli>(diff).count();
   
}

void SMA_aver_calc(const double* input, double* output, const int n, const int window)
{
    const double wind_1 = pow(window, -1);

    double tmp = 0;

    for (int i = 0; i < window; i++)
    {
        tmp = tmp + input[i];                                   //Сalculate the average of the first window
    }
    output[0] = tmp * wind_1;

    for (int i = window; i <= n; i++)
    {
        output[i - window + 1] = output[i - window] +
            wind_1 * (input[i] - input[i - window]);            //We consider the average of the walking window
    }
}
void SMA_aver_calc(const float* input, float* output, const int n, const int window)
{
    const float wind_1 = powf(window, -1); //we find the inverse value of the number of window elements to optimize the division

    float tmp = 0;


    for (int i = 0; i < window; i++)
    {
        tmp = tmp + input[i];
    }
    output[0] = tmp * wind_1;

    for (int i = window; i <= n; i++)
    {
        output[i - window + 1] = output[i - window] +
            wind_1 * (input[i] - input[i - window]);
    }
}


