#ifndef PLAYER_H
#define PLAYER_H

#include "tank.h"
#include <vector>
#include <SDL2/SDL_mixer.h>

class Player : public Tank
{
public:
    Player(double x, double y, SpriteType type, std::vector<KeyCode> control_keys);

    void handleKeyboardEvent(const KeyboardEvent &ev);
    void update(Uint32 dt) override;
    virtual ~Player();

    void respawn() override;
    void hit();
    void moveToNextLevel();

    /**
     * @return pointer to a new bullet, or nullptr if for some reason bullet cannot be created
     */
    Bullet *fire() override;
    void changeStarCountBy(int c);
    void addScore(unsigned points);
    unsigned score() const;

    void addLife();
    unsigned lives() const;
    Mix_Chunk *m_tankProjectile = NULL;

private:
    void resetKeyStates();
    void moveToCreatingState();
    unsigned m_score;
    int star_count;
    Uint32 m_fire_time;

    struct KeyState
    {
        KeyCode key;
        bool pressed;
    };

    KeyState m_key_state_up;
    KeyState m_key_state_down;
    KeyState m_key_state_left;
    KeyState m_key_state_right;
    KeyState m_key_state_fire;
};

#endif // PLAYER_H
