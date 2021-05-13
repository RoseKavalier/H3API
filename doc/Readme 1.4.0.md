H3API 1.4.0 has removed the following deprecated functions from version 1.3.X

| Deprecated | Replacement |
|---|----|
| \_H3\_STD\_CONVERSIONS\_ | \_H3API\_STD\_CONVERSIONS\_ |
| \_NAKED\_FUNCTION\_ | \_H3API\_NAKED\_FUNCTION\_ |
| H3Msg::MC_KeyDown | H3Msg::MC_KEY_DOWN |
| H3Msg::MC_KeyUp | H3Msg::MC_KEY_UP |
| H3Msg::MC_MouseOver | H3Msg::MC_MOUSE_OVER |
| H3Msg::MC_LClickOutside | H3Msg::MC_LCLICK_OUTSIDE |
| H3Msg::MC_RClickOutside | H3Msg::MC_RCLICK_OUTSIDE |
| H3Msg::MC_KeyHeld | H3Msg::MC_KEY_HELD |
| H3Msg::MC_MouseButton | H3Msg::MC_MOUSE_BUTTON |
| H3Msg::MC_WheelButton | H3Msg::MC_WHEEL_BUTTON |
| H3Msg::MC_MouseWheel | H3Msg::MC_MOUSE_WHEEL |
| H3Msg::MS_EndDialog | H3Msg::MS_END_DIALOG |
| H3Msg::MS_LButtonDown | H3Msg::MS_LBUTTON_DOWN |
| H3Msg::MS_LButtonClick | H3Msg::MS_LBUTTON_CLICK |
| H3Msg::MS_RButtonDown | H3Msg::MS_RBUTTON_DOWN |
| H3Msg::MS_MouseWheelButtonDown | H3Msg::MS_MOUSE_WHEEL_BUTTON_DOWN |
| H3Msg::MS_MouseWheelButtonUp | H3Msg::MS_MOUSE_WHEEL_BUTTON_UP |
| H3Msg::MF_Shift | H3Msg::MF_SHIFT |
| H3Msg::MF_Ctrl | H3Msg::MF_CTRL |
| H3Msg::MF_Alt | H3Msg::MF_ALT |
| H3LodItem::size_compressed | H3LodItem::sizeCompressed |
| H3Patcher::mnemonics::inc_eax | H3Patcher::mnemonics::INC_EAX    |
| H3Patcher::mnemonics::inc_ecx | H3Patcher::mnemonics::INC_ECX    |
| H3Patcher::mnemonics::inc_edx | H3Patcher::mnemonics::INC_EDX    |
| H3Patcher::mnemonics::inc_ebx | H3Patcher::mnemonics::INC_EBX    |
| H3Patcher::mnemonics::inc_esp | H3Patcher::mnemonics::INC_ESP    |
| H3Patcher::mnemonics::inc_ebp | H3Patcher::mnemonics::INC_EBP    |
| H3Patcher::mnemonics::inc_esi | H3Patcher::mnemonics::INC_ESI    |
| H3Patcher::mnemonics::inc_edi | H3Patcher::mnemonics::INC_EDI    |
| H3Patcher::mnemonics::dec_eax | H3Patcher::mnemonics::DEC_EAX    |
| H3Patcher::mnemonics::dec_ecx | H3Patcher::mnemonics::DEC_ECX    |
| H3Patcher::mnemonics::dec_edx | H3Patcher::mnemonics::DEC_EDX    |
| H3Patcher::mnemonics::dec_ebx | H3Patcher::mnemonics::DEC_EBX    |
| H3Patcher::mnemonics::dec_esp | H3Patcher::mnemonics::DEC_ESP    |
| H3Patcher::mnemonics::dec_ebp | H3Patcher::mnemonics::DEC_EBP    |
| H3Patcher::mnemonics::dec_esi | H3Patcher::mnemonics::DEC_ESI    |
| H3Patcher::mnemonics::dec_edi | H3Patcher::mnemonics::DEC_EDI    |
| H3Patcher::mnemonics::push_eax | H3Patcher::mnemonics::PUSH_EAX   |
| H3Patcher::mnemonics::push_ecx | H3Patcher::mnemonics::PUSH_ECX   |
| H3Patcher::mnemonics::push_edx | H3Patcher::mnemonics::PUSH_EDX   |
| H3Patcher::mnemonics::push_ebx | H3Patcher::mnemonics::PUSH_EBX   |
| H3Patcher::mnemonics::push_esp | H3Patcher::mnemonics::PUSH_ESP   |
| H3Patcher::mnemonics::push_ebp | H3Patcher::mnemonics::PUSH_EBP   |
| H3Patcher::mnemonics::push_esi | H3Patcher::mnemonics::PUSH_ESI   |
| H3Patcher::mnemonics::push_edi | H3Patcher::mnemonics::PUSH_EDI   |
| H3Patcher::mnemonics::pop_eax | H3Patcher::mnemonics::POP_EAX    |
| H3Patcher::mnemonics::pop_ecx | H3Patcher::mnemonics::POP_ECX    |
| H3Patcher::mnemonics::pop_edx | H3Patcher::mnemonics::POP_EDX    |
| H3Patcher::mnemonics::pop_ebx | H3Patcher::mnemonics::POP_EBX    |
| H3Patcher::mnemonics::pop_esp | H3Patcher::mnemonics::POP_ESP    |
| H3Patcher::mnemonics::pop_ebp | H3Patcher::mnemonics::POP_EBP    |
| H3Patcher::mnemonics::pop_esi | H3Patcher::mnemonics::POP_ESI    |
| H3Patcher::mnemonics::pop_edi | H3Patcher::mnemonics::POP_EDI    |
| H3Patcher::mnemonics::pushad | H3Patcher::mnemonics::PUSHAD     |
| H3Patcher::mnemonics::popad | H3Patcher::mnemonics::POPAD      |
| H3Patcher::mnemonics::push_dword | H3Patcher::mnemonics::PUSH_DWORD |
| H3Patcher::mnemonics::push_byte | H3Patcher::mnemonics::PUSH_BYTE  |
| H3Patcher::mnemonics::short_jo | H3Patcher::mnemonics::SHORT_JO   |
| H3Patcher::mnemonics::short_jno | H3Patcher::mnemonics::SHORT_JNO  |
| H3Patcher::mnemonics::short_jb | H3Patcher::mnemonics::SHORT_JB   |
| H3Patcher::mnemonics::short_jnb | H3Patcher::mnemonics::SHORT_JNB  |
| H3Patcher::mnemonics::short_jz | H3Patcher::mnemonics::SHORT_JZ   |
| H3Patcher::mnemonics::short_jnz | H3Patcher::mnemonics::SHORT_JNZ  |
| H3Patcher::mnemonics::short_jna | H3Patcher::mnemonics::SHORT_JNA  |
| H3Patcher::mnemonics::short_ja | H3Patcher::mnemonics::SHORT_JA   |
| H3Patcher::mnemonics::short_js | H3Patcher::mnemonics::SHORT_JS   |
| H3Patcher::mnemonics::short_jns | H3Patcher::mnemonics::SHORT_JNS  |
| H3Patcher::mnemonics::short_jp | H3Patcher::mnemonics::SHORT_JP   |
| H3Patcher::mnemonics::short_jnp | H3Patcher::mnemonics::SHORT_JNP  |
| H3Patcher::mnemonics::short_jl | H3Patcher::mnemonics::SHORT_JL   |
| H3Patcher::mnemonics::short_jge | H3Patcher::mnemonics::SHORT_JGE  |
| H3Patcher::mnemonics::short_jng | H3Patcher::mnemonics::SHORT_JNG  |
| H3Patcher::mnemonics::short_jg | H3Patcher::mnemonics::SHORT_JG   |
| H3Patcher::mnemonics::nop | H3Patcher::mnemonics::NOP        |
| H3Patcher::mnemonics::pushfd | H3Patcher::mnemonics::PUSHFD     |
| H3Patcher::mnemonics::popfd | H3Patcher::mnemonics::POPFD      |
| H3Patcher::mnemonics::call | H3Patcher::mnemonics::CALL       |
| H3Patcher::mnemonics::jmp | H3Patcher::mnemonics::JMP        |
| H3Patcher::mnemonics::short_jmp | H3Patcher::mnemonics::SHORT_JMP  |
| H3Patcher::mnemonics::_retn_ | H3Patcher::mnemonics::_RETN_     |
| H3Patcher::mnemonics::_retnX_ | H3Patcher::mnemonics::_RETNX_    |
| H3Patcher::mnemonics::far_jo | H3Patcher::mnemonics::FAR_JO     |
| H3Patcher::mnemonics::far_jno | H3Patcher::mnemonics::FAR_JNO    |
| H3Patcher::mnemonics::far_jb | H3Patcher::mnemonics::FAR_JB     |
| H3Patcher::mnemonics::far_jnb | H3Patcher::mnemonics::FAR_JNB    |
| H3Patcher::mnemonics::far_jz | H3Patcher::mnemonics::FAR_JZ     |
| H3Patcher::mnemonics::far_jnz | H3Patcher::mnemonics::FAR_JNZ    |
| H3Patcher::mnemonics::far_jna | H3Patcher::mnemonics::FAR_JNA    |
| H3Patcher::mnemonics::far_ja | H3Patcher::mnemonics::FAR_JA     |
| H3Patcher::mnemonics::far_js | H3Patcher::mnemonics::FAR_JS     |
| H3Patcher::mnemonics::far_jns | H3Patcher::mnemonics::FAR_JNS    |
| H3Patcher::mnemonics::far_jp | H3Patcher::mnemonics::FAR_JP     |
| H3Patcher::mnemonics::far_jnp | H3Patcher::mnemonics::FAR_JNP    |
| H3Patcher::mnemonics::far_jl | H3Patcher::mnemonics::FAR_JL     |
| H3Patcher::mnemonics::far_jnl | H3Patcher::mnemonics::FAR_JNL    |
| H3Patcher::mnemonics::far_jng | H3Patcher::mnemonics::FAR_JNG    |
| H3Patcher::mnemonics::far_jg | H3Patcher::mnemonics::FAR_JG     |
| H3Patcher::mnemonics::call_dword | H3Patcher::mnemonics::CALL_DWORD |
| H3QuickBattleCreatures | H3FastBattleCreature |
| H3AIQuickBattle | H3AiFastBattle |
| _H3API_DEPRECATED_ | no replacement |
| H3SmartPointer | H3AutoPtr |
| H3NetworkData::recipient_id | H3NetworkData::recipientId |
| H3NetworkData::msg_id | H3NetworkData::msgId |
| H3NetworkData::buffer_size | H3NetworkData::bufferSize |
| H3NetworkData::short_data | H3NetworkData::shortData |
| H3HeroFlags::swan_pond | H3HeroFlags::swanPond |
| H3HeroFlags::idol_fortune_morale | H3HeroFlags::idolFortuneMorale |
| H3HeroFlags::fountain_fortune1 | H3HeroFlags::fountainFortune1 |
| H3HeroFlags::watering_hole | H3HeroFlags::wateringHole |
| H3HeroFlags::derelect_ship | H3HeroFlags::derelectShip |
| H3HeroFlags::faerie_ring | H3HeroFlags::faerieRing |
| H3HeroFlags::fountain_of_youth | H3HeroFlags::fountainOfYouth |
| H3HeroFlags::rally_flag | H3HeroFlags::rallyFlag |
| H3HeroFlags::in_tavern | H3HeroFlags::inTavern |
| H3HeroFlags::in_boat | H3HeroFlags::inBoat |
| H3HeroFlags::warrior_tomb | H3HeroFlags::warriorTomb |
| H3HeroFlags::luck_cheat | H3HeroFlags::luckCheat |
| H3HeroFlags::morale_cheat | H3HeroFlags::moraleCheat |
| H3HeroFlags::speed_cheat | H3HeroFlags::speedCheat |
| H3HeroFlags::idol_fortune_luck | H3HeroFlags::idolFortuneLuck |
| H3HeroFlags::fountain_fortune2 | H3HeroFlags::fountainFortune2 |
| H3HeroFlags::fountain_fortune3 | H3HeroFlags::fountainFortune3 |
| H3HeroFlags::fountain_fortune4 | H3HeroFlags::fountainFortune4 |
| H3Hero::gender | H3Hero::isFemale |
| H3Hero::learned_spell | H3Hero::learnedSpells |
| H3Hero::available_spell | H3Hero::availableSpells |
| H3Hero::AI_aggressiveness | H3Hero::aiAggressiveness |
| H3Hero::AI_spellPowerEffectiveness | H3Hero::aiSpellPowerEffectiveness |
| H3Hero::AI_spellLengthEffectiveness | H3Hero::aiSpellLengthEffectiveness |
| H3Hero::AI_extraKnowledgeEffectiveness | H3Hero::aiKnowledgeEffectiveness |
| H3Hero::AI_doubleSpellPointsEffectiveness | H3Hero::aiDoubleSpellPointsEffectiveness |
| H3Hero::AI_extraSpellPointsEffectiveness | H3Hero::aiExtraSpellPointsEffectiveness |
| H3Player::hasHeroes | H3Player::numberHeroes |
| H3ValidCatapultTargets::fort_element_id | H3ValidCatapultTargets::fortElementId |
| H3Spell::SpellFlags::battlefield_spell| H3Spell::SpellFlags::battlefieldSpell |
| H3Spell::SpellFlags::map_spell| H3Spell::SpellFlags::mapSpell |
| H3Spell::SpellFlags::time_scale| H3Spell::SpellFlags::timeScale |
| H3Spell::SpellFlags::creature_spell| H3Spell::SpellFlags::creatureSpell |
| H3Spell::SpellFlags::single_target| H3Spell::SpellFlags::singleTarget |
| H3Spell::SpellFlags::single_shooting_stack| H3Spell::SpellFlags::singleShootingStack |
| H3Spell::SpellFlags::expert_mass_version| H3Spell::SpellFlags::expertMassVersion |
| H3Spell::SpellFlags::target_anywhere| H3Spell::SpellFlags::targetAnywhere |
| H3Spell::SpellFlags::remove_obstacle| H3Spell::SpellFlags::removeObstacle |
| H3Spell::SpellFlags::damage_spell| H3Spell::SpellFlags::damageSpell |
| H3Spell::SpellFlags::mind_spell| H3Spell::SpellFlags::mindSpell |
| H3Spell::SpellFlags::friendly_mass| H3Spell::SpellFlags::friendlyMass |
| H3Spell::SpellFlags::cannot_target_siege| H3Spell::SpellFlags::cannotTargetSiege |
| H3Spell::SpellFlags::spell_from_artifact| H3Spell::SpellFlags::spellFromArtifact |
| H3Spell::SpellFlags::AI_damage_spells| H3Spell::SpellFlags::aiDamageSpells |
| H3Spell::SpellFlags::AI_area_effect| H3Spell::SpellFlags::aiAreaEffect |
| H3Spell::SpellFlags::AI_mass_damage_spells| H3Spell::SpellFlags::aiMassDamageSpells |
| H3Spell::SpellFlags::AI_non_damage_spells| H3Spell::SpellFlags::aiNonDamageSpells |
| H3Spell::SpellFlags::AI_creatures| H3Spell::SpellFlags::aiCreatures |
| H3Spell::SpellFlags::AI_adventure_map| H3Spell::SpellFlags::aiAdventureMap |
| H3CreatureFlags::DOUBLE_WIDE|H3CreatureFlags::doubleWide |
| H3CreatureFlags::FLYER|H3CreatureFlags::flyer |
| H3CreatureFlags::SHOOTER|H3CreatureFlags::shooter |
| H3CreatureFlags::EXTENDED_ATTACK|H3CreatureFlags::extendedAttack |
| H3CreatureFlags::ALIVE|H3CreatureFlags::alive |
| H3CreatureFlags::DESTROY_WALLS|H3CreatureFlags::destroyWalls |
| H3CreatureFlags::SIEGE_WEAPON|H3CreatureFlags::siegeWeapon |
| H3CreatureFlags::KING1|H3CreatureFlags::king1 |
| H3CreatureFlags::KING2|H3CreatureFlags::king2 |
| H3CreatureFlags::KING3|H3CreatureFlags::king3 |
| H3CreatureFlags::MIND_IMMUNITY|H3CreatureFlags::mindImmunity |
| H3CreatureFlags::NO_OBSTACLE_PENALTY|H3CreatureFlags::noObstaclePenalty |
| H3CreatureFlags::NO_MELEE_PENALTY|H3CreatureFlags::noMeleePenalty |
| H3CreatureFlags::FIRE_IMMUNITY|H3CreatureFlags::fireImmunity |
| H3CreatureFlags::DOUBLE_ATTACK|H3CreatureFlags::doubleAttack |
| H3CreatureFlags::NO_RETALIATION|H3CreatureFlags::noRetaliation |
| H3CreatureFlags::NO_MORALE|H3CreatureFlags::noMorale |
| H3CreatureFlags::UNDEAD|H3CreatureFlags::undead |
| H3CreatureFlags::ATTACK_ALL_AROUND|H3CreatureFlags::attackAllAround |
| H3CreatureFlags::MAGOG|H3CreatureFlags::fireballAttack |
| H3CreatureFlags::CANNOT_MOVE|H3CreatureFlags::cannotMove |
| H3CreatureFlags::SUMMON|H3CreatureFlags::summon |
| H3CreatureFlags::CLONE|H3CreatureFlags::clone |
| H3CreatureFlags::MORALE|H3CreatureFlags::morale |
| H3CreatureFlags::WAITING|H3CreatureFlags::waiting |
| H3CreatureFlags::DONE|H3CreatureFlags::done |
| H3CreatureFlags::DEFENDING|H3CreatureFlags::defending |
| H3CreatureFlags::SACRIFICED|H3CreatureFlags::sacrificed |
| H3CreatureFlags::NO_COLORING|H3CreatureFlags::noColoring |
| H3CreatureFlags::GRAY|H3CreatureFlags::gray |
| H3CreatureFlags::DRAGON|H3CreatureFlags::dragon |
|H3CombatMonsterSpellsData::bless_damage |H3CombatMonsterSpellsData::blessDamage |
|H3CombatMonsterSpellsData::curse_damage |H3CombatMonsterSpellsData::curseDamage |
|H3CombatMonsterSpellsData::anti_magic |H3CombatMonsterSpellsData::antiMagic |
|H3CombatMonsterSpellsData::bloodlust_effect |H3CombatMonsterSpellsData::bloodlustEffect |
|H3CombatMonsterSpellsData::precision_effect |H3CombatMonsterSpellsData::precisionEffect |
|H3CombatMonsterSpellsData::weakness_effect |H3CombatMonsterSpellsData::weaknessEffect |
|H3CombatMonsterSpellsData::stone_skin_effect |H3CombatMonsterSpellsData::stoneSkinEffect |
|H3CombatMonsterSpellsData::prayer_effect |H3CombatMonsterSpellsData::prayerEffect |
|H3CombatMonsterSpellsData::mirth_effect |H3CombatMonsterSpellsData::mirthEffect |
|H3CombatMonsterSpellsData::sorrow_effect |H3CombatMonsterSpellsData::sorrowEffect |
|H3CombatMonsterSpellsData::fortune_effect |H3CombatMonsterSpellsData::fortuneEffect |
|H3CombatMonsterSpellsData::misfortune_effect |H3CombatMonsterSpellsData::misfortuneEffect |
|H3CombatMonsterSpellsData::slayer_type |H3CombatMonsterSpellsData::slayerType |
|H3CombatMonsterSpellsData::counterstrike_effect |H3CombatMonsterSpellsData::counterstrikeEffect |
|H3CombatMonsterSpellsData::blind_effect |H3CombatMonsterSpellsData::blindEffect |
|H3CombatMonsterSpellsData::fire_shield_effect |H3CombatMonsterSpellsData::fireShieldEffect |
|H3CombatMonsterSpellsData::protection_air_effect |H3CombatMonsterSpellsData::protectionAirEffect |
|H3CombatMonsterSpellsData::protection_fire_effect |H3CombatMonsterSpellsData::protectionFireEffect |
|H3CombatMonsterSpellsData::protection_water_effect |H3CombatMonsterSpellsData::protectionWaterEffect |
|H3CombatMonsterSpellsData::protection_earth_effect |H3CombatMonsterSpellsData::protectionEarthEffect |
|H3CombatMonsterSpellsData::shield_effect |H3CombatMonsterSpellsData::shieldEffect |
|H3CombatMonsterSpellsData::air_shield_effect |H3CombatMonsterSpellsData::airShieldEffect |
|H3CombatMonsterSpellsData::forgetfulness_level |H3CombatMonsterSpellsData::forgetfulnessLevel |
|H3CombatMonsterSpellsData::slow_effect |H3CombatMonsterSpellsData::slowEffect |
|H3CombatMonsterSpellsData::haste_effect |H3CombatMonsterSpellsData::hasteEffect |
|H3CombatMonsterSpellsData::disease_attack_effect |H3CombatMonsterSpellsData::diseaseAttackEffect |
|H3CombatMonsterSpellsData::disease_defense_effect |H3CombatMonsterSpellsData::diseaseDefenseEffect |
|H3CombatMonsterSpellsData::faerie_dragon_spell |H3CombatMonsterSpellsData::faerieDragonSpell |
|H3CombatMonsterSpellsData::magic_mirror_effect |H3CombatMonsterSpellsData::magicMirrorEffect |
| H3MainSetup::SubterraneanLevel |H3MainSetup::hasUnderground |
| H3Signpost::HasMess|H3Signpost::hasMessage |
| H3Boat::object_type|H3Boat::objectType |
| H3Boat::object_flag|H3Boat::objectFlag |
| H3Boat::object_setup|H3Boat::objectSetup |
| H3Boat::hero_id|H3Boat::heroId |
| H3Boat::has_hero|H3Boat::hasHero |
| H3MovementManager::DD_access|H3MovementManager::ddAccess |
| H3MovementManager::fly_access|H3MovementManager::flyAccess |
| H3MovementManager::waterwalk_access|H3MovementManager::waterwalkAccess |
| H3MovementManager::waterwalk_level|H3MovementManager::waterwalkLevel |
| H3MovementManager::fly_level|H3MovementManager::flyLevel |
| H3MovementManager::movement_info|H3MovementManager::movementInfo |
| H3InputManager::current_message|H3InputManager::currentMessage |
| H3InputManager::next_message|H3InputManager::nextMessage |
| H3CombatSquare::DeadStackSide|H3CombatSquare::deadStackSide |
| H3CombatSquare::DeadStackIndex|H3CombatSquare::deadStackIndex |
| H3CombatSquare::AvailableForLeftSquare|H3CombatSquare::availableForLeftSquare |
| H3CombatSquare::AvailableForRightSquare|H3CombatSquare::availableForRightSquare |
| TownTowerLoaded::StackNumber|TownTowerLoaded::stackNumber |
| H3CombatManager::creature_at_mouse_pos|H3CombatManager::creatureAtMousePos |
| H3CombatManager::mouse_coord|H3CombatManager::mouseCoord |
| H3CombatManager::attacker_coord|H3CombatManager::attackerCoord |
| H3CombatManager::move_type|H3CombatManager::moveType |
| H3CombatManager::fort_walls_hp|H3CombatManager::fortWallsHp |
| H3CombatManager::fort_walls_alive|H3CombatManager::fortWallsAlive |
| H3CombatManager::RedrawCreatureFrame|H3CombatManager::redrawCreatureFrame |
| H3AdventureManager::ePanel::PHero|H3AdventureManager::ePanel::PHERO |
| H3AdventureManager::ePanel::PTown|H3AdventureManager::ePanel::PTOWN |
| NH3Mouse::H3MouseCursorType::Cursor_Default|NH3Mouse::H3MouseCursorType::CURSOR_DEFAULT |
| NH3Mouse::H3MouseCursorType::Cursor_Adventure |NH3Mouse::H3MouseCursorType::CURSOR_ADVENTURE  |
| NH3Mouse::H3MouseCursorType::Cursor_Combat    |NH3Mouse::H3MouseCursorType::CURSOR_COMBAT|
| NH3Mouse::H3MouseCursorType::Cursor_Spell     |NH3Mouse::H3MouseCursorType::CURSOR_SPELL |
| NH3Mouse::H3MouseCursorType::Cursor_Artifact  |NH3Mouse::H3MouseCursorType::CURSOR_ARTIFACT |
| NH3Mouse::eAdventureMapCursorType::AMC_ArrowPointer| NH3Mouse::eAdventureMapCursorType::AMC_ARROWPOINTER         |
| NH3Mouse::eAdventureMapCursorType::AMC_Busy_Wait| NH3Mouse::eAdventureMapCursorType::AMC_BUSY_WAIT            |
| NH3Mouse::eAdventureMapCursorType::AMC_Hero| NH3Mouse::eAdventureMapCursorType::AMC_HERO                 |
| NH3Mouse::eAdventureMapCursorType::AMC_Town| NH3Mouse::eAdventureMapCursorType::AMC_TOWN                 |
| NH3Mouse::eAdventureMapCursorType::AMC_Horse| NH3Mouse::eAdventureMapCursorType::AMC_HORSE                |
| NH3Mouse::eAdventureMapCursorType::AMC_Attack| NH3Mouse::eAdventureMapCursorType::AMC_ATTACK               |
| NH3Mouse::eAdventureMapCursorType::AMC_Boat| NH3Mouse::eAdventureMapCursorType::AMC_BOAT                 |
| NH3Mouse::eAdventureMapCursorType::AMC_Anchor| NH3Mouse::eAdventureMapCursorType::AMC_ANCHOR               |
| NH3Mouse::eAdventureMapCursorType::AMC_Hero_Meeting| NH3Mouse::eAdventureMapCursorType::AMC_HERO_MEETING         |
| NH3Mouse::eAdventureMapCursorType::AMC_Rearing_Horse| NH3Mouse::eAdventureMapCursorType::AMC_REARING_HORSE        |
| NH3Mouse::eAdventureMapCursorType::AMC_Horse2| NH3Mouse::eAdventureMapCursorType::AMC_HORSE2               |
| NH3Mouse::eAdventureMapCursorType::AMC_Attack2| NH3Mouse::eAdventureMapCursorType::AMC_ATTACK2              |
| NH3Mouse::eAdventureMapCursorType::AMC_Boat2| NH3Mouse::eAdventureMapCursorType::AMC_BOAT2                |
| NH3Mouse::eAdventureMapCursorType::AMC_Anchor2| NH3Mouse::eAdventureMapCursorType::AMC_ANCHOR2              |
| NH3Mouse::eAdventureMapCursorType::AMC_Hero_Meeting2| NH3Mouse::eAdventureMapCursorType::AMC_HERO_MEETING2        |
| NH3Mouse::eAdventureMapCursorType::AMC_Rearing_Horse2| NH3Mouse::eAdventureMapCursorType::AMC_REARING_HORSE2       |
| NH3Mouse::eAdventureMapCursorType::AMC_Horse3| NH3Mouse::eAdventureMapCursorType::AMC_HORSE3               |
| NH3Mouse::eAdventureMapCursorType::AMC_Attack3| NH3Mouse::eAdventureMapCursorType::AMC_ATTACK3              |
| NH3Mouse::eAdventureMapCursorType::AMC_Boat3| NH3Mouse::eAdventureMapCursorType::AMC_BOAT3                |
| NH3Mouse::eAdventureMapCursorType::AMC_Anchor3| NH3Mouse::eAdventureMapCursorType::AMC_ANCHOR3              |
| NH3Mouse::eAdventureMapCursorType::AMC_Hero_Meeting3| NH3Mouse::eAdventureMapCursorType::AMC_HERO_MEETING3        |
| NH3Mouse::eAdventureMapCursorType::AMC_Rearing_Horse3| NH3Mouse::eAdventureMapCursorType::AMC_REARING_HORSE3       |
| NH3Mouse::eAdventureMapCursorType::AMC_Horse4| NH3Mouse::eAdventureMapCursorType::AMC_HORSE4               |
| NH3Mouse::eAdventureMapCursorType::AMC_Attack4| NH3Mouse::eAdventureMapCursorType::AMC_ATTACK4              |
| NH3Mouse::eAdventureMapCursorType::AMC_Boat4| NH3Mouse::eAdventureMapCursorType::AMC_BOAT4                |
| NH3Mouse::eAdventureMapCursorType::AMC_Anchor4| NH3Mouse::eAdventureMapCursorType::AMC_ANCHOR4              |
| NH3Mouse::eAdventureMapCursorType::AMC_Hero_Meeting4| NH3Mouse::eAdventureMapCursorType::AMC_HERO_MEETING4        |
| NH3Mouse::eAdventureMapCursorType::AMC_Rearing_Horse4| NH3Mouse::eAdventureMapCursorType::AMC_REARING_HORSE4       |
| NH3Mouse::eAdventureMapCursorType::AMC_Boat_1| NH3Mouse::eAdventureMapCursorType::AMC_BOAT_1               |
| NH3Mouse::eAdventureMapCursorType::AMC_Boat_2| NH3Mouse::eAdventureMapCursorType::AMC_BOAT_2               |
| NH3Mouse::eAdventureMapCursorType::AMC_Boat_3| NH3Mouse::eAdventureMapCursorType::AMC_BOAT_3               |
| NH3Mouse::eAdventureMapCursorType::AMC_Boat_4| NH3Mouse::eAdventureMapCursorType::AMC_BOAT_4               |
| NH3Mouse::eAdventureMapCursorType::AMC_Map_Scroll_North| NH3Mouse::eAdventureMapCursorType::AMC_MAP_SCROLL_NORTH     |
| NH3Mouse::eAdventureMapCursorType::AMC_Map_Scroll_Northeast| NH3Mouse::eAdventureMapCursorType::AMC_MAP_SCROLL_NORTHEAST |
| NH3Mouse::eAdventureMapCursorType::AMC_Map_Scroll_East| NH3Mouse::eAdventureMapCursorType::AMC_MAP_SCROLL_EAST      |
| NH3Mouse::eAdventureMapCursorType::AMC_Map_Scroll_Southeast| NH3Mouse::eAdventureMapCursorType::AMC_MAP_SCROLL_SOUTHEAST |
| NH3Mouse::eAdventureMapCursorType::AMC_Map_Scroll_South| NH3Mouse::eAdventureMapCursorType::AMC_MAP_SCROLL_SOUTH     |
| NH3Mouse::eAdventureMapCursorType::AMC_Map_Scroll_Southwest| NH3Mouse::eAdventureMapCursorType::AMC_MAP_SCROLL_SOUTHWEST |
| NH3Mouse::eAdventureMapCursorType::AMC_Map_Scroll_West| NH3Mouse::eAdventureMapCursorType::AMC_MAP_SCROLL_WEST      |
| NH3Mouse::eAdventureMapCursorType::AMC_Map_Scroll_Northwest| NH3Mouse::eAdventureMapCursorType::AMC_MAP_SCROLL_NORTHWEST |
| NH3Mouse::eAdventureMapCursorType::AMC_Arrow_Pointer| NH3Mouse::eAdventureMapCursorType::AMC_ARROW_POINTER        |
| NH3Mouse::eAdventureMapCursorType::AMC_Dimension_Door| NH3Mouse::eAdventureMapCursorType::AMC_DIMENSION_DOOR       |
| NH3Mouse::eAdventureMapCursorType::AMC_Scuttle_Boat| NH3Mouse::eAdventureMapCursorType::AMC_SCUTTLE_BOAT         |
| NH3Mouse::eBattleFieldCursorType::BFC_Null            | NH3Mouse::eBattleFieldCursorType::BFC_NULL            |
| NH3Mouse::eBattleFieldCursorType::BFC_Move            | NH3Mouse::eBattleFieldCursorType::BFC_MOVE            |
| NH3Mouse::eBattleFieldCursorType::BFC_Fly             | NH3Mouse::eBattleFieldCursorType::BFC_FLY             |
| NH3Mouse::eBattleFieldCursorType::BFC_Shooting        | NH3Mouse::eBattleFieldCursorType::BFC_SHOOTING        |
| NH3Mouse::eBattleFieldCursorType::BFC_Hero            | NH3Mouse::eBattleFieldCursorType::BFC_HERO            |
| NH3Mouse::eBattleFieldCursorType::BFC_Question_Mark   | NH3Mouse::eBattleFieldCursorType::BFC_QUESTION_MARK   |
| NH3Mouse::eBattleFieldCursorType::BFC_Arrow_Pointer   | NH3Mouse::eBattleFieldCursorType::BFC_ARROW_POINTER   |
| NH3Mouse::eBattleFieldCursorType::BFC_Attack_Northeast| NH3Mouse::eBattleFieldCursorType::BFC_ATTACK_NORTHEAST|
| NH3Mouse::eBattleFieldCursorType::BFC_Attack_East     | NH3Mouse::eBattleFieldCursorType::BFC_ATTACK_EAST     |
| NH3Mouse::eBattleFieldCursorType::BFC_Attack_Southeast| NH3Mouse::eBattleFieldCursorType::BFC_ATTACK_SOUTHEAST|
| NH3Mouse::eBattleFieldCursorType::BFC_Attack_Southwest| NH3Mouse::eBattleFieldCursorType::BFC_ATTACK_SOUTHWEST|
| NH3Mouse::eBattleFieldCursorType::BFC_Attack_West     | NH3Mouse::eBattleFieldCursorType::BFC_ATTACK_WEST     |
| NH3Mouse::eBattleFieldCursorType::BFC_Attack_Northwest| NH3Mouse::eBattleFieldCursorType::BFC_ATTACK_NORTHWEST|
| NH3Mouse::eBattleFieldCursorType::BFC_Attack_North    | NH3Mouse::eBattleFieldCursorType::BFC_ATTACK_NORTH    |
| NH3Mouse::eBattleFieldCursorType::BFC_Attack_South    | NH3Mouse::eBattleFieldCursorType::BFC_ATTACK_SOUTH    |
| NH3Mouse::eBattleFieldCursorType::BFC_Half_Damage     | NH3Mouse::eBattleFieldCursorType::BFC_HALF_DAMAGE     |
| NH3Mouse::eBattleFieldCursorType::BFC_Attack_Wall     | NH3Mouse::eBattleFieldCursorType::BFC_ATTACK_WALL     |
| NH3Mouse::eBattleFieldCursorType::BFC_Heal            | NH3Mouse::eBattleFieldCursorType::BFC_HEAL            |
| NH3Mouse::eBattleFieldCursorType::BFC_Sacrifice       | NH3Mouse::eBattleFieldCursorType::BFC_SACRIFICE       |
| NH3Mouse::eBattleFieldCursorType::BFC_Teleport        | NH3Mouse::eBattleFieldCursorType::BFC_TELEPORT        |
| NH3Quest::eQuestType::QT_None            | NH3Quest::eQuestType::QT_NONE            |
| NH3Quest::eQuestType::QT_ExperienceLevel | NH3Quest::eQuestType::QT_EXPERIENCE_LEVEL|
| NH3Quest::eQuestType::QT_PrimarySkill    | NH3Quest::eQuestType::QT_PRIMARY_SKILL   |
| NH3Quest::eQuestType::QT_DefeatHero      | NH3Quest::eQuestType::QT_DEFEAT_HERO     |
| NH3Quest::eQuestType::QT_DefeatMonster   | NH3Quest::eQuestType::QT_DEFEAT_MONSTER  |
| NH3Quest::eQuestType::QT_BringArtifacts  | NH3Quest::eQuestType::QT_BRING_ARTIFACTS |
| NH3Quest::eQuestType::QT_BringCreatures  | NH3Quest::eQuestType::QT_BRING_CREATURES |
| NH3Quest::eQuestType::QT_BringResources  | NH3Quest::eQuestType::QT_BRING_RESOURCES |
| NH3Quest::eQuestType::QT_BeHero          | NH3Quest::eQuestType::QT_BE_HERO         |
| NH3Quest::eQuestType::QT_BePlayer        | NH3Quest::eQuestType::QT_BE_PLAYER       |
| NH3Quest::eSeerReward::SR_None          | NH3Quest::eSeerReward::SR_NONE           |
| NH3Quest::eSeerReward::SR_Experience    | NH3Quest::eSeerReward::SR_EXPERIENCE     |
| NH3Quest::eSeerReward::SR_SpellPoints   | NH3Quest::eSeerReward::SR_SPELL_POINTS   |
| NH3Quest::eSeerReward::SR_Morale        | NH3Quest::eSeerReward::SR_MORALE         |
| NH3Quest::eSeerReward::SR_Luck          | NH3Quest::eSeerReward::SR_LUCK           |
| NH3Quest::eSeerReward::SR_Resource      | NH3Quest::eSeerReward::SR_RESOURCE       |
| NH3Quest::eSeerReward::SR_PrimarySkill  | NH3Quest::eSeerReward::SR_PRIMARY_SKILL  |
| NH3Quest::eSeerReward::SR_SecondarySkill| NH3Quest::eSeerReward::SR_SECONDARY_SKILL|
| NH3Quest::eSeerReward::SR_Artifact      | NH3Quest::eSeerReward::SR_ARTIFACT       |
| NH3Quest::eSeerReward::SR_Spell         | NH3Quest::eSeerReward::SR_SPELL          |
| NH3Quest::eSeerReward::SR_Creature      | NH3Quest::eSeerReward::SR_CREATURE       |
| NH3Dlg::TextAlignment::eTextAlignment::HLeft       | NH3Dlg::TextAlignment::eTextAlignment::HLEFT        |
| NH3Dlg::TextAlignment::eTextAlignment::HCenter     | NH3Dlg::TextAlignment::eTextAlignment::HCENTER      |
| NH3Dlg::TextAlignment::eTextAlignment::HRight      | NH3Dlg::TextAlignment::eTextAlignment::HRIGHT       |
| NH3Dlg::TextAlignment::eTextAlignment::VTop        | NH3Dlg::TextAlignment::eTextAlignment::VTOP         |
| NH3Dlg::TextAlignment::eTextAlignment::VCenter     | NH3Dlg::TextAlignment::eTextAlignment::VCENTER      |
| NH3Dlg::TextAlignment::eTextAlignment::VBottom     | NH3Dlg::TextAlignment::eTextAlignment::VBOTTOM      |
| NH3Dlg::TextAlignment::eTextAlignment::BottomLeft  | NH3Dlg::TextAlignment::eTextAlignment::BOTTOM_LEFT  |
| NH3Dlg::TextAlignment::eTextAlignment::BottomCenter| NH3Dlg::TextAlignment::eTextAlignment::BOTTOM_CENTER|
| NH3Dlg::TextAlignment::eTextAlignment::BottomRight | NH3Dlg::TextAlignment::eTextAlignment::BOTTOM_RIGHT |
| NH3Dlg::TextAlignment::eTextAlignment::MiddleLeft  | NH3Dlg::TextAlignment::eTextAlignment::MIDDLE_LEFT  |
| NH3Dlg::TextAlignment::eTextAlignment::MiddleCenter| NH3Dlg::TextAlignment::eTextAlignment::MIDDLE_CENTER|
| NH3Dlg::TextAlignment::eTextAlignment::MiddleRight | NH3Dlg::TextAlignment::eTextAlignment::MIDDLE_RIGHT |
| NH3Dlg::TextAlignment::eTextAlignment::TopLeft     | NH3Dlg::TextAlignment::eTextAlignment::TOP_LEFT     |
| NH3Dlg::TextAlignment::eTextAlignment::TopMiddle   | NH3Dlg::TextAlignment::eTextAlignment::TOP_MIDDLE   |
| NH3Dlg::TextAlignment::eTextAlignment::TopRight    | NH3Dlg::TextAlignment::eTextAlignment::TOP_RIGHT    |
