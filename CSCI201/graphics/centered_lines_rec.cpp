#include <SFML/Graphics.hpp>

int main() {
    // 1. Setup: Define window dimensions (Similar to Java PW and PH constants)
    const int PW = 800;
    const int PH = 800;
    
    // Create the render window (Equivalent to JFrame)
    sf::RenderWindow window(sf::VideoMode({PW, PH}), "Graphics Primitives 2D Exercise");

    // --- Translation of Java paintComponent Logic ---

    // 2. Crosshair Lines: Horizontal and Vertical (Red)
    // We use a VertexArray with 2 points to draw a simple line
    sf::VertexArray line1(sf::PrimitiveType::Lines, 2);
    line1[0].position = {0.0f, PH / 2.0f};      // Start at left-middle
    line1[1].position = {(float)PW, PH / 2.0f}; // End at right-middle
    line1[0].color = sf::Color::Red;
    line1[1].color = sf::Color::Red;

    sf::VertexArray line2(sf::PrimitiveType::Lines, 2);
    line2[0].position = {PW / 2.0f, 0.0f};      // Start at top-middle
    line2[1].position = {PW / 2.0f, (float)PH}; // End at bottom-middle
    line2[0].color = sf::Color::Red;
    line2[1].color = sf::Color::Red;

    // 3. Centered Rectangle Logic (Blue Outline)
    float RW = 300.0f; // Rectangle Width
    float RH = 200.0f; // Rectangle Height
    sf::RectangleShape rect1({RW, RH});

    // Calculate top-left corner so the rectangle sits in the exact center
    float rect1X = (PW - RW) / 2.0f;
    float rect1Y = (PH - RH) / 2.0f;
    
    rect1.setPosition({rect1X, rect1Y});
    rect1.setFillColor(sf::Color::Transparent); // No fill, just like g2.draw(rect)
    rect1.setOutlineColor(sf::Color::Blue);
    rect1.setOutlineThickness(1.0f);

    // --- The Application Loop (The "Engine") ---
    while (window.isOpen()) {
        // Handle window events (like clicking the "X" to close)
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // 1. Clear the screen (Equivalent to super.paintComponent(g) and setBackground)
        window.clear(sf::Color::White);

        // 2. Draw our primitives (Equivalent to g2.draw calls)
        window.draw(line1);
        window.draw(line2);
        window.draw(rect1); 

        // 3. Display the frame (Pushes the drawing to the monitor)
        window.display();
    }

    return 0;
}