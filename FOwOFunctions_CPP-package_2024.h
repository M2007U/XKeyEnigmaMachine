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
#include <cmath>
#include <math.h>

using namespace std;

//----- vector -----

template <typename TYPE>
int FOwO_vector_FindObjPos(vector<TYPE> inVektor , TYPE Target , char Direction)
{
    //tries to return the position of the requested Object in the vector
    //if the object cannot be found, then return -1
    //direction can either be start from left 'l' or start from right 'r'

    int CurrentPos;
    bool Found = false;
    int Answer;

    if(Direction == 'l')
    {
        CurrentPos = 0;
        while(CurrentPos < inVektor.size() && Found == false )
        {
            if(inVektor[CurrentPos] == Target)
            {
                Found = true;
            }
            else
            {
                CurrentPos++;
            }
        }
    }
    else if (Direction == 'r')
    {
        CurrentPos = inVektor.size() - 1;
        while(CurrentPos > -1 && Found == false)
        {
            if(inVektor[CurrentPos] == Target)
            {
                Found = true;
            }
            else
            {
                CurrentPos--;
            }
        }
    }
    else
    {
        //nope
        Found = false;
    }

    if(Found == true)
    {
        Answer = CurrentPos;
    }
    else
    {
        Answer = -1;
    }

    return Answer;
}

template <typename TYPE>
vector<TYPE> FOwO_vector_remove_byIndex(vector<TYPE> inVektor , int Index)
{
    //remove an item from the vektor based on the 

    vector<TYPE> outVektor = {};
    int inVektorSize = inVektor.size();

    //-----

    if (inVektorSize == 0 || Index == inVektorSize || Index > inVektorSize ) //if the inVektor is empty, or index is out of range
    {
        
        outVektor = inVektor; //change nothing
    }
    else if (Index >= 0) //it is a normal acceptable index
    {
        
        for(int i = 0 ; i < inVektorSize ; i++)
        {
            if(i != Index)
            {
                outVektor.push_back( inVektor[i] ); //exclude the targeted index
            }
        }
    }
    else if (Index < 0) //if the index is negative
    {
        
        for(int i = 0 ; i < inVektorSize - 1 ; i++)
        {
            outVektor.push_back( inVektor[i] ); //exclude the last item
        }
    }

    //-----

    return outVektor;    
}

template <typename TYPE>
vector<TYPE> FOwO_vector_concat_bin(vector<TYPE> VektorL , vector<TYPE> VektorR)
{
    vector<TYPE> outVektor = {};

    outVektor = VektorL;

    for(int i = 0 ; i < VektorR.size() ; i++)
    {
        outVektor.push_back(VektorR[i]);
    }

    return outVektor;
}

template <typename TYPE>
vector<TYPE> FOwO_vector_cycleBelt(vector<TYPE> inVektor, char Direction, int step)
{
    //move the items in the vector like a conveyor belt

    //directions are : 
    // 'f' : front : (0) <- (1) <- (2) <- (3) ... (n), then send (0) to behind (n)
    // 'b' : back  : (0) -> (1) -> (3) -> (3) ... (n), then send (n) in front of (0)

    //step : how many iterations to send one object to the front/back

    int SafeStep = step % inVektor.size();

    vector<TYPE> VekL = {};
    vector<TYPE> VekR = {};
    vector<TYPE> VekO = {};

    for(int i = 0 ; i < inVektor.size() ; i++)
    {
        if(i < SafeStep)
        {
            VekL.push_back(inVektor[i]);
        }
        else
        {
            VekR.push_back(inVektor[i]);
        }
    }

    VekO = FOwO_vector_concat_bin(VekR, VekL);

    return VekO;
}

template <typename TYPE0, typename TYPE1>
vector<TYPE1> FOwO_vector_FunctionMap(vector<TYPE0> VektorIn , vector<TYPE1> VektorOut , TYPE0 ObjIn, TYPE1 ObjOutIfNull)
{
    int CurrentPos = 0;
    bool Found = false;
    TYPE1 returnResult;

    while(Found == false && CurrentPos < VektorIn.size())
    {
        if(VektorIn[CurrentPos] == ObjIn)
        {
            Found = true;
        }
        else
        {
            CurrentPos++;
        }
    }

    if(Found == false)
    {
        returnResult = ObjOutIfNull;
    }
    else
    {
        returnResult = VektorOut[CurrentPos];
    }

    return returnResult;
}





//----- cout -----






int FOwO_cout_MakeSpace(int Iter, string ExtraTitle)
{
    for(int i = 0; i < Iter ; i++)
    {
        cout << endl;
    }

    cout << ExtraTitle << endl;
    return Iter;
}

int FOwO_cout_Debug(bool DebugSwitch, string Message, bool NextLine)
{
    if(DebugSwitch == true)
    {
        if(NextLine == false)
        {
            cout << Message;
        }
        else
        {
            cout << Message << endl;
        }  
    }

    return 0;
}






//----- math -----





float FOwO_number_round (float Given, int mode)
{
    //mode :
    //0 : round near
    //1 : round down
    //2 : round up

    int Result = 0;
    int PartInt = (int)Given;
    float PartFrac = Given - PartInt;

    if(mode == 0)
    {
        //round near
        if(PartFrac < 0.5)
        {
            Result = PartInt;
        }
        else if(PartFrac >= 0.5)
        {
            Result = PartInt + 1;
        }
    }
    else if (mode == 1)
    {
        //round down
        Result = PartInt;
    }
    else if (mode == 2)
    {
        //round up
        if(PartFrac > 0)
        {
            Result = PartInt + 1;
        }
        else //PartFrac is 0
        {
            Result = PartInt;
        }
    }

    return Result;
}

template <typename T>
T FOwO_math_SumVector(vector<T> inVektor)
{
    //sum all numbers in the vector

    T returnResult = 0;
    for(int i = 0 ; i < inVektor.size() ; i++)
    {
        returnResult += inVektor[i];
    }

    return returnResult;
}

double FOwO_math_rootAprox(double input, float root, int iter)
{
    //try to guess the approximate root of a number

    double boxL;
    double boxR;
    double boxC;
    double boxF;

    for (int i = 0 ; i < iter ; i++)
    {
        boxC = (boxL + boxR) / 2;
        boxF = pow(boxC,root);

        if (boxF == input)
        {
            boxL = boxC;
            boxR = boxC;
            i = iter;
        }
        else if (boxF < input)
        {
            boxL = boxC;
        }
        else if (boxF > input)
        {
            boxR = boxC;
        }
    }

    return (boxL + boxR) / 2;
}   

int FOwO_math_DigitSum(long input)
{
    int Box = input;
    int Acu = 0;

    while (Box > 0)
    {
        Acu = Acu + Box % 10;
        Box = Box / 10;
    }

    return Acu;
}

int FOwO_math_isPrime(int x)
{
    double xRoot = sqrt((double)x);
    int nowTesting = 2;
    bool Quot;
    int ReturnResult = 404; // 0 : not prime, 1 : prime , 2 : zero or one, 9 : invalid
    bool FLAG_Done = false;

    if (x < 0)
    {
        ReturnResult = 9;
    }
    else if (x == 0 || x == 1)
    {
        ReturnResult = 2;
    }
    else
    {
        while(FLAG_Done == false)
        {
            if (nowTesting > xRoot)
            {
                ReturnResult = 1;
                FLAG_Done = true;
            }
            else
            {
                Quot = x % nowTesting == 0;
                if (Quot == true)
                {
                    ReturnResult = 0;
                    FLAG_Done = true;
                }
                else
                {
                    nowTesting = nowTesting + 1;
                }
            }
        }
    }

    return ReturnResult;
}

long FOwO_math_integerReverse(long x)
{
    long box0 = x;
    long box1 = 0;

    while (box0 > 0)
    {
        box1 = box1 + box0 % 10;
        box0 = box0 / 10;
        box1 = box1 * 10;
    }

    box1 = box1 / 10 ;

    return box1;
}





//----- bool and logics -----





int FOwO_bool_toInt(bool Given, int ResultIfFalse, int ResultIfTrue, int ResultIfNull)
{
    int ReturnValue;

    if(Given == false)
    {
        ReturnValue = ResultIfFalse;
    }
    else if(Given == true)
    {
        ReturnValue = ResultIfTrue;
    }
    else
    {
        ReturnValue = ResultIfNull;
    }

    return ReturnValue;
}

bool FOwO_bool_logic_simple(string Gate, bool Input0, bool Input1)
{
    bool Output;

    if (Gate == "not")
    {
        Output = !Input0;
    }
    else if (Gate == "or")
    {
        Output = Input0 || Input1;
    }
    else if (Gate == "and")
    {
        Output = Input0 && Input1;
    }
    else if (Gate == "xor")
    {
        if(Input0) //if Input0 is already true
        {
            Output = !Input1;
        }
        else if(!Input0) //if Input0 is false
        {
            Output = Input1;
        }
    }
    else
    {
        Output = Input0;
    }

    return Output;
}

bool FOwO_bool_logic_matrix(bool Out00, bool Out01, bool Out10, bool Out11, bool Input0, bool Input1)
{
    bool OutF;

    if      (Input0 == false && Input1 == false){OutF = Out00;}
    else if (Input0 == false && Input1 == true ){OutF = Out01;}
    else if (Input0 == true  && Input1 == false){OutF = Out10;}
    else if (Input0 == true  && Input1 == true ){OutF = Out11;}

    return OutF;
}

bool FOwO_Int_toBool(int Given, int IfThisThenFalse, int IfThisThenTrue)
{
    //DESC        : to convert an int, and fuction will return true or false based on the given input and user set condition
    //INPUT ARGS  : int Given (the bool to be tested), int IfThisThenFalse (if Given is this, return false), int IfThisThenTrue (if Given is this, then return true)

    bool ReturnValue;

    if(Given == IfThisThenFalse)
    {
        ReturnValue = false;
    }
    else if(Given == IfThisThenTrue)
    {
        ReturnValue = true;
    }
    //else, let it be null

    return ReturnValue;
}

template <typename TYPE>
TYPE FOwO_vector_MatrixCross(vector<TYPE> Table, int TableWidth, int inRow, int inCol, TYPE ReturnIfNull)
{
    int UserChoice = inRow * TableWidth + inCol;
    TYPE Answer;

    if (0 <= UserChoice && UserChoice < Table.size())
    {
        Answer = Table[UserChoice];
    }
    else
    {
        Answer = ReturnIfNull;
    }

    return Answer;
}



//----- strings and chars -----





string FOwO_char_type(char Input)
{
    //wierd
    //space
    //symbol
    //number
    //ltrUpper
    //ltrLower
    //DEL
    //idk
    
    int ASCIIval = (int)Input;
    string output;

    if(0 <= ASCIIval && ASCIIval <= 31 && ASCIIval != 9)
    {
        output = "wierd";
    }
    else if(ASCIIval == 9 || ASCIIval == 32 || ASCIIval == 10 || ASCIIval == 13) //if is tab ot space
    {
        output = "space";
    }
    else if
    (
        (21 <= ASCIIval && ASCIIval <= 47) || 
        (58 <= ASCIIval && ASCIIval <= 64) ||
        (91 <= ASCIIval && ASCIIval <= 96) ||
        (123 <= ASCIIval && ASCIIval <= 126)
    )
    {
        output = "symbol";
    }
    else if(48 <= ASCIIval && ASCIIval <= 57)
    {
        output = "number";
    }
    else if(65 <= ASCIIval && ASCIIval <= 90)
    {
        output = "ltrUpper";
    }
    else if(97 <= ASCIIval && ASCIIval <= 122)
    {
        output = "ltrLower";
    }
    else if(ASCIIval == 127)
    {
        output = "DEL";
    }
    else
    {
        output = "idk";
    }

    return output;

}

string FOwO_char_toString(char Kar)
{
    //turn the given charracter into a single charracter string
    string boxStr = "";
    boxStr += Kar;
    return boxStr;
}

void FOwO_string_PrintAscii(string input)
{
    //to print every charracter in a string as ascii numbers, except the \0 charracter
    for(int i = 0; i<input.length(); i++)
    {
        cout << "-(" << (int)(input.at(i)) << ")-";
    }
    cout << endl;
}

string FOwO_string_toUpper(string InString)
{
    string boxString = "";

    for(int i = 0 ; i < InString.length() ; i++)
    {
        char KarPass0 = InString.at(i);
        char KarPass1;

        if(97 <= (int)KarPass0 && (int)KarPass0 <= 122)
        {
            KarPass1 = (char)((int)KarPass0 - 32);
        }
        else
        {
            KarPass1 = KarPass0;
        }

        boxString += KarPass1;
    }

    return boxString;
}

string FOwO_string_toLower(string InString)
{
    string boxString = "";

    for(int i = 0 ; i < InString.length() ; i++)
    {
        char KarPass0 = InString.at(i);
        char KarPass1;

        if(65 <= (int)KarPass0 && (int)KarPass0 <= 90)
        {
            KarPass1 = (char)((int)KarPass0 + 32);
        }
        else
        {
            KarPass1 = KarPass0;
        }

        boxString += KarPass1;
    }

    return boxString;
}

string FOwO_string_forceCase(string InString, char mode)
{
    //mode :
    //'l' : lower
    //'u' : upper
    //'f' : formal

    string boxString = "";

    for(int i = 0 ; i < InString.length() ; i++)
    {
        char KarPass0 = InString.at(i);
        char KarPass1;

        if      (65 <= (int)KarPass0 && (int)KarPass0 <= 90 && ( mode == 'l' || mode == 'f' )) //if is Upper but want to become lower
        {
            KarPass1 = (char)((int)KarPass0 + 32); //make it lower
        }
        else if (97 <= (int)KarPass0 && (int)KarPass0 <= 122 && mode == 'u') //if is lower but want to become upper
        {
            KarPass1 = (char)((int)KarPass0 - 32); //make it upper
        }
        else
        {
            KarPass1 = KarPass0;
        }

        boxString += KarPass1;
    }

    //now fix formal
    if(mode == 'f')
    {
        boxString[0] = (char)((int)boxString.at(0) - 32);
    }

    return boxString;
}

int FOwO_string_FindCharPos(string InString, char Target, char Direction)
{
    int CurrentPos;
    bool Found = false;
    int Answer;

    if(Direction == 'l')
    {
        CurrentPos = 0;
        while(CurrentPos < InString.length() && Found == false )
        {
            if(InString.at(CurrentPos) == Target)
            {
                Found = true;
            }
            else
            {
                CurrentPos++;
            }
        }
    }
    else if (Direction == 'r')
    {
        CurrentPos = InString.length() - 1;
        while(CurrentPos > -1 && Found == false)
        {
            if(InString.at(CurrentPos) == Target)
            {
                Found = true;
            }
            else
            {
                CurrentPos--;
            }
        }
    }
    else
    {
        //nope
        Found = false;
    }

    if(Found == true)
    {
        Answer = CurrentPos;
    }
    else
    {
        Answer = -1;
    }

    return Answer;
}

bool FOwO_string_atPosIsChar(string TestSubject, int TargetPos, char TargetChar)
{
    //check if the given string, at the given position is the requested char
    //is yes, return true, else false

    bool ReturnResult;

    if(TestSubject == "")
    {
        ReturnResult = false;
    }
    else
    {
        if( (int)(TestSubject.at(TargetPos)) == (int)(TargetChar) )
        {
            ReturnResult = true;
        }
        else
        {
            ReturnResult = false;
        }
    }

    return ReturnResult;
}

string FOwO_string_trim(string InString, int start, int end)
{
    //returns a trimmed string of the given string
    //given the starting position and endding position
    if
    (
        (start < end || start == end) &&
        (0 <= start) &&
        (end < InString.length())
    )
    {
        string resultStr = "";

        for(int i = start ; i < InString.length() && i <= end ; i++)
        {
                resultStr += InString.at(i);
        }

        return resultStr;
    }
    else
    {
        //cout << "FQAQ : improper parameters : " << "String Length : " << InString.length() << " , start : " << start << " , end : " << end << endl;
        return "";
    }
}

int FOwO_string_isNumber_Simple(string TestSubject)
{
    //0 : not a number
    //1 : int
    //2 : float

    int Answer = -1;


    //string is completely empty ?
        //bruh ~ reject
    if(TestSubject == "")
    {
        Answer = 0;
        return Answer;
    }
    
    //string has other charracters ?
        //wth ? reject
    for(int i = 0 ; i < TestSubject.length() ; i++ )
    {
        if( (TestSubject.at(i) < '0' || '9' < TestSubject.at(i)) && TestSubject.at(i) != '.' )
        {
            Answer = 0;
            return Answer;
        }
    }

    string BoxString = TestSubject;
    //" ... 000 125 . 125 000 ..."
    //" ... 000 000 . 000 000 ..."
    //clean out leading zeros and backing zeros
    while(BoxString.at(0) == '0' && BoxString.length() > 1)
    {
        BoxString = FOwO_string_trim(BoxString,1,BoxString.length()-1);
    }

    while(BoxString.at(BoxString.length() - 1) == '0' && BoxString.length() > 1)
    {
        BoxString = FOwO_string_trim(BoxString,0,BoxString.length()-2);
    }

    //then check how many decimal points there are
    int DecimalPointCount = 0;
    for(int i = 0 ; i < BoxString.length() ; i++)
    {
        if(BoxString.at(i) == '.')
        {
            DecimalPointCount++;
        }
    }

    if(DecimalPointCount == 0) //none ? 
    {
        // string is not empty ?
                //it is an int
        //end up with empty string ? prolly we have "000 000" to start with
            //it is integer zero
        Answer = 1;
    }
    else if (DecimalPointCount == 1)
    {
        //one ? it is a real
        //if on the left of the decimal is completely empty, it is because the zero is being cleared, add one zero back on the left
        //but if on the right of the decimal is completely empty, the zeros are redundant, but this will be treated as a real, so add a zero back
        //end up with "." ? prolly we have "000 . 000" to start with
            //it is real / float zero
        Answer = 2;
    }
    else
    {
        //more than that ? invalid
        Answer = -404;
    }
        
    return Answer;
}

string FOwO_string_isNumber_Complex(string TestSubject)
{

    //  00000                   12500       .   00064       00000
    // |----------------------|----------|---|-----------|---------------------|
    // | reduntant zero front | int part | . | frac part | redundant zero back |

    // '0'.ascii = 48, '9'.ascii = 57

    bool FLAG_isNeg = false;
    string CurrentState = "STATE_Start";
    bool Kontinue = true;
    int readCursor = 0;
    char charBox;

    string PART_Head = "";
    string PART_ReduntZeroF = "";
    string PART_IntPart = "";
    string PART_FracPart = "";
    string PART_ReduntZeroB = "";

    string ReturnResult = "";

    while( Kontinue == true && readCursor < TestSubject.length())
    {
        charBox = TestSubject.at(readCursor);

        if (CurrentState == "STATE_Start")
        {
            if (charBox == '-')
            {
                PART_Head = "-";
                CurrentState = "STATE_RedundantZeroF";
                Kontinue = true;
            }
            else if (charBox == '0')
            {
                PART_ReduntZeroF = PART_ReduntZeroF + charBox;
                CurrentState = "STATE_RedundantZeroF";
                Kontinue = true;
            }
            else if (49 <= (int)charBox && (int)charBox <=57) //1..9
            {
                PART_IntPart = PART_IntPart + charBox;
                CurrentState = "STATE_IntPart";
                Kontinue = true;
            }
            else
            {
                CurrentState = "EmergencyHalt" ;
                Kontinue = false;
            }
        }
        else if (CurrentState == "STATE_RedundantZeroF")
        {
            if (charBox == '0')
            {
                PART_ReduntZeroF = PART_ReduntZeroF + charBox;
                CurrentState = "STATE_RedundantZeroF";
                Kontinue = true;
            }
            else if (49 <= (int)charBox && (int)charBox <=57) //1..9
            {
                PART_IntPart = PART_IntPart + charBox;
                CurrentState = "STATE_IntPart" ;
                Kontinue = true;
            }
            else if (charBox == '.')
            {
                CurrentState = "STATE_FracPart";
                Kontinue = true;
            }
            else
            {
                CurrentState = "EmergencyHalt" ;
                Kontinue = false;
            }
        }
        else if (CurrentState == "STATE_IntPart")
        {
            if (48 <= (int)charBox && (int)charBox <=57) // 0..9
            {
                PART_IntPart = PART_IntPart + charBox;
                CurrentState = "STATE_IntPart";
                Kontinue = true;
            }
            else if (charBox == '.')
            {
                CurrentState = "STATE_FracPart";
                Kontinue = true;
            }
            else
            {
                CurrentState = "EmergencyHalt";
                Kontinue = false;
            }
        }
        else if (CurrentState == "STATE_FracPart")
        {
            if (charBox == '0')
            {
                PART_ReduntZeroB = PART_ReduntZeroB + charBox;
                CurrentState = "STATE_RedundantZeroB";
                Kontinue = true;
            }
            else if (49 <= (int)charBox && (int)charBox <=57) // 1..9
            {
                PART_FracPart = PART_FracPart + charBox;
                CurrentState = "STATE_FracPart";
                Kontinue = true;
            }
            else
            {
                CurrentState = "EmergencyHalt";
                Kontinue = false;
            }
        }
        else if (CurrentState == "STATE_RedundantZeroB")
        {
            if (charBox == '0')
            {
                PART_ReduntZeroB = PART_ReduntZeroB + charBox;
                CurrentState = "STATE_RedundantZeroB";
                Kontinue = true;
            }
            else if (49 <= (int)charBox && (int)charBox <=57) // 1..9
            {
                PART_ReduntZeroB = PART_ReduntZeroB + charBox;
                PART_FracPart = PART_FracPart + PART_ReduntZeroB;
                PART_ReduntZeroB = "";
                CurrentState = "STATE_FracPart";
                Kontinue = true;
            }
            else
            {
                CurrentState = "EmergencyHalt";
                Kontinue = false;
            }
        }
        else if (CurrentState == "EmergencyHalt")
        {
            CurrentState = "EmergencyHalt";
            Kontinue = false;
        }

        
        readCursor++;
    }

    
    if (CurrentState == "EmergencyHalt")
    {
        ReturnResult = "Undef";
    }
    else
    {
        if (PART_Head == "-" )
        {
            ReturnResult = ReturnResult + "Neg";
        }
        else
        {
            ReturnResult = ReturnResult + "Pos";
        }

        if (PART_ReduntZeroF.length() > 0)
        {
            ReturnResult = ReturnResult + "Rzero";
        }

        if (PART_IntPart.length() > 0 && PART_FracPart.length() == 0)
        {
            //is Int
            ReturnResult = ReturnResult + "Int";
        }
        else if ((PART_IntPart == "0" || PART_IntPart == "" ) && PART_FracPart.length() > 0 )
        {
            //is Frac
            ReturnResult = ReturnResult + "Frac";
        }
        else if (PART_IntPart.length() > 0 && PART_FracPart.length() > 0 )
        {
            //if Float
            ReturnResult = ReturnResult + "Float";
        }

        if (PART_ReduntZeroB.length() > 0)
        {
            ReturnResult = ReturnResult + "Rzero";
        }
    }

   //cout << "[" << PART_Head << "] [" << PART_ReduntZeroF << "] [" << PART_IntPart << "] . [" << PART_FracPart << "] [" << PART_ReduntZeroB << "]" << endl;

    return ReturnResult;
}

bool FOwO_string_isHexaDc(string TestSubject)
{
    //it will return 1 if the given string can be interpreted as a hexadecimal number, 
    //else, 0

    string box1 = FOwO_string_forceCase(TestSubject, 'u');
    vector<char> OKchars = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int box2 = 404;

    bool ReturnResult = true; //assume it is true first

    for(int i = 0;i<TestSubject.length();i++)
    {
        if( FOwO_vector_FindObjPos<char>(OKchars,box1.at(i),'l') < 0 ) //it is not in the set
        {
            ReturnResult = false;
        }
    }

    return ReturnResult;
}

bool FOwO_string_isNaughtyEmpty(string InString)
{
    //if the string is entirely tabs or whitespace or newline or empty, then return true, else false
    bool Answer;

    if(InString == "")
    {
        //bruh
        Answer = true;
    }
    else
    {
        //assume it is true first
        Answer = true;

        //now check if it is false
        int CurrentPos = 0;
        while(CurrentPos < InString.length() && Answer == true)
        {
            if
            (
                InString.at(CurrentPos) != ' ' &&
                InString.at(CurrentPos) != '\n' &&
                InString.at(CurrentPos) != '\t'
            )
            {
                Answer = false;
            }
            else
            {
                CurrentPos++;
            }
        }

        //now the Answer holds the result;
    }

    return Answer;

}

string FOwO_string_vectorConcat(vector<string> inVector)
{
    string AnswerString = "";

    for(int i = 0 ; i < inVector.size() ; i++)
    {
        AnswerString = AnswerString + inVector[i];
    }

    return AnswerString;
}

string FOwO_string_subStringReplace(string input, string target, string change)
{
    //safe strings       //potential target strings, say "apple" // queue
    //PlateL             PlateM                                  PlateR
    //d7u5heappl         app              6<---                  5uf7dhejapple48r

    string output = "";
    string PlateL = "";
    string PlateM = "";
    string PlateR = input;

    if(input.length() < target.length() || input == "" || target == "")
    {
        output = "";
    }
    else
    {
        while(PlateR != "")
        {
            //flush, get from PlateR
            if(PlateR.length() == 1)
            {
                PlateM = PlateM + PlateR;
                PlateR = "";
            }
            else
            {
                PlateM = PlateM + FOwO_string_trim(PlateR,0,0);
                PlateR = FOwO_string_trim(PlateR,1,PlateR.length()-1);
            }

            //maintain length of PlateM
            if(PlateM.length() > target.length())
            {
                PlateL = PlateL + FOwO_string_trim(PlateM,0,0);
                PlateM = FOwO_string_trim(PlateM,1,PlateM.length()-1);
            }

            //does PlateM matches target ?
            if(PlateM == target)
            {
                PlateL = PlateL + change;
                PlateM = "";
            }
           
        }

        output = PlateL + PlateM; //there might be leftovers in PlateM
    }

    return output;
}

string FOwO_string_toAsciiDoubleHex(string input)
{
    //turns a given string into a string of ascii number,
    //each charracter will be interpreted as a 2 digit hexadicamal number
    
    stringstream Bwuffer;
    int boxInt = 0;
    string boxString = "";
    string Result = "";

    for(int i = 0 ; i < input.length() ; i++)
    {
        Bwuffer.clear();
        boxInt = (int)(input.at(i));
        Bwuffer << hex << boxInt;
        Bwuffer >> hex >> boxString >> dec;
        Bwuffer.clear();

        Result = Result + boxString;
    }

    return Result;
}

string FOwO_string_HexaSignExtend(string input, int size)
{
    //sign extends a hexadecimal number

    string Result = input;
    stringstream Bwuffer;
    int Box;
    Bwuffer.clear();
    Bwuffer << hex << input;
    Bwuffer >> Box;

    if(input.length() < size)
    {
        while( Result.length() < size )
        {
            if(Box > 0){Result = "0" + Result;}
            else if(Box < 0){Result = "f" + Result;}
            else if(Box == 0){Result = Result + "0";}
        }
    }
    else if(input.length() > size)
    {
        while(Result.length() > size && Result.length() != 0)
        {
            Result = FOwO_string_trim(Result,1,Result.length()-1);
        }
    }
    else if(input.length() == 0)
    {
        Result = "";
        for(int i = 0 ; i < size ; i++)
        {
            Result = Result + "0";
        }
    }

    return Result;

}

string FOwO_string_HexaSignExtend2(string input, int size)
{
    //sign extend
    
    string Result = input;

    if(input == "")
    {
        while(Result.length() < size)
        {
            Result = Result + "0";
        }
    }
    else if (FOwO_string_isHexaDc(input) == true)
    {
        
        int GetSign = -1;
        char BoxChar = input.at(0);

        if( (int)('0') <= (int)BoxChar && (int)BoxChar <= (int)('7') )
        {
            //it is a possitive number
            GetSign = 0;
        }
        else
        {
            //it is negative
            GetSign = 1;
        }

        while(Result.length() < size)
        {
            if(GetSign == 0)
            {
                Result = "0" + Result;
            }
            else
            {
                Result = "f" + Result;
            }
        }
    }
    else
    {
        Result = input;
    }

    return Result;
}

int FOwO_string_IslandCount(string Given, string& OutString)
{
    //count how many islands, i.e. word count
    //output a string without leading spaces and tailing spaces

    int IslandQty = -1;
    string Plate = Given;
    bool IsEmpty_CannotProcess = false;

    //check if the string is naughtyly empty, meaning only whitespace, tabs, newline only
    if(FOwO_string_isNaughtyEmpty(Given) == 0)
    {
        //ok, at least we have something to deal with...

        //trim away leading spaces
        while
        (
            (
                FOwO_string_atPosIsChar(Plate,0,' ') ||
                FOwO_string_atPosIsChar(Plate,0,'\t') ||
                FOwO_string_atPosIsChar(Plate,0,'\n')
            )
            &&
            (
                Plate.length() > 1
            )
        )
        {
            Plate = FOwO_string_trim(Plate,1,Plate.length()-1);
            //cout << "debug : cut head : \"" << Plate << "\"" << endl;
        }

        //trim away tailing spaces
        while
        (
            (
                FOwO_string_atPosIsChar(Plate,Plate.length()-1,' ') ||
                FOwO_string_atPosIsChar(Plate,Plate.length()-1,'\t') ||
                FOwO_string_atPosIsChar(Plate,Plate.length()-1,'\n')
            )
            &&
            (
                Plate.length() > 1
            )
        )
        {
            Plate.pop_back();
            //cout << "debug : cut tail : \"" << Plate << "\"" << endl;
        }

        //now we can start counting islands
        //Initiallize Arrow into the first charracter, which is a land already
        int Arrow = 0;
        bool IWasOnLand = true;
        IslandQty = 1;

        while(Arrow < Plate.length())
        {
            if(IWasOnLand == true)
            {
                if //I Hit Sea
                (
                    FOwO_string_atPosIsChar(Plate,Arrow,' ') ||
                    FOwO_string_atPosIsChar(Plate,Arrow,'\t') ||
                    FOwO_string_atPosIsChar(Plate,Arrow,'\n')
                )
                {
                    //Just went into sea
                    IWasOnLand = false;
                }
                else
                {
                    //I am still on Land
                    //then do nothing
                }
            }
            else //IWasOnSea
            {
                if //I Hit Sea
                (
                    FOwO_string_atPosIsChar(Plate,Arrow,' ') ||
                    FOwO_string_atPosIsChar(Plate,Arrow,'\t') ||
                    FOwO_string_atPosIsChar(Plate,Arrow,'\n')
                )
                {
                    //I am still on Sea
                }
                else
                {
                    //I Hit Land~, Island + 1
                    IWasOnLand = true;
                    IslandQty++;
                }
            }

            Arrow++;
        }

        OutString = Plate;


    }
    else
    {
        //duh... like no words here, so yeah, 0
        IslandQty = 0;
    }

    return IslandQty;
}

int FOwO_string_TargetCharCount(string Given, char Target)
{
    int result = 0;

    for(int i = 0 ; i < Given.length() ; i++)
    {
        if(Given.at(i) == Target)
        {
            result++;
        }
    }

    return result;
}

string FOwO_string_cycleBelt(string InString, int Step, char Direction)
{
    string StrL = "";
    string StrR = "";
    string StrO = "";

    for(int i = 0 ; i < InString.length() ; i++)
    {
        if(i < Step)
        {
            StrL += InString.at(i);
        }
        else
        {
            StrR += InString.at(i);
        }
    }

    StrO = StrR + StrL;

    return StrO;
}

int FOwO_string_Hash_int_20240229_1925 (string InString, int startNumber, int factor, int size)
{
    int Box = startNumber;

    for(int i = 0 ; i < InString.length() ; i++)
    {
        Box += (int)InString.at(i);
        Box *= factor;
    }

    Box = Box / factor;
    Box = Box % size;

    return Box;
}

string FOwO_string_vectorToSeperatedString(vector<string> inVector, string TokenLeftSide, string TokenRightSide, string TokenBetween)
{
    //turn a string like : _bp-2	:=	_bp+4	*	_bp+6
    //into something like : <_bp-2>	<:=>	<_bp+4>	<*>	<_bp+6>

    string Answer = "";

    if (inVector.size() > 0)
    {
        Answer = TokenLeftSide + inVector[0] + TokenRightSide;
        for (int i = 1 ; i < inVector.size() ; i++)
        {
            Answer = Answer + TokenBetween + TokenLeftSide + inVector[i] + TokenRightSide;
        }
    }
    else
    {
        Answer = "";
    }

    return Answer;
    
}

vector<string> FOwO_string_SeparateByChar (string Blob, char SeparateChar)
{
    //separate the string into elements in a vector, separated by the given charracter

    string Plate = Blob;
    vector<string> Answer;
    string Box = "";

    while(Plate.length() > 0)
    {
        if (Plate.at(0) != SeparateChar)
        {
            Box = Box + Plate.at(0);
            if (Plate.length() > 1)
            {
                Plate = FOwO_string_trim(Plate,1,Plate.length()-1);
            }
            else if (Plate.length() == 1)
            {
                Plate = "";
            }
        }
        else
        {
            Answer.push_back(Box);
            Box = "";

            if (Plate.length() > 1)
            {
                Plate = FOwO_string_trim(Plate,1,Plate.length()-1);
            }
            else if (Plate.length() == 1)
            {
                Plate = "";
            }
        }
    }

    if (Box.length())
    {
        Answer.push_back(Box);
    }

    return Answer;

}

/*
string FOwO_string_hash_20240228(string InString, char Direction , int mapSize, vector<int> PowerMultiply)
{
    const vector<char> STANDARD_CHAR = {
        'A','B','C','D','E','F','G','H',
        'I','J','K','L','M','N','O','P',
        'Q','R','S','T','U','V','W','X',
        'Y','Z','a','b','c','d','e','f',
        'g','h','i','j','k','l','m','n',
        'o','p','q','r','s','t','u','v',
        'w','x','y','z','0','1','2','3',
        '4','5','6','7','8','9'
    };

    const vector<int>  STANDARD_INT1 = {
        1,2,3,4,5,6,7,8,
        9,10,11,12,13,14,15,16,
        17,18,19,20,21,22,23,24,
        25,26,27,28,29,30,31,32,
        33,34,35,36,37,38,39,40,
        41,42,43,44,45,46,47,48,
        49,50,51,52,53,54,55,56,
        57,58,59,60,61,62
    };

    vector<int> PlateU = {};
    vector<int> PlateD = {};
    string PlateO = "";

    for(int i = 0 ; i < InString.length() ; i++)
    {
        PlateU.push_back((int)(InString.at(i)));

        FOwO_vector_FunctionMap()
    }

    //copy from U to D
    PlateD = PlateU;
    PlateU = FOwO_vector_cycleBelt(PlateU, Direction, 1);

    //power2 multiply
    //PlateU            = <0> <1> <2> <3> ... <n>
    //multiply          = <1> <2> <4> <8> ... <2^n>
    //add to PlateD
    for(int j = 0 ; j < PowerMultiply.size() ; j++)
    {
        for(int i = 0 ; i < PlateU.size() ; i++)
        {
            PlateD[i] = (PlateD[i] + PlateU[i] * (int)pow(PowerMultiply[j] ,i)) % mapSize;
        }
        PlateU = FOwO_vector_cycleBelt(PlateU, Direction, 1);
    }     




    

}
*/