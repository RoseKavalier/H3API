target_sources(H3API PRIVATE
)

target_sources(H3API PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/H3DataArrayPointers.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3DataPointers.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3PrimitiveArrayPointers.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3PrimitivePointers.hpp"
)