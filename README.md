# Card_game

<div align="center">
Mokobia Jane Chidima

Group:24.B83-mm

st135735@student.spbu.ru

The docs folder holds the uml folder(class diagram), architectural structure folder( where you will find the general architectural description, class diagram.png/.md, component diagram.png/.md ,usage scenerio, and test plan.)

</div>

---

## 📖 Project Description

**Card RPG Game** is a text-based card role-playing game where players battle AI-controlled enemies using character abilities, effect cards, and items.


---

## 🏗️ Architecture

The project has a modular architecture based on object-oriented programming, consisting of the following main components:

- [System Overview](docs/architecture/architecture_description.md)
- [Requirements and Use Cases](docs/architecture/usage_scenarios.md)
- [Component Diagram](docs/architecture/component_diagram.md)
- [Class Diagram](docs/architecture/class_diagram.md)
- [Testing Plan](docs/architecture/test_plan.md)

### 📂 Project Structure

```
card-rpg-lab/
├── include/           # Header files (*.h)
├── src/               # Source code (*.cpp)
├── tests/             # Unit tests
├── docs/              # Project documentation
├── build/             # Build files
├── CMakeLists.txt     # Build configuration
├── Doxyfile           # Doxygen settings
├── assets             # holds fonts & images
├── mainpage.dox       # mainpagr for doxgen
└── README.md          # This file
```

---

## 🔧 Dependencies and Installation

### Requirements

- **C++17** compatible compiler (GCC, Clang, MSVC)
- **CMake** (version 3.10 or higher)
- ** Test** (for unit tests)
- **Doxygen** (for documentation generation)

# Build the project
mkdir build && cd build
cmake ..
cmake --build .
./CardGame
```

---

#### Battle Actions:
```
1 - Attack
2 - Use Card
3 - Defend
```

---

## 🧪 Testing

The project has complete unit test coverage using the Catch2 framework.

```bash
# Run tests
cd build
ctest

```

## 📚 Documentation

The project code is fully documented using Doxygen.

```bash
# Generate documentation
doxygen Doxyfile
xdg-open docs/html/index.html
```

After running this command, you will find the generated documentation in the `docs/html` directory.


### Design Principles

The codebase follows these design principles:
- **Object-oriented architecture** 
- **Complete unit test coverage**
- **Comprehensive Doxygen documentation**


## 📋 Development Roadmap

- **Graphical Interface**: Adding visual representation of the game (SFML)
- **Multiplayer**: Network play via local network or internet

---

