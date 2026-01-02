# Asteroid

A C++ / SFML project inspired by the classic *Asteroids* arcade game, built as an exercise in software architecture, system design, and clean responsibility separation.

The project emphasizes modular systems, explicit scene management, and decoupled gameplay logic.

## Tech
- Language: C++
- Graphics / Windowing: SFML
- Platform: Windows
- Tooling: Visual Studio

## Architecture Overview

### Scene Management
- `SceneManager` owns the active scene and handles transitions via `SceneID`.
- Each scene encapsulates its own update and draw logic.
- Scenes act as composition roots, wiring together entities and systems.

Implemented scenes:
- `AsteroidGameScene` — main gameplay loop, scoring, spawning
- `GameOverScene` — terminal state and transition handling

### Entities
- `Entity` is an abstract base class implementing:
  - rendering (`sf::Drawable`)
  - spatial transforms (`sf::Transformable`)
  - collision behavior (`ICollision`)
- Shared lifecycle handling via `markedForRemoval`.
- Concrete entities:
  - `Player`
  - `Asteroid`
  - `Projectile`
  - `FlyingBallon`
  
  ### Collision System
- Collision behavior is defined via the `ICollision` interface.
- `CollisionSystem` performs group-to-group collision checks using only the interface contract.
- Entities react to collisions through `onHit()` / `onDamage()` without coupling to detection logic.

(Current implementation uses a simple O(n²) approach, designed to be replaceable with spatial partitioning if needed.)

### Spawning & Lifecycle
- Abstract `Spawner` base class.
- Specialized spawners for asteroids and projectiles.
- Spawners control creation timing and entity initialization.
- Entities signal removal; scenes clean up centrally after updates.

### Utilities
- `VectorUtility` — vector math helpers
- `Cooldown` — reusable timing logic
- `PrintDebug` — isolated debug output

## Project Goals
- Practice clean separation of responsibilities
- Avoid tightly coupled gameplay logic
- Use interfaces where behavior should remain flexible
- Build systems that can be extended without rewriting existing code

## Build & Run (Windows)
1. Open the Visual Studio project.
2. Select Debug or Release configuration.
3. Build and run using `F5` or `Ctrl + F5`.

## Possible Improvements
- Introduce spatial partitioning for collision optimization
- Add automated tests for core systems (cooldowns, collisions)
