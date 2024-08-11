#include "WindowSystemFactory.h"

using namespace Gui;

WindowSystemFactory* WindowSystemFactory::_instance = 0;
WindowSystem configuration = GTK;

WindowSystemFactory* WindowSystemFactory::Instance()
{
    if (_instance == 0){
        _instance = new WindowSystemFactory();
    }
    return _instance;
}

WindowImp* WindowSystemFactory::MakeWindowImp()
{
    switch(configuration)
    {
        case GTK: return new GtkWindowImp();
        default: return new GtkWindowImp();
    }
}