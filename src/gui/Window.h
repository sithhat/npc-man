#include "WindowImp.h"

namespace Gui{

    class Window{
    public:
        Window();
        void MakeWindow();
        // virtual void Redraw();
        // virtual void Raise();
        // virtual void Lower();
        // virtual void Iconify();
        // virtual void Deiconify();
        // virtual void DrawRectangle(int, int, int, int);
    private:
        WindowImp* _windowImp;
    };

    // class ApplicationWindow : Window{
    // };

    // class IconWindow : Window{
    //     void Iconfify();
    // };

    
}