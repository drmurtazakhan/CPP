// timer_toggle.cpp
// To compile: g++ timer_toggle.cpp -o timer_toggle.exe -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode({400, 300}), "Timer Toggle Class");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        std::cout << "ERROR: arial.ttf not found!" << std::endl;
    }

    // 1. Setup Text (Centered)
    sf::Text timerText(font);
    timerText.setCharacterSize(60);
    timerText.setFillColor(sf::Color::White);
    timerText.setString("0");
    // Center the text roughly
    timerText.setPosition({170.f, 80.f});

    // 2. Setup Rectangle Button (Centered below text)
    sf::RectangleShape button({150.f, 60.f});
    button.setFillColor(sf::Color::Blue); 
    button.setOrigin({75.f, 30.f}); // Origin at center of rectangle
    button.setPosition({200.f, 210.f}); // Center of the 400x300 window

    sf::Clock clock;
    float totalTime = 0.f;
    bool isRunning = false;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* mousePress = event->getIf<sf::Event::MouseButtonPressed>()) {
                sf::Vector2f mousePos = sf::Vector2f(mousePress->position);
                
                // Check if we hit the rectangle
                if (button.getGlobalBounds().contains(mousePos)) {
                    isRunning = !isRunning;
                    button.setFillColor(isRunning ? sf::Color::Red : sf::Color::Blue);
                    std::cout << "SUCCESS! Timer is " << (isRunning ? "RUNNING" : "STOPPED") << std::endl;
                }
            }
        }

        // Logic
        sf::Time elapsed = clock.restart(); 
        if (isRunning) {
            totalTime += elapsed.asSeconds();
        }

        timerText.setString(std::to_string((int)totalTime));

        window.clear(sf::Color::Black);
        window.draw(button);    // Draw button
        window.draw(timerText); // Draw text on top
        window.display();
    }

    return 0;
}