#include "GtkUI.h"

namespace Gui {
    // Abstract class for hiding window-system dependent implementation
    class WindowImp{
    public:
        WindowImp() {};
        virtual ~WindowImp() {};
        virtual int DevicePresentMain(int, char**) { return 0; };
        virtual void DevicePresent() {};
    };

    // Concrete class for gtk implementations
    class GtkWindowImp : public WindowImp
    {
    public:
        GtkWindowImp();
        int DevicePresentMain(int, char**) override;
        void DevicePresent();
        static void Activate(GtkApplication*, gpointer*);
    };
};