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

WindowImp* WindowSystemFactory::MakeWindowImp(int id)
{
    switch(_configuration)
    {
        case GTK: return new GtkWindowImp(id);
        default: return new GtkWindowImp(id);
    }
}

