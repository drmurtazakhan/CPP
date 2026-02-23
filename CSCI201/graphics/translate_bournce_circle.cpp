// translate_bounce_circle.cpp 

// To compile write following command in terminal:
// g++ translate_bounce_circle.cpp -o translate_bounce_circle.exe -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Diagonal Bounce Translation");

    // Setting the framerate to ensure smooth, consistent movement
    window.setFramerateLimit(60); 

    sf::CircleShape circle(40.f);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition({0.f, 0.f});

    float speed = 5.0f; 
    
    // 1. Create a boolean to track direction
    bool movingDownRight = true; 

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // 2. Movement Logic based on current state
        if (movingDownRight) {
            circle.move({speed, speed}); // Move toward (800, 800)
        } else {
            circle.move({-speed, -speed}); // Move toward (0, 0)
        }

        // 3. Boundary Checking
        sf::Vector2f pos = circle.getPosition();
        
        // If it hits the bottom-right limit, flip the direction to false
        if (pos.x >= 720.f || pos.y >= 720.f) { // 800 minus diameter (80)
            movingDownRight = false;
        }
        
        // If it hits the top-left limit, flip the direction back to true
        if (pos.x <= 0.f || pos.y <= 0.f) {
            movingDownRight = true;
        }

        window.clear();
        window.draw(circle);
        window.display();
    }
    return 0;
}