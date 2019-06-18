#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
using namespace std::chrono;
int RandomGenerator()
{
    static mt19937 rnd((uint64_t)&rnd);
    uniform_int_distribution<int> d(-10000000, 10000000);
    return d(rnd);
}
int main()
{
    vector<int> v1;
    vector<int> v2(10000000);
    cout << "Вектор 2" << endl;
    steady_clock::time_point tp1 = steady_clock::now();
    generate(v2.begin(), v2.end(), RandomGenerator);
    steady_clock::time_point tp2 = steady_clock::now();
    duration<double> d1 = tp2 - tp1;
    cout << d1.count() << endl;
    cout << "Вектор 1" << endl;
    random_device random_device;
    mt19937 rnd(clock());
    uniform_int_distribution<int> r(-10000000, 10000000);
    steady_clock::time_point tp1s = steady_clock::now();
    for(int i = 0; i < 10000000; i++) {
	v1.push_back(i);
	v1.at(i) = r(rnd);
    }
    steady_clock::time_point tp2s = steady_clock::now();
    duration<double> d2 = tp2s - tp1s;
    cout << d2.count() << endl;
    cout << "Вектор 3" << endl;
    steady_clock::time_point tp1t = steady_clock::now();
    vector<int> v3(v2);
    steady_clock::time_point tp2t = steady_clock::now();
    duration<double> d3 = tp2t - tp1t;
    cout << d3.count() << endl;
	return 0;
}