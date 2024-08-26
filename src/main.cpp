#include "gui/GuiBuilder.h"

using namespace Gui;

int main(int argc, char** argv)
{
  auto guiBuilder = GuiBuilder::Instance();
  auto configuration = GTK;
  guiBuilder->SetWindowSystem(configuration);
  return guiBuilder->MakeGui(argc, argv);
}