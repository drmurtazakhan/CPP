// keyboard_move_circle.cpp
// To compile: g++ keyboard_move_circle.cpp -o keyboard_move_circle.exe -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>

int main() {
    // 1. Setup the Window
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Keyboard Control Class");
    window.setFramerateLimit(60);

    // 2. Create the Yellow Circle
    float radius = 40.f;
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Yellow);
    
    // Set origin to center so movement feels natural
    circle.setOrigin({radius, radius}); 
    circle.setPosition({400.f, 400.f}); // Center of 800x800

    float moveSpeed = 10.f; // How many pixels to move per press

    // 3. The Main Loop
    while (window.isOpen()) {
        
        // --- Event Handling ---
        while (const std::optional event = window.pollEvent()) {
            
            // Close window event
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // Detect Key Presses
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                
                // Check which arrow key was pressed
                if (keyPressed->code == sf::Keyboard::Key::Left) {
                    circle.move({-moveSpeed, 0.f});
                }
                else if (keyPressed->code == sf::Keyboard::Key::Right) {
                    circle.move({moveSpeed, 0.f});
                }
                else if (keyPressed->code == sf::Keyboard::Key::Up) {
                    circle.move({0.f, -moveSpeed});
                }
                else if (keyPressed->code == sf::Keyboard::Key::Down) {
                    circle.move({0.f, moveSpeed});
                }
            }
        }

        // --- Rendering ---
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }

    return 0;
}