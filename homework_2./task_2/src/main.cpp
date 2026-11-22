#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
bool IsAllDigit(std::string beIn) {
  if (beIn.empty())
    return false;
  for (char c : beIn) {
    if (!isdigit(c)) {
      return false;
    }
  }
  return true;
}
std::vector<std::string> Spli(std::string beIn, char spli) {
  std::vector<std::string> beBack;
  std::string tmp;
  for (char c : beIn) {
    if (c == spli) {
      if (!tmp.empty())
        beBack.push_back(tmp);
      tmp.clear();
    } else
      tmp += c;
  }
  if (!tmp.empty())
    beBack.push_back(tmp);
  if (beIn == tmp) {
    std::cerr << "[Warning]1" << std::endl;
    exit(1);
  }
  return beBack;
}
std::vector<std::string> DoSpi(std::vector<std::string> beIn) {
  std::vector<std::string> fron, bac, beBack;
  fron = Spli(beIn[0], '.');
  bac = Spli(beIn[1], '.');
  beBack.push_back(fron[0]);
  beBack.push_back(fron[1]);
  beBack.push_back(bac[0]);
  beBack.push_back(bac[1]);
  return beBack;
}
std::vector<std::string> CinGrab(std::string beIn1, std::string beIn2) {
  std::vector<std::string> beSpli;
  if (beIn1.find('.') != std::string::npos and
      beIn2.find('.') != std::string::npos) {
    std::vector<std::string> beIn;
    beIn.push_back(beIn1);
    beIn.push_back(beIn2);
    beSpli = DoSpi(beIn);
  } else {
    std::cerr << "[Warning]3" << std::endl;
    exit(1);
  }
  bool rBack = (beSpli[1] == "txt" and beSpli[3] == "txt") or
               (beSpli[1] == "png" and beSpli[3] == "png") or
               (beSpli[1] == "txt" and beSpli[3] == "png");
  bool rFront = IsAllDigit(beSpli[0]) or IsAllDigit(beSpli[2]);
  if (rBack and rFront) {
    return beSpli;
  } else {
    std::cerr << "[Warning]4" << std::endl;
    exit(1);
  }
}
int CinDiff(std::vector<std::string> beSpli) {
  int num1 = std::stoi(beSpli[0]);
  int num2 = std::stoi(beSpli[2]);
  if (beSpli[1] == "txt" and beSpli[3] == "txt") {
    return (num1 + num2) / 2;
  } else if (beSpli[1] == "png" and beSpli[3] == "png") {
    return num1 + num2;
  } else {
    return num1 % num2;
  }
}
int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "[Warning]0" << std::endl;
    exit(1);
  }
  std::string beIn1 = argv[1];
  std::string beIn2 = argv[2];
  std::vector<std::string> beSpli = CinGrab(beIn1, beIn2);
  std::cout << CinDiff(beSpli) << std::endl;
}