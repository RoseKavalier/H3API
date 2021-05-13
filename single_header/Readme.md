**Note**
>The library is now stored within `namespace h3` to help in preventing conflicts. If you do not wish to type `h3::` every time you use H3API, add the `using namespace h3;` line to your code.

## Single header

This header file is self-contained to use H3API within your projects. There is no need to define anything else, however you may like to use some of the additional options available through preprocessor definitions. Note that there are significantly fewer comments in this version, all `//` comments have been stripped to reduce file size. To view these comments, refer to the library version of the api.

## WARNING

No pull requests, modifications, contributions or anything will be accepted related to this unit. This single header is generated using [Quom](https://github.com/Viatorus/quom) and will not be maintained in any other way. **The only tolerated issues** are directly related to **bugs that occur during generation**.

## H3API Preprocessor Definitions Overview
---
To use these options, either add these preprocessor definitions to your project's preprocessor definitions, or `#define` them prior to including H3API.

|      Preprocessor option     	| Description                                     	|
|:----------------------------:	|-------------------------------------------------	|
|   \_H3API\_STD\_CONVERSIONS\_   	| allows conversion between the following formats<br>`std::string <<==>> h3::H3String`<br>`std::vector <<==>> h3::H3Vector` |
|   \_H3API\_STD\_VECTOR\_   	| allows use of H3StdVector<>, inherited from std::vector<> with H3ObjectAllocator<><br>uses conditional padding to match H3Vector format |
|     \_H3API\_EXCEPTION\_     	| tells the library to include the H3Exception exception handler within your project<br>which is derived from std::exception and may catch SEH errors.<br>your project needs to use /EHa compiler flag to use it. |
| \_H3API\_UNPREFIXED\_NAMES\_ | most types created by H3API get a typedef without the `H3` prefix<br>e.g. `H3String` has an equivalent `String` which may be more convenient. |
| \_H3API\_DONT\_USE\_MACROS\_ 	| tells the library to exclude some macros that can pollute the global namespace when defined.<br>these macros are then replaced by typedefs so extra parentheses may be required.<br>if you would like the convenience of switching between both modes, always add parentheses at the end. |
|   \_H3API\_NO\_VALIDATION\_  	| there are compile-time asserts in H3API to verify<br>structures' sizes and validate some template parameters.<br>define this macro if you do not wish to perform these validations. |
|    \_H3API\_PATCHER\_X86\_   	| tells the library to include its own "patcher_x86.hpp" header within your project<br>don't use this if you prefer having your own patcher_x86 header. |
|      \_H3API\_PLUGINS\_      	| tells the library to include the necessary headers to interact with H3Plugins projects<br>in most cases you won't need this. |