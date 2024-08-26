#include "WindowImp.h"

using namespace Gui;

GtkWidget* GtkWindowImp::_mainWindowInstance = 0;

GtkWindowImp::GtkWindowImp(){}

int GtkWindowImp::DeviceRunGui(int argc, char** argv)
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
    auto window = MainWindowInstance();
    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_window_present(GTK_WINDOW(window));
}

void GtkWindowImp::DevicePresentTextWindow()
{
    GtkWidget* window;
    window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), "Log");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    auto textView = gtk_text_view_new();
    auto buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textView));
    auto text = "";
    gtk_text_buffer_set_text(buffer, text, -1);
}

GtkWidget* GtkWindowImp::MainWindowInstance()
{
    if (_mainWindowInstance == 0){
        auto app = GtkApp::Instance();
        _mainWindowInstance = gtk_application_window_new(app);
    }
    return _mainWindowInstance;
}