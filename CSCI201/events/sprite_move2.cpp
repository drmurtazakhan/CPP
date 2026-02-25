#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <iostream>

int main() {
    // Window setup
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Meteor Dodge");
    window.setFramerateLimit(60);
    
    // Seed for random meteor positions
    srand(static_cast<unsigned>(time(NULL)));

    // 1. Load Your Specific Ship Image
    sf::Texture shipTexture;
    if (!shipTexture.loadFromFile("playerShip1_blue.png")) {
        std::cout << "Error: playerShip1_blue.png not found!" << std::endl;
        return -1; 
    }
    sf::Sprite ship(shipTexture);
    ship.setPosition({400, 500});

    // 2. Load Your Specific Meteor Image
    sf::Texture meteorTexture;
    if (!meteorTexture.loadFromFile("meteorBrown_small1.png")) {
        std::cout << "Error: meteorBrown_small1.png not found!" << std::endl;
        return -1;
    }

    std::vector<sf::Sprite> meteors;
    float spawnTimer = 0;
    
    // Balance settings
    float shipSpeed = 6.0f;    // Speed of your ship
    float meteorSpeed = 3.5f;  // Slower speed for better gameplay

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // 3. Four-Way Movement Logic
        // Left and Right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && ship.getPosition().x > 0)
            ship.move({-shipSpeed, 0.f});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && ship.getPosition().x < 700)
            ship.move({shipSpeed, 0.f});
        
        // Up and Down
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && ship.getPosition().y > 0)
            ship.move({0.f, -shipSpeed});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && ship.getPosition().y < 520)
            ship.move({0.f, shipSpeed});

        // 4. Slower Spawning Logic
        spawnTimer += 1.0f;
        if (spawnTimer >= 45.0f) { // Spawns roughly every 0.75 seconds
            sf::Sprite meteor(meteorTexture);
            meteor.setPosition({(float)(rand() % 750), -50.f});
            meteors.push_back(meteor);
            spawnTimer = 0;
        }

        // 5. Update Meteors and check for Game Over
        for (size_t i = 0; i < meteors.size(); ) {
            meteors[i].move({0.f, meteorSpeed});

            // Collision Check
            if (meteors[i].getGlobalBounds().findIntersection(ship.getGlobalBounds())) {
                std::cout << "BOOM! Game Over." << std::endl;
                window.close();
            }

            // Remove if it leaves the screen
            if (meteors[i].getPosition().y > 600) {
                meteors.erase(meteors.begin() + i);
            } else {
                i++;
            }
        }

        // Drawing
        window.clear();
        window.draw(ship);
        for (const auto& m : meteors) {
            window.draw(m);
        }
        window.display();
    }

    return 0;
}