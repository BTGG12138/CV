#include<iostream>
#include<string>
#include<cstdlib>
#include<limits>
std::string cinGrab()
{
    std::string bein;
    std::cin>>bein;
    if(std::cin.fail())
    {
        std::cerr << "Error encountered, exiting...\n";
        std::cin.clear(); // 清除失败标志
        // 忽略缓冲区所有字符直到换行
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        exit(1);
    }
    else if (cinNum < 0 or cinNum > 99) 
    {
        std::cerr << "[WARNING] : Number must be between 0 and 99" << endl;
        std::cout << randomNum << endl;
        exit(1);
    } 
    else 
    {
        return cinNum;
    }
}
int count(std::string bein)
{

}
int main()
{
    std::cout<<count(cinGrab());
}