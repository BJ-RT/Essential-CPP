使用vector:
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec;
    int ival,sum,ix;
    while (cin >> ival)
        ivec.push_back(ival);//push_back函数，在vector类中作用为在vector尾部加入一个数据。
    for (sum = 0,ix = 0; ix < ivec.size(); ++ix)
        sum+=ivec[ix];
    int average = sum / ivec.size();
    cout << "sum of " << ivec.size()
         << " elements: " << sum
         << ". Average: " <<average << endl;
    return 0;
}

使用array:
