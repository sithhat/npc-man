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

Widget::Widget()
{
    IdGenerator* idGenerator = IdGenerator::Instance();
    _id = idGenerator->GenerateWindowId();
    _widgetImp = 0;
}

WidgetImp* Widget::GetWidgetImp()
{
    if (_widgetImp == 0)
    {
        _widgetImp = WindowSystemFactory::Instance()->MakeWidgetImp(_id);
    }
    return _widgetImp;
}

int Widget::GetId()
{
    return _id;
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

void MainWindow::WindowAdd(Widget* child)
{
    _childWindows.push_back(child);
    MainWindowImp* imp = GetMainWindowImp();
    imp->ImpWindowAdd(child->GetId());
}

LogWindow::LogWindow()
    : Widget()
{
    WidgetImp* imp = GetWidgetImp();
    imp->ImpTextView();
}

void LogWindow::Log(std::string text)
{
    WidgetImp* imp = GetWidgetImp();
    const char* c_string = text.c_str();
    int length = text.length();
    imp->ImpAppendTextToBuffer(c_string, length);
}