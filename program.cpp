#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

CircleShape createCircle(CircleShape circle) {
    CircleShape new_circle(circle.getRadius());
    new_circle.setPosition(circle.getPosition());
    return new_circle;
}

void updateClickCount(Text& click_count, int& cc) {
    ++cc;
    string cc_str = "Click Count: " + to_string(cc);
    click_count.setString(cc_str);
}

class Dot {
private:
    Vector2f last_pos;
public:
    vector<CircleShape> all_dots;
    Dot() {
        last_pos = {-1, -1};
    }
    void addDot(Vector2f pos) {
        if(last_pos == pos) {
            return;
        }
        cout << "ADDING A NEW DOT" << endl;
        CircleShape dot(5);
        dot.setPosition(pos - Vector2f(dot.getRadius(), dot.getRadius()));
        all_dots.push_back(dot);
        last_pos = pos;
    }
};

int main() {
    RenderWindow window(VideoMode({800, 600}), "YEYELUCKYSINGH");

    const Texture* texture = new Texture("images/images.jpeg");

    const Font font("font/roboto.ttf");

    sf::Music music;

    // if (!music.openFromFile("audio/bg.wav")) {
    //     std::cerr << "Failed to load music file!" << std::endl;
    //     return -1;
    // }
    // music.openFromFile("audio/bg.mp3");
    // music.setVolume(50);
    // music.play();

    Text click_count(font);
    int cc = 0;
    string cc_str = "Click Count: " + to_string(cc);
    click_count.setString(cc_str);
    click_count.setCharacterSize(20);
    click_count.setFillColor(Color::Black);
    click_count.setPosition({10, 10});
    click_count.setStyle(Text::Bold | Text::Underlined);


    RectangleShape background(Vector2f(window.getSize()));
    background.setFillColor(Color::Cyan);
    // const Sprite sprite(texture);

    vector<CircleShape> circles;

    Dot dots;

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

            else if (event->is<Event::MouseButtonPressed>()) {
                // const Vector2i mouse_pos = event->getIf<Event::MouseButtonPressed>()->position;
                // circle.setPosition(window.mapPixelToCoords(mouse_pos) - Vector2f(circle.getRadius(), circle.getRadius()));
                updateClickCount(click_count, cc);
                // cout << mouse_pos.x << " " << mouse_pos.y << endl;

                if(Mouse::isButtonPressed(Mouse::Button::Left)) {
                    cout << "button pressed" << endl;
                    dots.addDot(window.mapPixelToCoords(Mouse::getPosition(window)));
                }
            }

            else if(event->is<Event::MouseMoved>()) {
                if(Mouse::isButtonPressed(Mouse::Button::Left)) {
                    dots.addDot(window.mapPixelToCoords(Mouse::getPosition(window)));
                }
            }
        }

        window.clear();

        window.draw(background);

        for(auto& circle: circles) {
            window.draw(circle);
        }

        for(auto& dot: dots.all_dots) {
            window.draw(dot);
        }

        window.draw(circle);

        window.draw(click_count);

        window.display();
    }
}