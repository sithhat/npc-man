#include "WidgetImp.h"

using namespace Gui;

std::map<int, GtkWidgetImp*> GtkWidgetMap = {};


WidgetImp::WidgetImp(int id)
{
    _id = id;
}

int WidgetImp::GetId()
{
    return _id;
}

GtkWidgetImp::GtkWidgetImp(int id)
    : WidgetImp(id)
{
    GtkWidgetMap[_id] = this;
}

GtkWidget* GtkWidgetImp::Get()
{
    return _widget;
}

void GtkMainWindowImp::ImpWindowAdd(int id)
{
    auto child = GtkWidgetMap[id]->Get();
    gtk_window_set_child(GTK_WINDOW(GtkApp::GetMain()), child);
}

void GtkWidgetImp::ImpTextView()
{
    _widget = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(_widget), FALSE);
    auto buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(_widget));
    auto text = "";
    gtk_text_buffer_set_text(buffer, text, -1);
}

void GtkWidgetImp::ImpAppendTextToBuffer(const char* text, int length)
{
    auto buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(_widget));
    auto end = new GtkTextIter;
    gtk_text_buffer_get_end_iter(buffer, end);
    gtk_text_buffer_insert(buffer, end, text, length);
}

GtkMainWindowImp::GtkMainWindowImp(int id)
    : WidgetImp(id)
    , GtkWidgetImp(id) {}

int GtkMainWindowImp::ImpPresentMain(int argc, char** argv)
{
    auto status = g_application_run(G_APPLICATION(GtkApp::Instance()), argc, argv);
    return status;
}

