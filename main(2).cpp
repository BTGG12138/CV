/*
2.（5 分）程序将只接受 2 个参数作为输入。两个参数都将是文件名，格式如下：“<INT>.<EXT>”，下面展示了输入参数示例。你的程序需要处理这些输入参数并提供一些关于它们的信息，所有输出都应打印到 stdout。

B.1 通过测试的要求
• 输出程序名称应为 task_2
• 你应检查程序只提供了两个且仅两个输入参数，否则打印错误消息并中止执行。
• 如果文件扩展名为“.txt”，你需要输出参数中第一个数字和最后一个数字之间的平均值。
• 如果文件扩展名为“.png”，你需要输出参数中第一个数字和最后一个数字之间的和。
• 如果第一个文件扩展名为“.txt”而最后一个为“.png”，你应输出第一个数字和最后一个数字之间的取模除法结果。
• 如果任何扩展名不匹配上述条件，那么你必须中止程序执行，并向 stderr 打印错误消息。

注意：在成功（无错误）的情况下，输出应位于你打印到 stdout 的任何内容的最后一行，否则测试将失败。

B.2 用法示例
cdcpp−homeworks/homework2cdcpp−homeworks/homework2​ ./bin/task_2 100.txt 200.txt
$ ./bin/task_2 100.doc 100.doc # 无效，应给出错误
*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<limits>
#include<vector>
#include<algorithm>
#include<cctype>
std::string GetBack(const std::string& s)
{
    size_t p= s.find('.');
    if(p == std::string::npos) return "";
    return s.substr(p+1,3);
}
std::string GetFront(const std::string& s)
{
    size_t p= s.find('.');
    if(p == std::string::npos) return "";
    return s.substr(p-1,3);
}
std::vector<std::string> GrabBack(std::string bein)
{
    std::vector<std::string> beinBack;
    std::string tmp;
    for(char c : bein){
        if(c ==' '){
            if(!tmp.empty()) beinBack.push_back(GetBack(tmp));
            tmp.clear();
        }else tmp += c;
    }
    if(!tmp.empty()) beinBack.push_back(GetBack(tmp));
    return beinBack;
}
std::string CinGrab()
{
    std::string bein;
    std::string tail1=".txt",tail2=".png";
    std::cin>>bein;
    if(std::cin.fail())
    {
        std::cerr << "Error encountered, exiting...\n";
        std::cin.clear(); // 清除失败标志
        // 忽略缓冲区所有字符直到换行
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        exit(1);
    }
    std::vector<std::string> beinBack=GrabBack(bein);
    if ((beinBack.front()==".txt" and beinBack.back()==".txt")or
            (beinBack.front()==".png" and beinBack.back()==".png")or
            (beinBack.front()==".txt" and beinBack.back()==".png"))
    {
        return bein;
    } 
    else 
    {
        std::cerr<<"[Warning]"<<std::endl;
        exit(1);
    }
}
int CinDiff(std::string bein)
{

}
int main()
{
    std::string bein=CinGrab();
    CinDiff(bein);
}