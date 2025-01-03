#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode({800, 600}), "YEYELUCKYSINGH");

    const Texture* texture = new Texture("images.jpeg");
    // const Sprite sprite(texture);

    CircleShape circle(150);

    // circle.setTexture(texture);
    circle.setPosition({50, 50});

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<Event::Closed>())
                window.close();
        }

        window.clear();

        window.draw(circle);

        window.display();
    }
}