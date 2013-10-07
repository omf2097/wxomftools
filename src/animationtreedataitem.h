#ifndef ANIMATIONTREEDATAITEM_H
#define ANIMATIONTREEDATAITEM_H

#include <wx/treectrl.h>
#include <shadowdive/shadowdive.h>

class AnimationTreeDataItem : public wxTreeItemData {
public:
    static const int ANIMATION = 0;
    static const int SPRITE = 1;

    AnimationTreeDataItem(sd_animation *animation);
    AnimationTreeDataItem(sd_sprite *sprite);

    int getType();
    sd_animation* getAnimation();
    sd_sprite* getSprite();

protected:
    sd_animation *animation;
    sd_sprite *sprite;
};

#endif // ANIMATIONTREEDATAITEM_H
