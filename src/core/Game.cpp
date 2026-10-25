#include "core/Game.hpp"

/// @brief Creates the game window (WIN_WIDTH x WIN_HEIGHT) and sets up the red placeholder square.
Game::Game()
    : m_window(sf::VideoMode({WIN_WIDTH, WIN_HEIGHT}), "Game Development")
{
    float square_side = 100;
    sf::Vector2f size(square_side, square_side);
    m_red_square.setSize(size);
    sf::Color red(255, 0, 0);
    m_red_square.setFillColor(red);
    sf::Vector2f pos(WIN_WIDTH / 2 - (square_side / 2), WIN_HEIGHT / 2 - (square_side / 2));
    m_red_square.setPosition(pos);
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
        if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            m_window.close();
        }
    }
}

/// @brief Updates game logic.
void Game::update(float deltaTime) {
    static constexpr sf::Keyboard::Key keys[8] = {
        sf::Keyboard::Key::W,
        sf::Keyboard::Key::Up,
        sf::Keyboard::Key::A,
        sf::Keyboard::Key::Left,
        sf::Keyboard::Key::S,
        sf::Keyboard::Key::Down,
        sf::Keyboard::Key::D,
        sf::Keyboard::Key::Right
    };
    static constexpr sf::Vector2f offsets[4] = {
        sf::Vector2f({0.0f, -1.0f}),
        sf::Vector2f({-1.0f, 0.0f}),
        sf::Vector2f({0.0f, 1.0f}),
        sf::Vector2f({1.0f, 0.0f})
    };
    sf::Vector2f offset(0.0f, 0.0f);

    for (int i = 0; i < 8; i += 2) {
        if (sf::Keyboard::isKeyPressed(keys[i])
            || sf::Keyboard::isKeyPressed(keys[i + 1]))
            offset += offsets[i / 2];
    }
    if (offset != sf::Vector2f())
        offset = offset.normalized();
    offset *= MVT_SPEED * deltaTime;
    m_red_square.move(offset);
}

/// @brief Clears the window and displays the current frame. Currently just clears to black.
void Game::render() {
    m_window.clear(sf::Color::Black);
    m_window.draw(m_red_square);
    m_window.display();
}