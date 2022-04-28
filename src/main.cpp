#include <iostream>
#include <SFML/Graphics.hpp>

int main(void)
{
    using namespace sf;
    RenderWindow win(VideoMode(720, 720), "Tattoo");
    CircleShape sh(100, 50);
    while (win.isOpen()) {
        Event e;
        while (win.pollEvent(e)) {
            if (e.type == Event::Closed)
                win.close();
        }
        win.clear();
        win.draw(sh);
        win.display();
    }
}