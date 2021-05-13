H3API 1.1.0 has removed the following deprecated functions from version 1.0.0

| Deprecated | Replacement |
|---|----|
|H3Error::_ShowError | H3Error::ShowErrorW |
|H3Error::_ShowErrorChoice | H3Error::ShowErrorChoiceW |
|H3ColumnTextFile |H3TextFile* |
|H3TextFile* | H3TextTable|
|H3BinTreeList |H3ResourceManager |
|H3BinaryTreeNode | H3ResourceManagerNode|
|H3BinaryItem |H3ResourceItem |
|H3LoadedPCX |H3LoadedPcx |
|H3LoadedPCX16 | H3LoadedPcx16|
|H3LoadedPCX24 |H3LoadedPcx24 |
|H3LoadedDEF | H3LoadedDef|
| BinaryLoader|H3BinaryLoader |
| DefLoader| H3DefLoader|
| PcxLoader| H3PcxLoader|
| Pcx16Loader| H3Pcx16Loader|
| FontLoader| H3FontLoader |
| H3ResourceItem::InitiateBinary| H3ResourceItem::InitiateResource|
| H3ResourceItem::AddToBinaryTree| H3ResourceItem::AddToResourceManager|
| H3LoadedPcx::DrawHue|H3LoadedPcx::AdjustHueSaturation |
|h3_MagicSchoolName|P_SpellbookText|
|h3_PrimarySkillName|P_PrimarySkillName|
|h3_ObjectName|P_ObjectName|
|h3_MineNames|P_MineNames|
|h3_TentColors|P_TentColors|
|h3_CastleName|P_CastleName|
|h3_TerrainName|P_TerrainName|
|h3_ResourceName|P_ResourceName|
|h3_RandomSignText|P_RandomSignText|
|h3_PlayerColor|P_PlayerColor|
|h3_DwellingNames1|P_DwellingNames1|
|h3_DwellingNames4|P_DwellingNames4|
|h3_SpecialBuildingCosts|P_SpecialBuildingCosts|
|h3_DwellingBuildingCosts|P_DwellingBuildingCosts|
|h3_SecondarySkillsInfo|P_SecondarySkillsInfo|
|h3_DataPath|P_DataPath|
|h3_ActivePlayer|P_ActivePlayer|
|h3_HWND|P_HWND|
|h3_ArtifactCount|P_ArtifactCount|
|h3_CreatureCount|P_CreatureCount|
|h3_HeroCount|P_HeroCount|
|h3_TownCount|P_TownCount|
|h3_SpellCount|P_SpellCount|
|gameWidth|P_GameWidth|
|gameHeight|P_GameHeight|
|gameMaxWidth|P_TextDlgMaxWidth|
|gameMaxHeight|P_TextDlgMaxHeight|
|h3_CurrentPlayerID|P_CurrentPlayerID|
|h3_CurrentAnimationSpeed|P_CurrentAnimationSpeed|
|h3_IsCampaignGame|P_IsCampaignGame|
|h3_AnimationSpeed|P_AnimationSpeed|
|h3_BattleShadowHexes|P_BattleShadowHexes|
|h3_Instance|P_Instance|
|SPEED_BONUS_BOOTS|P_BootsOfSpeedBonus|
|SPEED_BONUS_GLOVES|P_EquestriansGlovesBonus|
|WATER_BONUS_NECKLACE|P_NecklaceOceanGuidanceBonus|
|WATER_BONUS_SEA_CAPTAIN|P_SeaCaptainsHatBonus|
|SPEED_BONUS_STABLES|P_StablesBonus|
|WATER_BONUS_LIGHTHOUSE|P_LighthouseBonus|
|h3_HeroRetreated|P_HeroRetreated|
|h3_HeroSurrendered|P_HeroSurrendered|
|h3_AutoSolo|P_AutoSolo|
|h3_HumanID|P_HumanID|
|h3_ActivePlayerBitset|P_ActivePlayerBitset|
|h3_ColorMode|P_GreenMask|
|h3_QuestsText|P_QuestsText|
|h3_SeersText|P_SeersText|
|h3_TownDependencies|P_TownDependencies|
|P_BinaryTree|P_ResourceManager|
|C_ButtonWav|P_ButtonWav|
|F_MultiByteToWideChar |F_utf8ToUnicode or F_AnsiToUnicode |
| H3StreamBuf| H3ZStream|
|H3CreatureFlags::EXTENDED |H3CreatureFlags::EXTENDED_ATTACK|
|H3CreatureFlags::DESTROYWALLS |H3CreatureFlags::DESTROY_WALLS|
|H3CreatureFlags::SIEGEWEAPON |H3CreatureFlags::SIEGE_WEAPON|
|H3CreatureFlags::MINDIMMUNITY |H3CreatureFlags::MIND_IMMUNITY|
|H3CreatureFlags::NOOBSTACLEPENALTY |H3CreatureFlags::NO_OBSTACLE_PENALTY|
|H3CreatureFlags::NOMELEEPENALTY |H3CreatureFlags::NO_MELEE_PENALTY|
|H3CreatureFlags::FIREIMMUNITY |H3CreatureFlags::FIRE_IMMUNITY|
|H3CreatureFlags::DOUBLEATTACK |H3CreatureFlags::DOUBLE_ATTACK|
|H3CreatureFlags::NORETALIATION |H3CreatureFlags::NO_RETALIATION|
|H3CreatureFlags::NOMORALE |H3CreatureFlags::NO_MORALE|
|H3CreatureFlags::ATTACKALLAROUND |H3CreatureFlags::ATTACK_ALL_AROUND|
|H3CreatureFlags::CANNOTMOVE |H3CreatureFlags::CANNOT_MOVE|
|H3CreatureFlags::NOCOLORING |H3CreatureFlags::NO_COLORING|
|HookContext::_retn |HookContext::Retn |
| HookContext::_retn2| **no replacement** |
| HookContext::_retn3| **no replacement** |
| HookContext::arg_n| HookContext::Arg or HookContext::Arg<T> |
| HookContext::local_n| HookContext::Local or HookContext::Local<>|
| HookContext::local_stack| HookContext::LocalStack |

*H3ColumnTextFile was renamed H3TextFile while the old H3TextFile was appropriately renamed H3TextTable.