#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

const int FRM_WIDTH = 600;
const int FRM_HEIGHT = 300;

int main() {
    sf::RenderWindow window(sf::VideoMode(FRM_WIDTH, FRM_HEIGHT), "String Animation");
    window.setFramerateLimit(60);
    
    sf::Font font;
    if (!font.loadFromFile("Arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }
    
    sf::Text text("String Animation", font, 20);
    text.setFillColor(sf::Color::Red);
    int x = 0, y = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        x += 5;
        y += 5;
        text.setPosition(x, y);
        
        if (x >= FRM_WIDTH || y >= FRM_HEIGHT) {
            window.close();
        }
        
        window.clear(sf::Color::White);
        window.draw(text);
        window.display();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    return 0;
}