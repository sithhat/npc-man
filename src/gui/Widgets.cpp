#include <iostream>

#include "Widgets.h"

using namespace Gui;

void Glyph::Draw(Window*){
    std::cout << "Drawing!" << std::endl;
}

void Rectangle::Draw(Window* window){
    window->DrawRectangle(_x0, _y0, _x1, _y1);
}