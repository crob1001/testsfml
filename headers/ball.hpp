class Ball : public sf::CircleShape {
    public:
        float direction[2] = {float((std::time(0)) % 10), float(std::trunc((std::time(0) % 10) + 1))};
        float velocity = .3;
        float oldpos[2];

        Ball(float radius, sf::Vector2f pos) : CircleShape(radius) {
            // setOrigin(getRadius() / 2, getRadius() / 2);
            setFillColor(sf::Color(255, 255, 255, 255));
            setOrigin(sf::Vector2f(radius, radius));
            setOutlineColor(sf::Color(0, 0, 0, 255));
            setOutlineThickness(5);
            setPosition(pos);
        }
};