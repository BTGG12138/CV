#include <cstdlib> // exit
#include <iostream>
#include <limits>
#include <random>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int CinNum(int randomNum) {
  int cinNum;
  cin >> cinNum;
  if (cin.fail()) {
    cerr << "Error encountered, exiting...\n";
    cin.clear(); // 清除失败标志
    // 忽略缓冲区所有字符直到换行
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << randomNum << endl;
    exit(1);
    //- `return 1;`：**退出当前函数**；只有写在 `main`
    // 里面，才会结束整个程序、设置进程退出码
    //- `exit(1);`：**直接结束整个程序**，在哪一个函数调用都可以，立刻终止
  } else if (cinNum < 0 or cinNum > 99) {
    cerr << "[WARNING] : Number must be between 0 and 99" << endl;
    cout << randomNum << endl;
    exit(1);
  } else {
    return cinNum;
  }
}
int RandomNum() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<int> dist(0, 99);
  return dist(gen);
}
bool IfAndOut(int cinNum, int randomNum) {
  if (cinNum == randomNum) {
    cout << "You Win" << endl;
    cout << randomNum << endl;
    return true;
  } else if (cinNum < randomNum) {
    cout << "Too Small" << endl;
    return false;
  } else {
    cout << "Too Big" << endl;
    return false;
  }
}
int main() {
  bool isWin = false;
  int randomNum = RandomNum();
  while (!isWin) {
    int cinNum = CinNum(randomNum);
    isWin = IfAndOut(cinNum, randomNum);
  }
}
