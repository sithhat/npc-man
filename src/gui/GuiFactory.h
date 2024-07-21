#include <gtk/gtk.h>

// #include "Widgets.h"

namespace Gui{

    class GtkApp{
    public:
        static GtkApplication* Instance();
    protected:
        GtkApp();
    private:
        static GtkApplication* _instance;
    };
    
    class GtkGuiFactory{
    public:
        GtkGuiFactory();
        ~GtkGuiFactory();
        int MakeGui(int, char**);
        // Widgets::Glyph* CreateScrollbar();
    private:
        static void Activate(GtkApplication*, gpointer*);
        
    };
}