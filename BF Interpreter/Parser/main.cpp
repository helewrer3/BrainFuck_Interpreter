#include <iostream>
#include <string>

using namespace std;

string Prg;
unsigned int PrgPos = 0;
int MemPos = 0;
char output;
unsigned int BracketCount = 0;
int SynCheck = 0;
unsigned int ErrCheck = 0;

void parser()
{
    cin >> Prg;
    while(ErrCheck <= Prg.size())  {
        if(Prg[ErrCheck] == '>')  {
            MemPos += 1;
        }else if(Prg[ErrCheck] == '<')  {
            MemPos -= 1;
        }else if(Prg[ErrCheck] == '[')  {
            SynCheck += 1;
        }else if(Prg[ErrCheck] == ']')  {
            SynCheck -= 1;
        }
        ErrCheck += 1;
    }
    if(SynCheck != 0 || MemPos < 0)  {
        goto skip;
    }
    cout << "[";
    while(PrgPos <= Prg.size())  {
        if(Prg[PrgPos] == '+' || Prg[PrgPos] == '-' || Prg[PrgPos] == '>' || Prg[PrgPos] == '<' || Prg[PrgPos] == '.' || Prg[PrgPos] == ',')  {
            output = Prg[PrgPos];
            if(BracketCount == 0)  {
                if(PrgPos == (Prg.size() - 1))  {
                    cout << "['" << output << "']";
                }else  {
                    cout << "['" << output << "'],";
                }
            }else if (BracketCount != 0)  {
                cout << "'" << output << "',";
            }
        }else if(Prg[PrgPos] == '[')  {
            output = Prg[PrgPos];
            if(BracketCount == 0)  {
                cout << "['" << output << "',";
            }else if(BracketCount != 0)  {
                cout << "'" << output << "',";
            }
            BracketCount += 1;
        }else if(Prg[PrgPos] == ']')  {
            output = Prg[PrgPos];
            BracketCount -= 1;
            if(BracketCount == 0)  {
                if(PrgPos == (Prg.size() - 1))  {
                    cout << "'" << output << "']";
                }else  {
                    cout << "'" << output << "'],";
                }
            }else if(BracketCount != 0)  {
                cout << "'" << output << "',";
            }
        }
        PrgPos += 1;
        if(PrgPos == Prg.size())  {

            cout << "]";
        }
    }
    skip: cout << "\n";
}


int main()
{
    parser();
    return 0;
}
