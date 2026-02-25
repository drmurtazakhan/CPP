// To compile: g++ -o caps_converter.exe caps_converter.cpp -lsfml-graphics -lsfml-window -lsfml-system
// To Run: ./caps_converter.exe
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <algorithm> // For transform

int main() {
    sf::RenderWindow window(sf::VideoMode({600, 500}), "Caps Converter Class");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        std::cout << "Error: Place arial.ttf in the folder!" << std::endl;
    }

    std::string rawInput = "";
    std::string resultOutput = "";

    // 1. Top Input Box (Visual)
    sf::RectangleShape inputBox({500.f, 50.f});
    inputBox.setFillColor(sf::Color::White);
    inputBox.setPosition({50.f, 80.f});

    sf::Text inputText(font, "Type: ", 25);
    inputText.setFillColor(sf::Color::Black); // Black text on white box
    inputText.setPosition({60.f, 90.f});

    // 2. Bottom Output Box (Visual)
    sf::RectangleShape outputBox({500.f, 50.f});
    outputBox.setFillColor(sf::Color(200, 200, 200)); // Grey box for output
    outputBox.setPosition({50.f, 180.f});

    sf::Text outputText(font, "RESULT: ", 25);
    outputText.setFillColor(sf::Color::Blue);
    outputText.setPosition({60.f, 190.f});

    // 3. Submit Button
    sf::RectangleShape submitBtn({150.f, 50.f});
    submitBtn.setFillColor(sf::Color::Green);
    submitBtn.setPosition({225.f, 300.f});

    sf::Text btnLabel(font, "CONVERT", 20);
    btnLabel.setFillColor(sf::Color::Black);
    btnLabel.setPosition({255.f, 312.f});

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // Keyboard: Text Typing
            if (const auto* textEvent = event->getIf<sf::Event::TextEntered>()) {
                if (textEvent->unicode < 128 && textEvent->unicode != 8 && textEvent->unicode != 13) {
                    rawInput += static_cast<char>(textEvent->unicode);
                }
                if (textEvent->unicode == 8 && !rawInput.empty()) {
                    rawInput.pop_back();
                }
            }

            // Logic to perform conversion
            auto convertToCaps = [&]() {
                resultOutput = rawInput;
                std::transform(resultOutput.begin(), resultOutput.end(), resultOutput.begin(), ::toupper);
            };

            // Keyboard: Enter Trigger
            if (const auto* keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                if (keyEvent->code == sf::Keyboard::Key::Enter) {
                    convertToCaps();
                }
            }

            // Mouse: Button Trigger
            if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                sf::Vector2f mousePos = window.mapPixelToCoords(mouseEvent->position);
                if (submitBtn.getGlobalBounds().contains(mousePos)) {
                    convertToCaps();
                }
            }
        }

        inputText.setString("Type: " + rawInput);
        outputText.setString("RESULT: " + resultOutput);

        window.clear(sf::Color(50, 50, 50)); // Dark grey background
        window.draw(inputBox);
        window.draw(inputText);
        window.draw(outputBox);
        window.draw(outputText);
        window.draw(submitBtn);
        window.draw(btnLabel);
        window.display();
    }

    return 0;
}