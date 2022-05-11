#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "utils.hpp"

struct Polygon
{
    sf::VertexArray va;

    Polygon(sf::Vector2f center, sf::Color centerCol, size_t subdivs, float size) {
        va = sf::VertexArray(sf::TriangleFan, subdivs + 2);
        va[0].position = center;
        va[0].color = centerCol;
        for (int i = 1; i <= subdivs + 1; i++) {
            double angle = (2*M_PI)/subdivs * (i - 1);
            va[i].position = center + sf::Vector2f(cos(angle) * fabs(size), sin(angle) * fabs(size));
            va[i].color = HSVtoRGB(TO_DEG(angle), .75, .75);
        }
    }
    void update(sf::Vector2f center, sf::Color centerCol, float size, float angleOffset = 0) {
        va[0].position = center;
        va[0].color = centerCol;
        size_t subdivs = va.getVertexCount() - 2;
        for (int i = 1; i <= subdivs + 1; i++) {
            double angle = (2*M_PI)/subdivs * (i - 1) + angleOffset;
            va[i].position = center + sf::Vector2f(cos(angle) * size, sin(angle) * size);
            va[i].color = HSVtoRGB(TO_DEG(angle), .75, .75);
        }
    }
};

#define SUBDIVS 50
#define SIZE 450
#define VP_WIDTH 1920
#define VP_HEIGHT 1080

int main(void)
{
    using namespace sf;
    RenderWindow win(VideoMode(VP_WIDTH, VP_HEIGHT), "Tattoo");
    Vector2f center = Vector2f(VP_WIDTH/2, VP_HEIGHT/2);
    Clock cl;
    Polygon pol(center, Color(100, 100, 100), SUBDIVS, SIZE);

    cl.restart();
    while (win.isOpen()) {
        Event e;
        while (win.pollEvent(e)) {
            if (e.type == Event::Closed || (e.type == Event::KeyReleased && e.key.code == Keyboard::Escape))
                win.close();
        }
        pol.update(center, Color(100, 100, 100), SIZE, cl.getElapsedTime().asSeconds()/4);
        win.clear();
        win.draw(pol.va);
        win.display();
    }
}