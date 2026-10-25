#pragma once
#include <SFML/Graphics.hpp>

/**
 * @brief Main game class, handles the window and the main loop.
 */
class Game {
private:
    sf::RenderWindow        m_window; ///< Main game window.
    sf::RectangleShape      m_red_square;

    //const
    static constexpr int    WIN_WIDTH = 1280;
    static constexpr int    WIN_HEIGHT = 720;
    static constexpr float    MVT_SPEED = 300.0;

    /// @brief Handles SFML events (close, input, etc.).
    void processEvents();

    /**
     * @brief Updates the game logic.
     * @param deltaTime Time elapsed since the last frame, in seconds.
     */
    void update(float deltaTime);

    /// @brief Draws the current frame to the screen.
    void render();

public:
    /// @brief Creates the game window and sets up the red placeholder square.
    Game();

    /// @brief Runs the main loop (events, update, render) until the window closes.
    void run();
};