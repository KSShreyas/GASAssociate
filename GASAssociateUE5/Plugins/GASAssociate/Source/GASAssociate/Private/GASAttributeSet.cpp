// Fill out your copyright notice in the Description page of Project Settings.
#include "GASAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"


UGASAttributeSet::UGASAttributeSet()
{

}

void UGASAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
		HealthChangeDelegate.Broadcast(GetHealth(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.0f, GetMaxMana()));
		ManaChangeDelegate.Broadcast(GetMana(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetAttackDamageAttribute())
	{
		SetAttackDamage(FMath::Clamp(GetAttackDamage(), 1.0f, 50.0f));
		AttackDamageChangeDelegate.Broadcast(GetAttackDamage(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetAttackSpeedAttribute())
	{
		SetAttackSpeed(FMath::Clamp(GetAttackSpeed(), 0.0f, 2.0f));
		AttackSpeedChangeDelegate.Broadcast(GetAttackSpeed(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetBaseAttackSpeedMultiplierAttribute())
	{
		SetBaseAttackSpeedMultiplier(FMath::Clamp(GetBaseAttackSpeedMultiplier(), 1.0f, 3.0f));
		BaseAttackSpeedMultiplierChangeDelegate.Broadcast(GetBaseAttackSpeedMultiplier(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetMovementSpeedAttribute())
	{
		SetMovementSpeed(FMath::Clamp(GetMovementSpeed(), 1.0f, 5.0f));
		MovementSpeedChangeDelegate.Broadcast(GetMovementSpeed(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetArmorAttribute())
	{
		SetArmor(FMath::Clamp(GetArmor(), 0.0f, GetMaxArmor()));
		ArmorChangeDelegate.Broadcast(GetArmor(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetMagicResistanceAttribute())
	{
		SetMagicResistance(FMath::Clamp(GetMagicResistance(), 0.0f, GetMaxMagicResistance()));
		MagicResistanceChangeDelegate.Broadcast(GetMagicResistance(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetStrengthAttribute())
	{
		SetStrength(FMath::Clamp(GetStrength(), 1.0f, 50.0f));
		StrengthChangeDelegate.Broadcast(GetStrength(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetAgilityAttribute())
	{
		SetAgility(FMath::Clamp(GetAgility(), 1.0f, 50.0f));
		AgilityChangeDelegate.Broadcast(GetAgility(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetIntelligenceAttribute())
	{
		SetIntelligence(FMath::Clamp(GetIntelligence(), 1.0f, 50.0f));
		IntelligenceChangeDelegate.Broadcast(GetIntelligence(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetAbilityPowerAttribute())
	{
		SetAbilityPower(FMath::Clamp(GetAbilityPower(), 0.0f, 25.0f));
		AbilityPowerChangeDelegate.Broadcast(GetAbilityPower(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetAttackRangeAttribute())
	{
		SetAttackRange(FMath::Clamp(GetAttackRange(), 1.0f, 5.0f));
		AttackRangeChangeDelegate.Broadcast(GetAttackRange(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetCastTimeAttribute())
	{
		SetCastTime(FMath::Clamp(GetCastTime(), 0.0f, 3.0f));
		CastTimeChangeDelegate.Broadcast(GetCastTime(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetCooldownAttribute())
	{
		SetCooldown(FMath::Clamp(GetCooldown(), 1.0f, 10.0f));
		CooldownChangeDelegate.Broadcast(GetCooldown(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetCooldownReductionAttribute())
	{
		SetCooldownReduction(FMath::Clamp(GetCooldownReduction(), 0.0f, GetMaxCooldownReduction()));
		CooldownReductionChangeDelegate.Broadcast(GetCooldownReduction(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetAbilityScalingAttribute())
	{
		SetAbilityScaling(FMath::Clamp(GetAbilityScaling(), 0.0f, 2.0f));
		AbilityScalingChangeDelegate.Broadcast(GetAbilityScaling(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetBaseDamageAttribute())
	{
		SetBaseDamage(FMath::Clamp(GetBaseDamage(), 1.0f, 50.0f));
		BaseDamageChangeDelegate.Broadcast(GetBaseDamage(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetScalingCoefficientAttribute())
	{
		SetScalingCoefficient(FMath::Clamp(GetScalingCoefficient(), 0.0f, 2.0f));
		ScalingCoefficientChangeDelegate.Broadcast(GetScalingCoefficient(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetItemNameAttribute())
	{
		SetItemName(FMath::Clamp(GetItemName(), 1.0f, 50.0f));
		ItemNameChangeDelegate.Broadcast(GetItemName(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetItemCostAttribute())
	{
		SetItemCost(FMath::Clamp(GetItemCost(), 1.0f, GetMaxItemCost()));
		ItemCostChangeDelegate.Broadcast(GetItemCost(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetItemTypeAttribute())
	{
		SetItemType(FMath::Clamp(GetItemType(), 0.0f, 3.0f));
		ItemTypeChangeDelegate.Broadcast(GetItemType(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetItemDescriptionAttribute())
	{
		SetItemDescription(FMath::Clamp(GetItemDescription(), 1.0f, 50.0f));
		ItemDescriptionChangeDelegate.Broadcast(GetItemDescription(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetItemEffectAttribute())
	{
		SetItemEffect(FMath::Clamp(GetItemEffect(), 0.0f, GetMaxItemEffect()));
		ItemEffectChangeDelegate.Broadcast(GetItemEffect(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetItemIconPathAttribute())
	{
		SetItemIconPath(FMath::Clamp(GetItemIconPath(), 1.0f, 50.0f));
		ItemIconPathChangeDelegate.Broadcast(GetItemIconPath(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetUIWindowPositionAttribute())
	{
		SetUIWindowPosition(FMath::Clamp(GetUIWindowPosition(), 0.0f, GetMaxUIWindowPosition()));
		UIWindowPositionChangeDelegate.Broadcast(GetUIWindowPosition(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetUIWindowSizeAttribute())
	{
		SetUIWindowSize(FMath::Clamp(GetUIWindowSize(), 1.0f, 100.0f));
		UIWindowSizeChangeDelegate.Broadcast(GetUIWindowSize(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetUIButtonClickEventAttribute())
	{
		SetUIButtonClickEvent(FMath::Clamp(GetUIButtonClickEvent(), 0.0f, 1.0f));
		UIButtonClickEventChangeDelegate.Broadcast(GetUIButtonClickEvent(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetUIProgressBarValueAttribute())
	{
		SetUIProgressBarValue(FMath::Clamp(GetUIProgressBarValue(), 0.0f, GetMaxUIProgressBarValue()));
		UIProgressBarValueChangeDelegate.Broadcast(GetUIProgressBarValue(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetUITextAlignmentAttribute())
	{
		SetUITextAlignment(FMath::Clamp(GetUITextAlignment(), 0.0f, 2.0f));
		UITextAlignmentChangeDelegate.Broadcast(GetUITextAlignment(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetUIColorAttribute())
	{
		SetUIColor(FMath::Clamp(GetUIColor(), 0.0f, GetMaxUIColor()));
		UIColorChangeDelegate.Broadcast(GetUIColor(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetOnHeroDeathAttribute())
	{
		SetOnHeroDeath(FMath::Clamp(GetOnHeroDeath(), 0.0f, 1.0f));
		OnHeroDeathChangeDelegate.Broadcast(GetOnHeroDeath(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetOnAbilityCastAttribute())
	{
		SetOnAbilityCast(FMath::Clamp(GetOnAbilityCast(), 0.0f, 1.0f));
		OnAbilityCastChangeDelegate.Broadcast(GetOnAbilityCast(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetOnItemPickedUpAttribute())
	{
		SetOnItemPickedUp(FMath::Clamp(GetOnItemPickedUp(), 0.0f, 1.0f));
		OnItemPickedUpChangeDelegate.Broadcast(GetOnItemPickedUp(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetOnTurretDestroyedAttribute())
	{
		SetOnTurretDestroyed(FMath::Clamp(GetOnTurretDestroyed(), 0.0f, 1.0f));
		OnTurretDestroyedChangeDelegate.Broadcast(GetOnTurretDestroyed(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetOnGoldEarnedAttribute())
	{
		SetOnGoldEarned(FMath::Clamp(GetOnGoldEarned(), 0.0f, 1.0f));
		OnGoldEarnedChangeDelegate.Broadcast(GetOnGoldEarned(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetMapSizeAttribute())
	{
		SetMapSize(FMath::Clamp(GetMapSize(), 1.0f, GetMaxMapSize()));
		MapSizeChangeDelegate.Broadcast(GetMapSize(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetSpawnPositionAttribute())
	{
		SetSpawnPosition(FMath::Clamp(GetSpawnPosition(), 500.0f, 500.0f));
		SpawnPositionChangeDelegate.Broadcast(GetSpawnPosition(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetLanePositionsAttribute())
	{
		SetLanePositions(FMath::Clamp(GetLanePositions(), 500.0f, 500.0f));
		LanePositionsChangeDelegate.Broadcast(GetLanePositions(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetJungleCampLocationsAttribute())
	{
		SetJungleCampLocations(FMath::Clamp(GetJungleCampLocations(), 500.0f, 500.0f));
		JungleCampLocationsChangeDelegate.Broadcast(GetJungleCampLocations(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetPlayerLevelAttribute())
	{
		SetPlayerLevel(FMath::Clamp(GetPlayerLevel(), 1.0f, GetMaxPlayerLevel()));
		PlayerLevelChangeDelegate.Broadcast(GetPlayerLevel(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetPlayerExperienceAttribute())
	{
		SetPlayerExperience(FMath::Clamp(GetPlayerExperience(), 0.0f, GetMaxPlayerExperience()));
		PlayerExperienceChangeDelegate.Broadcast(GetPlayerExperience(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetPlayerGoldAttribute())
	{
		SetPlayerGold(FMath::Clamp(GetPlayerGold(), 0.0f, GetMaxPlayerGold()));
		PlayerGoldChangeDelegate.Broadcast(GetPlayerGold(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetPlayerKillsAttribute())
	{
		SetPlayerKills(FMath::Clamp(GetPlayerKills(), 0.0f, GetMaxPlayerKills()));
		PlayerKillsChangeDelegate.Broadcast(GetPlayerKills(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetPlayerDeathsAttribute())
	{
		SetPlayerDeaths(FMath::Clamp(GetPlayerDeaths(), 0.0f, GetMaxPlayerDeaths()));
		PlayerDeathsChangeDelegate.Broadcast(GetPlayerDeaths(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetPlayerAssistsAttribute())
	{
		SetPlayerAssists(FMath::Clamp(GetPlayerAssists(), 0.0f, GetMaxPlayerAssists()));
		PlayerAssistsChangeDelegate.Broadcast(GetPlayerAssists(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetPlayerKillDeathRatioAttribute())
	{
		SetPlayerKillDeathRatio(FMath::Clamp(GetPlayerKillDeathRatio(), 0.0f, 20.0f));
		PlayerKillDeathRatioChangeDelegate.Broadcast(GetPlayerKillDeathRatio(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetTeamScoreAttribute())
	{
		SetTeamScore(FMath::Clamp(GetTeamScore(), 0.0f, GetMaxTeamScore()));
		TeamScoreChangeDelegate.Broadcast(GetTeamScore(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetTeamObjectiveCountAttribute())
	{
		SetTeamObjectiveCount(FMath::Clamp(GetTeamObjectiveCount(), 0.0f, GetMaxTeamObjectiveCount()));
		TeamObjectiveCountChangeDelegate.Broadcast(GetTeamObjectiveCount(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetTeamTowerCountAttribute())
	{
		SetTeamTowerCount(FMath::Clamp(GetTeamTowerCount(), 0.0f, GetMaxTeamTowerCount()));
		TeamTowerCountChangeDelegate.Broadcast(GetTeamTowerCount(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetTeamJungleCampCountAttribute())
	{
		SetTeamJungleCampCount(FMath::Clamp(GetTeamJungleCampCount(), 0.0f, GetMaxTeamJungleCampCount()));
		TeamJungleCampCountChangeDelegate.Broadcast(GetTeamJungleCampCount(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetDurationAttribute())
	{
		SetDuration(FMath::Clamp(GetDuration(), 1.0f, 60.0f));
		DurationChangeDelegate.Broadcast(GetDuration(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetTickIntervalAttribute())
	{
		SetTickInterval(FMath::Clamp(GetTickInterval(), 1.0f, 60.0f));
		TickIntervalChangeDelegate.Broadcast(GetTickInterval(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetOnEffectApplyAttribute())
	{
		SetOnEffectApply(FMath::Clamp(GetOnEffectApply(), 0.0f, 1.0f));
		OnEffectApplyChangeDelegate.Broadcast(GetOnEffectApply(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetOnEffectRemoveAttribute())
	{
		SetOnEffectRemove(FMath::Clamp(GetOnEffectRemove(), 0.0f, 1.0f));
		OnEffectRemoveChangeDelegate.Broadcast(GetOnEffectRemove(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetStacksAttribute())
	{
		SetStacks(FMath::Clamp(GetStacks(), 0.0f, 1.0f));
		StacksChangeDelegate.Broadcast(GetStacks(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetMaxStacksAttribute())
	{
		SetMaxStacks(FMath::Clamp(GetMaxStacks(), 0.0f, 1.0f));
		MaxStacksChangeDelegate.Broadcast(GetMaxStacks(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetGameTimeAttribute())
	{
		SetGameTime(FMath::Clamp(GetGameTime(), 0.0f, 60.0f));
		GameTimeChangeDelegate.Broadcast(GetGameTime(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetMatchDurationAttribute())
	{
		SetMatchDuration(FMath::Clamp(GetMatchDuration(), 15.0f, 60.0f));
		MatchDurationChangeDelegate.Broadcast(GetMatchDuration(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetPauseStateAttribute())
	{
		SetPauseState(FMath::Clamp(GetPauseState(), 0.0f, 2.0f));
		PauseStateChangeDelegate.Broadcast(GetPauseState(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetGameModeAttribute())
	{
		SetGameMode(FMath::Clamp(GetGameMode(), 0.0f, 3.0f));
		GameModeChangeDelegate.Broadcast(GetGameMode(), Data.EffectSpec.GetStackCount());
	}
	if (Data.EvaluatedData.Attribute == GetGameStateAttribute())
	{
		SetGameState(FMath::Clamp(GetGameState(), 0.0f, 3.0f));
		GameStateChangeDelegate.Broadcast(GetGameState(), Data.EffectSpec.GetStackCount());
	}
}

void UGASAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, AttackDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, BaseAttackSpeedMultiplier, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxArmor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MagicResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxMagicResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Agility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, AbilityPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, AttackRange, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, CastTime, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Cooldown, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, CooldownReduction, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxCooldownReduction, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, AbilityScaling, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, BaseDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, ScalingCoefficient, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, ItemName, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, ItemCost, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxItemCost, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, ItemType, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, ItemDescription, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, ItemEffect, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxItemEffect, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, ItemIconPath, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, UIWindowPosition, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxUIWindowPosition, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, UIWindowSize, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, UIButtonClickEvent, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, UIProgressBarValue, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxUIProgressBarValue, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, UITextAlignment, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, UIColor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxUIColor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, OnHeroDeath, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, OnAbilityCast, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, OnItemPickedUp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, OnTurretDestroyed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, OnGoldEarned, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MapSize, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxMapSize, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, SpawnPosition, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, LanePositions, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, JungleCampLocations, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, PlayerLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxPlayerLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, PlayerExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxPlayerExperience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, PlayerGold, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxPlayerGold, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, PlayerKills, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxPlayerKills, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, PlayerDeaths, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxPlayerDeaths, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, PlayerAssists, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxPlayerAssists, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, PlayerKillDeathRatio, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, TeamScore, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxTeamScore, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, TeamObjectiveCount, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxTeamObjectiveCount, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, TeamTowerCount, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxTeamTowerCount, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, TeamJungleCampCount, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxTeamJungleCampCount, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Duration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, TickInterval, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, OnEffectApply, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, OnEffectRemove, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Stacks, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MaxStacks, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, GameTime, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MatchDuration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, PauseState, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, GameMode, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, GameState, COND_None, REPNOTIFY_Always);
}

void UGASAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Health, OldHealth);
}
void UGASAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxHealth, OldMaxHealth);
}
void UGASAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Mana, OldMana);
}
void UGASAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxMana, OldMaxMana);
}
void UGASAttributeSet::OnRep_AttackDamage(const FGameplayAttributeData& OldAttackDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, AttackDamage, OldAttackDamage);
}
void UGASAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, AttackSpeed, OldAttackSpeed);
}
void UGASAttributeSet::OnRep_BaseAttackSpeedMultiplier(const FGameplayAttributeData& OldBaseAttackSpeedMultiplier)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, BaseAttackSpeedMultiplier, OldBaseAttackSpeedMultiplier);
}
void UGASAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MovementSpeed, OldMovementSpeed);
}
void UGASAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Armor, OldArmor);
}
void UGASAttributeSet::OnRep_MaxArmor(const FGameplayAttributeData& OldMaxArmor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxArmor, OldMaxArmor);
}
void UGASAttributeSet::OnRep_MagicResistance(const FGameplayAttributeData& OldMagicResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MagicResistance, OldMagicResistance);
}
void UGASAttributeSet::OnRep_MaxMagicResistance(const FGameplayAttributeData& OldMaxMagicResistance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxMagicResistance, OldMaxMagicResistance);
}
void UGASAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Strength, OldStrength);
}
void UGASAttributeSet::OnRep_Agility(const FGameplayAttributeData& OldAgility)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Agility, OldAgility);
}
void UGASAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Intelligence, OldIntelligence);
}
void UGASAttributeSet::OnRep_AbilityPower(const FGameplayAttributeData& OldAbilityPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, AbilityPower, OldAbilityPower);
}
void UGASAttributeSet::OnRep_AttackRange(const FGameplayAttributeData& OldAttackRange)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, AttackRange, OldAttackRange);
}
void UGASAttributeSet::OnRep_CastTime(const FGameplayAttributeData& OldCastTime)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, CastTime, OldCastTime);
}
void UGASAttributeSet::OnRep_Cooldown(const FGameplayAttributeData& OldCooldown)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Cooldown, OldCooldown);
}
void UGASAttributeSet::OnRep_CooldownReduction(const FGameplayAttributeData& OldCooldownReduction)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, CooldownReduction, OldCooldownReduction);
}
void UGASAttributeSet::OnRep_MaxCooldownReduction(const FGameplayAttributeData& OldMaxCooldownReduction)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxCooldownReduction, OldMaxCooldownReduction);
}
void UGASAttributeSet::OnRep_AbilityScaling(const FGameplayAttributeData& OldAbilityScaling)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, AbilityScaling, OldAbilityScaling);
}
void UGASAttributeSet::OnRep_BaseDamage(const FGameplayAttributeData& OldBaseDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, BaseDamage, OldBaseDamage);
}
void UGASAttributeSet::OnRep_ScalingCoefficient(const FGameplayAttributeData& OldScalingCoefficient)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, ScalingCoefficient, OldScalingCoefficient);
}
void UGASAttributeSet::OnRep_ItemName(const FGameplayAttributeData& OldItemName)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, ItemName, OldItemName);
}
void UGASAttributeSet::OnRep_ItemCost(const FGameplayAttributeData& OldItemCost)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, ItemCost, OldItemCost);
}
void UGASAttributeSet::OnRep_MaxItemCost(const FGameplayAttributeData& OldMaxItemCost)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxItemCost, OldMaxItemCost);
}
void UGASAttributeSet::OnRep_ItemType(const FGameplayAttributeData& OldItemType)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, ItemType, OldItemType);
}
void UGASAttributeSet::OnRep_ItemDescription(const FGameplayAttributeData& OldItemDescription)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, ItemDescription, OldItemDescription);
}
void UGASAttributeSet::OnRep_ItemEffect(const FGameplayAttributeData& OldItemEffect)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, ItemEffect, OldItemEffect);
}
void UGASAttributeSet::OnRep_MaxItemEffect(const FGameplayAttributeData& OldMaxItemEffect)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxItemEffect, OldMaxItemEffect);
}
void UGASAttributeSet::OnRep_ItemIconPath(const FGameplayAttributeData& OldItemIconPath)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, ItemIconPath, OldItemIconPath);
}
void UGASAttributeSet::OnRep_UIWindowPosition(const FGameplayAttributeData& OldUIWindowPosition)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, UIWindowPosition, OldUIWindowPosition);
}
void UGASAttributeSet::OnRep_MaxUIWindowPosition(const FGameplayAttributeData& OldMaxUIWindowPosition)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxUIWindowPosition, OldMaxUIWindowPosition);
}
void UGASAttributeSet::OnRep_UIWindowSize(const FGameplayAttributeData& OldUIWindowSize)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, UIWindowSize, OldUIWindowSize);
}
void UGASAttributeSet::OnRep_UIButtonClickEvent(const FGameplayAttributeData& OldUIButtonClickEvent)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, UIButtonClickEvent, OldUIButtonClickEvent);
}
void UGASAttributeSet::OnRep_UIProgressBarValue(const FGameplayAttributeData& OldUIProgressBarValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, UIProgressBarValue, OldUIProgressBarValue);
}
void UGASAttributeSet::OnRep_MaxUIProgressBarValue(const FGameplayAttributeData& OldMaxUIProgressBarValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxUIProgressBarValue, OldMaxUIProgressBarValue);
}
void UGASAttributeSet::OnRep_UITextAlignment(const FGameplayAttributeData& OldUITextAlignment)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, UITextAlignment, OldUITextAlignment);
}
void UGASAttributeSet::OnRep_UIColor(const FGameplayAttributeData& OldUIColor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, UIColor, OldUIColor);
}
void UGASAttributeSet::OnRep_MaxUIColor(const FGameplayAttributeData& OldMaxUIColor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxUIColor, OldMaxUIColor);
}
void UGASAttributeSet::OnRep_OnHeroDeath(const FGameplayAttributeData& OldOnHeroDeath)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, OnHeroDeath, OldOnHeroDeath);
}
void UGASAttributeSet::OnRep_OnAbilityCast(const FGameplayAttributeData& OldOnAbilityCast)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, OnAbilityCast, OldOnAbilityCast);
}
void UGASAttributeSet::OnRep_OnItemPickedUp(const FGameplayAttributeData& OldOnItemPickedUp)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, OnItemPickedUp, OldOnItemPickedUp);
}
void UGASAttributeSet::OnRep_OnTurretDestroyed(const FGameplayAttributeData& OldOnTurretDestroyed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, OnTurretDestroyed, OldOnTurretDestroyed);
}
void UGASAttributeSet::OnRep_OnGoldEarned(const FGameplayAttributeData& OldOnGoldEarned)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, OnGoldEarned, OldOnGoldEarned);
}
void UGASAttributeSet::OnRep_MapSize(const FGameplayAttributeData& OldMapSize)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MapSize, OldMapSize);
}
void UGASAttributeSet::OnRep_MaxMapSize(const FGameplayAttributeData& OldMaxMapSize)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxMapSize, OldMaxMapSize);
}
void UGASAttributeSet::OnRep_SpawnPosition(const FGameplayAttributeData& OldSpawnPosition)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, SpawnPosition, OldSpawnPosition);
}
void UGASAttributeSet::OnRep_LanePositions(const FGameplayAttributeData& OldLanePositions)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, LanePositions, OldLanePositions);
}
void UGASAttributeSet::OnRep_JungleCampLocations(const FGameplayAttributeData& OldJungleCampLocations)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, JungleCampLocations, OldJungleCampLocations);
}
void UGASAttributeSet::OnRep_PlayerLevel(const FGameplayAttributeData& OldPlayerLevel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, PlayerLevel, OldPlayerLevel);
}
void UGASAttributeSet::OnRep_MaxPlayerLevel(const FGameplayAttributeData& OldMaxPlayerLevel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxPlayerLevel, OldMaxPlayerLevel);
}
void UGASAttributeSet::OnRep_PlayerExperience(const FGameplayAttributeData& OldPlayerExperience)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, PlayerExperience, OldPlayerExperience);
}
void UGASAttributeSet::OnRep_MaxPlayerExperience(const FGameplayAttributeData& OldMaxPlayerExperience)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxPlayerExperience, OldMaxPlayerExperience);
}
void UGASAttributeSet::OnRep_PlayerGold(const FGameplayAttributeData& OldPlayerGold)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, PlayerGold, OldPlayerGold);
}
void UGASAttributeSet::OnRep_MaxPlayerGold(const FGameplayAttributeData& OldMaxPlayerGold)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxPlayerGold, OldMaxPlayerGold);
}
void UGASAttributeSet::OnRep_PlayerKills(const FGameplayAttributeData& OldPlayerKills)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, PlayerKills, OldPlayerKills);
}
void UGASAttributeSet::OnRep_MaxPlayerKills(const FGameplayAttributeData& OldMaxPlayerKills)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxPlayerKills, OldMaxPlayerKills);
}
void UGASAttributeSet::OnRep_PlayerDeaths(const FGameplayAttributeData& OldPlayerDeaths)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, PlayerDeaths, OldPlayerDeaths);
}
void UGASAttributeSet::OnRep_MaxPlayerDeaths(const FGameplayAttributeData& OldMaxPlayerDeaths)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxPlayerDeaths, OldMaxPlayerDeaths);
}
void UGASAttributeSet::OnRep_PlayerAssists(const FGameplayAttributeData& OldPlayerAssists)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, PlayerAssists, OldPlayerAssists);
}
void UGASAttributeSet::OnRep_MaxPlayerAssists(const FGameplayAttributeData& OldMaxPlayerAssists)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxPlayerAssists, OldMaxPlayerAssists);
}
void UGASAttributeSet::OnRep_PlayerKillDeathRatio(const FGameplayAttributeData& OldPlayerKillDeathRatio)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, PlayerKillDeathRatio, OldPlayerKillDeathRatio);
}
void UGASAttributeSet::OnRep_TeamScore(const FGameplayAttributeData& OldTeamScore)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, TeamScore, OldTeamScore);
}
void UGASAttributeSet::OnRep_MaxTeamScore(const FGameplayAttributeData& OldMaxTeamScore)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxTeamScore, OldMaxTeamScore);
}
void UGASAttributeSet::OnRep_TeamObjectiveCount(const FGameplayAttributeData& OldTeamObjectiveCount)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, TeamObjectiveCount, OldTeamObjectiveCount);
}
void UGASAttributeSet::OnRep_MaxTeamObjectiveCount(const FGameplayAttributeData& OldMaxTeamObjectiveCount)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxTeamObjectiveCount, OldMaxTeamObjectiveCount);
}
void UGASAttributeSet::OnRep_TeamTowerCount(const FGameplayAttributeData& OldTeamTowerCount)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, TeamTowerCount, OldTeamTowerCount);
}
void UGASAttributeSet::OnRep_MaxTeamTowerCount(const FGameplayAttributeData& OldMaxTeamTowerCount)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxTeamTowerCount, OldMaxTeamTowerCount);
}
void UGASAttributeSet::OnRep_TeamJungleCampCount(const FGameplayAttributeData& OldTeamJungleCampCount)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, TeamJungleCampCount, OldTeamJungleCampCount);
}
void UGASAttributeSet::OnRep_MaxTeamJungleCampCount(const FGameplayAttributeData& OldMaxTeamJungleCampCount)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxTeamJungleCampCount, OldMaxTeamJungleCampCount);
}
void UGASAttributeSet::OnRep_Duration(const FGameplayAttributeData& OldDuration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Duration, OldDuration);
}
void UGASAttributeSet::OnRep_TickInterval(const FGameplayAttributeData& OldTickInterval)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, TickInterval, OldTickInterval);
}
void UGASAttributeSet::OnRep_OnEffectApply(const FGameplayAttributeData& OldOnEffectApply)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, OnEffectApply, OldOnEffectApply);
}
void UGASAttributeSet::OnRep_OnEffectRemove(const FGameplayAttributeData& OldOnEffectRemove)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, OnEffectRemove, OldOnEffectRemove);
}
void UGASAttributeSet::OnRep_Stacks(const FGameplayAttributeData& OldStacks)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Stacks, OldStacks);
}
void UGASAttributeSet::OnRep_MaxStacks(const FGameplayAttributeData& OldMaxStacks)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MaxStacks, OldMaxStacks);
}
void UGASAttributeSet::OnRep_GameTime(const FGameplayAttributeData& OldGameTime)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, GameTime, OldGameTime);
}
void UGASAttributeSet::OnRep_MatchDuration(const FGameplayAttributeData& OldMatchDuration)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MatchDuration, OldMatchDuration);
}
void UGASAttributeSet::OnRep_PauseState(const FGameplayAttributeData& OldPauseState)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, PauseState, OldPauseState);
}
void UGASAttributeSet::OnRep_GameMode(const FGameplayAttributeData& OldGameMode)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, GameMode, OldGameMode);
}
void UGASAttributeSet::OnRep_GameState(const FGameplayAttributeData& OldGameState)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, GameState, OldGameState);
}
