#include "WindowImp.h"

namespace Gui{
    class Window{
    public:
        // Window();
        // virtual void Open();
    protected:
        WindowImp* GetWindowImp();
    private:
        WindowImp* _windowImp;
    };

    class MainWindow : public Window{
    public:
        int PresentMain(int, char**);
    };

    // class LogWindow : Window{
    // public:
    //     virtual void UpdateLogBuffer();
    // };
};