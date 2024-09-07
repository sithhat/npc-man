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
        virtual void ImpTextView() {};
        virtual void ImpPresent() {};
    protected:
        int _id;
    };

    class MainWindowImp
    {
    public:
        virtual int ImpPresentMain(int, char**) { return 0; };
        virtual void ImpWindowAdd(int) {};
    };

    class GtkWidgetImp : virtual public WidgetImp
    {
    public:
        GtkWidgetImp(int);
        ~GtkWidgetImp() {};
        void ImpTextView() override;
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
        void ImpWindowAdd(int) override;
    };

    static std::map<int, GtkWidgetImp*> GtkWidgetMap;
};