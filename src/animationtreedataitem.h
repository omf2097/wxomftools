#ifndef ANIMATIONTREEDATAITEM_H
#define ANIMATIONTREEDATAITEM_H

#include <wx/treectrl.h>
#include <shadowdive/shadowdive.h>

class AnimationTreeDataItem : public wxTreeItemData {
public:
    static const int ANIMATION = 0;
    static const int SPRITE = 1;
    static const int EMPTY = 2;

    AnimationTreeDataItem(sd_bk_anim *animation);
    AnimationTreeDataItem(sd_sprite *sprite);
    AnimationTreeDataItem();

    int getType();
    sd_bk_anim* getAnimation();
    sd_sprite* getSprite();

protected:
    sd_bk_anim *animation;
    sd_sprite *sprite;
};

#endif // ANIMATIONTREEDATAITEM_H
