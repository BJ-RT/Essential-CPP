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
#include <iostream>
using namespace std;

int main()
{
    const int array_size = 128;
    int ia[array_size];
    int ival,icnt = 0;
    while (cin >> ival && icnt < array_size)
        ia[icnt++] = ival;
    int sum, ix;
    for (sum = 0, ix = 0; ix < icnt; ++ix)
        sum+=ia[ix];
    int average = sum/icnt;
    cout << "sum of " << icnt
         << " elements: " << sum
         << ". average: " << average << endl;
    return 0;
}
