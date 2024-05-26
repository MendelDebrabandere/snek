#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	TexturesInit();

}

void Draw()
{
	ClearBackground(0.3f, 0.3f, 0.3f);

	// Put your own draw statements here
	switch (g_GameModes)
	{
	case g_GameState::startScreen:
	{
		DrawStartScreen();
		break;
	}
	case g_GameState::shrekEasterEgg:
	{
		DrawShrek();
		break;
	}
	case g_GameState::mainMenu:
	{
		DrawMainMenu();
		break;
	}
	case g_GameState::credits:
	{
		DrawCredits();
		break;
	}
	case g_GameState::gameModes:
	{
		DrawGameModes();
		break;
	}
	case g_GameState::settings:
	{
		DrawSettings();
		break;
	}
	case g_GameState::mainGame:
	{
		DrawBackground();
		DrawSnake();
		DrawApple();
		Information();
		DrawPauseButton();
		// Draw border
		SetColor(204 / 255.f, 167 / 255.f, 89 / 255.f);
		if (g_Walls)
		{
			SetColor(1, 0, 0);;
		}
		DrawRect(g_Border, g_Border, g_CellSize * g_Columns, g_CellSize * g_Rows, 3);

		if (g_IsGamePaused)
		{
			DrawPausedScreen();
		}
		break;
	}
	case g_GameState::pvpGameMode:
	{
		DrawPVPGameMode();
		switch (g_PVPWinner)
		{
		case g_PVPState::blueWins:
		{
			DrawBlueWins();
			break;
		}
		case g_PVPState::redWins:
		{
			DrawRedWins();
			break;
		}
		case g_PVPState::draw:
		{
			DrawDraw();
			break;
		}
		}
		break;
	}
	case g_GameState::partyMode:
	{
		DrawPartyGameMode();
		break;
	}
	case g_GameState::gameOver:
	{
		DrawGameOver();
		break;
	}
	case g_GameState::gameOverPartyMode:
	{
		DrawPartyModeGameOverScreen();
		break;
	}
	}
}

void Update(float elapsedSec)
{
	// process input, do physics 
	if (g_CompetitiveMode)
	{
		g_Walls = true;
		g_TimePerCell = 0.2f;
		g_TimePerCellUserDef = 0.2f;
		g_SpeedSetting = 3;
	}
	switch (g_GameModes)
	{
	case g_GameState::startScreen:
	{
		break;
	}
	case g_GameState::shrekEasterEgg:
	{
		UpdateShrek(elapsedSec);
		break;
	}
	case g_GameState::mainMenu:
	{
		break;
	}
	case g_GameState::credits:
	{
		UpdateCredits(elapsedSec);
		break;
	}
	case g_GameState::mainGame:
	{
		MoveSnake(elapsedSec);
		CheckOutOfBounds();
		UpdateApple();
		CollisionCheck();
		break;
	}
	case g_GameState::pvpGameMode:
	{
		UpdatePVPGameMode(elapsedSec);
		break;
	}
	case g_GameState::partyMode:
	{
		UpdatePartyGameMode(elapsedSec);
		break;
	}
	case g_GameState::gameModes:
	{
		break;
	}
	case g_GameState::gameOver:
	{
		break;
	}
	}
}

void End()
{
	// free game resources here
	DeleteTexture(g_StartScreen);
	DeleteTexture(g_PressAnyKeyText);
	DeleteTexture(g_MainMenu);
	
	DeleteTexture(g_Grass);
	DeleteTexture(g_Apple);
	DeleteTexture(g_AppleScore);
	DeleteTexture(g_ArrowsUI);

	DeleteTexture(g_ArrowUp);
	DeleteTexture(g_ArrowDown);
	DeleteTexture(g_ArrowLeft);
	DeleteTexture(g_ArrowRight);
	DeleteTexture(g_ArrowUpPressed);
	DeleteTexture(g_ArrowDownPressed);
	DeleteTexture(g_ArrowLeftPressed);
	DeleteTexture(g_ArrowRightPressed);

	DeleteTexture(g_ScoreText);
	DeleteTexture(g_HighScoreText);
	DeleteTexture(g_ControlsText);
	DeleteTexture(g_ArrowUpText);
	DeleteTexture(g_ArrowLeftDownRightText);
	DeleteTexture(g_ScoreTextGameOver);
	DeleteTexture(g_HighScoreTextGameOver);
	DeleteTexture(g_OnePlayerText);
	DeleteTexture(g_MultiplayerText);

	DeleteTexture(g_SnakeBodyLeft);
	DeleteTexture(g_SnakeBodyRight);
	DeleteTexture(g_SnakeBodyUp);
	DeleteTexture(g_SnakeBodyDown);

	DeleteTexture(g_SnakeHeadLeft);
	DeleteTexture(g_SnakeHeadRight);
	DeleteTexture(g_SnakeHeadUp);
	DeleteTexture(g_SnakeHeadDown);

	DeleteTexture(g_GoldenSnakeBodyLeft);
	DeleteTexture(g_GoldenSnakeBodyRight);
	DeleteTexture(g_GoldenSnakeBodyUp);
	DeleteTexture(g_GoldenSnakeBodyDown);

	DeleteTexture(g_GoldenSnakeHeadLeft);
	DeleteTexture(g_GoldenSnakeHeadRight);
	DeleteTexture(g_GoldenSnakeHeadUp);
	DeleteTexture(g_GoldenSnakeHeadDown);

	DeleteTexture(g_SnakeBodyLeftP2);
	DeleteTexture(g_SnakeBodyRightP2);
	DeleteTexture(g_SnakeBodyUpP2);
	DeleteTexture(g_SnakeBodyDownP2);

	DeleteTexture(g_SnakeHeadLeftP2);
	DeleteTexture(g_SnakeHeadRightP2);
	DeleteTexture(g_SnakeHeadUpP2);
	DeleteTexture(g_SnakeHeadDownP2);
	
	DeleteTexture(g_ShrekSprite.texture);
	DeleteTexture(g_LeaveShrekText);
	//DeleteTexture(g_KudSprite.texture);

	DeleteTexture(g_GameOver);
	DeleteTexture(g_RetryText);
	DeleteTexture(g_ReturnText);
	
	DeleteTexture(g_SnekTitle);

	DeleteTexture(g_GameModesBackGround);
	DeleteTexture(g_ReturnButton);
	DeleteTexture(g_ReturnButtonOrange);

	DeleteTexture(g_PausedScreen);
	DeleteTexture(g_ContinueText);

	DeleteTexture(g_BlueWins);
	DeleteTexture(g_RedWins);
	DeleteTexture(g_Draw);
	DeleteTexture(g_PlayAgainText);
	DeleteTexture(g_PVPInfoBlue1);
	DeleteTexture(g_PVPInfoRed1);
	DeleteTexture(g_PVPInfoBlue2);
	DeleteTexture(g_PVPInfoRed2);

	DeleteTexture(g_ScorePartyModeText);
	DeleteTexture(g_HighScorePartyModeText);
	DeleteTexture(g_ScorePartyModeGameOverText);
	DeleteTexture(g_HighScorePartyModeGameOverText);
	DeleteTexture(g_Stone);
	DeleteTexture(g_QuestionBlock);
	DeleteTexture(g_SettingsBG);

	DeleteTexture(g_SettingsWhite);
	DeleteTexture(g_SettingsOrange);
	DeleteTexture(g_WallsSettingText);
	DeleteTexture(g_WallsSettingTextOn);
	DeleteTexture(g_WallsSettingTextOff);
	DeleteTexture(g_SpeedSettingsText);
	DeleteTexture(g_SpeedText);
	DeleteTexture(g_SpeedArrowUp);
	DeleteTexture(g_SpeedArrowDown);
	DeleteTexture(g_CompetitiveModeText);
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	
	switch (g_GameModes)
	{
	case g_GameState::startScreen:
	{
		g_GameModes = g_GameState::mainMenu;
		break;
	}
	case g_GameState::credits:
	{
		switch (key)
		{
		case SDLK_ESCAPE:
			g_GameModes = g_GameState::startScreen;
			break;
		}
		break;
	}
	case g_GameState::shrekEasterEgg:
	{
		switch (key)
		{
		case SDLK_ESCAPE:
		{
			g_GameModes = g_GameState::startScreen;
			break;
		}
		break;
		}
	}
	case g_GameState::mainGame:
	{
		if (!g_MovedThisGameTick)
		{
			switch (key)
			{
			case SDLK_LEFT:
				if (g_Direction == g_DirectionState::right) return;
				g_Direction = g_DirectionState::left;
				g_MovedThisGameTick = true;
				break;
			case SDLK_RIGHT:
				if (g_Direction == g_DirectionState::left) return;
				g_Direction = g_DirectionState::right;
				g_MovedThisGameTick = true;
				break;
			case SDLK_UP:
				if (g_Direction == g_DirectionState::down) return;
				g_Direction = g_DirectionState::up;
				g_MovedThisGameTick = true;
				break;
			case SDLK_DOWN:
				if (g_Direction == g_DirectionState::up) return;
				if (g_Direction == g_DirectionState::stationary) return;
				g_Direction = g_DirectionState::down;
				g_MovedThisGameTick = true;
				break;
			}
		}
		break;
	}
	case g_GameState::pvpGameMode:
	{
		//Player 1
		switch (key)
		{
		case SDLK_a:
		{
			if (!g_MovedThisGameTickP1)
			{
				if (g_DirectionP1 == g_DirectionState::right) return;
				g_DirectionP1 = g_DirectionState::left;
				g_MovedThisGameTickP1 = true;
			}
			break;
		}
		case SDLK_d:
		{
			if (!g_MovedThisGameTickP1)
			{
				if (g_DirectionP1 == g_DirectionState::left) return;
				g_DirectionP1 = g_DirectionState::right;
				g_MovedThisGameTickP1 = true;
			}
			break;
		}
		case SDLK_w:
		{
			if (!g_MovedThisGameTickP1)
			{
				if (g_DirectionP1 == g_DirectionState::down) return;
				g_DirectionP1 = g_DirectionState::up;
				g_MovedThisGameTickP1 = true;
			}
			break;
		}
		case SDLK_s:
		{
			if (!g_MovedThisGameTickP1)
			{
				if (g_DirectionP1 == g_DirectionState::up) return;
				if (g_DirectionP1 == g_DirectionState::stationary) return;
				g_DirectionP1 = g_DirectionState::down;
				g_MovedThisGameTickP1 = true;
			}
			break;
		}
		case SDLK_LEFT:
		{
			if (!g_MovedThisGameTickP2)
			{
				if (g_DirectionP2 == g_DirectionState::right) return;
				g_DirectionP2 = g_DirectionState::left;
				g_MovedThisGameTickP2 = true;
			}
			break;
		}
		case SDLK_RIGHT:
		{
			if (!g_MovedThisGameTickP2)
			{
				if (g_DirectionP2 == g_DirectionState::left) return;
				g_DirectionP2 = g_DirectionState::right;
				g_MovedThisGameTickP2 = true;
			}
			break;
		}
		case SDLK_UP:
		{
			if (!g_MovedThisGameTickP2)
			{
				if (g_DirectionP2 == g_DirectionState::down) return;
				g_DirectionP2 = g_DirectionState::up;
				g_MovedThisGameTickP2 = true;
			}
			break;
		}
		case SDLK_DOWN:
		{
			if (!g_MovedThisGameTickP2)
			{
				if (g_DirectionP2 == g_DirectionState::up) return;
				if (g_DirectionP2 == g_DirectionState::stationary) return;
				g_DirectionP2 = g_DirectionState::down;
				g_MovedThisGameTickP2 = true;
			}
			break;
		}
		}

	break;
	}
	case g_GameState::partyMode:
	{
		if (!g_MovedThisGameTick)
		{
			switch (key)
			{
			case SDLK_LEFT:
				if (g_Direction == g_DirectionState::right) return;
				g_Direction = g_DirectionState::left;
				g_MovedThisGameTick = true;
				break;
			case SDLK_RIGHT:
				if (g_Direction == g_DirectionState::left) return;
				g_Direction = g_DirectionState::right;
				g_MovedThisGameTick = true;
				break;
			case SDLK_UP:
				if (g_Direction == g_DirectionState::down) return;
				g_Direction = g_DirectionState::up;
				g_MovedThisGameTick = true;
				break;
			case SDLK_DOWN:
				if (g_Direction == g_DirectionState::up) return;
				if (g_Direction == g_DirectionState::stationary) return;
				g_Direction = g_DirectionState::down;
				g_MovedThisGameTick = true;
				break;
			}
		}
		break;
	}
	case g_GameState::gameOver:
	{
		break;
	}
	}
}

void OnKeyUpEvent(SDL_Keycode key)
{

}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);

}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		switch (g_GameModes)
		{
		case g_GameState::startScreen:
		{
			Rectf shreksterEgg{};
			shreksterEgg.left = 761;
			shreksterEgg.bottom = 0;
			shreksterEgg.width = g_WindowWidth - 761;
			shreksterEgg.height = g_WindowHeight - 490;

			if (IsPointInRect(g_MousePos, shreksterEgg))
			{
				g_GameModes = g_GameState::shrekEasterEgg;
				ResetGame();
			}
			break;
		}
		case g_GameState::mainMenu:
		{
			Rectf gameModes{};
			gameModes.width = 200;
			gameModes.height = 70;
			gameModes.left = g_WindowWidth / 2 - gameModes.width / 2;
			gameModes.bottom = 140 + gameModes.height + 20;

			if (IsPointInRect(g_MousePos, gameModes))
			{
				g_GameModes = g_GameState::gameModes;
			}

			Rectf Exit{};
			Exit.width = 200;
			Exit.height = 70;
			Exit.left = g_WindowWidth / 2 - Exit.width / 2;
			Exit.bottom = 50;

			if (IsPointInRect(g_MousePos, Exit))
			{
				//Quit SDL subsystems
				TTF_Quit();
				IMG_Quit();
				SDL_Quit();
				exit(-1);
			}

			Rectf credits{};
			credits.width = 200;
			credits.height = 70;
			credits.left = g_WindowWidth / 2 - Exit.width / 2;
			credits.bottom = Exit.bottom + Exit.height + 20;

			if (IsPointInRect(g_MousePos, credits))
			{
				g_GameModes = g_GameState::credits;
				g_TotalTime = 0;
			}
			break;
		}
		case g_GameState::mainGame:
		{
			PressPauseButton();
			break;
		}
		case g_GameState::gameModes:
		{
			Rectf onePlayer{};
			onePlayer.width = 200;
			onePlayer.height = 70;
			onePlayer.left = g_WindowWidth / 2 - onePlayer.width / 2;
			onePlayer.bottom = g_WindowHeight / 2 - onePlayer.height / 2;

			if (IsPointInRect(g_MousePos, onePlayer))
			{
				g_GameModes = g_GameState::mainGame;
			}

			Rectf multiplayer{};
			multiplayer.width = 200;
			multiplayer.height = 70;
			multiplayer.left = g_WindowWidth / 2 - multiplayer.width / 2;
			multiplayer.bottom = g_WindowHeight / 2 - multiplayer.height / 2 - onePlayer.height - 40;

			if (IsPointInRect(g_MousePos, multiplayer))
			{
				g_GameModes = g_GameState::pvpGameMode;
			}

			Rectf party{};
			party.width = 200;
			party.height = 70;
			party.left = g_WindowWidth / 2 - party.width / 2;
			party.bottom = g_WindowHeight / 2 - party.height / 2 - 2 * (onePlayer.height + 20);

			if (IsPointInRect(g_MousePos, party))
			{
				g_GameModes = g_GameState::partyMode;
			}

			Rectf returnButton{};
			returnButton.width = 70;
			returnButton.height = 70;
			returnButton.left = 10;
			returnButton.bottom = g_WindowHeight - returnButton.height - 10;

			if (IsPointInRect(g_MousePos, returnButton))
			{
				g_GameModes = g_GameState::mainMenu;
			}

			Rectf settingsButton{};
			settingsButton.width = 70;
			settingsButton.height = 70;
			settingsButton.left = g_WindowWidth - settingsButton.width - 10;
			settingsButton.bottom = g_WindowHeight - settingsButton.height - 10;

			if (IsPointInRect(g_MousePos, settingsButton))
			{
				g_GameModes = g_GameState::settings;
			}

			break;
		}
		case g_GameState::settings:
		{
			Rectf returnButton{};
			returnButton.width = 70;
			returnButton.height = 70;
			returnButton.left = 10;
			returnButton.bottom = g_WindowHeight - returnButton.height - 10;

			if (IsPointInRect(g_MousePos, returnButton))
			{
				g_GameModes = g_GameState::gameModes;
			}


			Rectf walls{};
			walls.left = g_WindowWidth / 2 - 150 - 100;
			walls.bottom = g_WindowHeight / 3;
			walls.width = 200;
			walls.height = 70;

			Rectf wallsBox{};
			wallsBox.left = walls.left + walls.width / 2 + g_WallsSettingText.width / 2 - 15;
			wallsBox.bottom = walls.bottom + walls.height / 2 - g_WallsSettingText.height / 2 - 5;
			wallsBox.width = g_WallsSettingText.height + g_WallsSettingTextOff.width - 10;
			wallsBox.height = g_WallsSettingText.height + 10;

			if (!g_CompetitiveMode)
			{
				if (IsPointInRect(g_MousePos, wallsBox))
				{
					g_Walls = !g_Walls;
				}
			}

			Rectf speedUpBox{};
			speedUpBox.left = g_WindowWidth / 2 + 150 - 100 + 155;
			speedUpBox.bottom = g_WindowHeight / 3 + 40;
			speedUpBox.width = 20;
			speedUpBox.height = 20;
			if (!g_CompetitiveMode)
			{
				if (IsPointInRect(g_MousePos, speedUpBox))
				{
					if (g_SpeedSetting < 4)
					{
						Color4f textColor{ 1,1,1,0 };
						int fontSize{ 20 };
						g_SpeedSetting++;
						g_TimePerCellUserDef -= 0.1f;
						g_TimePerCell = g_TimePerCellUserDef;
						TextureFromString(std::to_string(g_SpeedSetting), "Resources/8-bit-fortress.ttf", fontSize, textColor, g_SpeedText);
					}
				}
			}

			Rectf speedDownBox{};
			speedDownBox.left = g_WindowWidth / 2 + 150 - 100 + 155;
			speedDownBox.bottom = g_WindowHeight / 3 + 10;
			speedDownBox.width = 20;
			speedDownBox.height = 20;

			if (!g_CompetitiveMode)
			{
				if (IsPointInRect(g_MousePos, speedDownBox))
				{
					if (g_SpeedSetting > 1)
					{
						Color4f textColor{ 1,1,1,0 };
						int fontSize{ 20 };
						g_SpeedSetting--;
						g_TimePerCellUserDef += 0.1f;
						g_TimePerCell = g_TimePerCellUserDef;
						TextureFromString(std::to_string(g_SpeedSetting), "Resources/8-bit-fortress.ttf", fontSize, textColor, g_SpeedText);
					}
				}
			}


			Rectf competitiveModeRect{};
			competitiveModeRect.left = g_WindowWidth / 2 + 60;
			competitiveModeRect.bottom = g_WindowHeight / 3 - 65;
			competitiveModeRect.width = g_CompetitiveModeText.height + g_WallsSettingTextOff.width - 10;
			competitiveModeRect.height = g_CompetitiveModeText.height + 10;

			if (IsPointInRect(g_MousePos, competitiveModeRect))
			{
				Color4f textColor{ 1,1,1,0 };
				int fontSize{ 20 };
				g_CompetitiveMode = !g_CompetitiveMode;
				g_Walls = true;
				g_TimePerCell = 0.2f;
				g_TimePerCellUserDef = 0.2f;
				g_SpeedSetting = 3;
				TextureFromString(std::to_string(g_SpeedSetting), "Resources/8-bit-fortress.ttf", fontSize, textColor, g_SpeedText);
			}


			break;
		}
		case g_GameState::gameOver:
		{
			Rectf mainMenu{};
			mainMenu.left = g_WindowWidth / 2 - 150 - 100;
			mainMenu.bottom = g_WindowHeight / 4;
			mainMenu.width = 200;
			mainMenu.height = 70;

			if (IsPointInRect(g_MousePos, mainMenu))
			{
				g_GameModes = g_GameState::mainMenu;
				ResetGame();
			}

			Rectf retry{};
			retry.left = g_WindowWidth / 2 + 150 - 100;
			retry.bottom = g_WindowHeight / 4;
			retry.width = 200;
			retry.height = 70;

			if (IsPointInRect(g_MousePos, retry))
			{
				g_GameModes = g_GameState::mainGame;
				ResetGame();
			}
			break;
		}
		case g_GameState::pvpGameMode:
		{


			switch (g_PVPWinner)
			{
			case g_PVPState::running:
			{
				Rectf pauseButton{};
				pauseButton.width = pauseButton.height = 50;
				pauseButton.left = g_WindowWidth - 10 - pauseButton.width;
				pauseButton.bottom = g_WindowHeight - 10 - pauseButton.height;

				if (IsPointInRect(g_MousePos, pauseButton))
				{
					g_IsGamePaused = true;
				}

				if (g_IsGamePaused)
				{
					Rectf backToMenu{};
					backToMenu.left = g_WindowWidth / 2 - 150 - 100;
					backToMenu.bottom = g_WindowHeight / 3;
					backToMenu.width = 200;
					backToMenu.height = 70;
					if (IsPointInRect(g_MousePos, backToMenu))
					{
						g_GameModes = g_GameState::mainMenu;
						g_IsGamePaused = false;
						ResetPVPGame();
					}

					Rectf continuePlaying{};
					continuePlaying.left = g_WindowWidth / 2 + 150 - 100;
					continuePlaying.bottom = g_WindowHeight / 3;
					continuePlaying.width = 200;
					continuePlaying.height = 70;
					if (IsPointInRect(g_MousePos, continuePlaying))
					{
						g_IsGamePaused = false;
					}

				}
				break;
			}
			case g_PVPState::draw:
			case g_PVPState::redWins:
			case g_PVPState::blueWins:
			{
				Rectf backToMenu{};
				backToMenu.left = g_WindowWidth / 2 - 150 - 100;
				backToMenu.bottom = g_WindowHeight / 3;
				backToMenu.width = 200;
				backToMenu.height = 70;
				if (IsPointInRect(g_MousePos, backToMenu))
				{
					g_GameModes = g_GameState::mainMenu;
					g_PVPWinner = g_PVPState::running;
					ResetPVPGame();
				}

				Rectf playAgain{};
				playAgain.left = g_WindowWidth / 2 + 150 - 100;
				playAgain.bottom = g_WindowHeight / 3;
				playAgain.width = 200;
				playAgain.height = 70;
				if (IsPointInRect(g_MousePos, playAgain))
				{
					g_PVPWinner = g_PVPState::running;
					ResetPVPGame();
				}
				break;
			}
			}
			break;
		}
		case g_GameState::partyMode:
		{
			PressPauseButton();
			break;
		}
		case g_GameState::gameOverPartyMode:
		{
			Rectf mainMenu{};
			mainMenu.left = g_WindowWidth / 2 - 150 - 100;
			mainMenu.bottom = g_WindowHeight / 4;
			mainMenu.width = 200;
			mainMenu.height = 70;

			if (IsPointInRect(g_MousePos, mainMenu))
			{
				g_GameModes = g_GameState::mainMenu;
				ResetPartyMode();
			}

			Rectf retry{};
			retry.left = g_WindowWidth / 2 + 150 - 100;
			retry.bottom = g_WindowHeight / 4;
			retry.width = 200;
			retry.height = 70;

			if (IsPointInRect(g_MousePos, retry))
			{
				g_GameModes = g_GameState::partyMode;
				ResetPartyMode();
			}
			break;
		}
		break;
		}
	}
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void TexturesInit()
{
	Color4f textColor{ 1,1,1,0 };
	int fontSize{ 20 };

	//screens
	TextureFromFile("Resources/start_screen.png", g_StartScreen);
	TextureFromString("Press any key to continue...", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_PressAnyKeyText);
	TextureFromFile("Resources/main_menu.png", g_MainMenu);
	TextureFromString("Game Modes", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_GameModesText);
	TextureFromString("Credits", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_CreditsText);
	TextureFromString("Exit", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_ExitText);
	TextureFromString("Developed by", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_CreditsScreenText);
	TextureFromString("Debrabandere  Mendel", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_MendelText);
	TextureFromString("Dewachtere  Michiel", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_MichielText);

	//symbols
	TextureFromFile("Resources/grass.jpg", g_Grass);
	TextureFromFile("Resources/apple.png", g_Apple);
	TextureFromFile("Resources/apple.png", g_AppleScore);
	TextureFromFile("Resources/trophy.png", g_Trophy);
	TextureFromFile("Resources/arrows_ui.png", g_ArrowsUI);

	//arrow
	TextureFromFile("Resources/arrow_up.png", g_ArrowUp);
	TextureFromFile("Resources/arrow_down.png", g_ArrowDown);
	TextureFromFile("Resources/arrow_left.png", g_ArrowLeft);
	TextureFromFile("Resources/arrow_right.png", g_ArrowRight);
	TextureFromFile("Resources/arrow_up_pressed.png", g_ArrowUpPressed);
	TextureFromFile("Resources/arrow_down_pressed.png", g_ArrowDownPressed);
	TextureFromFile("Resources/arrow_left_pressed.png", g_ArrowLeftPressed);
	TextureFromFile("Resources/arrow_right_pressed.png", g_ArrowRightPressed);

	//text
	TextureFromString(g_Score, "Resources/8-bit-fortress.ttf", fontSize, textColor, g_ScoreText);
	TextureFromString(g_HighScore, "Resources/8-bit-fortress.ttf", fontSize, textColor, g_HighScoreText);
	TextureFromString("Press esc to leave", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_LeaveShrekText);
	TextureFromString("Controls", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_ControlsText);
	TextureFromString("Up", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_ArrowUpText);
	TextureFromString("Left    Down     Right", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_ArrowLeftDownRightText);
	TextureFromString(g_ScoreGameOver, "Resources/8-bit-fortress.ttf", fontSize, textColor, g_ScoreTextGameOver);
	TextureFromString(g_HighScoreGameOver, "Resources/8-bit-fortress.ttf", fontSize, textColor, g_HighScoreTextGameOver);
	TextureFromString("Classic", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_OnePlayerText);
	TextureFromString("Multiplayer", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_MultiplayerText);
	TextureFromString("Party Mode", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_PartyModeText);
	TextureFromString(g_ScorePartyMode, "Resources/8-bit-fortress.ttf", fontSize, textColor, g_ScorePartyModeText);
	TextureFromString(g_HighScorePartyMode, "Resources/8-bit-fortress.ttf", fontSize, textColor, g_HighScorePartyModeText);
	TextureFromString(g_ScorePartyModeGameOver, "Resources/8-bit-fortress.ttf", fontSize, textColor, g_ScorePartyModeGameOverText);
	TextureFromString(g_HighScorePartyModeGameOver, "Resources/8-bit-fortress.ttf", fontSize, textColor, g_HighScorePartyModeGameOverText);

	//snake body
	TextureFromFile("Resources/snake_body_left.png", g_SnakeBodyLeft);
	TextureFromFile("Resources/snake_body_right.png", g_SnakeBodyRight);
	TextureFromFile("Resources/snake_body_up.png", g_SnakeBodyUp);
	TextureFromFile("Resources/snake_body_down.png", g_SnakeBodyDown);

	//snake head
	TextureFromFile("Resources/snake_head_left.png", g_SnakeHeadLeft);
	TextureFromFile("Resources/snake_head_right.png", g_SnakeHeadRight);
	TextureFromFile("Resources/snake_head_up.png", g_SnakeHeadUp);
	TextureFromFile("Resources/snake_head_down.png", g_SnakeHeadDown);

	//golden snake body
	TextureFromFile("Resources/gold_snake_body_left.png", g_GoldenSnakeBodyLeft);
	TextureFromFile("Resources/gold_snake_body_right.png", g_GoldenSnakeBodyRight);
	TextureFromFile("Resources/gold_snake_body_up.png", g_GoldenSnakeBodyUp);
	TextureFromFile("Resources/gold_snake_body_down.png", g_GoldenSnakeBodyDown);

	//golden snake head
	TextureFromFile("Resources/gold_snake_head_left.png", g_GoldenSnakeHeadLeft);
	TextureFromFile("Resources/gold_snake_head_right.png", g_GoldenSnakeHeadRight);
	TextureFromFile("Resources/gold_snake_head_up.png", g_GoldenSnakeHeadUp);
	TextureFromFile("Resources/gold_snake_head_down.png", g_GoldenSnakeHeadDown);

	//snake body p2
	TextureFromFile("Resources/snake_p2_body_left.png", g_SnakeBodyLeftP2);
	TextureFromFile("Resources/snake_p2_body_right.png", g_SnakeBodyRightP2);
	TextureFromFile("Resources/snake_p2_body_up.png", g_SnakeBodyUpP2);
	TextureFromFile("Resources/snake_p2_body_down.png", g_SnakeBodyDownP2);

	//snake head p2
	TextureFromFile("Resources/snake_p2_head_left.png", g_SnakeHeadLeftP2);
	TextureFromFile("Resources/snake_p2_head_right.png", g_SnakeHeadRightP2);
	TextureFromFile("Resources/snake_p2_head_up.png", g_SnakeHeadUpP2);
	TextureFromFile("Resources/snake_p2_head_down.png", g_SnakeHeadDownP2);


	//shrek sprite
	TextureFromFile("Resources/shrek_sprite.png", g_ShrekSprite.texture);
	g_ShrekSprite.cols = 5;
	g_ShrekSprite.frames = 125;
	g_ShrekSprite.currentFrame = 0;
	g_ShrekSprite.accumulatedTime = 0.f;
	g_ShrekSprite.frameTime = 0.7f / 10.f;

	//kud sprite
	//TextureFromFile("Resources/credits_easter_egg.png", g_KudSprite.texture);
	//g_KudSprite.cols = 5;
	//g_KudSprite.frames = 255;
	//g_KudSprite.currentFrame = 0;
	//g_KudSprite.accumulatedTime = 0.f;
	//g_KudSprite.frameTime = 51.f / 255.f;

	//game over
	TextureFromFile("Resources/game_over.png", g_GameOver);
	TextureFromString("Main Menu", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_ReturnText);
	TextureFromString("Retry", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_RetryText);

	//credits
	TextureFromFile("Resources/snek_title.png", g_SnekTitle);

	//game modes
	TextureFromFile("Resources/game_modes.png", g_GameModesBackGround);
	TextureFromFile("Resources/return_button.png", g_ReturnButton);
	TextureFromFile("Resources/return_button_orange.png", g_ReturnButtonOrange);

	//pause screen
	TextureFromString("Continue", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_ContinueText);
	TextureFromFile("Resources/paused_screen.png", g_PausedScreen);

	//PVP textures
	TextureFromFile("Resources/blue_wins.png", g_BlueWins);
	TextureFromFile("Resources/red_wins.png", g_RedWins);
	TextureFromFile("Resources/draw.png", g_Draw);
	TextureFromString("Play again", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_PlayAgainText);

	TextureFromString("The blue snek", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_PVPInfoBlue1);
	TextureFromString("The red snek", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_PVPInfoRed1);
	TextureFromString("uses WASD to move", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_PVPInfoBlue2);
	TextureFromString("uses the arrow keys to move", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_PVPInfoRed2);
	TextureFromFile("Resources/stone.png", g_Stone);
	TextureFromFile("Resources/question_block.png", g_QuestionBlock);
	TextureFromFile("Resources/settings_bg.png", g_SettingsBG);

	TextureFromFile("Resources/settings_white.png", g_SettingsWhite);
	TextureFromFile("Resources/settings_orange.png", g_SettingsOrange);
	TextureFromString("Walls", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_WallsSettingText);
	TextureFromString("On", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_WallsSettingTextOn);
	TextureFromString("Off", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_WallsSettingTextOff);
	TextureFromString("Speed", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_SpeedSettingsText);
	TextureFromString(std::to_string(g_SpeedSetting), "Resources/8-bit-fortress.ttf", fontSize, textColor, g_SpeedText);
	TextureFromFile("Resources/speed_arrow_up.png", g_SpeedArrowUp);
	TextureFromFile("Resources/speed_arrow_down.png", g_SpeedArrowDown);
	TextureFromString("Competitive", "Resources/8-bit-fortress.ttf", fontSize, textColor, g_CompetitiveModeText);
}
void DrawStartScreen()
{
	Rectf startScreen{};
	startScreen.left = 0;
	startScreen.bottom = 0;
	startScreen.width = g_WindowWidth;
	startScreen.height = g_WindowHeight;
	DrawTexture(g_StartScreen, startScreen);

	Point2f pressAnyKey(g_WindowWidth / 2 - g_PressAnyKeyText.width / 2, g_WindowHeight / 3);
	DrawTexture(g_PressAnyKeyText, pressAnyKey);
}
void DrawBackground()
{
	Rectf background{};
	background.left = g_Border;
	background.bottom = g_Border;
	background.width = g_CellSize * g_Columns;
	background.height = g_CellSize * g_Rows;
	DrawTexture(g_Grass, background);
}
void CheckOutOfBounds()
{
	if (((g_SnakePos.x < g_Border) || (g_SnakePos.x >= g_Border + (g_CellSize * g_Columns))) ||
		((g_SnakePos.y < g_Border) || (g_SnakePos.y >= g_Border + (g_CellSize * g_Rows))))
	{
		g_GameModes = g_GameState::gameOver;
		Color4f textColor{ 1,1,1,0 };
		int fontSize{ 20 };
		std::string g_ScoreGameOver{		"Score              " + std::to_string(g_ScoreCounter) };
		std::string g_HighScoreGameOver{	"Highscore    " + std::to_string(g_HighScoreCounter) };
		TextureFromString(g_ScoreGameOver, "Resources/8-bit-fortress.ttf", fontSize, textColor, g_ScoreTextGameOver);
		TextureFromString(g_HighScoreGameOver, "Resources/8-bit-fortress.ttf", fontSize, textColor, g_HighScoreTextGameOver);
	}
}
void MoveSnake(float elapsedSec)
{
	if (!g_IsGamePaused)
	{
		g_AccumulatedTime += elapsedSec;
		if (g_AccumulatedTime > g_TimePerCell)
		{

			for (int i{ g_ArraySize - 2 }; i >= 0; --i)
			{
				g_SnakeArr[i + 1] = g_SnakeArr[i];
			}

			switch (g_Direction)
			{
			case g_DirectionState::left:
				g_SnakePos.x -= g_CellSize;
				g_SnakeArr[0] = 1;
				if (!g_Walls)
				{
					if (g_SnakePos.x < g_Border)
					{
						g_SnakePos.x = g_Border + (g_Columns - 1) * g_CellSize;
					}
				}
				break;
			case g_DirectionState::right:
				g_SnakePos.x += g_CellSize;
				g_SnakeArr[0] = 2;
				if (!g_Walls)
				{
					if (g_SnakePos.x > g_Border + (g_Columns - 1) * g_CellSize)
					{
						g_SnakePos.x = g_Border;
					}
				}
				break;
			case g_DirectionState::up:
				g_SnakePos.y += g_CellSize;
				g_SnakeArr[0] = 3;
				if (!g_Walls)
				{
					if (g_SnakePos.y > g_Border + (g_Rows - 1) * g_CellSize)
					{
						g_SnakePos.y = g_Border;
					}
				}
				break;
			case g_DirectionState::down:
				g_SnakePos.y -= g_CellSize;
				g_SnakeArr[0] = 4;
				if (!g_Walls)
				{
					if (g_SnakePos.y < g_Border)
					{
						g_SnakePos.y = g_Border + (g_Rows - 1) * g_CellSize;
					}
				}
				break;
			}
			g_AccumulatedTime -= g_TimePerCell;

			if (g_MovedThisGameTick == true)
			{
				g_MovedThisGameTick = false;
			}
		}
	}
}
void DrawSnake()
{
	g_SnakeTail = g_SnakePos;
	
	Rectf snakeBody{};
	snakeBody.left = g_SnakeTail.x;
	snakeBody.bottom = g_SnakeTail.y;
	snakeBody.width = g_CellSize;
	snakeBody.height = g_CellSize;
	if (g_ScoreCounter <= 50)
	{
		for (int i{}; i < g_SnakeLength; ++i)
		{
			switch (g_SnakeArr[i])
			{
			case 1:
				g_SnakeTail.x += g_CellSize;
				if (!g_Walls)
				{
					if (g_SnakeTail.x > g_Border + (g_Columns - 1) * g_CellSize)
					{
						g_SnakeTail.x = g_Border;
					}
				}
				snakeBody.left = g_SnakeTail.x;
				DrawTexture(g_SnakeBodyLeft, snakeBody);
				break;
			case 2:
				g_SnakeTail.x -= g_CellSize;
				if (!g_Walls)
				{
					if (g_SnakeTail.x < g_Border)
					{
						g_SnakeTail.x = g_Border + (g_Columns - 1) * g_CellSize;
					}
				}
				snakeBody.left = g_SnakeTail.x;
				DrawTexture(g_SnakeBodyRight, snakeBody);
				break;
			case 3:
				g_SnakeTail.y -= g_CellSize;
				if (!g_Walls)
				{
					if (g_SnakeTail.y < g_Border)
					{
						g_SnakeTail.y = g_Border + (g_Rows - 1) * g_CellSize;
					}
				}
				snakeBody.bottom = g_SnakeTail.y;
				DrawTexture(g_SnakeBodyUp, snakeBody);
				break;
			case 4:
				g_SnakeTail.y += g_CellSize;
				if (!g_Walls)
				{
					if (g_SnakeTail.y > g_Border + (g_Rows - 1) * g_CellSize)
					{
						g_SnakeTail.y = g_Border;
					}
				}
				snakeBody.bottom = g_SnakeTail.y;
				DrawTexture(g_SnakeBodyDown, snakeBody);
				break;
			}
		}

		Rectf snakeHead{};
		snakeHead.left = g_SnakePos.x;
		snakeHead.bottom = g_SnakePos.y;
		snakeHead.width = snakeHead.height = g_CellSize;

		switch (g_Direction)
		{
		case g_DirectionState::left:
			DrawTexture(g_SnakeHeadLeft, snakeHead);
			break;
		case g_DirectionState::right:
			DrawTexture(g_SnakeHeadRight, snakeHead);
			break;
		case g_DirectionState::stationary:
		case g_DirectionState::up:
			DrawTexture(g_SnakeHeadUp, snakeHead);
			break;
		case g_DirectionState::down:
			DrawTexture(g_SnakeHeadDown, snakeHead);
			break;
		}
	}
	else
	{
		DrawGoldenSnake();
	}
}
void DrawGoldenSnake()
{
	g_SnakeTail = g_SnakePos;
	
	Rectf snakeBody{};
	snakeBody.left = g_SnakeTail.x;
	snakeBody.bottom = g_SnakeTail.y;
	snakeBody.width = g_CellSize;
	snakeBody.height = g_CellSize;

	for (int i{}; i < g_SnakeLength; ++i)
	{
		switch (g_SnakeArr[i])
		{
		case 1:
			g_SnakeTail.x += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x > g_Border + (g_Columns - 1) * g_CellSize)
				{
					g_SnakeTail.x = g_Border;
				}
			}
			snakeBody.left = g_SnakeTail.x;
			DrawTexture(g_GoldenSnakeBodyLeft, snakeBody);
			break;
		case 2:
			g_SnakeTail.x -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x < g_Border)
				{
					g_SnakeTail.x = g_Border + (g_Columns - 1) * g_CellSize;
				}
			}
			snakeBody.left = g_SnakeTail.x;
			DrawTexture(g_GoldenSnakeBodyRight, snakeBody);
			break;
		case 3:
			g_SnakeTail.y -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y < g_Border)
				{
					g_SnakeTail.y = g_Border + (g_Rows - 1) * g_CellSize;
				}
			}
			snakeBody.bottom = g_SnakeTail.y;
			DrawTexture(g_GoldenSnakeBodyUp, snakeBody);
			break;
		case 4:
			g_SnakeTail.y += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y > g_Border + (g_Rows - 1) * g_CellSize)
				{
					g_SnakeTail.y = g_Border;
				}
			}
			snakeBody.bottom = g_SnakeTail.y;
			DrawTexture(g_GoldenSnakeBodyDown, snakeBody);
			break;
		}
	}

	Rectf snakeHead{};
	snakeHead.left = g_SnakePos.x;
	snakeHead.bottom = g_SnakePos.y;
	snakeHead.width = snakeHead.height = g_CellSize;

	switch (g_Direction)
	{
	case g_DirectionState::left:
		DrawTexture(g_GoldenSnakeHeadLeft, snakeHead);
		break;
	case g_DirectionState::right:
		DrawTexture(g_GoldenSnakeHeadRight, snakeHead);
		break;
	case g_DirectionState::stationary:
	case g_DirectionState::up:
		DrawTexture(g_GoldenSnakeHeadUp, snakeHead);
		break;
	case g_DirectionState::down:
		DrawTexture(g_GoldenSnakeHeadDown, snakeHead);
		break;
	}
}
void DrawGrid()
{
	for (int i{}; i < g_ArraySize; ++i)
	{
		float xCord{ g_Border + (i % g_Columns) * g_CellSize };
		float yCord{ g_Border + (i / g_Columns) * g_CellSize };

		SetColor(1, 1, 1);
		DrawRect(xCord, yCord, g_CellSize, g_CellSize);
	}
}
void DrawApple()
{
	//SetColor(0, 1, 0);
	//FillRect(g_AppleCord, g_CellSize, g_CellSize);
	Rectf apple{};
	apple.left = g_AppleCord.x;
	apple.bottom = g_AppleCord.y;
	apple.width = g_CellSize;
	apple.height = g_CellSize;
	DrawTexture(g_Apple, apple);
}
void UpdateScore()
{

	g_Score = "Score                     " + std::to_string(g_ScoreCounter);
	Color4f textColor{ 1,1,1,0 };
	TextureFromString(g_Score, "Resources/8-bit-fortress.ttf", 20, textColor, g_ScoreText);
	if (g_ScoreCounter >= g_HighScoreCounter)
	{
		g_HighScoreCounter = g_ScoreCounter;
		g_HighScore = "Highscore           " + std::to_string(g_HighScoreCounter);
		TextureFromString(g_HighScore, "Resources/8-bit-fortress.ttf", 20, textColor, g_HighScoreText);
	}

}
void UpdateApple()
{
	if ((g_SnakePos.x == g_AppleCord.x) && (g_SnakePos.y == g_AppleCord.y))
	{
		g_AppleCord.x = g_Border + g_CellSize * (rand() % g_Rows);
		g_AppleCord.y = g_Border + g_CellSize * (rand() % g_Columns);
		g_SnakeLength++;
		++g_ScoreCounter;
		UpdateScore();
	}

	g_SnakeTail = g_SnakePos;
	for (int i{}; i < g_SnakeLength; ++i)
	{
		switch (g_SnakeArr[i])
		{
		case 1:
			g_SnakeTail.x += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x > g_Border + (g_Columns - 1) * g_CellSize)
				{
					g_SnakeTail.x = g_Border;
				}
			}
			break;
		case 2:
			g_SnakeTail.x -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x < g_Border)
				{
					g_SnakeTail.x = g_Border + (g_Columns - 1) * g_CellSize;
				}
			}
			break;
		case 3:
			g_SnakeTail.y -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y < g_Border)
				{
					g_SnakeTail.y = g_Border + (g_Rows - 1) * g_CellSize;
				}
			}
			break;
		case 4:
			g_SnakeTail.y += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y > g_Border + (g_Rows - 1) * g_CellSize)
				{
					g_SnakeTail.y = g_Border;
				}
			}
			break;
		}
		if ((g_AppleCord.x == g_SnakeTail.x) && (g_AppleCord.y == g_SnakeTail.y))
		{
			g_AppleCord.x = g_Border + g_CellSize * (rand() % g_Rows);
			g_AppleCord.y = g_Border + g_CellSize * (rand() % g_Columns);
		}
	}
}
void CollisionCheck()
{
	g_SnakeTail = g_SnakePos;
	for (int i{}; i < g_SnakeLength; ++i)
	{
		switch (g_SnakeArr[i])
		{
		case 1:
			g_SnakeTail.x += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x > g_Border + (g_Columns - 1) * g_CellSize)
				{
					g_SnakeTail.x = g_Border;
				}
			}
			break;
		case 2:
			g_SnakeTail.x -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x < g_Border)
				{
					g_SnakeTail.x = g_Border + (g_Columns - 1) * g_CellSize;
				}
			}
			break;
		case 3:
			g_SnakeTail.y -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y < g_Border)
				{
					g_SnakeTail.y = g_Border + (g_Rows - 1) * g_CellSize;
				}
			}
			break;
		case 4:
			g_SnakeTail.y += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y > g_Border + (g_Rows - 1) * g_CellSize)
				{
					g_SnakeTail.y = g_Border;
				}
			}
			break;
		}


		if ((g_SnakePos.x == g_SnakeTail.x) && (g_SnakePos.y == g_SnakeTail.y))
		{
			g_GameModes = g_GameState::gameOver;
			Color4f textColor{ 1,1,1,0 };
			int fontSize{ 20 };
			std::string g_ScoreGameOver{		"Score              " + std::to_string(g_ScoreCounter) };
			std::string g_HighScoreGameOver{	"Highscore    " + std::to_string(g_HighScoreCounter) };
			TextureFromString(g_ScoreGameOver, "Resources/8-bit-fortress.ttf", fontSize, textColor, g_ScoreTextGameOver);
			TextureFromString(g_HighScoreGameOver, "Resources/8-bit-fortress.ttf", fontSize, textColor, g_HighScoreTextGameOver);
		}
	}
}
void Information()
{
	Point2f score{};
	score.x = g_Border * 2 + g_Columns * g_CellSize;
	score.y = g_WindowHeight - 105;
	DrawTexture(g_ScoreText, score);

	Rectf apple{};
	apple.left = g_Border * 2 + g_Columns * g_CellSize + 240;
	apple.bottom = g_WindowHeight - 107;
	apple.height = apple.width = 32.5f;
	DrawTexture(g_AppleScore, apple);

	Rectf trophy{};
	trophy.left = g_Border * 2 + g_Columns * g_CellSize + 240;
	trophy.bottom = g_WindowHeight - 37 - 32.5f - 5 - 70;
	trophy.height = trophy.width = g_CellSize;
	DrawTexture(g_Trophy, trophy);

	Point2f highscore{};
	highscore.x = g_Border * 2 + g_Columns * g_CellSize;
	highscore.y = g_WindowHeight - 35 - 32.5f - 5 - 70;
	DrawTexture(g_HighScoreText, highscore);

	Rectf arrowsUI{};
	float scale{ 0.3f };
	arrowsUI.width = g_ArrowsUI.width * scale;
	arrowsUI.height = g_ArrowsUI.height * scale;
	arrowsUI.left = g_Border * 2 + g_CellSize * g_Columns + ((g_WindowWidth - (g_Border * 2 + g_CellSize * g_Columns)) / 2 - arrowsUI.width / 2);
	arrowsUI.bottom = g_WindowHeight - 35 - 32.5f - 25 - arrowsUI.height;

	Point2f controls{};
	controls.x = g_Border * 2 + g_Columns * g_CellSize;
	controls.y = 90 + 2 * g_ArrowDown.height * 0.5f;
	DrawTexture(g_ControlsText, controls);

	DrawArrowUI();
}
void DrawArrowUI()
{
	float scale{ 0.5f };

	Rectf arrowUp{};
	arrowUp.width = g_ArrowUp.width * scale;
	arrowUp.height = g_ArrowUp.height * scale;
	arrowUp.left = 637;
	arrowUp.bottom = 50 + g_ArrowDown.width * scale;
	DrawTexture(g_ArrowUp, arrowUp);

	Point2f arrowUpText{};
	arrowUpText.x = arrowUp.left;
	arrowUpText.y = arrowUp.bottom + arrowUp.height + 10;
	DrawTexture(g_ArrowUpText, arrowUpText);
 
	Rectf arrowDown{};
	arrowDown.width = g_ArrowDown.width * scale;
	arrowDown.height = g_ArrowDown.height * scale;
	arrowDown.left = 637;
	arrowDown.bottom = 40;
	DrawTexture(g_ArrowDown, arrowDown);

	Rectf arrowLeft{};
	arrowLeft.width = g_ArrowUp.width * scale;
	arrowLeft.height = g_ArrowUp.height * scale;
	arrowLeft.left = 637 - 10 - g_ArrowLeft.width * scale;
	arrowLeft.bottom = arrowDown.bottom;
	DrawTexture(g_ArrowLeft, arrowLeft);

	Rectf arrowRight{};
	arrowRight.width = g_ArrowUp.width * scale;
	arrowRight.height = g_ArrowUp.height * scale;
	arrowRight.left = 637 + 10 + g_ArrowRight.width * scale;
	arrowRight.bottom = arrowDown.bottom;
	DrawTexture(g_ArrowRight, arrowRight);

	Point2f arrowLeftDownRightText{};
	arrowLeftDownRightText.x = arrowLeft.left;
	arrowLeftDownRightText.y = 10;
	DrawTexture(g_ArrowLeftDownRightText, arrowLeftDownRightText);

	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_RIGHT])
	{
		DrawTexture(g_ArrowRightPressed, arrowRight);
	}
	if ( pStates[SDL_SCANCODE_LEFT])
	{
		DrawTexture(g_ArrowLeftPressed, arrowLeft);
	}
	if (pStates[SDL_SCANCODE_UP])
	{
		DrawTexture(g_ArrowUpPressed, arrowUp);
	}
	if (pStates[SDL_SCANCODE_DOWN])
	{
		DrawTexture(g_ArrowDownPressed, arrowDown);
	}
}
void UpdateShrek(float elapsedSec)
{
	g_ShrekSprite.accumulatedTime += elapsedSec;
	if (g_ShrekSprite.accumulatedTime > g_ShrekSprite.frameTime)
	{
		// Determine next frame number
		++g_ShrekSprite.currentFrame %= g_ShrekSprite.frames;
		g_ShrekSprite.accumulatedTime -= g_ShrekSprite.frameTime;
	}
}
void DrawShrek()
{
	// Select a part from the png
	Rectf srcRect{};
	srcRect.width = g_ShrekSprite.texture.width / g_ShrekSprite.cols;
	srcRect.height = g_ShrekSprite.texture.height / (g_ShrekSprite.frames / g_ShrekSprite.cols);
	srcRect.left = float(int(g_ShrekSprite.currentFrame * srcRect.width) % int(g_ShrekSprite.texture.width));
	srcRect.bottom = (int(g_ShrekSprite.currentFrame * srcRect.width) / int(g_ShrekSprite.texture.width)) * srcRect.height + srcRect.height;

	// Draw it at topright side of the screen
	Rectf destRect{};
	destRect.left = 0;
	destRect.bottom = 0;
	destRect.width = g_WindowWidth;
	destRect.height = g_WindowHeight;

	DrawTexture(g_ShrekSprite.texture, destRect, srcRect);

	Point2f leaveShrek(10, 10);
	DrawTexture(g_LeaveShrekText, leaveShrek);
}
void DrawGameOver()
{
	Rectf gameOverScreen{};
	gameOverScreen.left = 0;
	gameOverScreen.bottom = 0;
	gameOverScreen.width = g_WindowWidth;
	gameOverScreen.height = g_WindowHeight;
	DrawTexture(g_GameOver, gameOverScreen);
	
	Rectf backToMenu{};
	backToMenu.left = g_WindowWidth/2 - 150 - 100;
	backToMenu.bottom = g_WindowHeight / 4;
	backToMenu.width = 200;
	backToMenu.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(backToMenu.left + 2, backToMenu.bottom - 2, backToMenu.width, backToMenu.height, 3);
	SetColor(1,1,1,1);
	if (IsPointInRect(g_MousePos, backToMenu))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(backToMenu, 3);
	
	DrawTexture(g_ReturnText, Point2f(backToMenu.left + backToMenu.width/2 - g_ReturnText.width/2, backToMenu.bottom + backToMenu.height/2 - g_ReturnText.height/2));

	Rectf retry{};
	retry.left = g_WindowWidth/2 + 150 - 100;
	retry.bottom = g_WindowHeight / 4;
	retry.width = 200;
	retry.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(retry.left + 2, retry.bottom - 2, retry.width, retry.height, 3);
	SetColor(1,1,1,1);
	if (IsPointInRect(g_MousePos, retry))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(retry, 3);
	
	DrawTexture(g_RetryText, Point2f(retry.left + retry.width/2 - g_RetryText.width/2, retry.bottom + retry.height/2 - g_RetryText.height/2));

	Point2f score{};
	score.x = g_WindowWidth/2 - 165 - g_ScoreTextGameOver.width/2;
	score.y = g_WindowHeight/2 - 40;
	DrawTexture(g_ScoreTextGameOver, score);

	Rectf apple{};
	apple.left = g_WindowWidth/2 - 150 + g_ScoreTextGameOver.width/2 - 10;
	apple.bottom = g_WindowHeight/2 - 42;
	apple.height = apple.width = 32.5f;
	DrawTexture(g_AppleScore, apple);

	Point2f highscore{};
	highscore.x = g_WindowWidth/2 + 135 - g_HighScoreTextGameOver.width/2;
	highscore.y = g_WindowHeight/2 - 40;
	DrawTexture(g_HighScoreTextGameOver, highscore);

	Rectf trophy{};
	trophy.left = g_WindowWidth/2 + 150 + g_HighScoreTextGameOver.width/2 - 10;
	trophy.bottom = g_WindowHeight/2 - 42;
	trophy.height = trophy.width = g_CellSize;
	DrawTexture(g_Trophy, trophy);

	Rectf competitiveModeRect{};
	competitiveModeRect.left = g_WindowWidth / 2 + 60;
	competitiveModeRect.bottom = g_WindowHeight / 3 - 95;
	competitiveModeRect.width = g_CompetitiveModeText.height + g_WallsSettingTextOff.width - 10;
	competitiveModeRect.height = g_CompetitiveModeText.height + 10;
	SetColor(0, 0, 0, .5f);
	DrawRect(competitiveModeRect.left + 2, competitiveModeRect.bottom - 2, competitiveModeRect.width, competitiveModeRect.height, 3);
	SetColor(1, 1, 1, 1);
	DrawRect(competitiveModeRect, 3);

	Point2f competitiveMode{};
	competitiveMode.x = g_WindowWidth / 2 - (g_CompetitiveModeText.width / 2 + competitiveModeRect.width / 2);
	competitiveMode.y = g_WindowHeight / 3 - 90;
	DrawTexture(g_CompetitiveModeText, competitiveMode);


	if (g_CompetitiveMode)
	{
		DrawTexture(g_WallsSettingTextOn, Point2f(competitiveModeRect.left + 5, competitiveModeRect.bottom + 5));
	}
	else
	{
		DrawTexture(g_WallsSettingTextOff, Point2f(competitiveModeRect.left + 5, competitiveModeRect.bottom + 5));
	}
}
void DrawMainMenu()
{
	Rectf mainMenu{};
	mainMenu.left = mainMenu.bottom = 0;
	mainMenu.height = g_MainMenu.height;
	mainMenu.width = g_MainMenu.width;
	DrawTexture(g_MainMenu, mainMenu); 

	Rectf exit{};
	exit.width = 200;
	exit.height = 70;
	exit.left = g_WindowWidth / 2 - exit.width / 2;
	exit.bottom = 50;
	SetColor(0, 0, 0, .5f);
	DrawRect(exit.left + 2, exit.bottom - 2, exit.width, exit.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, exit))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(exit, 3);

	Point2f exitText{};
	exitText.x = g_WindowWidth / 2 - g_ExitText.width / 2;
	exitText.y = exit.bottom + exit.height / 2 - g_ExitText.height / 2;
	DrawTexture(g_ExitText, exitText);

	Rectf credits{};
	credits.width = 200;
	credits.height = 70;
	credits.left = g_WindowWidth / 2 - exit.width / 2;
	credits.bottom = exit.bottom + exit.height + 20;
	SetColor(0, 0, 0, .5f);
	DrawRect(credits.left + 2, credits.bottom - 2, credits.width, credits.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, credits))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(credits, 3);

	Point2f creditsText{};
	creditsText.x = g_WindowWidth / 2 - g_CreditsText.width / 2;
	creditsText.y = credits.bottom + credits.height / 2 - g_CreditsText.height / 2;
	DrawTexture(g_CreditsText, creditsText);

	Rectf gameModes{};
	gameModes.width = 200;
	gameModes.height = 70;
	gameModes.left = g_WindowWidth / 2 - gameModes.width / 2;
	gameModes.bottom = credits.bottom + credits.height + 20;
	SetColor(0, 0, 0, .5f);
	DrawRect(gameModes.left + 2, gameModes.bottom - 2, gameModes.width, gameModes.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, gameModes))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(gameModes, 3);

	Point2f gameModesText{};
	gameModesText.x = g_WindowWidth / 2 - g_GameModesText.width / 2;
	gameModesText.y = gameModes.bottom + gameModes.height / 2 - g_GameModesText.height / 2;
	DrawTexture(g_GameModesText, gameModesText);
}
void ResetGame()
{
	g_Direction = g_DirectionState::stationary;
	g_SnakePos.x = g_SnakePosCenterX;
	g_SnakePos.y = g_SnakePosCenterY;
	g_SnakeArr[0] =  3;
	g_SnakeArr[1] =  3;
	g_SnakeArr[2] =  3;
	g_SnakeLength = 2;
	g_ScoreCounter = 0;
	UpdateScore();
	UpdateApple();
}
void UpdateCredits(float elapsedSec)
{
	g_ScrollingCreddits += 100 * elapsedSec;
	UpdateKudSprite(elapsedSec);
	g_TotalTime += elapsedSec;
}
void DrawCredits()
{
	ClearBackground(0, 0, 0);
	Rectf snekTitle{};
	snekTitle.width = g_SnekTitle.width;
	snekTitle.height = g_SnekTitle.height;
	snekTitle.left = 0;
	snekTitle.bottom = g_ScrollingCreddits - g_WindowHeight;
	DrawTexture(g_SnekTitle, snekTitle);

	Point2f credits{ g_WindowWidth / 2 - g_CreditsScreenText.width / 2, g_ScrollingCreddits - g_WindowHeight/2 -  g_CreditsText.height - 5 };
	DrawTexture(g_CreditsScreenText, credits);

	Point2f mendel{ g_WindowWidth / 2 - g_MendelText.width / 2, credits.y - g_MendelText.height - 5 };
	DrawTexture(g_MendelText, mendel);

	Point2f michiel{ g_WindowWidth / 2 - g_MichielText.width / 2, mendel.y - g_MichielText.height - 5 };
	DrawTexture(g_MichielText, michiel);
	if (g_TotalTime > 10)
	{
		DrawKudSprite();
	}
	

	Point2f leaveShrek(10, 10);
	DrawTexture(g_LeaveShrekText, leaveShrek);
}
void UpdateKudSprite(float elapsedSec)
{
	//	g_KudSprite.accumulatedTime += elapsedSec;
	//	if (g_KudSprite.accumulatedTime > g_KudSprite.frameTime)
	//	{
	//		++g_KudSprite.currentFrame %= g_KudSprite.frames;
	//		g_KudSprite.accumulatedTime -= g_KudSprite.frameTime;
	//	}
}
void DrawKudSprite()
{
	//Rectf srcRect{};
	//srcRect.width = g_KudSprite.texture.width / g_KudSprite.cols;
	//srcRect.height = g_KudSprite.texture.height / (g_KudSprite.frames / g_KudSprite.cols);
	//srcRect.left = float(int(g_KudSprite.currentFrame * srcRect.width) % int(g_KudSprite.texture.width));
	//srcRect.bottom = (int(g_KudSprite.currentFrame * srcRect.width) / int(g_KudSprite.texture.width)) * srcRect.height + srcRect.height;

	//Rectf kudSprite{};
	//kudSprite.left = 0;
	//kudSprite.bottom = 0;
	//kudSprite.height = g_WindowHeight;
	//kudSprite.width = g_WindowWidth;

	//DrawTexture(g_KudSprite.texture, kudSprite, srcRect);
}
void DrawPauseButton()
{
	Rectf pauseButton{};
	pauseButton.width = pauseButton.height = 50;
	pauseButton.left = g_WindowWidth - 10 - pauseButton.width;
	pauseButton.bottom = g_WindowHeight - 10 - pauseButton.height;
	SetColor(0, 0, 0, 0.5f);
	DrawRect(pauseButton.left + 2, pauseButton.bottom - 2, pauseButton.width, pauseButton.height, 3);
	SetColor(1, 1, 1);
	if (IsPointInRect(g_MousePos, pauseButton))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(pauseButton, 3);

	Rectf rect1{};
	rect1.width = 10;
	rect1.height = 35;
	rect1.bottom = pauseButton.bottom + 7.5f;
	rect1.left = pauseButton.left + 10.333f;
	SetColor(0, 0, 0, 0.5f);
	DrawRect(rect1.left + 2, rect1.bottom - 2, rect1.width, rect1.height, 3);
	SetColor(1, 1, 1);
	FillRect(rect1);

	Rectf rect2{};
	rect2.width = 10;
	rect2.height = 35;
	rect2.bottom = pauseButton.bottom + 7.5f;
	rect2.left = rect1.left + rect1.width + 9.33f;
	SetColor(0, 0, 0, 0.5f);
	DrawRect(rect2.left + 2, rect2.bottom - 2, rect2.width, rect2.height, 3);
	SetColor(1, 1, 1);
	FillRect(rect2);
}
void DrawPausedScreen()
{
	Rectf background{ 0, 0, g_WindowWidth, g_WindowHeight };
	SetColor(0, 0, 0, 0.7f);
	FillRect(background);
	
	Rectf paused{ 0,0,g_WindowWidth, g_WindowHeight };
	DrawTexture(g_PausedScreen, paused);

	Rectf backToMenu{};
	backToMenu.left = g_WindowWidth / 2 - 150 - 100;
	backToMenu.bottom = g_WindowHeight / 3;
	backToMenu.width = 200;
	backToMenu.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(backToMenu.left + 2, backToMenu.bottom - 2, backToMenu.width, backToMenu.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, backToMenu))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(backToMenu, 3);

	DrawTexture(g_ReturnText, Point2f(backToMenu.left + backToMenu.width / 2 - g_ReturnText.width / 2, backToMenu.bottom + backToMenu.height / 2 - g_ReturnText.height / 2));

	Rectf continuePlaying{};
	continuePlaying.left = g_WindowWidth / 2 + 150 - 100;
	continuePlaying.bottom = g_WindowHeight / 3;
	continuePlaying.width = 200;
	continuePlaying.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(continuePlaying.left + 2, continuePlaying.bottom - 2, continuePlaying.width, continuePlaying.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, continuePlaying))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(continuePlaying, 3);

	DrawTexture(g_ContinueText, Point2f(continuePlaying.left + continuePlaying.width / 2 - g_ContinueText.width / 2, continuePlaying.bottom + continuePlaying.height / 2 - g_ContinueText.height / 2));
}
void DrawGameModes()
{
	Rectf screen{};
	screen.left = 0;
	screen.bottom = 0;
	screen.width = g_WindowWidth;
	screen.height = g_WindowHeight;
	DrawTexture(g_GameModesBackGround, screen);

	Rectf onePlayer{};
	onePlayer.width = 200;
	onePlayer.height = 70;
	onePlayer.left = g_WindowWidth/2 - onePlayer.width/2;
	onePlayer.bottom = g_WindowHeight/2 - onePlayer.height/2;
	onePlayer.left += 2;
	onePlayer.bottom -= 2;
	SetColor(0, 0, 0, .5f);
	DrawRect(onePlayer.left + 2, onePlayer.bottom - 2, onePlayer.width, onePlayer.height, 3);
	SetColor(1, 1, 1);
	if (IsPointInRect(g_MousePos, onePlayer))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(onePlayer, 3);
	

	DrawTexture(g_OnePlayerText, Point2f(g_WindowWidth / 2 - g_OnePlayerText.width / 2, g_WindowHeight / 2 - g_OnePlayerText.height / 2));

	Rectf multiplayer{};
	multiplayer.width = 200;
	multiplayer.height = 70;
	multiplayer.left = g_WindowWidth/2 - multiplayer.width/2;
	multiplayer.bottom = g_WindowHeight/2 - multiplayer.height/2 - onePlayer.height - 20;
	multiplayer.left += 2;
	multiplayer.bottom -= 2;
	SetColor(0, 0, 0, .5f);
	DrawRect(multiplayer.left + 2, multiplayer.bottom - 2, multiplayer.width, multiplayer.height, 3);
	SetColor(1, 1, 1);
	if (IsPointInRect(g_MousePos, multiplayer))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(multiplayer, 3);
	
	DrawTexture(g_MultiplayerText, Point2f(g_WindowWidth / 2 - g_MultiplayerText.width / 2, g_WindowHeight / 2 - g_MultiplayerText.height / 2 - onePlayer.height - 20));

	Rectf party{};
	party.width = 200;
	party.height = 70;
	party.left = g_WindowWidth / 2 - party.width / 2;
	party.bottom = g_WindowHeight / 2 - party.height / 2 - 2 * (onePlayer.height + 20);
	party.left += 2;
	party.bottom -= 2;
	SetColor(0, 0, 0, .5f);
	DrawRect(party.left + 2, party.bottom - 2, party.width, party.height, 3);
	SetColor(1, 1, 1);
	if (IsPointInRect(g_MousePos, party))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(party, 3);
	

	DrawTexture(g_PartyModeText, Point2f(g_WindowWidth / 2 - g_PartyModeText.width / 2, g_WindowHeight / 2 - g_PartyModeText.height / 2 - 2 * (onePlayer.height + 20)));
	
	Rectf returnButton{};
	returnButton.width = 70;
	returnButton.height = 70;
	returnButton.left = 10;
	returnButton.bottom = g_WindowHeight - returnButton.height - 10;
	
	if (IsPointInRect(g_MousePos, returnButton))
	{
		DrawTexture(g_ReturnButtonOrange, returnButton);
	}
	else
	{
		DrawTexture(g_ReturnButton, returnButton);
	}

	Rectf settingsButton{};
	settingsButton.width = 70;
	settingsButton.height = 70;
	settingsButton.left = g_WindowWidth - settingsButton.width - 10;
	settingsButton.bottom = g_WindowHeight - settingsButton.height - 10;

	if (IsPointInRect(g_MousePos, settingsButton))
	{
		DrawTexture(g_SettingsOrange, settingsButton);
	}
	else
	{
		DrawTexture(g_SettingsWhite, settingsButton);
	}
}
void DrawSettings()
{
	Rectf settings{ 0,0,g_WindowWidth, g_WindowHeight };
	DrawTexture(g_SettingsBG, settings);

	Rectf walls{};
	walls.left = g_WindowWidth / 2 - 150 - 100;
	walls.bottom = g_WindowHeight / 3;
	walls.width = 200;
	walls.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(walls.left + 2, walls.bottom - 2, walls.width, walls.height, 3);
	SetColor(1, 1, 1, 1);
	DrawRect(walls, 3);

	DrawTexture(g_WallsSettingText, Point2f(walls.left + walls.width / 2 - g_WallsSettingText.width / 2 - 25, walls.bottom + walls.height / 2 - g_WallsSettingText.height / 2));



	Rectf wallsBox{};
	wallsBox.left = walls.left + walls.width / 2 + g_WallsSettingText.width / 2 - 15;
	wallsBox.bottom = walls.bottom + walls.height / 2 - g_WallsSettingText.height / 2 - 5;
	wallsBox.width = g_WallsSettingText.height + g_WallsSettingTextOff.width - 10;
	wallsBox.height = g_WallsSettingText.height + 10;
	SetColor(0, 0, 0, .5f);
	DrawRect(wallsBox.left + 2, wallsBox.bottom - 2, wallsBox.width, wallsBox.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, wallsBox))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(wallsBox, 3);


	if (g_Walls)
	{
		DrawTexture(g_WallsSettingTextOn, Point2f(wallsBox.left + 5, wallsBox.bottom + 5));
	}
	else
	{
		DrawTexture(g_WallsSettingTextOff, Point2f(wallsBox.left + 5, wallsBox.bottom + 5));
	}


	Rectf speed{};
	speed.left = g_WindowWidth / 2 + 150 - 100;
	speed.bottom = g_WindowHeight / 3;
	speed.width = 200;
	speed.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(speed.left + 2, speed.bottom - 2, speed.width, speed.height, 3);
	SetColor(1, 1, 1, 1);
	DrawRect(speed, 3);

	DrawTexture(g_SpeedSettingsText, Point2f(speed.left + speed.width / 2 - g_SpeedSettingsText.width / 2 - 25, speed.bottom + speed.height / 2 - g_SpeedSettingsText.height / 2));

	DrawTexture(g_SpeedText, Point2f(speed.left + 130, speed.bottom + speed.height / 2 - g_SpeedSettingsText.height / 2));

	Rectf speedUpBox{};
	speedUpBox.left = g_WindowWidth / 2 + 150 - 100 + 155;
	speedUpBox.bottom = g_WindowHeight / 3 + 40;
	speedUpBox.width = 20;
	speedUpBox.height = 20;
	SetColor(0, 0, 0, .5f);
	DrawRect(speedUpBox.left + 2, speedUpBox.bottom - 2, speedUpBox.width, speedUpBox.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, speedUpBox))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}

	DrawRect(speedUpBox, 3);
	DrawTexture(g_SpeedArrowUp, speedUpBox);

	Rectf speedDownBox{};
	speedDownBox.left = g_WindowWidth / 2 + 150 - 100 + 155;
	speedDownBox.bottom = g_WindowHeight / 3 + 10;
	speedDownBox.width = 20;
	speedDownBox.height = 20;
	SetColor(0, 0, 0, .5f);
	DrawRect(speedDownBox.left + 2, speedDownBox.bottom - 2, speedDownBox.width, speedDownBox.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, speedDownBox))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}

	DrawRect(speedDownBox, 3);
	DrawTexture(g_SpeedArrowDown, speedDownBox);
	
	Rectf competitiveModeRect{};
	competitiveModeRect.left = g_WindowWidth / 2 + 60;
	competitiveModeRect.bottom = g_WindowHeight / 3 - 65;
	competitiveModeRect.width = g_CompetitiveModeText.height + g_WallsSettingTextOff.width - 10;
	competitiveModeRect.height = g_CompetitiveModeText.height + 10;
	SetColor(0, 0, 0, .5f);
	DrawRect(competitiveModeRect.left + 2, competitiveModeRect.bottom - 2, competitiveModeRect.width, competitiveModeRect.height, 3);
	SetColor(1, 1, 1, 1);
	DrawRect(competitiveModeRect, 3);

	Point2f competitiveMode{};
	competitiveMode.x = g_WindowWidth / 2 - (g_CompetitiveModeText.width / 2 + competitiveModeRect.width / 2);
	competitiveMode.y = g_WindowHeight / 3 - 60;
	DrawTexture(g_CompetitiveModeText, competitiveMode);


	if (g_CompetitiveMode)
	{
		DrawTexture(g_WallsSettingTextOn, Point2f(competitiveModeRect.left + 5, competitiveModeRect.bottom + 5));
	}
	else
	{
		DrawTexture(g_WallsSettingTextOff, Point2f(competitiveModeRect.left + 5, competitiveModeRect.bottom + 5));
	}


	Rectf returnButton{};
	returnButton.width = 70;
	returnButton.height = 70;
	returnButton.left = 10;
	returnButton.bottom = g_WindowHeight - returnButton.height - 10;

	if (IsPointInRect(g_MousePos, returnButton))
	{
		DrawTexture(g_ReturnButtonOrange, returnButton);
	}
	else
	{
		DrawTexture(g_ReturnButton, returnButton);
	}
}

void DrawPVPGameMode()
{
	DrawBackground();
	DrawSnake1();
	DrawSnake2();
	DrawApple();
	InformationPVP();
	DrawPauseButton();
	SetColor(204 / 255.f, 167 / 255.f, 89 / 255.f);
	if (g_Walls)
	{
		SetColor(1, 0, 0);;
	}
	DrawRect(g_Border, g_Border, g_CellSize * g_Columns, g_CellSize * g_Rows, 3);

	if (g_IsGamePaused)
	{
		DrawPausedScreen();
	}
}
void UpdatePVPGameMode(float elapsedSec)
{
		UpdateSnake1(elapsedSec);
		UpdateSnake2(elapsedSec);
		CheckOutOfBoundsPVP();
		UpdateApplePVP();
		CollisionCheckPVP();
}
void DrawSnake1()
{
	g_SnakeTail = g_Snake1Pos;

	Rectf snakeBody{};
	snakeBody.left = g_SnakeTail.x;
	snakeBody.bottom = g_SnakeTail.y;
	snakeBody.width = g_CellSize;
	snakeBody.height = g_CellSize;

	for (int i{}; i < g_Snake1Length; ++i)
	{


		switch (g_Snake1Arr[i])
		{
		case 1:
			g_SnakeTail.x += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x > g_Border + (g_Columns - 1) * g_CellSize)
				{
					g_SnakeTail.x = g_Border;
				}
			}
			snakeBody.left = g_SnakeTail.x;
			DrawTexture(g_SnakeBodyLeft, snakeBody);
			break;
		case 2:
			g_SnakeTail.x -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x < g_Border)
				{
					g_SnakeTail.x = g_Border + (g_Columns - 1) * g_CellSize;
				}
			}
			snakeBody.left = g_SnakeTail.x;
			DrawTexture(g_SnakeBodyRight, snakeBody);
			break;
		case 3:
			g_SnakeTail.y -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y < g_Border)
				{
					g_SnakeTail.y = g_Border + (g_Rows - 1) * g_CellSize;
				}
			}
			snakeBody.bottom = g_SnakeTail.y;
			DrawTexture(g_SnakeBodyUp, snakeBody);
			break;
		case 4:
			g_SnakeTail.y += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y > g_Border + (g_Rows - 1) * g_CellSize)
				{
					g_SnakeTail.y = g_Border;
				}
			}
			snakeBody.bottom = g_SnakeTail.y;
			DrawTexture(g_SnakeBodyDown, snakeBody);
			break;
		}
	}

	Rectf snakeHead{};
	snakeHead.left = g_Snake1Pos.x;
	snakeHead.bottom = g_Snake1Pos.y;
	snakeHead.width = snakeHead.height = g_CellSize;

	switch (g_DirectionP1)
	{
	case g_DirectionState::left:
		DrawTexture(g_SnakeHeadLeft, snakeHead);
		break;
	case g_DirectionState::right:
		DrawTexture(g_SnakeHeadRight, snakeHead);
		break;
	case g_DirectionState::stationary:
	case g_DirectionState::up:
		DrawTexture(g_SnakeHeadUp, snakeHead);
		break;
	case g_DirectionState::down:
		DrawTexture(g_SnakeHeadDown, snakeHead);
		break;
	}
}
void DrawSnake2()
{
	g_SnakeTail = g_Snake2Pos;
	
	Rectf snakeBody{};
	snakeBody.left = g_SnakeTail.x;
	snakeBody.bottom = g_SnakeTail.y;
	snakeBody.width = g_CellSize;
	snakeBody.height = g_CellSize;

	for (int i{}; i < g_Snake2Length; ++i)
	{
		

		switch (g_Snake2Arr[i])
		{
		case 1:
			g_SnakeTail.x += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x > g_Border + (g_Columns - 1) * g_CellSize)
				{
					g_SnakeTail.x = g_Border;
				}
			}
			snakeBody.left = g_SnakeTail.x;
			DrawTexture(g_SnakeBodyLeftP2, snakeBody);
			break;
		case 2:
			g_SnakeTail.x -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x < g_Border)
				{
					g_SnakeTail.x = g_Border + (g_Columns - 1) * g_CellSize;
				}
			}
			snakeBody.left = g_SnakeTail.x;
			DrawTexture(g_SnakeBodyRightP2, snakeBody);
			break;
		case 3:
			g_SnakeTail.y -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y < g_Border)
				{
					g_SnakeTail.y = g_Border + (g_Rows - 1) * g_CellSize;
				}
			}
			snakeBody.bottom = g_SnakeTail.y;
			DrawTexture(g_SnakeBodyUpP2, snakeBody);
			break;
		case 4:
			g_SnakeTail.y += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y > g_Border + (g_Rows - 1) * g_CellSize)
				{
					g_SnakeTail.y = g_Border;
				}
			}
			snakeBody.bottom = g_SnakeTail.y;
			DrawTexture(g_SnakeBodyDownP2, snakeBody);
			break;
		}
	}

	Rectf snakeHead{};
	snakeHead.left = g_Snake2Pos.x;
	snakeHead.bottom = g_Snake2Pos.y;
	snakeHead.width = snakeHead.height = g_CellSize;

	switch (g_DirectionP2)
	{
	case g_DirectionState::left:
		DrawTexture(g_SnakeHeadLeftP2, snakeHead);
		break;
	case g_DirectionState::right:
		DrawTexture(g_SnakeHeadRightP2, snakeHead);
		break;
	case g_DirectionState::stationary:
	case g_DirectionState::up:
		DrawTexture(g_SnakeHeadUpP2, snakeHead);
		break;
	case g_DirectionState::down:
		DrawTexture(g_SnakeHeadDownP2, snakeHead);
		break;
	}
}
void UpdateSnake1(float elapsedSec)
{
	if ((g_PVPWinner == g_PVPState::running) && (!g_IsGamePaused)) 
	{
		g_AccumulatedTime1 += elapsedSec;
		if (g_AccumulatedTime1 > g_TimePerCell)
		{

			for (int i{ g_ArraySize - 2 }; i >= 0; --i)
			{
				if (g_Snake1Arr[i] != 0)
				{
					g_Snake1Arr[i + 1] = g_Snake1Arr[i];
				}
			}

			switch (g_DirectionP1)
			{
			case g_DirectionState::left:
				g_Snake1Pos.x -= g_CellSize;
				if (!g_Walls)
				{
					if (g_Snake1Pos.x < g_Border)
					{
						g_Snake1Pos.x = g_Border + (g_Columns - 1) * g_CellSize;
					}
				}
				g_Snake1Arr[0] = 1;
				break;
			case g_DirectionState::right:
				g_Snake1Pos.x += g_CellSize;
				if (!g_Walls)
				{
					if (g_Snake1Pos.x > g_Border + (g_Columns - 1) * g_CellSize)
					{
						g_Snake1Pos.x = g_Border;
					}
				}
				g_Snake1Arr[0] = 2;
				break;
			case g_DirectionState::up:
				g_Snake1Pos.y += g_CellSize;
				if (!g_Walls)
				{
					if (g_Snake1Pos.y > g_Border + (g_Rows - 1) * g_CellSize)
					{
						g_Snake1Pos.y = g_Border;
					}
				}
				g_Snake1Arr[0] = 3;
				break;
			case g_DirectionState::down:
				g_Snake1Pos.y -= g_CellSize;
				if (!g_Walls)
				{
					if (g_Snake1Pos.y < g_Border)
					{
						g_Snake1Pos.y = g_Border + (g_Rows - 1) * g_CellSize;
					}
				}
				g_Snake1Arr[0] = 4;
				break;
			}
			g_AccumulatedTime1 -= g_TimePerCell;

			if (g_MovedThisGameTickP1 == true)
			{
				g_MovedThisGameTickP1 = false;
			}
		}
	}
}
void UpdateSnake2(float elapsedSec)
{
	if ((g_PVPWinner == g_PVPState::running) && (!g_IsGamePaused))
	{
		g_AccumulatedTime2 += elapsedSec;
		if (g_AccumulatedTime2 > g_TimePerCell)
		{

			for (int i{ g_ArraySize - 2 }; i >= 0; --i)
			{
				if (g_Snake2Arr[i] != 0)
				{
					g_Snake2Arr[i + 1] = g_Snake2Arr[i];
				}
			}

			switch (g_DirectionP2)
			{
			case g_DirectionState::left:
				g_Snake2Pos.x -= g_CellSize;
				if (!g_Walls)
				{
					if (g_Snake2Pos.x < g_Border)
					{
						g_Snake2Pos.x = g_Border + (g_Columns - 1) * g_CellSize;
					}
				}
				g_Snake2Arr[0] = 1;
				break;
			case g_DirectionState::right:
				g_Snake2Pos.x += g_CellSize;
				if (!g_Walls)
				{
					if (g_Snake2Pos.x > g_Border + (g_Columns - 1) * g_CellSize)
					{
						g_Snake2Pos.x = g_Border;
					}
				}
				g_Snake2Arr[0] = 2;
				break;
			case g_DirectionState::up:
				g_Snake2Pos.y += g_CellSize;
				if (!g_Walls)
				{
					if (g_Snake2Pos.y > g_Border + (g_Rows - 1) * g_CellSize)
					{
						g_Snake2Pos.y = g_Border;
					}
				}
				g_Snake2Arr[0] = 3;
				break;
			case g_DirectionState::down:
				g_Snake2Pos.y -= g_CellSize;
				if (!g_Walls)
				{
					if (g_Snake2Pos.y < g_Border)
					{
						g_Snake2Pos.y = g_Border + (g_Rows - 1) * g_CellSize;
					}
				}
				g_Snake2Arr[0] = 4;
				break;
			}
			g_AccumulatedTime2 -= g_TimePerCell;

			if (g_MovedThisGameTickP2 == true)
			{
				g_MovedThisGameTickP2 = false;
			}
		}
	}
}
void CollisionCheckPVP()
{
	bool redWins{ false };
	bool blueWins{ false };

	g_SnakeTail = g_Snake1Pos;
	for (int i{}; i < g_Snake1Length; ++i)
	{
		switch (g_Snake1Arr[i])
		{
		case 1:
			g_SnakeTail.x += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x > g_Border + (g_Columns - 1) * g_CellSize)
				{
					g_SnakeTail.x = g_Border;
				}
			}
			break;
		case 2:
			g_SnakeTail.x -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x < g_Border)
				{
					g_SnakeTail.x = g_Border + (g_Columns - 1) * g_CellSize;
				}
			}
			break;
		case 3:
			g_SnakeTail.y -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y < g_Border)
				{
					g_SnakeTail.y = g_Border + (g_Rows - 1) * g_CellSize;
				}
			}
			break;
		case 4:
			g_SnakeTail.y += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y > g_Border + (g_Rows - 1) * g_CellSize)
				{
					g_SnakeTail.y = g_Border;
				}
			}
			break;
		}


		if ((g_Snake1Pos.x == g_SnakeTail.x) && (g_Snake1Pos.y == g_SnakeTail.y))
		{
			g_PVPWinner = g_PVPState::redWins;
			redWins = true;
		}

		if ((g_Snake2Pos.x == g_SnakeTail.x) && (g_Snake2Pos.y == g_SnakeTail.y))
		{
			g_PVPWinner = g_PVPState::blueWins;
			blueWins = true;
		}
	}

	g_SnakeTail = g_Snake2Pos;
	for (int i{}; i < g_Snake2Length; ++i)
	{
		switch (g_Snake2Arr[i])
		{
		case 1:
			g_SnakeTail.x += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x > g_Border + (g_Columns - 1) * g_CellSize)
				{
					g_SnakeTail.x = g_Border;
				}
			}
			break;
		case 2:
			g_SnakeTail.x -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x < g_Border)
				{
					g_SnakeTail.x = g_Border + (g_Columns - 1) * g_CellSize;
				}
			}
			break;
		case 3:
			g_SnakeTail.y -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y < g_Border)
				{
					g_SnakeTail.y = g_Border + (g_Rows - 1) * g_CellSize;
				}
			}
			break;
		case 4:
			g_SnakeTail.y += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y > g_Border + (g_Rows - 1) * g_CellSize)
				{
					g_SnakeTail.y = g_Border;
				}
			}
			break;
		}


		if ((g_Snake2Pos.x == g_SnakeTail.x) && (g_Snake2Pos.y == g_SnakeTail.y))
		{
			g_PVPWinner = g_PVPState::blueWins;
			blueWins = true;
		}


		if ((g_Snake1Pos.x == g_SnakeTail.x) && (g_Snake1Pos.y == g_SnakeTail.y))
		{
			g_PVPWinner = g_PVPState::redWins;
			redWins = true;
		}
	}


	//draw
	if ((g_Snake1Pos.x == g_Snake2Pos.x) && (g_Snake1Pos.y == g_Snake2Pos.y))
	{
		g_PVPWinner = g_PVPState::draw;
	}

	if ((redWins) && (blueWins))
	{
		g_PVPWinner = g_PVPState::draw;
	}
}
void UpdateApplePVP()
{
	if ((g_Snake1Pos.x == g_AppleCord.x) && (g_Snake1Pos.y == g_AppleCord.y))
	{
		g_AppleCord.x = g_Border + g_CellSize * (rand() % g_Rows);
		g_AppleCord.y = g_Border + g_CellSize * (rand() % g_Columns);
		g_Snake1Length++;
	}

	if ((g_Snake2Pos.x == g_AppleCord.x) && (g_Snake2Pos.y == g_AppleCord.y))
	{
		g_AppleCord.x = g_Border + g_CellSize * (rand() % g_Rows);
		g_AppleCord.y = g_Border + g_CellSize * (rand() % g_Columns);
		g_Snake2Length++;
	}

	g_SnakeTail = g_Snake1Pos;
	for (int i{}; i < g_Snake1Length; ++i)
	{
		switch (g_Snake1Arr[i])
		{
		case 1:
			g_SnakeTail.x += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x > g_Border + (g_Columns - 1) * g_CellSize)
				{
					g_SnakeTail.x = g_Border;
				}
			}
			break;
		case 2:
			g_SnakeTail.x -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x < g_Border)
				{
					g_SnakeTail.x = g_Border + (g_Columns - 1) * g_CellSize;
				}
			}
			break;
		case 3:
			g_SnakeTail.y -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y < g_Border)
				{
					g_SnakeTail.y = g_Border + (g_Rows - 1) * g_CellSize;
				}
			}
			break;
		case 4:
			g_SnakeTail.y += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y > g_Border + (g_Rows - 1) * g_CellSize)
				{
					g_SnakeTail.y = g_Border;
				}
			}
			break;
		}
		if ((g_AppleCord.x == g_SnakeTail.x) && (g_AppleCord.y == g_SnakeTail.y))
		{
			g_AppleCord.x = g_Border + g_CellSize * (rand() % g_Rows);
			g_AppleCord.y = g_Border + g_CellSize * (rand() % g_Columns);
		}
	}

	g_SnakeTail = g_Snake2Pos;
	for (int i{}; i < g_Snake2Length; ++i)
	{
		switch (g_Snake2Arr[i])
		{
		case 1:
			g_SnakeTail.x += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x > g_Border + (g_Columns - 1) * g_CellSize)
				{
					g_SnakeTail.x = g_Border;
				}
			}
			break;
		case 2:
			g_SnakeTail.x -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x < g_Border)
				{
					g_SnakeTail.x = g_Border + (g_Columns - 1) * g_CellSize;
				}
			}
			break;
		case 3:
			g_SnakeTail.y -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y < g_Border)
				{
					g_SnakeTail.y = g_Border + (g_Rows - 1) * g_CellSize;
				}
			}
			break;
		case 4:
			g_SnakeTail.y += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y > g_Border + (g_Rows - 1) * g_CellSize)
				{
					g_SnakeTail.y = g_Border;
				}
			}
			break;
		}
		if ((g_AppleCord.x == g_SnakeTail.x) && (g_AppleCord.y == g_SnakeTail.y))
		{
			g_AppleCord.x = g_Border + g_CellSize * (rand() % g_Rows);
			g_AppleCord.y = g_Border + g_CellSize * (rand() % g_Columns);
		}
	}
}
void CheckOutOfBoundsPVP()
{
	if (((g_Snake1Pos.x < g_Border) || (g_Snake1Pos.x >= g_Border + (g_CellSize * g_Columns))) ||
		((g_Snake1Pos.y < g_Border) || (g_Snake1Pos.y >= g_Border + (g_CellSize * g_Rows))))
	{
		g_PVPWinner = g_PVPState::redWins;
	}
	if (((g_Snake2Pos.x < g_Border) || (g_Snake2Pos.x >= g_Border + (g_CellSize * g_Columns))) ||
		((g_Snake2Pos.y < g_Border) || (g_Snake2Pos.y >= g_Border + (g_CellSize * g_Rows))))
	{
		g_PVPWinner = g_PVPState::blueWins;
	}

	if (((g_Snake1Pos.x < g_Border) || (g_Snake1Pos.x >= g_Border + (g_CellSize * g_Columns))) ||
	((g_Snake1Pos.y < g_Border) || (g_Snake1Pos.y >= g_Border + (g_CellSize * g_Rows))))
	{
		if (((g_Snake2Pos.x < g_Border) || (g_Snake2Pos.x >= g_Border + (g_CellSize * g_Columns))) ||
		((g_Snake2Pos.y < g_Border) || (g_Snake2Pos.y >= g_Border + (g_CellSize * g_Rows))))
		{
			g_PVPWinner = g_PVPState::draw;
		}
	}
}
void ResetPVPGame()
{
	g_Snake1Length = 2;
	g_Snake1Arr[0] = 3;
	g_Snake1Arr[1] = 3;
	g_Snake1Arr[2] = 3;
	g_Snake1Pos.x = g_SnakePosCenterX - 5 * g_CellSize;
	g_Snake1Pos.y = g_SnakePosCenterY;

	g_DirectionP1 =  g_DirectionState::stationary;
	g_MovedThisGameTickP1 = false;
	g_AccumulatedTime1 = 0.f;

	g_Snake2Length = 2;
	g_Snake2Arr[0] = 3;
	g_Snake2Arr[1] = 3;
	g_Snake2Arr[2] = 3;
	g_Snake2Pos.x = g_SnakePosCenterX + 4 * g_CellSize;
	g_Snake2Pos.y = g_SnakePosCenterY;

	g_DirectionP2 = g_DirectionState::stationary;
	g_MovedThisGameTickP2 = false;
	g_AccumulatedTime2 = 0.f;
}
void DrawBlueWins()
{
	Rectf background{ 0, 0, g_WindowWidth, g_WindowHeight };
	SetColor(0, 0, 0, 0.7f);
	FillRect(background);

	Rectf blueWins{ 0,0,g_WindowWidth, g_WindowHeight };
	DrawTexture(g_BlueWins, blueWins);

	Rectf backToMenu{};
	backToMenu.left = g_WindowWidth / 2 - 150 - 100;
	backToMenu.bottom = g_WindowHeight / 3;
	backToMenu.width = 200;
	backToMenu.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(backToMenu.left + 2, backToMenu.bottom - 2, backToMenu.width, backToMenu.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, backToMenu))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(backToMenu, 3);

	DrawTexture(g_ReturnText, Point2f(backToMenu.left + backToMenu.width / 2 - g_ReturnText.width / 2, backToMenu.bottom + backToMenu.height / 2 - g_ReturnText.height / 2));

	Rectf playAgain{};
	playAgain.left = g_WindowWidth / 2 + 150 - 100;
	playAgain.bottom = g_WindowHeight / 3;
	playAgain.width = 200;
	playAgain.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(playAgain.left + 2, playAgain.bottom - 2, playAgain.width, playAgain.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, playAgain))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(playAgain, 3);

	DrawTexture(g_PlayAgainText, Point2f(playAgain.left + playAgain.width / 2 - g_PlayAgainText.width / 2, playAgain.bottom + playAgain.height / 2 - g_PlayAgainText.height / 2));

	Rectf competitiveModeRect{};
	competitiveModeRect.left = g_WindowWidth / 2 + 60;
	competitiveModeRect.bottom = g_WindowHeight / 3 - 65;
	competitiveModeRect.width = g_CompetitiveModeText.height + g_WallsSettingTextOff.width - 10;
	competitiveModeRect.height = g_CompetitiveModeText.height + 10;
	SetColor(0, 0, 0, .5f);
	DrawRect(competitiveModeRect.left + 2, competitiveModeRect.bottom - 2, competitiveModeRect.width, competitiveModeRect.height, 3);
	SetColor(1, 1, 1, 1);
	DrawRect(competitiveModeRect, 3);

	Point2f competitiveMode{};
	competitiveMode.x = g_WindowWidth / 2 - (g_CompetitiveModeText.width / 2 + competitiveModeRect.width / 2);
	competitiveMode.y = g_WindowHeight / 3 - 60;
	DrawTexture(g_CompetitiveModeText, competitiveMode);


	if (g_CompetitiveMode)
	{
		DrawTexture(g_WallsSettingTextOn, Point2f(competitiveModeRect.left + 5, competitiveModeRect.bottom + 5));
	}
	else
	{
		DrawTexture(g_WallsSettingTextOff, Point2f(competitiveModeRect.left + 5, competitiveModeRect.bottom + 5));
	}
}
void DrawRedWins()
{
	Rectf background{ 0, 0, g_WindowWidth, g_WindowHeight };
	SetColor(0, 0, 0, 0.7f);
	FillRect(background);

	Rectf redWins{ 0,0,g_WindowWidth, g_WindowHeight };
	DrawTexture(g_RedWins, redWins);

	Rectf backToMenu{};
	backToMenu.left = g_WindowWidth / 2 - 150 - 100;
	backToMenu.bottom = g_WindowHeight / 3;
	backToMenu.width = 200;
	backToMenu.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(backToMenu.left + 2, backToMenu.bottom - 2, backToMenu.width, backToMenu.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, backToMenu))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(backToMenu, 3);

	DrawTexture(g_ReturnText, Point2f(backToMenu.left + backToMenu.width / 2 - g_ReturnText.width / 2, backToMenu.bottom + backToMenu.height / 2 - g_ReturnText.height / 2));

	Rectf playAgain{};
	playAgain.left = g_WindowWidth / 2 + 150 - 100;
	playAgain.bottom = g_WindowHeight / 3;
	playAgain.width = 200;
	playAgain.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(playAgain.left + 2, playAgain.bottom - 2, playAgain.width, playAgain.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, playAgain))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(playAgain, 3);

	DrawTexture(g_PlayAgainText, Point2f(playAgain.left + playAgain.width / 2 - g_PlayAgainText.width / 2, playAgain.bottom + playAgain.height / 2 - g_PlayAgainText.height / 2));

	Rectf competitiveModeRect{};
	competitiveModeRect.left = g_WindowWidth / 2 + 60;
	competitiveModeRect.bottom = g_WindowHeight / 3 - 65;
	competitiveModeRect.width = g_CompetitiveModeText.height + g_WallsSettingTextOff.width - 10;
	competitiveModeRect.height = g_CompetitiveModeText.height + 10;
	SetColor(0, 0, 0, .5f);
	DrawRect(competitiveModeRect.left + 2, competitiveModeRect.bottom - 2, competitiveModeRect.width, competitiveModeRect.height, 3);
	SetColor(1, 1, 1, 1);
	DrawRect(competitiveModeRect, 3);

	Point2f competitiveMode{};
	competitiveMode.x = g_WindowWidth / 2 - (g_CompetitiveModeText.width / 2 + competitiveModeRect.width / 2);
	competitiveMode.y = g_WindowHeight / 3 - 60;
	DrawTexture(g_CompetitiveModeText, competitiveMode);


	if (g_CompetitiveMode)
	{
		DrawTexture(g_WallsSettingTextOn, Point2f(competitiveModeRect.left + 5, competitiveModeRect.bottom + 5));
	}
	else
	{
		DrawTexture(g_WallsSettingTextOff, Point2f(competitiveModeRect.left + 5, competitiveModeRect.bottom + 5));
	}
}
void DrawDraw()
{
	Rectf background{ 0, 0, g_WindowWidth, g_WindowHeight };
	SetColor(0, 0, 0, 0.7f);
	FillRect(background);

	Rectf draw{ 0,0,g_WindowWidth, g_WindowHeight };
	DrawTexture(g_Draw, draw);

	Rectf backToMenu{};
	backToMenu.left = g_WindowWidth / 2 - 150 - 100;
	backToMenu.bottom = g_WindowHeight / 3;
	backToMenu.width = 200;
	backToMenu.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(backToMenu.left + 2, backToMenu.bottom - 2, backToMenu.width, backToMenu.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, backToMenu))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(backToMenu, 3);

	DrawTexture(g_ReturnText, Point2f(backToMenu.left + backToMenu.width / 2 - g_ReturnText.width / 2, backToMenu.bottom + backToMenu.height / 2 - g_ReturnText.height / 2));

	Rectf playAgain{};
	playAgain.left = g_WindowWidth / 2 + 150 - 100;
	playAgain.bottom = g_WindowHeight / 3;
	playAgain.width = 200;
	playAgain.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(playAgain.left + 2, playAgain.bottom - 2, playAgain.width, playAgain.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, playAgain))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(playAgain, 3);

	DrawTexture(g_PlayAgainText, Point2f(playAgain.left + playAgain.width / 2 - g_PlayAgainText.width / 2, playAgain.bottom + playAgain.height / 2 - g_PlayAgainText.height / 2));

	Rectf competitiveModeRect{};
	competitiveModeRect.left = g_WindowWidth / 2 + 60;
	competitiveModeRect.bottom = g_WindowHeight / 3 - 65;
	competitiveModeRect.width = g_CompetitiveModeText.height + g_WallsSettingTextOff.width - 10;
	competitiveModeRect.height = g_CompetitiveModeText.height + 10;
	SetColor(0, 0, 0, .5f);
	DrawRect(competitiveModeRect.left + 2, competitiveModeRect.bottom - 2, competitiveModeRect.width, competitiveModeRect.height, 3);
	SetColor(1, 1, 1, 1);
	DrawRect(competitiveModeRect, 3);

	Point2f competitiveMode{};
	competitiveMode.x = g_WindowWidth / 2 - (g_CompetitiveModeText.width / 2 + competitiveModeRect.width / 2);
	competitiveMode.y = g_WindowHeight / 3 - 60;
	DrawTexture(g_CompetitiveModeText, competitiveMode);


	if (g_CompetitiveMode)
	{
		DrawTexture(g_WallsSettingTextOn, Point2f(competitiveModeRect.left + 5, competitiveModeRect.bottom + 5));
	}
	else
	{
		DrawTexture(g_WallsSettingTextOff, Point2f(competitiveModeRect.left + 5, competitiveModeRect.bottom + 5));
	}
}
void InformationPVP()
{
	Point2f textLoc{ g_WindowWidth - 283, g_WindowHeight / 2 + 100 };
	DrawTexture(g_PVPInfoBlue1, textLoc);
	textLoc.y -= 50;
	DrawTexture(g_PVPInfoBlue2, textLoc);
	textLoc.y -= 100;
	DrawTexture(g_PVPInfoRed1, textLoc);
	textLoc.y -= 50;
	DrawTexture(g_PVPInfoRed2, textLoc);
}

void InformationPartyMode()
{
	Point2f score{};
	score.x = g_Border * 2 + g_Columns * g_CellSize;
	score.y = g_WindowHeight - 105;
	DrawTexture(g_ScorePartyModeText, score);

	Rectf apple{};
	apple.left = g_Border * 2 + g_Columns * g_CellSize + 240;
	apple.bottom = g_WindowHeight - 107;
	apple.height = apple.width = 32.5f;
	DrawTexture(g_AppleScore, apple);

	Rectf trophy{};
	trophy.left = g_Border * 2 + g_Columns * g_CellSize + 240;
	trophy.bottom = g_WindowHeight - 37 - 32.5f - 5 - 70;
	trophy.height = trophy.width = g_CellSize;
	DrawTexture(g_Trophy, trophy);

	Point2f highscore{};
	highscore.x = g_Border * 2 + g_Columns * g_CellSize;
	highscore.y = g_WindowHeight - 35 - 32.5f - 5 - 70;
	DrawTexture(g_HighScorePartyModeText, highscore);

	Rectf arrowsUI{};
	float scale{ 0.3f };
	arrowsUI.width = g_ArrowsUI.width * scale;
	arrowsUI.height = g_ArrowsUI.height * scale;
	arrowsUI.left = g_Border * 2 + g_CellSize * g_Columns + ((g_WindowWidth - (g_Border * 2 + g_CellSize * g_Columns)) / 2 - arrowsUI.width / 2);
	arrowsUI.bottom = g_WindowHeight - 35 - 32.5f - 25 - arrowsUI.height;

	Point2f controls{};
	controls.x = g_Border * 2 + g_Columns * g_CellSize;
	controls.y = 90 + 2 * g_ArrowDown.height * 0.5f;
	DrawTexture(g_ControlsText, controls);

	DrawArrowUI();
}
void UpdateScorePartyMode()
{
	g_ScorePartyMode = "Score                     " + std::to_string(g_ScoreCounterPartyMode);
	Color4f textColor{ 1,1,1,0 };
	TextureFromString(g_ScorePartyMode, "Resources/8-bit-fortress.ttf", 20, textColor, g_ScorePartyModeText);
	if (g_ScoreCounterPartyMode >= g_HighScoreCounterPartyMode)
	{
		g_HighScoreCounterPartyMode = g_ScoreCounterPartyMode;
		g_HighScorePartyMode = "Highscore           " + std::to_string(g_HighScoreCounterPartyMode);
		TextureFromString(g_HighScorePartyMode, "Resources/8-bit-fortress.ttf", 20, textColor, g_HighScorePartyModeText);
	}
}
void UpdateApplePartyMode()
{
	if ((g_SnakePos.x == g_AppleCord.x) && (g_SnakePos.y == g_AppleCord.y))
	{
		g_AppleCord.x = g_Border + g_CellSize * (rand() % g_Rows);
		g_AppleCord.y = g_Border + g_CellSize * (rand() % g_Columns);
		g_SnakeLength++;
		++g_ScoreCounterPartyMode;
		g_TimePerCell = g_TimePerCellUserDef;
		UpdateScorePartyMode();
	}

	g_SnakeTail = g_SnakePos;
	for (int i{}; i < g_SnakeLength; ++i)
	{
		switch (g_SnakeArr[i])
		{
		case 1:
			g_SnakeTail.x += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x > g_Border + (g_Columns - 1) * g_CellSize)
				{
					g_SnakeTail.x = g_Border;
				}
			}
			break;
		case 2:
			g_SnakeTail.x -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x < g_Border)
				{
					g_SnakeTail.x = g_Border + (g_Columns - 1) * g_CellSize;
				}
			}
			break;
		case 3:
			g_SnakeTail.y -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y < g_Border)
				{
					g_SnakeTail.y = g_Border + (g_Rows - 1) * g_CellSize;
				}
			}
			break;
		case 4:
			g_SnakeTail.y += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y > g_Border + (g_Rows - 1) * g_CellSize)
				{
					g_SnakeTail.y = g_Border;
				}
			}
			break;
		}
		if (((g_AppleCord.x == g_SnakeTail.x) && (g_AppleCord.y == g_SnakeTail.y))
			|| ((g_AppleCord.x == g_StoneCord.x) && (g_AppleCord.y == g_StoneCord.y))
			|| ((g_AppleCord.x == g_StoneCord1.x) && (g_AppleCord.y == g_StoneCord1.y))
			|| ((g_AppleCord.x == g_StoneCord2.x) && (g_AppleCord.y == g_StoneCord2.y))
			|| ((g_AppleCord.x == g_MisteryBlockCord.x) && (g_AppleCord.y == g_MisteryBlockCord.y)))
		{
			g_AppleCord.x = g_Border + g_CellSize * (rand() % g_Rows);
			g_AppleCord.y = g_Border + g_CellSize * (rand() % g_Columns);
		}
	}
}
void CollisionCheckPartyMode()
{
	g_SnakeTail = g_SnakePos;
	for (int i{}; i < g_SnakeLength; ++i)
	{
		switch (g_SnakeArr[i])
		{
		case 1:
			g_SnakeTail.x += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x > g_Border + (g_Columns - 1) * g_CellSize)
				{
					g_SnakeTail.x = g_Border;
				}
			}
			break;
		case 2:
			g_SnakeTail.x -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x < g_Border)
				{
					g_SnakeTail.x = g_Border + (g_Columns - 1) * g_CellSize;
				}
			}
			break;
		case 3:
			g_SnakeTail.y -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y < g_Border)
				{
					g_SnakeTail.y = g_Border + (g_Rows - 1) * g_CellSize;
				}
			}
			break;
		case 4:
			g_SnakeTail.y += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y > g_Border + (g_Rows - 1) * g_CellSize)
				{
					g_SnakeTail.y = g_Border;
				}
			}
			break;
		}
		if ((g_SnakePos.x == g_SnakeTail.x) && (g_SnakePos.y == g_SnakeTail.y))
		{
			g_GameModes = g_GameState::gameOverPartyMode;
			g_TimePerCell = g_TimePerCellUserDef;
		}
	}
}
void CheckOutOfBoundsPartyMode()
{
	if (((g_SnakePos.x < g_Border) || (g_SnakePos.x >= g_Border + (g_CellSize * g_Columns))) ||
		((g_SnakePos.y < g_Border) || (g_SnakePos.y >= g_Border + (g_CellSize * g_Rows))))
	{
		g_GameModes = g_GameState::gameOverPartyMode;
		g_TimePerCell = g_TimePerCellUserDef;
	}
}
void DrawPartyGameMode()
{
	DrawBackground();
	DrawSnake();
	DrawApple();
	InformationPartyMode();
	DrawPauseButton();
	DrawPowerUps();
	SetColor(204 / 255.f, 167 / 255.f, 89 / 255.f);
	if (g_Walls)
	{
		SetColor(1, 0, 0);;
	}
	DrawRect(g_Border, g_Border, g_CellSize * g_Columns, g_CellSize * g_Rows, 3);

	if (g_IsGamePaused)
	{
		DrawPausedScreen();
	}
}
void UpdatePartyGameMode(float elapsedSec)
{
	MoveSnake(elapsedSec);
	CheckOutOfBoundsPartyMode();
	UpdateApplePartyMode();
	CollisionCheckPartyMode();
	UpdatePowerUps(elapsedSec);
}
void PressPauseButton()
{
	Rectf pauseButton{};
	pauseButton.width = pauseButton.height = 50;
	pauseButton.left = g_WindowWidth - 10 - pauseButton.width;
	pauseButton.bottom = g_WindowHeight - 10 - pauseButton.height;

	if (IsPointInRect(g_MousePos, pauseButton))
	{
		g_IsGamePaused = true;
	}

	if (g_IsGamePaused)
	{
		Rectf backToMenu{};
		backToMenu.left = g_WindowWidth / 2 - 150 - 100;
		backToMenu.bottom = g_WindowHeight / 3;
		backToMenu.width = 200;
		backToMenu.height = 70;
		if (IsPointInRect(g_MousePos, backToMenu))
		{
			g_GameModes = g_GameState::mainMenu;
			g_IsGamePaused = false;
			g_TimePerCell = g_TimePerCellUserDef;
			ResetGame();
			ResetPartyMode();
		}

		Rectf continuePlaying{};
		continuePlaying.left = g_WindowWidth / 2 + 150 - 100;
		continuePlaying.bottom = g_WindowHeight / 3;
		continuePlaying.width = 200;
		continuePlaying.height = 70;
		if (IsPointInRect(g_MousePos, continuePlaying))
		{
			g_IsGamePaused = false;
		}
	}
}
void DrawPartyModeGameOverScreen()
{
	Rectf gameOverScreen{};
	gameOverScreen.left = 0;
	gameOverScreen.bottom = 0;
	gameOverScreen.width = g_WindowWidth;
	gameOverScreen.height = g_WindowHeight;
	DrawTexture(g_GameOver, gameOverScreen);
			
	Rectf backToMenu{};
	backToMenu.left = g_WindowWidth / 2 - 150 - 100;
	backToMenu.bottom = g_WindowHeight / 4;
	backToMenu.width = 200;
	backToMenu.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(backToMenu.left + 2, backToMenu.bottom - 2, backToMenu.width, backToMenu.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, backToMenu))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(backToMenu, 3);

	DrawTexture(g_ReturnText, Point2f(backToMenu.left + backToMenu.width / 2 - g_ReturnText.width / 2, backToMenu.bottom + backToMenu.height / 2 - g_ReturnText.height / 2));

	Rectf retry{};
	retry.left = g_WindowWidth / 2 + 150 - 100;
	retry.bottom = g_WindowHeight / 4;
	retry.width = 200;
	retry.height = 70;
	SetColor(0, 0, 0, .5f);
	DrawRect(retry.left + 2, retry.bottom - 2, retry.width, retry.height, 3);
	SetColor(1, 1, 1, 1);
	if (IsPointInRect(g_MousePos, retry))
	{
		SetColor(239 / 255.f, 132 / 255.f, 63 / 255.f);
	}
	DrawRect(retry, 3);

	DrawTexture(g_RetryText, Point2f(retry.left + retry.width / 2 - g_RetryText.width / 2, retry.bottom + retry.height / 2 - g_RetryText.height / 2));

	Point2f score{};
	score.x = g_WindowWidth / 2 - 165 - g_ScorePartyModeText.width / 2;
	score.y = g_WindowHeight / 2 - 40;
	DrawTexture(g_ScorePartyModeText, score);

	Rectf apple{};
	apple.left = g_WindowWidth / 2 - 150 + g_ScorePartyModeText.width / 2 - 10;
	apple.bottom = g_WindowHeight / 2 - 42;
	apple.height = apple.width = 32.5f;
	DrawTexture(g_AppleScore, apple);

	Point2f highscore{};
	highscore.x = g_WindowWidth / 2 + 135 - g_HighScorePartyModeText.width / 2;
	highscore.y = g_WindowHeight / 2 - 40;
	DrawTexture(g_HighScorePartyModeText, highscore);

	Rectf trophy{};
	trophy.left = g_WindowWidth / 2 + 150 + g_HighScorePartyModeText.width / 2 - 10;
	trophy.bottom = g_WindowHeight / 2 - 42;
	trophy.height = trophy.width = g_CellSize;
	DrawTexture(g_Trophy, trophy);

	Rectf competitiveModeRect{};
	competitiveModeRect.left = g_WindowWidth / 2 + 60;
	competitiveModeRect.bottom = g_WindowHeight / 3 - 95;
	competitiveModeRect.width = g_CompetitiveModeText.height + g_WallsSettingTextOff.width - 10;
	competitiveModeRect.height = g_CompetitiveModeText.height + 10;
	SetColor(0, 0, 0, .5f);
	DrawRect(competitiveModeRect.left + 2, competitiveModeRect.bottom - 2, competitiveModeRect.width, competitiveModeRect.height, 3);
	SetColor(1, 1, 1, 1);
	DrawRect(competitiveModeRect, 3);

	Point2f competitiveMode{};
	competitiveMode.x = g_WindowWidth / 2 - (g_CompetitiveModeText.width / 2 + competitiveModeRect.width / 2);
	competitiveMode.y = g_WindowHeight / 3 - 90;
	DrawTexture(g_CompetitiveModeText, competitiveMode);


	if (g_CompetitiveMode)
	{
		DrawTexture(g_WallsSettingTextOn, Point2f(competitiveModeRect.left + 5, competitiveModeRect.bottom + 5));
	}
	else
	{
		DrawTexture(g_WallsSettingTextOff, Point2f(competitiveModeRect.left + 5, competitiveModeRect.bottom + 5));
	}
}
void ResetPartyMode()
{
	g_Direction = g_DirectionState::stationary;
	g_SnakePos.x = g_SnakePosCenterX;
	g_SnakePos.y = g_SnakePosCenterY;
	g_SnakeArr[0] = 3;
	g_SnakeArr[1] = 3;
	g_SnakeArr[2] = 3;
	g_SnakeLength = 2;
	g_ScoreCounterPartyMode = 0;
	g_TimePerCell = g_TimePerCellUserDef;
	UpdateScorePartyMode();
	UpdateApplePartyMode();
}
void DrawPowerUps()
{
	DrawStones();
	DrawMisteryBlock();
}
void DrawStones()
{
	Rectf stone1{};
	stone1.left = g_StoneArr[0].x;
	stone1.bottom = g_StoneArr[0].y;
	stone1.width = g_CellSize;
	stone1.height = g_CellSize;
	DrawTexture(g_Stone, stone1);

	Rectf stone2{};
	stone2.left = g_StoneArr[1].x;
	stone2.bottom = g_StoneArr[1].y;
	stone2.width = g_CellSize;
	stone2.height = g_CellSize;
	DrawTexture(g_Stone, stone2);

	Rectf stone3{};
	stone3.left = g_StoneArr[2].x;
	stone3.bottom = g_StoneArr[2].y;
	stone3.width = g_CellSize;
	stone3.height = g_CellSize;
	DrawTexture(g_Stone, stone3);
}
void UpdatePowerUps(float elapsedSec)
{
	if	(	((g_SnakePos.x == g_StoneCord.x) && (g_SnakePos.y == g_StoneCord.y))
		||	((g_SnakePos.x == g_StoneCord1.x) && (g_SnakePos.y == g_StoneCord1.y))
		||	((g_SnakePos.x == g_StoneCord2.x) && (g_SnakePos.y == g_StoneCord2.y)))
	{
		g_GameModes = g_GameState::gameOverPartyMode;
	}
	UpdateMisteryBlock(elapsedSec);
}
void DrawMisteryBlock()
{
	Rectf luckyBlock{};
	luckyBlock.left = g_MisteryBlockCord.x;
	luckyBlock.bottom = g_MisteryBlockCord.y;
	luckyBlock.width = g_CellSize;
	luckyBlock.height = g_CellSize;
	DrawTexture(g_QuestionBlock, luckyBlock);
}
void UpdateMisteryBlock(float elapsedSec)
{
	if ((g_SnakePos.x == g_MisteryBlockCord.x) && (g_SnakePos.y == g_MisteryBlockCord.y))
	{
		g_MisteryBlockCord.x = g_Border + g_CellSize * (rand() % g_Rows);
		g_MisteryBlockCord.y = g_Border + g_CellSize * (rand() % g_Columns);

		g_TimePerCell = g_TimePerCellUserDef;

		int bonus{ rand() % 4};
		switch (bonus)
		{
		case 0:
		{
			g_TimePerCell = g_TimePerCellUserDef/2.f;
			break;
		}
		case 1:
		{
			// -2 points
			g_ScoreCounterPartyMode -= 2;
			if (g_ScoreCounterPartyMode < 0)
			{
				g_ScoreCounterPartyMode = 0;
			}
			UpdateScorePartyMode();
			break;
		}
		case 2:
		{
			// +5 points
			g_ScoreCounterPartyMode += 3;
			UpdateScorePartyMode();
			break;
		}
		case 3:
		{
			g_StoneArr[0] = g_StoneCord  = Point2f(g_Border + g_CellSize * (rand() % g_Rows), g_Border + g_CellSize * (rand() % g_Columns));
			g_StoneArr[1] = g_StoneCord1 = Point2f(g_Border + g_CellSize * (rand() % g_Rows), g_Border + g_CellSize * (rand() % g_Columns));
			g_StoneArr[2] = g_StoneCord2 = Point2f(g_Border + g_CellSize * (rand() % g_Rows), g_Border + g_CellSize * (rand() % g_Columns));
			break;
		}
		}
	}

	g_SnakeTail = g_SnakePos;
	for (int i{}; i < g_SnakeLength; ++i)
	{

		switch (g_SnakeArr[i])
		{
		case 1:
			g_SnakeTail.x += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x > g_Border + (g_Columns - 1) * g_CellSize)
				{
					g_SnakeTail.x = g_Border;
				}
			}
			break;
		case 2:
			g_SnakeTail.x -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.x < g_Border)
				{
					g_SnakeTail.x = g_Border + (g_Columns - 1) * g_CellSize;
				}
			}
			break;
		case 3:
			g_SnakeTail.y -= g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y < g_Border)
				{
					g_SnakeTail.y = g_Border + (g_Rows - 1) * g_CellSize;
				}
			}
			break;
		case 4:
			g_SnakeTail.y += g_CellSize;
			if (!g_Walls)
			{
				if (g_SnakeTail.y > g_Border + (g_Rows - 1) * g_CellSize)
				{
					g_SnakeTail.y = g_Border;
				}
			}
			break;
		}	
		if(    ((g_MisteryBlockCord.x == g_SnakeTail.x) && (g_MisteryBlockCord.y == g_SnakeTail.y))
			|| ((g_MisteryBlockCord.x == g_StoneCord.x) && (g_MisteryBlockCord.y == g_StoneCord.y))
			|| ((g_MisteryBlockCord.x == g_StoneCord1.x) && (g_MisteryBlockCord.y == g_StoneCord1.y))
			|| ((g_MisteryBlockCord.x == g_StoneCord2.x) && (g_MisteryBlockCord.y == g_StoneCord2.y))
			|| ((g_MisteryBlockCord.x == g_AppleCord.x) && (g_MisteryBlockCord.y == g_AppleCord.y)))
		{
			g_MisteryBlockCord.x = g_Border + g_CellSize * (rand() % g_Rows);
			g_MisteryBlockCord.y = g_Border + g_CellSize * (rand() % g_Columns);
		}
	}
}
#pragma endregion ownDefinitions