#include "animationtreedataitem.h"

AnimationTreeDataItem::AnimationTreeDataItem(sd_bk_anim *animation, int anim_id) : wxTreeItemData() {
    this->sprite = NULL;
    this->animation = animation;
    this->anim_id = anim_id;
    this->sprite_id = -1;
}

AnimationTreeDataItem::AnimationTreeDataItem(sd_sprite *sprite, int anim_id, int sprite_id) : wxTreeItemData() {
    this->sprite = sprite;
    this->animation = NULL;
    this->anim_id = anim_id;
    this->sprite_id = sprite_id;
}

AnimationTreeDataItem::AnimationTreeDataItem() : wxTreeItemData() {
    this->sprite = NULL;
    this->animation = NULL;
}

int AnimationTreeDataItem::getType() {
    if(this->sprite != NULL) {
        return SPRITE;
    } else if(this->animation != NULL) {
        return ANIMATION;
    } else {
        return EMPTY;
    }
}

sd_bk_anim* AnimationTreeDataItem::getAnimation() {
    return this->animation;
}

sd_sprite* AnimationTreeDataItem::getSprite() {
    return this->sprite;
}
