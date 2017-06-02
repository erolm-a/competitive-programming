#include <iostream>
#include <fstream>
#include <cstdio> // per fscanf
#include <stack>

using namespace std;

void scrivi_output(bool buono)
{
  ofstream o_f("output.txt");
  if(buono)
    o_f << "corretta" << endl;
  else o_f << "malformata" << endl;
}

int main()
{
  stack<char> parentesi;
  
  FILE* i_f = fopen("input.txt", "r"); // è più semplice per la lettura di caratteri
  int lunghezza;
  fscanf(i_f, " %d", &lunghezza);
  
  for(int i = 0; i < lunghezza; i++)
  {
    char c;
    fscanf(i_f, " %c", &c);

    switch(c)
    {
      case '{' :
      case '[' :
      case '(' :
      case '<' :
	parentesi.push(c);
	break;
      case '}' :
	if(parentesi.empty() || parentesi.top() != '{') {
	  scrivi_output(false);
	  return 0;
	}
	parentesi.pop();
	break;
      case ']' :
	if(parentesi.empty() || parentesi.top() != '[') {
	  scrivi_output(false);
	  return 0;
	}
	parentesi.pop();
	break;
      case ')' :
	if(parentesi.empty() || parentesi.top() != '(') {
	  scrivi_output(false);
	  return 0;
	}
	parentesi.pop();
	break;
      case '>' :
        if(parentesi.empty() || parentesi.top() != '<') {
          scrivi_output(false);
          return 0;
        }
        parentesi.pop();
        break;
    }
  }
  
  if(!parentesi.empty())
    scrivi_output(false);
  else scrivi_output(true);
  
  return 0;
}
