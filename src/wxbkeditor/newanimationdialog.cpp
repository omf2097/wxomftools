#include "newanimationdialog.h"
#include <wx/dialog.h>

NewAnimationDialog::NewAnimationDialog(wxWindow *parent) : NewAnimationBaseDialog(parent) {}
NewAnimationDialog::~NewAnimationDialog() {}

int NewAnimationDialog::getIndex() {
    long value;
    if(!this->anim_id_field->GetValue().ToLong(&value)) {
        value = -1;
    }
    return value;
}
