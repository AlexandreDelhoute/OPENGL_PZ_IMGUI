#include "Includes.h"

using jniGetCreatedJavaVMs_t = jint(*)(JavaVM** vmBuf, jsize bufLen, jsize* nVMs);

void GodModeON()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}
	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}
	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setGodModMethodId = jniEnv->GetMethodID(isoPlayerClass, "setGodMod", "(Z)V");
	if (setGodModMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setGodMod method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setGodModMethodId, 1); // Activate Gode Mode
}
void GodModeOFF()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setGodModMethodId = jniEnv->GetMethodID(isoPlayerClass, "setGodMod", "(Z)V");
	if (setGodModMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setGodMod method.\n";
		return;
	}
	//actions :
	jniEnv->CallVoidMethod(playerInstance, setGodModMethodId, 0); // Activate Gode Mode
}
void CarryON()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setUnlimitedCarryId = jniEnv->GetMethodID(isoPlayerClass, "setUnlimitedCarry", "(Z)V");
	if (setUnlimitedCarryId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setUnlimitedCarry method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setUnlimitedCarryId, 1);// Activate Unlimited Carry
}
void CarryOFF()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setUnlimitedCarryId = jniEnv->GetMethodID(isoPlayerClass, "setUnlimitedCarry", "(Z)V");
	if (setUnlimitedCarryId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setUnlimitedCarry method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setUnlimitedCarryId, 0);// Activate Unlimited Carry
}
void EnduranceON()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto setUnlimitedEnduranceId = jniEnv->GetMethodID(isoPlayerClass, "setUnlimitedEndurance", "(Z)V");
	if (setUnlimitedEnduranceId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setUnlimitedEndurance method.\n";
		return;
	}
	//actions :
	jniEnv->CallVoidMethod(playerInstance, setUnlimitedEnduranceId, 1); // Activate Unlimited Endurance
}
void EnduranceOFF()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setGodModMethodId = jniEnv->GetMethodID(isoPlayerClass, "setGodMod", "(Z)V");
	if (setGodModMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setGodMod method.\n";
		return;
	}

	const auto setUnlimitedCarryId = jniEnv->GetMethodID(isoPlayerClass, "setUnlimitedCarry", "(Z)V");
	if (setUnlimitedCarryId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setUnlimitedCarry method.\n";
		return;
	}
	const auto setUnlimitedEnduranceId = jniEnv->GetMethodID(isoPlayerClass, "setUnlimitedEndurance", "(Z)V");
	if (setUnlimitedEnduranceId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setUnlimitedEndurance method.\n";
		return;
	}
	//actions :
	jniEnv->CallVoidMethod(playerInstance, setUnlimitedEnduranceId, 0); // Activate Unlimited Endurance
}
void BuildCheatON()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setBuildCheatId = jniEnv->GetMethodID(isoPlayerClass, "setBuildCheat", "(Z)V");
	if (setBuildCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setBuildCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setBuildCheatId, 1); // Activate Build Infini
}
void BuildCheatOFF()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setBuildCheatId = jniEnv->GetMethodID(isoPlayerClass, "setBuildCheat", "(Z)V");
	if (setBuildCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setBuildCheat method.\n";
		return;
	}
	//actions :
	jniEnv->CallVoidMethod(playerInstance, setBuildCheatId, 0); // Activate Build Infini
}
void FarmCheatON()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto setFarmingCheatId = jniEnv->GetMethodID(isoPlayerClass, "setFarmingCheat", "(Z)V");
	if (setFarmingCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setFarmingCheat method.\n";
		return;
	}
	//actions :
	jniEnv->CallVoidMethod(playerInstance, setFarmingCheatId, 1); // Activate Farming Cheat
}
void FarmCheatOFF()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto setFarmingCheatId = jniEnv->GetMethodID(isoPlayerClass, "setFarmingCheat", "(Z)V");
	if (setFarmingCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setFarmingCheat method.\n";
		return;
	}
	//actions :
	jniEnv->CallVoidMethod(playerInstance, setFarmingCheatId, 0); // Activate Farming Cheat
}
void HealthCheatON()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto setHealthCheatId = jniEnv->GetMethodID(isoPlayerClass, "setHealthCheat", "(Z)V");
	if (setHealthCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setHealthCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setHealthCheatId, 1); // Activate Health cheat
}
void HealthCheatOFF()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setHealthCheatId = jniEnv->GetMethodID(isoPlayerClass, "setHealthCheat", "(Z)V");
	if (setHealthCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setHealthCheat method.\n";
		return;
	}
	//actions :
	jniEnv->CallVoidMethod(playerInstance, setHealthCheatId, 0); // Activate Health cheat
}
void MechanicsCheatON()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto setMechanicsCheatId = jniEnv->GetMethodID(isoPlayerClass, "setMechanicsCheat", "(Z)V");
	if (setMechanicsCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setMechanicsCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setMechanicsCheatId, 1); // Activate Mechanics Cheats
}
void MechanicsCheatOFF()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setMechanicsCheatId = jniEnv->GetMethodID(isoPlayerClass, "setMechanicsCheat", "(Z)V");
	if (setMechanicsCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setMechanicsCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setMechanicsCheatId, 0); // Activate Mechanics Cheats
}
void MovableCheatON()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setMovablesCheatId = jniEnv->GetMethodID(isoPlayerClass, "setMovablesCheat", "(Z)V");
	if (setMovablesCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setMovablesCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setMovablesCheatId, 1); // Activate Movables Cheats
}
void MovableCheatOFF()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setMovablesCheatId = jniEnv->GetMethodID(isoPlayerClass, "setMovablesCheat", "(Z)V");
	if (setMovablesCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setMovablesCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setMovablesCheatId, 1); // Activate Movables Cheats
}
void InvisibleCheatON()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setInvisibleId = jniEnv->GetMethodID(isoPlayerClass, "setInvisible", "(Z)V");
	if (setInvisibleId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setInvisible method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setInvisibleId, 1); // Activate Invisible
}
void InvisibleCheatOFF()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto setInvisibleId = jniEnv->GetMethodID(isoPlayerClass, "setInvisible", "(Z)V");
	if (setInvisibleId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setInvisible method.\n";
		return;
	}
	//actions :
	jniEnv->CallVoidMethod(playerInstance, setInvisibleId, 0); // Activate Invisible
}
void InstantActionON()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto setTimedActionInstantCheatId = jniEnv->GetMethodID(isoPlayerClass, "setTimedActionInstantCheat", "(Z)V");
	if (setTimedActionInstantCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setTimedActionInstantCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setTimedActionInstantCheatId, 1); // Activate Instant Action
}
void InstantActionOFF()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto setTimedActionInstantCheatId = jniEnv->GetMethodID(isoPlayerClass, "setTimedActionInstantCheat", "(Z)V");
	if (setTimedActionInstantCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setTimedActionInstantCheat method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setTimedActionInstantCheatId, 0); // Activate Instant Action
}
void NoRecoilON()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto setRecoilDelayId = jniEnv->GetMethodID(isoPlayerClass, "setRecoilDelay", "(F)V");
	if (setRecoilDelayId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setRecoilDelay method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setRecoilDelayId, 0); // Activate No Recoil
}
void NoRecoilOFF()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto setRecoilDelayId = jniEnv->GetMethodID(isoPlayerClass, "setRecoilDelay", "(F)V");
	if (setRecoilDelayId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setRecoilDelay method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setRecoilDelayId, 1); // Activate No Recoil
}
void LevelMultiplierON()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto setLevelUpMultiplierId = jniEnv->GetMethodID(isoPlayerClass, "setLevelUpMultiplier", "(F)V");
	if (setLevelUpMultiplierId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setLevelUpMultiplier method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setLevelUpMultiplierId, 100.0f); // Activate xp multiplier
}
void LevelMultiplierOFF()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto setLevelUpMultiplierId = jniEnv->GetMethodID(isoPlayerClass, "setLevelUpMultiplier", "(F)V");
	if (setLevelUpMultiplierId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setLevelUpMultiplier method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setLevelUpMultiplierId, 1.0f); // Activate xp multiplier
}

void AddXpToSkills()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}
	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}
	const auto perkFactoryClass = jniEnv->FindClass("zombie/characters/skills/PerkFactory");
	if (perkFactoryClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve PerkFactory class.\n";
		return;
	}
	const auto IsoGameCharacterXPClass = jniEnv->FindClass("zombie/characters/IsoGameCharacter$XP");
	if (IsoGameCharacterXPClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacterXP class.\n";
		return;
	}
	const auto perkFactoryPerksClass = jniEnv->FindClass("zombie/characters/skills/PerkFactory$Perks");
	if (perkFactoryPerksClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacterXP class.\n";
		return;
	}
	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto addXPMethodId = jniEnv->GetMethodID(IsoGameCharacterXPClass, "AddXP", "(Lzombie/characters/skills/PerkFactory$Perk;F)V");
	if (addXPMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::AddXP method.\n";
		return;
	}
	const auto aimingPerkFieldId = jniEnv->GetStaticFieldID(perkFactoryPerksClass, "aiming", "Lzombie/characters/skills/PerkFactory$Perk;");
	if (aimingPerkFieldId == nullptr)
	{
		std::cout << "[!] Failed to retrieve PerkFactory.aiming field.\n";
			return;
	}
	const auto aimingPerkObject = jniEnv->GetStaticObjectField(perkFactoryPerksClass, aimingPerkFieldId);
	if (aimingPerkObject == nullptr)
	{
		std::cout << "[!] Failed to retrieve PerkFactory.aiming object.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, addXPMethodId, aimingPerkObject, 1000.0f);
}

void AddXpToSkills2()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}
	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}
	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}
	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}
	const auto perkFactoryClass = jniEnv->FindClass("zombie/characters/skills/PerkFactory");
	if (perkFactoryClass == nullptr) {
		std::cout << "[!] Failed to retrieve PerkFactory Class.\n";
		return;
	}

	const auto aimingPerk = jniEnv->GetStaticObjectField(perkFactoryClass, jniEnv->GetStaticFieldID(perkFactoryClass, "AIMING", "Lzombie/characters/skills/PerkType;"));
	if (aimingPerk == nullptr) {
		std::cout << "[!] Failed to retrieve Aiming Field.\n";
		return;
	}

	const auto xpClass = jniEnv->FindClass("zombie/characters/IsoGameCharacter$XP");
	if (xpClass == nullptr) {
		std::cout << "[!] Failed to retrieve IsoGameCharacterXP Class.\n";
		return;
	}

	const auto addXPMethod = jniEnv->GetMethodID(xpClass, "AddXP", "(Lzombie/characters/skills/PerkType;F)V");
	if (addXPMethod == nullptr) {
		std::cout << "[!] Failed to retrieve IsoGameCharacterXP::AddXP Method.\n";
		return;
	}

	jniEnv->CallVoidMethod(playerInstance, addXPMethod, aimingPerk, 1000.0f);
}


/*
void SetLevelUpMultiplier(float levelUpMultiplier)
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}
	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}
	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setLevelUpMultiplierMethodId = jniEnv->GetMethodID(isoPlayerClass, "setLevelUpMultiplier", "(F)V");
	if (setLevelUpMultiplierMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::setLevelUpMultiplier method.\n";
		return;
	}
	jniEnv->CallVoidMethod(playerInstance, setLevelUpMultiplierMethodId, levelUpMultiplier);
}
*/
/*//BASE
void InvisibleCheatOFF()
{
	const auto jvmHandle = GetModuleHandleW(L"jvm.dll");
	if (jvmHandle == nullptr)
	{
		std::cout << "[!] Failed to retrieve handle for jvm.dll !\n";
		return;
	}

	const auto jniGetCreatedJavaVMs = reinterpret_cast<jniGetCreatedJavaVMs_t>(GetProcAddress(
		jvmHandle, "JNI_GetCreatedJavaVMs"));

	JavaVM* javaVm = nullptr;
	jniGetCreatedJavaVMs(&javaVm, 1, nullptr);
	if (javaVm == nullptr)
	{
		std::cout << "[!] Failed to retrieve created Java VMs!\n";
		return;
	}
	JNIEnv* jniEnv = nullptr;

	javaVm->AttachCurrentThread(reinterpret_cast<void**>(&jniEnv), nullptr);
	if (jniEnv == nullptr)
	{
		std::cout << "[!] Failed to attach to the Java VM.\n";
		return;
	}

	const auto isoPlayerClass = jniEnv->FindClass("zombie/characters/IsoPlayer");
	if (isoPlayerClass == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer class.\n";
		return;
	}

	const auto hasInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "hasInstance", "()Z");
	if (hasInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrive IsoPlayer::hasInstance method.\n";
		return;
	}

	const auto playerHasInstance = jniEnv->CallStaticBooleanMethod(isoPlayerClass, hasInstanceMethodId);
	if (!playerHasInstance)
	{
		std::cout << "[!] IsoPlayer::hasInstance returned false.\n";
		return;
	}

	const auto getInstanceMethodId = jniEnv->GetStaticMethodID(isoPlayerClass, "getInstance", "()Lzombie/characters/IsoPlayer;");
	if (getInstanceMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoPlayer::getInstance method.\n";
		return;
	}

	const auto playerInstance = jniEnv->CallStaticObjectMethod(isoPlayerClass, getInstanceMethodId);
	if (playerInstance == nullptr)
	{
		std::cout << "[!] IsoPlayer::getInstance returned nullptr!\n";
		return;
	}

	const auto setGodModMethodId = jniEnv->GetMethodID(isoPlayerClass, "setGodMod", "(Z)V");
	if (setGodModMethodId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setGodMod method.\n";
		return;
	}

	const auto setUnlimitedCarryId = jniEnv->GetMethodID(isoPlayerClass, "setUnlimitedCarry", "(Z)V");
	if (setUnlimitedCarryId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setUnlimitedCarry method.\n";
		return;
	}
	const auto setUnlimitedEnduranceId = jniEnv->GetMethodID(isoPlayerClass, "setUnlimitedEndurance", "(Z)V");
	if (setUnlimitedEnduranceId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setUnlimitedEndurance method.\n";
		return;
	}
	const auto setBuildCheatId = jniEnv->GetMethodID(isoPlayerClass, "setBuildCheat", "(Z)V");
	if (setBuildCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setBuildCheat method.\n";
		return;
	}
	const auto setFarmingCheatId = jniEnv->GetMethodID(isoPlayerClass, "setFarmingCheat", "(Z)V");
	if (setFarmingCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setFarmingCheat method.\n";
		return;
	}
	const auto setHealthCheatId = jniEnv->GetMethodID(isoPlayerClass, "setHealthCheat", "(Z)V");
	if (setHealthCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setHealthCheat method.\n";
		return;
	}
	const auto setMechanicsCheatId = jniEnv->GetMethodID(isoPlayerClass, "setMechanicsCheat", "(Z)V");
	if (setMechanicsCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setMechanicsCheat method.\n";
		return;
	}
	const auto setMovablesCheatId = jniEnv->GetMethodID(isoPlayerClass, "setMovablesCheat", "(Z)V");
	if (setMovablesCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setMovablesCheat method.\n";
		return;
	}
	const auto setTimedActionInstantCheatId = jniEnv->GetMethodID(isoPlayerClass, "setTimedActionInstantCheat", "(Z)V");
	if (setTimedActionInstantCheatId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setTimedActionInstantCheat method.\n";
		return;
	}
	const auto setLevelUpMultiplierId = jniEnv->GetMethodID(isoPlayerClass, "setLevelUpMultiplier", "(F)V");
	if (setLevelUpMultiplierId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setLevelUpMultiplier method.\n";
		return;
	}
	const auto setSuperAttackId = jniEnv->GetMethodID(isoPlayerClass, "setSuperAttack", "(Z)V");
	if (setSuperAttackId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setSuperAttack method.\n";
		return;
	}
	const auto setRecoilDelayId = jniEnv->GetMethodID(isoPlayerClass, "setRecoilDelay", "(F)V");
	if (setRecoilDelayId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setRecoilDelay method.\n";
		return;
	}
	const auto setInvisibleId = jniEnv->GetMethodID(isoPlayerClass, "setInvisible", "(Z)V");
	if (setInvisibleId == nullptr)
	{
		std::cout << "[!] Failed to retrieve IsoGameCharacter::setInvisible method.\n";
		return;
	}
	//actions :
	jniEnv->CallVoidMethod(playerInstance, setGodModMethodId, 1); // Activate Gode Mode
	jniEnv->CallVoidMethod(playerInstance, setUnlimitedCarryId, 1);// Activate Unlimited Carry
	jniEnv->CallVoidMethod(playerInstance, setUnlimitedEnduranceId, 1); // Activate Unlimited Endurance
	jniEnv->CallVoidMethod(playerInstance, setBuildCheatId, 1); // Activate Build Infini
	jniEnv->CallVoidMethod(playerInstance, setFarmingCheatId, 1); // Activate Farming Cheat
	jniEnv->CallVoidMethod(playerInstance, setHealthCheatId, 1); // Activate Health cheat
	jniEnv->CallVoidMethod(playerInstance, setMechanicsCheatId, 1); // Activate Mechanics Cheats
	jniEnv->CallVoidMethod(playerInstance, setMovablesCheatId, 1); // Activate Movables Cheats
	jniEnv->CallVoidMethod(playerInstance, setTimedActionInstantCheatId, 1); // Activate Instant Action
	jniEnv->CallVoidMethod(playerInstance, setLevelUpMultiplierId, 5000); // Activate xp multiplier
	jniEnv->CallVoidMethod(playerInstance, setSuperAttackId, 1); // Activate Super Attack
	jniEnv->CallVoidMethod(playerInstance, setRecoilDelayId, 0); // Activate No Recoil
	jniEnv->CallVoidMethod(playerInstance, setInvisibleId, 0); // Activate Invisible
}
*/


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
        if (ImGui::Button("God Mode ON"))
        {
            GodModeON();
        }
		if (ImGui::Button("God Mode OFF"))
		{
			GodModeOFF();
		}
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
			LevelMultiplierOFF();
		}
		if (ImGui::Button("TEST"))
		{
			AddXpToSkills();
		}
		if (ImGui::Button("TEST2"))
		{
			AddXpToSkills2();
		}
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

		std::cout << "Bonjour, console!" << std::endl;

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
