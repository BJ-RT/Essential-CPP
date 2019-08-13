使用你最称手的编辑工具,输入两行(或更多)文字并存盘。然后编写一个程序,打开该文本文件,将其中每个字都读取到一个 vector< string>对象中。
遍历该 vector,将内容显示到cout。然后利用泛型算法sort(),对所有文字排序:  #include <algorithm> sort( container begin(), container end());
再将排序后的结果输出到另一个文件。

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main()
{
    ifstream infile("D:\\obj\\text.txt");
    if(!infile)
    {
        cerr << "opps! unable to open input file\n";
        return -1;
    }
    ofstream outfile("D:\\obj\\text.sort");
    if(!outfile)
    {
        cerr << "opps! unable to open output file\n";
        return -2;
    }
    string word;
    vector<string> text;
    while (infile >> word)
        text.push_back(word);

    int ix;
    cout << "unsorted text: \n";

    for (ix = 0; ix < text.size(); ++ix)
        cout << text[ix] << " ";
    cout << endl;

    sort(text.begin(),text.end());

    outfile << "sorted text: \n";
    for (ix = 0; ix < text.size(); ++ix)
        outfile << text[ix] << " ";
    outfile << endl;
    return 0;
}
