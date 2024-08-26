#include <list>

#include "WindowImp.h"

namespace Gui{
    class Window
    {
    public:
        virtual void Present() {};
    protected:
        Window();
        WindowImp* GetWindowImp();
    private:
        WindowImp* _windowImp;
        Window* _parent;
    };

    class CompositeWindow : public Window
    {
    public:
        virtual ~CompositeWindow() {};
        virtual void Add(Window*);
    private:
        std::list<Window*> _child_windows;
    };

    class MainWindow : public CompositeWindow
    {
    public:
        int PresentMain(int, char**);
    };

    class LogWindow : Window
    {
    public:
        void Present() override;
        // virtual void UpdateLogBuffer();
    private:
        const char* _logText;
    };
};