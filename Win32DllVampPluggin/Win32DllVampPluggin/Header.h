#pragma once
#include "VampPlugginDll.h"
#include <string>
#include "src/Energy.h"
#include "src/Intensity.h"
#include "src/Peaks.h"
#include "src/Rhythm.h"
#include "src/SpectralFlux.h"
#include "src/SpectralContrast.h"
#include "src/SpeechMusicSegmenter.h"
#include "src/Pitch.h"

namespace Win32DllVampPluggin {
	 class MainClass {
		public :
			MainClass();

			int count = 0;

			static MainClass& getInstance();

			static int callCount();

	};

	 class RhythmListener {
		 
	 };

}