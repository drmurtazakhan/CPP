// circle.cpp

// To compile write following command in terminal:
// g++ circle.cpp -o circle.exe -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>

int main() {
    // 1. Setup the Window (800x600 pixels)
    sf::RenderWindow window(sf::VideoMode({800, 600}), "C++ Circle Example");

    // 2. Create the Circle
    float radius = 50.f;
    sf::CircleShape circle(radius);
    
    // Set color and position
    circle.setFillColor(sf::Color::Green);
    circle.setOutlineThickness(5.f);
    circle.setOutlineColor(sf::Color::White);
    circle.setPosition({375.f, 275.f}); // Center-ish of the screen

    // 3. The Loop (Your "Animation Thread")
    while (window.isOpen()) {
        // Check for "X" button click
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // --- Rendering ---
        window.clear(sf::Color::Black); // Erase previous frame
        window.draw(circle);             // Draw the circle object
        window.display();                // Push to screen
    }

    return 0;
}