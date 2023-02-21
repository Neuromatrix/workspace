void shapes::Romb::draw(const sf::Vector2f& st, sf::RenderWindow & window, sf::Color col) {
    window.clear(sf::Color::White);
    sf::CircleShape m_Figure(80.f,4);
    m_Figure.setFillColor(col);
    m_Figure.setPosition(st);
    window.draw(m_Figure);
    window.display();
}
