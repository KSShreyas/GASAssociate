// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "GetAbilityInfo.h"
#include "GASCharacter.generated.h"

UCLASS()
class GASASSOCIATE_API AGASCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGASCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Add Ability System Component to Character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GASGameplayAbility")
	class UGASAbilitySystemComponent* AbilitySystemComponent;

	//Add Attribute Set to Character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GASGameplayAbility")
	const class UGASAttributeSet* AttributeSetVar;

	//Add Variable for Initial Abilities (do not leave blank!)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GASGameplayAbility")
	TArray<TSubclassOf<class UGameplayAbility>> InitialAbilities;

	//Interface Function to return Ability System Component of this character
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//Initialize a single Ability (Generic Version)
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void InitializeAbility(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel);

	//Initialize Ability Multi (Generic Version)
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void InitializeAbilityMulti(TArray<TSubclassOf<UGameplayAbility>> AbilitiesToAcquire, int32 AbilityLevel);

	//Initialize a single Ability (SERVER Version)
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "GASGameplayAbility|Server Version")
	void Server_InitializeAbility(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel);

	//Initialize Ability Multi (SERVER Version)
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility|Server Version")
	void Server_InitializeAbilityMulti(TArray<TSubclassOf<UGameplayAbility>> AbilitiesToAcquire, int32 AbilityLevel);

	//Get Ability Info from a GA Class, Ability Cooldown and Ability Costs
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	FGameplayAbilityInfo GetAbilityInfoFromAbilityClass(TSubclassOf<UGameplayAbility> AbilityClass, int32 AtAbilityLevel);

	//Server/Client Functions, not exposed to Blueprints
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	//********Ability Modifier Functions********
	//These are the Generic Versions that can be called either from Server or Client
	//May not work if triggered from Client in certain situations

	//Remove Abilities with Tag
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void RemoveAbilityWithTags(FGameplayTagContainer TagContainer);

	//Change Ability Level with Tag
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void ChangeAbilityLevelWithTags(FGameplayTagContainer TagContainer, int32 NewLevel);

	//Cancel Ability With Tag
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void CancelAbilityWithTags(FGameplayTagContainer WithTags, FGameplayTagContainer WithoutTags);

	//Add Loose Gameplay Tag
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void AddLooseGameplayTag(FGameplayTag TagToAdd);

	//Remove Loose Gameplay Tag
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void RemoveLooseGameplayTags(FGameplayTag TagsToRemove);

	//********Ability Modifier Functions SERVER ONLY********
	//These are the Server Only Versions that can be called either from Server or Client
	//They will always be called as server even when called from a Client event

	//Remove Abilities with Tag SERVER
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "GASGameplayAbility|Server Version")
	void Server_RemoveAbilityWithTags(FGameplayTagContainer TagContainer);

	//Change Ability Level with Tag SERVER
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "GASGameplayAbility|Server Version")
	void Server_ChangeAbilityLevelWithTags(FGameplayTagContainer TagContainer, int32 NewLevel);

	//Cancel Ability With Tag SERVER
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "GASGameplayAbility|Server Version")
	void Server_CancelAbilityWithTags(FGameplayTagContainer WithTags, FGameplayTagContainer WithoutTags);

	//Add Loose Gameplay Tag SERVER
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "GASGameplayAbility|Server Version")
	void Server_AddLooseGameplayTag(FGameplayTag TagToAdd);

	//Remove Loose Gameplay Tag SERVER
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "GASGameplayAbility|Server Version")
	void Server_RemoveLooseGameplayTags(FGameplayTag TagsToRemove);

	//==PATTERN==
	//Native functions for Attribute Change Delagates. Using UFUNCTION() to expose to BP Side Link

	UFUNCTION()
	virtual void OnHealthChangedNative(float Health, int32 StackCount);
	UFUNCTION()
	virtual void OnManaChangedNative(float Mana, int32 StackCount);
	UFUNCTION()
	virtual void OnAttackDamageChangedNative(float AttackDamage, int32 StackCount);
	UFUNCTION()
	virtual void OnAttackSpeedChangedNative(float AttackSpeed, int32 StackCount);
	UFUNCTION()
	virtual void OnBaseAttackSpeedMultiplierChangedNative(float BaseAttackSpeedMultiplier, int32 StackCount);
	UFUNCTION()
	virtual void OnMovementSpeedChangedNative(float MovementSpeed, int32 StackCount);
	UFUNCTION()
	virtual void OnArmorChangedNative(float Armor, int32 StackCount);
	UFUNCTION()
	virtual void OnMagicResistanceChangedNative(float MagicResistance, int32 StackCount);
	UFUNCTION()
	virtual void OnStrengthChangedNative(float Strength, int32 StackCount);
	UFUNCTION()
	virtual void OnAgilityChangedNative(float Agility, int32 StackCount);
	UFUNCTION()
	virtual void OnIntelligenceChangedNative(float Intelligence, int32 StackCount);
	UFUNCTION()
	virtual void OnAbilityPowerChangedNative(float AbilityPower, int32 StackCount);
	UFUNCTION()
	virtual void OnAttackRangeChangedNative(float AttackRange, int32 StackCount);
	UFUNCTION()
	virtual void OnCastTimeChangedNative(float CastTime, int32 StackCount);
	UFUNCTION()
	virtual void OnCooldownChangedNative(float Cooldown, int32 StackCount);
	UFUNCTION()
	virtual void OnCooldownReductionChangedNative(float CooldownReduction, int32 StackCount);
	UFUNCTION()
	virtual void OnAbilityScalingChangedNative(float AbilityScaling, int32 StackCount);
	UFUNCTION()
	virtual void OnBaseDamageChangedNative(float BaseDamage, int32 StackCount);
	UFUNCTION()
	virtual void OnScalingCoefficientChangedNative(float ScalingCoefficient, int32 StackCount);
	UFUNCTION()
	virtual void OnItemNameChangedNative(float ItemName, int32 StackCount);
	UFUNCTION()
	virtual void OnItemCostChangedNative(float ItemCost, int32 StackCount);
	UFUNCTION()
	virtual void OnItemTypeChangedNative(float ItemType, int32 StackCount);
	UFUNCTION()
	virtual void OnItemDescriptionChangedNative(float ItemDescription, int32 StackCount);
	UFUNCTION()
	virtual void OnItemEffectChangedNative(float ItemEffect, int32 StackCount);
	UFUNCTION()
	virtual void OnItemIconPathChangedNative(float ItemIconPath, int32 StackCount);
	UFUNCTION()
	virtual void OnUIWindowPositionChangedNative(float UIWindowPosition, int32 StackCount);
	UFUNCTION()
	virtual void OnUIWindowSizeChangedNative(float UIWindowSize, int32 StackCount);
	UFUNCTION()
	virtual void OnUIButtonClickEventChangedNative(float UIButtonClickEvent, int32 StackCount);
	UFUNCTION()
	virtual void OnUIProgressBarValueChangedNative(float UIProgressBarValue, int32 StackCount);
	UFUNCTION()
	virtual void OnUITextAlignmentChangedNative(float UITextAlignment, int32 StackCount);
	UFUNCTION()
	virtual void OnUIColorChangedNative(float UIColor, int32 StackCount);
	UFUNCTION()
	virtual void OnOnHeroDeathChangedNative(float OnHeroDeath, int32 StackCount);
	UFUNCTION()
	virtual void OnOnAbilityCastChangedNative(float OnAbilityCast, int32 StackCount);
	UFUNCTION()
	virtual void OnOnItemPickedUpChangedNative(float OnItemPickedUp, int32 StackCount);
	UFUNCTION()
	virtual void OnOnTurretDestroyedChangedNative(float OnTurretDestroyed, int32 StackCount);
	UFUNCTION()
	virtual void OnOnGoldEarnedChangedNative(float OnGoldEarned, int32 StackCount);
	UFUNCTION()
	virtual void OnMapSizeChangedNative(float MapSize, int32 StackCount);
	UFUNCTION()
	virtual void OnSpawnPositionChangedNative(float SpawnPosition, int32 StackCount);
	UFUNCTION()
	virtual void OnLanePositionsChangedNative(float LanePositions, int32 StackCount);
	UFUNCTION()
	virtual void OnJungleCampLocationsChangedNative(float JungleCampLocations, int32 StackCount);
	UFUNCTION()
	virtual void OnPlayerLevelChangedNative(float PlayerLevel, int32 StackCount);
	UFUNCTION()
	virtual void OnPlayerExperienceChangedNative(float PlayerExperience, int32 StackCount);
	UFUNCTION()
	virtual void OnPlayerGoldChangedNative(float PlayerGold, int32 StackCount);
	UFUNCTION()
	virtual void OnPlayerKillsChangedNative(float PlayerKills, int32 StackCount);
	UFUNCTION()
	virtual void OnPlayerDeathsChangedNative(float PlayerDeaths, int32 StackCount);
	UFUNCTION()
	virtual void OnPlayerAssistsChangedNative(float PlayerAssists, int32 StackCount);
	UFUNCTION()
	virtual void OnPlayerKillDeathRatioChangedNative(float PlayerKillDeathRatio, int32 StackCount);
	UFUNCTION()
	virtual void OnTeamScoreChangedNative(float TeamScore, int32 StackCount);
	UFUNCTION()
	virtual void OnTeamObjectiveCountChangedNative(float TeamObjectiveCount, int32 StackCount);
	UFUNCTION()
	virtual void OnTeamTowerCountChangedNative(float TeamTowerCount, int32 StackCount);
	UFUNCTION()
	virtual void OnTeamJungleCampCountChangedNative(float TeamJungleCampCount, int32 StackCount);
	UFUNCTION()
	virtual void OnDurationChangedNative(float Duration, int32 StackCount);
	UFUNCTION()
	virtual void OnTickIntervalChangedNative(float TickInterval, int32 StackCount);
	UFUNCTION()
	virtual void OnOnEffectApplyChangedNative(float OnEffectApply, int32 StackCount);
	UFUNCTION()
	virtual void OnOnEffectRemoveChangedNative(float OnEffectRemove, int32 StackCount);
	UFUNCTION()
	virtual void OnStacksChangedNative(float Stacks, int32 StackCount);
	UFUNCTION()
	virtual void OnMaxStacksChangedNative(float MaxStacks, int32 StackCount);
	UFUNCTION()
	virtual void OnGameTimeChangedNative(float GameTime, int32 StackCount);
	UFUNCTION()
	virtual void OnMatchDurationChangedNative(float MatchDuration, int32 StackCount);
	UFUNCTION()
	virtual void OnPauseStateChangedNative(float PauseState, int32 StackCount);
	UFUNCTION()
	virtual void OnGameModeChangedNative(float GameMode, int32 StackCount);
	UFUNCTION()
	virtual void OnGameStateChangedNative(float GameState, int32 StackCount);


	//******Event that bind to native events and are implemented in BPs********

	//Event Trigger On Health Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnHealthChange(float Health, int32 StackCount);
	//Event Trigger On Mana Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnManaChange(float Mana, int32 StackCount);
	//Event Trigger On AttackDamage Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnAttackDamageChange(float AttackDamage, int32 StackCount);
	//Event Trigger On AttackSpeed Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnAttackSpeedChange(float AttackSpeed, int32 StackCount);
	//Event Trigger On BaseAttackSpeedMultiplier Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnBaseAttackSpeedMultiplierChange(float BaseAttackSpeedMultiplier, int32 StackCount);
	//Event Trigger On MovementSpeed Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnMovementSpeedChange(float MovementSpeed, int32 StackCount);
	//Event Trigger On Armor Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnArmorChange(float Armor, int32 StackCount);
	//Event Trigger On MagicResistance Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnMagicResistanceChange(float MagicResistance, int32 StackCount);
	//Event Trigger On Strength Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnStrengthChange(float Strength, int32 StackCount);
	//Event Trigger On Agility Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnAgilityChange(float Agility, int32 StackCount);
	//Event Trigger On Intelligence Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnIntelligenceChange(float Intelligence, int32 StackCount);
	//Event Trigger On AbilityPower Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnAbilityPowerChange(float AbilityPower, int32 StackCount);
	//Event Trigger On AttackRange Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnAttackRangeChange(float AttackRange, int32 StackCount);
	//Event Trigger On CastTime Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnCastTimeChange(float CastTime, int32 StackCount);
	//Event Trigger On Cooldown Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnCooldownChange(float Cooldown, int32 StackCount);
	//Event Trigger On CooldownReduction Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnCooldownReductionChange(float CooldownReduction, int32 StackCount);
	//Event Trigger On AbilityScaling Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnAbilityScalingChange(float AbilityScaling, int32 StackCount);
	//Event Trigger On BaseDamage Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnBaseDamageChange(float BaseDamage, int32 StackCount);
	//Event Trigger On ScalingCoefficient Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnScalingCoefficientChange(float ScalingCoefficient, int32 StackCount);
	//Event Trigger On ItemName Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnItemNameChange(float ItemName, int32 StackCount);
	//Event Trigger On ItemCost Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnItemCostChange(float ItemCost, int32 StackCount);
	//Event Trigger On ItemType Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnItemTypeChange(float ItemType, int32 StackCount);
	//Event Trigger On ItemDescription Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnItemDescriptionChange(float ItemDescription, int32 StackCount);
	//Event Trigger On ItemEffect Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnItemEffectChange(float ItemEffect, int32 StackCount);
	//Event Trigger On ItemIconPath Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnItemIconPathChange(float ItemIconPath, int32 StackCount);
	//Event Trigger On UIWindowPosition Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnUIWindowPositionChange(float UIWindowPosition, int32 StackCount);
	//Event Trigger On UIWindowSize Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnUIWindowSizeChange(float UIWindowSize, int32 StackCount);
	//Event Trigger On UIButtonClickEvent Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnUIButtonClickEventChange(float UIButtonClickEvent, int32 StackCount);
	//Event Trigger On UIProgressBarValue Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnUIProgressBarValueChange(float UIProgressBarValue, int32 StackCount);
	//Event Trigger On UITextAlignment Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnUITextAlignmentChange(float UITextAlignment, int32 StackCount);
	//Event Trigger On UIColor Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnUIColorChange(float UIColor, int32 StackCount);
	//Event Trigger On OnHeroDeath Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnOnHeroDeathChange(float OnHeroDeath, int32 StackCount);
	//Event Trigger On OnAbilityCast Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnOnAbilityCastChange(float OnAbilityCast, int32 StackCount);
	//Event Trigger On OnItemPickedUp Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnOnItemPickedUpChange(float OnItemPickedUp, int32 StackCount);
	//Event Trigger On OnTurretDestroyed Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnOnTurretDestroyedChange(float OnTurretDestroyed, int32 StackCount);
	//Event Trigger On OnGoldEarned Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnOnGoldEarnedChange(float OnGoldEarned, int32 StackCount);
	//Event Trigger On MapSize Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnMapSizeChange(float MapSize, int32 StackCount);
	//Event Trigger On SpawnPosition Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnSpawnPositionChange(float SpawnPosition, int32 StackCount);
	//Event Trigger On LanePositions Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnLanePositionsChange(float LanePositions, int32 StackCount);
	//Event Trigger On JungleCampLocations Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnJungleCampLocationsChange(float JungleCampLocations, int32 StackCount);
	//Event Trigger On PlayerLevel Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnPlayerLevelChange(float PlayerLevel, int32 StackCount);
	//Event Trigger On PlayerExperience Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnPlayerExperienceChange(float PlayerExperience, int32 StackCount);
	//Event Trigger On PlayerGold Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnPlayerGoldChange(float PlayerGold, int32 StackCount);
	//Event Trigger On PlayerKills Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnPlayerKillsChange(float PlayerKills, int32 StackCount);
	//Event Trigger On PlayerDeaths Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnPlayerDeathsChange(float PlayerDeaths, int32 StackCount);
	//Event Trigger On PlayerAssists Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnPlayerAssistsChange(float PlayerAssists, int32 StackCount);
	//Event Trigger On PlayerKillDeathRatio Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnPlayerKillDeathRatioChange(float PlayerKillDeathRatio, int32 StackCount);
	//Event Trigger On TeamScore Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnTeamScoreChange(float TeamScore, int32 StackCount);
	//Event Trigger On TeamObjectiveCount Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnTeamObjectiveCountChange(float TeamObjectiveCount, int32 StackCount);
	//Event Trigger On TeamTowerCount Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnTeamTowerCountChange(float TeamTowerCount, int32 StackCount);
	//Event Trigger On TeamJungleCampCount Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnTeamJungleCampCountChange(float TeamJungleCampCount, int32 StackCount);
	//Event Trigger On Duration Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnDurationChange(float Duration, int32 StackCount);
	//Event Trigger On TickInterval Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnTickIntervalChange(float TickInterval, int32 StackCount);
	//Event Trigger On OnEffectApply Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnOnEffectApplyChange(float OnEffectApply, int32 StackCount);
	//Event Trigger On OnEffectRemove Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnOnEffectRemoveChange(float OnEffectRemove, int32 StackCount);
	//Event Trigger On Stacks Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnStacksChange(float Stacks, int32 StackCount);
	//Event Trigger On MaxStacks Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnMaxStacksChange(float MaxStacks, int32 StackCount);
	//Event Trigger On GameTime Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnGameTimeChange(float GameTime, int32 StackCount);
	//Event Trigger On MatchDuration Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnMatchDurationChange(float MatchDuration, int32 StackCount);
	//Event Trigger On PauseState Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnPauseStateChange(float PauseState, int32 StackCount);
	//Event Trigger On GameMode Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnGameModeChange(float GameMode, int32 StackCount);
	//Event Trigger On GameState Change
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGameplayAbility")
	void OnGameStateChange(float GameState, int32 StackCount);


	//*******Ability Values Getter Functions**********

	//Getter for Health Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetHealthValues(float& Health, float& MaxHealth);
	//Getter for Mana Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetManaValues(float& Mana, float& MaxMana);
	//Getter for AttackDamage Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetAttackDamageValue(float& AttackDamage);
	//Getter for AttackSpeed Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetAttackSpeedValue(float& AttackSpeed);
	//Getter for BaseAttackSpeedMultiplier Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetBaseAttackSpeedMultiplierValue(float& BaseAttackSpeedMultiplier);
	//Getter for MovementSpeed Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetMovementSpeedValue(float& MovementSpeed);
	//Getter for Armor Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetArmorValues(float& Armor, float& MaxArmor);
	//Getter for MagicResistance Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetMagicResistanceValues(float& MagicResistance, float& MaxMagicResistance);
	//Getter for Strength Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetStrengthValue(float& Strength);
	//Getter for Agility Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetAgilityValue(float& Agility);
	//Getter for Intelligence Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetIntelligenceValue(float& Intelligence);
	//Getter for AbilityPower Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetAbilityPowerValue(float& AbilityPower);
	//Getter for AttackRange Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetAttackRangeValue(float& AttackRange);
	//Getter for CastTime Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetCastTimeValue(float& CastTime);
	//Getter for Cooldown Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetCooldownValue(float& Cooldown);
	//Getter for CooldownReduction Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetCooldownReductionValues(float& CooldownReduction, float& MaxCooldownReduction);
	//Getter for AbilityScaling Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetAbilityScalingValue(float& AbilityScaling);
	//Getter for BaseDamage Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetBaseDamageValue(float& BaseDamage);
	//Getter for ScalingCoefficient Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetScalingCoefficientValue(float& ScalingCoefficient);
	//Getter for ItemName Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetItemNameValue(float& ItemName);
	//Getter for ItemCost Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetItemCostValues(float& ItemCost, float& MaxItemCost);
	//Getter for ItemType Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetItemTypeValue(float& ItemType);
	//Getter for ItemDescription Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetItemDescriptionValue(float& ItemDescription);
	//Getter for ItemEffect Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetItemEffectValues(float& ItemEffect, float& MaxItemEffect);
	//Getter for ItemIconPath Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetItemIconPathValue(float& ItemIconPath);
	//Getter for UIWindowPosition Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetUIWindowPositionValues(float& UIWindowPosition, float& MaxUIWindowPosition);
	//Getter for UIWindowSize Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetUIWindowSizeValue(float& UIWindowSize);
	//Getter for UIButtonClickEvent Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetUIButtonClickEventValue(float& UIButtonClickEvent);
	//Getter for UIProgressBarValue Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetUIProgressBarValueValues(float& UIProgressBarValue, float& MaxUIProgressBarValue);
	//Getter for UITextAlignment Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetUITextAlignmentValue(float& UITextAlignment);
	//Getter for UIColor Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetUIColorValues(float& UIColor, float& MaxUIColor);
	//Getter for OnHeroDeath Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetOnHeroDeathValue(float& OnHeroDeath);
	//Getter for OnAbilityCast Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetOnAbilityCastValue(float& OnAbilityCast);
	//Getter for OnItemPickedUp Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetOnItemPickedUpValue(float& OnItemPickedUp);
	//Getter for OnTurretDestroyed Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetOnTurretDestroyedValue(float& OnTurretDestroyed);
	//Getter for OnGoldEarned Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetOnGoldEarnedValue(float& OnGoldEarned);
	//Getter for MapSize Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetMapSizeValues(float& MapSize, float& MaxMapSize);
	//Getter for SpawnPosition Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetSpawnPositionValue(float& SpawnPosition);
	//Getter for LanePositions Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetLanePositionsValue(float& LanePositions);
	//Getter for JungleCampLocations Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetJungleCampLocationsValue(float& JungleCampLocations);
	//Getter for PlayerLevel Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetPlayerLevelValues(float& PlayerLevel, float& MaxPlayerLevel);
	//Getter for PlayerExperience Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetPlayerExperienceValues(float& PlayerExperience, float& MaxPlayerExperience);
	//Getter for PlayerGold Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetPlayerGoldValues(float& PlayerGold, float& MaxPlayerGold);
	//Getter for PlayerKills Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetPlayerKillsValues(float& PlayerKills, float& MaxPlayerKills);
	//Getter for PlayerDeaths Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetPlayerDeathsValues(float& PlayerDeaths, float& MaxPlayerDeaths);
	//Getter for PlayerAssists Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetPlayerAssistsValues(float& PlayerAssists, float& MaxPlayerAssists);
	//Getter for PlayerKillDeathRatio Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetPlayerKillDeathRatioValue(float& PlayerKillDeathRatio);
	//Getter for TeamScore Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetTeamScoreValues(float& TeamScore, float& MaxTeamScore);
	//Getter for TeamObjectiveCount Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetTeamObjectiveCountValues(float& TeamObjectiveCount, float& MaxTeamObjectiveCount);
	//Getter for TeamTowerCount Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetTeamTowerCountValues(float& TeamTowerCount, float& MaxTeamTowerCount);
	//Getter for TeamJungleCampCount Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetTeamJungleCampCountValues(float& TeamJungleCampCount, float& MaxTeamJungleCampCount);
	//Getter for Duration Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetDurationValue(float& Duration);
	//Getter for TickInterval Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetTickIntervalValue(float& TickInterval);
	//Getter for OnEffectApply Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetOnEffectApplyValue(float& OnEffectApply);
	//Getter for OnEffectRemove Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetOnEffectRemoveValue(float& OnEffectRemove);
	//Getter for Stacks Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetStacksValue(float& Stacks);
	//Getter for MaxStacks Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetMaxStacksValue(float& MaxStacks);
	//Getter for GameTime Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetGameTimeValue(float& GameTime);
	//Getter for MatchDuration Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetMatchDurationValue(float& MatchDuration);
	//Getter for PauseState Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetPauseStateValue(float& PauseState);
	//Getter for GameMode Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetGameModeValue(float& GameMode);
	//Getter for GameState Values
	UFUNCTION(BlueprintPure, Category = "GASGameplayAbility")
	void GetGameStateValue(float& GameState);


	//*******Ability Values Setter Functions**********

	//Setter for Health Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetHealthValues(float NewHealth, float NewMaxHealth);
	//Setter for Mana Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetManaValues(float NewMana, float NewMaxMana);
	//Setter for AttackDamage Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetAttackDamageValue(float NewAttackDamage);
	//Setter for AttackSpeed Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetAttackSpeedValue(float NewAttackSpeed);
	//Setter for BaseAttackSpeedMultiplier Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetBaseAttackSpeedMultiplierValue(float NewBaseAttackSpeedMultiplier);
	//Setter for MovementSpeed Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetMovementSpeedValue(float NewMovementSpeed);
	//Setter for Armor Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetArmorValues(float NewArmor, float NewMaxArmor);
	//Setter for MagicResistance Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetMagicResistanceValues(float NewMagicResistance, float NewMaxMagicResistance);
	//Setter for Strength Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetStrengthValue(float NewStrength);
	//Setter for Agility Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetAgilityValue(float NewAgility);
	//Setter for Intelligence Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetIntelligenceValue(float NewIntelligence);
	//Setter for AbilityPower Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetAbilityPowerValue(float NewAbilityPower);
	//Setter for AttackRange Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetAttackRangeValue(float NewAttackRange);
	//Setter for CastTime Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetCastTimeValue(float NewCastTime);
	//Setter for Cooldown Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetCooldownValue(float NewCooldown);
	//Setter for CooldownReduction Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetCooldownReductionValues(float NewCooldownReduction, float NewMaxCooldownReduction);
	//Setter for AbilityScaling Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetAbilityScalingValue(float NewAbilityScaling);
	//Setter for BaseDamage Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetBaseDamageValue(float NewBaseDamage);
	//Setter for ScalingCoefficient Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetScalingCoefficientValue(float NewScalingCoefficient);
	//Setter for ItemName Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetItemNameValue(float NewItemName);
	//Setter for ItemCost Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetItemCostValues(float NewItemCost, float NewMaxItemCost);
	//Setter for ItemType Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetItemTypeValue(float NewItemType);
	//Setter for ItemDescription Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetItemDescriptionValue(float NewItemDescription);
	//Setter for ItemEffect Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetItemEffectValues(float NewItemEffect, float NewMaxItemEffect);
	//Setter for ItemIconPath Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetItemIconPathValue(float NewItemIconPath);
	//Setter for UIWindowPosition Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetUIWindowPositionValues(float NewUIWindowPosition, float NewMaxUIWindowPosition);
	//Setter for UIWindowSize Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetUIWindowSizeValue(float NewUIWindowSize);
	//Setter for UIButtonClickEvent Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetUIButtonClickEventValue(float NewUIButtonClickEvent);
	//Setter for UIProgressBarValue Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetUIProgressBarValueValues(float NewUIProgressBarValue, float NewMaxUIProgressBarValue);
	//Setter for UITextAlignment Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetUITextAlignmentValue(float NewUITextAlignment);
	//Setter for UIColor Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetUIColorValues(float NewUIColor, float NewMaxUIColor);
	//Setter for OnHeroDeath Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetOnHeroDeathValue(float NewOnHeroDeath);
	//Setter for OnAbilityCast Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetOnAbilityCastValue(float NewOnAbilityCast);
	//Setter for OnItemPickedUp Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetOnItemPickedUpValue(float NewOnItemPickedUp);
	//Setter for OnTurretDestroyed Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetOnTurretDestroyedValue(float NewOnTurretDestroyed);
	//Setter for OnGoldEarned Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetOnGoldEarnedValue(float NewOnGoldEarned);
	//Setter for MapSize Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetMapSizeValues(float NewMapSize, float NewMaxMapSize);
	//Setter for SpawnPosition Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetSpawnPositionValue(float NewSpawnPosition);
	//Setter for LanePositions Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetLanePositionsValue(float NewLanePositions);
	//Setter for JungleCampLocations Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetJungleCampLocationsValue(float NewJungleCampLocations);
	//Setter for PlayerLevel Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetPlayerLevelValues(float NewPlayerLevel, float NewMaxPlayerLevel);
	//Setter for PlayerExperience Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetPlayerExperienceValues(float NewPlayerExperience, float NewMaxPlayerExperience);
	//Setter for PlayerGold Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetPlayerGoldValues(float NewPlayerGold, float NewMaxPlayerGold);
	//Setter for PlayerKills Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetPlayerKillsValues(float NewPlayerKills, float NewMaxPlayerKills);
	//Setter for PlayerDeaths Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetPlayerDeathsValues(float NewPlayerDeaths, float NewMaxPlayerDeaths);
	//Setter for PlayerAssists Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetPlayerAssistsValues(float NewPlayerAssists, float NewMaxPlayerAssists);
	//Setter for PlayerKillDeathRatio Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetPlayerKillDeathRatioValue(float NewPlayerKillDeathRatio);
	//Setter for TeamScore Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetTeamScoreValues(float NewTeamScore, float NewMaxTeamScore);
	//Setter for TeamObjectiveCount Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetTeamObjectiveCountValues(float NewTeamObjectiveCount, float NewMaxTeamObjectiveCount);
	//Setter for TeamTowerCount Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetTeamTowerCountValues(float NewTeamTowerCount, float NewMaxTeamTowerCount);
	//Setter for TeamJungleCampCount Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetTeamJungleCampCountValues(float NewTeamJungleCampCount, float NewMaxTeamJungleCampCount);
	//Setter for Duration Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetDurationValue(float NewDuration);
	//Setter for TickInterval Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetTickIntervalValue(float NewTickInterval);
	//Setter for OnEffectApply Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetOnEffectApplyValue(float NewOnEffectApply);
	//Setter for OnEffectRemove Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetOnEffectRemoveValue(float NewOnEffectRemove);
	//Setter for Stacks Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetStacksValue(float NewStacks);
	//Setter for MaxStacks Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetMaxStacksValue(float NewMaxStacks);
	//Setter for GameTime Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetGameTimeValue(float NewGameTime);
	//Setter for MatchDuration Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetMatchDurationValue(float NewMatchDuration);
	//Setter for PauseState Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetPauseStateValue(float NewPauseState);
	//Setter for GameMode Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetGameModeValue(float NewGameMode);
	//Setter for GameState Values
	UFUNCTION(BlueprintCallable, Category = "GASGameplayAbility")
	void SetGameStateValue(float NewGameState);


};
