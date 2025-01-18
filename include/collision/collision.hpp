#ifndef COLLISION
#define COLLISION

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <circle.hpp>
#include <math.h>
using namespace sf;

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
                
                float centerDist = sqrt(pow(centerA.x - centerB.x, 2) + pow(centerA.y - centerB.y, 2));

                cout << "centerDist: " << centerDist << endl;

                if(centerDist < (circleA->radius + circleB->radius)) {
                    cout << "Collision detected!" << endl;
                    circleA->x_dir *= -1, circleA->y_dir *= -1;
                    circleB->x_dir *= -1, circleB->y_dir *= -1;
                    // circleA->circle.setPosition({centerA.x + circleA->x_dir * 10, centerA.y + circleA->y_dir * 10});
                    // circleA->circle.setPosition({centerB.x + circleB->x_dir * 10, centerB.y + circleB->y_dir * 10});
                }
            }
        }
    }
};


#endif