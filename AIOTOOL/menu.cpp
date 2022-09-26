#include "menu.h"
#include "UI_Sauce.h"
#include "icons.h"




ImFont* MainCaps;
ImFont* Main;
ImFont* FMenu;

std::string chars{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()`~-_=+[{]{|;:'\",<.>/?" };
std::random_device rd;
std::mt19937 generator(rd());
// Randomize String.
std::string RandStr(size_t length)
{
    const size_t char_size = chars.size();
    std::uniform_int_distribution<> random_int(0, char_size - 1);
    std::string output;
    for (size_t i = 0; i < length; ++i)
        output.push_back(chars[random_int(generator)]);
    return output;
}

std::string sRandWin = RandStr(12);
std::string sRandBegin = RandStr(12);
std::string sRandChild1 = RandStr(12);
std::string sRandChild2 = RandStr(12);
std::string sRandChild3 = RandStr(12);
std::string sRandChild4 = RandStr(12);
std::string sRandChild5 = RandStr(12);
ImVec2 screen_Size = ImVec2(WND_SIZEX, WND_SIZEY);

void cMenu::DrawMenu()
{
    nigger::UITheme();

    ImGui::SetNextWindowPos(ImVec2(screen_Size.x / 2.75, screen_Size.y / 2.75), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(500, 275), ImGuiCond_Always);

    if (ImGui::Begin(sRandBegin.c_str(), 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar))
    {
   
        ImGui::SetCursorPos(ImVec2(115, 10));
        if (ImGui::BeginChild(sRandChild2.c_str(), ImVec2(375, 255), true, ImGuiWindowFlags_NoDecoration))
        {
            
            nigger::DisplayESPFeatures();

            
            nigger::DisplayAimFeatures();

            
            nigger::DisplayMiscFeatures();

            
            nigger::DisplaySettings();

        } ImGui::EndChild();

            
            ImGui::SetCursorPos(ImVec2(10, 10));
            if (ImGui::BeginChild(sRandChild3.c_str(), ImVec2(100, 255), true, ImGuiWindowFlags_NoDecoration))
            {
                
                ImGui::Spacing();
                ImGui::Text("AIO");
                ImGui::SetCursorPos(ImVec2(10, 30));
                if (ImGui::Button("Misc 1", ImVec2(80, 45)))
                {
                    GlobalVars::iTab = 0;
                }
                ImGui::NewLine();
                ImGui::SetCursorPos(ImVec2(10, 85));
                if (ImGui::Button("Misc 2", ImVec2(80, 45)))
                {
                    GlobalVars::iTab = 1;
                }
                ImGui::NewLine();
                ImGui::SetCursorPos(ImVec2(10, 140));
                if (ImGui::Button("Cosmetic", ImVec2(80, 45)))
                {
                    GlobalVars::iTab = 2;
                }
                ImGui::NewLine();
                ImGui::SetCursorPos(ImVec2(10, 195));
                if (ImGui::Button("Stats", ImVec2(80, 45)))
                {
                    GlobalVars::iTab = 3;
                }
            } ImGui::EndChild();
       
       

    } ImGui::End();
}