H3API 1.6.0 has made significant changes to library architecture.

All enum prefixes are removed (e.g. `eArtifactSlot::sHEAD` is now `eArtifactSlot::HEAD`)
All random map generation structures have their prefix changed from `RMG_` to `H3Rmg`

The following are marked as deprecated from previous versions.

| Deprecated | Replacement |
|---|----|
| F_AnsiToUnicode | H3Encoding::AnsiToUnicode or H3String/H3WString |
| F_utf8ToUnicode | H3Encoding::Utf8ToUnicode or H3String/H3WString |
| F_atof | libc::atof |
| F_atoi | libc::atoi |
| F_Breakpoint | H3Patcher::Breakpoint |
| F_CanViewTile | H3TileVision::CanViewTile |
| F_CloseHandle | H3File::CloseHandle |
| F_CreateFile | H3File::CreateFileA |
| F_CreatureHasUpgrade | H3Creature::HasUpgrade |
| F_fclose | H3Stream::fclose |
| F_fgetpos | H3Stream::fgetpos |
| F_FindClose | H3Path or H3DirectoryTraveler |
| F_FindFirstFileA | H3Path or H3DirectoryTraveler |
| F_FindNextFileA | H3Path or H3DirectoryTraveler |
| F_fopen | H3Stream::fopen |
| F_fputc | H3Stream::fputc |
| F_fread | H3Stream::fread |
| F_fseek | H3Stream::fseek |
| F_fsetpos | H3Stream::fsetpos |
| F_ftell | H3Stream::ftell |
| F_fwrite | H3Stream::fwrite |
| F_GetCreatureUpgrade | H3Creature::GetUpgrade |
| F_GetCurrentDirectory | H3Path::CurrentDirectory |
| F_GetCursorPosition | H3POINT::GetCursorPosition |
| F_GetDiplomacyPowerFactor | H3Diplomacy::GetPowerFactor |
| F_GetFileAttributesA | H3Path::GetAttributes |
| F_GetFileSize | H3Stream::GetFileSize or H3File::GetFileSize |
| F_GetFullPathNameA | H3Path::GetPathName |
| F_GetLocalTime | H3String::GetLocalTime |
| F_GetModuleFileNameA | H3Path::GetModuleFileName |
| F_GetTileVision | H3TileVision::GetTile |
| F_GetTime | GetTime |
| F_GetTownName | P_TownNames or H3TownNames |
| F_memcpy | libc::memcpy |
| F_memset | libc::memset |
| F_MessageBox | H3MessageBox::Show |
| F_MessageBoxChoice | H3MessageBox::Choice |
| F_MessageBoxRMB | H3MessageBox::RMB |
| F_Multiplayer | H3Network::Multiplayer |
| F_MultiplayerRNG | H3Random::MultiplayerRNG |
| F_PrintScreenText | H3Screenchat::Show |
| F_ReadFile | H3File::ReadFile |
| F_ReveaTile | H3TileVision::RevealTile |
| F_SetCurrentDirectory | H3DirectoryChanger |
| F_SetFilePointer | H3File::SetFilePointer |
| F_SingleTargetSpell | H3Spell::SingleTarget |
| F_sprintf | libc::sprintf |
| F_sprintfBuffer | libc::sprintf |
| F_strcmpi | libc::strcmpi |
| F_strncpy | libc::strncpy |
| F_strnicmp | libc::strnicmp |
| F_strRev | libc::strrev |
| F_strtok | libc::strtok |
| F_strtol | libc::strtol |
| F_strtoul | libc::strtoul |
| F_vsprintf | libc::vsprintf |
| F_wcslen | libc::wcslen |
| F_WriteFile | H3File::WriteFile |
| H3DefGroup | H3LoadedDef::DefGroup |
| H3SoundManager::PlaySound | H3SoundManager::Play |
| H3Spell::ai_value | H3Spell::aiValue |
| H3Spell::base_value | H3Spell::baseValue |
| H3Spell::chance_to_get | H3Spell::chanceToGet |
| H3Spell::mana_cost | H3Spell::manaCost |
| H3Spell::sp_effect | H3Spell::spEffect |
| H3Town::manaVortextUnused | H3Town::manaVortexAvailable |