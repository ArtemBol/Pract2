#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
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
    generate(v2.begin(), v2.end(), RandomGenerator);
    random_device random_device;
    mt19937 rnd(clock());
    uniform_int_distribution<int> r(-10000000, 10000000);
    for(int i = 0; i < 10000000; i++) {
	v1.push_back(i);
	v1.at(i) = r(rnd);
    }
    vector<int> v3(v2);
	return 0;
}