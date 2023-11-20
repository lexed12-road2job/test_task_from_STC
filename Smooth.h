// STC_v1_1.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>


#include "math.h"
#include <stdio.h> 
#include <chrono>
#include "fstream"

void smooth(const double* input, double* output, const int n, const int window);
void smooth(const float* input, float* output, const int n, const int window);

double  productivity_time_measuring(const float* input, float* output, const int n, const int window);
double  productivity_time_measuring(const double* input, double* output, const int n, const int window);

double productivity_time_measuring(const float* input, float* output, const int n, const int window)
{
    
    auto start = std::chrono::steady_clock::now();
    smooth(input, output, n, window);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    
    std::cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;
    
    return std::chrono::duration <double, std::milli>(diff).count();
}
double productivity_time_measuring(const double* input, double* output, const int n, const int window)
{
    auto start = std::chrono::steady_clock::now();
    smooth(input, output, n, window);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    
    std::cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;

    return std::chrono::duration <double, std::milli>(diff).count();
   
}

void smooth(const double* input, double* output, const int n, const int window)
{
    const double wind_1 = pow(window, -1);

    double tmp = 0;

    for (int i = 0; i < window; i++)
    {
        tmp = tmp + input[i];                                   //Считаем среднее первого окна
    }
    output[0] = tmp * wind_1;

    for (int i = window; i <= n; i++)
    {
        output[i - window + 1] = output[i - window] +
            wind_1 * (input[i] - input[i - window]);            //Считаем среднее шагающего окна
    }
}
void smooth(const float* input, float* output, const int n, const int window)
{
    const float wind_1 = powf(window, -1); //находим обратное значение числа элементов окна для оптимизации деления

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

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
