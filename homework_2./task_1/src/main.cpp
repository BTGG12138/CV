#include <iostream>
#include <random>
using std::cin;
using std::cout;
using std::endl;
int CinNum()
{
    int cinNum;
    cin>>cinNum;
    return cinNum;
}
int RandomNum()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(0,99);
    return dist(gen);
}
bool IfAndOut(int cinNum,int randomNum)
{
    if(cinNum==randomNum)
    {
        cout<<"You Win"<<endl;
        return true;
    }
    else if(cinNum<randomNum)
    {
        cout<<"Too Small"<<endl;
        return false;
    }
    else
    {
        cout<<"Too Big"<<endl;
        return false;
    }
}
int main()
{
    bool isWin=false;
    int randomNum=RandomNum();
    while(!isWin)
    {
        int cinNum=CinNum();
        isWin=IfAndOut(cinNum,randomNum);
    }
}
    