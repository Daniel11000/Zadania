#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Moving Point");

    sf::CircleShape point(2.f);
    point.setFillColor(sf::Color::White);
    point.setPosition(0.f, 0.f);

    sf::Clock clock;

    const sf::Vector2f startPos(0.f, 0.f);
    const sf::Vector2f pointB(40.f, 0.f);
    const sf::Vector2f pointC(40.f, 10.f);
    const float durationAB = 2000.f; // Czas trwania animacji od punktu A do B w ms
    const float durationBC = 3000.f; // Czas trwania animacji od punktu B do C w ms
    const float durationCA = 1000.f; // Czas trwania animacji od punktu C do A w ms
    const int numLoops = 5; // Liczba powtórzeń trasy

    for (int i = 0; i < numLoops; ++i)
    {
        // Przechodzimy z punktu A do punktu B
        sf::Vector2f distanceAB = pointB - startPos;
        float elapsedTimeAB = 0.f;
        while (elapsedTimeAB < durationAB)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            elapsedTimeAB += clock.restart().asMilliseconds();

            if (elapsedTimeAB >= durationAB)
            {
                point.setPosition(pointB);
                window.clear();
                window.draw(point);
                window.display();
                continue;
            }

            float t = elapsedTimeAB / durationAB;
            sf::Vector2f newPos = startPos + distanceAB * t;
            point.setPosition(newPos);

            window.clear();
            window.draw(point);
            window.display();
        }

        // Przechodzimy z punktu B do punktu C
        sf::Vector2f distanceBC = pointC - pointB;
        float elapsedTimeBC = 0.f;
        while (elapsedTimeBC < durationBC)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            elapsedTimeBC += clock.restart().asMilliseconds();

            if (elapsedTimeBC >= durationBC)
            {
                point.setPosition(pointC);
                window.clear();
                window.draw(point);
                window.display();
                continue;
            }

            float t = elapsedTimeBC / durationBC;
            sf::Vector2f newPos = pointB + distanceBC * t;
            point.setPosition(newPos);

            window.clear();
            window.draw(point);
            window.display();
        }

        // Przechodzimy z punktu C do punktu A
        sf::Vector2f distanceCA = startPos - pointC;
        float elapsedTimeCA = 0.f;
        while (elapsedTimeCA < durationCA)
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            elapsedTimeCA += clock.restart().asMilliseconds();

            if (elapsedTimeCA >= durationCA)
            {
            point.setPosition(startPos);
            window.clear();
            window.draw(point);
            window.display();
            continue;
            }

                    float t = elapsedTimeCA / durationCA;
        sf::Vector2f newPos = pointC + distanceCA * t;
        point.setPosition(newPos);

        window.clear();
        window.draw(point);
        window.display();
    }
}

return 0;


}

