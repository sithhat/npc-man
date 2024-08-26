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

WindowImp* WindowSystemFactory::MakeWindowImp()
{
    switch(_configuration)
    {
        case GTK: return new GtkWindowImp();
        default: return new GtkWindowImp();
    }
}