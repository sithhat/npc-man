#include "gui/WindowSystemFactory.h"

using namespace Gui;

int main(int argc, char** argv)
{
  configuration = GTK;
  auto main = new MainWindow();
  return main->PresentMain(argc, argv);
}