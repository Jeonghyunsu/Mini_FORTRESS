#include "Headers.h"

int main()
{
	RenderWindow window(VideoMode(800, 600), "SFML Fortress");
	window.setFramerateLimit(60); // 프레임 제한(얼마나 화면을 빨리 갱신하는지) 조정
	Game game;

	while (window.isOpen())
	{
		#pragma region 사용자 이벤트 처리

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed) {
				if (game.GetIsShotting() == false) {
					if (Keyboard::isKeyPressed(Keyboard::Space)) {
						game.PressSpace();
					}
				}
			}
		}
		if (game.GetIsShotting() == false) {
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				game.GetCurPlayer()->MoveTank(1);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Left)) {
				game.GetCurPlayer()->MoveTank(-1);				
			}
			else if (Keyboard::isKeyPressed(Keyboard::Q)) {
				game.GetCurPlayer()->GetTank()->SetSelectMissile(1);
			}
			else if (Keyboard::isKeyPressed(Keyboard::W)) {
				game.GetCurPlayer()->GetTank()->SetSelectMissile(2);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Up)) {
				game.GetCurPlayer()->SetAngle(1);
			}
			else if (Keyboard::isKeyPressed(Keyboard::Down)) {
				game.GetCurPlayer()->SetAngle(-1);
			}
			game.ChangeAngle();
		}

		#pragma endregion

		#pragma region 게임 구동

		if (game.GetIsPressingSpace() == true) {
			game.UpPowerGauge(0.5);
		}
		
		if (game.GetIsShotting() == true) {
			game.MissileFlying();
		}

		if (game.GetisBombFlag() == true) {

			game.SetBombFlag(false);
			Drawing(window, game, true);

			sf::sleep(sf::milliseconds(1500));

			game.ChangWind();
			game.GetStatus()->Update(*game.GetCurPlayer());
			game.EraseBombImg();
		}

		if (game.GetisPlayingGame() == false){
			Drawing(window, game, false);
			while (1) {};
		}

		#pragma endregion
		Drawing(window, game, false);	
	}
	return 0;
}

void Drawing(RenderWindow& window, Game& game, bool bomb_stop_flag)
{
	window.clear();
	DrawObjects(window, game, bomb_stop_flag);
	window.display();
}

void DrawObjects(RenderWindow& window, Game& game, bool bomb_stop_flag)
{
	window.draw(game.GetMap()->GetSpMap());

	window.draw(game.GetStatus()->GetSpStatus());
	window.draw(game.GetStatus()->GetSpHPGauge());
	window.draw(game.GetStatus()->GetSpPowerGauge());

	window.draw(game.GetPlayer1()->GetSpTank());
	window.draw(game.GetPlayer2()->GetSpTank());

	window.draw(game.GetStatus()->GetSpMissile1());
	window.draw(game.GetStatus()->GetSpMissile2());
	window.draw(game.GetStatus()->GetSpBomb());
	window.draw(game.GetStatus()->GetSpWind());
	window.draw(game.GetStatus()->GetSpLine(), 2, sf::Lines);
	window.draw(game.GetStatus()->GetSpFinal());
	
	if (bomb_stop_flag){
		if(game.GetCurPlayer()->GetPlayerNum() == PLAYER1) window.draw(game.GetStatus()->GetDir(game.GetPlayer2()));
		else window.draw(game.GetStatus()->GetDir(game.GetPlayer1()));
	}
	else
		window.draw(game.GetStatus()->GetDir(game.GetCurPlayer()));

	if (game.GetIsShotting() == true) {
		window.draw(game.GetCurPlayer()->GetTank()->GetMissile()->GetSpMissile());
	}
}

