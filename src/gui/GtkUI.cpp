#include "GtkUI.h"

using namespace Gui;

GtkApplication* GtkApp::_instance = 0;
GtkWidget* GtkApp::_mainWindow = 0;

GtkApplication* GtkApp::Instance()
{
    Init();
    return _instance;
}

void GtkApp::Init()
{
    if (_instance == 0){
        _instance = gtk_application_new("npc.man.bstanley", G_APPLICATION_DEFAULT_FLAGS);
        g_signal_connect(_instance, "activate", G_CALLBACK(Activate), NULL);
        auto cancel = g_cancellable_new();
        GError* error = NULL;
        bool status = g_application_register(G_APPLICATION(_instance), cancel, &error);
    }
}

GtkWidget* GtkApp::GetMain()
{
    if (_mainWindow == 0){
        auto app = Instance();
        _mainWindow = gtk_application_window_new(app);
    }
    return _mainWindow;
}

void GtkApp::Activate(GtkApplication* app)//, gpointer* data)
{
    auto window = GetMain();
    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_window_present(GTK_WINDOW(window));
}

GtkApp::~GtkApp()
{
    g_object_unref(GtkApp::Instance());
}