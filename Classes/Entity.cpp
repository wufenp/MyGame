#include "Entity.h"
#include "Player.h"

USING_NS_CC;

Entity::Entity()
{
    m_sprite = NULL;
}

Sprite* Entity::getSprite()
{
    return this->m_sprite;
}

void Entity::bindSprite(Sprite *sprite)
{
    this->m_sprite = sprite;
    this->addChild(m_sprite);
}
