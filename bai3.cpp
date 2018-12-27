#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef struct 
{
	string cauhoi;
	string A,B,C;
	char da;	
}CauHoi;

typedef struct 
{
	int diem;
	string ten;	
}nguoi;

vector<CauHoi> dscau;

void DocDe()
{
	ifstream f("de1.txt");
	int sl;
	string s;
	getline(f,s);
	sl=atoi(s.c_str()); //doi string sang int
	for(int i=0; i<sl; i++)
	{
		getline(f,s); dscau[i].cauhoi; cout <<s<< endl;
		getline(f,s); dscau[i].A; cout << s << endl;
		getline(f,s); dscau[i].B; cout << s << endl;
		getline(f,s); dscau[i].C; cout << s << endl;
		getline(f,s); dscau[i].da;
		
	}
}



int main()
{
	DocDe();
}
