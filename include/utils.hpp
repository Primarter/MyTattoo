#include <SFML/Graphics.hpp>

typedef struct {
    double h;       // angle in degrees
    double s;       // a fraction between 0 and 1
    double v;       // a fraction between 0 and 1
} HsvColor;

#define TO_RAD(a) (a * M_PI/180)
#define TO_DEG(a) (a * 180/M_PI)

void RGBtoHSV(sf::Color col, float& fH, float& fS, float& fV);
sf::Color HSVtoRGB(float fH, float fS, float fV);