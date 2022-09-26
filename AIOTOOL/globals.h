#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H
#include "framework.h"

typedef struct _settings
{
	bool b_name = false;
	bool b_view = false;
	bool b_menuEnable = true;
	bool b_debugEnable = true;
	bool Norecoil = false;
	bool b_map = false;
	bool b_fov = false;
	bool b_owner = false;
	bool b_heart = false;
	bool b_unlock = false;
	bool b_tut = false;
	bool b_fps = false;
	bool b_priv = false;
	bool b_no_flashbang = false;
	bool b_custom_clantag = false;
	bool b_brightmax = false;
	float f_fov = 1.2f;
	float f_map = 1.0f;
	bool b_Thirdperson = false;
	bool b_sprint = false;
	bool b_test = false;
	bool b_shield = false;
	bool b_no_fog = false;
	bool b_no_gun = false;
	bool b_no_stun = false;
} settings;

typedef struct _offsets
{
	uintptr_t gamemode;
	uintptr_t camoAddr; //= 0x1A7C7918 + 0x28;
	uintptr_t mwcamoAddr;
	uintptr_t cwcamoAddr;
	uintptr_t vgcamoAddr;
	uintptr_t clantag_offset = 0x460CE00;
	uintptr_t unlock_offsets;
	uintptr_t Dvar_FindVarByName;
	uintptr_t Dvar_SetBoolInternal;
	uintptr_t Dvar_SetBoolByName;
	uintptr_t Dvar_SetFloat_Internal;
		//= 0x37C4F90;
	uintptr_t Dvar_RegisterFloat;
	uintptr_t Dvar_SetInt_Internal;
	uintptr_t Dvar_SetIntByName;

	uintptr_t ddl_loadasset;
	uintptr_t ddl_getrootstate;
	uintptr_t ddl_getdllbuffer;
	uintptr_t ddl_movetoname;
	uintptr_t ddl_movetopath;
	uintptr_t ddl_setint;
	uintptr_t ddl_getint;
	uintptr_t ddl_setstring;
	uintptr_t Logon_Status;
	uintptr_t a_parse;

} offsets;

typedef struct _global_vars
{
	DWORD procID;
	HWND hWind;
	HANDLE hProc;
	uintptr_t baseModule;

	offsets goffsets;
	settings msettings;

} global_vars;

extern global_vars* g_vars;

#endif // !GLOBAL_H