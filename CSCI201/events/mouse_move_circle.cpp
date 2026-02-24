// mouse_move_circle.cpp
// To compile: g++ mouse_move_circle.cpp -o mouse_move_circle.exe -lsfml-graphics -lsfml-window -lsfml-system
// To Run: ./mouse_move_circle.exe

#include <SFML/Graphics.hpp>

int main() {
    // 1. Setup the Window
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Mouse Control Class");
    window.setFramerateLimit(60);

    // 2. Create the Yellow Circle
    float radius = 40.f;
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Yellow);
    
    // Set origin to center so the mouse is in the middle of the circle
    circle.setOrigin({radius, radius}); 
    circle.setPosition({400.f, 400.f});

    // 3. The Main Loop
    while (window.isOpen()) {
        
        // --- Event Handling ---
        while (const std::optional event = window.pollEvent()) {
            
            // Close window event
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // Detect Mouse Movement (The Event Listener)
            if (const auto* mouseMove = event->getIf<sf::Event::MouseMoved>()) {
                
                // Get the mouse coordinates from the event
                float mouseX = (float)mouseMove->position.x;
                float mouseY = (float)mouseMove->position.y;

                // Move the circle to exactly where the mouse is
                circle.setPosition({mouseX, mouseY});
            }
        }

        // --- Rendering ---
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }

    return 0;
}