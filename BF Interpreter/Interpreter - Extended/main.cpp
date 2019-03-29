#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Prg;
unsigned int PrgPos = 0;
int MemPos = 0;
int BracketOpen = 0;
int BracketClose = 0;
vector <int> Mem(1);
char output;

void brainfuck()
{
    cin >> Prg;
    while(PrgPos < Prg.size())  {
        if(Prg[PrgPos] == '+')  {
            if(Mem[MemPos]==255)  {
                cout<<"ERROR"<<endl;
                break;
            }
            Mem[MemPos]+=1;
        }else if(Prg[PrgPos] == '-')  {
            if(Mem[MemPos]==0){
                cout<<"ERROR"<<endl;
                break;
            }
            Mem[MemPos]-=1;
        }else if(Prg[PrgPos] == ',')  {
            cin >> Mem[MemPos];
        }else if(Prg[PrgPos] == '.')  {
            char asc=Mem[MemPos];
            cout << asc;
        }else if(Prg[PrgPos] == '>')  {
            Mem.resize(Mem.size() + 1);
            MemPos += 1;
        }else if(Prg[PrgPos] == '<')  {
            MemPos -= 1;
        }else if(Prg[PrgPos] == '[')  {
			if(Mem[MemPos] == 0)  {
				PrgPos += 1;
				while(PrgPos < Prg.size())  {
					if(Prg[PrgPos] == ']' && BracketOpen == 0)  {
						break;
					}else if(Prg[PrgPos] == '[')  {
						BracketOpen += 1;
					}else if(Prg[PrgPos] == ']')  {
						BracketOpen -= 1;
					}
					PrgPos += 1;
				}
			}
        }else if(Prg[PrgPos] == ']')  {
			if(Mem[MemPos] != 0)  {
				PrgPos -= 1;
				while(PrgPos >= 0)  {
					if(Prg[PrgPos] == '[' && BracketClose == 0)  {
						break;
					}else if(Prg[PrgPos] == ']')  {
						BracketClose += 1;
					}else if(Prg[PrgPos] == '[')  {
						BracketClose -= 1;
					}
					PrgPos -= 1;
				}
			}
        }
        PrgPos += 1;
    }
}

int main()
{
    brainfuck();
    return 0;
}
