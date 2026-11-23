// @file      html_writer.h
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// 版权所有 (c) 2020 Ignacio Vizzo，保留所有权利
#ifndef HTML_WRITER_H_
#define HTML_WRITER_H_

#include <string>

namespace html_writer {

/**
 * @brief OpenDocument() 将向标准输出打印 HTML5 文件的开头。此函数应仅在
 * 测试程序开始时调用一次。
 */
void OpenDocument();

/**
 * @brief CloseDocument() 将关闭 HTML5 文件，此函数应仅在测试程序结束时
 * 调用一次。
 */
void CloseDocument();

/**
 * @brief 为了让你的应用程序看起来更美观，你可以选择为 Web 应用程序提供
 * 使用 CSS 的样式表。
 *
 * @param stylesheet CSS 文件所在的路径，通常为
 * "<path>/style.css"
 */
void AddCSSStyle(const std::string& stylesheet);

/**
 * @brief 此函数向你的 Web 应用程序添加标题
 *
 * @param title 包含标题的字符串，长度可任意。
 */
void AddTitle(const std::string& title);

/**
 * @brief 这将在你的 Web 应用程序中打开一个 <body> 子句。
 */
void OpenBody();

/**
 * @brief 这将在你的 Web 应用程序中关闭一个 </body> 子句。
 */
void CloseBody();

/**
 * @brief 这将为你的应用程序打开一个新的行分区，请确保类 "row" 已在
 * CSS 文件（如果有）中定义。
 */
void OpenRow();

/**
 * @brief 这将关闭你的应用程序的一个行分区，请确保仅在此前调用过
 * OpenRow() 后才调用此函数
 */
void CloseRow();

/**
 * @brief 此函数将使用 <img src=""> 子句向你的 Web 应用程序添加新图像。
 * 它还会打印图像的分数和图像名称。如果这恰好是你添加到 Web 应用程序的
 * 第一张图像，那么它应被高亮显示。
 *
 * @param img_path 图像路径 [png, jpg]
 * @param score 给定图像的分数
 * @param highlight 如果是第一张图像，则必须为 true。
 */
void AddImage(const std::string& img_path, float score, bool highlight = false);

void OpenHead();

void CloseHead();
}  // namespace html_writer

#endif  // HTML_WRITER_H_