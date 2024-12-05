#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <random>

#include "FOwOFunctions_CPP-package_2024.h"

using namespace std;

vector<int> OwOKEUtil_key_gen_swap(int chQty)
{
    random_device rand;  //get a random number from hardware
    mt19937 eng(rand()); //seed the generator
    uniform_int_distribution<>distr(0,chQty - 1); //set min and max

    vector<int> VektorInt = {};

    for(int i = 0 ; i < chQty ; i++)
    {
        VektorInt.push_back(i);
    }

    for(int i = 0 ; i < chQty ; i++)
    {
        int RandomChosenIndexA = distr(eng);
        int RandomChosenIndexB = distr(eng);
        int Box = VektorInt[RandomChosenIndexA];
        VektorInt[RandomChosenIndexA] = VektorInt[RandomChosenIndexB];
        VektorInt[RandomChosenIndexB] = Box;
    }

    return VektorInt;
}

vector<int> OwOKEUtil_key_gen_card(int chQty)
{
    random_device rand;  //get a random number from hardware
    mt19937 eng(rand()); //seed the generator
    uniform_int_distribution<>distr(0,chQty-1); //set min and max

    vector<int> VektorInt = {};
    vector<int> VektorDeckA = {};
    vector<int> VektorDeckB = {};

    for(int i = 0 ; i < chQty ; i++)
    {
        VektorInt.push_back(i);
    }

    for(int Z = 0 ; Z < chQty ; Z++)
    {
        for(int i = 0 ; i < chQty ; i++)
        {
            if (distr(eng) < chQty/2)
            {
                VektorDeckA.push_back(VektorInt[i]);
            }
            else
            {
                VektorDeckB.push_back(VektorInt[i]);
            }
        }

        VektorInt = FOwO_vector_concat_bin(VektorDeckA,VektorDeckB);
        VektorDeckA = {};
        VektorDeckB = {};
    }

    return VektorInt;
}