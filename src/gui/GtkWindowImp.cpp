#include "gtk/gtk.h"

#include "GtkWindowImp.h"

using namespace Gui;

GtkWindowImp::GtkWindowImp(){}

void GtkWindowImp::DeviceMakeWindow()
{
    GtkWidget* window;
    window = gtk_window_new();
    gtk_window_set_application(GTK_WINDOW(window), GtkApp::Instance());
    gtk_window_present(GTK_WINDOW(window));
}