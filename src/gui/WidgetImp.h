#include <list>
#include <map>
#include "GtkUI.h"

namespace Gui {

    class WidgetImp
    {
    public:
        WidgetImp(int);
        int GetId();
        virtual ~WidgetImp() {};
        virtual void ImpAdd(int) {};
    protected:
        int _id;
    };

    class MainWindowImp
    {
    public:
        virtual int ImpPresentMain(int, char**) { return 0; };
    };

    class GtkWidgetImp : virtual public WidgetImp
    {
    public:
        GtkWidgetImp(int);
        ~GtkWidgetImp() {};
        void ImpAdd(int) override;
        GtkWidget* Get();
    private:
        GtkWidget* _widget;
    };

    class GtkMainWindowImp : public GtkWidgetImp, virtual public MainWindowImp
    {
    public:
        GtkMainWindowImp(int);
        ~GtkMainWindowImp() {};
        int ImpPresentMain(int, char**) override;
        static void Activate(GtkApplication*);//, gpointer*);
    private:
        static GtkWidget* GetMain();
        static GtkWidget* _mainWindow;
    };

    static std::map<int, GtkWidgetImp*> GtkWidgetMap;
};