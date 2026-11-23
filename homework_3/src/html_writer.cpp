#include "html_writer.hpp"
#include <iomanip>
#include <iostream>
#include <string>
using std::cerr;
using std::cout;
namespace html_writer {

/**
 * @brief OpenDocument() 将向标准输出打印 HTML5 文件的开头。此函数应仅在
 * 测试程序开始时调用一次。
 */
void OpenDocument() {
  cout << "<!DOCTYPE html>\n";
  cout << "<html>\n";
}

/**
 * @brief CloseDocument() 将关闭 HTML5 文件，此函数应仅在测试程序结束时
 * 调用一次。
 */
void CloseDocument() { cout << "</html>\n"; }

/**
 * @brief 为了让你的应用程序看起来更美观，你可以选择为 Web 应用程序提供
 * 使用 CSS 的样式表。
 *
 * @param stylesheet CSS 文件所在的路径，通常为
 * "<path>/style.css"
 */
void AddCSSStyle(const std::string &stylesheet) {
  cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"" << stylesheet
       << "\" />\n";
}

/**
 * @brief 此函数向你的 Web 应用程序添加标题
 *
 * @param title 包含标题的字符串，长度可任意。
 */
void AddTitle(const std::string &title) {
  cout << "<title>" << title << "</title>\n";
}

/**
 * @brief 这将在你的 Web 应用程序中打开一个 <body> 子句。
 */
void OpenBody() { cout << "<body>\n"; }

/**
 * @brief 这将在你的 Web 应用程序中关闭一个 </body> 子句。
 */
void CloseBody() { cout << "</body>\n"; }

/**
 * @brief 这将为你的应用程序打开一个新的行分区，请确保类 "row" 已在
 * CSS 文件（如果有）中定义。
 */
void OpenRow() { cout << "<div class=\"row\">\n"; }

/**
 * @brief 这将关闭你的应用程序的一个行分区，请确保仅在此前调用过
 * OpenRow() 后才调用此函数
 */
void CloseRow() { cout << "</div>\n"; }

/**
 * @brief 此函数将使用 <img src=""> 子句向你的 Web 应用程序添加新图像。
 * 它还会打印图像的分数和图像名称。如果这恰好是你添加到 Web 应用程序的
 * 第一张图像，那么它应被高亮显示。
 *
 * @param img_path 图像路径 [png, jpg]
 * @param score 给定图像的分数
 * @param highlight 如果是第一张图像，则必须为 true。
 *  该库将只处理 png 或 jpg 文件。如果使用了任何其他类型的扩展名，它应向 stderr
打印错误。 •   当你使用 AddImage 函数向 Web 应用添加图像时，你需要考虑以下规则：
    (a) 如果用户要求，你应能够高亮该图像（参见 Web 应用示例，第一张图像）
    (b) 图像标题应仅为图像的文件名。它不应包含任何其他路径。
    (c) 图像分数应仅使用 2 位十进制数字报告。
*/
std::string RFind(std::string beIn, char mark) {
  std::string beBack;
  size_t p = beIn.rfind(mark);
  if (p != std::string::npos) {
    beBack = beIn.substr(p + 1);
  } else {
    beBack = beIn;
  }
  return beBack;
}
void AddImage(const std::string &img_path, float score, bool highlight) {
  if (img_path.find(".jpg") == std::string::npos and
      img_path.find(".png") == std::string::npos) {
    exit(1);
  }
  if (highlight) {
    cout << "<div class=\"column\" style=\"border: 5px solid green;\">\n";
  } else {
    cout << "<div class=\"column\">\n";
  }
  std::string name = RFind(img_path, '/');
  cout << "<h2>" << name << "</h2>\n";
  cout << "<img src=\"" << img_path << "\" />\n";
  cout << "<p>score =" << std::fixed << std::setprecision(2) << score
       << "</p>\n";
  cout << "</div>\n";
}

void OpenHead() { cout << "<head>\n"; }

void CloseHead() { cout << "</head>\n"; }

} // namespace html_writer