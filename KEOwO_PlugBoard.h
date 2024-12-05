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

class KEOwO_Plugboard
{
    public:

    int CharracterQty = 64;
    vector<int> LSide; //orderred number list
    vector<int> RSide; //jumbled up mess
    

    string PlugBoardName = "";

    KEOwO_Plugboard(int User_CharracterQty, string User_PlugBoardName)
    {
        PlugBoardName = User_PlugBoardName;

        CharracterQty = User_CharracterQty;
        for(int i = 0 ; i < CharracterQty ; i++ )
        {
            LSide.push_back(i);
            RSide.push_back(i);
        }
    }

    string PrintContent ()
    {
        return "LSide : " + PrintContentL() + "\n" + "RSide : " + PrintContentR();
    }

    string PrintContentL ()
    {
        string AnswerL = "";
        for(int i = 0 ; i < RSide.size() ; i++)
        {
            AnswerL = AnswerL + to_string(LSide[i]) + " ";
        }
        return AnswerL;
    }

    string PrintContentR ()
    {
        string AnswerR = "";
        for(int i = 0 ; i < RSide.size() ; i++)
        {
            AnswerR = AnswerR + to_string(RSide[i]) + " ";
        }
        return AnswerR;
    }

    

    void SetRSide (string Blob, char SeparateChar)
    {
        //Blob is going to be a comma separeted list
        if(FOwO_string_isNaughtyEmpty(Blob))
        {
            cout << "KEOwO_Plugboard : " + PlugBoardName + " : SetRSide : List contains white space, will not procede" << endl; 
        }
        else
        {
            //"1,2,3,4,5,6,7,8"
            //turn given string from User into a vector of strings
            vector<string> RSideList = FOwO_string_SeparateByChar(Blob,SeparateChar);

            //check if size of vector is the same as CharracterQty
            if(RSideList.size() != CharracterQty)
            {
                cout << "KEOwO_Rotor : " << PlugBoardName << " : SetRSide : Given List does not match with Charracter Quantity, Received Qty : " << RSideList.size() << endl;
            }
            else
            {
                vector<int> Answer = {};

                for(int i = 0 ; i < RSideList.size() ; i++)
                {
                    Answer.push_back(stoi(RSideList[i]));
                }

                RSide = Answer;
            }


        }
    }

    int SignalLtoR(int Input)
    {
        int InputSafe = Input % CharracterQty;
        //the given Input is a coordinate, not a label

        int Label = LSide[InputSafe];

        int curr = 0 ;

        while (RSide[curr] != Label && curr < CharracterQty)
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

    int SignalRtoL(int Input)
    {
        int InputSafe = Input % CharracterQty;
        //the given Input is a coordinate, not a label

        int Label = RSide[InputSafe];

        int curr = 0 ;

        while (LSide[curr] != Label && curr < CharracterQty)
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



};