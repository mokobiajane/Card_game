
#ifndef LEVEL_H
#define LEVEL_H

class Level {
public:
    Level(int currentLevel);
    ~Level();

    void levelUp();
    int getCurrentLevel() const;

private:
    int currentLevel;
};

#endif