namespace Gui{
    class Window{
    public:
        Window();
        virtual void Redraw();
        virtual void Raise();
        virtual void Lower();
        virtual void Iconify();
        virtual void Deiconify();
        virtual void DrawRectangle(int, int, int, int);
    };

    class ApplicationWindow : Window{
    };

    class IconWindow : Window{
        void Iconfify();
    };
}