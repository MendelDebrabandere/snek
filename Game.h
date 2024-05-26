#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Snek" };

// Change the window dimensions here
float g_WindowWidth{ 823 };
float g_WindowHeight{ 540 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
#pragma region Textures
Texture g_StartScreen{};
Texture g_PressAnyKeyText{};
Texture g_MainMenu{};
Texture g_GameModesText{};
Texture g_CreditsText{};
Texture g_ExitText{};
Texture g_CreditsScreenText{};
Texture g_MendelText{};
Texture g_MichielText{};

Texture g_Grass{};
Texture g_Apple{};
Texture g_AppleScore{};
Texture g_Trophy{};
Texture g_ArrowsUI{};

Texture g_ArrowUp{};
Texture g_ArrowDown{};
Texture g_ArrowLeft{};
Texture g_ArrowRight{};
Texture g_ArrowUpPressed{};
Texture g_ArrowDownPressed{};
Texture g_ArrowLeftPressed{};
Texture g_ArrowRightPressed{};

Texture g_ScoreText{};
Texture g_HighScoreText{};
Texture g_ControlsText{};
Texture g_ArrowUpText{};
Texture g_ArrowLeftDownRightText{};
Texture g_ScoreTextGameOver{};
Texture g_HighScoreTextGameOver{};
Texture g_SettingsBG{};

Texture g_SnakeBodyLeft{};
Texture g_SnakeBodyRight{};
Texture g_SnakeBodyUp{};
Texture g_SnakeBodyDown{};

Texture g_SnakeHeadLeft{};
Texture g_SnakeHeadRight{};
Texture g_SnakeHeadUp{};
Texture g_SnakeHeadDown{};

Texture g_GoldenSnakeBodyLeft{};
Texture g_GoldenSnakeBodyRight{};
Texture g_GoldenSnakeBodyUp{};
Texture g_GoldenSnakeBodyDown{};

Texture g_GoldenSnakeHeadLeft{};
Texture g_GoldenSnakeHeadRight{};
Texture g_GoldenSnakeHeadUp{};
Texture g_GoldenSnakeHeadDown{};

Texture g_SnakeBodyLeftP2{};
Texture g_SnakeBodyRightP2{};
Texture g_SnakeBodyUpP2{};
Texture g_SnakeBodyDownP2{};

Texture g_SnakeHeadLeftP2{};
Texture g_SnakeHeadRightP2{};
Texture g_SnakeHeadUpP2{};
Texture g_SnakeHeadDownP2{};

Sprite g_ShrekSprite{};
Texture g_LeaveShrekText{};
//Sprite g_KudSprite{};

Texture g_GameOver{};
Texture g_RetryText{};
Texture g_ReturnText{};

Texture g_SnekTitle{};

Texture g_GameModesBackGround{};
Texture g_ReturnButton{};
Texture g_ReturnButtonOrange{};
Texture g_OnePlayerText{};
Texture g_MultiplayerText{};
Texture g_PartyModeText{};

Texture g_PausedScreen{};
Texture g_ContinueText{};

Texture g_BlueWins{};
Texture g_RedWins{};
Texture g_Draw{};
Texture g_PlayAgainText{};

Texture g_PVPInfoBlue1{};
Texture g_PVPInfoBlue2{};
Texture g_PVPInfoRed1{};
Texture g_PVPInfoRed2{};

Texture g_ScorePartyModeText{};
Texture g_HighScorePartyModeText{};
Texture g_ScorePartyModeGameOverText{};
Texture g_HighScorePartyModeGameOverText{};
Texture g_Stone{};
Texture g_QuestionBlock{};

Texture g_SettingsWhite{};
Texture g_SettingsOrange{};
Texture g_WallsSettingText{};
Texture g_WallsSettingTextOn{};
Texture g_WallsSettingTextOff{};
Texture g_SpeedSettingsText{};
Texture g_SpeedText{};
Texture g_SpeedArrowUp{};
Texture g_SpeedArrowDown{};
Texture g_CompetitiveModeText{};
#pragma endregion

const int g_Columns{ 16 };
const int g_Rows{ 16 };
const int g_ArraySize{ g_Rows * g_Columns };
int g_GameArr[g_ArraySize]{};

float g_Border{ 10 };
float g_CellSize{ (g_WindowHeight - 2 * g_Border) / g_Rows };
float g_SnakeSpeed{ 50 };
float g_AccumulatedTime{};
float g_TimePerCellUserDef{ 0.2f };
int g_SpeedSetting{3};
float g_TimePerCell{ g_TimePerCellUserDef };

float g_SnakePosCenterX = g_Border + (g_CellSize * g_Columns) / 2;
float g_SnakePosCenterY = g_Border + (g_CellSize * g_Rows) / 2;
Point2f g_SnakePos{ g_SnakePosCenterX, g_SnakePosCenterY };

int g_SnakeLength{ 2 };
int g_SnakeArr[g_ArraySize]{ 3,3,3 };

enum class g_DirectionState { stationary, left, right, up, down };
g_DirectionState g_Direction{};
bool g_MovedThisGameTick{};

int g_Snake1Length{ 2 };
int g_Snake1Arr[g_ArraySize]{ 3,3,3 };
Point2f g_Snake1Pos{ g_SnakePosCenterX - 5 *g_CellSize, g_SnakePosCenterY };

g_DirectionState g_DirectionP1{};
bool g_MovedThisGameTickP1{};
float g_AccumulatedTime1{};

int g_Snake2Length{ 2 };
int g_Snake2Arr[g_ArraySize]{ 3,3,3 };
Point2f g_Snake2Pos{ g_SnakePosCenterX + 4 * g_CellSize, g_SnakePosCenterY };

g_DirectionState g_DirectionP2{};
bool g_MovedThisGameTickP2{};
float g_AccumulatedTime2{};

bool g_Walls{ false };

Point2f g_AppleCord{	g_Border + g_CellSize * (rand() % g_Rows)
					,	g_Border + g_CellSize * (rand() % g_Columns) };

Point2f g_SnakeTail{};

enum class g_GameState { startScreen, shrekEasterEgg, mainMenu, gameModes, mainGame, gameOver, credits, pvpGameMode, partyMode, gameOverPartyMode, settings };
g_GameState g_GameModes{ g_GameState::startScreen };

int g_ScoreCounter{};
std::string g_Score{		"Score                     " + std::to_string(g_ScoreCounter) };
int g_HighScoreCounter{};
std::string g_HighScore{	"Highscore           " + std::to_string(g_HighScoreCounter) };

std::string g_ScoreGameOver{		"Score           " + std::to_string(g_ScoreCounter) };
std::string g_HighScoreGameOver{	"Highscore       " + std::to_string(g_HighScoreCounter) };

float g_ScrollingCreddits{ 0 };
float g_TotalTime{};

Point2f g_MousePos{ 0 , 0 };

bool g_IsGamePaused{ false };
bool g_MouseOnButton{};

enum class g_PVPState { running, redWins, blueWins, draw };
g_PVPState g_PVPWinner{};

int g_ScoreCounterPartyMode{};
std::string g_ScorePartyMode{ "Score                     " + std::to_string(g_ScoreCounterPartyMode) };
int g_HighScoreCounterPartyMode{};
std::string g_HighScorePartyMode{ "Highscore           " + std::to_string(g_HighScoreCounterPartyMode) };

std::string g_ScorePartyModeGameOver{ "Score           " + std::to_string(g_ScoreCounterPartyMode) };
std::string g_HighScorePartyModeGameOver{ "Highscore       " + std::to_string(g_HighScoreCounterPartyMode) };

const int g_StoneArrSize{3};
Point2f g_StoneCord{	g_Border + g_CellSize * (rand() % g_Rows)
					,	g_Border + g_CellSize * (rand() % g_Columns) };
Point2f g_StoneCord1{	g_Border + g_CellSize * (rand() % g_Rows)
					,	g_Border + g_CellSize * (rand() % g_Columns) };
Point2f g_StoneCord2{	g_Border + g_CellSize * (rand() % g_Rows)
					,	g_Border + g_CellSize * (rand() % g_Columns) };
Point2f g_StoneArr[g_StoneArrSize]{ g_StoneCord, g_StoneCord1, g_StoneCord2 };

Point2f g_MisteryBlockCord{ g_Border + g_CellSize * (rand() % g_Rows)
						,	g_Border + g_CellSize * (rand() % g_Columns) };

bool g_CompetitiveMode{ false };
// Declare your own functions here
void TexturesInit();
void DrawStartScreen();
void DrawBackground();
void CheckOutOfBounds();
void MoveSnake(float elapsedSec);
void DrawSnake();
void DrawGoldenSnake();
void DrawGrid();
void DrawApple();
void UpdateApple();
void CollisionCheck();
void Information();
void DrawArrowUI();
void UpdateScore();
void UpdateShrek(float elapsedSec);
void DrawShrek();
void DrawGameOver();
void DrawMainMenu();
void ResetGame();
void DrawCredits();
void UpdateCredits(float elapsedSec);
void UpdateKudSprite(float elapsedSec);
void DrawKudSprite();
void DrawPauseButton();
void DrawGameModes();
void DrawPausedScreen();
void DrawSettings();
void DrawPVPGameMode();
void UpdatePVPGameMode(float elapsedSec);
void DrawSnake1();
void DrawSnake2();
void UpdateSnake1(float elapsedSec);
void UpdateSnake2(float elapsedSec);
void UpdateApplePVP();
void CollisionCheckPVP();
void CheckOutOfBoundsPVP();
void ResetPVPGame();
void InformationPVP();
void DrawBlueWins();
void DrawRedWins();
void DrawDraw();
void DrawPartyGameMode();
void UpdatePartyGameMode(float elapsedSec);
void PressPauseButton();
void InformationPartyMode();
void UpdateApplePartyMode();
void UpdateScorePartyMode();
void CollisionCheckPartyMode();
void UpdateApplePartyMode();
void ResetPartyMode();
void DrawPartyModeGameOverScreen();
void DrawPowerUps();
void UpdatePowerUps(float elapsedSec);
void DrawStones();
void DrawMisteryBlock();
void UpdateMisteryBlock(float elapsedSec);
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
