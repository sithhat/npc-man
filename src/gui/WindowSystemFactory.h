#include "Window.h"

namespace Gui{
    
    // Enum for window configuration types
    enum WindowSystem
    {
        GTK,
    };
    
    // Class for providing an interface to creating different kinds of window system-dependent implementations
    class WindowSystemFactory{
    public:
        static WindowSystemFactory* Instance();
        WindowImp* MakeWindowImp(int);
        WidgetImp* MakeWidgetImp(int);
        MainWindowImp* MakeMainWindowImp(int);
        void SetWindowSystem(WindowSystem);
    protected:
        WindowSystemFactory() {};
    private:
        static WindowSystemFactory* _instance;
        WindowSystem _configuration;
    };
};