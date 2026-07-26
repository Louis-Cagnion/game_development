#include "core/AssetManager.hpp"

/// @brief Checks assets/private first, falls back to assets/public if the asset isn't found there.
std::string AssetManager::resolvePath(const std::string& relativePath) {
    std::filesystem::path privatePath = std::filesystem::path(PRIVATE_ROOT) / relativePath;
    if (std::filesystem::exists(privatePath)) {
        return privatePath.string();
    }
    return (std::filesystem::path(PUBLIC_ROOT) / relativePath).string();
}