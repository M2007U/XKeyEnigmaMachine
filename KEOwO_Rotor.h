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

#include "FOwOFunctions_2024.cpp"

class KEOwO_Rotor
{
    public:

    FOwO fowo;

    int CharracterQty = 64;
    vector<int> LSide; //orderred number list
    vector<int> RSide; //jumbled up mess
    int KickPoint = 63; //when to kick the next rotor

    string RotorName = "";

    KEOwO_Rotor(int User_CharracterQty, string User_RotorName)
    {
        RotorName = User_RotorName;
        ChangeCharracterQty(User_CharracterQty);
    }

    void ChangeCharracterQty(int InAmount)
    {
        CharracterQty = InAmount;
        KickPoint = CharracterQty - 1;
        LSide = {};
        RSide = {};
        for(int i = 0 ; i < CharracterQty ; i++ )
        {
            LSide.push_back(i);
            RSide.push_back(i);
        }
    }

    string PrintContent ()
    {
        return "LSide : " + PrintContentL() + "\n" + "RSide : " + PrintContentR() + "\n Kick  : " + to_string(KickPoint);
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

    int Rotate_ByAmount (int amount)
    {
        //rotates the rotor,
        //if it will kick another rotor because of the kick point,
        //if kick forward, return +1
        //if kick backward, return -1
        //else 0

        int needToKick = 0;

        for(int i = 0 ; i < amount ; i++)
        {
            //do this amount of times

            //do we need to kick ?
            if (LSide[0] == KickPoint)
            {
                if (amount < 0)
                {
                    needToKick = -1;
                }
                else if (amount > 0)
                {
                    needToKick = 1;
                }
            }

            if (amount < 0){ Rotate_ByOne(-1);}
            else if (amount > 0){ Rotate_ByOne(1); }
        }

        return needToKick;
    }

    void Rotate_ByOne(int Direction)
    {
        if (Direction == 1)
        {
            LSide = fowo.vectOwOr.cycleBelt(LSide,1);
            RSide = fowo.vectOwOr.cycleBelt(RSide,1);
        }
        else if (Direction == -1)
        {
            LSide = fowo.vectOwOr.cycleBelt(LSide, LSide.size()-2);
            RSide = fowo.vectOwOr.cycleBelt(RSide, RSide.size()-2);
        }
    }


    int GetPosition ()
    {
        return LSide[0];
    }

    int SetPosition (int User_Target)
    {
        int Target = User_Target;

        while(Target < 0)
        {
            Target = Target + CharracterQty;
        }

        while(Target >= CharracterQty)
        {
            Target = Target - CharracterQty;
        }

        int curr = 0;

        while(LSide[curr] != Target && curr < CharracterQty)
        {
            curr++;
        }

        if(curr < CharracterQty)
        {
            //found it
            //now curr will have the position of the target

            //       V
            // 5 6 7 8 9 0 1 2 3 4
            // 1 3 5 7 9 2 4 6 8 0

            Rotate_ByAmount(curr);

        }
        else
        {
            //out of bounds
            return -1;
        }

        return 0;

        
    }

    void SetRSide (string Blob, char SeparateChar)
    {
        //Blob is going to be a comma separeted list
        if( fowo.strOwOng.dOwOtect.isNaughtyEmpty(Blob) )
        {
            cout << "KEOwO_Rotor : " + RotorName + " : SetRSide : List contains white space, will not procede" << endl; 
        }
        else
        {
            //"1,2,3,4,5,6,7,8"
            //turn given string from User into a vector of strings
            vector<string> RSideList = fowo.strOwOng.mOwOnip.SeparateByChar(Blob,SeparateChar);

            //check if size of vector is the same as CharracterQty
            if(RSideList.size() != CharracterQty)
            {
                cout << "KEOwO_Rotor : " << RotorName << " : SetRSide : Given List does not match with Charracter Quantity, Received Qty : " << RSideList.size() << endl;
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

    void SetKickPoint (int Target)
    {
        KickPoint = Target;
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