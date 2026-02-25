// sprite_move.cpp
// To compile: g++ sprite_move.cpp -o sprite_move.exe -lsfml-graphics -lsfml-window -lsfml-system
// To Run: ./sprite_move.exe

#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Space Ship Movement");
    window.setFramerateLimit(60);

    // 1. Load the ship texture
    sf::Texture shipTexture;
    if (!shipTexture.loadFromFile("playerShip1_blue.png")) {
        std::cout << "Error: playerShip1_blue.png not found!" << std::endl;
        return -1;
    }

    // 2. Initialize sprite with the texture (SFML 3 requirement)
    sf::Sprite ship(shipTexture);

    ship.setPosition({400.f, 500.f}); 

    // Updated variable name
    float pixelShift = 7.f; 

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // 3. Movement Logic using pixelShift
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
            ship.move({-pixelShift, 0.f});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
            ship.move({pixelShift, 0.f});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            ship.move({0.f, -pixelShift});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            ship.move({0.f, pixelShift});
        }

        window.clear(sf::Color::Black);
        window.draw(ship);
        window.display();
    }

    return 0;
}