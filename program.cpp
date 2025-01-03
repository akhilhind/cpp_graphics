#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode({800, 600}), "YEYELUCKYSINGH");

    const Texture* texture = new Texture("images/images.jpeg");
    // const Sprite sprite(texture);

    CircleShape circle(50);
    circle.setPosition({50, 50});
    circle.setTexture(texture);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            // std::cout << event.value() << endl;
            if (event->is<Event::Closed>())
                window.close();
            else if(event->is<Event::KeyPressed>()) {
                const Keyboard::Key key_code = event->getIf<Event::KeyPressed>()->code;
                if(key_code == Keyboard::Key::Up) {
                    const Vector2f curr_pos = circle.getPosition();
                    circle.setPosition({curr_pos.x, curr_pos.y - 10});
                }
                else if(key_code == Keyboard::Key::Down) {
                    const Vector2f curr_pos = circle.getPosition();
                    circle.setPosition({curr_pos.x, curr_pos.y + 10});
                }
                else if(key_code == Keyboard::Key::Left) {
                    const Vector2f curr_pos = circle.getPosition();
                    circle.setPosition({curr_pos.x - 10, curr_pos.y});
                }
                else if(key_code == Keyboard::Key::Right) {
                    const Vector2f curr_pos = circle.getPosition();
                    circle.setPosition({curr_pos.x + 10, curr_pos.y});
                }
            }
            // never directly check event->getIf without first checking if the key is pressed or not, it will give seg fault.
            // else if(event->is<Event::KeyPressed>() && event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Up) {
            //     cout << "key B is pressed" << endl;
            //     circle.setTexture(nullptr);
            // }
        }

        window.clear();

        window.draw(circle);

        window.display();
    }
}