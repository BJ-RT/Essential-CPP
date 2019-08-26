#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
using namespace std;

struct travelInfo          //游客信息
{
    string name;
    int age;
    string travelRoute;    //旅游路线
    string teamNature;     //团队名
};

//运算符重载
ostream& operator << (ostream& out, travelInfo listIter)//输出
{
    cout << listIter.name << "\t"
         << listIter.age  << "\t"
         << listIter.travelRoute << "\t"
         << listIter.teamNature<< endl;
    return out;
}

istream& operator >> (istream& in, travelInfo& tempData)//输入,&传值,引用,非拷贝
{
    in >> tempData.name
       >> tempData.age
       >> tempData.travelRoute
       >> tempData.teamNature;
    return in;

}

class TravelSystem
{
public:
    void inputInfo(travelInfo info);//输入操作
    void printInfo();               //打印循环列表
    void searchInfo(int age);       //通过年龄查找
    void searchInfo(string name);   //通过姓名查找(重载)
    void modifyInfobyName(string name);//通过姓名修改
    int  deleteInfobyName(string name);//通过姓名删除
    void printStyle();              //打印格式

protected:
    //用C++中的STL存储: list 双向链表
    list<travelInfo> travelList;//--------------------------------------------?
};

void TravelSystem::inputInfo(travelInfo info)//输入
{
    travelList.push_back(info);//插入链表,尾插
}

void TravelSystem::printStyle()//输出格式
{
    cout << "姓名\t年龄\t路线\t\t团队"
         << endl;
}

void TravelSystem::printInfo()//浏览信息,把容器里的所有元素打印
{
    //迭代器,类中类,模板
    list<travelInfo>::iterator listIter;
    printStyle();
    for(listIter = travelList.begin();
        listIter != travelList.end();
        ++listIter)
    {
        cout << *listIter;//输出,运算符重载
    }
}

void TravelSystem::searchInfo(string name)//按名字查找
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
        cout << "无相关人员信息!" << endl;
    }
}

void TravelSystem::searchInfo(int age)//按年龄查找
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
        cout << "无相关人员信息!" << endl;
    }
}

int TravelSystem::deleteInfobyName(string name)//通过姓名删除
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
            break;
        case 4:
            cout << "---------------按团队查找--------------" << endl;
            break;
        default:
            cout << "输入错误!"
                 << endl;
            break;
    }
}

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
        system("pause");
        exit(0);    //正常退出
        break;
    case 1:
        cout << "---------------增加信息---------------" << endl;
        cout << "请输入(name, age, route, team)" << endl;
        cin >> tempData;
        pInfo -> inputInfo(tempData);//通过对象指针访问input消息,存入链表-----------------------------------------------------------?
        break;
    case 2:
        cout << "---------------浏览信息---------------" << endl;
        pInfo -> printInfo();
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
int main()
{
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
