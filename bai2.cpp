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

NgayThang ngaytuSTT(int stt, int nam)
{
	
}

NgayThang CongNgayThang(NgayThang n, int x)
{
	int kq = x + STTday(n);
	int nam = n.year;
	if(kq <= 365) return ngaytuSTT(kq, nam)
	else
		if(KTyear(n) == 1)
			if(kq == 366) 
				return ngaytuSTT(kq, nam)
			else 
				return ngaytuSTT(kq - 366, nam + 1 );
		else 
			return ngaytuSTT(kq - 365, nam +1)	
}
void add(NgayThang date, int x)
{
	
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
	
}

