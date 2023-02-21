#include "src/figures.hpp"
#include "src/menu_color.hpp"
#include "src/menu_figures.hpp"

int main(){
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;
    sf::RenderWindow window(sf::VideoMode(700,700), "Geometry Shapes",sf::Style::Default, contextSettings);
    sf::Color listColors[] = {sf::Color::Red,sf::Color::Blue,sf::Color::Green};
    int typeNumber,colorNumber;
    while (true){
        showMenuFigures(window);
        sf::Event event;
        window.pollEvent(event);
        if (event.type == sf::Event::Closed){
            window.close();
            return 0;
        } else if (event.type == sf::Event::KeyPressed){
            typeNumber = event.key.code-sf::Keyboard::Num0;
            if (typeNumber > 5 || typeNumber < 1){
                continue;
            }
            break;
        }
    }
    while (true){
        showMenuColors(window);
        sf::Event event;
        window.pollEvent(event);
        if (event.type == sf::Event::Closed){
            window.close();
            return 0;
        } else if (event.type == sf::Event::KeyPressed){
            colorNumber = event.key.code-sf::Keyboard::Num0;
            if (colorNumber > 3 || colorNumber < 1){
                continue;
            }
            break;
        }
    }
    sf::Color colors = listColors[colorNumber-1];
    while (true){
        sf::Event event;
        window.pollEvent(event);
        if (event.type == sf::Event::Closed){
            window.close();
            return 0;
        }
        if (typeNumber == 1){
            shapes::screenDrawing(shapes::Rectangle(),sf::Vector2f(100.f,100.f),window,colors);
        }else if (typeNumber == 2) {
            shapes::screenDrawing(shapes::Circle(),sf::Vector2f(100.f,100.f),window,colors);
        }else if (typeNumber == 3) {
            shapes::screenDrawing(shapes::Romb(),sf::Vector2f(100.f,100.f),window,colors);
        } else if (typeNumber == 4) {
            shapes::screenDrawing(shapes::RotationCude(),sf::Vector2f(100.f,100.f),window,colors);
        }else if (typeNumber == 5) {
            shapes::screenDrawing(shapes::Triangle(),sf::Vector2f(100.f,100.f),window,colors);
        }
    }

    return 0;
}
