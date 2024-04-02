#include "GameEngine.h"
#include <vector>
#include "System.h"
#include "Label.h"
#include "Shot.h"
#include <memory>
#include <iterator>
#include "Button.h"

#define FPS fps

#include "Enemy.h"

namespace spacewing
{

    using namespace std;

    GameEngine::GameEngine() //: tickInterval(1 / fps)
    {
    }

    // add sprite
    void GameEngine::add(std::shared_ptr<Sprite> s)
    {

        added.push_back(s);
    }

    // remove sprite
    void GameEngine::remove(std::shared_ptr<Sprite> s)
    {
        if (s != nullptr)
        {
            removed.push_back(s); // adding to with sprites that are going to be removed
        }
    }

    void GameEngine::removeSprites()
    {

        for (const auto &s : removed)
        {
            sprites.erase(std::remove(sprites.begin(), sprites.end(), s), sprites.end());
        }
        removed.clear();
    }

    // set custom fps eventloop speed
    void GameEngine::setFps(int x)
    {
        fps = x;
    }
    // set custom tick intervall.
    void GameEngine::setTickIntevall(int x)
    {
        tickInterval = x / FPS;
    }

    void GameEngine::enemyGenerator(int n)
    {

        Uint32 currentTime = SDL_GetTicks();

        if (currentTime - tickCounter >= enemyIntervall)
        {
            std::shared_ptr<Enemy> e = Enemy::create(enemyXpos, enemyYpos, enemyWidth, enemyHeigt, enemyUrl);

            if (e == nullptr)
            {
                throw std::invalid_argument("No setEnemyType created");
            }

            tickCounter = currentTime;
            e->setSlowerSpeed(n);
            game.add(e);
            setEnemyXpos(1000);
        }
    }

    void GameEngine::setEnemyTypeOne(int x, int y, int w, int h, std::string s)
    {

        enemyXpos = x;
        enemyYpos = y;
        enemyWidth = w;
        enemyHeigt = h;
        enemyUrl = s;
    }

    void GameEngine::setEnemySpeed(int n)
    {
        enemySpeed = n;
    }

    void GameEngine::setEnemyIntervall(int n)
    {
        enemyIntervall = n;
    }

    void GameEngine::setEnemyXpos(int x)
    {

        enemyXpos = (enemyXpos + x) % 660;
    }

    std::shared_ptr<Sprite> GameEngine::collisionDetect(const std::shared_ptr<Sprite> &s)
    {

        for (auto it = sprites.begin(); it != sprites.end(); ++it)
        {
            std::shared_ptr<Sprite> s2 = *it;
            if (s2 != s && rectCompare(s2, s))

            {
                if (std::shared_ptr<Label> lbl = std::dynamic_pointer_cast<Label>(s2))
                {
                    // do nothing
                }
                else
                {

                    remove(s2);
                    remove(s);
                    return s2; // return s2 to be examined by Enemy
                }
            }
        }
        return nullptr;
    }
    bool GameEngine::rectCompare(const std::shared_ptr<Sprite> &s1, const std::shared_ptr<Sprite> &s2)
    {

        int s1X, s1Y, s1W, s1H;
        int s2X, s2Y, s2W, s2H;

        s1X = s1->getRect().x;
        s1Y = s1->getRect().y;
        s1W = s1->getRect().w;
        s1H = s1->getRect().h;

        s2X = s2->getRect().x;
        s2Y = s2->getRect().y;
        s2W = s2->getRect().w;
        s2H = s2->getRect().h;

        if ((s1X < s2X + s2W) && (s1X + s1W > s2X) &&
            (s1Y < s2Y + s2H) && (s1Y + s1H > s2Y))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void GameEngine::shotCreator(int x, int y, int w, int h, const std::string &s)
    {
        std::shared_ptr<Shot> shot = Shot::create(x, y, w, h, s);
        game.add(shot);
    }

    void GameEngine::setBackGroundImage(const std::string &s)
    {
        sys.setBackGround(s);
    }

    void GameEngine::gameOver(int x, int y, int w, int h, std::string txt, unsigned char r, unsigned char g, unsigned char b)
    {

        std::shared_ptr<Label> end = Label::create(x, y, w, h, txt, r, g, b);
        game.add(end);
    }

    void GameEngine::slowShotSpeed(int n)
    {
        shotSlowSpeed = n;
    }

    int GameEngine::getSlowShotSpeed() const
    {
        return shotSlowSpeed;
    }

    // eventloop
    void GameEngine::run()
    {

        bool exit = false;

        while (!exit)
        {

            Uint32 nextTick = SDL_GetTicks() + tickInterval;

            SDL_Event event;

            while (SDL_PollEvent(&event))
            {

                switch (event.type)
                {

                case SDL_QUIT:
                    exit = true;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    for (std::shared_ptr<Sprite> s : sprites)
                    { // kolla igenom alla sprites och skicka med eventlysnnaren.
                        s->mouseDown(event);
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    for (std::shared_ptr<Sprite> s : sprites)
                    { // kolla igenom alla sprites och skicka med eventlysnnaren.
                        s->mouseUp(event);
                    }
                    break;

                case SDL_KEYDOWN:
                    for (std::shared_ptr<Sprite> s : sprites)
                    {
                        s->keyDown(event);
                    }
                    break;
                case SDL_KEYUP:
                    for (std::shared_ptr<Sprite> s : sprites)
                    {
                        s->keyUp(event);
                    }
                    break;

                } // switch

            } // inner while

            GameEngine::enemyGenerator(enemySpeed);

            for (std::shared_ptr<Sprite> s : sprites)
            {
                s->tick();
            }

            // moves added to sprites and clears added
            for (std::shared_ptr<Sprite> s : added)
            {
                sprites.push_back(s);
            }
            added.clear();
            // tar bort alla sprites som finns i removed.
            for (shared_ptr<Sprite> s : removed)
                for (std::vector<shared_ptr<Sprite>>::iterator i = sprites.begin(); i != sprites.end();)
                {
                    if (*i == s)
                    {
                        i = sprites.erase(i);
                    }
                    else
                    {
                        i++;
                    }
                }

            removed.clear();

            SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
            SDL_RenderClear(sys.get_ren());
            SDL_RenderCopy(sys.get_ren(), sys.get_texture(), NULL, NULL); // background

            for (std::shared_ptr<Sprite> s : sprites)
            {
                s->draw();
            }

            SDL_RenderPresent(sys.get_ren());

            int delay = nextTick - SDL_GetTicks();
            if (delay > 0)
            {
                SDL_Delay(delay);
            }

        } // run
    }
    GameEngine::~GameEngine()
    {

        sprites.clear();
    }

    GameEngine game;
}
