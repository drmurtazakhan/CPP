// event_logger.cpp
// To compile: g++ event_logger.cpp -o event_logger.exe -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <iostream> // To print to the console

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Event Driven Basics");

    while (window.isOpen()) {
        // 1. The Event Loop
        // This loop runs as long as there are "messages" waiting for us
        while (const std::optional event = window.pollEvent()) {
            
            // Handle Window Closing
            if (event->is<sf::Event::Closed>()) {
                std::cout << "Window close event detected!" << std::endl;
                window.close();
            }

            // Handle Key Pressed
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Space) {
                    std::cout << "Spacebar was pressed!" << std::endl;
                }
            }

            // Handle Mouse Click
            if (event->is<sf::Event::MouseButtonPressed>()) {
                std::cout << "Mouse button clicked!" << std::endl;
            }
        }

        // 2. Rendering (Keep it empty for now)
        window.clear(sf::Color::Yellow);
        window.display();
    }

    return 0;
}