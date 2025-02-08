// Fill out your copyright notice in the Description page of Project Settings.


#include "GASCharacter.h"
#include "GASAttributeSet.h"
#include "GASAbilitySystemComponent.h"

// Sets default values
AGASCharacter::AGASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UGASAbilitySystemComponent>("AbilitySystemComp");
	AbilitySystemComponent->SetIsReplicated(true);
	//Options for SetReplicationMode available are Full, Minimal, Mixed (Mixed is used for easier implementation of Gameplay Cues for replication via Gameplay Effect)
	//For handling Gameplay Cues locally, See GASAbilitySystemComponent.h file's comments

//==PATTERN==


}


// Called when the game starts or when spawned
void AGASCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (AbilitySystemComponent)
	{
		if (AbilitySystemComponent->DefaultStartingData.Num() > 0 && AbilitySystemComponent->DefaultStartingData[0].Attributes != NULL && AbilitySystemComponent->DefaultStartingData[0].DefaultStartingTable != NULL)
		{
			//Link Attribute Set to Ability System Component
			AttributeSetVar = AbilitySystemComponent->GetSet<UGASAttributeSet>();

			//Bindings for Attribute Change Delegates
			const_cast<UGASAttributeSet*>(AttributeSetVar)->HealthChangeDelegate.AddDynamic(this, &AGASCharacter::OnHealthChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->ManaChangeDelegate.AddDynamic(this, &AGASCharacter::OnManaChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->AttackDamageChangeDelegate.AddDynamic(this, &AGASCharacter::OnAttackDamageChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->AttackSpeedChangeDelegate.AddDynamic(this, &AGASCharacter::OnAttackSpeedChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->BaseAttackSpeedMultiplierChangeDelegate.AddDynamic(this, &AGASCharacter::OnBaseAttackSpeedMultiplierChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->MovementSpeedChangeDelegate.AddDynamic(this, &AGASCharacter::OnMovementSpeedChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->ArmorChangeDelegate.AddDynamic(this, &AGASCharacter::OnArmorChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->MagicResistanceChangeDelegate.AddDynamic(this, &AGASCharacter::OnMagicResistanceChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->StrengthChangeDelegate.AddDynamic(this, &AGASCharacter::OnStrengthChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->AgilityChangeDelegate.AddDynamic(this, &AGASCharacter::OnAgilityChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->IntelligenceChangeDelegate.AddDynamic(this, &AGASCharacter::OnIntelligenceChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->AbilityPowerChangeDelegate.AddDynamic(this, &AGASCharacter::OnAbilityPowerChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->AttackRangeChangeDelegate.AddDynamic(this, &AGASCharacter::OnAttackRangeChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->CastTimeChangeDelegate.AddDynamic(this, &AGASCharacter::OnCastTimeChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->CooldownChangeDelegate.AddDynamic(this, &AGASCharacter::OnCooldownChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->CooldownReductionChangeDelegate.AddDynamic(this, &AGASCharacter::OnCooldownReductionChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->AbilityScalingChangeDelegate.AddDynamic(this, &AGASCharacter::OnAbilityScalingChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->BaseDamageChangeDelegate.AddDynamic(this, &AGASCharacter::OnBaseDamageChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->ScalingCoefficientChangeDelegate.AddDynamic(this, &AGASCharacter::OnScalingCoefficientChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->ItemNameChangeDelegate.AddDynamic(this, &AGASCharacter::OnItemNameChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->ItemCostChangeDelegate.AddDynamic(this, &AGASCharacter::OnItemCostChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->ItemTypeChangeDelegate.AddDynamic(this, &AGASCharacter::OnItemTypeChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->ItemDescriptionChangeDelegate.AddDynamic(this, &AGASCharacter::OnItemDescriptionChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->ItemEffectChangeDelegate.AddDynamic(this, &AGASCharacter::OnItemEffectChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->ItemIconPathChangeDelegate.AddDynamic(this, &AGASCharacter::OnItemIconPathChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->UIWindowPositionChangeDelegate.AddDynamic(this, &AGASCharacter::OnUIWindowPositionChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->UIWindowSizeChangeDelegate.AddDynamic(this, &AGASCharacter::OnUIWindowSizeChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->UIButtonClickEventChangeDelegate.AddDynamic(this, &AGASCharacter::OnUIButtonClickEventChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->UIProgressBarValueChangeDelegate.AddDynamic(this, &AGASCharacter::OnUIProgressBarValueChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->UITextAlignmentChangeDelegate.AddDynamic(this, &AGASCharacter::OnUITextAlignmentChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->UIColorChangeDelegate.AddDynamic(this, &AGASCharacter::OnUIColorChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->OnHeroDeathChangeDelegate.AddDynamic(this, &AGASCharacter::OnOnHeroDeathChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->OnAbilityCastChangeDelegate.AddDynamic(this, &AGASCharacter::OnOnAbilityCastChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->OnItemPickedUpChangeDelegate.AddDynamic(this, &AGASCharacter::OnOnItemPickedUpChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->OnTurretDestroyedChangeDelegate.AddDynamic(this, &AGASCharacter::OnOnTurretDestroyedChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->OnGoldEarnedChangeDelegate.AddDynamic(this, &AGASCharacter::OnOnGoldEarnedChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->MapSizeChangeDelegate.AddDynamic(this, &AGASCharacter::OnMapSizeChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->SpawnPositionChangeDelegate.AddDynamic(this, &AGASCharacter::OnSpawnPositionChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->LanePositionsChangeDelegate.AddDynamic(this, &AGASCharacter::OnLanePositionsChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->JungleCampLocationsChangeDelegate.AddDynamic(this, &AGASCharacter::OnJungleCampLocationsChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->PlayerLevelChangeDelegate.AddDynamic(this, &AGASCharacter::OnPlayerLevelChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->PlayerExperienceChangeDelegate.AddDynamic(this, &AGASCharacter::OnPlayerExperienceChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->PlayerGoldChangeDelegate.AddDynamic(this, &AGASCharacter::OnPlayerGoldChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->PlayerKillsChangeDelegate.AddDynamic(this, &AGASCharacter::OnPlayerKillsChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->PlayerDeathsChangeDelegate.AddDynamic(this, &AGASCharacter::OnPlayerDeathsChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->PlayerAssistsChangeDelegate.AddDynamic(this, &AGASCharacter::OnPlayerAssistsChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->PlayerKillDeathRatioChangeDelegate.AddDynamic(this, &AGASCharacter::OnPlayerKillDeathRatioChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->TeamScoreChangeDelegate.AddDynamic(this, &AGASCharacter::OnTeamScoreChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->TeamObjectiveCountChangeDelegate.AddDynamic(this, &AGASCharacter::OnTeamObjectiveCountChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->TeamTowerCountChangeDelegate.AddDynamic(this, &AGASCharacter::OnTeamTowerCountChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->TeamJungleCampCountChangeDelegate.AddDynamic(this, &AGASCharacter::OnTeamJungleCampCountChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->DurationChangeDelegate.AddDynamic(this, &AGASCharacter::OnDurationChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->TickIntervalChangeDelegate.AddDynamic(this, &AGASCharacter::OnTickIntervalChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->OnEffectApplyChangeDelegate.AddDynamic(this, &AGASCharacter::OnOnEffectApplyChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->OnEffectRemoveChangeDelegate.AddDynamic(this, &AGASCharacter::OnOnEffectRemoveChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->StacksChangeDelegate.AddDynamic(this, &AGASCharacter::OnStacksChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->MaxStacksChangeDelegate.AddDynamic(this, &AGASCharacter::OnMaxStacksChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->GameTimeChangeDelegate.AddDynamic(this, &AGASCharacter::OnGameTimeChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->MatchDurationChangeDelegate.AddDynamic(this, &AGASCharacter::OnMatchDurationChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->PauseStateChangeDelegate.AddDynamic(this, &AGASCharacter::OnPauseStateChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->GameModeChangeDelegate.AddDynamic(this, &AGASCharacter::OnGameModeChangedNative);
			const_cast<UGASAttributeSet*>(AttributeSetVar)->GameStateChangeDelegate.AddDynamic(this, &AGASCharacter::OnGameStateChangedNative);
		}
	}
}

//==PATTERNSTART==

// Called every frame
void AGASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


UAbilitySystemComponent* AGASCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AGASCharacter::InitializeAbility(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel)
{
	if (HasAuthority() && AbilitySystemComponent)
	{
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AbilityToGet, AbilityLevel, 0));
	}
}

void AGASCharacter::InitializeAbilityMulti(TArray<TSubclassOf<UGameplayAbility>> AbilitiesToAcquire, int32 AbilityLevel)
{
	for (TSubclassOf<UGameplayAbility> AbilityItem : AbilitiesToAcquire)
	{
		InitializeAbility(AbilityItem, AbilityLevel);
	}
}

void AGASCharacter::Server_InitializeAbility_Implementation(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel)
{
	if (HasAuthority() && AbilitySystemComponent)
	{
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(AbilityToGet, AbilityLevel, 0));
	}
}

void AGASCharacter::Server_InitializeAbilityMulti(TArray<TSubclassOf<UGameplayAbility>> AbilitiesToAcquire, int32 AbilityLevel)
{
	for (TSubclassOf<UGameplayAbility> AbilityItem : AbilitiesToAcquire)
	{
		Server_InitializeAbility(AbilityItem, AbilityLevel);
	}
}

FGameplayAbilityInfo AGASCharacter::GetAbilityInfoFromAbilityClass(TSubclassOf<UGameplayAbility> AbilityClass, int32 AtAbilityLevel)
{
	//Create a default GA Class Object to retrieve info
	UGameplayAbility* AbilityCDO = AbilityClass.GetDefaultObject();
	
	if (AbilityCDO)
	{
		//Store Cost and Cooldown GE Classes in Variables
		UGameplayEffect* CooldownEffect = AbilityCDO->GetCooldownGameplayEffect();
		UGameplayEffect* CostEffect = AbilityCDO->GetCostGameplayEffect();
		
		//Proceed only if we have valid Cost and Cooldown Classes
		if (CostEffect && CooldownEffect)
		{
			//Create variables to store info
			float CooldownDuration = 0;
			TArray<float> Cost;
			TArray<FString> CostName;
			//Theses variables are needed as temp variables to add to TArray
			float SingleCost = 0.0f;
			FString SingleCostName;

			//Initialize the TArray as Empty Arrays
			Cost.Empty();
			CostName.Empty();

			//Get the Cooldown Duration Magnitude from GE
			CooldownEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(AtAbilityLevel, CooldownDuration);

			//If we have atleast one modifier for Cost GE (I'm only dealing with Modifiers, not other types like Exec Calculations etc.)
			if (CostEffect->Modifiers.Num() > 0)
			{
				//Iterate over Modifier Array and add to TArray
				for (auto EffectInfo : CostEffect->Modifiers)
				{
					EffectInfo.ModifierMagnitude.GetStaticMagnitudeIfPossible(AtAbilityLevel, SingleCost);
					FGameplayAttribute CostAttribute = EffectInfo.Attribute;
					SingleCostName = CostAttribute.AttributeName;
					Cost.Add(SingleCost);
					CostName.Add(SingleCostName);

				}
			}
			return FGameplayAbilityInfo(CooldownDuration, Cost, CostName);
		}
		else
		{
			//Return Empty if Invalid
			return FGameplayAbilityInfo();
		}
	}
	else
	{
		//Return Empty if Invalid
		return FGameplayAbilityInfo();
	}
}

void AGASCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	InitializeAbilityMulti(InitialAbilities, 0);
}

void AGASCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AGASCharacter::RemoveAbilityWithTags(FGameplayTagContainer TagContainer)
{
	if (AbilitySystemComponent)
	{
		TArray<FGameplayAbilitySpec*> MatchingAbilities;
		AbilitySystemComponent->GetActivatableGameplayAbilitySpecsByAllMatchingTags(TagContainer, MatchingAbilities, true);
		for (FGameplayAbilitySpec* Spec : MatchingAbilities)
		{
			AbilitySystemComponent->ClearAbility(Spec->Handle);
		}
	}
}

void AGASCharacter::ChangeAbilityLevelWithTags(FGameplayTagContainer TagContainer, int32 NewLevel)
{
	if (AbilitySystemComponent)
	{
		TArray<FGameplayAbilitySpec*> MatchingAbility;
		AbilitySystemComponent->GetActivatableGameplayAbilitySpecsByAllMatchingTags(TagContainer, MatchingAbility, true);
		for (FGameplayAbilitySpec* Spec : MatchingAbility)
		{
			Spec->Level = NewLevel;
		}
	}
}

void AGASCharacter::CancelAbilityWithTags(FGameplayTagContainer WithTags, FGameplayTagContainer WithoutTags)
{
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->CancelAbilities(&WithTags, &WithoutTags, nullptr);
	}
}

void AGASCharacter::AddLooseGameplayTag(FGameplayTag TagToAdd)
{
	if (AbilitySystemComponent)
	{
		GetAbilitySystemComponent()->AddLooseGameplayTag(TagToAdd);
		GetAbilitySystemComponent()->SetTagMapCount(TagToAdd, 1);
	}
}

void AGASCharacter::RemoveLooseGameplayTags(FGameplayTag TagsToRemove)
{
	if (AbilitySystemComponent)
	{
		GetAbilitySystemComponent()->RemoveLooseGameplayTag(TagsToRemove);
	}
}

void AGASCharacter::Server_RemoveAbilityWithTags_Implementation(FGameplayTagContainer TagContainer)
{
	if (HasAuthority() && AbilitySystemComponent)
	{
		TArray<FGameplayAbilitySpec*> MatchingAbilities;
		AbilitySystemComponent->GetActivatableGameplayAbilitySpecsByAllMatchingTags(TagContainer, MatchingAbilities, true);
		for (FGameplayAbilitySpec* Spec : MatchingAbilities)
		{
			AbilitySystemComponent->ClearAbility(Spec->Handle);
		}
	}
}

void AGASCharacter::Server_ChangeAbilityLevelWithTags_Implementation(FGameplayTagContainer TagContainer, int32 NewLevel)
{
	if (HasAuthority() && AbilitySystemComponent)
	{
		TArray<FGameplayAbilitySpec*> MatchingAbility;
		AbilitySystemComponent->GetActivatableGameplayAbilitySpecsByAllMatchingTags(TagContainer, MatchingAbility, true);
		for (FGameplayAbilitySpec* Spec : MatchingAbility)
		{
			Spec->Level = NewLevel;
		}
	}
}

void AGASCharacter::Server_CancelAbilityWithTags_Implementation(FGameplayTagContainer WithTags, FGameplayTagContainer WithoutTags)
{
	if (HasAuthority() && AbilitySystemComponent)
	{
		AbilitySystemComponent->CancelAbilities(&WithTags, &WithoutTags, nullptr);
	}
}

void AGASCharacter::Server_AddLooseGameplayTag_Implementation(FGameplayTag TagToAdd)
{
	if (HasAuthority() && AbilitySystemComponent)
	{
		GetAbilitySystemComponent()->AddLooseGameplayTag(TagToAdd);
		GetAbilitySystemComponent()->SetTagMapCount(TagToAdd, 1);
	}
}

void AGASCharacter::Server_RemoveLooseGameplayTags_Implementation(FGameplayTag TagsToRemove)
{
	if (HasAuthority() && AbilitySystemComponent)
	{
		GetAbilitySystemComponent()->RemoveLooseGameplayTag(TagsToRemove);
	}
}

//==PATTERNSTOP==
void AGASCharacter::OnHealthChangedNative(float Health, int32 StackCount)
{
	OnHealthChange(Health, StackCount);
}

void AGASCharacter::OnManaChangedNative(float Mana, int32 StackCount)
{
	OnManaChange(Mana, StackCount);
}

void AGASCharacter::OnAttackDamageChangedNative(float AttackDamage, int32 StackCount)
{
	OnAttackDamageChange(AttackDamage, StackCount);
}

void AGASCharacter::OnAttackSpeedChangedNative(float AttackSpeed, int32 StackCount)
{
	OnAttackSpeedChange(AttackSpeed, StackCount);
}

void AGASCharacter::OnBaseAttackSpeedMultiplierChangedNative(float BaseAttackSpeedMultiplier, int32 StackCount)
{
	OnBaseAttackSpeedMultiplierChange(BaseAttackSpeedMultiplier, StackCount);
}

void AGASCharacter::OnMovementSpeedChangedNative(float MovementSpeed, int32 StackCount)
{
	OnMovementSpeedChange(MovementSpeed, StackCount);
}

void AGASCharacter::OnArmorChangedNative(float Armor, int32 StackCount)
{
	OnArmorChange(Armor, StackCount);
}

void AGASCharacter::OnMagicResistanceChangedNative(float MagicResistance, int32 StackCount)
{
	OnMagicResistanceChange(MagicResistance, StackCount);
}

void AGASCharacter::OnStrengthChangedNative(float Strength, int32 StackCount)
{
	OnStrengthChange(Strength, StackCount);
}

void AGASCharacter::OnAgilityChangedNative(float Agility, int32 StackCount)
{
	OnAgilityChange(Agility, StackCount);
}

void AGASCharacter::OnIntelligenceChangedNative(float Intelligence, int32 StackCount)
{
	OnIntelligenceChange(Intelligence, StackCount);
}

void AGASCharacter::OnAbilityPowerChangedNative(float AbilityPower, int32 StackCount)
{
	OnAbilityPowerChange(AbilityPower, StackCount);
}

void AGASCharacter::OnAttackRangeChangedNative(float AttackRange, int32 StackCount)
{
	OnAttackRangeChange(AttackRange, StackCount);
}

void AGASCharacter::OnCastTimeChangedNative(float CastTime, int32 StackCount)
{
	OnCastTimeChange(CastTime, StackCount);
}

void AGASCharacter::OnCooldownChangedNative(float Cooldown, int32 StackCount)
{
	OnCooldownChange(Cooldown, StackCount);
}

void AGASCharacter::OnCooldownReductionChangedNative(float CooldownReduction, int32 StackCount)
{
	OnCooldownReductionChange(CooldownReduction, StackCount);
}

void AGASCharacter::OnAbilityScalingChangedNative(float AbilityScaling, int32 StackCount)
{
	OnAbilityScalingChange(AbilityScaling, StackCount);
}

void AGASCharacter::OnBaseDamageChangedNative(float BaseDamage, int32 StackCount)
{
	OnBaseDamageChange(BaseDamage, StackCount);
}

void AGASCharacter::OnScalingCoefficientChangedNative(float ScalingCoefficient, int32 StackCount)
{
	OnScalingCoefficientChange(ScalingCoefficient, StackCount);
}

void AGASCharacter::OnItemNameChangedNative(float ItemName, int32 StackCount)
{
	OnItemNameChange(ItemName, StackCount);
}

void AGASCharacter::OnItemCostChangedNative(float ItemCost, int32 StackCount)
{
	OnItemCostChange(ItemCost, StackCount);
}

void AGASCharacter::OnItemTypeChangedNative(float ItemType, int32 StackCount)
{
	OnItemTypeChange(ItemType, StackCount);
}

void AGASCharacter::OnItemDescriptionChangedNative(float ItemDescription, int32 StackCount)
{
	OnItemDescriptionChange(ItemDescription, StackCount);
}

void AGASCharacter::OnItemEffectChangedNative(float ItemEffect, int32 StackCount)
{
	OnItemEffectChange(ItemEffect, StackCount);
}

void AGASCharacter::OnItemIconPathChangedNative(float ItemIconPath, int32 StackCount)
{
	OnItemIconPathChange(ItemIconPath, StackCount);
}

void AGASCharacter::OnUIWindowPositionChangedNative(float UIWindowPosition, int32 StackCount)
{
	OnUIWindowPositionChange(UIWindowPosition, StackCount);
}

void AGASCharacter::OnUIWindowSizeChangedNative(float UIWindowSize, int32 StackCount)
{
	OnUIWindowSizeChange(UIWindowSize, StackCount);
}

void AGASCharacter::OnUIButtonClickEventChangedNative(float UIButtonClickEvent, int32 StackCount)
{
	OnUIButtonClickEventChange(UIButtonClickEvent, StackCount);
}

void AGASCharacter::OnUIProgressBarValueChangedNative(float UIProgressBarValue, int32 StackCount)
{
	OnUIProgressBarValueChange(UIProgressBarValue, StackCount);
}

void AGASCharacter::OnUITextAlignmentChangedNative(float UITextAlignment, int32 StackCount)
{
	OnUITextAlignmentChange(UITextAlignment, StackCount);
}

void AGASCharacter::OnUIColorChangedNative(float UIColor, int32 StackCount)
{
	OnUIColorChange(UIColor, StackCount);
}

void AGASCharacter::OnOnHeroDeathChangedNative(float OnHeroDeath, int32 StackCount)
{
	OnOnHeroDeathChange(OnHeroDeath, StackCount);
}

void AGASCharacter::OnOnAbilityCastChangedNative(float OnAbilityCast, int32 StackCount)
{
	OnOnAbilityCastChange(OnAbilityCast, StackCount);
}

void AGASCharacter::OnOnItemPickedUpChangedNative(float OnItemPickedUp, int32 StackCount)
{
	OnOnItemPickedUpChange(OnItemPickedUp, StackCount);
}

void AGASCharacter::OnOnTurretDestroyedChangedNative(float OnTurretDestroyed, int32 StackCount)
{
	OnOnTurretDestroyedChange(OnTurretDestroyed, StackCount);
}

void AGASCharacter::OnOnGoldEarnedChangedNative(float OnGoldEarned, int32 StackCount)
{
	OnOnGoldEarnedChange(OnGoldEarned, StackCount);
}

void AGASCharacter::OnMapSizeChangedNative(float MapSize, int32 StackCount)
{
	OnMapSizeChange(MapSize, StackCount);
}

void AGASCharacter::OnSpawnPositionChangedNative(float SpawnPosition, int32 StackCount)
{
	OnSpawnPositionChange(SpawnPosition, StackCount);
}

void AGASCharacter::OnLanePositionsChangedNative(float LanePositions, int32 StackCount)
{
	OnLanePositionsChange(LanePositions, StackCount);
}

void AGASCharacter::OnJungleCampLocationsChangedNative(float JungleCampLocations, int32 StackCount)
{
	OnJungleCampLocationsChange(JungleCampLocations, StackCount);
}

void AGASCharacter::OnPlayerLevelChangedNative(float PlayerLevel, int32 StackCount)
{
	OnPlayerLevelChange(PlayerLevel, StackCount);
}

void AGASCharacter::OnPlayerExperienceChangedNative(float PlayerExperience, int32 StackCount)
{
	OnPlayerExperienceChange(PlayerExperience, StackCount);
}

void AGASCharacter::OnPlayerGoldChangedNative(float PlayerGold, int32 StackCount)
{
	OnPlayerGoldChange(PlayerGold, StackCount);
}

void AGASCharacter::OnPlayerKillsChangedNative(float PlayerKills, int32 StackCount)
{
	OnPlayerKillsChange(PlayerKills, StackCount);
}

void AGASCharacter::OnPlayerDeathsChangedNative(float PlayerDeaths, int32 StackCount)
{
	OnPlayerDeathsChange(PlayerDeaths, StackCount);
}

void AGASCharacter::OnPlayerAssistsChangedNative(float PlayerAssists, int32 StackCount)
{
	OnPlayerAssistsChange(PlayerAssists, StackCount);
}

void AGASCharacter::OnPlayerKillDeathRatioChangedNative(float PlayerKillDeathRatio, int32 StackCount)
{
	OnPlayerKillDeathRatioChange(PlayerKillDeathRatio, StackCount);
}

void AGASCharacter::OnTeamScoreChangedNative(float TeamScore, int32 StackCount)
{
	OnTeamScoreChange(TeamScore, StackCount);
}

void AGASCharacter::OnTeamObjectiveCountChangedNative(float TeamObjectiveCount, int32 StackCount)
{
	OnTeamObjectiveCountChange(TeamObjectiveCount, StackCount);
}

void AGASCharacter::OnTeamTowerCountChangedNative(float TeamTowerCount, int32 StackCount)
{
	OnTeamTowerCountChange(TeamTowerCount, StackCount);
}

void AGASCharacter::OnTeamJungleCampCountChangedNative(float TeamJungleCampCount, int32 StackCount)
{
	OnTeamJungleCampCountChange(TeamJungleCampCount, StackCount);
}

void AGASCharacter::OnDurationChangedNative(float Duration, int32 StackCount)
{
	OnDurationChange(Duration, StackCount);
}

void AGASCharacter::OnTickIntervalChangedNative(float TickInterval, int32 StackCount)
{
	OnTickIntervalChange(TickInterval, StackCount);
}

void AGASCharacter::OnOnEffectApplyChangedNative(float OnEffectApply, int32 StackCount)
{
	OnOnEffectApplyChange(OnEffectApply, StackCount);
}

void AGASCharacter::OnOnEffectRemoveChangedNative(float OnEffectRemove, int32 StackCount)
{
	OnOnEffectRemoveChange(OnEffectRemove, StackCount);
}

void AGASCharacter::OnStacksChangedNative(float Stacks, int32 StackCount)
{
	OnStacksChange(Stacks, StackCount);
}

void AGASCharacter::OnMaxStacksChangedNative(float MaxStacks, int32 StackCount)
{
	OnMaxStacksChange(MaxStacks, StackCount);
}

void AGASCharacter::OnGameTimeChangedNative(float GameTime, int32 StackCount)
{
	OnGameTimeChange(GameTime, StackCount);
}

void AGASCharacter::OnMatchDurationChangedNative(float MatchDuration, int32 StackCount)
{
	OnMatchDurationChange(MatchDuration, StackCount);
}

void AGASCharacter::OnPauseStateChangedNative(float PauseState, int32 StackCount)
{
	OnPauseStateChange(PauseState, StackCount);
}

void AGASCharacter::OnGameModeChangedNative(float GameMode, int32 StackCount)
{
	OnGameModeChange(GameMode, StackCount);
}

void AGASCharacter::OnGameStateChangedNative(float GameState, int32 StackCount)
{
	OnGameStateChange(GameState, StackCount);
}

void AGASCharacter::GetHealthValues(float& Health, float& MaxHealth)
{
	if (AttributeSetVar)
	{
		Health = AttributeSetVar->GetHealth();
		MaxHealth = AttributeSetVar->GetMaxHealth();
	}
}

void AGASCharacter::GetManaValues(float& Mana, float& MaxMana)
{
	if (AttributeSetVar)
	{
		Mana = AttributeSetVar->GetMana();
		MaxMana = AttributeSetVar->GetMaxMana();
	}
}

void AGASCharacter::GetAttackDamageValue(float& AttackDamage)
{
	if (AttributeSetVar)
	{
		AttackDamage = AttributeSetVar->GetAttackDamage();
	}
}

void AGASCharacter::GetAttackSpeedValue(float& AttackSpeed)
{
	if (AttributeSetVar)
	{
		AttackSpeed = AttributeSetVar->GetAttackSpeed();
	}
}

void AGASCharacter::GetBaseAttackSpeedMultiplierValue(float& BaseAttackSpeedMultiplier)
{
	if (AttributeSetVar)
	{
		BaseAttackSpeedMultiplier = AttributeSetVar->GetBaseAttackSpeedMultiplier();
	}
}

void AGASCharacter::GetMovementSpeedValue(float& MovementSpeed)
{
	if (AttributeSetVar)
	{
		MovementSpeed = AttributeSetVar->GetMovementSpeed();
	}
}

void AGASCharacter::GetArmorValues(float& Armor, float& MaxArmor)
{
	if (AttributeSetVar)
	{
		Armor = AttributeSetVar->GetArmor();
		MaxArmor = AttributeSetVar->GetMaxArmor();
	}
}

void AGASCharacter::GetMagicResistanceValues(float& MagicResistance, float& MaxMagicResistance)
{
	if (AttributeSetVar)
	{
		MagicResistance = AttributeSetVar->GetMagicResistance();
		MaxMagicResistance = AttributeSetVar->GetMaxMagicResistance();
	}
}

void AGASCharacter::GetStrengthValue(float& Strength)
{
	if (AttributeSetVar)
	{
		Strength = AttributeSetVar->GetStrength();
	}
}

void AGASCharacter::GetAgilityValue(float& Agility)
{
	if (AttributeSetVar)
	{
		Agility = AttributeSetVar->GetAgility();
	}
}

void AGASCharacter::GetIntelligenceValue(float& Intelligence)
{
	if (AttributeSetVar)
	{
		Intelligence = AttributeSetVar->GetIntelligence();
	}
}

void AGASCharacter::GetAbilityPowerValue(float& AbilityPower)
{
	if (AttributeSetVar)
	{
		AbilityPower = AttributeSetVar->GetAbilityPower();
	}
}

void AGASCharacter::GetAttackRangeValue(float& AttackRange)
{
	if (AttributeSetVar)
	{
		AttackRange = AttributeSetVar->GetAttackRange();
	}
}

void AGASCharacter::GetCastTimeValue(float& CastTime)
{
	if (AttributeSetVar)
	{
		CastTime = AttributeSetVar->GetCastTime();
	}
}

void AGASCharacter::GetCooldownValue(float& Cooldown)
{
	if (AttributeSetVar)
	{
		Cooldown = AttributeSetVar->GetCooldown();
	}
}

void AGASCharacter::GetCooldownReductionValues(float& CooldownReduction, float& MaxCooldownReduction)
{
	if (AttributeSetVar)
	{
		CooldownReduction = AttributeSetVar->GetCooldownReduction();
		MaxCooldownReduction = AttributeSetVar->GetMaxCooldownReduction();
	}
}

void AGASCharacter::GetAbilityScalingValue(float& AbilityScaling)
{
	if (AttributeSetVar)
	{
		AbilityScaling = AttributeSetVar->GetAbilityScaling();
	}
}

void AGASCharacter::GetBaseDamageValue(float& BaseDamage)
{
	if (AttributeSetVar)
	{
		BaseDamage = AttributeSetVar->GetBaseDamage();
	}
}

void AGASCharacter::GetScalingCoefficientValue(float& ScalingCoefficient)
{
	if (AttributeSetVar)
	{
		ScalingCoefficient = AttributeSetVar->GetScalingCoefficient();
	}
}

void AGASCharacter::GetItemNameValue(float& ItemName)
{
	if (AttributeSetVar)
	{
		ItemName = AttributeSetVar->GetItemName();
	}
}

void AGASCharacter::GetItemCostValues(float& ItemCost, float& MaxItemCost)
{
	if (AttributeSetVar)
	{
		ItemCost = AttributeSetVar->GetItemCost();
		MaxItemCost = AttributeSetVar->GetMaxItemCost();
	}
}

void AGASCharacter::GetItemTypeValue(float& ItemType)
{
	if (AttributeSetVar)
	{
		ItemType = AttributeSetVar->GetItemType();
	}
}

void AGASCharacter::GetItemDescriptionValue(float& ItemDescription)
{
	if (AttributeSetVar)
	{
		ItemDescription = AttributeSetVar->GetItemDescription();
	}
}

void AGASCharacter::GetItemEffectValues(float& ItemEffect, float& MaxItemEffect)
{
	if (AttributeSetVar)
	{
		ItemEffect = AttributeSetVar->GetItemEffect();
		MaxItemEffect = AttributeSetVar->GetMaxItemEffect();
	}
}

void AGASCharacter::GetItemIconPathValue(float& ItemIconPath)
{
	if (AttributeSetVar)
	{
		ItemIconPath = AttributeSetVar->GetItemIconPath();
	}
}

void AGASCharacter::GetUIWindowPositionValues(float& UIWindowPosition, float& MaxUIWindowPosition)
{
	if (AttributeSetVar)
	{
		UIWindowPosition = AttributeSetVar->GetUIWindowPosition();
		MaxUIWindowPosition = AttributeSetVar->GetMaxUIWindowPosition();
	}
}

void AGASCharacter::GetUIWindowSizeValue(float& UIWindowSize)
{
	if (AttributeSetVar)
	{
		UIWindowSize = AttributeSetVar->GetUIWindowSize();
	}
}

void AGASCharacter::GetUIButtonClickEventValue(float& UIButtonClickEvent)
{
	if (AttributeSetVar)
	{
		UIButtonClickEvent = AttributeSetVar->GetUIButtonClickEvent();
	}
}

void AGASCharacter::GetUIProgressBarValueValues(float& UIProgressBarValue, float& MaxUIProgressBarValue)
{
	if (AttributeSetVar)
	{
		UIProgressBarValue = AttributeSetVar->GetUIProgressBarValue();
		MaxUIProgressBarValue = AttributeSetVar->GetMaxUIProgressBarValue();
	}
}

void AGASCharacter::GetUITextAlignmentValue(float& UITextAlignment)
{
	if (AttributeSetVar)
	{
		UITextAlignment = AttributeSetVar->GetUITextAlignment();
	}
}

void AGASCharacter::GetUIColorValues(float& UIColor, float& MaxUIColor)
{
	if (AttributeSetVar)
	{
		UIColor = AttributeSetVar->GetUIColor();
		MaxUIColor = AttributeSetVar->GetMaxUIColor();
	}
}

void AGASCharacter::GetOnHeroDeathValue(float& OnHeroDeath)
{
	if (AttributeSetVar)
	{
		OnHeroDeath = AttributeSetVar->GetOnHeroDeath();
	}
}

void AGASCharacter::GetOnAbilityCastValue(float& OnAbilityCast)
{
	if (AttributeSetVar)
	{
		OnAbilityCast = AttributeSetVar->GetOnAbilityCast();
	}
}

void AGASCharacter::GetOnItemPickedUpValue(float& OnItemPickedUp)
{
	if (AttributeSetVar)
	{
		OnItemPickedUp = AttributeSetVar->GetOnItemPickedUp();
	}
}

void AGASCharacter::GetOnTurretDestroyedValue(float& OnTurretDestroyed)
{
	if (AttributeSetVar)
	{
		OnTurretDestroyed = AttributeSetVar->GetOnTurretDestroyed();
	}
}

void AGASCharacter::GetOnGoldEarnedValue(float& OnGoldEarned)
{
	if (AttributeSetVar)
	{
		OnGoldEarned = AttributeSetVar->GetOnGoldEarned();
	}
}

void AGASCharacter::GetMapSizeValues(float& MapSize, float& MaxMapSize)
{
	if (AttributeSetVar)
	{
		MapSize = AttributeSetVar->GetMapSize();
		MaxMapSize = AttributeSetVar->GetMaxMapSize();
	}
}

void AGASCharacter::GetSpawnPositionValue(float& SpawnPosition)
{
	if (AttributeSetVar)
	{
		SpawnPosition = AttributeSetVar->GetSpawnPosition();
	}
}

void AGASCharacter::GetLanePositionsValue(float& LanePositions)
{
	if (AttributeSetVar)
	{
		LanePositions = AttributeSetVar->GetLanePositions();
	}
}

void AGASCharacter::GetJungleCampLocationsValue(float& JungleCampLocations)
{
	if (AttributeSetVar)
	{
		JungleCampLocations = AttributeSetVar->GetJungleCampLocations();
	}
}

void AGASCharacter::GetPlayerLevelValues(float& PlayerLevel, float& MaxPlayerLevel)
{
	if (AttributeSetVar)
	{
		PlayerLevel = AttributeSetVar->GetPlayerLevel();
		MaxPlayerLevel = AttributeSetVar->GetMaxPlayerLevel();
	}
}

void AGASCharacter::GetPlayerExperienceValues(float& PlayerExperience, float& MaxPlayerExperience)
{
	if (AttributeSetVar)
	{
		PlayerExperience = AttributeSetVar->GetPlayerExperience();
		MaxPlayerExperience = AttributeSetVar->GetMaxPlayerExperience();
	}
}

void AGASCharacter::GetPlayerGoldValues(float& PlayerGold, float& MaxPlayerGold)
{
	if (AttributeSetVar)
	{
		PlayerGold = AttributeSetVar->GetPlayerGold();
		MaxPlayerGold = AttributeSetVar->GetMaxPlayerGold();
	}
}

void AGASCharacter::GetPlayerKillsValues(float& PlayerKills, float& MaxPlayerKills)
{
	if (AttributeSetVar)
	{
		PlayerKills = AttributeSetVar->GetPlayerKills();
		MaxPlayerKills = AttributeSetVar->GetMaxPlayerKills();
	}
}

void AGASCharacter::GetPlayerDeathsValues(float& PlayerDeaths, float& MaxPlayerDeaths)
{
	if (AttributeSetVar)
	{
		PlayerDeaths = AttributeSetVar->GetPlayerDeaths();
		MaxPlayerDeaths = AttributeSetVar->GetMaxPlayerDeaths();
	}
}

void AGASCharacter::GetPlayerAssistsValues(float& PlayerAssists, float& MaxPlayerAssists)
{
	if (AttributeSetVar)
	{
		PlayerAssists = AttributeSetVar->GetPlayerAssists();
		MaxPlayerAssists = AttributeSetVar->GetMaxPlayerAssists();
	}
}

void AGASCharacter::GetPlayerKillDeathRatioValue(float& PlayerKillDeathRatio)
{
	if (AttributeSetVar)
	{
		PlayerKillDeathRatio = AttributeSetVar->GetPlayerKillDeathRatio();
	}
}

void AGASCharacter::GetTeamScoreValues(float& TeamScore, float& MaxTeamScore)
{
	if (AttributeSetVar)
	{
		TeamScore = AttributeSetVar->GetTeamScore();
		MaxTeamScore = AttributeSetVar->GetMaxTeamScore();
	}
}

void AGASCharacter::GetTeamObjectiveCountValues(float& TeamObjectiveCount, float& MaxTeamObjectiveCount)
{
	if (AttributeSetVar)
	{
		TeamObjectiveCount = AttributeSetVar->GetTeamObjectiveCount();
		MaxTeamObjectiveCount = AttributeSetVar->GetMaxTeamObjectiveCount();
	}
}

void AGASCharacter::GetTeamTowerCountValues(float& TeamTowerCount, float& MaxTeamTowerCount)
{
	if (AttributeSetVar)
	{
		TeamTowerCount = AttributeSetVar->GetTeamTowerCount();
		MaxTeamTowerCount = AttributeSetVar->GetMaxTeamTowerCount();
	}
}

void AGASCharacter::GetTeamJungleCampCountValues(float& TeamJungleCampCount, float& MaxTeamJungleCampCount)
{
	if (AttributeSetVar)
	{
		TeamJungleCampCount = AttributeSetVar->GetTeamJungleCampCount();
		MaxTeamJungleCampCount = AttributeSetVar->GetMaxTeamJungleCampCount();
	}
}

void AGASCharacter::GetDurationValue(float& Duration)
{
	if (AttributeSetVar)
	{
		Duration = AttributeSetVar->GetDuration();
	}
}

void AGASCharacter::GetTickIntervalValue(float& TickInterval)
{
	if (AttributeSetVar)
	{
		TickInterval = AttributeSetVar->GetTickInterval();
	}
}

void AGASCharacter::GetOnEffectApplyValue(float& OnEffectApply)
{
	if (AttributeSetVar)
	{
		OnEffectApply = AttributeSetVar->GetOnEffectApply();
	}
}

void AGASCharacter::GetOnEffectRemoveValue(float& OnEffectRemove)
{
	if (AttributeSetVar)
	{
		OnEffectRemove = AttributeSetVar->GetOnEffectRemove();
	}
}

void AGASCharacter::GetStacksValue(float& Stacks)
{
	if (AttributeSetVar)
	{
		Stacks = AttributeSetVar->GetStacks();
	}
}

void AGASCharacter::GetMaxStacksValue(float& MaxStacks)
{
	if (AttributeSetVar)
	{
		MaxStacks = AttributeSetVar->GetMaxStacks();
	}
}

void AGASCharacter::GetGameTimeValue(float& GameTime)
{
	if (AttributeSetVar)
	{
		GameTime = AttributeSetVar->GetGameTime();
	}
}

void AGASCharacter::GetMatchDurationValue(float& MatchDuration)
{
	if (AttributeSetVar)
	{
		MatchDuration = AttributeSetVar->GetMatchDuration();
	}
}

void AGASCharacter::GetPauseStateValue(float& PauseState)
{
	if (AttributeSetVar)
	{
		PauseState = AttributeSetVar->GetPauseState();
	}
}

void AGASCharacter::GetGameModeValue(float& GameMode)
{
	if (AttributeSetVar)
	{
		GameMode = AttributeSetVar->GetGameMode();
	}
}

void AGASCharacter::GetGameStateValue(float& GameState)
{
	if (AttributeSetVar)
	{
		GameState = AttributeSetVar->GetGameState();
	}
}

void AGASCharacter::SetHealthValues(float NewHealth, float NewMaxHealth)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetHealthAttribute(), EGameplayModOp::Override, NewHealth);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxHealthAttribute(), EGameplayModOp::Override, NewMaxHealth); 
	}
}

void AGASCharacter::SetManaValues(float NewMana, float NewMaxMana)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetManaAttribute(), EGameplayModOp::Override, NewMana);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxManaAttribute(), EGameplayModOp::Override, NewMaxMana); 
	}
}

void AGASCharacter::SetAttackDamageValue(float NewAttackDamage)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetAttackDamageAttribute(), EGameplayModOp::Override, NewAttackDamage);
	}
}

void AGASCharacter::SetAttackSpeedValue(float NewAttackSpeed)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetAttackSpeedAttribute(), EGameplayModOp::Override, NewAttackSpeed);
	}
}

void AGASCharacter::SetBaseAttackSpeedMultiplierValue(float NewBaseAttackSpeedMultiplier)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetBaseAttackSpeedMultiplierAttribute(), EGameplayModOp::Override, NewBaseAttackSpeedMultiplier);
	}
}

void AGASCharacter::SetMovementSpeedValue(float NewMovementSpeed)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMovementSpeedAttribute(), EGameplayModOp::Override, NewMovementSpeed);
	}
}

void AGASCharacter::SetArmorValues(float NewArmor, float NewMaxArmor)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetArmorAttribute(), EGameplayModOp::Override, NewArmor);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxArmorAttribute(), EGameplayModOp::Override, NewMaxArmor); 
	}
}

void AGASCharacter::SetMagicResistanceValues(float NewMagicResistance, float NewMaxMagicResistance)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMagicResistanceAttribute(), EGameplayModOp::Override, NewMagicResistance);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxMagicResistanceAttribute(), EGameplayModOp::Override, NewMaxMagicResistance); 
	}
}

void AGASCharacter::SetStrengthValue(float NewStrength)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetStrengthAttribute(), EGameplayModOp::Override, NewStrength);
	}
}

void AGASCharacter::SetAgilityValue(float NewAgility)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetAgilityAttribute(), EGameplayModOp::Override, NewAgility);
	}
}

void AGASCharacter::SetIntelligenceValue(float NewIntelligence)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetIntelligenceAttribute(), EGameplayModOp::Override, NewIntelligence);
	}
}

void AGASCharacter::SetAbilityPowerValue(float NewAbilityPower)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetAbilityPowerAttribute(), EGameplayModOp::Override, NewAbilityPower);
	}
}

void AGASCharacter::SetAttackRangeValue(float NewAttackRange)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetAttackRangeAttribute(), EGameplayModOp::Override, NewAttackRange);
	}
}

void AGASCharacter::SetCastTimeValue(float NewCastTime)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetCastTimeAttribute(), EGameplayModOp::Override, NewCastTime);
	}
}

void AGASCharacter::SetCooldownValue(float NewCooldown)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetCooldownAttribute(), EGameplayModOp::Override, NewCooldown);
	}
}

void AGASCharacter::SetCooldownReductionValues(float NewCooldownReduction, float NewMaxCooldownReduction)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetCooldownReductionAttribute(), EGameplayModOp::Override, NewCooldownReduction);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxCooldownReductionAttribute(), EGameplayModOp::Override, NewMaxCooldownReduction); 
	}
}

void AGASCharacter::SetAbilityScalingValue(float NewAbilityScaling)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetAbilityScalingAttribute(), EGameplayModOp::Override, NewAbilityScaling);
	}
}

void AGASCharacter::SetBaseDamageValue(float NewBaseDamage)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetBaseDamageAttribute(), EGameplayModOp::Override, NewBaseDamage);
	}
}

void AGASCharacter::SetScalingCoefficientValue(float NewScalingCoefficient)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetScalingCoefficientAttribute(), EGameplayModOp::Override, NewScalingCoefficient);
	}
}

void AGASCharacter::SetItemNameValue(float NewItemName)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetItemNameAttribute(), EGameplayModOp::Override, NewItemName);
	}
}

void AGASCharacter::SetItemCostValues(float NewItemCost, float NewMaxItemCost)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetItemCostAttribute(), EGameplayModOp::Override, NewItemCost);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxItemCostAttribute(), EGameplayModOp::Override, NewMaxItemCost); 
	}
}

void AGASCharacter::SetItemTypeValue(float NewItemType)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetItemTypeAttribute(), EGameplayModOp::Override, NewItemType);
	}
}

void AGASCharacter::SetItemDescriptionValue(float NewItemDescription)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetItemDescriptionAttribute(), EGameplayModOp::Override, NewItemDescription);
	}
}

void AGASCharacter::SetItemEffectValues(float NewItemEffect, float NewMaxItemEffect)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetItemEffectAttribute(), EGameplayModOp::Override, NewItemEffect);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxItemEffectAttribute(), EGameplayModOp::Override, NewMaxItemEffect); 
	}
}

void AGASCharacter::SetItemIconPathValue(float NewItemIconPath)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetItemIconPathAttribute(), EGameplayModOp::Override, NewItemIconPath);
	}
}

void AGASCharacter::SetUIWindowPositionValues(float NewUIWindowPosition, float NewMaxUIWindowPosition)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetUIWindowPositionAttribute(), EGameplayModOp::Override, NewUIWindowPosition);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxUIWindowPositionAttribute(), EGameplayModOp::Override, NewMaxUIWindowPosition); 
	}
}

void AGASCharacter::SetUIWindowSizeValue(float NewUIWindowSize)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetUIWindowSizeAttribute(), EGameplayModOp::Override, NewUIWindowSize);
	}
}

void AGASCharacter::SetUIButtonClickEventValue(float NewUIButtonClickEvent)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetUIButtonClickEventAttribute(), EGameplayModOp::Override, NewUIButtonClickEvent);
	}
}

void AGASCharacter::SetUIProgressBarValueValues(float NewUIProgressBarValue, float NewMaxUIProgressBarValue)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetUIProgressBarValueAttribute(), EGameplayModOp::Override, NewUIProgressBarValue);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxUIProgressBarValueAttribute(), EGameplayModOp::Override, NewMaxUIProgressBarValue); 
	}
}

void AGASCharacter::SetUITextAlignmentValue(float NewUITextAlignment)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetUITextAlignmentAttribute(), EGameplayModOp::Override, NewUITextAlignment);
	}
}

void AGASCharacter::SetUIColorValues(float NewUIColor, float NewMaxUIColor)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetUIColorAttribute(), EGameplayModOp::Override, NewUIColor);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxUIColorAttribute(), EGameplayModOp::Override, NewMaxUIColor); 
	}
}

void AGASCharacter::SetOnHeroDeathValue(float NewOnHeroDeath)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetOnHeroDeathAttribute(), EGameplayModOp::Override, NewOnHeroDeath);
	}
}

void AGASCharacter::SetOnAbilityCastValue(float NewOnAbilityCast)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetOnAbilityCastAttribute(), EGameplayModOp::Override, NewOnAbilityCast);
	}
}

void AGASCharacter::SetOnItemPickedUpValue(float NewOnItemPickedUp)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetOnItemPickedUpAttribute(), EGameplayModOp::Override, NewOnItemPickedUp);
	}
}

void AGASCharacter::SetOnTurretDestroyedValue(float NewOnTurretDestroyed)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetOnTurretDestroyedAttribute(), EGameplayModOp::Override, NewOnTurretDestroyed);
	}
}

void AGASCharacter::SetOnGoldEarnedValue(float NewOnGoldEarned)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetOnGoldEarnedAttribute(), EGameplayModOp::Override, NewOnGoldEarned);
	}
}

void AGASCharacter::SetMapSizeValues(float NewMapSize, float NewMaxMapSize)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMapSizeAttribute(), EGameplayModOp::Override, NewMapSize);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxMapSizeAttribute(), EGameplayModOp::Override, NewMaxMapSize); 
	}
}

void AGASCharacter::SetSpawnPositionValue(float NewSpawnPosition)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetSpawnPositionAttribute(), EGameplayModOp::Override, NewSpawnPosition);
	}
}

void AGASCharacter::SetLanePositionsValue(float NewLanePositions)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetLanePositionsAttribute(), EGameplayModOp::Override, NewLanePositions);
	}
}

void AGASCharacter::SetJungleCampLocationsValue(float NewJungleCampLocations)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetJungleCampLocationsAttribute(), EGameplayModOp::Override, NewJungleCampLocations);
	}
}

void AGASCharacter::SetPlayerLevelValues(float NewPlayerLevel, float NewMaxPlayerLevel)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetPlayerLevelAttribute(), EGameplayModOp::Override, NewPlayerLevel);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxPlayerLevelAttribute(), EGameplayModOp::Override, NewMaxPlayerLevel); 
	}
}

void AGASCharacter::SetPlayerExperienceValues(float NewPlayerExperience, float NewMaxPlayerExperience)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetPlayerExperienceAttribute(), EGameplayModOp::Override, NewPlayerExperience);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxPlayerExperienceAttribute(), EGameplayModOp::Override, NewMaxPlayerExperience); 
	}
}

void AGASCharacter::SetPlayerGoldValues(float NewPlayerGold, float NewMaxPlayerGold)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetPlayerGoldAttribute(), EGameplayModOp::Override, NewPlayerGold);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxPlayerGoldAttribute(), EGameplayModOp::Override, NewMaxPlayerGold); 
	}
}

void AGASCharacter::SetPlayerKillsValues(float NewPlayerKills, float NewMaxPlayerKills)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetPlayerKillsAttribute(), EGameplayModOp::Override, NewPlayerKills);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxPlayerKillsAttribute(), EGameplayModOp::Override, NewMaxPlayerKills); 
	}
}

void AGASCharacter::SetPlayerDeathsValues(float NewPlayerDeaths, float NewMaxPlayerDeaths)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetPlayerDeathsAttribute(), EGameplayModOp::Override, NewPlayerDeaths);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxPlayerDeathsAttribute(), EGameplayModOp::Override, NewMaxPlayerDeaths); 
	}
}

void AGASCharacter::SetPlayerAssistsValues(float NewPlayerAssists, float NewMaxPlayerAssists)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetPlayerAssistsAttribute(), EGameplayModOp::Override, NewPlayerAssists);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxPlayerAssistsAttribute(), EGameplayModOp::Override, NewMaxPlayerAssists); 
	}
}

void AGASCharacter::SetPlayerKillDeathRatioValue(float NewPlayerKillDeathRatio)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetPlayerKillDeathRatioAttribute(), EGameplayModOp::Override, NewPlayerKillDeathRatio);
	}
}

void AGASCharacter::SetTeamScoreValues(float NewTeamScore, float NewMaxTeamScore)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetTeamScoreAttribute(), EGameplayModOp::Override, NewTeamScore);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxTeamScoreAttribute(), EGameplayModOp::Override, NewMaxTeamScore); 
	}
}

void AGASCharacter::SetTeamObjectiveCountValues(float NewTeamObjectiveCount, float NewMaxTeamObjectiveCount)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetTeamObjectiveCountAttribute(), EGameplayModOp::Override, NewTeamObjectiveCount);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxTeamObjectiveCountAttribute(), EGameplayModOp::Override, NewMaxTeamObjectiveCount); 
	}
}

void AGASCharacter::SetTeamTowerCountValues(float NewTeamTowerCount, float NewMaxTeamTowerCount)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetTeamTowerCountAttribute(), EGameplayModOp::Override, NewTeamTowerCount);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxTeamTowerCountAttribute(), EGameplayModOp::Override, NewMaxTeamTowerCount); 
	}
}

void AGASCharacter::SetTeamJungleCampCountValues(float NewTeamJungleCampCount, float NewMaxTeamJungleCampCount)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetTeamJungleCampCountAttribute(), EGameplayModOp::Override, NewTeamJungleCampCount);
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxTeamJungleCampCountAttribute(), EGameplayModOp::Override, NewMaxTeamJungleCampCount); 
	}
}

void AGASCharacter::SetDurationValue(float NewDuration)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetDurationAttribute(), EGameplayModOp::Override, NewDuration);
	}
}

void AGASCharacter::SetTickIntervalValue(float NewTickInterval)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetTickIntervalAttribute(), EGameplayModOp::Override, NewTickInterval);
	}
}

void AGASCharacter::SetOnEffectApplyValue(float NewOnEffectApply)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetOnEffectApplyAttribute(), EGameplayModOp::Override, NewOnEffectApply);
	}
}

void AGASCharacter::SetOnEffectRemoveValue(float NewOnEffectRemove)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetOnEffectRemoveAttribute(), EGameplayModOp::Override, NewOnEffectRemove);
	}
}

void AGASCharacter::SetStacksValue(float NewStacks)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetStacksAttribute(), EGameplayModOp::Override, NewStacks);
	}
}

void AGASCharacter::SetMaxStacksValue(float NewMaxStacks)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMaxStacksAttribute(), EGameplayModOp::Override, NewMaxStacks);
	}
}

void AGASCharacter::SetGameTimeValue(float NewGameTime)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetGameTimeAttribute(), EGameplayModOp::Override, NewGameTime);
	}
}

void AGASCharacter::SetMatchDurationValue(float NewMatchDuration)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetMatchDurationAttribute(), EGameplayModOp::Override, NewMatchDuration);
	}
}

void AGASCharacter::SetPauseStateValue(float NewPauseState)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetPauseStateAttribute(), EGameplayModOp::Override, NewPauseState);
	}
}

void AGASCharacter::SetGameModeValue(float NewGameMode)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetGameModeAttribute(), EGameplayModOp::Override, NewGameMode);
	}
}

void AGASCharacter::SetGameStateValue(float NewGameState)
{
	if (AttributeSetVar)
	{
		AbilitySystemComponent->ApplyModToAttribute(AttributeSetVar->GetGameStateAttribute(), EGameplayModOp::Override, NewGameState);
	}
}

