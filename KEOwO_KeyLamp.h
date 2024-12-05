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

#include "FOwOFunctions_CPP-package_2024.h"

class KEOwO_KeyLamp
{
    public:

    int CharracterQty = 64;
    vector<char> KSide; //Keyboard Vector
    vector<char> LSide; //LampBoard Vector
    

    string KeyLampName = "";

    KEOwO_KeyLamp
    (
        int User_CharracterQty, 
        string User_KeyLampName,
        string User_KSideList,
        string User_LSideList,
        char User_ListSeparatorChar
    )
    {
        KeyLampName = User_KeyLampName;
        CharracterQty = User_CharracterQty;
        
        SetKSide(User_KSideList,User_ListSeparatorChar);
        SetLSide(User_LSideList,User_ListSeparatorChar);
    }

    string PrintContent ()
    {
        return "KSide : \n" + PrintContentK() + "\n" + "LSide : \n" + PrintContentL();
    }

    string PrintContentK()
    {
        string AnswerK = "";

        for(int i = 0 ; i < KSide.size() ; i++)
        {
            AnswerK = AnswerK + to_string(i) + ":";
            AnswerK.push_back(KSide[i]);
            AnswerK = AnswerK + " ";
        }
        
        return AnswerK;
    }

    string PrintContentL()
    {
        string AnswerL = "";

        for(int i = 0 ; i < LSide.size() ; i++)
        {
            AnswerL = AnswerL + to_string(i) + ":";
            AnswerL.push_back(LSide[i]);
            AnswerL = AnswerL + " ";
        }

        return AnswerL;
    }



    void SetKSide (string Blob, char SeparateChar)
    {
        //Blob is going to be a comma separeted list
        if(FOwO_string_isNaughtyEmpty(Blob))
        {
            cout << "KEOwO_KeyLamp : " + KeyLampName + " : SetKSide : List contains white space, will not procede" << endl; 
        }
        else
        {
            //"1,2,3,4,5,6,7,8"
            //turn given string from User into a vector of strings
            vector<string> KSideList = FOwO_string_SeparateByChar(Blob,SeparateChar);

            //check if size of vector is the same as CharracterQty
            if(KSideList.size() != CharracterQty)
            {
                cout << "KEOwO_KeyLamp : " << KeyLampName << " : SetKSide : Given List does not match with Charracter Quantity, Received Qty : " << KSideList.size() << endl;
            }
            else
            {
                vector<char> Answer = {};

                for(int i = 0 ; i < KSideList.size() ; i++)
                {
                    Answer.push_back(KSideList[i].at(0));
                }

                KSide = Answer;
            }


        }
    }

    void SetLSide (string Blob, char SeparateChar)
    {
        //Blob is going to be a comma separeted list
        if(FOwO_string_isNaughtyEmpty(Blob))
        {
            cout << "KEOwO_KeyLamp : " + KeyLampName + " : SetLSide : List contains white space, will not procede" << endl; 
        }
        else
        {
            //"1,2,3,4,5,6,7,8"
            //turn given string from User into a vector of strings
            vector<string> LSideList = FOwO_string_SeparateByChar(Blob,SeparateChar);

            //check if size of vector is the same as CharracterQty
            if(LSideList.size() != CharracterQty)
            {
                cout << "KEOwO_KeyLamp : " << KeyLampName << " : SetKSide : Given List does not match with Charracter Quantity, Received Qty : " << LSideList.size() << endl;
            }
            else
            {
                vector<char> Answer = {};

                for(int i = 0 ; i < LSideList.size() ; i++)
                {
                    Answer.push_back(LSideList[i].at(0));
                }

                LSide = Answer;
            }


        }
    }

    
    int SignalKtoI(char Input)
    {
        int curr = 0 ;

        while (KSide[curr] != Input && curr < CharracterQty)
        {
            curr++;
        }

        int Answer = -1;

        if (curr < CharracterQty)
        {
            //found it
            Answer = curr;
        }
        else
        {
            //out of bounds
            Answer = -1;
        }

        return Answer;  
    }

    int SignalLtoI(char Input)
    {
        int curr = 0 ;

        while (LSide[curr] != Input && curr < CharracterQty)
        {
            curr++;
        }

        int Answer = -1;

        if (curr < CharracterQty)
        {
            //found it
            Answer = curr;
        }
        else
        {
            //out of bounds
            Answer = -1;
        }

        return Answer;  
    }



    char SignalItoL (int Input)
    {
        return LSide[Input];
    }

    char SignalItoK (int Input)
    {
        return KSide[Input];
    }



};
