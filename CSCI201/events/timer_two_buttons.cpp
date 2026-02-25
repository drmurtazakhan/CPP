// timer_two_buttons.cpp
// To compile: g++ timer_two_buttons.cpp -o timer_two_buttons.exe -lsfml-graphics -lsfml-window -lsfml-system
// To Run: ./timer_two_buttons.exe

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


int main() {
    sf::RenderWindow window(sf::VideoMode({400, 400}), "Dual Button Timer");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        std::cout << "ERROR: arial.ttf not found!" << std::endl;
    }

    // 1. Timer Text
    sf::Text timerText(font);
    timerText.setCharacterSize(80);
    timerText.setFillColor(sf::Color::White);
    timerText.setPosition({160.f, 50.f});
    timerText.setString("0");

    // 2. Start Button (Green)
    sf::RectangleShape startBtn({120.f, 50.f});
    startBtn.setFillColor(sf::Color::Green);
    startBtn.setPosition({50.f, 250.f});

    // 3. Stop Button (Red)
    sf::RectangleShape stopBtn({120.f, 50.f});
    stopBtn.setFillColor(sf::Color::Red);
    stopBtn.setPosition({230.f, 250.f});

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
                
                // Check Start Button
                if (startBtn.getGlobalBounds().contains(mousePos)) {
                    isRunning = true;
                    std::cout << "START Pressed" << std::endl;
                }
                
                // Check Stop Button
                if (stopBtn.getGlobalBounds().contains(mousePos)) {
                    isRunning = false;
                    std::cout << "STOP Pressed" << std::endl;
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
        window.draw(timerText);
        window.draw(startBtn);
        window.draw(stopBtn);
        window.display();
    }

    return 0;
}