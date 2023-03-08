class Paddle : public sf::RectangleShape {
    public:
        int score = 0;

        Paddle(sf::Vector2f size, sf::Vector2f pos, sf::Color color) : RectangleShape(size) {
            // setOrigin(getRadius() / 2, getRadius() / 2);
            setFillColor(color);
            setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
            setOutlineColor(sf::Color(0, 0, 0, 255));
            setOutlineThickness(5);
            setPosition(pos);
        }
};