# Game Development

A 2D puzzle-based adventure game where every action shapes the story and alters the game world.

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
├── include/                # Header files
├── assets/                 # Game resources
│   ├── public/             # Public resources
│   └── private/            # Private assets (Git submodule)
│
├── docs/                   # Documentation and design files
│
├── README.md
├── .gitignore
├── .gitmodules
├── .gitattributes
└── .env.example
```

## Folder description

### `src/`

Contains the source code of the game.

Examples:

* gameplay systems;
* game logic;
* engine features;
* tools.

---

### `include/`

Contains header files used by the project source code.

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
