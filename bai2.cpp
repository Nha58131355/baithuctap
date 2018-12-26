#include <iostream>
#include <stdlib.h>
using namespace std;

struct NgayThang
{
	int day;
	int month;
	int year;
};

void NhapNgay(string &st, NgayThang &date)
{
	cout << "nhap ngay thang: "; 
	getline(cin, st);
	cout << "ngay thang vua nhap: " << st;
}

void Laydmy(string &st, NgayThang &date)
{
	date.day = atoi((st.substr(0,2)).c_str());
	cout << "\nngay: " << date.day<<endl;
	date.month = atoi((st.substr(3,2)).c_str());
	cout << "thang: " << date.month<<endl;
	date.year = atoi((st.substr(6,4)).c_str());
	cout << "nam: " << date.year <<endl;
}

int KTyear (NgayThang date)
{
	 if(((date.year)%100 == 0) && ((date.year)%400 == 0) || (((date.year)%100 != 0) && ((date.year)%4 == 0)))
        return 1;
    else
        return 0;
}

int day_of_month(NgayThang date, int i)
{
	int NumDay;
	
	switch (i)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: 
			NumDay = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11: 
			NumDay = 30;
			break;
		case 2:
			if (KTyear(date) == 1)
			{
				NumDay = 29;
			}
			else
			{
				NumDay = 28;
			}
			break;
	}

	return NumDay;	
}

int STTday(NgayThang date)
{
	int ngay = date.day;
	for(int i = 1; i <= date.month - 1; i++)
	{
		ngay = ngay + day_of_month(date, i);
	}
	return ngay;
}

void STTSangNgay(NgayThang &b, int &n)
{
	for(int i = n; n > 0; n -= day_of_month(b, b.month))
		if(n > day_of_month(b, b.month))
		{
			b.month++;
		}
		else
			if(n == day_of_month(b, b.month))
			{
				b.month++;
				b.day = 1;
				n = 0;
			}
			else
			{
				b.day = n;
				n = 0;
			}
	cout << b.day << "/" << b.month << "/" << b.year << endl;	
}

void Cong(NgayThang a, int &x)
{
	
	cout << "\nnhap so cong them: ";
	cin >> x;
	
	int n = STTday(a) + x;
	
	NgayThang b;
	b.year = a.year;
	b.month = 1;
	b.day = 0;
	
	while(n > 365)
		for(n; n >= 366; n-=366)
		{
			if(KTyear(b) == 0)
				n++;
			b.year++; 
		}
	if(n == 365)
	{
		b.year++; 
		b.day = 1; 
		b.month = 1; 
	}
	else
		if(n < 365)
			STTSangNgay(b, n); 
}

void Tru(NgayThang a, int &x)
{
	cout << "nhap so ngay tru di: ";
	cin >> x;
	
	NgayThang b;
	b.year = a.year;
	b.month = a.month;
	b.day = a.day;
	
	while(x >= 365)
	{
		if(KTyear(b) == 0)
		{
			b.year--;
			x -= 365;
		}
		else
		{
			b.year--;
			x -= 366;
		}
	}
	
	int stt = STTday(b);
	
	b.month = 1;
	b.day = 0;
	
	if(stt > x)
	{
		stt -= x;
		STTSangNgay(b, stt);
	}
	else
	{
		b.year--;
		if(KTyear(b) == 1)
			stt += 366;
		else
			stt += 365;
		stt -= x;
		STTSangNgay(b, stt);
	}
}

int main()
{
	struct NgayThang date;
	string st;
	NhapNgay(st, date);
	Laydmy(st, date);
	if(KTyear(date) == 1 ) cout << date.year << " la nam nhuan.";
	else cout << date.year << " khong phai nam nhuan.";
	cout << "\nSTT ngay trong nam la: " << STTday(date);
	int c;
	Cong(date,c);
	int t;
	Tru(date,t);
	
}

