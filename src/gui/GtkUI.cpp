#include "GtkUI.h"

using namespace Gui;

GtkApplication* GtkApp::_instance = 0;

GtkApplication* GtkApp::Instance(){
    if (_instance == 0){
        _instance = gtk_application_new("npc.man.bstanley", G_APPLICATION_DEFAULT_FLAGS);
    }
    return _instance;
}




