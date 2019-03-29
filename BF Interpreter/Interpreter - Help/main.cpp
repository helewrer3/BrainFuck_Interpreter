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
    char c;
    char option;
	start:cout << "\n\n---------------------------------------------------BRAINFUCK!--------------------------------------------------\n\n";
    cout << "What u wanna do ?";
	cout << "\n-------------------------------";
    cout << "\n|INTERPRETER              -> 1|";
    cout << "\n-------------------------------";
    cout << "\n|HELP                     -> 2|";
    cout << "\n-------------------------------";
	cin >> c;
	if (c == '1')  {
            cout << "\n\n\nTYPE!\n\n\n";
			brainfuck();
	}
	if (c == '2')  {
		cout << "\n\n---------------------------------------------------HELP!--------------------------------------------------\n\n";
		char a;
		cout << "What u wanna search for ?";
		cout << "\n-------------------------------";
		cout << "\n|'>'                      -> 1|";
		cout << "\n-------------------------------";
		cout << "\n|'<'                      -> 2|";
		cout << "\n-------------------------------";
		cout << "\n|'.'                      -> 3|";
		cout << "\n-------------------------------";
		cout << "\n|','                      -> 4|";
		cout << "\n-------------------------------";
		cout << "\n|'['                      -> 5|";
		cout << "\n-------------------------------";
		cout << "\n|']'                      -> 6|";
		cout << "\n-------------------------------";
		cout << "\n|'+'                      -> 7|";
		cout << "\n-------------------------------";
		cout << "\n|'-'                      -> 8|";
		cout << "\n-------------------------------";
		cout << "\n";
		cin >> a;
		switch (a)  {
			case '1':  {
                cout << "increment the data pointer (to point to the next cell to the right).";
                break;
            }
			case '2':  {
                cout << "decrement the data pointer (to point to the next cell to the left).";
                break;
            }
			case '3':  {
                cout << "output the byte at the data pointer.";
                break;
            }
			case '4':  {
                cout << "accept one byte of input, storing its value in the byte at the data pointer.";
                break;
            }
			case '5':  {
                cout << "if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.";
                break;
            }
			case '6':  {
                cout << "if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command.";
                break;
            }
			case '7':  {
                cout << "increment (increase by one) the byte at the data pointer.";
                break;
            }
			case '8':  {
                cout << "decrement (decrease by one) the byte at the data pointer.";
                break;
            }
			default: break;
		}
	}
    label: cout << "\n-----------------------------";
    cout << "\nU WANNA GO AGAIN?![MAIN()] - "<<"\n Y -> Yes \t N -> No ";
    cout << "\n-----------------------------\n";
    cin >> option;
    if (option != 'Y' && option != 'N')  {
        goto label;
    }else if (option == 'Y')  {
        goto start;
    }
    char b;
    cout << "\n------------------------";
    cout << "\n|ENTER ANY KEY TO EXIT!|";
    cout << "\n------------------------\n";
    cin >> b;
    return 0;
}
