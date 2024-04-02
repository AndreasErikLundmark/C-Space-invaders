# ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Sprite.h"
#include <vector>
#include <string>


namespace spacewing{

class GameEngine{

public: 
    // static GameEngine& getInstance();
    void add(std::shared_ptr<Sprite> s);
   
    void remove(std::shared_ptr<Sprite> s);
    void removeSprites();

    void setFps(int x);
    void setTickIntevall(int x);
    void enemyGenerator(int n);
    void setEnemyXpos(int);
    std::shared_ptr<Sprite> collisionDetect(const std::shared_ptr<Sprite>& s);
    bool rectCompare(const std::shared_ptr<Sprite>& s1, const std::shared_ptr<Sprite>& s2);
    void shotCreator(int x, int y, int w, int h, const std::string& s);
    void setBackGroundImage(const std::string& s);
    void gameOver(int x, int y, int w, int h, std::string txt, unsigned char r, unsigned char g, unsigned char b);
    void setEnemyTypeOne(int x, int y, int w, int h, std::string s);
    void setEnemyIntervall(int n);
    void setEnemySpeed(int n);
    void slowShotSpeed(int n);
    int getSlowShotSpeed()const;

    // void button(int x, int y, int w, int h, const std::string& upButtonUrl, const std::string& pressButtonUrl);
    void run();

    GameEngine();
    ~GameEngine();

protected:            
   

private:
    GameEngine(const GameEngine& other) = delete;
    GameEngine& operator=(const GameEngine& other) = delete;

    std::vector<std::shared_ptr<Sprite>> sprites;
    std::vector<std::shared_ptr<Sprite>> added, removed;   
    // int fps = 60; 
    // Uint32 tickInterval = 1000 / fps;
    int fps = 60; 
    Uint32 tickInterval = 1;
    Uint32 tickCounter = 0;
    int enemyXpos = 100;
    int enemyYpos = 0;
    int enemyWidth = 50;
    int enemyHeigt = 40;
    int enemySpeed = 1;
    int enemyIntervall = 5000;
    std::string enemyUrl= "images/Pixel-art-cute-robot-colorful-vector-Graphics-62976844-1-580x387.jpg";
    int shotSlowSpeed = 1;

  

};

extern GameEngine game;

}


#endif