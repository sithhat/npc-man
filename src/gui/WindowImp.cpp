#include "WindowImp.h"

using namespace Gui;

std::map<int, GtkWindowImp*> GtkWidgetMap = {};

WindowImp::WindowImp(int id)
{
    _id = id;
}

int WindowImp::GetId()
{
    return _id;
}

GtkWidget* GtkWindowImp::_widget = 0;

GtkWindowImp::GtkWindowImp(int id)
    : WindowImp(id)
{
    GtkWidgetMap[_id] = this;
}

int GtkWindowImp::DevicePresentMain(int argc, char** argv)
{
    g_signal_connect(GtkApp::Instance(), "activate", G_CALLBACK(Activate), NULL);
    auto status = g_application_run(G_APPLICATION(GtkApp::Instance()), argc, argv);
    return status;
}

void GtkWindowImp::DeviceAdd(int id)
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

void GtkWindowImp::Activate(GtkApplication* app, gpointer* data)
{
    auto window = Get();
    gtk_window_set_application(GTK_WINDOW(window), app);
    gtk_window_present(GTK_WINDOW(window));
}

void GtkWindowImp::DeviceTextWidget()
{
    auto text_view = gtk_text_view_new();
    auto buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    auto text = "";
    gtk_text_buffer_set_text(buffer, text, -1);
}

GtkWidget* GtkWindowImp::Get()
{
    if (_widget == 0){
        auto app = GtkApp::Instance();
        _widget = gtk_application_window_new(app);
    }
    return _widget;
}