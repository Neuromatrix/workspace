void shapes::Rectangle::draw(const sf::Vector2f& st, sf::RenderWindow & window, sf::Color col) {
    window.clear(sf::Color::White);
    sf::RectangleShape m_Figure;
    m_Figure.setFillColor(col);
    m_Figure.setSize(sf::Vector2f(150.f,300.f));
    m_Figure.setPosition(st);
    window.draw(m_Figure);
    window.display();
}
