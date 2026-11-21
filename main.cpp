#include<iostream>
#include<string>
#include<cstdlib>
#include<limits>
#include<algorithm>
#include<cctype>
std::string cinGrab()
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
    else if (std::count(bein.begin(),bein.end(),tail1)+
            std::count(bein.begin(),bein.end(),tail2)!=2) 
    {
        std::cerr << "[WARNING]" <<std::endl;
        exit(1);
    } 
    else 
    {
        bein.erase(std::remove_if(bein.begin(),bein.end(),
        [](char c) {
        return !std::isdigit(static_cast<unsigned char>(c));
        }), bein.end());
        return bein;
    }
}
int count(std::string bein)
{
    std::string temp;
    int tailNum1,tailNum2;
    for (char c : bein)
    {
        if (c ==' ')
        {
            if (!temp.empty())
            {
                tailNum1=std::stoi(temp);
            }
            temp.clear();
        }
        else
        {
            temp += c;
        }
    }
    if (!temp.empty())
    {
        tailNum2=std::stoi(temp);
    }
}
int main()
{
    std::cout<<count(cinGrab());
}