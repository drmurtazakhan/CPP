// mousedrag_move_circle.cpp
// To compile: g++ mousedrag_move_circle.cpp -o mousedrag_move_circle.exe -lsfml-graphics -lsfml-window -lsfml-system
// To Run: ./mousedrag_move_circle.exe 

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Hit Test Drag Class");
    window.setFramerateLimit(60);

    float radius = 50.f;
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Yellow);
    circle.setOrigin({radius, radius}); 
    circle.setPosition({400.f, 400.f});

    bool isDragging = false;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // 1. Check for Mouse Press
            if (const auto* mousePress = event->getIf<sf::Event::MouseButtonPressed>()) {
                // Convert mouse position to float for the check
                sf::Vector2f mousePos = {(float)mousePress->position.x, (float)mousePress->position.y};

                // HIT TEST: Only start dragging if mouse is inside the circle's bounds
                if (circle.getGlobalBounds().contains(mousePos)) {
                    isDragging = true;
                }
            }

            // 2. Stop dragging when mouse is released
            if (event->is<sf::Event::MouseButtonReleased>()) {
                isDragging = false;
            }

            // 3. Move only if dragging is true
            if (const auto* mouseMove = event->getIf<sf::Event::MouseMoved>()) {
                if (isDragging) {
                    circle.setPosition({(float)mouseMove->position.x, (float)mouseMove->position.y});
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }

    return 0;
}