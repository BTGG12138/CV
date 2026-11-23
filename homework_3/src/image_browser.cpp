#include"image_browser.hpp"
#include <array>
#include <string>
#include <tuple>
#include <vector>

namespace image_browser {

/// 一些实用名称类型，它们将使代码更具可读性
using ScoredImage = std::tuple<std::string, float>;
using ImageRow = std::array<ScoredImage, 3>;

/**
 * @brief 此函数负责在 Web 应用程序中添加完整的一行。一行始终由 3 列组成，
 * 每列包含一张带有给定分数的图像。
 *
 * @param row          包含 3 张图像以及每张图像分数的一组数据。
 * @param first_row    如果这是第一行，则第一张图像应被高亮显示。
 */
void AddFullRow(const ImageRow& row, bool first_row );

/**
 * @brief 创建一个图像浏览器应用程序。此函数应完全自包含，并应采取所有必要操作
 * 来创建图像 Web 浏览器应用程序。
 *
 * @param title      Web 应用程序的标题。
 * @param stylesheet CSS 样式（如果有）。
 * @param rows       一组 ImageRow，包含所有要显示的给定图像。
 */
void CreateImageBrowser(const std::string& title, const std::string& stylesheet,
                        const std::vector<ImageRow>& rows);

}  // namespace image_browser