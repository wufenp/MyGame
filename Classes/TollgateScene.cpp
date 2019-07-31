#include "TollgateScene.h"
#include "Player.h"

USING_NS_CC;

cocos2d::Size mapSize;
Scene* TollgateScene::createScene()
{
    return TollgateScene::create();
}

bool TollgateScene::init()
{
    if(!Scene::init())
        return false;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    m_player = Player::create();
    m_player->bindSprite(Sprite::create("res/run0.png"));
    m_player->setPosition(Vec2(200, 128));
    this->addChild(m_player, 3);
    mapSize = m_bgSprite1->getContentSize();
    initBG();
    this->scheduleUpdate();


    return true;

}

void TollgateScene::initBG()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    m_bgSprite1 = Sprite::create("res/backgroud.png");
    m_bgSprite1->setPosition(Vec2(mapSize.width / 2, 0));
//    m_bgSprite1->setAnchorPoint(Vec2(0, 0));
    this->addChild(m_bgSprite1, 0);

    m_bgSprite2 = Sprite::create("res/backgroud.png");
    m_bgSprite2->setPosition(Vec2((mapSize.width / 2) + mapSize.width, 0));
//    m_bgSprite2->setAnchorPoint(Vec2(0, 0));
    this->addChild(m_bgSprite2, 0);
}

void TollgateScene::update(float dalta)
{
    int posX1 = m_bgSprite1->getPositionX();
    int posX2 = m_bgSprite2->getPositionX();

    int iSpeed = 1;

    posX1 -= iSpeed;
    posX2 -= iSpeed;



    if(posX1 <= -mapSize.width / 2)
        posX1 = mapSize.width + mapSize.width / 2;
    if(posX2 <= -mapSize.width / 2)
        posX2 = mapSize.width + mapSize.width / 2;
    m_bgSprite1->setPositionX(posX1);
    m_bgSprite2->setPositionX(posX2);

}
