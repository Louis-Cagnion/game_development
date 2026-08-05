#pragma once
#include <string>
#include <filesystem>

/**
 * @brief Resolves an asset's path, prioritizing private resources.
 *
 * Looks first in assets/private (private Git submodule), and falls back
 * to assets/public if the resource isn't found there (useful if the
 * submodule isn't cloned, e.g. a contributor without private access).
 */
class AssetManager {
public:
    /**
     * @brief Resolves the full path of an asset.
     * @param relativePath Relative path of the asset (e.g. "textures/player.png").
     * @return Full path to the file found (private first, then public).
     */
    static std::string resolvePath(const std::string& relativePath);

private:
    static constexpr const char* PRIVATE_ROOT = "assets/private";
    static constexpr const char* PUBLIC_ROOT  = "assets/public";
};