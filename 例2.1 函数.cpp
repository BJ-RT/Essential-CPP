#include <iostream>
using namespace std;
bool fibon_elem(int, int&);//注意参数,参数名可省略

bool fibon_elem(int pos, int &elem)//注意参数,参数名不省略
{                                  //参数在主函数主函数中还要定义
    //合理性检查                   //在此函数中不需要重新定义
    if (pos <= 0 || pos > 1024)
    {
        elem = 0;
        return false;
    }
    elem = 1;
    int n2 = 1, n1 = 1;

    for(int ix = 3; ix <= pos; ++ix)
    {
        elem = n2+n1;
        n2 = n1;
        n1 = elem;
    }
    return true;
}

int main()
{
    int pos;                       //定义参数
    cout << "Please enter a position: ";
    cin >> pos;

    int elem;                      //定义参数
    if(fibon_elem(pos, elem))
        cout << "element # " << pos
             << " is " << elem << endl;
    else cout << "Sorry, Could not calculate element # "
              << pos << endl;
    return 0;
}
