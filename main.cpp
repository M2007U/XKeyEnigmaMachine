/*
Kwazy Enigma OwO Machine / KEOwO
created by : XR_XharpRazor
department : Memo2007Ultra - Learn2016 - Academic2017 - Science2017 - ComputerScience2021
*/

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

#include "FOwOFunctions_2024.cpp"

#include "KEOwO_Rotor.h"
#include "KEOwO_PlugBoard.h"
#include "KEOwO_KeyLamp.h"
#include "KEOwO_Util.h"

using namespace std;

void printEnc (int R1, int R2, int R3, int R4, char C0, int N1, int N2, int N3, int N4, int N5, int N6, int N7, char C1)
{
    cout << "(";
    cout << setfill('0') << right << setw(2) << R1 << ",";
    cout << setfill('0') << right << setw(2) << R2 << ",";
    cout << setfill('0') << right << setw(2) << R3 << ",";
    cout << setfill('0') << right << setw(2) << R4 << ") : ";
    cout << setw(1) << setfill(' ') << C0 << " -K0> ";
    cout << setfill('0') << right << setw(2) << N1 << " -P1> " ;
    cout << setfill('0') << right << setw(2) << N2 << " -R1> " ;
    cout << setfill('0') << right << setw(2) << N3 << " -R2> " ;
    cout << setfill('0') << right << setw(2) << N4 << " -R3> " ;
    cout << setfill('0') << right << setw(2) << N5 << " -R4> " ;
    cout << setfill('0') << right << setw(2) << N6 << " -P1> " ;
    cout << setfill('0') << right << setw(2) << N7 << " -L0> " ;
    cout << setw(1) << setfill(' ') << C1;
    cout << endl;
}

void printDec (int R1, int R2, int R3, int R4, char C0, int N1, int N2, int N3, int N4, int N5, int N6, int N7, char C1)
{
    cout << "(";
    cout << setfill('0') << right << setw(2) << R1 << ",";
    cout << setfill('0') << right << setw(2) << R2 << ",";
    cout << setfill('0') << right << setw(2) << R3 << ",";
    cout << setfill('0') << right << setw(2) << R4 << ") : ";
    cout << setw(1) << setfill(' ') << C1 << " -L0> ";
    cout << setfill('0') << right << setw(2) << N7 << " -P2> " ;
    cout << setfill('0') << right << setw(2) << N6 << " -R4> " ;
    cout << setfill('0') << right << setw(2) << N5 << " -R3> " ;
    cout << setfill('0') << right << setw(2) << N4 << " -R2> " ;
    cout << setfill('0') << right << setw(2) << N3 << " -R1> " ;
    cout << setfill('0') << right << setw(2) << N2 << " -P1> " ;
    cout << setfill('0') << right << setw(2) << N1 << " -K0> " ;
    cout << setw(1) << setfill(' ') << C0;
    cout << endl;
}

bool charracterQtyCheck(int KL, int P1, int R1, int R2, int R3, int R4, int P2)
{
    if 
    ( KL == P1 && KL == R1 && KL == R2 && KL == R3 && KL == R4 && KL == P2 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main ()
{
    
    KEOwO_KeyLamp KL
    (
        64,
        "K1",
        "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z a b c d e f g h i j k l m n o p q r s t u v w x y z 0 1 2 3 4 5 6 7 8 9 , .",
        "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z a b c d e f g h i j k l m n o p q r s t u v w x y z 0 1 2 3 4 5 6 7 8 9 , .",
        ' '
    );
    KEOwO_Plugboard P1 (64,"P1");
    KEOwO_Rotor R1 (64,"R1");
    KEOwO_Rotor R2 (64,"R2");
    KEOwO_Rotor R3 (64,"R3");
    KEOwO_Rotor R4 (64,"R4");
    KEOwO_Plugboard P2 (64,"P1");


    
    

    char C0,C1;
    int N1,N2,N3,N4,N5,N6,N7;
    int R1pos, R2pos, R3pos, R4pos;

    FOwO fowo;

    string UserCommand = "";
    cout << "type \"help\" to get all the commands" << endl;
    cout << "\033[34m" << ">" << "\033[0m";

    while(UserCommand != "exit")
    {
        cout << fowo.strOwOng.shOwOrthand.ColorText("b") << ">";
        getline(cin,UserCommand);
        cout << fowo.strOwOng.shOwOrthand.ColorText("d");

        if (UserCommand != "exit")
        {

            if (UserCommand == "help")
            {
                cout << fowo.strOwOng.shOwOrthand.ColorText("g");
                cout << "start with typing the command :" << endl;
                cout << "h.m   : open the operating manual" << endl;
                cout << "h.i   : printing the concept hand book" << endl;
                cout << fowo.strOwOng.shOwOrthand.ColorText("d");
            }
            if (UserCommand == "h.m")
            {
                fstream OwOreader;
                OwOreader.open("KEOwO_help_manual.txt",ios::in);

                if(!OwOreader)
                {
                    cout << fowo.cOwOut.ConsoleQuick("error","failed to open manual, please reinstall the zip file") << endl;
                }
                else
                {
                    string stringBox = "";
                    while(getline(OwOreader,stringBox))
                    {
                        cout << fowo.strOwOng.shOwOrthand.ColorText("g");
                        cout << stringBox << endl;
                        cout << fowo.strOwOng.shOwOrthand.ColorText("d");
                    }
                }

                OwOreader.close();
            }
            if (UserCommand == "h.i")
            {
                fstream OwOreader;
                OwOreader.open("KEOwO_help_info.txt",ios::in);

                if(!OwOreader)
                {
                    cout << fowo.cOwOut.ConsoleQuick("error","failed to open manual, please reinstall the zip file") << endl;
                }
                else
                {
                    string stringBox = "";
                    while(getline(OwOreader,stringBox))
                    {
                        cout << fowo.strOwOng.shOwOrthand.ColorText("g");
                        cout << stringBox << endl;
                        cout << fowo.strOwOng.shOwOrthand.ColorText("d");
                    }
                }

                OwOreader.close();
            }
            else if (UserCommand == "chQty")
            {
                int UserInput;

                cout << fowo.cOwOut.ConsoleQuick("prompt","insert Character Quantity : ") ;
                cin >> UserInput;

                R1.ChangeCharracterQty(UserInput);
                R2.ChangeCharracterQty(UserInput);
                R3.ChangeCharracterQty(UserInput);
                R4.ChangeCharracterQty(UserInput);

                P1.ChangeCharracterQty(UserInput);
                P2.ChangeCharracterQty(UserInput);

                KL.CharracterQty = UserInput;
            }
            else if (UserCommand == "KL.sK")
            {
                cout << fowo.cOwOut.ConsoleQuick("prompt","insert content : ") ; 
                string KSideList; 
                getline(cin,KSideList);
                
                cout << fowo.cOwOut.ConsoleQuick("prompt","insert separation charracter"); 
                string SepaChar;
                getline(cin,SepaChar);

                if (KSideList.length() > 0 && SepaChar.length() > 0)
                {
                    KL.SetKSide(KSideList,SepaChar.at(0));
                }
            }
            else if (UserCommand == "KL.sL")
            {
                cout << fowo.cOwOut.ConsoleQuick("prompt","insert content : "); 
                string LSideList; 
                getline(cin,LSideList);
                
                cout << fowo.cOwOut.ConsoleQuick("prompt","insert separation charracter"); 
                string SepaChar;
                getline(cin,SepaChar);

                if (LSideList.length() > 0 && SepaChar.length() > 0)
                {
                    KL.SetLSide(LSideList,SepaChar.at(0));
                }
            }
            else if (fowo.vectOwOr.FindObjPos({"R1.sR.m","R2.sR.m","R3.sR.m","R4.sR.m"},UserCommand,'l') > -1 )
            {
                cout << fowo.cOwOut.ConsoleQuick("prompt","insert content : "); 
                string RSideList; 
                getline(cin,RSideList);
                
                cout << fowo.cOwOut.ConsoleQuick("prompt","insert separation charracter"); 
                string SepaChar;
                getline(cin,SepaChar);

                if (RSideList.length() > 0 && SepaChar.length() > 0)
                {
                    if      (UserCommand == "R1.sR.m"){ R1.SetRSide(RSideList,SepaChar.at(0)); }
                    else if (UserCommand == "R2.sR.m"){ R2.SetRSide(RSideList,SepaChar.at(0)); }
                    else if (UserCommand == "R3.sR.m"){ R3.SetRSide(RSideList,SepaChar.at(0)); }
                    else if (UserCommand == "R4.sR.m"){ R4.SetRSide(RSideList,SepaChar.at(0)); }
                }
                
            }
            else if (fowo.vectOwOr.FindObjPos({"R1.sR.r","R2.sR.r","R3.sR.r","R4.sR.r"},UserCommand,'l') > -1 )
            {
                cout << fowo.cOwOut.ConsoleQuick("prompt","choose a mode : \"card\" / \"swap\"") << endl;
                string UserInput = "";
                getline(cin,UserInput);

                int TempCharracterQty = 0;

                if      (UserCommand == "R1.sR.r"){TempCharracterQty = R1.CharracterQty;}
                else if (UserCommand == "R2.sR.r"){TempCharracterQty = R2.CharracterQty;}
                else if (UserCommand == "R3.sR.r"){TempCharracterQty = R3.CharracterQty;}
                else if (UserCommand == "R4.sR.r"){TempCharracterQty = R4.CharracterQty;}

                vector<int> VekInt = {};
                bool SafeToContinue = false;
                if (UserInput == "card" || UserInput == "c")
                {
                    VekInt = OwOKEUtil_key_gen_card(TempCharracterQty);
                    SafeToContinue = true;
                }
                else if (UserInput == "swap" || UserInput == "s")
                {
                    VekInt = OwOKEUtil_key_gen_swap(TempCharracterQty);
                    SafeToContinue = true;
                }
                else
                {
                    cout << fowo.cOwOut.ConsoleQuick("error","invalid choice") << endl;
                    SafeToContinue = false;
                }

                if (SafeToContinue)
                {
                    if      (UserCommand == "R1.sR.r"){R1.RSide = VekInt;}
                    else if (UserCommand == "R2.sR.r"){R2.RSide = VekInt;}
                    else if (UserCommand == "R3.sR.r"){R3.RSide = VekInt;}
                    else if (UserCommand == "R4.sR.r"){R4.RSide = VekInt;}
                }
            }
            else if (fowo.vectOwOr.FindObjPos({"R1.sK","R2.sK","R3.sK","R4.sK"},UserCommand,'l') > -1 )
            {
                int UserInput;
                cout << fowo.cOwOut.ConsoleQuick("prompt","set Kick Point :");
                cin >> UserInput;

                if      (UserCommand == "R1.sK"){R1.KickPoint = UserInput;}
                else if (UserCommand == "R2.sK"){R2.KickPoint = UserInput;}
                else if (UserCommand == "R3.sK"){R3.KickPoint = UserInput;}
                else if (UserCommand == "R4.sK"){R4.KickPoint = UserInput;}
            }
            else if ( UserCommand == "P1.sR.m" || UserCommand == "P2.sR.m" )
            {
                cout << fowo.cOwOut.ConsoleQuick("prompt","insert content : "); 
                string RSideList; 
                getline(cin,RSideList);
                
                cout << fowo.cOwOut.ConsoleQuick("prompt","insert separation charracter"); 
                string SepaChar;
                getline(cin,SepaChar);

                if (RSideList.length() > 0 && SepaChar.length() > 0)
                {
                    if      (UserCommand == "P1.sR.m"){P1.SetRSide(RSideList,SepaChar.at(0));}
                    else if (UserCommand == "P2.sR.m"){P2.SetRSide(RSideList,SepaChar.at(0));}
                }

            }
            else if (UserCommand == "P1.sR.r" || UserCommand == "P2.sR.r")
            {
                cout << fowo.cOwOut.ConsoleQuick("prompt","choose mode : card / swap") << endl;
                string UserInput = "";
                getline(cin,UserInput);

                int TempCharracterQty = 0;
                if      (UserCommand == "P1.sR.r"){ TempCharracterQty = P1.CharracterQty; }
                else if (UserCommand == "P2.sR.r"){ TempCharracterQty = P2.CharracterQty; }

                vector<int> VekInt = {};
                bool SafeToContinue = false;
                if (UserInput == "card")
                {
                    VekInt = OwOKEUtil_key_gen_card(TempCharracterQty);
                    SafeToContinue = true;
                }
                else if (UserInput == "swap")
                {
                    VekInt = OwOKEUtil_key_gen_swap(TempCharracterQty);
                    SafeToContinue = true;
                }
                else
                {
                    cout << fowo.cOwOut.ConsoleQuick("error","invalid choice") << endl;
                    SafeToContinue = false;
                }

                if (SafeToContinue)
                {
                    if      (UserCommand == "P1.sR.r"){P1.RSide = VekInt;}
                    else if (UserCommand == "P2.sR.r"){P2.RSide = VekInt;}
                }
            }
            else if (fowo.vectOwOr.FindObjPos({"R1.r","R2.r","R3.r","R4.r"},UserCommand,'l') > -1 )
            {
                string TempName = "";
                if      (UserCommand == "R1.r"){TempName = "R1";}
                else if (UserCommand == "R2.r"){TempName = "R2";}
                else if (UserCommand == "R3.r"){TempName = "R3";}
                else if (UserCommand == "R4.r"){TempName = "R4";}

                int UserInput;
                cout << fowo.cOwOut.ConsoleQuick("prompt","rotate rotor " + TempName + " by units : ");
                cin >> UserInput;

                if      (UserCommand == "R1.r"){R1.Rotate_ByAmount(UserInput);}
                else if (UserCommand == "R2.r"){R2.Rotate_ByAmount(UserInput);}
                else if (UserCommand == "R3.r"){R3.Rotate_ByAmount(UserInput);}
                else if (UserCommand == "R4.r"){R4.Rotate_ByAmount(UserInput);}
            }
            else if (UserCommand == "RA.sP")
            {
                cout << fowo.cOwOut.ConsoleQuick("prompt","R1 pos ? : ");
                cin >> R1pos;
                cout << fowo.cOwOut.ConsoleQuick("prompt","R2 pos ? : ");
                cin >> R2pos;
                cout << fowo.cOwOut.ConsoleQuick("prompt","R3 pos ? : ");
                cin >> R3pos;
                cout << fowo.cOwOut.ConsoleQuick("prompt","R4 pos ? : ");
                cin >> R4pos;
                cin.ignore();

                R1.SetPosition(R1pos);
                R2.SetPosition(R2pos);
                R3.SetPosition(R3pos);
                R4.SetPosition(R4pos);
            }
            else if (fowo.vectOwOr.FindObjPos({"KL.p","R1.p","R2.p","R3.p","R4.p","RA.p","P1.p","P2.p"},UserCommand,'l') > -1)
            {
                cout << fowo.strOwOng.shOwOrthand.ColorText("g");
                
                if (UserCommand == "KL.p")
                {
                    cout << KL.PrintContent() << endl;
                }
                else if (UserCommand == "R1.p")
                {
                    cout << R1.PrintContent() << endl;
                }
                else if (UserCommand == "R2.p")
                {
                    cout << R2.PrintContent() << endl;
                }
                else if (UserCommand == "R3.p")
                {
                    cout << R3.PrintContent() << endl;
                }
                else if (UserCommand == "R4.p")
                {
                    cout << R4.PrintContent() << endl;
                }
                else if (UserCommand == "RA.p")
                {
                    cout <<"R1pos : ("<< setfill('0') << setw(2) << right << R1.GetPosition() << ") : " << R1.PrintContentR() << endl;
                    cout <<"R2pos : ("<< setfill('0') << setw(2) << right << R2.GetPosition() << ") : " << R2.PrintContentR() << endl;
                    cout <<"R3pos : ("<< setfill('0') << setw(2) << right << R3.GetPosition() << ") : " << R3.PrintContentR() << endl;
                    cout <<"R4pos : ("<< setfill('0') << setw(2) << right << R4.GetPosition() << ") : " << R4.PrintContentR() << endl;
                }
                else if (UserCommand == "P1.p")
                {
                    cout << P1.PrintContent() << endl;
                }
                else if (UserCommand == "P2.p")
                {
                    cout << P2.PrintContent() << endl;
                }

                cout << fowo.strOwOng.shOwOrthand.ColorText("d");
            }
            else if (UserCommand == "key.print")
            {
                int TempR1pos = R1.GetPosition();
                int TempR2pos = R2.GetPosition();
                int TempR3pos = R3.GetPosition();
                int TempR4pos = R4.GetPosition();

                R1.SetPosition(0);
                R2.SetPosition(0);
                R3.SetPosition(0);
                R4.SetPosition(0);

                cout << fowo.strOwOng.shOwOrthand.ColorText("g");
                cout << "Machine Settings : " << endl;
                cout << endl;
                cout << "Keyboard : " << endl;
                cout << KL.PrintContent() << endl;
                cout << endl;
                cout << "Plugboard 1 : " << endl;
                cout << P1.PrintContentR() << endl;
                cout << endl;
                cout << "Rotors : (Position) : RSide Wiring" << endl;
                cout << "R1 : (" << setfill('0') << setw(2) << right << TempR1pos << ") : " << R1.PrintContentR() << endl;
                cout << "R2 : (" << setfill('0') << setw(2) << right << TempR2pos << ") : " << R2.PrintContentR() << endl;
                cout << "R3 : (" << setfill('0') << setw(2) << right << TempR3pos << ") : " << R3.PrintContentR() << endl;
                cout << "R4 : (" << setfill('0') << setw(2) << right << TempR4pos << ") : " << R4.PrintContentR() << endl;
                cout << endl;
                cout << "Plugboard 2 : " << endl;
                cout << P2.PrintContentR() << endl;
                cout << endl;
                cout << fowo.strOwOng.shOwOrthand.ColorText("d");

                R1.SetPosition(TempR1pos);
                R2.SetPosition(TempR2pos);
                R3.SetPosition(TempR3pos);
                R4.SetPosition(TempR4pos);
            }
            else if (UserCommand == "key.gen.swap")
            {
                vector<int> VekInt = OwOKEUtil_key_gen_swap(R1.CharracterQty);
                string Ans = "";

                for(int i = 0 ; i < R1.CharracterQty ; i++)
                {
                    Ans = Ans + to_string(VekInt[i]) + ",";
                }

                Ans.pop_back();

                cout << fowo.strOwOng.shOwOrthand.ColorText("g") << Ans << fowo.strOwOng.shOwOrthand.ColorText("d") << endl;
            }
            else if (UserCommand == "key.gen.card")
            {
                vector<int> VekInt = OwOKEUtil_key_gen_card(R1.CharracterQty);
                string Ans = "";

                for(int i = 0 ; i < R1.CharracterQty ; i++)
                {
                    Ans =  Ans + to_string(VekInt[i]) + ",";
                }

                Ans.pop_back();

                cout << fowo.strOwOng.shOwOrthand.ColorText("g") << Ans << fowo.strOwOng.shOwOrthand.ColorText("d") << endl;
            }
            else if (UserCommand == "enc.c")
            {

                if(charracterQtyCheck(KL.CharracterQty, P1.CharracterQty, R1.CharracterQty, R2.CharracterQty, R3.CharracterQty, R4.CharracterQty, P2.CharracterQty))
                {
                    string UserInsert = "A";
                    while(UserInsert != "done")
                    {
                        getline(cin,UserInsert);

                        if(UserInsert != "done")
                        {
                            C0 = UserInsert.at(0);

                            N1 = KL.SignalKtoI(C0);
                            N2 = P1.SignalLtoR(N1);
                            N3 = R1.SignalLtoR(N2);
                            N4 = R2.SignalLtoR(N3);
                            N5 = R3.SignalLtoR(N4);
                            N6 = R4.SignalLtoR(N5);
                            N7 = P2.SignalLtoR(N6);

                            C1 = KL.SignalItoL(N7);

                            cout << fowo.strOwOng.shOwOrthand.ColorText("g");
                            printEnc(R1.GetPosition(), R2.GetPosition(), R3.GetPosition(), R4.GetPosition(), C0, N1, N2, N3, N4, N5, N6, N7, C1);
                            cout << fowo.strOwOng.shOwOrthand.ColorText("d");
                            //kick the rotors

                            int needToKickR3 = R4.Rotate_ByAmount(1);
                            int needToKickR2 = R3.Rotate_ByAmount(needToKickR3);
                            int needToKickR1 = R2.Rotate_ByAmount(needToKickR2);
                            R1.Rotate_ByAmount(needToKickR1);

                        }

                        

                    }
                }
                else
                {
                    cout << "KEQAQ : Charracter Quantities between KeyBoard/LampBoard and Rotors and Plugboard do not match, will not encrypt" << endl;
                }  
            }
            else if (UserCommand == "enc.s")
            {

                if(charracterQtyCheck(KL.CharracterQty, P1.CharracterQty, R1.CharracterQty, R2.CharracterQty, R3.CharracterQty, R4.CharracterQty, P2.CharracterQty))
                {
                    string UserInput = "";
                    string OutputString = "";
                    cout << fowo.cOwOut.ConsoleQuick("prompt","insert plaintext : ");
                    getline(cin,UserInput);

                    for(int i = 0 ; i < UserInput.length() ; i++)
                    {
                        C0 = UserInput.at(i);

                        N1 = KL.SignalKtoI(C0);
                        N2 = P1.SignalLtoR(N1);
                        N3 = R1.SignalLtoR(N2);
                        N4 = R2.SignalLtoR(N3);
                        N5 = R3.SignalLtoR(N4);
                        N6 = R4.SignalLtoR(N5);
                        N7 = P2.SignalLtoR(N6);

                        C1 = KL.SignalItoL(N7);
                        
                        cout << fowo.strOwOng.shOwOrthand.ColorText("g");
                        printEnc(R1.GetPosition(), R2.GetPosition(), R3.GetPosition(), R4.GetPosition(), C0, N1, N2, N3, N4, N5, N6, N7, C1);
                        cout << fowo.strOwOng.shOwOrthand.ColorText("d");

                        OutputString.push_back(C1);

                        //kick the rotors
                        int needToKickR3 = R4.Rotate_ByAmount(1);
                        int needToKickR2 = R3.Rotate_ByAmount(needToKickR3);
                        int needToKickR1 = R2.Rotate_ByAmount(needToKickR2);
                        R1.Rotate_ByAmount(needToKickR1);


                    }
                    
                    cout << fowo.strOwOng.shOwOrthand.ColorText("g") << "output ciphertext : " << OutputString << fowo.strOwOng.shOwOrthand.ColorText("d") << endl;
                }
                else
                {
                    cout << fowo.cOwOut.ConsoleQuick("error","Charracter Quantities between KeyBoard/LampBoard and Rotors and Plugboard do not match, will not encrypt") << endl;
                }   
            }
            else if (UserCommand == "dec.c")
            {
                if (charracterQtyCheck(KL.CharracterQty, P1.CharracterQty, R1.CharracterQty, R2.CharracterQty, R3.CharracterQty, R4.CharracterQty, P2.CharracterQty))
                {
                    string UserInsert = "A";
                    while(UserInsert != "done")
                    {
                        getline(cin,UserInsert);

                        if (UserInsert != "done")
                        {
                            C1 = UserInsert.at(0);

                            N7 = KL.SignalLtoI(C1);
                            N6 = P2.SignalRtoL(N7);
                            N5 = R4.SignalRtoL(N6);
                            N4 = R3.SignalRtoL(N5);
                            N3 = R2.SignalRtoL(N4);
                            N2 = R1.SignalRtoL(N3);
                            N1 = P1.SignalRtoL(N2);
                            C0 = KL.SignalItoK(N1);

                            cout << fowo.strOwOng.shOwOrthand.ColorText("g");
                            printDec(R1.GetPosition(), R2.GetPosition(), R3.GetPosition(), R4.GetPosition(), C0, N1, N2, N3, N4, N5, N6, N7, C1);
                            cout << fowo.strOwOng.shOwOrthand.ColorText("d");

                            //kick the rotors
                            int needToKickR3 = R4.Rotate_ByAmount(1);
                            int needToKickR2 = R3.Rotate_ByAmount(needToKickR3);
                            int needToKickR1 = R2.Rotate_ByAmount(needToKickR2);
                            R1.Rotate_ByAmount(needToKickR1);
                        }

                        

                    }
                }
                else
                {
                    cout << fowo.cOwOut.ConsoleQuick("error","Charracter Quantities between KeyBoard/LampBoard and Rotors and Plugboard do not match, will not decrypt") << endl;
                }

                
                
            }
            else if (UserCommand == "dec.s")
            {
                if (charracterQtyCheck(KL.CharracterQty, P1.CharracterQty, R1.CharracterQty, R2.CharracterQty, R3.CharracterQty, R4.CharracterQty, P2.CharracterQty))
                {
                    string UserInput = "";
                    string OutputString = "";
                    cout << fowo.cOwOut.ConsoleQuick("prompt","insert ciphertext : ");
                    getline(cin,UserInput);

                    for(int i = 0 ; i < UserInput.length() ; i++)
                    {
                        C1 = UserInput.at(i);

                        N7 = KL.SignalLtoI(C1);
                        N6 = P2.SignalRtoL(N7);
                        N5 = R4.SignalRtoL(N6);
                        N4 = R3.SignalRtoL(N5);
                        N3 = R2.SignalRtoL(N4);
                        N2 = R1.SignalRtoL(N3);
                        N1 = P1.SignalRtoL(N2);
                        C0 = KL.SignalItoK(N1);

                        cout << fowo.strOwOng.shOwOrthand.ColorText("g");
                        printDec(R1.GetPosition(), R2.GetPosition(), R3.GetPosition(), R4.GetPosition(), C0, N1, N2, N3, N4, N5, N6, N7, C1);
                        cout << fowo.strOwOng.shOwOrthand.ColorText("d");

                        OutputString.push_back(C0);

                        //kick the rotors

                        int needToKickR3 = R4.Rotate_ByAmount(1);
                        int needToKickR2 = R3.Rotate_ByAmount(needToKickR3);
                        int needToKickR1 = R2.Rotate_ByAmount(needToKickR2);
                        R1.Rotate_ByAmount(needToKickR1);
                    }

                    cout << fowo.strOwOng.shOwOrthand.ColorText("g");
                    cout << "output plaintext : " << OutputString << endl;
                    cout << fowo.strOwOng.shOwOrthand.ColorText("d");
                }
                else
                {
                    cout << fowo.cOwOut.ConsoleQuick("error","Charracter Quantities between KeyBoard/LampBoard and Rotors and Plugboard do not match, will not decrypt") << endl;
                }

                
            }
            else if (UserCommand == "ld.64")
            {
                cout << fowo.strOwOng.shOwOrthand.ColorText("g");
                cout << "here are some string contents : " << endl;
                cout << "63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 //reverse" << endl << endl;
                cout << "0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,63,61,59,57,55,53,51,49,47,45,43,41,39,37,35,33,31,29,27,25,23,21,19,17,15,13,11,9,7,5,3,1 //jump hill" << endl << endl;
                cout << "0,32,1,33,2,34,3,35,4,36,5,37,6,38,7,39,8,40,9,41,10,42,11,43,12,44,13,45,14,46,15,47,16,48,17,49,18,50,19,51,20,52,21,53,22,54,23,55,24,56,25,57,26,58,27,59,28,60,29,61,30,62,31,63 //comb" << endl << endl;
                cout << "0,63,1,62,2,61,3,60,4,59,5,58,6,57,7,56,8,55,9,54,10,53,11,52,12,51,13,50,14,49,15,48,16,47,17,46,18,45,19,44,20,43,21,42,22,41,23,40,24,39,25,38,26,37,27,36,28,35,29,34,30,33,31,32 //comb reverse" << endl << endl;
                cout << "0,1,2,4,8,16,32,3,9,27,5,25,7,49,11,13,17,19,23,29,31,37,41,43,47,53,59,61,6,10,12,14,15,18,20,21,22,24,26,28,30,33,34,35,36,38,39,40,42,44,45,46,48,50,51,52,54,55,56,57,58,60,62,63 //prime group" << endl << endl;
                cout << "0,1,59,2,61,11,3,40,15,36,4,24,18,27,58,5,51,53,50,45,12,6,63,62,52,39,37,26,7,16,48,32,21,31,47,13,8,23,19,33,30,56,54,55,34,9,29,49,25,17,42,14,43,46,41,10,35,28,57,38,60,22,20,44 //space jump" << endl << endl;
                cout << fowo.strOwOng.shOwOrthand.ColorText("d");
            }
            else if (UserCommand == "ld.ch")
            {
                cout << fowo.strOwOng.shOwOrthand.ColorText("g");
                cout << "here are some of the character sets : " << endl;

                cout << "English - Normal" << endl;
                cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z _ . , ? ! ` \" : 0 1 2 3 4 5 6 7 8 9 ( ) [ ] { } ~ + - * / % ^ & | = < > x y" << endl << endl;

                cout << "English - QWERTY" << endl;
                cout << "~ ! % ^ & * ( ) _ + ` 1 2 3 4 5 6 7 8 9 0 - = Q W E R T Y U I O P { } | [ ] \\ A S D F G H J K L : \" ; Z X C V B N M < > ? , . /" << endl << endl;

                cout << "English - Enigma" << endl;
                cout << "Q W E R T Y Z U I O A S D F G H J K P X C V B N M L _ . , ? ! ` \" : 0 1 2 3 4 5 6 7 8 9 ( ) [ ] { } ~ + - * / % ^ & | = < > x y" << endl << endl;

                cout << "Greek" << endl;
                cout << "A B Γ Δ Ε Ζ Η Θ ι Κ Λ Μ Ν Ξ Ο Π Ρ Σ Τ Υ Φ Χ Ψ Ω α β γ δ ε ζ η θ ι κ λ μ ν ξ ο π ρ σ τ υ φ χ ψ ω _ . , ? ! # 0 1 2 3 4 5 6 7 8 9" << endl << endl;

                cout << "Chinese - ZhuYin" << endl;
                cout << "ㄅ ㄆ ㄇ ㄈ ㄪ ㄉ ㄊ ㄋ ㄌ ㄍ ㄎ ㄫ ㄏ ㄐ ㄑ ㄬ ㄒ ㄓ ㄔ ㄕ ㄖ ㄗ ㄘ ㄙ ㄚ ㄛ ㄜ ㄝ ㄞ ㄟ ㄠ ㄡ ㄢ ㄣ ㄤ ㄥ ㄦ ㄧ ㄨ ㄩ 丨 _ 。 ， ? ! : ’ ” 0 1 2 3 4 5 6 7 8 9 + - * / =" << endl << endl;

                cout << "Japanese - Hira" << endl;
                cout << "あ い う え お か き く け こ さ し す せ そ た ち つ て と な に ぬ ね の は ひ ふ へ ほ ま み む め も や ゆ よ ら り る れ ろ わ を ん d c _ 。 ， ! ? 0 1 2 3 4 5 6 7 8 9 #" << endl;

                cout << "Japanese - Kata" << endl;
                cout << "ア イ ウ エ オ カ キ ク ケ コ サ シ ス セ ソ タ チ ツ テ ト ナ ニ ヌ ネ ノ ハ ヒ フ ヘ ホ マ ミ ム メ モ ヤ ユ ヨ ラ リ ル レ ロ ワ ヲ ン d c _ 。 ， ! ? 0 1 2 3 4 5 6 7 8 9 #" << endl;

                cout << "Korean - Hangul" << endl;
                cout << "ㄱ ㄲ ㄴ ㄷ ㄸ ㄹ ㅁ ㅂ ㅃ ㅅ ㅆ ㅇ ㅈ ㅉ ㅊ ㅋ ㅌ ㅍ ㅎ ㅏ ㅐ ㅑ ㅒ ㅓ ㅔ ㅕ ㅖ ㅗ ㅘ ㅙ ㅚ ㅛ ㅜ ㅝ ㅞ ㅟ ㅠ ㅡ ㅢ ㅣ _ 。 ， ? ! : \" 0 1 2 3 4 5 6 7 8 9 + - * / ( ) ="<< endl;

                cout << "Astralica" << endl;
                cout << "a æ e i y ī ï o u w ü ə ô ʔ m b p f v z c s j q x n l d t ŋ g k h r . , ? ! : \" 0 1 2 3 4 5 6 7 8 9 A B C D E F + - * / ( ) = _ " <<  endl;
            
                cout << fowo.strOwOng.shOwOrthand.ColorText("d");
            }
            else if (UserCommand == "clear")
            {
                #ifdef _WIN32
                    system("cls");
                #elif defined(__linux)
                    system("clear");
                #elif defined(__APPLE__) && defined(__MACH__)
                    system("clear");
                #endif
            }

            
        }
    }

/*
Space Jump
int main ()
{
    vector<int> box = {};

    for(int i = 0 ; i < 64 ; i++)
    {
        box.push_back(-1);
    }

    int curr = 0 ; //current position in the list
    int count = -1; //current space jumped
    int progress = 0; //current number working on

    while(progress < 64)
    {
        cout << "prog : " << progress << endl;
        if (box[curr] == -1)
        {
            if (count == progress - 1)
            {
                box[curr] = progress;
                progress++;
                count = 0;
                curr = (curr + 1)%64;
            }
            else
            {
                count++;
                curr = (curr + 1)%64;
            }
        }
        else
        {
            curr = (curr + 1)%64;
        }
    }

    for(int i = 0 ; i < 64 ; i++)
    {
        cout << box[i] << ",";
    }


}



*/

}


