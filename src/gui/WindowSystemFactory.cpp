#include "WindowSystemFactory.h"

using namespace Gui;

WindowSystemFactory* WindowSystemFactory::_instance = 0;

WindowSystemFactory* WindowSystemFactory::Instance()
{
    if (_instance == 0)
    {
        _instance = new WindowSystemFactory();
    }
    return _instance;
}

void WindowSystemFactory::SetWindowSystem(WindowSystem configuration){
    _configuration = configuration;
}

WidgetImp* WindowSystemFactory::MakeWidgetImp(int id)
{
    switch(_configuration)
    {
        case GTK: return new GtkWidgetImp(id);
        default: return new GtkWidgetImp(id);
    }    
}

MainWindowImp* WindowSystemFactory::MakeMainWindowImp(int id)
{
    switch(_configuration)
    {
        case GTK: return new GtkMainWindowImp(id);
        default: return new GtkMainWindowImp(id);
    }
}