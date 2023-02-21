void showMenuColors(sf::RenderWindow &window){
    sf::Text text;
    sf::Font font;
    window.clear(sf::Color::White);
    font.loadFromFile("src/arial.ttf");
    text.setFont(font);
    text.setCharacterSize(28);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    //Main label
    text.setString("Choose Color");
    text.setPosition(sf::Vector2f(30, 35));
    window.draw(text);
    // choose colors
    text.setString("Press the num button to select Color");
    text.setPosition(sf::Vector2f(30, 100));
    window.draw(text);
    // colors
    //? RED
    text.setFillColor(sf::Color::Red);
    text.setString("Press 1 to choose RED");
    text.setPosition(sf::Vector2f(30, 175));
    window.draw(text);
    //? Blue
    text.setFillColor(sf::Color::Blue);
    text.setString("Press 2 to choose Blue");
    text.setPosition(sf::Vector2f(30, 250));
    window.draw(text);
    //? Green
    text.setFillColor(sf::Color::Green);
    text.setString("Press 3 to choose Green");
    text.setPosition(sf::Vector2f(30, 325));
    window.draw(text);
    window.display();
}
