#include "WindowImp.h"

using namespace Gui;

std::map<int, GtkWidgetImp*> GtkWidgetMap = {};
GtkWidget* GtkMainWindowImp::_mainWindow = 0;

WidgetImp::WidgetImp(int id)
{
    _id = id;
}

int WidgetImp::GetId()
{
    return _id;
}

WindowImp::WindowImp(int id)
    : WidgetImp(id) {}

MainWindowImp::MainWindowImp(int id)
    : WindowImp(id)
    , WidgetImp(id) {}

GtkWidgetImp::GtkWidgetImp(int id)
    : WidgetImp(id)
{
    GtkWidgetMap[_id] = this;
}

GtkWidget* GtkWidgetImp::Get()
{
    return _widget;
}

GtkWindowImp::GtkWindowImp(int id)
    : GtkWidgetImp(id) 
    , WindowImp(id)
    , WidgetImp(id) {}

void GtkWindowImp::ImpAdd(int id)
{
    auto child = GtkWidgetMap[id]->Get();
    gtk_window_set_child(GTK_WINDOW(Get()), child);
}

// void GtkWindowImp::DevicePresent()
// {
//     GtkWidget* window;
//     window = gtk_window_new();
//     gtk_window_set_application(GTK_WINDOW(window), GtkApp::Instance());
//     gtk_window_present(GTK_WINDOW(window));
// }

// void GtkWindowImp::ImpTextWidget()
// {
//     auto text_view = gtk_text_view_new();
//     auto buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
//     auto text = "";
//     gtk_text_buffer_set_text(buffer, text, -1);
// }

GtkMainWindowImp::GtkMainWindowImp(int id)
    : GtkWindowImp(id)
    , GtkWidgetImp(id)
    , MainWindowImp(id)
    , WindowImp(id)
    , WidgetImp(id) {}

GtkWidget* GtkMainWindowImp::GetMain()
{
    if (_mainWindow == 0){
        auto app = GtkApp::Instance();
        _mainWindow = gtk_application_window_new(app);
    }
    return _mainWindow;
}

int GtkMainWindowImp::ImpPresentMain(int argc, char** argv)
{
    g_signal_connect(GtkApp::Instance(), "activate", G_CALLBACK(Activate), NULL);
    auto status = g_application_run(G_APPLICATION(GtkApp::Instance()), argc, argv);
    return status;
}

void GtkMainWindowImp::Activate(GtkApplication* app, gpointer* data)
{
    auto window = GetMain();
    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_window_present(GTK_WINDOW(window));
}