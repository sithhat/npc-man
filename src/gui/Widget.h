#include "WidgetImp.h"

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

    class Widget
    {
    public:
        virtual void Present() {};
        WidgetImp* GetWidgetImp();
        int GetId();
    protected:
        Widget();
        int _id;
    private:
        WidgetImp* _windowImp;
    };

    class CompositeWidget : public Widget
    {
    public:
        virtual ~CompositeWidget() {};
        virtual void Add(Widget*);
    private:
        std::list<Widget*> _childWindows;
    };

    class MainWindow : public CompositeWidget
    {
    public:
        MainWindowImp* GetMainWindowImp();
        int PresentMain(int, char**);
    private:
        MainWindowImp* _mainWindowImp;
    };

    class LogWindow : public Widget
    {
    public:
        void Present() override;
        // virtual void UpdateLogBuffer();
    private:
        const char* _logText;
    };
};