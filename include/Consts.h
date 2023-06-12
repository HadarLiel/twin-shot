#pragma once 
#include <vector>
#include <string>
#include <iostream>

const int pixel = 32;

const int Window_Height = 800.0f;
const int Window_Width = 1000.0f;


const float buttonWidth = 300.0f;
const float buttonHeight = 80.0f;

const int num_Buttons = 5;

const int Num_Char_Types = 5; //princess

const int num_Design_Buttons = 2;

const float princess_buttonHeight = 100.0f;
const float princess_buttonWidth = 100.0f;



// Define the names of the buttom pictures
static const std::vector<std::string> buttons_types =
{
	"New_Game", "Design", "Settings", "Help", "Exit" 
};

// Define the names of the colors and car pictures
static const std::vector<std::string> design_buttons_types =
{
	"back", "save"
};

// Define the names of the colors and car pictures
static const std::vector<std::string> help_buttons_types =
{
	"back"
};
