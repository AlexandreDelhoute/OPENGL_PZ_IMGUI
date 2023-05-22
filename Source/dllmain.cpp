#include "Includes.h"

using jniGetCreatedJavaVMs_t = jint(*)(JavaVM** vmBuf, jsize bufLen, jsize* nVMs);

JNIEnv* getJNIEnv()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return nullptr;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return nullptr;
	}

	JNIEnv* jniEnv = nullptr;
	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return nullptr;
	}
	return jniEnv;
}
jobject getPlayerInstance(JNIEnv* jniEnv)
{
	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return nullptr;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return nullptr;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return nullptr;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return nullptr;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return nullptr;
	}

	return playerInstance;
}

///===============================///
bool godModeEnabled = false;
bool carryEnabled = false;
bool enduranceEnabled = false;
bool buildCheatEnabled = false;
bool farmCheatEnabled = false;
bool healthCheatEnabled = false;
bool mechanicsCheatEnabled = false;
bool movablesCheatEnabled = false;
bool invisibleCheatEnabled = false;
bool instantActionEnabled = false;
bool noRecoilDelayEnabled = false;
///===============================///

void GodModeON()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}

	const auto setGodModMethodId = jniEnv->GetMethodID(isoPlayerClass, "setGodMod", "(Z)V");
	if (setGodModMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setGodMod method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setGodModMethodId, JNI_TRUE);
	bool godModeEnabled = true;
}
void GodModeOFF()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}

	const auto setGodModMethodId = jniEnv->GetMethodID(isoPlayerClass, "setGodMod", "(Z)V");
	if (setGodModMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setGodMod method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setGodModMethodId, JNI_FALSE);
	bool godModeEnabled = false;
}

void CarryON()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}

	const auto setUnlimitedCarryId = jniEnv->GetMethodID(isoPlayerClass, "setUnlimitedCarry", "(Z)V");
	if (setUnlimitedCarryId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setUnlimitedCarry method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setUnlimitedCarryId, JNI_TRUE);
	bool carryEnabled = true;

}
void CarryOFF()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}

	const auto setUnlimitedCarryId = jniEnv->GetMethodID(isoPlayerClass, "setUnlimitedCarry", "(Z)V");
	if (setUnlimitedCarryId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setUnlimitedCarry method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setUnlimitedCarryId, JNI_FALSE);
	bool carryEnabled = false;
}

void EnduranceON()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}
	const auto setUnlimitedEnduranceId = jniEnv->GetMethodID(isoPlayerClass, "setUnlimitedEndurance", "(Z)V");
	if (setUnlimitedEnduranceId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setUnlimitedEndurance method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setUnlimitedEnduranceId, 1);
	bool enduranceEnabled = true;
}
void EnduranceOFF()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}
	const auto setUnlimitedEnduranceId = jniEnv->GetMethodID(isoPlayerClass, "setUnlimitedEndurance", "(Z)V");
	if (setUnlimitedEnduranceId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setUnlimitedEndurance method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setUnlimitedEnduranceId, 0);
	bool enduranceEnabled = false;
}

void BuildCheatON()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}

	const auto setBuildCheatId = jniEnv->GetMethodID(isoPlayerClass, "setBuildCheat", "(Z)V");
	if (setBuildCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setBuildCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setBuildCheatId, JNI_TRUE);
	bool buildCheatEnabled = true;
}
void BuildCheatOFF()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}

	const auto setBuildCheatId = jniEnv->GetMethodID(isoPlayerClass, "setBuildCheat", "(Z)V");
	if (setBuildCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setBuildCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setBuildCheatId, JNI_FALSE);
	bool buildCheatEnabled = false;
}

void FarmCheatON()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}
	const auto setFarmingCheatId = jniEnv->GetMethodID(isoPlayerClass, "setFarmingCheat", "(Z)V");
	if (setFarmingCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setFarmingCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setFarmingCheatId, JNI_TRUE);
	bool farmCheatEnabled = true;
}
void FarmCheatOFF()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}
	const auto setFarmingCheatId = jniEnv->GetMethodID(isoPlayerClass, "setFarmingCheat", "(Z)V");
	if (setFarmingCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setFarmingCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setFarmingCheatId, JNI_FALSE);
	bool farmCheatEnabled = false;
}

void HealthCheatON()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}
	const auto setHealthCheatId = jniEnv->GetMethodID(isoPlayerClass, "setHealthCheat", "(Z)V");
	if (setHealthCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setHealthCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setHealthCheatId, JNI_TRUE);
	bool healthCheatEnabled = true;
}
void HealthCheatOFF()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}

	const auto setHealthCheatId = jniEnv->GetMethodID(isoPlayerClass, "setHealthCheat", "(Z)V");
	if (setHealthCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setHealthCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setHealthCheatId, JNI_FALSE);
	bool healthCheatEnabled = false;
}

void MechanicsCheatON()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}
	const auto setMechanicsCheatId = jniEnv->GetMethodID(isoPlayerClass, "setMechanicsCheat", "(Z)V");
	if (setMechanicsCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setMechanicsCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setMechanicsCheatId, JNI_TRUE);
	bool mechanicsCheatEnabled = true;
}
void MechanicsCheatOFF()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}

	const auto setMechanicsCheatId = jniEnv->GetMethodID(isoPlayerClass, "setMechanicsCheat", "(Z)V");
	if (setMechanicsCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setMechanicsCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setMechanicsCheatId, JNI_FALSE);
	bool mechanicsCheatEnabled = false;
}

void MovableCheatON()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}

	const auto setMovablesCheatId = jniEnv->GetMethodID(isoPlayerClass, "setMovablesCheat", "(Z)V");
	if (setMovablesCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setMovablesCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setMovablesCheatId, JNI_TRUE);
	bool movablesCheatEnabled = true;
}
void MovableCheatOFF()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}

	const auto setMovablesCheatId = jniEnv->GetMethodID(isoPlayerClass, "setMovablesCheat", "(Z)V");
	if (setMovablesCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setMovablesCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setMovablesCheatId, JNI_FALSE);
	bool movablesCheatEnabled = false;
}

void InvisibleCheatON()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}

	const auto setInvisibleId = jniEnv->GetMethodID(isoPlayerClass, "setInvisible", "(Z)V");
	if (setInvisibleId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setInvisible method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setInvisibleId, JNI_TRUE);
	bool invisibleCheatEnabled = true;
}
void InvisibleCheatOFF()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}
	const auto setInvisibleId = jniEnv->GetMethodID(isoPlayerClass, "setInvisible", "(Z)V");
	if (setInvisibleId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setInvisible method.\n";
		return;
	}
	//actions :
	jniEnv->CallVoidMethod(playerInstance, setInvisibleId, JNI_FALSE);
	bool invisibleCheatEnabled = false;
}

void InstantActionON()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}
	const auto setTimedActionInstantCheatId = jniEnv->GetMethodID(isoPlayerClass, "setTimedActionInstantCheat", "(Z)V");
	if (setTimedActionInstantCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setTimedActionInstantCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setTimedActionInstantCheatId, JNI_TRUE);
	bool instantActionEnabled = true;
}
void InstantActionOFF()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}
	const auto setTimedActionInstantCheatId = jniEnv->GetMethodID(isoPlayerClass, "setTimedActionInstantCheat", "(Z)V");
	if (setTimedActionInstantCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setTimedActionInstantCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setTimedActionInstantCheatId, JNI_FALSE);
	bool instantActionEnabled = false;
}

void NoRecoilDelayON()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}
	const auto setRecoilDelayId = jniEnv->GetMethodID(isoPlayerClass, "setRecoilDelay", "(F)V");
	if (setRecoilDelayId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setRecoilDelay method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setRecoilDelayId, 0.0f);
	bool noRecoilDelayEnabled = true;
}
void NoRecoilDelayOFF()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}
	const auto setRecoilDelayId = jniEnv->GetMethodID(isoPlayerClass, "setRecoilDelay", "(F)V");
	if (setRecoilDelayId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setRecoilDelay method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setRecoilDelayId, 1.0f);
	bool noRecoilDelayEnabled = false;
}

void AddXpToSkills()
{
	JNIEnv* jniEnv = getJNIEnv();
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to get JNIEnv.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	jobject playerInstance = getPlayerInstance(jniEnv);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] Failed to get player instance.\n";
		return;
	}

	const auto perkFactoryClass = jniEnv->FindClass("zombie/characters/skills/PerkFactory$Perks");

	const auto getXpMethodId = jniEnv->GetMethodID(isoPlayerClass, "getXp", "()Lzombie/characters/IsoGameCharacter$XP;");
	jobject xpObject = jniEnv->CallObjectMethod(playerInstance, getXpMethodId);

	const auto IsoGameCharacterXPClass = jniEnv->FindClass("zombie/characters/IsoGameCharacter$XP");

	const auto addXPMethodId = jniEnv->GetMethodID(IsoGameCharacterXPClass, "AddXP", "(Lzombie/characters/skills/PerkFactory$Perk;F)V");

	jobject perkObjectAiming = jniEnv->GetStaticObjectField(perkFactoryClass, jniEnv->GetStaticFieldID(perkFactoryClass, "Aiming", "Lzombie/characters/skills/PerkFactory$Perk;"));
	jobject perkObjectReloading = jniEnv->GetStaticObjectField(perkFactoryClass, jniEnv->GetStaticFieldID(perkFactoryClass, "Reloading", "Lzombie/characters/skills/PerkFactory$Perk;"));
	jobject perkObjectSprinting = jniEnv->GetStaticObjectField(perkFactoryClass, jniEnv->GetStaticFieldID(perkFactoryClass, "Sprinting", "Lzombie/characters/skills/PerkFactory$Perk;"));

	jniEnv->CallVoidMethod(xpObject, addXPMethodId, perkObjectAiming, 1000.0f);
	jniEnv->CallVoidMethod(xpObject, addXPMethodId, perkObjectReloading, 1000.0f);
	jniEnv->CallVoidMethod(xpObject, addXPMethodId, perkObjectSprinting, 1000.0f);
}


twglSwapBuffers oSwapBuffers = NULL;
WNDPROC oWndProc;
static HWND Window = NULL;

int init = false;
bool show = false;
BOOL __stdcall hkSwapBuffers(_In_ HDC hDc)
{
	if (init == FALSE)
	{
		glewExperimental = GL_TRUE;
		if (glewInit() == GLEW_OK)
		{
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO();
			io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
			ImGui_ImplWin32_Init(Window);
			ImGui_ImplOpenGL3_Init();
			init = TRUE;
		}
	}

	if (GetAsyncKeyState(VK_INSERT) & 1)
		show = !show;

	if (GetAsyncKeyState(VK_END) & 1) // Unload
	{
		MH_DisableHook(MH_ALL_HOOKS);
		SetWindowLongPtr(Window, GWL_WNDPROC, (LONG_PTR)oWndProc); // Reset WndProc
	}

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (show)
	{
		ImGui::Begin("Ici les bo boutons !");
		if (ImGui::Checkbox("God Mode", &godModeEnabled))
		{
			if (godModeEnabled) { GodModeON(); }
			else { GodModeOFF(); }
		}
		if (ImGui::Checkbox("Unlimited Carry", &carryEnabled))
		{
			if (godModeEnabled) { CarryON(); }
			else { CarryOFF(); }
		}
		if (ImGui::Checkbox("Unlimited Endurance", &enduranceEnabled))
		{
			if (godModeEnabled) { EnduranceON(); }
			else { EnduranceOFF(); }
		}
		if (ImGui::Checkbox("Health Cheat", &healthCheatEnabled))
		{
			if (godModeEnabled) { HealthCheatON(); }
			else { HealthCheatOFF(); }
		}
		if (ImGui::Checkbox("Build Cheat", &buildCheatEnabled))
		{
			if (godModeEnabled) { BuildCheatON(); }
			else { BuildCheatOFF(); }
		}
		if (ImGui::Checkbox("Mechanics Cheat", &mechanicsCheatEnabled))
		{
			if (godModeEnabled) { MechanicsCheatON(); }
			else { MechanicsCheatOFF(); }
		}
		if (ImGui::Checkbox("Farm Cheat", &farmCheatEnabled))
		{
			if (godModeEnabled) { FarmCheatON(); }
			else { FarmCheatOFF(); }
		}
		if (ImGui::Checkbox("Farm Cheat", &movablesCheatEnabled))
		{
			if (godModeEnabled) { MovableCheatON(); }   
			else { MovableCheatOFF(); }
		}
		/*
		if (ImGui::Button("Unlimited Carry ON"))
		{
			CarryON();
		}
		if (ImGui::Button("Unlimited Carry OFF"))
		{
			CarryOFF();
		}
		if (ImGui::Button("Endurance Cheat ON"))
		{
			EnduranceON();
		}
		if (ImGui::Button("Endurance Cheat OFF"))
		{
			EnduranceOFF();
		}
		if (ImGui::Button("Build Cheat ON"))
		{
			BuildCheatON();
		}
		if (ImGui::Button("Build Cheat OFF"))
		{
			BuildCheatOFF();
		}
		if (ImGui::Button("Farm Cheat ON"))
		{
			FarmCheatON();
		}
		if (ImGui::Button("Farm Cheat OFF"))
		{
			FarmCheatOFF();
		}
		if (ImGui::Button("Health Cheat ON"))
		{
			HealthCheatON();
		}
		if (ImGui::Button("Health Cheat OFF"))
		{
			HealthCheatOFF();
		}
		if (ImGui::Button("Mechanics Cheat ON"))
		{
			MechanicsCheatON();
		}
		if (ImGui::Button("Mechanics Cheat OFF"))
		{
			MechanicsCheatOFF();
		}
		if (ImGui::Button("Movable Cheat ON"))
		{
			MovableCheatON();
		}
		if (ImGui::Button("Movable Cheat OFF"))
		{
			MovableCheatOFF();
		}
		if (ImGui::Button("Invisible Cheat ON"))
		{
			InvisibleCheatON();
		}
		if (ImGui::Button("Invisible Cheat OFF"))
		{
			InvisibleCheatOFF();
		}
		if (ImGui::Button("Instant Action ON"))
		{
			InstantActionON();
		}
		if (ImGui::Button("Instant Action OFF"))
		{
			InstantActionOFF();
		}
		if (ImGui::Button("No Recoil ON"))
		{
			NoRecoilON();
		}
		if (ImGui::Button("No Recoil OFF"))
		{
			NoRecoilOFF();
		}
		if (ImGui::Button("Level Multiplier ON"))
		{
			LevelMultiplierON();
		}
		if (ImGui::Button("Level Multiplier OFF"))
		{
			//LevelMultiplierOFF();
		}
		if (ImGui::Button("TEST"))
		{
			AddXpToSkills();
		}
		if (ImGui::Button("TEST2"))
		{
		}*/
		ImGui::End(); //END MENU
	}

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	return oSwapBuffers(hDc);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

DWORD WINAPI Initalization(__in  LPVOID lpParameter)
{
	while (GetModuleHandle("opengl32.dll") == NULL) { Sleep(100); }
	Sleep(100);

	HMODULE hMod = GetModuleHandle("opengl32.dll");
	if (hMod)
	{
		void* ptr = GetProcAddress(hMod, "wglSwapBuffers");
		MH_Initialize();
		MH_CreateHook(ptr, hkSwapBuffers, reinterpret_cast<void**>(&oSwapBuffers));
		MH_EnableHook(ptr);
		do
			Window = GetProcessWindow();
		while (Window == NULL);
		oWndProc = (WNDPROC)SetWindowLongPtr(Window, GWL_WNDPROC, (LONG_PTR)WndProc);

		// Ajouter une console
		AllocConsole();
		FILE* file;
		freopen_s(&file, "CONOUT$", "w", stdout);

		std::cout << "Start debug console" << std::endl;

		return true;
	}
	else
		return false;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		CreateThread(0, 0, Initalization, 0, 0, 0);
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
