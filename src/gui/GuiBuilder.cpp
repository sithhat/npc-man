#include "GuiBuilder.h"

using namespace Gui;

GuiBuilder* GuiBuilder::_instance = 0;

GuiBuilder* GuiBuilder::Instance()
{
    if (_instance == 0){
        _instance = new GuiBuilder();
    }
    return _instance;
}

void GuiBuilder::SetWindowSystem(WindowSystem configuration)
{
    auto _windowSystemFactory = WindowSystemFactory::Instance();
    _windowSystemFactory->SetWindowSystem(configuration);
}

int GuiBuilder::MakeGui(int argc, char** argv)
{
    auto mainWindow = new MainWindow();
    auto logWindow = new LogWindow();
    mainWindow->WindowAdd(logWindow);
    return mainWindow->PresentMain(argc, argv);
}