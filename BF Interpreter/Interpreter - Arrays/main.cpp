#include <iostream>
#include <string>

using namespace std;

string C;
unsigned int D = 0;
int E = 0;
int G = 0;
int H = 0;

int F[3000] = {0};
char output;

void brainfuck()
{
    cin >> C;
    while(D < C.size())
    {
        if(C[D] == '+')
        {
            if(F[E]==255){
                cout<<"ERROR-"<<endl;
                break;
            }
            F[E]+=1;
        }
        else if(C[D] == '-')
        {
            if(F[E]==0){
                cout<<"ERROR"<<endl;
                break;
            }
            F[E]-=1;
        }
        else if(C[D] == ',')
        {
            cin >> F[E];
        }
		else if(C[D] == '.')
        {
            char asc=F[E];
            cout << asc;
        }
        else if(C[D] == '>')
        {
            E += 1;
        }
        else if(C[D] == '<')
        {
            E -= 1;
        }
        else if(C[D] == '[')
        {
			if(F[E] == 0)
			{
				D += 1;
				while(D < C.size())
				{
					if(C[D] == ']' && G == 0)
					{
						break;
					}
					else if(C[D] == '[')
					{
						G += 1;
					}
					else if(C[D] == ']')
					{
						G -= 1;
					}
					D += 1;
				}
			}
        }
        else if(C[D] == ']')
        {
			if(F[E] != 0)
			{
				D -= 1;
				while(D >= 0)
				{
					if(C[D] == '[' && H == 0)
					{
						break;
					}
					else if(C[D] == ']')
					{
						H += 1;
					}
					else if(C[D] == '[')
					{
						H -= 1;
					}
					D -= 1;
				}
			}
        }
        D += 1;
    }
}

int main()
{
    brainfuck();
    return 0;
}
