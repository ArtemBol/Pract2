#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void Time(tm* ptm)
{
    vector<string> dow {"Воскресенье", "Понедельник", "Вторник","Среда","Четверг","Пятница","Суббота"};
	vector<string> moy{"Январь", "Февраль", "Март", "Апрель","Май","Июнь","Июль","Август","Сентябрь","Октябрь","Ноябрь","Декабрь"};
		int i = ptm->tm_wday;
	    int k = ptm->tm_mon;
	    cout << dow[i] << " " << moy[k] << " " << ptm->tm_mday << " " << ptm->tm_hour << ":" << ptm->tm_min << ":" << ptm->tm_sec << " " << 1900 + ptm->tm_year << endl;
	}
	int main(int argc, char** argv)
	{
	    time_t t = time(NULL);
	    tm* ptm;
	    ptm = localtime(&t);
	    Time(ptm);
	    return 0;
	}