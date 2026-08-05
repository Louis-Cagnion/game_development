#pragma once
#include <SFML/Graphics.hpp>

/**
 * @brief Main game class, handles the window and the main loop.
 */
class Game {
public:
    /// @brief Creates the game window (1280x720).
    Game();

    /// @brief Runs the main loop (events, update, render) until the window closes.
    void run();

private:
    /// @brief Handles SFML events (close, input, etc.).
    void processEvents();

    /**
     * @brief Updates the game logic.
     * @param deltaTime Time elapsed since the last frame, in seconds.
     */
    void update(float deltaTime);

    /// @brief Draws the current frame to the screen.
    void render();

    sf::RenderWindow m_window; ///< Main game window.
};