#include <gtk/gtk.h>

#include "GuiFactory.h"
// #include "Widgets.h"

using namespace Gui;

GtkApplication* GtkApp::_instance = 0;

GtkApplication* GtkApp::Instance(){
    if (_instance == 0){
        _instance = gtk_application_new("npc.man.bstanley", G_APPLICATION_DEFAULT_FLAGS);
    }
    return _instance;
}

GtkApp::GtkApp(){}

void GtkGuiFactory::Activate(GtkApplication* app, gpointer* data){
    GtkWidget* window;
    window = gtk_application_window_new(app);
    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_window_present(GTK_WINDOW(window));
}

int GtkGuiFactory::MakeGui(int argc, char** argv){
    g_signal_connect(GtkApp::Instance(), "activate", G_CALLBACK(Activate), NULL);
    return g_application_run(G_APPLICATION(GtkApp::Instance()), argc, argv);
}

GtkGuiFactory::GtkGuiFactory(){}

GtkGuiFactory::~GtkGuiFactory(){
    g_object_unref(GtkApp::Instance());
}


