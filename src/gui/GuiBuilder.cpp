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

void GuiBuilder::SetWindowSystem(WindowSystem configuration){
    auto _windowSystemFactory = WindowSystemFactory::Instance();
    _windowSystemFactory->SetWindowSystem(configuration);
}

int GuiBuilder::MakeGui(int argc, char** argv){
    auto main = new MainWindow();
    return main->PresentMain(argc, argv);
}