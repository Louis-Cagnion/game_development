# Game Development

A 2D puzzle-based adventure game where every action shapes the story and alters the game world.

## Table of Contents

- [About the project](#about-the-project)
- [Project structure](#project-structure)
  - [Folder description](#folder-description)
  - [Build](#build)
  - [Run](#run)
  - [Troubleshooting](#troubleshooting)
  - [Dependencies](#dependencies)
- [Private assets repository](#private-assets-repository)
  - [Clone the project with private assets](#clone-the-project-with-private-assets)
- [Project collaboration workflow](#project-collaboration-workflow)
- [Creating a branch using GitHub website](#creating-a-branch-using-github-website)
- [Adding or updating files](#adding-or-updating-files)
- [Creating a Pull Request](#creating-a-pull-request)
- [Branch naming](#branch-naming)
- [Large files](#large-files)
- [Development guidelines](#development-guidelines)


## About the project

**Game Development** is a 2D adventure game focused on exploration, puzzles, and storytelling.

The player's actions influence the evolution of the story and the game world. The goal is to create an experience where gameplay mechanics, narrative choices, and the environment are interconnected.

The project aims to combine gameplay and storytelling by creating a world that evolves based on player decisions.

---

# Project structure

The project is organized into different sections:

```
game_development/
│
├── src/                    # Game source code
│   ├── core/               # Game loop, game states, AssetManager
│   ├── systems/            # Input, collision, rendering
│   ├── entities/           # Player, interactive objects
│   └── scenes/             # Scene/level management
│
├── include/                # Header files (mirrors src/)
│   ├── core/
│   ├── systems/
│   ├── entities/
│   └── scenes/
│
├── assets/                 # Game resources
│   ├── public/             # Public resources
│   └── private/            # Private assets (Git submodule)
│
├── docs/                   # Documentation and design files
│
├── CMakeLists.txt          # Build configuration
├── vcpkg.json              # Dependency manifest (SFML)
├── README.md
├── .gitignore
├── .gitmodules
├── .gitattributes
└── .env.example
```

## Folder description

### `src/`

Contains the game source code, organized by responsibility:

* `core/` — main game loop, game states, asset resolution (`AssetManager`);
* `systems/` — input handling, collision detection, rendering;
* `entities/` — player and interactive objects;
* `scenes/` — scene/level loading and management.

---

### `include/`

Header files mirroring the structure of `src/`.

---

## Build

The project uses **CMake** with **vcpkg** to manage the SFML dependency.

### 1. Install system dependencies (Linux/Ubuntu)

```bash
sudo apt update
sudo apt install -y cmake g++ ninja-build pkg-config \
    libx11-dev libxrandr-dev libxi-dev libxcursor-dev \
    libudev-dev libgl1-mesa-dev
```

### 2. Install vcpkg (one-time setup)

```bash
git clone https://github.com/microsoft/vcpkg.git ~/vcpkg
~/vcpkg/bootstrap-vcpkg.sh
```

### 3. Clone the project

```bash
git clone --recurse-submodules git@github.com:Louis-Cagnion/game_development.git
cd game_development
```

If already cloned without submodules:

```bash
git submodule update --init --recursive
```

### 4. Configure the project

This step downloads and builds SFML automatically via vcpkg (can take a few minutes the first time).

```bash
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=~/vcpkg/scripts/buildsystems/vcpkg.cmake -G Ninja
```

### 5. Build the project

```bash
cmake --build build
```

### 6. Rebuilding after code changes

If you only edited existing `.cpp`/`.hpp` files:

```bash
cmake --build build
```

If you added a new `.cpp` file, changed `CMakeLists.txt`, or changed `vcpkg.json`, re-run step 4 first, then step 5.

---

### `assets/`

Contains game resources used by the project.

Examples:

* textures;
* sounds;
* music;
* models;
* animations;
* other game resources.

Large files are managed using Git LFS.

The `assets/private/` directory is a Git submodule linked to a separate private repository.

---

### `assets/public/`

Contains resources that can be shared publicly.

Examples:

* demonstration assets;
* placeholders;
* open resources;
* promotional files.

---

### `assets/private/`

Contains production resources that should not be publicly available.

Examples:

* unreleased artwork;
* original source files;
* licensed assets;
* high resolution textures;
* private models;
* internal resources.

This directory is managed through a private Git repository and is not accessible from the public repository without permission.

---

### `docs/`

Contains project documentation:

* story information;
* game design documents;
* gameplay specifications;
* technical documentation.

---

## Run

```bash
./build/GameDevelopment
```

A black 1280x720 window should open. This confirms SFML, CMake, and vcpkg are working correctly. Close the window to exit.

---

## Troubleshooting

- **`vcpkg install failed` / version errors**: check that `vcpkg.json` uses a valid `builtin-baseline` (a commit SHA, not a branch name) and a version of SFML that actually exists in the vcpkg registry.
- **`CMake was unable to find a build program`**: make sure `ninja-build` is installed (`sudo apt install ninja-build`) and that you passed `-G Ninja`.
- **SFML build fails with missing system libraries**: install the packages listed in step 1 (`libx11-dev`, `libxi-dev`, `libxrandr-dev`, `libxcursor-dev`, `libudev-dev`, `libgl1-mesa-dev`).
- **`find_package(SFML)` fails / wrong version**: `CMakeLists.txt` must request `find_package(SFML 3.0 COMPONENTS Graphics Window System Audio REQUIRED)` — component names must be capitalized (SFML 3 syntax), not lowercase (SFML 2 syntax).

---

## Dependencies

- **CMake** ≥ 3.20
- **Ninja** (build system)
- **g++** (C++20)
- **vcpkg** (C++ dependency manager, installed separately)
- **SFML** ≥ 3.0 (installed automatically by vcpkg via `vcpkg.json`)

### System libraries (Linux)

```bash
sudo apt install -y cmake g++ ninja-build pkg-config \
    libx11-dev libxrandr-dev libxi-dev libxcursor-dev \
    libudev-dev libgl1-mesa-dev
```

# Private assets repository

The project uses a separate private repository for sensitive resources.

The private repository contains:

* production artwork;
* source files;
* large assets;
* unreleased content.

The public repository only stores a reference to the current version of the private assets repository through a Git submodule.

---

## Clone the project with private assets

To download the project with all private resources:

```bash
git clone --recurse-submodules git@github.com:Louis-Cagnion/game_development.git
```

If the repository was already cloned:

```bash
git submodule update --init --recursive
```

You need access to the private assets repository to download its content.

---

# Project collaboration workflow

To keep the project organized, the `main` branch represents the stable version of the game.

Direct modifications to `main` should be avoided. All new content must be added through a separate branch and reviewed using a Pull Request.

This workflow applies to:

* new artwork;
* story content;
* dialogue;
* game data;
* code changes;
* bug fixes.

---

# Creating a branch using GitHub website

## 1. Open the repository

Go to the project repository on GitHub.

At the top of the page, click on the branch selector:

```
main ▼
```

## 2. Create a new branch

Enter the name of your new branch.

Choose a name that describes your work:

Examples:

```
art/main-character
art/environment-village
story/chapter-one
data/items-update
feature/inventory-system
```

Then click:

```
Create branch: <branch-name>
```

Your new branch is now created from the current version of `main`.

---

# Adding or updating files

Once your branch is created:

1. Navigate to the folder where you want to add or modify files.
2. Click:

```
Add file
→ Upload files
```

3. Select your files.
4. Add a short description of your changes.

Example:

```
Add new character artwork
```

5. Click:

```
Commit changes
```

Make sure the commit is made on your new branch, not on `main`.

---

# Creating a Pull Request

When your work is finished:

1. Open the repository page.
2. Click:

```
Compare & pull request
```

or go to:

```
Pull requests
→ New pull request
```

3. Select:

```
base: main
compare: your-branch-name
```

Example:

```
base: main
compare: art/main-character
```

4. Add a description explaining your changes.
5. Create the Pull Request.

After review, the changes can be merged into `main`.

---

# Branch naming

Use clear branch names:

| Type    | Example               |
| ------- | --------------------- |
| Artwork | `art/character-name`  |
| Story   | `story/chapter-name`  |
| Data    | `data/item-update`    |
| Bug fix | `fix/bug-description` |
| Feature | `feature/system-name` |

---

# Large files

Git LFS is used for large game files such as:

* high resolution images;
* audio files;
* 3D assets;
* animation files;
* other large resources.

This avoids storing heavy binary files directly in the Git history.

---

# Development guidelines

Before adding new content:

* make sure the correct branch type is used;
* keep files organized in the correct directory;
* avoid adding private resources to the public repository;
* use meaningful commit messages;
* update the private assets repository when modifying production resources.

The goal is to keep the project history clean and easy to understand.