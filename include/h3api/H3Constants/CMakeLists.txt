target_sources(H3API PRIVATE
)

target_sources(H3API PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstArtifact.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstAssets.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstCampaigns.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstCombat.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstCreatures.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstDlg.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstDlgControls.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstExperienceLevels.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstHeroes.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstMapEditor.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstMessages.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstMouseCursor.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstNetwork.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstObjects.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstPlayers.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstQuest.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstReplayActions.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstResources.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstSkills.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstSpells.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstTerrain.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstTowns.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstVictoryLoss.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CstVKey.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Limits.hpp"
)