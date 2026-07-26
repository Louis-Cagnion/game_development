#pragma once
#include <string>
#include <filesystem>

class AssetManager {
public:
    static std::string resolvePath(const std::string& relativePath);

private:
    static constexpr const char* PRIVATE_ROOT = "assets/private";
    static constexpr const char* PUBLIC_ROOT  = "assets/public";
};