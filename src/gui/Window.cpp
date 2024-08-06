#include "Window.h"

using namespace Gui;

WindowSystemFactory* windowSystemFactory = 0;

Window::Window(){
    _windowImp = windowSystemFactory->CreateWindowImp();
}

void Window::DrawRectangle(int x0, int y0, int x1, int y1){
    _windowImp->DeviceDrawRectangle(x0, y0, x1, y1);
}

WindowImp* GtkWindowSystemFactory(){
    return new GtkWindowImp;
}