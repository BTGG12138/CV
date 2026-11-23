#include<iostream>
#include"html_writer.hpp"
#include"image_browser.hpp"
using namespace html_writer;
int main()
{
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
}