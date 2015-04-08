#ifndef IGAME_H
#define IGAME_H

class iGame
{
private:
protected:

public:

    virtual void init() = 0;

    virtual void update(double delta) = 0;

	virtual void pause() = 0;

    virtual void draw(double delta) = 0;

	virtual void dispose() = 0;

};
#endif
