// Win32DllVampPluggin.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "VampPlugginDll.h"

#define DLLVAMPPLUGGIN_EXPORTS true

#include "Header.h"
#include <iostream>
#include <string>
#include "src/Rhythm.h"
#include <vamp-sdk\RealTime.h>

namespace Win32DllVampPluggin {

	extern "C++" __declspec(dllexport) MainClass* instance = 0;

	extern "C++" __declspec(dllexport) Rhythm* rhythmInstance = 0;

	extern "C++" __declspec(dllexport) Pitch* pitchInstance = 0;

	MainClass::MainClass() : count(0)
	{};
	

	MainClass& MainClass::getInstance()
	{
		if (instance == NULL)
		{
			instance = new MainClass();
		}

		return *instance;
	}

	int MainClass::callCount()
	{
		return getInstance().count++;
	}

	Rhythm* getRhythmInstance() {
		if (rhythmInstance == NULL)
		{
			rhythmInstance = new Rhythm(48800);
		}

		return rhythmInstance;
	}

	Pitch* getPitchInstance() {
		if (pitchInstance == NULL)
		{
			pitchInstance = new Pitch(48800);
		}

		return pitchInstance;
	}

	extern "C" __declspec(dllexport) int Initialize() {

		return MainClass::callCount();
	}

	extern "C" __declspec(dllexport) bool InitializeRhythm() {

		Rhythm* rhythm = getRhythmInstance();
		Pitch* pitch = getPitchInstance();

		if (rhythm != NULL)
		{
			rhythm->initialise(1,15,15);
			pitch->initialise(1,5,10);
			return true;
		}

		return false;
	}

	extern "C" __declspec(dllexport) bool feedRhythmWithData(float* data, float timeStamp) {

		Rhythm* rhythm = getRhythmInstance();

		float ** processData = new float*[1];
		processData[0] = data;

		Vamp::RealTime t = Vamp::RealTime::fromMilliseconds(timeStamp);
		rhythm->process(processData, t);
	}

	extern "C" __declspec(dllexport) bool feedPitchWithData(float* data, float timeStamp) {

		Pitch* pitch = getPitchInstance();

		float ** processData = new float*[1];
		processData[0] = data;

		Vamp::RealTime t = Vamp::RealTime::fromMilliseconds(100.0f);
		pitch->process(processData, t);
	}
}
