#include "core/Game.hpp"

Game::Game()
    : m_window(sf::VideoMode(1280, 720), "Game Development")
{
}

void Game::run() {
    sf::Clock clock;
    while (m_window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
    }
}

void Game::update(float deltaTime) {
    (void)deltaTime;
}

void Game::render() {
    m_window.clear(sf::Color::Black);
    m_window.display();
}