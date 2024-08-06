

#include "GuiFactory.h"
#include "GtkUI.h"
// #include "Window.h"
// #include "Widgets.h"

using namespace Gui;

GuiFactory* guiFactory = 0;

GtkGuiFactory::GtkGuiFactory()
{
    // windowSystemFactory = new GtkWindowSystemFactory;
}

GtkGuiFactory::~GtkGuiFactory()
{
    g_object_unref(GtkApp::Instance());
}

void GtkGuiFactory::Activate(GtkApplication* app, gpointer* data)
{
    GtkWidget* window;
    window = gtk_application_window_new(app);
    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_window_present(GTK_WINDOW(window));
}

int GtkGuiFactory::MakeGui(int argc, char** argv)
{
    g_signal_connect(GtkApp::Instance(), "activate", G_CALLBACK(Activate), NULL);
    return g_application_run(G_APPLICATION(GtkApp::Instance()), argc, argv);
}