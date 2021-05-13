# About
H3API is a series of header and source files created from reverse engineering the Heroes of Might and Magic III executable version 3.2; with this library you can create plugins for the game such as [these](https://github.com/RoseKavalier/H3Plugins). See [H3API.hpp](https://github.com/RoseKavalier/H3API/blob/master/include/H3API.hpp) for a list of all sources that were consulted in the creation of the library.

# Header Only
H3API can be used as a header-only library. For this you only need to include the singler header file into your project. See the `single_header` directory for more information.
```
e.g.
#include "<relative path>/single_header/H3API.hpp"
#include "externals/h3api/single_header/H3API.hpp"
```

# Static Library
H3API may also be compiled as a static library to speed up compilation of your projects. There is no special preprocessor definition required, you need only include the main include directory and header file to your project as well as link the `H3API.lib` binary to your project.
```
#include <H3API.hpp> // link <relative path>/H3API/include/
```

# Building
CMakeLists are provided to create generators. It is very basic and I've only tested creation of *.sln files for Visual Studio.

x86 platform is now set within CMakeLists as heroes3 depends on it and many structures require precise size and alignment which are verified through static assertions.
```
mkdir build
cd build
cmake ..
cmake -- build .. --config Release
```
To specify which generator to use do something like `cmake -G "Visual Studio 15 2017"`. See [CMake documentation](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#visual-studio-generators) for more information.

# Compatibility
H3API was successfully compiled as a static library with the following:
- Visual Studio 2008
- Visual Studio 2013
- Visual Studio 2015
- Visual Studio 2017
- Visual Studio 2019

# C++11
It is highly suggested to use a fully C++11 capable IDE (e.g. VS 2015+) for better optimizations and access to more features from H3API.

# Contributions
You are welcome to suggest modifications, improvements, corrections and whatnot to H3API. It is requested that you document your contributions with addresses, examples or other relevant information so that some verifications may be done before integrating within the library.

While there isn't a super strict standard enforced, there is an attempt to have a more or less uniform appearance.

There had been no clear decision up until now on these regulations; it will be some time before the library reflects them fully.

Use of any C++11 feature should be enclosed within `_H3API_CPLUSPLUS11_` guards, with suitable alternative provided if possible.

## Namespaces
* global namespace `h3` is required everywhere.
* second-level namespaces will generally indicate a group of similar functions, classes or such
* NH3 prefixed namespaces are only for storing constants
## Types
* Data types should follow ALLCAPS style as defined in *H3Types.hpp*
  * e.g. `INT`, `CHAR`, `BOOL8`
* there are four exceptions to this rule:
  * `h3unk` family which indicates unknown regions of a h3 structure
  * `h3align` which indicates padding within a structure
  * `h3func` which indicates the presence of a function within h3
  * `bool` which is needed for some function signatures
* Slight preference for bit-capacity to be included for clarity `INT32` vs `INT`
* use of `auto` is not accepted within H3API as there is no pre C++11 equivalent
* `references&` are preferred to `pointers*`; pointers are fine if the original data type is (likely) a pointer
* `const refererence&` is also preferred where possible
## Comments
* comments follow `/** ... */` [Doxygen](https://www.doxygen.nl/manual/docblocks.html) style
  * functions will have a brief description, including parameter details
  * struct and class will have a brief description
  * struct members will be commented before their definition `/** @brief ... */`
    struct members should have their relative offset clearly stated within []
  * trivial member functions shall not be commented (e.g. con/destructor/Get/Set) unless clarification is needed
* some important comments are left in as `/* ... */` without Doxygen style
* non-essential or implementation comments use the `//` format, they are removed for the single header format
## struct
* Any data object interacting directly with code from Heroes3 is a **struct** not class
  * `H3` prefix is required, followed by PascalCase notation
    * e.g. `struct H3Structure`
  * Structures defined within other structures need not have `H3` prefix
  * iterators should follow std::iterator format
    * e.g. `H3Structure::iterator` or `H3Structure::const_iterator`
  * Data members should clearly indicate what they mean as their access should be public and be camelCase
    * In the case of data members that should preferably not be available to user, prefix `m_` is encouraged (e.g. H3String, H3Vector)
      * You may want to provide `Get()` and/or `Set()` access methods for these
    * Unknown data members or likely irrelevant are marked **protected**
    * Unknown data members are prefixed with `_f_` (field) and indicate their offset within the structure
      * e.g. `_f_42`
  * In the case of alignment members, they should clearly be marked with type `h3align`
  * Member functions should be CamelCase and have the `_H3API_` macro at their heads (unless template function)
    * e.g. `_H3API_ INT MemberFunction()`
  * Member functions that return iterators should follow `std::` naming format
    * e.g. `begin()` & `end()`
  * Non-public member functions should be camelCase to distinguish them
    * e.g. `_H3API_ INT privateMemberFunction()`
## class
* Custom data objects should be marked as **class**, not struct
* data members should not be public
* otherwise, `struct` rules apply
  * e.g. `class H3Ini`
## Bitfields
* H3 uses quite a few bitfields/bitsets to save on memory, use `H3Bitset` when possible and H3Bitfield otherwise
* otherwise, bitfield members should be camelCase as struct members and `unsigned :` unless the type is clearly a signed value
## Variables
* Absolutely no globals are allowed
* local variables and functions parameters should follow snake_case
  * e.g. `local_variable`
## Macros
* Macros are reserved for two purposes only:
  * defining access to memory data or objects
  * library maintenance
* Macros should begin with the prefix `P_` and follow PascalCase and are restricted to the `H3Defines` submodule
  * All non-primitive data macros should use `H3DataPointer` or `H3DataArrayPointer`
    * primitive refers to any data type that is not object-oriented
  * All primitive data macros should use `H3PrimitivePointer` or `H3PrimitiveArrayPointer`
  * `_H3API_` prefix is reserved for library maintenance
## Functions
* Standalone Functions are being deprecated for the most part, with only a few remaining.
  * `_H3API_` prefix is required, it allows inline or compilation dual state between single header and library
    * e.g. `_H3API_ INT atoi()`
* Standard C library functions using h3 assets are now housed in namespace `libc`
## Constants
* All constants and enums are stored in the `H3Constants` submodule. Classes get typedefs of the relevant types
* non-enum constants should be marked as `constexpr` (reduces to `const` without C++11)
* char* type should be explicitly written as `LPCSTR const` to avoid duplicate definitions
* Dialog-specific constants/ids will be reorganized in the future
## Enums
* enum name should be prefixed with `e` and follow PascalCase. Specifying expected type is a plus.
  * e.g. `enum eObject : INT32`
* ALL_CAPS format is sought on its members and the expected value should be explicitly written
  * e.g. `CARTOGRAPHER = 13,`
* enums are essentially weakly typed, but to add some safety each enum is contained in a namespace of its own, with an exposed typedef created outside of that namespace. This more or less forces the use of `eEnumType::VALUE` and allows each constant unit to have multiple enum members with the same name.
  * e.g. `eArtifact::NONE` & `eArtifactSlot::NONE`
* enum class should use `_H3API_ENUM_` macro for compatibility

# Contributors
People who have sent in fixes to the api but are not directly shown for various reasons:

[@igrikRS](https://github.com/igrikRS)<br>
[@thehlopster](https://github.com/thehlopster)

# Disclaimer

This software is not in any way official and is not endorsed by anyone.
Heroes, Might and Magic, Heroes of Might and Magic, Ubisoft and the Ubisoft logo are trademarks of Ubisoft Entertainment in the U.S. and/or other countries.
