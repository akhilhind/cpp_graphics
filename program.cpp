#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace sf;

CircleShape createCircle(CircleShape circle) {
    CircleShape new_circle(circle.getRadius());
    new_circle.setPosition(circle.getPosition());
    return new_circle;
}

int main() {
    RenderWindow window(VideoMode({800, 600}), "YEYELUCKYSINGH");

    const Texture* texture = new Texture("images/images.jpeg");

    RectangleShape background(Vector2f(window.getSize()));
    background.setFillColor(Color::Cyan);
    // const Sprite sprite(texture);

    vector<CircleShape> circles;

    CircleShape circle(50);
    // CircleShape circle2(50);
    circle.setPosition({50, 50});
    circle.setTexture(texture);

    // circles.push_back(circle);
    // circles.push_back(circle2);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            // std::cout << event.value() << endl;
            if (event->is<Event::Closed>())
                window.close();
            else if(event->is<Event::KeyPressed>()) {
                const Keyboard::Key key_code = event->getIf<Event::KeyPressed>()->code;
                if(key_code == Keyboard::Key::Up) {
                    const Vector2f curr_pos = circle.getPosition();
                    circles.push_back(createCircle(circle));
                    circle.setPosition({curr_pos.x, curr_pos.y - 10});
                }
                else if(key_code == Keyboard::Key::Down) {
                    const Vector2f curr_pos = circle.getPosition();
                    circles.push_back(createCircle(circle));
                    circle.setPosition({curr_pos.x, curr_pos.y + 10});
                }
                else if(key_code == Keyboard::Key::Left) {
                    const Vector2f curr_pos = circle.getPosition();
                    circles.push_back(createCircle(circle));
                    circle.setPosition({curr_pos.x - 10, curr_pos.y});
                }
                else if(key_code == Keyboard::Key::Right) {
                    const Vector2f curr_pos = circle.getPosition();
                    circles.push_back(createCircle(circle));
                    circle.setPosition({curr_pos.x + 10, curr_pos.y});
                }
                else if(key_code == Keyboard::Key::W) {
                    circle.setRadius(circle.getRadius() + 10);
                }
                else if(key_code == Keyboard::Key::S) {
                    circle.setRadius(circle.getRadius() - 10);
                }
            }
            // never directly check event->getIf without first checking if the key is pressed or not, it will give seg fault.
            // else if(event->is<Event::KeyPressed>() && event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Up) {
            //     cout << "key B is pressed" << endl;
            //     circle.setTexture(nullptr);
            // }
        }

        window.clear();

        window.draw(background);

        for(auto& circle: circles) {
            window.draw(circle);
        }

        window.draw(circle);

        window.display();
    }
}