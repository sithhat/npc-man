namespace Gui{
    // Abstract class for hiding window-system dependent implementation
    class WindowImp{
    public:
        // virtual void DeviceRaise();
        // virtual void DeviceLower();
        virtual void DeviceDrawRectangle(int, int, int, int);
    };

    class Window{
    public:
        Window();
        virtual void Redraw();
        virtual void Raise();
        virtual void Lower();
        virtual void Iconify();
        virtual void Deiconify();
        virtual void DrawRectangle(int, int, int, int);
    private:
        WindowImp* _windowImp;
    };

    // class ApplicationWindow : Window{
    // };

    // class IconWindow : Window{
    //     void Iconfify();
    // };

    class GtkWindowImp : public WindowImp{
    public:
        // void DeviceRaise();
        // void DeviceLower();
        void DeviceDrawRectangle(int, int, int, int);
    };

    // Abstract class for providing an interface to creating different kinds of window system-dependent implementations
    class WindowSystemFactory{
    public:
        WindowSystemFactory() {};
        virtual ~WindowSystemFactory() {};
        virtual WindowImp* CreateWindowImp() = 0;
        // virtual ColorImp* CreateColorImp() = 0;
        // virtual FontImp* CreateFontImp() = 0;
    };

    class GtkWindowSystemFactory : public WindowSystemFactory{
    public:
        GtkWindowSystemFactory() {};
        virtual WindowImp* CreateWindowImp();
    };

    static WindowSystemFactory* windowSystemFactory;
}