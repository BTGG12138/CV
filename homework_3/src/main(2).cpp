#include<iostream>
#include"html_writer.hpp"
#include"image_browser.hpp"
using namespace html_writer;
using ScoredImage = std::tuple<std::string, float>;
using ImageRow = std::array<ScoredImage, 3>;
int main()
{
    std::vector<ImageRow> rows;
    ImageRow row1=
    {{
        {"data/000000.png",0.98f},
        {"data/000100.png",0.96f},
        {"data/000200.png",0.88f}
    }};
    ImageRow row2=
    {{
        {"data/000300.png",0.87f},
        {"data/000400.png",0.80f},
        {"data/000500.png",0.79f}
    }};
    ImageRow row3=
    {{
        {"data/000600.png",0.76f},
        {"data/000700.png",0.75f},
        {"data/000800.png",0.20f}
    }};
    rows.push_back(row1);
    rows.push_back(row2);
    rows.push_back(row3);
    image_browser::CreateImageBrowser("Image Browser","style.css",rows);
}