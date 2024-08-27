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
    private:
        WindowImp* _windowImp;
        int _id;
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
        int PresentMain(int, char**);
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