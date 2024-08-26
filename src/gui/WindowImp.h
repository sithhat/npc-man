#include "GtkUI.h"

namespace Gui {
    // Abstract class for hiding window-system dependent implementation
    class WindowImp{
    public:
        WindowImp() {};
        virtual ~WindowImp() {};
        virtual int DeviceRunGui(int, char**) { return 0; };
        virtual void DevicePresent() {};
        virtual void DevicePresentTextWindow() {};
    };

    // Concrete class for gtk implementations
    class GtkWindowImp : public WindowImp
    {
    public:
        GtkWindowImp();
        int DeviceRunGui(int, char**) override;
        void DevicePresent();
        void DevicePresentTextWindow();
        void DeviceSetParent();
        static void Activate(GtkApplication*, gpointer*);      
    private:
        static GtkWidget* MainWindowInstance();
        static GtkWidget* _mainWindowInstance;
    };
};