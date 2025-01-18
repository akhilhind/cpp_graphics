#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <math.h>
using namespace sf;

// CircleShape createCircle(CircleShape circle) {
//     CircleShape new_circle(circle.getRadius());
//     new_circle.setPosition(circle.getPosition());
//     return new_circle;
// }

// void updateClickCount(Text& click_count, int& cc) {
//     ++cc;
//     string cc_str = "Click Count: " + to_string(cc);
//     click_count.setString(cc_str);
// }

// class Dot {
// private:
//     Vector2f last_pos;
// public:
//     vector<CircleShape> all_dots;
//     Dot() {
//         last_pos = {-1, -1};
//     }
//     void addDot(Vector2f pos) {
//         if(last_pos == pos) {
//             return;
//         }
//         // cout << "ADDING A NEW DOT" << endl;
//         CircleShape dot(5);
//         dot.setPosition(pos - Vector2f(dot.getRadius(), dot.getRadius()));
//         all_dots.push_back(dot);
//         last_pos = pos;
//     }
// };

// int main() {
//     RenderWindow window(VideoMode({800, 600}), "YEYELUCKYSINGH");

//     const Texture* texture = new Texture("images/images.jpeg");

//     const Font font("font/roboto.ttf");

//     sf::Music music;

//     // if (!music.openFromFile("audio/bg.wav")) {
//     //     std::cerr << "Failed to load music file!" << std::endl;
//     //     return -1;
//     // }
//     // music.openFromFile("audio/bg.mp3");
//     // music.setVolume(50);
//     // music.play();

//     Text click_count(font);
//     int cc = 0;
//     string cc_str = "Click Count: " + to_string(cc);
//     click_count.setString(cc_str);
//     click_count.setCharacterSize(20);
//     click_count.setFillColor(Color::Black);
//     click_count.setPosition({10, 10});
//     click_count.setStyle(Text::Bold | Text::Underlined);


//     Text fpsText(font);
//     fpsText.setFont(font);
//     fpsText.setCharacterSize(20);
//     fpsText.setFillColor(sf::Color::Black);
//     fpsText.setPosition({200, 50});

//     sf::Clock clock;
//     int frameCount = 0;
//     float elapsedTime = 0.0f;


//     RectangleShape background(Vector2f(window.getSize()));
//     background.setFillColor(Color::Cyan);
//     // const Sprite sprite(texture);

//     vector<CircleShape> circles;

//     Dot dots;

//     CircleShape circle(50);
//     // CircleShape circle2(50);
//     circle.setPosition({50, 50});
//     circle.setTexture(texture);

//     // circles.push_back(circle);
//     // circles.push_back(circle2);

//     while (window.isOpen()) {
//         while (const std::optional event = window.pollEvent()) {
//             // std::cout << event.value() << endl;
//             if (event->is<Event::Closed>())
//                 window.close();
//             else if(event->is<Event::KeyPressed>()) {
//                 const Keyboard::Key key_code = event->getIf<Event::KeyPressed>()->code;
//                 if(key_code == Keyboard::Key::Up) {
//                     const Vector2f curr_pos = circle.getPosition();
//                     circles.push_back(createCircle(circle));
//                     circle.setPosition({curr_pos.x, curr_pos.y - 10});
//                 }
//                 else if(key_code == Keyboard::Key::Down) {
//                     const Vector2f curr_pos = circle.getPosition();
//                     circles.push_back(createCircle(circle));
//                     circle.setPosition({curr_pos.x, curr_pos.y + 10});
//                 }
//                 else if(key_code == Keyboard::Key::Left) {
//                     const Vector2f curr_pos = circle.getPosition();
//                     circles.push_back(createCircle(circle));
//                     circle.setPosition({curr_pos.x - 10, curr_pos.y});
//                 }
//                 else if(key_code == Keyboard::Key::Right) {
//                     const Vector2f curr_pos = circle.getPosition();
//                     circles.push_back(createCircle(circle));
//                     circle.setPosition({curr_pos.x + 10, curr_pos.y});
//                 }
//                 else if(key_code == Keyboard::Key::W) {
//                     circle.setRadius(circle.getRadius() + 10);
//                 }
//                 else if(key_code == Keyboard::Key::S) {
//                     circle.setRadius(circle.getRadius() - 10);
//                 }
//             }
//             // never directly check event->getIf without first checking if the key is pressed or not, it will give seg fault.
//             // else if(event->is<Event::KeyPressed>() && event->getIf<Event::KeyPressed>()->code == Keyboard::Key::Up) {
//             //     cout << "key B is pressed" << endl;
//             //     circle.setTexture(nullptr);
//             // }

//             else if (event->is<Event::MouseButtonPressed>()) {
//                 // const Vector2i mouse_pos = event->getIf<Event::MouseButtonPressed>()->position;
//                 // circle.setPosition(window.mapPixelToCoords(mouse_pos) - Vector2f(circle.getRadius(), circle.getRadius()));
//                 updateClickCount(click_count, cc);
//                 // cout << mouse_pos.x << " " << mouse_pos.y << endl;

//                 if(Mouse::isButtonPressed(Mouse::Button::Left)) {
//                     cout << "button pressed" << endl;
//                     dots.addDot(window.mapPixelToCoords(Mouse::getPosition(window)));
//                 }
//             }

//             else if(event->is<Event::MouseMoved>()) {
//                 if(Mouse::isButtonPressed(Mouse::Button::Left)) {
//                     dots.addDot(window.mapPixelToCoords(Mouse::getPosition(window)));
//                 }
//             }
//         }

        
//         frameCount++;
//         elapsedTime += clock.restart().asSeconds();

//         if (elapsedTime >= 1.0f) {
//             fpsText.setString("FPS: " + std::to_string(frameCount));
//             frameCount = 0;
//             elapsedTime = 0.0f;
//         }
        
//         window.clear();

//         window.draw(background);

//         for(auto& circle: circles) {
//             window.draw(circle);
//         }

//         for(auto& dot: dots.all_dots) {
//             window.draw(dot);
//         }

//         window.draw(circle);
//         window.draw(fpsText);

//         window.draw(click_count);

//         window.display();
//     }
// }


class SoundEffects {
private:
    SoundBuffer boink;
    vector<Sound> active_sounds;
public:
    unordered_map<string, SoundBuffer> sound_effects;
    SoundEffects() {
        cout << "INITIALIZING SOUND EFFECTS" << endl;
        if(!boink.loadFromFile("audio/boink.wav")) {
            std::cerr << "Failed to load sound file!" << std::endl;
            return;
        }
        sound_effects["boink"] = boink;
    }
    void playSound(const string& sound_name) {
        cout << "PLAYING SOUND" << endl;
        if (sound_effects.find(sound_name) != sound_effects.end()) {
            Sound sound(sound_effects[sound_name]);
            active_sounds.push_back(sound);
            active_sounds.back().play();
        }
    }

    void cleanUp() {
        active_sounds.erase(remove_if(active_sounds.begin(), active_sounds.end(),
            [](const Sound& sound) { return sound.getStatus() == Sound::Status::Stopped; }),
                active_sounds.end());
    }
};


class Circle {
private:
    Clock last_moved;
    Vector2i last_pos;
    int start_x, start_y;
    bool hit_x_edge = false;
public:
    int x_dir = -1, y_dir = -1;
    int radius;
    float curr_x, curr_y;
    CircleShape circle;
    SoundEffects sound_effects;

    Circle(int radius=50, float start_x=50, float start_y=50) : circle(radius), start_x(start_x), start_y(start_y) {
        circle.setPosition({start_x, start_y});
        circle.setFillColor(Color::Red);
        this->radius = radius;
        this->curr_x = start_x, this->curr_y = start_y;
        this->last_pos = {int(this->curr_x), int(this->curr_y)};
    }

    void move() {
        bool is_at_edge = (
            circle.getPosition().x <= 0
            || circle.getPosition().x >= 800 - 2 * circle.getRadius()
            || circle.getPosition().y <= 0
            || circle.getPosition().y >= 600 - 2 * circle.getRadius()
        );

        if (is_at_edge && !hit_x_edge) {
            sound_effects.playSound("boink");
            hit_x_edge = true;
        } else if (!is_at_edge) {
            hit_x_edge = false;
        }

        if (circle.getPosition().x <= 0) {
            x_dir = 1;
        } else if (circle.getPosition().x >= 800 - 2 * circle.getRadius()) {
            x_dir = -1;
        }

        if(circle.getPosition().y <= 0) {
            y_dir = 1;
        } else if(circle.getPosition().y >= 600 - 2 * circle.getRadius()) {
            y_dir = -1;
        }

        if (last_moved.getElapsedTime().asMilliseconds() > 10) {
            curr_x += x_dir * 2;
            curr_y += y_dir * 2;
            this->circle.setPosition({curr_x, curr_y});
            cout << this->circle.getPosition().x << " " << this->circle.getPosition().y << endl;
            
            if(int(curr_x) != this->last_pos.x || int(curr_y) != this->last_pos.y) {
                cout << "circle with radius: " << this->radius << " is now at: ";
                cout << "Updated position: (" << curr_x << ", " << curr_y << ")" << endl;
            }

            last_moved.restart();
        }
        sound_effects.cleanUp();
        // if(this->radius == 20) {
        //     cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        //     cout << this->radius << endl;
        //     cout << curr_x << " " << curr_y << endl;
        //     cout << this->circle.getPosition().x << this->circle.getPosition().y << endl;
        //     cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
        // }
    }

    Vector2f getPosition() {
        return this->circle.getPosition();
    }
};


class HandleCollision {
private:
    vector<Circle*> circles;
public:
    HandleCollision(vector<Circle*> &cc): circles(cc) {}
    void updateDirection(Circle &circle) {

    }
    void checkCollition() {
        // cout << endl << endl << endl << "++++++++++++++++++++++++++++++" << endl;
        // for(int i=0; i<circles.size(); i++) {
        //     for(int j=i+1; j<circles.size(); j++) {
        //         auto* circleA = circles[i];
        //         auto* circleB = circles[j];
        //         cout << circleA->circle.getPosition().x << " " << circleA->circle.getPosition().y << endl;
        //         cout << circleB->circle.getPosition().x << " " << circleB->circle.getPosition().y << endl;
        //     }
        // }
        // cout << "++++++++++++++++++++++++++" << endl << endl << endl;
        for(int i = 0; i < circles.size(); i++) {
            for(int j = i+1; j < circles.size(); j++) {
                if(i == j) continue;

                auto *circleA = circles[i];
                auto *circleB = circles[j];
                
                auto centerA = circleA->circle.getPosition();
                auto centerB = circleB->circle.getPosition();
                // cout << circleA.radius << " " << circleB.radius << endl;
                // cout << endl << "**************************" << endl;
                // cout << centerA.x << " " << centerA.y << endl;
                // cout << centerB.x << " " << centerB.y << endl;
                // cout << "**************************" << endl;
                // cout << centerA.x << " " << centerA.y << endl;
                // cout << centerB.x << " " << centerB.y << endl;
                
                float centerDist = pow(centerA.x - centerB.x, 2) + pow(centerA.y - centerB.y, 2);

                cout << "centerDist: " << centerDist << endl;

                if(centerDist < pow(circleA->radius + circleB->radius, 2)) {
                    cout << "Collision detected!" << endl;
                    circleA->x_dir *= -1;
                    circleB->x_dir *= -1;
                    circleA->circle.setPosition({circleA->curr_x + circleA->x_dir * 10, circleA->curr_y + circleA->y_dir * 10});
                    circleB->circle.setPosition({circleB->curr_x + circleB->x_dir * 10, circleB->curr_y + circleB->y_dir * 10});
                }
            }
        }
    }
};

int main() {
    RenderWindow window(VideoMode({800, 600}), "YEYELUCKYSINGH");

    const Texture* texture = new Texture("images/images.jpeg");

    const Font font("font/roboto.ttf");

    SoundBuffer buffer;
    if(!buffer.loadFromFile("audio/boink.wav")) {
        std::cerr << "Failed to load sound file!" << std::endl;
        return -1;
    }
    // buffer.loadFromFile("audio/boink.wav");

    Sound sound(buffer);

    sound.play();

    RectangleShape background(Vector2f(window.getSize()));
    background.setFillColor(Color::Cyan);

    // define two circles
    // CircleShape circle1(50), circle2(50);

    Circle circle1, circle2(50, 300, 300);
    // cout << "**************************************" << endl;
    // cout << circle1.radius << endl;
    // cout << circle2.radius << endl;
    // cout << "**************************************" << endl;

    vector<Circle*> circles;
    circles.emplace_back(&circle1);
    circles.emplace_back(&circle2);

    HandleCollision collisionHandler(circles);

    Clock clock;

    while(window.isOpen()) {
        while(const std::optional event = window.pollEvent()) {
            if(event->is<Event::Closed>()) {
                window.close();
            }
        }
        circle1.move();
        circle2.move();
        // cout << endl << "#######################" << endl;
        // cout << circle1.circle.getPosition().x << " " << circle1.circle.getPosition().y << endl;
        // cout << circle2.circle.getPosition().x << " " << circle2.circle.getPosition().y << endl;
        // cout << "#######################" << endl;
        collisionHandler.checkCollition();
        window.clear();
        window.draw(background);
        window.draw(circle1.circle);
        window.draw(circle2.circle);
        window.display();
    }

    return 0;
}