#include <list>
#include <map>
#include "GtkUI.h"

namespace Gui {

    // Abstract class for hiding window-system dependent implementation
    class WindowImp
    {
    public:
        WindowImp(int);
        int GetId();
        ~WindowImp() {};
        virtual int DevicePresentMain(int, char**) { return 0; };
        virtual void DeviceAdd(int) {};
        virtual void DeviceTextWidget() {};
    protected:
        int _id;
    };

    // Concrete class for gtk implementations
    class GtkWindowImp : public WindowImp
    {
    public:
        GtkWindowImp(int);
        ~GtkWindowImp() {};
        int DevicePresentMain(int, char**) override;
        void DeviceAdd(int) override;
        void DeviceTextWidget() override;
        static void Activate(GtkApplication*, gpointer*);
    private:
        static GtkWidget* Get();
        static GtkWidget* _widget;
    };

    static std::map<int, GtkWindowImp*> GtkWidgetMap;
};