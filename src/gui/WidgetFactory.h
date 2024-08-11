#include "Window.h"

// Abstract factory for widgets.
namespace Gui{
    class WidgetFactory{
    public:
        WidgetFactory() {};
        virtual ~WidgetFactory();
        virtual Window* CreateWindow() {};
    };
}