#include "WindowSystemFactory.h"

namespace Gui{
    class GuiBuilder{
    public:
        static GuiBuilder* Instance();
        void SetWindowSystem(WindowSystem);
        int MakeGui(int, char**);
    protected:
        GuiBuilder() {};
    private:
        static GuiBuilder* _instance;
    };
};
