// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GASAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

struct FGameplayEffectModCallbackData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttrChangeDelegate, float, Attr, int32, StackcCount);

/**
 * 
 */
UCLASS()
class GASASSOCIATE_API UGASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	UGASAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	//Post Gameplay Effect Execute, only to clamp values
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	//Define Attributes Here

//==PATTERN==
	//Attribute for Health
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Health)

	//Attribute for MaxHealth
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxHealth)

	//Attribute for Mana
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Mana)

	//Attribute for MaxMana
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxMana)

	//Attribute for AttackDamage
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AttackDamage)
	FGameplayAttributeData AttackDamage;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, AttackDamage)

	//Attribute for AttackSpeed
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AttackSpeed)
	FGameplayAttributeData AttackSpeed;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, AttackSpeed)

	//Attribute for BaseAttackSpeedMultiplier
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_BaseAttackSpeedMultiplier)
	FGameplayAttributeData BaseAttackSpeedMultiplier;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, BaseAttackSpeedMultiplier)

	//Attribute for MovementSpeed
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MovementSpeed)
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MovementSpeed)

	//Attribute for Armor
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Armor)
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Armor)

	//Attribute for MaxArmor
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxArmor)
	FGameplayAttributeData MaxArmor;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxArmor)

	//Attribute for MagicResistance
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MagicResistance)
	FGameplayAttributeData MagicResistance;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MagicResistance)

	//Attribute for MaxMagicResistance
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxMagicResistance)
	FGameplayAttributeData MaxMagicResistance;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxMagicResistance)

	//Attribute for Strength
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Strength)
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Strength)

	//Attribute for Agility
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Agility)
	FGameplayAttributeData Agility;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Agility)

	//Attribute for Intelligence
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Intelligence)
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Intelligence)

	//Attribute for AbilityPower
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AbilityPower)
	FGameplayAttributeData AbilityPower;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, AbilityPower)

	//Attribute for AttackRange
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AttackRange)
	FGameplayAttributeData AttackRange;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, AttackRange)

	//Attribute for CastTime
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CastTime)
	FGameplayAttributeData CastTime;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, CastTime)

	//Attribute for Cooldown
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Cooldown)
	FGameplayAttributeData Cooldown;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Cooldown)

	//Attribute for CooldownReduction
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_CooldownReduction)
	FGameplayAttributeData CooldownReduction;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, CooldownReduction)

	//Attribute for MaxCooldownReduction
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxCooldownReduction)
	FGameplayAttributeData MaxCooldownReduction;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxCooldownReduction)

	//Attribute for AbilityScaling
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AbilityScaling)
	FGameplayAttributeData AbilityScaling;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, AbilityScaling)

	//Attribute for BaseDamage
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_BaseDamage)
	FGameplayAttributeData BaseDamage;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, BaseDamage)

	//Attribute for ScalingCoefficient
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ScalingCoefficient)
	FGameplayAttributeData ScalingCoefficient;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, ScalingCoefficient)

	//Attribute for ItemName
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ItemName)
	FGameplayAttributeData ItemName;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, ItemName)

	//Attribute for ItemCost
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ItemCost)
	FGameplayAttributeData ItemCost;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, ItemCost)

	//Attribute for MaxItemCost
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxItemCost)
	FGameplayAttributeData MaxItemCost;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxItemCost)

	//Attribute for ItemType
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ItemType)
	FGameplayAttributeData ItemType;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, ItemType)

	//Attribute for ItemDescription
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ItemDescription)
	FGameplayAttributeData ItemDescription;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, ItemDescription)

	//Attribute for ItemEffect
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ItemEffect)
	FGameplayAttributeData ItemEffect;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, ItemEffect)

	//Attribute for MaxItemEffect
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxItemEffect)
	FGameplayAttributeData MaxItemEffect;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxItemEffect)

	//Attribute for ItemIconPath
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ItemIconPath)
	FGameplayAttributeData ItemIconPath;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, ItemIconPath)

	//Attribute for UIWindowPosition
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_UIWindowPosition)
	FGameplayAttributeData UIWindowPosition;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, UIWindowPosition)

	//Attribute for MaxUIWindowPosition
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxUIWindowPosition)
	FGameplayAttributeData MaxUIWindowPosition;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxUIWindowPosition)

	//Attribute for UIWindowSize
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_UIWindowSize)
	FGameplayAttributeData UIWindowSize;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, UIWindowSize)

	//Attribute for UIButtonClickEvent
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_UIButtonClickEvent)
	FGameplayAttributeData UIButtonClickEvent;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, UIButtonClickEvent)

	//Attribute for UIProgressBarValue
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_UIProgressBarValue)
	FGameplayAttributeData UIProgressBarValue;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, UIProgressBarValue)

	//Attribute for MaxUIProgressBarValue
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxUIProgressBarValue)
	FGameplayAttributeData MaxUIProgressBarValue;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxUIProgressBarValue)

	//Attribute for UITextAlignment
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_UITextAlignment)
	FGameplayAttributeData UITextAlignment;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, UITextAlignment)

	//Attribute for UIColor
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_UIColor)
	FGameplayAttributeData UIColor;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, UIColor)

	//Attribute for MaxUIColor
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxUIColor)
	FGameplayAttributeData MaxUIColor;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxUIColor)

	//Attribute for OnHeroDeath
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_OnHeroDeath)
	FGameplayAttributeData OnHeroDeath;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, OnHeroDeath)

	//Attribute for OnAbilityCast
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_OnAbilityCast)
	FGameplayAttributeData OnAbilityCast;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, OnAbilityCast)

	//Attribute for OnItemPickedUp
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_OnItemPickedUp)
	FGameplayAttributeData OnItemPickedUp;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, OnItemPickedUp)

	//Attribute for OnTurretDestroyed
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_OnTurretDestroyed)
	FGameplayAttributeData OnTurretDestroyed;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, OnTurretDestroyed)

	//Attribute for OnGoldEarned
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_OnGoldEarned)
	FGameplayAttributeData OnGoldEarned;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, OnGoldEarned)

	//Attribute for MapSize
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MapSize)
	FGameplayAttributeData MapSize;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MapSize)

	//Attribute for MaxMapSize
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxMapSize)
	FGameplayAttributeData MaxMapSize;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxMapSize)

	//Attribute for SpawnPosition
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_SpawnPosition)
	FGameplayAttributeData SpawnPosition;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, SpawnPosition)

	//Attribute for LanePositions
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_LanePositions)
	FGameplayAttributeData LanePositions;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, LanePositions)

	//Attribute for JungleCampLocations
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_JungleCampLocations)
	FGameplayAttributeData JungleCampLocations;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, JungleCampLocations)

	//Attribute for PlayerLevel
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PlayerLevel)
	FGameplayAttributeData PlayerLevel;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, PlayerLevel)

	//Attribute for MaxPlayerLevel
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxPlayerLevel)
	FGameplayAttributeData MaxPlayerLevel;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxPlayerLevel)

	//Attribute for PlayerExperience
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PlayerExperience)
	FGameplayAttributeData PlayerExperience;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, PlayerExperience)

	//Attribute for MaxPlayerExperience
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxPlayerExperience)
	FGameplayAttributeData MaxPlayerExperience;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxPlayerExperience)

	//Attribute for PlayerGold
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PlayerGold)
	FGameplayAttributeData PlayerGold;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, PlayerGold)

	//Attribute for MaxPlayerGold
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxPlayerGold)
	FGameplayAttributeData MaxPlayerGold;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxPlayerGold)

	//Attribute for PlayerKills
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PlayerKills)
	FGameplayAttributeData PlayerKills;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, PlayerKills)

	//Attribute for MaxPlayerKills
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxPlayerKills)
	FGameplayAttributeData MaxPlayerKills;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxPlayerKills)

	//Attribute for PlayerDeaths
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PlayerDeaths)
	FGameplayAttributeData PlayerDeaths;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, PlayerDeaths)

	//Attribute for MaxPlayerDeaths
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxPlayerDeaths)
	FGameplayAttributeData MaxPlayerDeaths;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxPlayerDeaths)

	//Attribute for PlayerAssists
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PlayerAssists)
	FGameplayAttributeData PlayerAssists;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, PlayerAssists)

	//Attribute for MaxPlayerAssists
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxPlayerAssists)
	FGameplayAttributeData MaxPlayerAssists;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxPlayerAssists)

	//Attribute for PlayerKillDeathRatio
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PlayerKillDeathRatio)
	FGameplayAttributeData PlayerKillDeathRatio;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, PlayerKillDeathRatio)

	//Attribute for TeamScore
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_TeamScore)
	FGameplayAttributeData TeamScore;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, TeamScore)

	//Attribute for MaxTeamScore
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxTeamScore)
	FGameplayAttributeData MaxTeamScore;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxTeamScore)

	//Attribute for TeamObjectiveCount
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_TeamObjectiveCount)
	FGameplayAttributeData TeamObjectiveCount;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, TeamObjectiveCount)

	//Attribute for MaxTeamObjectiveCount
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxTeamObjectiveCount)
	FGameplayAttributeData MaxTeamObjectiveCount;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxTeamObjectiveCount)

	//Attribute for TeamTowerCount
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_TeamTowerCount)
	FGameplayAttributeData TeamTowerCount;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, TeamTowerCount)

	//Attribute for MaxTeamTowerCount
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxTeamTowerCount)
	FGameplayAttributeData MaxTeamTowerCount;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxTeamTowerCount)

	//Attribute for TeamJungleCampCount
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_TeamJungleCampCount)
	FGameplayAttributeData TeamJungleCampCount;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, TeamJungleCampCount)

	//Attribute for MaxTeamJungleCampCount
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxTeamJungleCampCount)
	FGameplayAttributeData MaxTeamJungleCampCount;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxTeamJungleCampCount)

	//Attribute for Duration
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Duration)
	FGameplayAttributeData Duration;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Duration)

	//Attribute for TickInterval
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_TickInterval)
	FGameplayAttributeData TickInterval;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, TickInterval)

	//Attribute for OnEffectApply
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_OnEffectApply)
	FGameplayAttributeData OnEffectApply;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, OnEffectApply)

	//Attribute for OnEffectRemove
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_OnEffectRemove)
	FGameplayAttributeData OnEffectRemove;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, OnEffectRemove)

	//Attribute for Stacks
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Stacks)
	FGameplayAttributeData Stacks;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Stacks)

	//Attribute for MaxStacks
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxStacks)
	FGameplayAttributeData MaxStacks;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MaxStacks)

	//Attribute for GameTime
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_GameTime)
	FGameplayAttributeData GameTime;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, GameTime)

	//Attribute for MatchDuration
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MatchDuration)
	FGameplayAttributeData MatchDuration;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MatchDuration)

	//Attribute for PauseState
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PauseState)
	FGameplayAttributeData PauseState;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, PauseState)

	//Attribute for GameMode
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_GameMode)
	FGameplayAttributeData GameMode;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, GameMode)

	//Attribute for GameState
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_GameState)
	FGameplayAttributeData GameState;
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, GameState)

	//Delegates for attribute changes
	FAttrChangeDelegate HealthChangeDelegate;
	FAttrChangeDelegate ManaChangeDelegate;
	FAttrChangeDelegate AttackDamageChangeDelegate;
	FAttrChangeDelegate AttackSpeedChangeDelegate;
	FAttrChangeDelegate BaseAttackSpeedMultiplierChangeDelegate;
	FAttrChangeDelegate MovementSpeedChangeDelegate;
	FAttrChangeDelegate ArmorChangeDelegate;
	FAttrChangeDelegate MagicResistanceChangeDelegate;
	FAttrChangeDelegate StrengthChangeDelegate;
	FAttrChangeDelegate AgilityChangeDelegate;
	FAttrChangeDelegate IntelligenceChangeDelegate;
	FAttrChangeDelegate AbilityPowerChangeDelegate;
	FAttrChangeDelegate AttackRangeChangeDelegate;
	FAttrChangeDelegate CastTimeChangeDelegate;
	FAttrChangeDelegate CooldownChangeDelegate;
	FAttrChangeDelegate CooldownReductionChangeDelegate;
	FAttrChangeDelegate AbilityScalingChangeDelegate;
	FAttrChangeDelegate BaseDamageChangeDelegate;
	FAttrChangeDelegate ScalingCoefficientChangeDelegate;
	FAttrChangeDelegate ItemNameChangeDelegate;
	FAttrChangeDelegate ItemCostChangeDelegate;
	FAttrChangeDelegate ItemTypeChangeDelegate;
	FAttrChangeDelegate ItemDescriptionChangeDelegate;
	FAttrChangeDelegate ItemEffectChangeDelegate;
	FAttrChangeDelegate ItemIconPathChangeDelegate;
	FAttrChangeDelegate UIWindowPositionChangeDelegate;
	FAttrChangeDelegate UIWindowSizeChangeDelegate;
	FAttrChangeDelegate UIButtonClickEventChangeDelegate;
	FAttrChangeDelegate UIProgressBarValueChangeDelegate;
	FAttrChangeDelegate UITextAlignmentChangeDelegate;
	FAttrChangeDelegate UIColorChangeDelegate;
	FAttrChangeDelegate OnHeroDeathChangeDelegate;
	FAttrChangeDelegate OnAbilityCastChangeDelegate;
	FAttrChangeDelegate OnItemPickedUpChangeDelegate;
	FAttrChangeDelegate OnTurretDestroyedChangeDelegate;
	FAttrChangeDelegate OnGoldEarnedChangeDelegate;
	FAttrChangeDelegate MapSizeChangeDelegate;
	FAttrChangeDelegate SpawnPositionChangeDelegate;
	FAttrChangeDelegate LanePositionsChangeDelegate;
	FAttrChangeDelegate JungleCampLocationsChangeDelegate;
	FAttrChangeDelegate PlayerLevelChangeDelegate;
	FAttrChangeDelegate PlayerExperienceChangeDelegate;
	FAttrChangeDelegate PlayerGoldChangeDelegate;
	FAttrChangeDelegate PlayerKillsChangeDelegate;
	FAttrChangeDelegate PlayerDeathsChangeDelegate;
	FAttrChangeDelegate PlayerAssistsChangeDelegate;
	FAttrChangeDelegate PlayerKillDeathRatioChangeDelegate;
	FAttrChangeDelegate TeamScoreChangeDelegate;
	FAttrChangeDelegate TeamObjectiveCountChangeDelegate;
	FAttrChangeDelegate TeamTowerCountChangeDelegate;
	FAttrChangeDelegate TeamJungleCampCountChangeDelegate;
	FAttrChangeDelegate DurationChangeDelegate;
	FAttrChangeDelegate TickIntervalChangeDelegate;
	FAttrChangeDelegate OnEffectApplyChangeDelegate;
	FAttrChangeDelegate OnEffectRemoveChangeDelegate;
	FAttrChangeDelegate StacksChangeDelegate;
	FAttrChangeDelegate MaxStacksChangeDelegate;
	FAttrChangeDelegate GameTimeChangeDelegate;
	FAttrChangeDelegate MatchDurationChangeDelegate;
	FAttrChangeDelegate PauseStateChangeDelegate;
	FAttrChangeDelegate GameModeChangeDelegate;
	FAttrChangeDelegate GameStateChangeDelegate;
	//Replication Functions for Attributes
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	UFUNCTION()
	virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);
	UFUNCTION()
	virtual void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);
	UFUNCTION()
	virtual void OnRep_AttackDamage(const FGameplayAttributeData& OldAttackDamage);
	UFUNCTION()
	virtual void OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed);
	UFUNCTION()
	virtual void OnRep_BaseAttackSpeedMultiplier(const FGameplayAttributeData& OldBaseAttackSpeedMultiplier);
	UFUNCTION()
	virtual void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed);
	UFUNCTION()
	virtual void OnRep_Armor(const FGameplayAttributeData& OldArmor);
	UFUNCTION()
	virtual void OnRep_MaxArmor(const FGameplayAttributeData& OldMaxArmor);
	UFUNCTION()
	virtual void OnRep_MagicResistance(const FGameplayAttributeData& OldMagicResistance);
	UFUNCTION()
	virtual void OnRep_MaxMagicResistance(const FGameplayAttributeData& OldMaxMagicResistance);
	UFUNCTION()
	virtual void OnRep_Strength(const FGameplayAttributeData& OldStrength);
	UFUNCTION()
	virtual void OnRep_Agility(const FGameplayAttributeData& OldAgility);
	UFUNCTION()
	virtual void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence);
	UFUNCTION()
	virtual void OnRep_AbilityPower(const FGameplayAttributeData& OldAbilityPower);
	UFUNCTION()
	virtual void OnRep_AttackRange(const FGameplayAttributeData& OldAttackRange);
	UFUNCTION()
	virtual void OnRep_CastTime(const FGameplayAttributeData& OldCastTime);
	UFUNCTION()
	virtual void OnRep_Cooldown(const FGameplayAttributeData& OldCooldown);
	UFUNCTION()
	virtual void OnRep_CooldownReduction(const FGameplayAttributeData& OldCooldownReduction);
	UFUNCTION()
	virtual void OnRep_MaxCooldownReduction(const FGameplayAttributeData& OldMaxCooldownReduction);
	UFUNCTION()
	virtual void OnRep_AbilityScaling(const FGameplayAttributeData& OldAbilityScaling);
	UFUNCTION()
	virtual void OnRep_BaseDamage(const FGameplayAttributeData& OldBaseDamage);
	UFUNCTION()
	virtual void OnRep_ScalingCoefficient(const FGameplayAttributeData& OldScalingCoefficient);
	UFUNCTION()
	virtual void OnRep_ItemName(const FGameplayAttributeData& OldItemName);
	UFUNCTION()
	virtual void OnRep_ItemCost(const FGameplayAttributeData& OldItemCost);
	UFUNCTION()
	virtual void OnRep_MaxItemCost(const FGameplayAttributeData& OldMaxItemCost);
	UFUNCTION()
	virtual void OnRep_ItemType(const FGameplayAttributeData& OldItemType);
	UFUNCTION()
	virtual void OnRep_ItemDescription(const FGameplayAttributeData& OldItemDescription);
	UFUNCTION()
	virtual void OnRep_ItemEffect(const FGameplayAttributeData& OldItemEffect);
	UFUNCTION()
	virtual void OnRep_MaxItemEffect(const FGameplayAttributeData& OldMaxItemEffect);
	UFUNCTION()
	virtual void OnRep_ItemIconPath(const FGameplayAttributeData& OldItemIconPath);
	UFUNCTION()
	virtual void OnRep_UIWindowPosition(const FGameplayAttributeData& OldUIWindowPosition);
	UFUNCTION()
	virtual void OnRep_MaxUIWindowPosition(const FGameplayAttributeData& OldMaxUIWindowPosition);
	UFUNCTION()
	virtual void OnRep_UIWindowSize(const FGameplayAttributeData& OldUIWindowSize);
	UFUNCTION()
	virtual void OnRep_UIButtonClickEvent(const FGameplayAttributeData& OldUIButtonClickEvent);
	UFUNCTION()
	virtual void OnRep_UIProgressBarValue(const FGameplayAttributeData& OldUIProgressBarValue);
	UFUNCTION()
	virtual void OnRep_MaxUIProgressBarValue(const FGameplayAttributeData& OldMaxUIProgressBarValue);
	UFUNCTION()
	virtual void OnRep_UITextAlignment(const FGameplayAttributeData& OldUITextAlignment);
	UFUNCTION()
	virtual void OnRep_UIColor(const FGameplayAttributeData& OldUIColor);
	UFUNCTION()
	virtual void OnRep_MaxUIColor(const FGameplayAttributeData& OldMaxUIColor);
	UFUNCTION()
	virtual void OnRep_OnHeroDeath(const FGameplayAttributeData& OldOnHeroDeath);
	UFUNCTION()
	virtual void OnRep_OnAbilityCast(const FGameplayAttributeData& OldOnAbilityCast);
	UFUNCTION()
	virtual void OnRep_OnItemPickedUp(const FGameplayAttributeData& OldOnItemPickedUp);
	UFUNCTION()
	virtual void OnRep_OnTurretDestroyed(const FGameplayAttributeData& OldOnTurretDestroyed);
	UFUNCTION()
	virtual void OnRep_OnGoldEarned(const FGameplayAttributeData& OldOnGoldEarned);
	UFUNCTION()
	virtual void OnRep_MapSize(const FGameplayAttributeData& OldMapSize);
	UFUNCTION()
	virtual void OnRep_MaxMapSize(const FGameplayAttributeData& OldMaxMapSize);
	UFUNCTION()
	virtual void OnRep_SpawnPosition(const FGameplayAttributeData& OldSpawnPosition);
	UFUNCTION()
	virtual void OnRep_LanePositions(const FGameplayAttributeData& OldLanePositions);
	UFUNCTION()
	virtual void OnRep_JungleCampLocations(const FGameplayAttributeData& OldJungleCampLocations);
	UFUNCTION()
	virtual void OnRep_PlayerLevel(const FGameplayAttributeData& OldPlayerLevel);
	UFUNCTION()
	virtual void OnRep_MaxPlayerLevel(const FGameplayAttributeData& OldMaxPlayerLevel);
	UFUNCTION()
	virtual void OnRep_PlayerExperience(const FGameplayAttributeData& OldPlayerExperience);
	UFUNCTION()
	virtual void OnRep_MaxPlayerExperience(const FGameplayAttributeData& OldMaxPlayerExperience);
	UFUNCTION()
	virtual void OnRep_PlayerGold(const FGameplayAttributeData& OldPlayerGold);
	UFUNCTION()
	virtual void OnRep_MaxPlayerGold(const FGameplayAttributeData& OldMaxPlayerGold);
	UFUNCTION()
	virtual void OnRep_PlayerKills(const FGameplayAttributeData& OldPlayerKills);
	UFUNCTION()
	virtual void OnRep_MaxPlayerKills(const FGameplayAttributeData& OldMaxPlayerKills);
	UFUNCTION()
	virtual void OnRep_PlayerDeaths(const FGameplayAttributeData& OldPlayerDeaths);
	UFUNCTION()
	virtual void OnRep_MaxPlayerDeaths(const FGameplayAttributeData& OldMaxPlayerDeaths);
	UFUNCTION()
	virtual void OnRep_PlayerAssists(const FGameplayAttributeData& OldPlayerAssists);
	UFUNCTION()
	virtual void OnRep_MaxPlayerAssists(const FGameplayAttributeData& OldMaxPlayerAssists);
	UFUNCTION()
	virtual void OnRep_PlayerKillDeathRatio(const FGameplayAttributeData& OldPlayerKillDeathRatio);
	UFUNCTION()
	virtual void OnRep_TeamScore(const FGameplayAttributeData& OldTeamScore);
	UFUNCTION()
	virtual void OnRep_MaxTeamScore(const FGameplayAttributeData& OldMaxTeamScore);
	UFUNCTION()
	virtual void OnRep_TeamObjectiveCount(const FGameplayAttributeData& OldTeamObjectiveCount);
	UFUNCTION()
	virtual void OnRep_MaxTeamObjectiveCount(const FGameplayAttributeData& OldMaxTeamObjectiveCount);
	UFUNCTION()
	virtual void OnRep_TeamTowerCount(const FGameplayAttributeData& OldTeamTowerCount);
	UFUNCTION()
	virtual void OnRep_MaxTeamTowerCount(const FGameplayAttributeData& OldMaxTeamTowerCount);
	UFUNCTION()
	virtual void OnRep_TeamJungleCampCount(const FGameplayAttributeData& OldTeamJungleCampCount);
	UFUNCTION()
	virtual void OnRep_MaxTeamJungleCampCount(const FGameplayAttributeData& OldMaxTeamJungleCampCount);
	UFUNCTION()
	virtual void OnRep_Duration(const FGameplayAttributeData& OldDuration);
	UFUNCTION()
	virtual void OnRep_TickInterval(const FGameplayAttributeData& OldTickInterval);
	UFUNCTION()
	virtual void OnRep_OnEffectApply(const FGameplayAttributeData& OldOnEffectApply);
	UFUNCTION()
	virtual void OnRep_OnEffectRemove(const FGameplayAttributeData& OldOnEffectRemove);
	UFUNCTION()
	virtual void OnRep_Stacks(const FGameplayAttributeData& OldStacks);
	UFUNCTION()
	virtual void OnRep_MaxStacks(const FGameplayAttributeData& OldMaxStacks);
	UFUNCTION()
	virtual void OnRep_GameTime(const FGameplayAttributeData& OldGameTime);
	UFUNCTION()
	virtual void OnRep_MatchDuration(const FGameplayAttributeData& OldMatchDuration);
	UFUNCTION()
	virtual void OnRep_PauseState(const FGameplayAttributeData& OldPauseState);
	UFUNCTION()
	virtual void OnRep_GameMode(const FGameplayAttributeData& OldGameMode);
	UFUNCTION()
	virtual void OnRep_GameState(const FGameplayAttributeData& OldGameState);

};
