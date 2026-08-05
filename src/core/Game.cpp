#include "core/Game.hpp"

/// @brief Constructs the game window with a fixed 1280x720 resolution.
Game::Game()
    : m_window(sf::VideoMode({1280, 720}), "Game Development")
{
}

/// @brief Main loop: processes events, updates game state, and renders each frame until the window closes.
void Game::run() {
    sf::Clock clock;
    while (m_window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        processEvents();
        update(deltaTime);
        render();
    }
}

/// @brief Polls and handles SFML events (currently only window close).
void Game::processEvents() {
    while (const std::optional event = m_window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            m_window.close();
        }
    }
}

/// @brief Updates game logic. Currently empty, to be implemented as gameplay systems are added.
void Game::update(float deltaTime) {
    (void)deltaTime;
}

/// @brief Clears the window and displays the current frame. Currently just clears to black.
void Game::render() {
    m_window.clear(sf::Color::Black);
    m_window.display();
}