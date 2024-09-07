#include <gtk/gtk.h>

namespace Gui{

    class GtkApp{
    public:
        ~GtkApp();
        static GtkApplication* Instance();
        static void Init();
        static void Activate(GtkApplication*);
        static GtkWidget* GetMain();
    protected:
        GtkApp() {};
    private:
        static GtkWidget* _mainWindow;
        static GtkApplication* _instance;
    };
};