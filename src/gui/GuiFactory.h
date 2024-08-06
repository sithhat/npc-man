#include <gtk/gtk.h>

// #include "Widgets.h"

namespace Gui{

    class GuiFactory{
    public:
        GuiFactory() {};
        virtual ~GuiFactory() {};
        virtual int MakeGui(int, char**) { return 0; };
    };
    
    class GtkGuiFactory : public GuiFactory{
    public:
        GtkGuiFactory();
        ~GtkGuiFactory();
        int MakeGui(int, char**);
        // Widgets::Glyph* CreateScrollbar();
    private:
        static void Activate(GtkApplication*, gpointer*);
        
    };

    static GuiFactory* guiFactory;
}