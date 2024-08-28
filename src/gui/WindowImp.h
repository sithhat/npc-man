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

    class WindowImp : virtual public WidgetImp
    {
    public:
        WindowImp(int);
    };

    class MainWindowImp : virtual public WindowImp
    {
    public:
        MainWindowImp(int);
        virtual int ImpPresentMain(int, char**) { return 0; };
    };

    class GtkWidgetImp : virtual public WidgetImp
    {
    public:
        GtkWidgetImp(int);
        ~GtkWidgetImp() {};
        GtkWidget* Get();
    private:
        GtkWidget* _widget;
    };

    class GtkWindowImp : virtual public WindowImp, virtual public GtkWidgetImp
    {
    public:
        GtkWindowImp(int);
        ~GtkWindowImp() {};
        void ImpAdd(int) override;
    };

    class GtkMainWindowImp : public MainWindowImp, public GtkWindowImp
    {
    public:
        GtkMainWindowImp(int);
        ~GtkMainWindowImp() {};
        int ImpPresentMain(int, char**) override;
        static void Activate(GtkApplication*, gpointer*);
    private:
        static GtkWidget* GetMain();
        static GtkWidget* _mainWindow;
    };

    static std::map<int, GtkWidgetImp*> GtkWidgetMap;
};