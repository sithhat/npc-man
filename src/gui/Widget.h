#include <string>
#include <queue>

#include "WidgetImp.h"

namespace Gui{
    enum LogLevel
    {
        DEBUG,
        INFO,
        WARN,
        ERROR
    };

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
        WidgetImp* _widgetImp;
    };

    class CompositeWidget : public Widget
    {
    public:
        virtual ~CompositeWidget() {};
        std::list<Widget*> _childWindows;
    };

    class MainWindow : virtual public CompositeWidget
    {
    public:
        MainWindowImp* GetMainWindowImp();
        int PresentMain(int, char**);
        void WindowAdd(Widget*);
    private:
        MainWindowImp* _mainWindowImp;
    };

    class LogWindow : virtual public Widget
    {
    public:
        LogWindow();
        void Log(std::queue<std::string>*);
    };
};