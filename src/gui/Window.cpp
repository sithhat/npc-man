#include "WindowSystemFactory.h"

using namespace Gui;

Window::Window()
{
    
}

void CompositeWindow::Add(Window* child)
{
    _child_windows.push_back(child);
}

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
    return imp->DeviceRunGui(argc, argv);
}

void LogWindow::Present(){
    WindowImp* imp = GetWindowImp();
    imp->DevicePresentTextWindow();
    return;
}