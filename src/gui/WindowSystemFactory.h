#include "Window.h"

namespace Gui{
    
    // Enum for window configuration types
    enum WindowSystem
    {
        GTK,
    };

    static WindowSystem configuration;
    
    // Class for providing an interface to creating different kinds of window system-dependent implementations
    class WindowSystemFactory{
    public:
        static WindowSystemFactory* Instance();
        WindowImp* MakeWindowImp();
    protected:
        WindowSystemFactory() {};
    private:
        static WindowSystemFactory* _instance;
    };
};