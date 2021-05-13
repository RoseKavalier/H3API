This is an overview of the contents of H3API, which are now better sorted into sections. This makes it way simpler to find relevant information and continue development without fear of cluttering files too much (I'm looking at you, H3Structures).

As such, each `.hpp` file with a corresponding `directory` corresponds to a `submodule` which houses all defined structures that are relevant to the current topic. Each `.hpp + .cpp` combination within a submodule is referred to as a `unit`.
```
+---<submodule1>
    |- unit1.cpp
    |- unit1.hpp
    |- unit2.cpp
    |- unit2.hpp
    |- unit3.cpp
    |- unit3.hpp
+---<submodule2>
    |- unit1.cpp
    |- unit1.hpp
    |- unit2.cpp
    |- unit2.hpp
+---submodule1.hpp
+---submodule2.hpp
```

### AdventureMap
Adventure map contains all objects that appear on it as well as structures that are strictly used on the adventure map, e.g. `Tilevision`

### AI
Artificial Intelligence houses all data relevant to computer opponents, including simulated combat and pathfinder which controls pathfinding on the adventure map and in combat.

### Artifacts
Artifacts, combination artifacts and details about artifacts.

### Assets
Known as binary items in WoG, these are all the data structures that are held by ResourceManager, as well as some named variants of assets with details on how they are stored in memory, e.g. `QuestsText`

### Base
Allocator, library Configuration, Bitfields and a few functions.

### Campaign
Campaign options, configuration and data.

### Combat
Everything related to combat featuring at least one human. `CombatManager` is in submodule `Managers`

### Constants
All enums and constants are housed here.

### Containers
Equivalent `std::` containers: vector, string, bitset, set

### Creatures
General information about creatures, and the creature array known as `Army`

### Defines
Houses all data and primitive pointers. In the case of primitive pointers, static structures are defined here.

### DialogControls
All controls that are used by h3 windows (DialogItems) as well as any custom controls to be added.

### Dialogs
All h3 windows (Dialogs). From debug information, it seems likely that NWC used the term `Window` for these types.

### GameData
Everything related to the current game/map being played that is not really visible to the player.

### GzWrapper
NWC created specific types to handle creation of map and save files, which are essentially wrappers around the `zlib` library. The names can be deducted from debug information.

### Heroes
The hero structure is handled quite uniquely on the adventure map and has many related data, such as specialty.

### Managers
Several structures are derived from the `base_manager` type, and are more or less all active together. All such derived structures are housed here e.g. CombatManager, SoundManager, RecruitManager

### Players
Data specifically related to each player on the map.

### RMG
Types used in the creation of random maps. Several names are deducted from the mapeditor.

### Skills
Primary and secondary skills information, as well as secondary-skill specific functions housed in static classes.

### Towns
Similar to the hero structure, towns are handled quite specifically and contain a significant number of related classes.

### Utilities
Helper classes for your plugins. These are essentially *not found* within the game but can be used in place of writing everything on your own.
* The `H3Random` unit does have a few game-related structures but I'd advise against using h3's native random number generator unless you're certain of what you're trying to accomplish.
* In this case, the `H3Random::SeedRestore` class is useful in restoring the current seed after you have completed your operations.

#### PreprocessorCleanup
Removes all non-essential macros used in the library. If you happen to use the `_H3API_DONT_USE_MACROS_` preprocessor, then all macros are essentially removed.