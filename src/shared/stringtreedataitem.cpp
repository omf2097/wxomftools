#include "stringtreedataitem.h"

StringTreeDataItem::StringTreeDataItem(StringType string_type, int string_number, int frame_number) : wxTreeItemData() {
    this->string_type = string_type;
    this->string_number = string_number;
    this->frame_number = frame_number;
}

StringType StringTreeDataItem::getType() {
    return this->string_type;
}

int StringTreeDataItem::getNumber() {
    return this->string_number;
}

int StringTreeDataItem::getFrame() {
    return this->frame_number;
}