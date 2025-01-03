#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    // Create the main window
    RenderWindow window(VideoMode({800, 600}), "YEYELUCKYSINGH");

    const Texture* texture = new Texture("images.jpeg");
    // const Sprite sprite(texture);

    CircleShape circle(150);

    // circle.setTexture(texture);
    circle.setPosition({50, 50});

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<Event::Closed>())
                window.close();
        }

        // Clear screen
        window.clear();

        window.draw(circle);

        // Update the window
        window.display();
    }
}