#include "html_writer.hpp"
#include "image_browser.hpp"
#include <iostream>
using namespace html_writer;
using ScoredImage = std::tuple<std::string, float>;
using ImageRow = std::array<ScoredImage, 3>;
int main() {
  std::vector<ImageRow> rows;
  ImageRow row1 = {{{"data/000000.png", 0.98f},
                    {"data/000100.png", 0.96f},
                    {"data/000200.png", 0.88f}}};
  ImageRow row2 = {{{"data/000300.png", 0.87f},
                    {"data/000400.png", 0.80f},
                    {"data/000500.png", 0.79f}}};
  ImageRow row3 = {{{"data/000600.png", 0.76f},
                    {"data/000700.png", 0.75f},
                    {"data/000800.png", 0.20f}}};
  rows.push_back(row1);
  rows.push_back(row2);
  rows.push_back(row3);
  image_browser::CreateImageBrowser("Image Browser", "style.css", rows);
}
/*
 OpenDocument();
    OpenHead();
    AddTitle("Image Browser");
    AddCSSStyle("style.css");
    CloseHead();
    OpenBody();
    OpenRow();
    AddImage("data/000000.png",0.98,true);
    AddImage("data/000100.png",0.96);
    AddImage("data/000200.png",0.88);
    CloseRow();
    OpenRow();
    AddImage("data/000300.png",0.87);
    AddImage("data/000400.png",0.80);
    AddImage("data/000500.png",0.79);
    CloseRow();
    OpenRow();
    AddImage("data/000600.png",0.76);
    AddImage("data/000700.png",0.75);
    AddImage("data/000800.png",0.20);
    CloseRow();
    CloseBody();
    CloseDocument();
*/