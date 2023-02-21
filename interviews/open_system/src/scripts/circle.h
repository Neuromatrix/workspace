void shapes::Circle::draw(const sf::Vector2f& st, sf::RenderWindow & window, sf::Color col) {
    window.clear(sf::Color::White);
    sf::CircleShape m_Figure;
    m_Figure.setFillColor(col);
    m_Figure.setRadius(40.f);
    m_Figure.setPosition(st);
    window.draw(m_Figure);
    window.display();
}
