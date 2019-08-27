#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <fstream>
#include <conio.h>
#include <stdio.h>

using namespace std;

//游客信息
struct travelInfo
{
    string name;
    int age;
    string travelRoute;    //旅游路线
    string teamNature;     //团队名
};

//用于排序
void swap(int val1, int val2)
 {
        int temp = val1;
        val1 = val2;
        val2 = temp;
 }


//运算符重载
//输出
ostream& operator << (ostream& out, travelInfo& listIter)
{
    cout << listIter.name << "\t"
         << listIter.age  << "\t"
         << listIter.travelRoute << "\t"
         << listIter.teamNature;
    return out;
}

//输入,&传值,引用,非拷贝
istream& operator >> (istream& in, travelInfo& tempData)
{
    in >> tempData.name
       >> tempData.age
       >> tempData.travelRoute
       >> tempData.teamNature;
    return in;

}

//int islogn = 0;

//登录类
class System_Login
{
public:
    ifstream readName;
    ifstream readPass;

//构造器,打开文件
    System_Login()
    {
        readName.open("name.txt");
        readPass.open("pass.txt");

        if(!readName || !readPass)
        {
            cout << "打开失败!";
            cout << endl;
        }
    }

//析构器,关闭文件
    ~System_Login()
    {
        readName.close();
        readPass.close();
    }

//登录操作函数
    void AdminLogin()
    {
        int leftTry;//尝试次数
        leftTry = 3;
        string fileName;
        readName >> fileName; //读取文件中的用户名

        string userName;//定义用户名
        cout << "请输入用户名:";
        cin >> userName;
        if (userName == fileName)
        {
            cout << endl;
            cout << "输入正确";
            cout << endl;
            cout << endl;
            cout << "请输入密码:";

            string pass;
            cin >> pass;

            string filePass;
            getline(readPass, filePass);

            if (pass==filePass)
            {
                cout << "登录成功!" << endl;
            }

            else
            {
                cout << "密码错误!"
                     << endl;
                char yn;
                bool input_yn;
                while (leftTry > 0)
                {
                    cout << "您还有"
                         << --leftTry
                         << "次机会"
                         << endl;
                    cout << "是否重新输入(Y/N) ? : ";
                    cin >> yn;

                    if (yn =='Y' || yn == 'y')
                    {
                        input_yn = true;
                    }
                    else
                    {
                        if (yn == 'N' || yn == 'n')
                        {
                            input_yn = false;
                        }
                        else
                        {
                            cout << "输入错误!"
                                 << endl;
                            exit(0);
                        }

                    }

                    if (input_yn)
                    {
                        cout << "请再次输入密码:";
                        cin >> pass;
                        if (pass == filePass)
                        {
                            cout << "登陆成功!";
                            cout << endl;
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }

            }


        }



    }
};


//系统功能类
class TravelSystem
{
public:
    ofstream Output;

    //TravelSystem();
   // ~TravelSystem();

    void inputInfo(travelInfo info);//输入操作
    void printInfo();               //打印循环列表
    void searchInfo(int age);       //通过年龄查找
    void searchInfo(string name);   //通过姓名查找(重载)
    void searchbyInfo(string travelRoute);
    void search_Info(string teamNature);
    void modifyInfobyName(string name);//通过姓名修改
    int  deleteInfobyName(string name);//通过姓名删除
    void sort();
    void printStyle();              //打印格式

protected:
    //用C++中的STL存储: list 双向链表
    list<travelInfo> travelList;//--------------------------------------------?
};

//构造函数,打开文件
TravelSystem::TravelSystem()
{
    Output.open("test.txt", ios::app);  //以追加的形式打开一个文件,

}

//析构函数,关闭文件
TravelSystem::~TravelSystem()
{
    Output.close();         //关闭文件
}

//输入操作
void TravelSystem::inputInfo(travelInfo info)
{
    travelList.push_back(info);//插入链表,尾插
}

//打印格式
void TravelSystem::printStyle()
{
    cout << "姓名\t年龄\t路线\t\t团队"
         << endl;
}

//输出操作,把容器里的所有元素打印
void TravelSystem::printInfo()
{
    //迭代器,类中类,模板
    list<travelInfo>::iterator listIter;
    printStyle();
    for(listIter = travelList.begin();
        listIter != travelList.end();
        ++listIter)
    {
        cout << *listIter << endl;//输出,运算符重载
    }
}

//排序,按年龄由大到小
void TravelSystem::sort()
{
    travelInfo array[20];
    int i = 0;
    list<travelInfo>::iterator listIter;
    printStyle();
    for(listIter = travelList.begin();
        listIter != travelList.end();
        ++listIter)
    {
        array[i] = *listIter;
        i++;
    }

    for (int ix = 0; ix  < i; ++ix)
    {
        for (int jx = ix+1; jx < i; ++jx)
        {
            if (array[ix].age > array[jx].age)
            {
                swap(array[ix].age, array[jx].age);
            }
        }
    }
    for (int m = 0; m < i; ++m)
    {
        cout << array[m].name
             << "\t"
             << array[m].age
             << "\t"
             << array[m].travelRoute
             << "\t"
             << array[m].teamNature
             << endl;
    }
}

//按名字查找
void TravelSystem::searchInfo(string name)
{
    int flag = 0;
    list<travelInfo>::iterator listIter;
    printStyle();
    for(listIter = travelList.begin();
        listIter != travelList.end();
        ++listIter)
    {
        if (listIter->name == name)
        {
            cout << *listIter;//输出,运算符重载
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "无相关人员信息!"
             << endl;
    }
}

//按年龄查找
void TravelSystem::searchInfo(int age)
{
    int flag = 0;
    list<travelInfo>::iterator listIter;
    printStyle();
    for(listIter = travelList.begin();
        listIter != travelList.end();
        ++listIter)
    {
        if (listIter->age == age)
        {
            cout << *listIter;//输出,运算符重载
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "无相关人员信息!"
             << endl;
    }
}

//按旅游路线查找
void TravelSystem::searchbyInfo(string travelRoute)
{
    int flag = 0;
    list<travelInfo>::iterator listIter;
    printStyle();
    for(listIter = travelList.begin();
        listIter != travelList.end();
        ++listIter)
    {
        if (listIter->travelRoute == travelRoute)
        {
            cout << *listIter;//输出,运算符重载
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "无相关线路信息!"
             << endl;
    }
}

//按团队查找
void TravelSystem::search_Info(string teamNature)
{
    int flag = 0;
    list<travelInfo>::iterator listIter;
    printStyle();
    for(listIter = travelList.begin();
        listIter != travelList.end();
        ++listIter)
    {
        if (listIter->teamNature == teamNature)
        {
            cout << *listIter;//输出,运算符重载
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "无相关团队信息!"
             << endl;
    }
}

//通过姓名删除
int TravelSystem::deleteInfobyName(string name)
{
    int flag = 0;
    list<travelInfo>::iterator listIter;
    for(listIter = travelList.begin();
        listIter != travelList.end();
        ++listIter)
    {
        if (listIter->name == name)
        {
            travelList.erase(listIter);//删除
            flag = 1;
            cout << "删除成功!"
                 << endl;
            return flag;                     //删完了不能让迭代器往下走了,当前迭代器或者指针不存在
                                             //删除完成要用return结束这个函数
        }
    }
    if (flag == 0)
    {
        cout << "无法删除!" << endl;
        return flag;
    }
    return flag;
}

//修改操作
void TravelSystem::modifyInfobyName(string name)
{
    travelInfo tempData;

    deleteInfobyName(name);
    cout << "请输入修改后的(name, age, route, team)" << endl;
    cin >> tempData;
    inputInfo(tempData);
}

//主菜单
void menu()
{
    cout << "---------------旅游管理系统--------------" << endl;
    cout << "\t\t0.退出系统" << endl;
    cout << "\t\t1.增加信息" << endl;
    cout << "\t\t2.浏览信息" << endl;
    cout << "\t\t3.删除信息" << endl;
    cout << "\t\t4.查找信息" << endl;
    cout << "\t\t5.修改信息" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "请输入0-5菜单编号:";
}

//浏览菜单
void printMenu()
{
    cout << "---------------浏览菜单--------------" << endl;
    cout << "\t\t0.退出浏览" << endl;
    cout << "\t\t1.按录入次序浏览" << endl;
    cout << "\t\t2.按年龄次序浏览" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "请输入0-2菜单编号:";
}

//查找菜单
void searchMenu()
{
    cout << "---------------查找菜单--------------" << endl;
    cout << "\t\t0.退出查找" << endl;
    cout << "\t\t1.按姓名查找" << endl;
    cout << "\t\t2.按年龄查找" << endl;
    cout << "\t\t3.按路线查找" << endl;
    cout << "\t\t5.按团队查找" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "请输入0-5菜单编号:";
}

//查找菜单交互
void Keydown_SearchMenu(TravelSystem* pInfo)
{
    int choice;
    cin >> choice;
    travelInfo tempData;
    switch(choice)
    {
        case 0:
            cout << "退出成功!"
                 << endl;
            break;
        case 1:
            cout << "---------------按姓名查找--------------" << endl;
            cin >> tempData.name;
            pInfo->searchInfo(tempData.name);
            break;
        case 2:
            cout << "---------------按年龄查找--------------" << endl;
            cin >> tempData.age;
            pInfo->searchInfo(tempData.age);
            break;
        case 3:
            cout << "---------------按路线查找--------------" << endl;
            cin >> tempData.travelRoute;
            pInfo->searchbyInfo(tempData.travelRoute);
            break;
        case 4:
            cout << "---------------按团队查找--------------" << endl;
            cin >> tempData.teamNature;
            pInfo->search_Info(tempData.teamNature);
            break;
        default:
            cout << "输入错误!"
                 << endl;
            break;
    }
}

//浏览菜单交互
void keydown_printMenu(TravelSystem* pInfo)
{
    int choice;
    cin >> choice;
    switch(choice)
    {
    case 0:
        cout << "退出成功!"
             << endl;
        break;
    case 1:
        cout << "---------------按录入次序浏览--------------"
             << endl;
        pInfo->printInfo();
        break;
    case 2:
        cout << "---------------按年龄大小浏览--------------"
             << endl;
        pInfo->sort();

        break;
    default:
        cout << "输入错误!"
             << endl;
        break;
    }
}

//主菜单交互
//结构体变量或者类的变量只能通过相应的变量或者对象指针访问
void  keydown_menu(TravelSystem* pInfo)
{
    int choice;
    cin >> choice;
    travelInfo tempData;        //局部变量,处理用户交互
    switch(choice)
    {
    case 0:
        cout << "正常退出" << endl;
        delete pInfo;
        system("pause");
        exit(0);    //正常退出
        break;
    case 1:
        cout << "---------------增加信息---------------" << endl;
        cout << "请输入(name, age, route, team)" << endl;
        cin >> tempData;
        pInfo -> inputInfo(tempData);//通过对象指针访问input消息,存入链表-----------------------------------------------------------
        break;
    case 2:
        cout << "---------------浏览信息---------------" << endl;
        printMenu();
        keydown_printMenu(pInfo);
        break;
    case 3:
        cout << "---------------删除信息---------------" << endl;
        cout << "请输入需要删除的姓名:";
        cin >> tempData.name;
        pInfo->deleteInfobyName(tempData.name);
        break;
    case 4:
        cout << "---------------查找信息---------------" << endl;
        searchMenu();
        Keydown_SearchMenu(pInfo);
        break;
    case 5:
        cout << "---------------修改信息---------------" << endl;
        cout << "请输入要修改的游客的姓名:";
        cin >> tempData.name;
        pInfo->modifyInfobyName(tempData.name);
        break;
    default:
        cout << "输入错误" << endl;
        break;
    }
}

//主函数
int main()
{
    System_Login a;
    a.AdminLogin();
    TravelSystem *pInfo = new TravelSystem;
    while(1)
    {
        menu();
        keydown_menu(pInfo);
        system("pause");//暂停,防止清屏
        system("cls");  //清屏
    }

    return 0;
}

//小明 18 北京-上海 A团
//小红 19 广州-深圳 B团
//小白 20 柳州-潍坊 C团

