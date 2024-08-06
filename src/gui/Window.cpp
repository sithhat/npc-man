#include "Window.h"
#include "WindowSystem.h"
#include "WindowImp.h"

using namespace Gui;

Gui::Window::Window()
{
    _windowImp = windowSystemFactory->CreateWindowImp();
}

void Gui::Window::MakeWindow()
{
    _windowImp->DeviceMakeWindow();
}