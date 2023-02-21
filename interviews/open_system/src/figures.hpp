#include "../include/SFML/Graphics.hpp"
#include "../include/SFML/Window.hpp"
#include "../include/SFML/OpenGL.hpp"
#include <cmath>
namespace shapes{
    // override
    template <class T>
    void screenDrawing(T &&figure, sf::Vector2f start, sf::RenderWindow & window, sf::Color col){
        figure.draw(start,window,col);
        return;
    }

    //decoraters
    class Circle{
    public:
        void draw(const sf::Vector2f&, sf::RenderWindow &, sf::Color);
    };


    class Rectangle{
    public:
        void draw(const sf::Vector2f&, sf::RenderWindow &, sf::Color);
    };


    class Romb{
    public:
        void draw(const sf::Vector2f&, sf::RenderWindow &, sf::Color);
    };


    class RotationCude{
    public:
        int draw(sf::Vector2f&, sf::RenderWindow &, sf::Color);
    };

    class Triangle{
    public:
        void draw(const sf::Vector2f&, sf::RenderWindow &, sf::Color);
    };

}
#include "scripts/rotation_cube.h"
#include "scripts/circle.h"
#include "scripts/rectangle.h"
#include "scripts/romb.h"
#include "scripts/triangle.h"
