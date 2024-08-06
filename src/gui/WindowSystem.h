#include "Window.h"

namespace Gui{
    // Abstract class for providing an interface to creating different kinds of window system-dependent implementations
    class WindowSystemFactory{
    public:
        WindowSystemFactory() {};
        virtual ~WindowSystemFactory() {};
        virtual WindowImp* CreateWindowImp() { return new WindowImp(); };
    };

    class GtkWindowSystemFactory : public WindowSystemFactory{
    public:
        GtkWindowSystemFactory() {};
    };

    static WindowSystemFactory* windowSystemFactory;
}