#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <iostream>
#include <string>

int main() {
    // --- CONSTANTS / SETTINGS ---
    const float WINDOW_WIDTH = 800.f;
    const float WINDOW_HEIGHT = 600.f;    

    float shipSpeed = 6.0f;
    float meteorSpeed = 2.0f;
    float bulletSpeed = 10.0f;
    float spawnRate = 45.0f;  // Lower is faster spawning
    float fireRate = 15.0f;   // Lower is faster shooting

    // Window setup
    sf::RenderWindow window(sf::VideoMode({(unsigned int)WINDOW_WIDTH, (unsigned int)WINDOW_HEIGHT}), "Meteor Dodge");
    window.setFramerateLimit(60);
    srand(static_cast<unsigned>(time(NULL)));

    // 1. Load Textures
    sf::Texture shipTexture, meteorTexture, bulletTexture;
    if (!shipTexture.loadFromFile("playerShip1_blue.png")) return -1;
    if (!meteorTexture.loadFromFile("meteorBrown_small1.png")) return -1;
    if (!bulletTexture.loadFromFile("laserBlue06.png")) return -1;

    // 2. Setup Sprites & UI
    sf::Sprite ship(shipTexture);
    ship.setPosition({400.f, 500.f});

    int score = 0;
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) return -1;
    sf::Text scoreText(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({650.f, 10.f});

    // 3. Vectors and Timers
    std::vector<sf::Sprite> meteors;
    std::vector<sf::Sprite> bullets;
    float spawnTimer = 0;
    float bulletTimer = 0;

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) window.close();
        }

        // --- INPUT & MOVEMENT ---
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && ship.getPosition().x > 0)
            ship.move({-shipSpeed, 0.f});
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && ship.getPosition().x < 700)
            ship.move({shipSpeed, 0.f});

        // Shooting Logic
        bulletTimer += 1.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && bulletTimer >= fireRate) {
            sf::Sprite bullet(bulletTexture);
            bullet.setPosition({ship.getPosition().x + 45.f, ship.getPosition().y});
            bullets.push_back(bullet);
            bulletTimer = 0;
        }

        // --- UPDATES ---
        spawnTimer += 1.0f;
        if (spawnTimer >= spawnRate) {
            sf::Sprite meteor(meteorTexture);
            meteor.setPosition({(float)(rand() % 750), -50.f});
            meteors.push_back(meteor);
            spawnTimer = 0;
        }

        // Update Bullets
        for (size_t i = 0; i < bullets.size(); ) {
            bullets[i].move({0.f, -bulletSpeed});
            if (bullets[i].getPosition().y < -20.f) bullets.erase(bullets.begin() + i);
            else i++;
        }

        // Update Meteors & Collisions
        // Outer Loop: Look at each meteor
        for (size_t i = 0; i < meteors.size(); ) {
            meteors[i].move({0.f, meteorSpeed});

            bool destroyed = false;
            // Inner Loop: Look at each bullet for the CURRENT meteor
            for (size_t j = 0; j < bullets.size(); j++) {
                if (meteors[i].getGlobalBounds().findIntersection(bullets[j].getGlobalBounds())) {
                    meteors.erase(meteors.begin() + i); // Remove Meteor
                    bullets.erase(bullets.begin() + j); // Remove Bullet
                    score += 10;
                    destroyed = true;
                    break; // Stop looking at other bullets for this deleted meteor
                }
            }
            if (destroyed) continue;

            // Check Ship vs Meteor
            if (meteors[i].getGlobalBounds().findIntersection(ship.getGlobalBounds())) window.close();

            // Check Boundary
            if (meteors[i].getPosition().y > WINDOW_HEIGHT) {
                meteors.erase(meteors.begin() + i);
                score += 1; // Small reward for dodging
            } else i++;
        }

        // --- DRAWING ---
        scoreText.setString("Score: " + std::to_string(score));
        window.clear();
        window.draw(ship);
        for (auto& b : bullets) window.draw(b);
        for (auto& m : meteors) window.draw(m);
        window.draw(scoreText);
        window.display();
    }
    return 0;
}