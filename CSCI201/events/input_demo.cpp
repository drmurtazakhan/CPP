// input_demo.cpp
// To compile: g++ input_demo.cpp -o input_demo.exe -lsfml-graphics -lsfml-window -lsfml-system
// To Run: ./input_demo.exe

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode({600, 400}), "Keyboard and Mouse Class");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        std::cout << "Error: Place arial.ttf in the folder!" << std::endl;
    }

    // 1. THE FIX: Text(font, string, size)
    // SFML 3 requires the font to be the FIRST argument.
    sf::Text userInput(font, "Type here: ", 30);
    userInput.setPosition({50.f, 100.f});
    userInput.setFillColor(sf::Color::White);
    std::string displayString = "Type here: ";

    // 2. Setup Button
    sf::RectangleShape button({150.f, 50.f});
    button.setFillColor(sf::Color::Blue);
    button.setPosition({225.f, 250.f});

    // 3. THE FIX: Same here, font must come first.
    sf::Text btnLabel(font, "SUBMIT", 20);
    btnLabel.setPosition({260.f, 262.f});
    btnLabel.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // --- KEYBOARD EVENT: Text Input ---
            if (const auto* textEvent = event->getIf<sf::Event::TextEntered>()) {
                if (textEvent->unicode < 128 && textEvent->unicode != 8 && textEvent->unicode != 13) {
                    displayString += static_cast<char>(textEvent->unicode);
                }
                if (textEvent->unicode == 8 && displayString.length() > 11) {
                    displayString.pop_back();
                }
            }

            // --- KEYBOARD EVENT: Enter Key ---
            if (const auto* keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                if (keyEvent->code == sf::Keyboard::Key::Enter) {
                    userInput.setFillColor(sf::Color::Green);
                }
            }

            // --- MOUSE EVENT: Button Click ---
            if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                sf::Vector2f mousePos = window.mapPixelToCoords(mouseEvent->position);
                if (button.getGlobalBounds().contains(mousePos)) {
                    userInput.setFillColor(sf::Color::Green);
                }
            }
        }

        userInput.setString(displayString);

        window.clear(sf::Color::Black);
        window.draw(userInput);
        window.draw(button);
        window.draw(btnLabel);
        window.display();
    }

    return 0;
}