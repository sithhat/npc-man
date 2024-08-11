#include "WindowSystemFactory.h"

using namespace Gui;

WindowImp* Window::GetWindowImp()
{
    if (_windowImp == 0)
    {
        _windowImp = WindowSystemFactory::Instance()->MakeWindowImp();
    }
    return _windowImp;
}

int MainWindow::PresentMain(int argc, char** argv){
    WindowImp* imp = GetWindowImp();
    return imp->DevicePresentMain(argc, argv);
}