#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Card
{
    int nominal;
    int mast;
    Card(){};
    Card(int a, int b): nominal(a), mast(b){};
    friend ostream& operator<<(ostream& outputStream, Card c)
    {
	return outputStream << to_string(c.nominal) + " " + to_string(c.mast);
    }
};
bool Color(Card x, Card y)
{
    if((x.mast == y.mast) || (x.mast == 0 && y.mast == 1) || (x.mast == 2 && y.mast == 3) ||
        (y.mast == 1 && x.mast == 0) || (y.mast == 3 && x.mast == 2))
	return 0;
}
bool Nominal(Card x, Card y)
{
    if(x.nominal == y.nominal)
	return 0;
}
bool Queen(Card x)
{
    return (x.nominal == 6 && x.mast == 3);
}
bool Ace(Card x)
{
    return (x.nominal == 8);
}
int main()
{
    vector<Card> koloda;
    for(int j = 0; j < 4; j++) {
	for(int i = 0; i < 9; i++) {
	    koloda.push_back(Card(i, j));
	}
    }
    for(int i = 0; i < 36; i++)
	cout << koloda[i] << endl;
    random_shuffle(koloda.begin(), koloda.end());
    for(int i = 0; i < 36; i++)
	cout << koloda[i] << endl;
    for(auto it = ++koloda.begin(); it < koloda.end(); it++) {
	it = adjacent_find(--it, koloda.end(), Color);
	if(it != koloda.end())
	    cout << "Карты одного цвета: " << *(it) << " и " << *(it++) << '\n';
    }
    for(auto it = ++koloda.begin(); it < koloda.end(); it++) {
	it = adjacent_find(--it, koloda.end(), Nominal);
	if(it != koloda.end())
	    cout << "Карты одного номинала: " << *(it) << " и " << *(it++) << '\n';
    }
    auto it = find_if(koloda.begin(), koloda.end(), Queen);
    cout << "Пиковая дама " << distance(koloda.begin(), it) << "-я в колоде" << endl;
    cout << "Тузы в колоде на ";
    it = koloda.begin() - 1;
    for(int i = 0; i < 4; i++) {
	it = find_if(it + 1, koloda.end(), Ace);
	cout << distance(koloda.begin(), it) << " ";
    }
    cout << "позициях" << endl;
    return 0;
}