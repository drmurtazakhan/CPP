// sprite_move.cpp
// To compile: g++ sprite_move.cpp -o sprite_move.exe -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Sprite Movement Class");
    window.setFramerateLimit(60);

    // 1. Load an image file into a Texture
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("player.png")) {
        // If the image doesn't exist, show an error
        std::cout << "Error: Could not find player.png" << std::endl;
        return -1;
    }

    // 2. Create the Sprite and "stick" the texture onto it
    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition({400.f, 400.f});

    float pixelShift = 10.f;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // Keyboard logic (Same as the circle!)
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Left) {
                    playerSprite.move({-pixelShift, 0.f});
                }
                else if (keyPressed->code == sf::Keyboard::Key::Right) {
                    playerSprite.move({pixelShift, 0.f});
                }
                else if (keyPressed->code == sf::Keyboard::Key::Up) {
                    playerSprite.move({0.f, -pixelShift});
                }
                else if (keyPressed->code == sf::Keyboard::Key::Down) {
                    playerSprite.move({0.f, pixelShift});
                }
            }
        }

        window.clear(sf::Color::Black);
        window.draw(playerSprite); // Draw the sprite instead of a shape
        window.display();
    }

    return 0;
}