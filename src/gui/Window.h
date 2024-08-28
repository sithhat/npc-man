#include "WindowImp.h"

namespace Gui{
    class IdGenerator
    {
    public:
        static IdGenerator* Instance();
        int GenerateWindowId();
    protected:
        IdGenerator();
    private:
        static IdGenerator* _instance;
        int _count;
    };

    class Window
    {
    public:
        virtual void Present() {};
        WindowImp* GetWindowImp();
        int GetId();
    protected:
        Window();
        int _id;
    private:
        WindowImp* _windowImp;
    };

    class CompositeWindow : public Window
    {
    public:
        virtual ~CompositeWindow() {};
        virtual void Add(Window*);
    private:
        std::list<Window*> _childWindows;
    };

    class MainWindow : public CompositeWindow
    {
    public:
        MainWindowImp* GetMainWindowImp();
        int PresentMain(int, char**);
    private:
        MainWindowImp* _mainWindowImp;
    };

    class LogWindow : public Window
    {
    public:
        void Present() override;
        // virtual void UpdateLogBuffer();
    private:
        const char* _logText;
    };
};