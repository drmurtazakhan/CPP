// Meteor_Dodge1.cpp
// compile with: g++ Meteor_Dodge1.cpp -o Meteor_Dodge1 -lsfml-graphics -lsfml-window -lsfml-system
// run with: ./Meteor_Dodge1

#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <iostream>
#include <string> // Added for to_string

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Meteor Dodge");
    window.setFramerateLimit(60);
    srand(static_cast<unsigned>(time(NULL)));

    // 1. Load Ship
    sf::Texture shipTexture;
    if (!shipTexture.loadFromFile("playerShip1_blue.png")) return -1; 
    sf::Sprite ship(shipTexture);
    ship.setPosition({400, 500});

    // 2. Load Meteor
    sf::Texture meteorTexture;
    if (!meteorTexture.loadFromFile("meteorBrown_small1.png")) return -1;

    // Score and Font Setup ---
    int score = 0;
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) { // Ensure arial.ttf is in your folder
        std::cout << "Error: font not found!" << std::endl;
        return -1;
    }
    sf::Text scoreText(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({650.f, 10.f}); // Top right
    // ---------------------------------

    std::vector<sf::Sprite> meteors;
    float spawnTimer = 0;
    float shipSpeed = 6.0f;
    float meteorSpeed = 3.5f;

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) window.close();
        }

        // Movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && ship.getPosition().x > 0)
            ship.move({-shipSpeed, 0.f});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && ship.getPosition().x < 700)
            ship.move({shipSpeed, 0.f});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && ship.getPosition().y > 0)
            ship.move({0.f, -shipSpeed});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && ship.getPosition().y < 520)
            ship.move({0.f, shipSpeed});

        // Spawning
        spawnTimer += 1.0f;
        if (spawnTimer >= 45.0f) {
            sf::Sprite meteor(meteorTexture);
            meteor.setPosition({(float)(rand() % 750), -50.f});
            meteors.push_back(meteor);
            spawnTimer = 0;
        }

        // Update Meteors
        for (size_t i = 0; i < meteors.size(); ) {
            meteors[i].move({0.f, meteorSpeed});

            if (meteors[i].getGlobalBounds().findIntersection(ship.getGlobalBounds())) {
                std::cout << "Final Score: " << score << std::endl;
                window.close();
            }

            if (meteors[i].getPosition().y > 600) {
                meteors.erase(meteors.begin() + i);                
                score++;                
            } else {
                i++;
            }
        }
        
        scoreText.setString("Score: " + std::to_string(score));
        // -------------------------------

        // Drawing
        window.clear();
        window.draw(ship);
        for (const auto& m : meteors) window.draw(m);
        window.draw(scoreText); // Draw the score
        window.display();
    }

    return 0;
}