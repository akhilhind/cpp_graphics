#ifndef CIRCLE
#define CIRCLE

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "../sound/soundEffects.hpp"
using namespace sf;

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


#endif