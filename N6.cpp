#include <iostream>

#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
using namespace std;
struct Data {
    string FirstName;
    string LastName;
    string Patronymic;
    friend bool operator<(const Data& d1, const Data& d2)
    {
	if(d1.FirstName != d2.FirstName) {
	    return d1.FirstName < d2.FirstName;
	} else {
	    if(d1.LastName != d2.LastName) {
		return d1.LastName < d2.LastName;
	    } else {
		if(d1.Patronymic != d2.Patronymic) {
		    return d1.Patronymic < d2.Patronymic;
		}
	    }
	}
    }
    friend ostream& operator<<(ostream& out, const Data& data)
    {
	cout << data.FirstName << " " << data.LastName << " " << data.Patronymic << endl;
    }
};
int main()
{
    ifstream file("/media/artem/291ae5c5-da33-449a-8784-d51af46f306b/artem/Лабораторные работы/Тема8/spisok.txt");
    if(!file.good()) {
	cerr << "Не рабочий файл" << endl;
    }
    int str = 0;
    string line;
    while(getline(file, line)) {
	stringstream lineStream(line);
	while(getline(lineStream, line, ' ')) {
	    ++str;
	}
    }
    str = str / 3;
    vector<Data> slova;
    file.clear();
    file.seekg(ios::beg);
    Data data;
    for(int i = 0; i < str; i++) {
	file >> data.FirstName;
	file >> data.LastName;
	file >> data.Patronymic;
	slova.push_back(data);
    }
    sort(slova.begin(), slova.end());
    cout << "Отсортированый список: " << endl;
    for(int i = 0; i < str; i++) {
	cout << slova[i];
    }
    int t;
    for(int i = 0; i < str; i++) {
	if(slova[i].FirstName == slova[i + 1].FirstName) {
	    cout << "Однофамильцы: " << endl;
	    t = i;
	    string fn = slova[i].FirstName;
	    while(slova[t].FirstName == fn) {
		cout << slova[t];
		t++;
	    }
	    i = t - 1;
	}
    }
    map<string, int> ounter;
    map<string, int>::iterator it;
    for(int i = 0; i < str; i++) {
	ounter[slova[i].LastName]++;
    }
 auto x = max_element(ounter.begin(),ounter.end(), [](const pair< string, int>& p1, constpair<string, int>& p2) {
	return p1.second < p2.second;
 };
 auto y = min_element(ounter.begin(),ounter.end(), [](const pair< string, int>& p1, const pair<string, int>& p2) {
	return p1.second < p2.second;
 };
 cout<<"Самые популярые имена: "<<endl;
 for(it=ounter.begin();it!=ounter.end();it++){
	if(it->second == x->second)
	    cout << it->first << endl;
 }
 cout<<"Самое редкое имя: "<<endl;
 for(it=ounter.begin();it!=ounter.end();it++){
	if(it->second == y->second)
	    cout << it->first << endl;
 }
 file.close();
}