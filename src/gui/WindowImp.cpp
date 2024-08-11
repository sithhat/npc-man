#include "WindowImp.h"

using namespace Gui;

GtkWindowImp::GtkWindowImp(){}

int GtkWindowImp::DevicePresentMain(int argc, char** argv)
{
    g_signal_connect(GtkApp::Instance(), "activate", G_CALLBACK(Activate), NULL);
    auto status = g_application_run(G_APPLICATION(GtkApp::Instance()), argc, argv);
    return status;
}

void GtkWindowImp::DevicePresent()
{
    GtkWidget* window;
    window = gtk_window_new();
    gtk_window_set_application(GTK_WINDOW(window), GtkApp::Instance());
    gtk_window_present(GTK_WINDOW(window));
}

void GtkWindowImp::Activate(GtkApplication* app, gpointer* data)
{
    GtkWidget* window;
    window = gtk_application_window_new(app);
    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_window_present(GTK_WINDOW(window));
}