#ifndef STRINGTREEDATAITEM_H
#define STRINGTREEDATAITEM_H

#include <wx/treectrl.h>

enum StringType {
    NONE_STRING,
    ANIM_STRING,
    FOOTER_STRING,
    EXTRA_STRING,
};

class StringTreeDataItem : public wxTreeItemData {
protected:
    int string_number;
    int frame_number;
    StringType string_type;

public:
    StringTreeDataItem(StringType string_type, int string_number, int frame_number = 0);
    StringType getType();
    int getNumber();
    int getFrame();
};

#endif // STRINGTREEDATAITEM_H
