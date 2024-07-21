#include "Window.h"

namespace Gui{
    class Glyph{
    public:
        virtual void Draw(Window*);
        virtual void Bounds(Rectangle&);
    };

    class Rectangle : Glyph{
    public:
        Rectangle(int, int, int, int);
        void Draw(Window*);
    private:
        int _x0;
        int _y0;
        int _x1;
        int _y1;
    };
}
