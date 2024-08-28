#include "WindowSystemFactory.h"

using namespace Gui;

IdGenerator* IdGenerator::_instance = 0;

IdGenerator::IdGenerator()
{
    _count = 0;
}

IdGenerator* IdGenerator::Instance()
{
    if (_instance == 0)
    {
        _instance = new IdGenerator();
    }
    return _instance;
}

int IdGenerator::GenerateWindowId()
{
    _count = _count + 1;
    return _count;
}

Window::Window()
{
    IdGenerator* idGenerator = IdGenerator::Instance();
    _id = idGenerator->GenerateWindowId();
}

WindowImp* Window::GetWindowImp()
{
    if (_windowImp == 0)
    {
        _windowImp = WindowSystemFactory::Instance()->MakeWindowImp(_id);
    }
    return _windowImp;
}

int Window::GetId()
{
    return _id;
}

void CompositeWindow::Add(Window* child)
{
    _childWindows.push_back(child);
    WindowImp* imp = GetWindowImp();
    imp->ImpAdd(child->GetId());
}

MainWindowImp* MainWindow::GetMainWindowImp()
{
    if (_mainWindowImp == 0)
    {
        _mainWindowImp = WindowSystemFactory::Instance()->MakeMainWindowImp(_id);
    }
    return _mainWindowImp;
}

int MainWindow::PresentMain(int argc, char** argv)
{
    MainWindowImp* imp = GetMainWindowImp();
    return imp->ImpPresentMain(argc, argv);
}

void LogWindow::Present()
{
    // WidgetImp* imp = GetWidgetImp();
}