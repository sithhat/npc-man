#include "gui/GuiFactory.h"

using namespace Gui;

int main(int argc, char** argv)
{
  guiFactory = new GtkGuiFactory();
  return guiFactory->MakeGui(argc, argv);
}