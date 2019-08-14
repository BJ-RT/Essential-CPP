#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &vec)  //此处的&可有可无, 加上&会提高效率(不用复制,只需传地址)
                                //需要改变的参数才加&.(缓冲区)
    
{
    for (int ix = 0; ix < vec.size(); ++ix)
        cout <<vec[ix] << " ";
    cout << endl;
}

void swap(int &v1, int &v2)     //+&
{
    int temp = v1;
    v1 = v2;
    v2 = temp;
}

void bubble_sort(vector<int> &vec)      //+&
{
    for (int ix = 0; ix < vec.size(); ++ix)
        for (int jx = ix +1; jx < vec.size(); ++jx)
            if(vec[ix] > vec[jx])
                swap(vec[ix],vec[jx]);
}

int main()
{
    int ia[8] = {8,34,3,13,1,21,5,2};
    vector<int> vec(ia,ia+8);

    cout << "vector before sort: ";
    display(vec);

    bubble_sort(vec);

    cout << "vector after sort:  ";
    display(vec);
    return 0;
}
