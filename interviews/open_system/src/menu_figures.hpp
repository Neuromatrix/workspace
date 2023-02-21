void showMenuFigures(sf::RenderWindow &window){
    sf::Text text;
    sf::Font font;
    window.clear(sf::Color::White);
    font.loadFromFile("src/arial.ttf");
    text.setFont(font);
    text.setCharacterSize(35);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    //Main label
    text.setString("Choose Figure");
    text.setPosition(sf::Vector2f(30, 35));
    window.draw(text);
    // choose figures
    text.setCharacterSize(30);
    text.setString("Press the num button to select Figure");
    text.setPosition(sf::Vector2f(30, 100));
    window.draw(text);
    text.setCharacterSize(28);
    // figures
    //? Rectangle
    std::string types[] = {"Rectangle", "Circle", "Romb", "Rotation Cube", "Triangle"};
    for (int i = 0 ; i < 5; i++){
        text.setString("Press " + std::to_string(i+1) + " to choose " + types[i]);
        text.setPosition(sf::Vector2f(30, 175+55*i));
        window.draw(text);
    }
    window.display();
}
