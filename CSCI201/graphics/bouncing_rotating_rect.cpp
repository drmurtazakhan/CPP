// bouncing_rotating_rect.cpp

// to compile write following command in terminal:
// g++ bouncing_rotating_rect.cpp -o bouncing_rotating_rect.exe -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>

int main() {
    // 1. Setup the Window and Speed Limit
    const int PW = 800;
    const int PH = 800;
    sf::RenderWindow window(sf::VideoMode({PW, PH}), "Infinite Rotating Translation");
    window.setFramerateLimit(60); // Keeps speed consistent

    // 2. Create the Rectangle (from rotating_rect.cpp)
    float RW = 100.0f; 
    float RH = 60.0f;
    sf::RectangleShape rect1({RW, RH});
    
    // Set the Origin to the center so it spins in place
    rect1.setOrigin({RW / 2.0f, RH / 2.0f});
    rect1.setPosition({0.f, 0.f}); // Start at top-left

    rect1.setFillColor(sf::Color::Cyan);
    rect1.setOutlineColor(sf::Color::White);
    rect1.setOutlineThickness(2.0f);

    // 3. Movement Variables
    float speed = 2.0f; 
    bool movingForward = true; // State to track direction

    // 4. The Application Loop
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close(); // Terminate when X is pressed
        }

        // --- Logic: Rotation (from rotating_rect.cpp) ---
        rect1.rotate(sf::degrees(2.0f)); // Spins while it moves

        // --- Logic: Infinite Translation (combined logic) ---
        sf::Vector2f pos = rect1.getPosition();

        if (movingForward) {
            rect1.move({speed, speed}); // Move toward bottom-right
            // Check if we reached the bottom-right corner
            if (pos.x >= PW || pos.y >= PH) {
                movingForward = false;
            }
        } else {
            rect1.move({-speed, -speed}); // Move toward top-left
            // Check if we reached the top-left corner
            if (pos.x <= 0 || pos.y <= 0) {
                movingForward = true;
            }
        }

        // --- Rendering ---
        window.clear(sf::Color::Black);
        window.draw(rect1); 
        window.display();
    }

    return 0;
}