//"Spelklass" main.. adding buttons, adding player, background, music, and setting different speeds
//Andreas Lundmark

#include <iostream>
#include <string>
#include "GameEngine.h"
#include "Constants.h"
#include "Sprite.h"
#include "Player.h"
#include "Button.h"
#include "VolumeUpButton.h"
#include "Label.h"
#include "VolumeButtonDown.h"
#include "VolumeBar.h"
#include "NextSongButton.h"
#include <memory>
#include "System.h"
#include "Enemy.h"

using namespace spacewing;
using namespace std;

int main(int argc, char **argv)
{

       // Creating buttons

    std::shared_ptr<VolumeButtonDown> vd = VolumeButtonDown::create(10, 670, 20, 20, (constants::gResPath + "images/minusdownbutton.png").c_str(),
                                                                    (constants::gResPath + "images/minusbutton.png").c_str());

    std::shared_ptr<VolumeUpButton> vu = VolumeUpButton::create(40, 670, 20, 20, (constants::gResPath + "images/plusdownbutton2.png").c_str(),
                                                                (constants::gResPath + "images/plusbutton2.png").c_str());

    std::shared_ptr<NextSongButton> ns = NextSongButton::create(70, 670, 20, 20, (constants::gResPath + "images/nextsong2.png").c_str(),
                                                                (constants::gResPath + "images/nextsongdown.png").c_str());

    // add custom music to the list.

    sys.add_music("sounds/cinematic-atmosphere.mp3");
    sys.add_music("sounds/space-chillout.mp3");

    // creating Player

    std::shared_ptr<Player> p = Player::create(320, 620, 30, 40, "images/spaceship1.png");

    p->setSpeed(2); // increasing movementspeed on player;
    game.setFps(80);
    game.setTickIntevall(1);
    game.setBackGroundImage("images/sky.png");
    game.setEnemyTypeOne(2500, 0, 20, 25, "images/CuteRobot2.png"); // create one type of enemy that will be generated
    game.setEnemySpeed(2);                                         // slow down speed of enemies by increasing int.
    game.setEnemyIntervall(2000);                                  // how long intervall between enemies
    game.slowShotSpeed(1);                                         // slow down speed of shot/bullet by increasing int.
    game.add(vd);                                                  // add volumedown button
    game.add(vu);                                                  // adding volumeup button
    game.add(ns);                                                  // adding next song button
    game.add(p);                                                   // adding player
    game.run();

    return 0;
}