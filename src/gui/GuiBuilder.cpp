#include <functional>
#include <memory>

#include "GuiBuilder.h"
#include "../logging/Logger.h"

using namespace Gui;
using namespace Logging;

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
    auto logger = new Logging::Logger();
    logger->Log(Logging::LogLevel::INFO, "Adding log window to main.");
    mainWindow->WindowAdd(logWindow);
    logWindow->Log(logger->GetQueue());
    return mainWindow->PresentMain(argc, argv);
}