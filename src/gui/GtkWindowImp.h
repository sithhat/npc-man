#include "gtk/gtk.h"

#include "WindowImp.h"
#include "GtkUI.h"

namespace Gui{
    class GtkWindowImp : public WindowImp{
    public:
        GtkWindowImp();
        void DeviceMakeWindow();
    };
}