#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class StoreQuote
{
public:
    string quote, speaker;
    ofstream fileOutput;

    StoreQuote ();              //声明构造器
    ~StoreQuote ();             //声明析构器

    void inputQuote();
    void inputSpeaker ();
    bool write ();
};

StoreQuote::StoreQuote()        //构造器, 准备工作
{
    fileOutput.open("test.txt", ios::app);  //以追加的形式打开一个文件,
                                            //会自动新建一个test.txt文件
}

StoreQuote::~StoreQuote()       //析构器,善后清理工作

{
    fileOutput.close();         //关闭文件 
}

void StoreQuote::inputQuote()   //函数体
{
    getline(cin, quote);
}

void StoreQuote::inputSpeaker() //函数体
{
    getline(cin, speaker);
}

bool StoreQuote::write()        //函数体
{
    if(fileOutput.is_open())    //文件成功打开
    {
        fileOutput << quote << "|" << speaker << endl; //写入
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    StoreQuote quote;
    cout << "请输入一句名言: " << endl;
    quote.inputQuote();

    cout << "请输入作者: " << endl;
    quote.inputSpeaker();

    if(quote.write())
    {
        cout << "成功写入文件" << endl;
    }
    else
    {
        cout << "写入文件失败" << endl;
        return 1;                        //main返回0为正常, 返回0为不正常
    }
    return 0;
}

