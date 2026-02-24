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
    circle.setPosition({400.f, 400.f}); // Start in the center

    // pixelShift describes the displacement (offset) per event
    float pixelShift = 15.f; 

    // 3. The Main Loop
    while (window.isOpen()) {
        
        // --- Event Handling ---
        while (const std::optional event = window.pollEvent()) {
            
            // Close window event
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // Detect Key Presses (The Event Listener)
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                
                // Check which arrow key was pressed and apply the pixelShift
                if (keyPressed->code == sf::Keyboard::Key::Left) {
                    circle.move({-pixelShift, 0.f});
                }
                else if (keyPressed->code == sf::Keyboard::Key::Right) {
                    circle.move({pixelShift, 0.f});
                }
                else if (keyPressed->code == sf::Keyboard::Key::Up) {
                    circle.move({0.f, -pixelShift});
                }
                else if (keyPressed->code == sf::Keyboard::Key::Down) {
                    circle.move({0.f, pixelShift});
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