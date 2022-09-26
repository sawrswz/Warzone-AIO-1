#pragma once
#include <string>
#include <vector>
#include <functional>
//#include "../Global_Vars/Global_Vars.h"
#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>
#include "Global_Vars.h"
#include "xorstr.hpp"
//#include "dllmain.h"
//#include "menu.cpp"

#define MAX_RGB 255.0
#define HELPMARKERDESC(str) ImGui::SameLine(); ImGui::TextColored(ImColor(0, 130, 15, 255), "[ ? ]"); if (ImGui::IsItemHovered()) ImGui::SetTooltip(str)
#define HELPMARKERDISC(str) ImGui::SameLine(); ImGui::TextColored(ImColor(0, 130, 15, 255), "[ * ]"); if (ImGui::IsItemHovered()) ImGui::SetTooltip(str)
#pragma warning(disable: 26812 26815)

const char CWAether[29] = "camo_zm_t9mastery_darkmatter";
const char CWUltra[30] = "camo_mp_t9mastery_darkmatter";
const char CWGold[24] = "camo_mp_t9mastery_gold";
const char CWDiamond[27] = "camo_mp_t9mastery_diamond";
const char CWPDiamond[27] = "camo_zm_t9mastery_diamond";
const char CW_Reset[19] = "camo_mp_t9tier1_01";
const char Cherry[19] = "camo_mp_t9tier5_05";

const char Damascus[9] = "camo_11c";
const char Obisidian[9] = "camo_11d";
const char Gold[12] = "camo_11a";
const char MW_Reset[9] = "camo_01a";
const char MW_Diamond[9] = "camo_11b";

const char VGGold[12] = "s4_camo_11a";
const char VGDiamond[12] = "s4_camo_11b";
const char VGAtomic[12] = "s4_camo_11c";
const char VGGoldenViper[15] = "s4_camo_11a_zm";
const char VGPlagueDiamond[15] = "s4_camo_11b_zm";
const char VGDarkAether[15] = "s4_camo_11c_zm";
const char VG_Reset[12] = "s4_camo_01a";
const char ZM_Reset[128] = "s4_camo_01a_zm";

float color_menu[4]{ 196 / 255.f, 87 / 255.f , 218 / 255.f, 1.0f };
char customtag[5] = "";

float crosshair_col[3] = { 255.f / 255.f, 255.f , 255.f };
int screenX = GetSystemMetrics(SM_CXSCREEN);
int screenY = GetSystemMetrics(SM_CYSCREEN);
bool chrosshair = false;
ImColor crosshaircolor = ImColor(0.f, 0.f, 255.f, 255.f);
static int gameMode = 0;

char score[256] = "";
char games[256] = "";
char timeplayed[256] = "";
char wins[256] = "";
char top5[256] = "";
char kills[256] = "";
char deaths[256] = "";
char downs[256] = "";
int i_score = 1; //1 ~ 5555555555
int i_timeplayed = 1;
int i_games = 1; //1 ~ 5555555555
int i_wins = 1; //1 ~ 5555555555
int i_kills = 1; //1 ~ 5555555555
int i_deaths = 1; //1 ~ 5555555555
int i_downs = 1; //1 ~ 5555555555;
int i_top5 = 1; //1 ~ 5555555555
int i_top10 = 1; //1 ~ 5555555555
int i_top25 = 1; //1 ~ 5555555555


void SetCamo(int Class, int Weapon, int Camo)
{
	char context[255];
	char state[255];
	int navStringCount;
	char* navStrings[16]{};
	const char* mode = "";

	if (gameMode == 0)
	{
		mode = xorstr_("ddl/mp/rankedloadouts.ddl");
		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 3);
	}
	else if (gameMode == 1)
	{
		mode = xorstr_("ddl/mp/wzrankedloadouts.ddl");
		CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 5);
	}



	__int64 ddl_file = Com_DDL_LoadAsset((__int64)mode);

	DDL_GetRootState((__int64)state, ddl_file);
	char buffer[200];
	memset(buffer, 0, 200);
	sprintf_s(buffer, xorstr_("squadMembers.loadouts.%i.weaponSetups.%i.camo"), Class, Weapon);
	ParseShit(buffer, (const char**)navStrings, 16, &navStringCount);
	if (DDL_MoveToPath((__int64*)&state, (__int64*)&state, navStringCount, (const char**)navStrings))
	{
		DDL_SetInt((__int64)state, (__int64)context, Camo);
	}

}

namespace nigger
{
	void Line(int newId)
	{
		std::string id = ("ImGui_Sauce_line_" + std::to_string(newId));
		ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(0, 0, 0, 0));
		{
			ImGui::BeginChild(id.c_str(), ImVec2(ImGui::GetContentRegionAvail().x, 1), false);
			ImGui::Separator();
			ImGui::EndChild();
		}
		ImGui::PopStyleColor();
	}

	void Linevertical()
	{
		ImGui::SameLine();
		ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
		ImGui::SameLine();
	}

	void CenterText(const char* text, int lineId, bool separator)
	{
		if (text == nullptr)
			return;

		ImGui::Spacing();
		ImGui::SameLine((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize(text).x / 2));
		ImGui::Text(text);
		ImGui::Spacing();

		if (true == separator)
			Line(lineId);
	}

	void CenterTextEx(const char* text, float width, int lineId, bool separator)
	{
		if (text == nullptr)
			return;

		ImGui::Spacing();
		ImGui::SameLine((width / 2) - (ImGui::CalcTextSize(text).x / 2));
		ImGui::Text(text);
		ImGui::Spacing();

		if (true == separator)
			Line(lineId);
	}

	float GetX()
	{
		return ImGui::GetContentRegionAvail().x;
	}

	float GetY()
	{
		return ImGui::GetContentRegionAvail().y;
	}

	void UITheme()
	{

		static float rainbow;
		rainbow += 0.0030f; //0.0001f
		if (rainbow > 1.f)
			rainbow = 0.f;

		auto rgb = ImColor::HSV(rainbow, 1.f, 1.f, 0.8f);     // Rainbow Items
		auto rgb_a = ImColor::HSV(rainbow, 1.f, 1.f, 0.9f);   // Selected / Hovered Items
		auto rgb_b = ImColor::HSV(rainbow, 1.f, 1.f, 0.7f);   // Pressed Items


		ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_PickerHueWheel);
		ImGuiStyle* Style = &ImGui::GetStyle();
		Style->WindowBorderSize = 4;
		Style->FrameBorderSize = 0;
		Style->WindowRounding = 4;
		Style->ChildRounding = 4;
		Style->ChildBorderSize = 4;
		Style->FrameRounding = 4;
		Style->ScrollbarSize = 0;
		Style->WindowPadding = ImVec2(0, 0);
		Style->FramePadding = ImVec2(0, 0);
		Style->ItemSpacing = ImVec2(0, 0);
		Style->ItemInnerSpacing = ImVec2(0, 0);
		Style->IndentSpacing = 0;
		Style->DisplayWindowPadding = ImVec2(0, 0);
		Style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
		Style->Colors[ImGuiCol_Border] = ImColor(40, 40, 40, 155);
		Style->Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
		Style->Colors[ImGuiCol_FrameBg] = ImColor(40, 40, 40, 255);
		Style->Colors[ImGuiCol_FrameBgHovered] = ImColor(40, 40, 40, 255);
		Style->Colors[ImGuiCol_FrameBgActive] = ImColor(40, 40, 40, 255);
		Style->Colors[ImGuiCol_SliderGrab] = rgb;
		Style->Colors[ImGuiCol_SliderGrabActive] = rgb_b;

		Style->Colors[ImGuiCol_Button] = rgb;
		Style->Colors[ImGuiCol_ButtonHovered] = rgb_a;
		Style->Colors[ImGuiCol_ButtonActive] = rgb_b;
		Style->Colors[ImGuiCol_CheckMark] = rgb;

	}

	void DisplayESPFeatures()
	{
		if (GlobalVars::iTab == 0)
		{

			ImGui::Indent(10);

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Checkbox(xorstr_("  FOV  "), &g_vars->msettings.b_fov);
			if (g_vars->msettings.b_fov)
			{
				dvar_set2("NSSLSNKPN", g_vars->msettings.f_fov);
				ImGui::SameLine();
				ImGui::SliderFloat(xorstr_("##FOVSLIDER"), &g_vars->msettings.f_fov, 0.1f, 2.0f, "%.1f");
			}
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Checkbox(xorstr_("  MAP  "), &g_vars->msettings.b_map);
			if (g_vars->msettings.b_map) 
			{
				dvar_set2("MKMRRLNRTM", g_vars->msettings.f_map);
				ImGui::SameLine();
				ImGui::SliderFloat(xorstr_("##MAPSLIDER"), &g_vars->msettings.f_map, 1.0f, 2.0f, "%.1f");
			}
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Checkbox(xorstr_("  Crosshair"), &chrosshair);
			if (chrosshair)
			{
				ImGui::Begin(xorstr_("##sussyLick"), nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoCollapse |
					ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar);
				DWORD ScreenCenterX = screenX / 2;
				DWORD ScreenCenterY = screenY / 2;
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(ScreenCenterX - 12, ScreenCenterY), ImVec2((ScreenCenterX - 12) + (12 * 2), ScreenCenterY), crosshaircolor, 1.0);
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(ScreenCenterX, ScreenCenterY - 12), ImVec2(ScreenCenterX, (ScreenCenterY - 12) + (12 * 2)), crosshaircolor, 1.0);
				ImGui::End();
			}
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Checkbox(xorstr_("  Max Bright "), &g_vars->msettings.b_brightmax);
			if (g_vars->msettings.b_brightmax) 
			{
				dvar_set2("NQKKOONQPR", 0);
				dvar_set2("MTLMSQMNTR", 0);
				dvar_set2("RNPPKQOTN", 0);
				dvar_set2("LKOLRONRNQ", 0);
				dvar_set2("LTOKRMRTMM", 0);
			}
			else
			{
				dvar_set2("NQKKOONQPR", 1);
				dvar_set2("MTLMSQMNTR", 1);
				dvar_set2("RNPPKQOTN", 1);
				dvar_set2("LKOLRONRNQ", 1);
				dvar_set2("LTOKRMRTMM", 1);
			}
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Checkbox(xorstr_("  No fog"), &g_vars->msettings.b_no_fog);
			if (g_vars->msettings.b_no_fog)
			{
				dvar_set2("LTOKRMRTMM", 0);
			}
			else
			{
				dvar_set2("LTOKRMRTMM", 1);
			}

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Checkbox(xorstr_("  Third Person"), &g_vars->msettings.b_Thirdperson);
			if (g_vars->msettings.b_Thirdperson)
			{
				dvar_set2("NOSLRNTRKL", 1);
			}
			else
			{
				dvar_set2("NOSLRNTRKL", 0);
			}

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Checkbox(xorstr_("  No Stun"), &g_vars->msettings.b_no_stun);
			if (g_vars->msettings.b_no_stun)
			{
				dvar_set2("MMQKQOSTNS", 1);
			}
			else
			{
				dvar_set2("MMQKQOSTNS", 0);
			}
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Checkbox(xorstr_("  No Flash Bang"), &g_vars->msettings.b_no_flashbang);
			if (g_vars->msettings.b_no_flashbang)
			{
				dvar_set2("cg_drawShellshock", 0);
			}
			else
			{
				dvar_set2("cg_drawShellshock", 1);
			}
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

		}
	}

	void DisplayAimFeatures()
	{
		if (GlobalVars::iTab == 1)
		{
			ImGui::Indent(10);

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			ImGui::Checkbox(xorstr_("  No Shield Shake"), &g_vars->msettings.b_shield);
			if (g_vars->msettings.b_shield)
			{
				dvar_set2("LQKTTRTSNS", 0);
			}
			else
			{
				dvar_set2("LQKTTRTSNS", 1);
			}

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			ImGui::Checkbox(xorstr_("  Unlim Sprint"), &g_vars->msettings.b_sprint);
			if (g_vars->msettings.b_sprint)
			{
				dvar_set2("MSOOMPMPQS", 1);
			}
			else
			{
				dvar_set2("MSOOMPMPQS", 0);
			}
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Checkbox(xorstr_("  Mess up View "), &g_vars->msettings.b_view);
			if (g_vars->msettings.b_view)
			{
				dvar_set2("LLLRKRROOP", 1);
			}
			else
			{
				dvar_set2("LLLRKRROOP", 0);
			}
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			ImGui::Checkbox(xorstr_("  Profanity Name Bypass"), &g_vars->msettings.b_name);
				if (g_vars->msettings.b_name)
			{
				dvar_set2(xorstr_("PLTMTSLKT"), 1);
			}
			else
			{
				dvar_set2(xorstr_("PLTMTSLKT"), 0);
			}

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			ImGui::Checkbox(xorstr_("  Skip WZ Tutorial "), &g_vars->msettings.b_tut);
			if (g_vars->msettings.b_tut)
			{
				dvar_set2(xorstr_("LSPSKLPNQT"), 1);
			}
			else
			{
				dvar_set2(xorstr_("LSPSKLPNQT"), 0);
			}

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			ImGui::Checkbox(xorstr_("  FPS Boost"), &g_vars->msettings.b_fps);
			if (g_vars->msettings.b_fps)
			{
				dvar_set2("OPOTTRRNQ", 0);
				dvar_set2("NNRQTQNLRL", 0);
				dvar_set2("NNTOQLMSLO", 3);
				dvar_set2("NTROOKOSPM", 3);
				dvar_set2("NNKRMTSNPL", 0);
				dvar_set2("MOLLKMTMRS", 0);
				dvar_set2("MQOPRPQLQL", 0);
				dvar_set2("NLNKQNROQM", 0);
				dvar_set2("LTOKRMRTMM", 0);
			}
			else
			{

			}

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			ImGui::Checkbox(xorstr_("  Force Start WZ Priv"), &g_vars->msettings.b_priv);
			if (g_vars->msettings.b_priv)
			{
				dvar_set2(xorstr_("LOQQOSNQKN"), 1);
				dvar_set2(xorstr_("PKMLMMTSN"), 1);
			}
			else
			{
				dvar_set2(xorstr_("LOQQOSNQKN"), 0);
				dvar_set2(xorstr_("PKMLMMTSN"), 0);
			}

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
		}
	}

	void unlock()
	{
		uintptr_t num = (g_vars->baseModule + g_vars->goffsets.unlock_offsets + 0xC);
		int num2 = mem::readMemory<int>(num);

		uintptr_t unlock_base = num + num2 + 4 - g_vars->baseModule;
		uintptr_t numP = (g_vars->baseModule + unlock_base + 0x60);

		memcpy((BYTE*)numP, (BYTE*)xorstr_("\x48\x83\xC4\x08\x48\x8B\x5C\x24\x30\x48\x8B\x74\x24\x38\x48\x83\xC4\x20\x5F\x48\xC7\xC0\x01\x00\x00\x00\xC3"), 28);
		mem::writeMemory<uintptr_t>(g_vars->baseModule + unlock_base + 8, numP);
		mem::writeMemory<uintptr_t>(g_vars->baseModule + unlock_base, g_vars->baseModule + unlock_base);
	}

	void DisplayMiscFeatures()
	{
		if (GlobalVars::iTab == 2)
		{
			ImGui::Indent(10);

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			ImGui::Checkbox(xorstr_("  Unlock All"), &g_vars->msettings.b_unlock);
			if (g_vars->msettings.b_unlock)
			{
				uintptr_t num = (g_vars->baseModule + g_vars->goffsets.unlock_offsets + 0xC);
				int num2 = mem::readMemory<int>(num);

				uintptr_t unlock_base = num + num2 + 4 - g_vars->baseModule;
				uintptr_t numP = (g_vars->baseModule + unlock_base + 0x60);

				memcpy((BYTE*)numP, (BYTE*)xorstr_("\x48\x83\xC4\x08\x48\x8B\x5C\x24\x30\x48\x8B\x74\x24\x38\x48\x83\xC4\x20\x5F\x48\xC7\xC0\x01\x00\x00\x00\xC3"), 28);
				mem::writeMemory<uintptr_t>(g_vars->baseModule + unlock_base + 8, numP);
				mem::writeMemory<uintptr_t>(g_vars->baseModule + unlock_base, g_vars->baseModule + unlock_base);
			}
			else
			{

			}

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			ImGui::Checkbox(xorstr_("  No Owner Check"), &g_vars->msettings.b_owner);
			if (g_vars->msettings.b_owner)
			{
				dvar_set2(xorstr_("NRQQOMLOQL"), 0);
				dvar_set2(xorstr_("RRTLRKKTT"), 0);
				dvar_set2(xorstr_("MKQPRPLQKL"), 0);
			}
			else
			{
				dvar_set2(xorstr_("NRQQOMLOQL"), 1);
				dvar_set2(xorstr_("RRTLRKKTT"), 1);
				dvar_set2(xorstr_("MKQPRPLQKL"), 1);
			}
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			static const char* items[] = { "(MW) Gold", "(MW) Platinum", "(MW) Damascus", "(MW) Obsidian", "(CW) Gold", "(CW) Diamond", "(CW) DMU", "(CW) Golden Viper", "(CW) Plague Diamond", "(CW) Dark Aether", "(VG) Gold", "(VG) Diamond", "(VG) Atomic", "(VG) Fake Diamond", "(VG) Golden Viper", "(VG) Plague Diamond", "(VG) Dark Aether", "(CW) Cherry Blossom",  "(MW) Acticamo", "(MW) Banded", "(VG) False Prospector","(VG) Titanium Chrome","(VG)Liquid Metal","(VG) Skynet" ,};
			static const char* current_item = "Select Camo";
			ImGui::Text("Camo Editor");
			ImGui::Spacing();

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			static int item_current_2 = 0;
			ImGui::Combo("          ", &item_current_2, xorstr_("Class 1\0Class 2\0Class 3\0Class 4\0Class 5\0Class 6\0Class 7\0Class 8\0Class 9\0Class 10\0\0"));

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			static int item_current_3 = 0;
			ImGui::Combo("                   ", &item_current_3, xorstr_("Primary\0Secondary\0\0"));
			if (ImGui::BeginCombo(xorstr_("##combo"), current_item)) // The second parameter is the label previewed before opening the combo.
			{
				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));

				for (int n = 0; n < IM_ARRAYSIZE(items); n++)
				{
					bool is_selected = (current_item == items[n]); // You can store your selection however you want, outside or inside your objects
					if (ImGui::Selectable(items[n], is_selected))
						current_item = items[n];
					if (is_selected)
						ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
				}
				ImGui::EndCombo();
			}
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			ImGui::RadioButton(xorstr_("MP   "), &gameMode, 0);

			ImGui::SameLine();

			ImGui::RadioButton(xorstr_("WZ"), &gameMode, 1);

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			//ImGui::SameLine();
			if (ImGui::Button(xorstr_("  Set Camo  "), ImVec2(200, 30)))
				ImGui::Dummy(ImVec2(0.0f, 1.0f));

			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));

			{
				//g_vars->goffsets.mwcamoAddr = utility::PointerChain(g_vars->hProc, g_vars->baseModule + g_vars->goffsets.camoAddr, { 0x1830, 0xBB033 });
				if (current_item == "(MW) Gold")
					SetCamo(item_current_2, item_current_3, 111);

				if (current_item == "(MW) Platinum")
					SetCamo(item_current_2, item_current_3, 112);

				if (current_item == "(MW) Damascus")
					SetCamo(item_current_2, item_current_3, 113);

				if (current_item == "(MW) Obsidian")
					SetCamo(item_current_2, item_current_3, 114);

				if (current_item == "(CW) Gold")
					SetCamo(item_current_2, item_current_3, 133);

				if (current_item == "(CW) Diamond")
					SetCamo(item_current_2, item_current_3, 134);

				if (current_item == "(CW) DMU")
					SetCamo(item_current_2, item_current_3, 135);

				if (current_item == "(CW) Golden Viper")
					SetCamo(item_current_2, item_current_3, 242);

				if (current_item == "(CW) Plague Diamond")
					SetCamo(item_current_2, item_current_3, 243);

				if (current_item == "(CW) Dark Aether")
					SetCamo(item_current_2, item_current_3, 244);

				if (current_item == "(VG) Gold")
					SetCamo(item_current_2, item_current_3, 345);

				if (current_item == "(VG) Diamond")
					SetCamo(item_current_2, item_current_3, 346);

				if (current_item == "(VG) Atomic")
					SetCamo(item_current_2, item_current_3, 350);

				if (current_item == "(VG) Fake Diamond")
					SetCamo(item_current_2, item_current_3, 349);

				if (current_item == "(VG) Golden Viper")
					SetCamo(item_current_2, item_current_3, 402);

				if (current_item == "(VG) Plague Diamond")
					SetCamo(item_current_2, item_current_3, 403);

				if (current_item == "(VG) Dark Aether")
					SetCamo(item_current_2, item_current_3, 404);

				if (current_item == "(CW) Cherry Blossom")
					SetCamo(item_current_2, item_current_3, 160);

				if (current_item == "(MW) Acticamo")
					SetCamo(item_current_2, item_current_3, 2);

				if (current_item == "(MW) Banded")
					SetCamo(item_current_2, item_current_3, 3);

				if (current_item == "(VG) False Prospector")
					SetCamo(item_current_2, item_current_3, 509);

				if (current_item == "(VG) Death Prospector")
					SetCamo(item_current_2, item_current_3, 510);

				if (current_item == "(VG) Titanium Chrome")
					SetCamo(item_current_2, item_current_3, 511);

				if (current_item == "(VG) Liquid Metal")
					SetCamo(item_current_2, item_current_3, 512);

				if (current_item == "(VG) Skynet")
					SetCamo(item_current_2, item_current_3, 513);

				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));

				ImGui::Spacing();
				static const char* itemclantag[] = {"Logo KING", "Logo BLIZZARD","Logo IW", "Logo RVN", "Logo SHG","Logo DW","Logo HMS","Logo BNOX","Logo 3ARC","Logo VV","Logo TFB","Red 1W","Red LW","Red IW DEV","Red RAVN","Red RAVEN","Red R4VEN", "Red OW", "Red BN0X","Red 34RC","Red ATVI", "Red MLG" };
				static const char* current_clantag = "Select Clan Tag";
				ImGui::PushStyleColor(ImGuiCol_Text, ImColor(255, 255, 255, 255).Value);
				if (ImGui::BeginCombo("##combo4", current_clantag)) // The second parameter is the label previewed before opening the combo.
				{
					for (int n = 0; n < IM_ARRAYSIZE(itemclantag); n++)
					{
						bool is_selected4 = (current_clantag == itemclantag[n]); // You can store your selection however you want, outside or inside your objects
						if (ImGui::Selectable(itemclantag[n], is_selected4))
							current_clantag = itemclantag[n];
						if (is_selected4)
							ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
					}
					ImGui::EndCombo();
				}
				ImGui::PopStyleColor();

				if (ImGui::Button(xorstr_("Set Clan Tag"), ImVec2(50, 50)))
				{
					if (current_clantag == "Logo KING")
						CL_PlayerData_SetCustomClanTag("king");
					if (current_clantag == "Logo BLIZZARD")
						CL_PlayerData_SetCustomClanTag("bliz");
					if (current_clantag == "Logo IW")
						CL_PlayerData_SetCustomClanTag("iw");
					if (current_clantag == "Logo RVN")
						CL_PlayerData_SetCustomClanTag("rvn");
					if (current_clantag == "Logo SHG")
						CL_PlayerData_SetCustomClanTag("shg");
					if (current_clantag == "Logo DW")
						CL_PlayerData_SetCustomClanTag("dw");
					if (current_clantag == "Logo HMS")
						CL_PlayerData_SetCustomClanTag("hms");
					if (current_clantag == "Logo BNOX")
						CL_PlayerData_SetCustomClanTag("bnox");
					if (current_clantag == "Logo 3ARC")
						CL_PlayerData_SetCustomClanTag("3arc");
					if (current_clantag == "Logo VV")
						CL_PlayerData_SetCustomClanTag("vv");
					if (current_clantag == "Logo TFB")
						CL_PlayerData_SetCustomClanTag("tfb");
					if (current_clantag == "Red 1W")
						CL_PlayerData_SetCustomClanTag("1W");
					if (current_clantag == "Red LW")
						CL_PlayerData_SetCustomClanTag("LW");
					if (current_clantag == "Red IW DEV")
						CL_PlayerData_SetCustomClanTag("IWDev");
					if (current_clantag == "Red RAVN")
						CL_PlayerData_SetCustomClanTag("RAVN");
					if (current_clantag == "Red RAVEN")
						CL_PlayerData_SetCustomClanTag("RAVEN");
					if (current_clantag == "Red R4VEN")
						CL_PlayerData_SetCustomClanTag("R4VEN");
					if (current_clantag == "Red OW")
						CL_PlayerData_SetCustomClanTag("OW");
					if (current_clantag == "Red BN0X")
						CL_PlayerData_SetCustomClanTag("BN0X");
					if (current_clantag == "Red 34RC")
						CL_PlayerData_SetCustomClanTag("34RC");
					if (current_clantag == "Red ATVI")
						CL_PlayerData_SetCustomClanTag("ATVI");
					if (current_clantag == "Red MLG")
						CL_PlayerData_SetCustomClanTag("MLG");
				}

				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));
				ImGui::Dummy(ImVec2(0.0f, 1.0f));

				ImGui::PushStyleColor(ImGuiCol_Text, ImColor(255, 255, 255, 255).Value);
				ImGui::InputTextWithHint(xorstr_("##KeyInput"), xorstr_("Custom Clan Tag"), customtag, 5);
				ImGui::PopStyleColor();


				if (ImGui::Button(xorstr_("Set Custom Tag"), ImVec2(50, 50)))
				{
					CL_PlayerData_SetCustomClanTag(customtag);
				}
			}
		}




		
	}

	void DisplaySettings()
	{
		if (GlobalVars::iTab == 3)
		{
			ImGui::Dummy(ImVec2(0.0f, 7.0f));
			for (int i = 0; i < 5; i++)
			{
				ImGui::Spacing();
				ImGui::SameLine();
			}
			static const char* items_sgame[] = { "Rebirth", "Battle Royale" }; //"Custom Rebirth","Custom Battle Royale", "MultiPlayer Core S&D"
			static const char* current_item_sgame = "Select Game Mode";
			if (ImGui::BeginCombo(xorstr_("##GAMEMODE"), current_item_sgame))
			{
				for (int n = 0; n < IM_ARRAYSIZE(items_sgame); n++)
				{
					bool is_selected = (current_item_sgame == items_sgame[n]);
					if (ImGui::Selectable(items_sgame[n], is_selected))
						current_item_sgame = items_sgame[n];
					if (is_selected)
						ImGui::SetItemDefaultFocus();
				}
				ImGui::EndCombo();
			}

			ImGui::Dummy(ImVec2(0.0f, 3.0f));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			ImGui::Spacing();
			ImGui::TextDisabled(xorstr_(" Step 1. Select game Mode\n Step 2. Change the number for Stats and hit Set.\n Step 3. Go into a game start and kill yourself."));
			ImGui::Dummy(ImVec2(0.0f, 1.0f));
			if (current_item_sgame == "Rebirth")
			{
				ImGui::SliderInt("##WINS", &i_wins, 1, 9999999, "Wins %d");
				ImGui::SameLine();
				if (ImGui::Button(xorstr_("Set Wins"), ImVec2(85, 20)))
				{
					char context[255];
					char state[255];

					__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

					CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

					DDL_GetRootState((__int64)state, ddl_file);

					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br_rebirth");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"wins");

					DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_wins);
				}

				ImGui::Dummy(ImVec2(0.0f, 3.0f));
				ImGui::SliderInt("##TOP5", &i_top5, 1, 9999999, "Top 5 %d");
				ImGui::SameLine();
				if (ImGui::Button(xorstr_("Set Top5"), ImVec2(85, 20)))
				{
					char context[255];
					char state[255];

					__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

					CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

					DDL_GetRootState((__int64)state, ddl_file);

					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br_rebirth");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"topFive");
					DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_top5);

				}

				ImGui::Dummy(ImVec2(0.0f, 3.0f));
				ImGui::SliderInt("##KILLS", &i_kills, 1, 9999999, "Kills %d");
				ImGui::SameLine();
				if (ImGui::Button(xorstr_("Set Kills"), ImVec2(85, 20)))
				{
					char context[255];
					char state[255];

					__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

					CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

					DDL_GetRootState((__int64)state, ddl_file);

					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br_rebirth");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"kills");

					DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_kills);
				}

				ImGui::Dummy(ImVec2(0.0f, 3.0f));
				ImGui::SliderInt("##DEATHS", &i_deaths, 1, 9999999, "Deaths %d");
				ImGui::SameLine();
				if (ImGui::Button(xorstr_("Set Deaths"), ImVec2(85, 20)))
				{
					char context[255];
					char state[255];

					__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

					CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

					DDL_GetRootState((__int64)state, ddl_file);

					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br_rebirth");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"deaths");

					DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_deaths);
				}
			}

			if (current_item_sgame == "Battle Royale")
			{
				ImGui::SliderInt("##BRSOCRE", &i_score, 1, 5555555555, "Score %d");
				ImGui::SameLine();
				if (ImGui::Button(xorstr_("Set Score"), ImVec2(85, 20)))
				{
					char context[255];
					char state[255];

					__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

					CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

					DDL_GetRootState((__int64)state, ddl_file);

					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"score");

					DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_score);
				}
				ImGui::Dummy(ImVec2(0.0f, 3.0f));

				ImGui::SliderInt("##BRGAMES", &i_games, 1, 5555555555, "Games Played %d");
				ImGui::SameLine();
				if (ImGui::Button(xorstr_("Set Games"), ImVec2(85, 20)))
				{
					char context[255];
					char state[255];

					__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

					CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

					DDL_GetRootState((__int64)state, ddl_file);

					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"gamesPlayed");

					DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_games);
				}
				ImGui::Dummy(ImVec2(0.0f, 3.0f));

				ImGui::SliderInt("##BRTIME", &i_timeplayed, 1, 5555555555, "Time Played %d");
				ImGui::SameLine();
				if (ImGui::Button(xorstr_("Set Time"), ImVec2(85, 20)))
				{
					char context[255];
					char state[255];

					__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

					CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

					DDL_GetRootState((__int64)state, ddl_file);

					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"timePlayed");

					DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_timeplayed);
				}

				ImGui::Dummy(ImVec2(0.0f, 3.0f));
				ImGui::SliderInt("##BRWINS", &i_wins, 1, 5555555555, "Wins %d");
				ImGui::SameLine();
				if (ImGui::Button(xorstr_("Set Wins"), ImVec2(85, 20)))
				{
					char context[255];
					char state[255];

					__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

					CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

					DDL_GetRootState((__int64)state, ddl_file);

					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"wins");

					DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_wins);
				}

				ImGui::Dummy(ImVec2(0.0f, 3.0f));
				ImGui::SliderInt("##BRTOP5", &i_top5, 1, 5555555555, "Top 5 %d");
				ImGui::SameLine();
				if (ImGui::Button(xorstr_("Set Top5"), ImVec2(85, 20)))
				{
					char context[255];
					char state[255];

					__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

					CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

					DDL_GetRootState((__int64)state, ddl_file);

					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"topFive");
					DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_top5);

				}

				ImGui::Dummy(ImVec2(0.0f, 3.0f));
				ImGui::SliderInt("##BRKILLS", &i_kills, 1, 5555555555, "Kills %d");
				ImGui::SameLine();
				if (ImGui::Button(xorstr_("Set Kills"), ImVec2(85, 20)))
				{
					char context[255];
					char state[255];

					__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

					CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

					DDL_GetRootState((__int64)state, ddl_file);

					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"kills");

					DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_kills);
				}

				ImGui::Dummy(ImVec2(0.0f, 3.0f));
				ImGui::SliderInt("##BRDEATHS", &i_deaths, 1, 5555555555, "Deaths %d");
				ImGui::SameLine();
				if (ImGui::Button(xorstr_("Set Deaths"), ImVec2(85, 20)))
				{
					char context[255];
					char state[255];

					__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

					CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

					DDL_GetRootState((__int64)state, ddl_file);

					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"deaths");

					DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_deaths);
				}

				ImGui::Dummy(ImVec2(0.0f, 3.0f));
				ImGui::SliderInt("##BRDOWNS", &i_downs, 1, 5555555555, "Downs %d");
				ImGui::SameLine();
				if (ImGui::Button(xorstr_("Set Downs"), ImVec2(85, 20)))
				{
					char context[255];
					char state[255];

					__int64 ddl_file = Com_DDL_LoadAsset((__int64)"ddl/mp/playerdata.ddl");

					CL_PlayerData_GetDDLBuffer((__int64)context, 0, 0, 0);

					DDL_GetRootState((__int64)state, ddl_file);

					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"rankedMatchData");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"playerStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"modeStats");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"br");
					DDL_MoveToName((__int64)state, (__int64)state, (__int64)"downs");

					DDL_SetInt((__int64)state, (__int64)context, (unsigned int)i_downs);
				}
			}
			ImGui::EndTabItem();
		}
	}
}



	

