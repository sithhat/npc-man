#include <gtk/gtk.h>

namespace Gui{

    class GtkApp{
    public:
        static GtkApplication* Instance();
        ~GtkApp();
    protected:
        GtkApp() {};
    private:
        static GtkApplication* _instance;
    };
};