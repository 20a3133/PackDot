#include "DxLib.h"
int player[8], player2[8], chip[7], enemy[2], enemy1, enemy2;	//01, 04, 09, 10
int px = 1, py = 1;	//ÉvÉåÉCÉÑÅ[ÇÃà íu
int ex = 13, ey = 18;	//ìGÇÃà íu	04
int ex1 = 1, ey1 = 18;	//ìGÇÃà íu	2-09
int ex2 = 18, ey2 = 1;	//ìGÇÃà íu	2-09
int status = -1;		//ÉQÅ[ÉÄÇÃèÛë‘Å@Å|ÇPÅFÉXÉ^Å[ÉgÅCÇOÅFÉvÉåÉCÅCÇPÅFÇfÇÅÇçÇÖÇnÇñÇÖÇíÅCÇQÅFÇfÇÅÇçÇÖÇbÇåÇÖÇÅÇí
int map[15][20];
int map1[15][20] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,2,2,3,2,2,5,1,5,2,2,3,2,0,0,0,1},
	{1,0,0,0,2,2,2,3,2,5,1,5,2,3,2,2,0,0,0,1},
	{1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1},
	{1,4,2,1,0,0,0,0,0,0,1,0,0,0,0,0,1,6,4,1},
	{1,2,2,1,0,0,1,1,0,0,0,0,1,1,0,0,1,2,2,1},
	{1,2,2,0,2,2,2,1,2,3,5,2,1,2,2,2,0,2,2,1},
	{1,3,2,0,2,3,2,1,3,1,1,3,1,2,3,2,0,2,3,1},
	{1,2,2,0,2,2,2,1,2,5,3,2,1,2,2,2,0,2,2,1},
	{1,2,2,1,0,0,1,1,0,0,0,0,1,1,0,0,1,2,2,1},
	{1,4,6,1,0,0,0,0,0,1,0,0,0,0,0,0,1,2,4,1},
	{1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1},
	{1,0,0,0,2,2,3,2,5,1,5,2,3,2,2,2,0,0,0,1},
	{1,0,0,0,2,3,2,2,5,1,5,2,2,3,2,2,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
int map2[15][20] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,4,1,0,0,2,2,5,2,2,5,1,5,2,5,1,4,3,1},
	{1,4,2,1,0,1,4,2,1,2,2,2,1,2,2,2,1,2,4,1},
	{1,2,3,1,0,1,1,1,1,0,0,1,1,1,0,0,1,2,2,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,2,2,1,1,6,0,1,1,0,0,1,1,0,6,1,1,2,2,1},
	{1,2,2,1,3,2,2,2,1,0,0,1,2,2,2,3,1,2,2,1},
	{1,3,2,0,2,5,5,2,0,0,0,0,2,5,5,2,0,2,3,1},
	{1,2,2,1,2,2,2,3,1,0,0,1,3,2,2,2,1,2,2,1},
	{1,2,2,1,1,0,6,1,1,0,0,1,1,6,0,1,1,2,2,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,2,2,1,0,0,1,1,1,0,0,1,1,1,1,0,1,2,2,1},
	{1,4,2,1,2,2,2,1,2,2,2,1,2,4,1,0,1,2,4,1},
	{1,3,4,1,2,2,2,1,5,2,2,5,2,2,0,0,1,4,3,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
int map3[15][20] = {
	{1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1},
	{1,0,5,5,5,2,2,4,3,2,2,2,2,2,2,5,5,5,5,1},
	{1,5,1,1,2,3,2,2,2,2,2,3,4,2,3,2,1,1,5,1},
	{1,5,1,2,2,2,2,1,0,0,0,0,1,2,2,2,2,1,5,1},
	{1,5,1,2,0,1,1,1,0,0,0,0,1,1,1,0,2,1,5,1},
	{1,5,1,2,0,1,4,2,2,2,2,2,2,2,1,0,2,1,5,1},
	{0,2,2,2,0,1,2,2,1,1,3,2,2,2,1,0,2,2,2,0},
	{0,6,3,2,0,6,2,2,2,4,4,2,2,6,1,0,2,3,6,0},
	{0,2,2,2,0,1,2,2,2,3,1,1,0,2,1,0,2,2,2,0},
	{1,5,1,2,0,1,2,2,2,2,2,2,2,4,1,0,2,1,5,1},
	{1,5,1,2,0,1,1,1,0,0,0,0,1,1,1,0,2,1,5,1},
	{1,5,1,2,2,2,2,1,0,0,0,0,1,2,2,2,2,1,5,1},
	{1,5,1,1,2,3,2,2,3,2,2,2,4,2,3,2,1,1,5,1},
	{1,5,5,5,5,2,2,4,2,2,2,3,2,2,2,5,5,5,5,1},
	{1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1},
};
int map4[15][20] = {
	{1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,5,2,5,2,2,2,3,2,5,2,5,2,0,0,0,1},
	{1,2,2,4,2,5,2,5,2,5,2,5,2,5,2,5,4,2,2,1},
	{1,4,2,1,2,1,1,1,6,3,2,2,1,1,1,2,1,2,4,1},
	{1,6,1,1,2,2,2,1,1,1,1,1,1,2,2,2,1,1,6,1},
	{1,2,2,1,2,3,2,1,3,5,5,3,1,2,3,2,1,2,2,1},
	{1,2,2,1,1,1,4,1,5,5,5,5,1,4,1,1,1,2,2,1},
	{0,0,0,0,0,4,6,4,5,1,1,5,4,6,4,0,0,0,0,0},
	{1,2,2,1,1,1,4,1,5,5,5,5,1,4,1,1,1,2,2,1},
	{1,2,2,1,2,3,2,1,3,5,5,3,1,2,3,2,1,2,2,1},
	{1,6,2,1,2,2,2,1,1,1,1,1,1,2,2,2,1,2,6,1},
	{1,4,1,1,2,1,1,1,2,3,2,6,1,1,1,2,1,1,4,1},
	{1,2,2,4,5,2,5,2,5,2,5,2,5,2,5,2,4,2,2,1},
	{1,0,0,0,2,5,2,5,2,2,3,2,2,5,2,5,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
};
int score = 0;	//02
int esa_num_yellow = 0, esa_num_red = 0/*, esa_num_green = 0*/;	//07
int p_dir = 0, p_bite = 0;		//09ÅFPlayerÇÃå¸Ç´, 10:PlayerÇÃå˚
int enemy_color = 0;
int eat_sound, eat_sound2, eat_sound3, eat_sound4, tairu_sound, tekieat_sound;	//12
int timer = 0;				//ñ≥ìGâaÇêHÇ◊ÇΩéûÇÃÉ^ÉCÉ}Å[
int play_flag = 0;			//ÉQÅ[ÉÄÉvÉåÉCíÜÇÃÉtÉâÉOÅiñ≥ìGèÛë‘ÇÃéûÇ∆í èÌéûÇÃîªíËÇ»Ç«Åj
int sousa_flag = 0;         //ëÄçÏïœçXâa
int player_flag = 0;        //ÉXÉLÉìïœçX

void sound_get(void) {	//12
	eat_sound = LoadSoundMem("./music/eat.mp3"); //ïÅí âa
	eat_sound2 = LoadSoundMem("./music/powerup.mp3"); //ñ≥ìGâa
	eat_sound3 = LoadSoundMem("./music/sousa.mp3"); //ëÄçÏîΩì]âa
	eat_sound4 = LoadSoundMem("./music/genten.mp3"); //å∏ì_âa
	tairu_sound = LoadSoundMem("./music/tekiidou.mp3"); //ìGã≠êßà⁄ìÆ
	tekieat_sound = LoadSoundMem("./music/tekieat.mp3"); //ìGêHÇ◊ÇÈ
}

void esa_count(void) {	//07
	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 20; x++) {
			if (map[y][x] == 2) esa_num_yellow++;
			if (map[y][x] == 3) esa_num_red++;
		}
	}
}

void Gazo(void) {	//âÊëúéÊÇËçûÇ›ä÷êî
	//player = LoadGraph("./images/player1.png");					//09
	//LoadDivGraph("./images/player2.png", 4, 4, 1, 32, 32, player);	//09
	LoadDivGraph("./images/player3.png", 8, 4, 2, 32, 32, player);	//10
	LoadDivGraph("./images/player3'.png", 8, 4, 2, 32, 32, player2);	//10
	LoadDivGraph("./images/chip3.jpg", 7, 7, 1, 32, 32, chip);	//01
	enemy1 = LoadGraph("./images/enemy.png");		//04
	enemy2 = LoadGraph("./images/enemy3.png");
	LoadDivGraph("./images/enemy2.png", 2, 2, 1, 32, 32, enemy);	//01
}

void Hyoji(void) {	//ï\é¶ä÷êî
	for (int y = 0; y < 15; y++) {	//01
		for (int x = 0; x < 20; x++) {
			DrawGraph(x * 32, y * 32, chip[map[y][x]], FALSE);
		}
	}
	//DrawGraph(px * 32, py * 32, player[p_dir], FALSE);			//09
	if(player_flag == 0) DrawGraph(px * 32, py * 32, player[p_dir + p_bite * 4], FALSE);			//10
	else DrawGraph(px * 32, py * 32, player2[p_dir + p_bite * 4], FALSE);
	DrawGraph(ex * 32, ey * 32, enemy[enemy_color = 1 - enemy_color], FALSE);		//04
	DrawGraph(ex1 * 32, ey1 * 32, enemy1, FALSE);		//04
	DrawGraph(ex2 * 32, ey2 * 32, enemy2, FALSE);		//04
	DrawFormatString(0, 0, GetColor(255, 255, 255), "SCORE : %d", score);	//02
	DrawFormatString(500, 0, GetColor(255, 255, 255), "TIMER : %d", timer);	//02
	WaitTimer(80);
}

void Player(void) {	//ÉvÉåÉCÉÑÅ[ÇÃìÆÇ´ä÷êî
	int tmpx = px, tmpy = py;	//03
	if (sousa_flag == 0) {
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			px--;
			//if (px < 0) px = 19;
			p_dir = 2;
		}		//2-06
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			px++;
			//if (px > 19) px = 0;
			p_dir = 0;
		}		//2-06
		if (CheckHitKey(KEY_INPUT_UP)) { py--; p_dir = 3; }			//09
		if (CheckHitKey(KEY_INPUT_DOWN)) { py++; p_dir = 1; }		//09
		if (map[py][px] == 1) {	//03
			px = tmpx;
			py = tmpy;
		}

		if (px <= 0 && CheckHitKey(KEY_INPUT_LEFT)) {
			px = 19;
		}
		if (px >= 19 && CheckHitKey(KEY_INPUT_RIGHT)) {
			px = 0;
		}
		if (py <= 0 && CheckHitKey(KEY_INPUT_UP)) {
			py = 14;
		}
		if (py >= 14 && CheckHitKey(KEY_INPUT_DOWN)) {
			py = 0;
		}
	}
	
	if (sousa_flag == 1) {
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			px++;
			if (px < 0) px = 19;
			p_dir = 0;
		}		//2-06
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			px--;
			if (px > 19) px = 0;
			p_dir = 2;
		}		//2-06
		if (CheckHitKey(KEY_INPUT_UP)) { py++; p_dir = 1; }			//09
		if (CheckHitKey(KEY_INPUT_DOWN)) { py--; p_dir = 3; }		//09
		if (map[py][px] == 1) {	//03
			px = tmpx;
			py = tmpy;
		}

		if (px <= 0 && CheckHitKey(KEY_INPUT_RIGHT)) {
			px = 19;
		}
		if (px >= 19 && CheckHitKey(KEY_INPUT_LEFT)) {
			px = 0;
		}
		if (py <= 0 && CheckHitKey(KEY_INPUT_DOWN)) {
			py = 14;
		}
		if (py >= 14 && CheckHitKey(KEY_INPUT_UP)) {
			py = 0;
		}
	}
	p_bite = 1 - p_bite;		//10

	
}

void atari(void) {	//02
	if (map[py][px] == 2) { //ïÅí âa
		map[py][px] = 0;
		score += 20;
		PlaySoundMem(eat_sound, DX_PLAYTYPE_BACK, TRUE);	//12
		esa_num_yellow--;						//07
		if (esa_num_yellow <= 0 && esa_num_red <= 0) status = 2;	//07
	}
	if (map[py][px] == 3) { //ñ≥ìGâaÅAìGêHÇ◊ÇÈ
		map[py][px] = 0;
		play_flag = 1;
		player_flag = 1;
		score += 100;
		PlaySoundMem(eat_sound2, DX_PLAYTYPE_BACK, TRUE);	//12
		esa_num_red--;						//07
		if (esa_num_yellow <= 0 && esa_num_red <= 0) status = 2;	//07
	}
	if (map[py][px] == 4) { //ëÄçÏîΩì]
		map[py][px] = 0;
		score += 10;
		PlaySoundMem(eat_sound3, DX_PLAYTYPE_BACK, TRUE);
		sousa_flag += 1;
		if (sousa_flag == 2) sousa_flag = 0;
		if (esa_num_yellow <= 0 && esa_num_red <= 0) status = 2;	//07
	}
	if (map[py][px] == 5) { //å∏ì_âa
		map[py][px] = 0;
		score -= 50;
		PlaySoundMem(eat_sound4, DX_PLAYTYPE_BACK, TRUE);
		if (esa_num_yellow <= 0 && esa_num_red <= 0) status = 2;	//07
	}
	if (map[py][px] == 6) { //ìGã≠êßà⁄ìÆ
		PlaySoundMem(tairu_sound, DX_PLAYTYPE_BACK, TRUE);
		ex = 18; ey = 13;	
		ex1 = 1; ey1 = 13;	
		ex2 = 18; ey2 = 1;
		if (esa_num_yellow <= 0 && esa_num_red <= 0) status = 2;	//07
	}
	if (ex == px && ey == py && play_flag == 0) status = 1;	//08, 2-09
	if (ex1 == px && ey1 == py && play_flag == 0) status = 1;	//08, 2-09
	if (ex2 == px && ey2 == py && play_flag == 0) status = 1;

	if (play_flag == 1) {
		if (ex == px && ey == py) {
			PlaySoundMem(tekieat_sound, DX_PLAYTYPE_BACK, TRUE);
			score += 200;
			map[ey][ex] = 0;
			ex = 18; ey = 13;
		}
		if (ex1 == px && ey1 == py) {
			PlaySoundMem(tekieat_sound, DX_PLAYTYPE_BACK, TRUE);
			score += 200;
			map[ey1][ex1] = 0;
			ex1 = 1; ey1 = 13;
		}
		if (ex2 == px && ey2 == py) {
			PlaySoundMem(tekieat_sound, DX_PLAYTYPE_BACK, TRUE);
			score += 200;
			map[ey2][ex2] = 0;
			ex2 = 18; ey2 = 1;
		}
	}
}

void teki(void) {	//05
	int tmpx = ex, tmpy = ey;
	if (GetRand(10) == 0) {
		if (ex > px) ex--;
		if (ex < px) ex++;
		if (ey > py) ey--;
		if (ey < py) ey++;
	}
	else {
		ex += GetRand(2) - 1;
		ey += GetRand(2) - 1;
	}

	if (ex < 0) ex = 19;
	if (ex > 19) ex = 0;

	if (map[ey][ex] == 1) {
		ex = tmpx;
		ey = tmpy;
	}

	if (ex < 0) {
		ex = 19;
	}
	if (ex > 19) {
		ex = 0;
	}
	if (ey < 0) {
		ey = 15;
	}
	if (ey > 15) {
		ey = 0;
	}
}
void teki1(void) {	//2-09
	int tmpx = ex1, tmpy = ey1;
	if (GetRand(10) == 0) {
		if (ex1 > px) ex1--;
		if (ex1 < px) ex1++;
		if (ey1 > py) ey1--;
		if (ey1 < py) ey1++;
	}
	else {
		ex1 += GetRand(2) - 1;
		ey1 += GetRand(2) - 1;
	}

	if (ex1 < 0) ex1 = 19;
	if (ex1 > 19) ex1 = 0;

	if (map[ey1][ex1] == 1) {
		ex1 = tmpx;
		ey1 = tmpy;
	}

	if (ex1 < 0) {
		ex1 = 19;
	}
	if (ex1 > 19) {
		ex1 = 0;
	}
	if (ey1 < 0) {
		ey1 = 15;
	}
	if (ey1 > 15) {
		ey1 = 0;
	}
}

void teki2(void) {	//2-09
	int tmpx = ex2, tmpy = ey2;
	if (GetRand(10) == 0) {
		if (ex2 > px) ex2--;
		if (ex2 < px) ex2++;
		if (ey2 > py) ey2--;
		if (ey2 < py) ey2++;
	}
	else {
		ex2 += GetRand(2) - 1;
		ey2 += GetRand(2) - 1;
	}

	if (ex2 < 0) ex2 = 19;
	if (ex2 > 19) ex2 = 0;

	if (map[ey2][ex2] == 1) {
		ex2 = tmpx;
		ey2 = tmpy;
	}

	if (ex2 < 0) {
		ex2 = 19;
	}
	if (ex2 > 19) {
		ex2 = 0;
	}
	if (ey2 < 0) {
		ey2 = 15;
	}
	if (ey2 > 15) {
		ey2 = 0;
	}
}
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	Gazo();
	sound_get();	//12
	
	while (status != -100) {
		while (status == -1 && ProcessMessage() == 0 && ScreenFlip() == 0 && ClearDrawScreen() == 0) {
			DrawString(280, 230, "CRAZY PACMAN", GetColor(0, 255, 255));
			DrawString(230, 260, "Put a key 1 to 4 to Serect map", GetColor(255, 255, 255));
			DrawString(250, 290, "map1 map2 map3 map4", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_1) || CheckHitKey(KEY_INPUT_2) || CheckHitKey(KEY_INPUT_3) || CheckHitKey(KEY_INPUT_4)) status = 0;
			if (CheckHitKey(KEY_INPUT_1)) {
				for (int y = 0; y < 15; y++) {
					for (int x = 0; x < 20; x++) {
						map[y][x] = map1[y][x];
					}
				}
			}
			if (CheckHitKey(KEY_INPUT_2)) {
				for (int y = 0; y < 15; y++) {
					for (int x = 0; x < 20; x++) {
						map[y][x] = map2[y][x];
					}
				}
			}
			if (CheckHitKey(KEY_INPUT_3)) {
				for (int y = 0; y < 15; y++) {
					for (int x = 0; x < 20; x++) {
						map[y][x] = map3[y][x];
					}
				}
			}
			if (CheckHitKey(KEY_INPUT_4)) {
				for (int y = 0; y < 15; y++) {
					for (int x = 0; x < 20; x++) {
						map[y][x] = map4[y][x];
					}
				}
			}
			esa_count();
			px = 1;  py = 1;	//ÉvÉåÉCÉÑÅ[ÇÃà íu
			ex = 18; ey = 13;	//ìGÇÃà íu	04
			ex1 = 1; ey1 = 13;	//ìGÇÃà íu	04
			ex2 = 18; ey2 = 1;
			sousa_flag = 0;
			PlaySoundFile("./music/bgm.mp3", DX_PLAYTYPE_LOOP);	//11
		}

		while (status == 0 && ProcessMessage() == 0 && ScreenFlip() == 0 && ClearDrawScreen() == 0) {
			if (play_flag == 0) {
				Player();
				teki();		//05
				teki1();		//05
				teki2();
				atari();	//02
				Hyoji();
			}
			else if (play_flag == 1) {
				Player();
				teki();		//05
				teki1();		//05
				teki2();
				atari();	//02
				Hyoji();
				timer++;
				if (timer >= 200) {
					timer = 0;
					play_flag = 0;
					player_flag = 0;
				}
			}
		}
		StopSoundFile();

		if (status == 1) PlaySoundFile("./music/gameover.mp3", DX_PLAYTYPE_LOOP);
		if (status == 2) PlaySoundFile("./music/gameclear.mp3", DX_PLAYTYPE_LOOP);

		while (status == 1 && ProcessMessage() == 0 && ScreenFlip() == 0 && ClearDrawScreen() == 0) {
			DrawString(280, 230, "GAME OVER", GetColor(255, 0, 0));
			DrawFormatString(0, 0, GetColor(255, 255, 255), "SCORE : %d", score);
			DrawString(265, 250, "HIT ENTER KEY TO RESTART", GetColor(255, 255, 255));
			DrawString(265, 270, "HIT ESC KEY TO END", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_RETURN)) {
				status = -1;
				StopSoundFile();
				PlaySoundFile("./music/bgm.mp3", DX_PLAYTYPE_LOOP);
				play_flag = 0;
			}
			if (CheckHitKey(KEY_INPUT_ESCAPE)) status = -100;
		}
		while (status == 2 && ProcessMessage() == 0 && ScreenFlip() == 0 && ClearDrawScreen() == 0) {
			DrawString(280, 230, "GAME CLEAR", GetColor(255, 255, 255));
			DrawFormatString(0, 0, GetColor(255, 255, 255), "SCORE : %d", score);
			DrawString(265, 250, "HIT ENTER KEY TO RESTART", GetColor(255, 255, 255));
			DrawString(265, 270, "HIT ESC KEY TO END", GetColor(255, 255, 255));
			if (CheckHitKey(KEY_INPUT_RETURN)) {
				status = -1;
				StopSoundFile();
				PlaySoundFile("./music/bgm.mp3", DX_PLAYTYPE_LOOP);
				play_flag = 0;
			}
			if (CheckHitKey(KEY_INPUT_ESCAPE)) status = -100;
		}
		//	StopSoundFile();
	}
	DxLib_End();
	return 0;
}
