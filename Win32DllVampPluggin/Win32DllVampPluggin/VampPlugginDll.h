#pragma once

#ifdef DLLVAMPPLUGGIN_EXPORTS
#define DLLVAMPPLUGGIN_API __declspec(dllexport)
#else
#define DLLVAMPPLUGGIN_API __declspec(dllimport)
#endif

