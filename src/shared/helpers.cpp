#include "helpers.h"
#include <wx/string.h>

void _cs(wxTextCtrl *ctrl, int num) {
    wxString v = wxString::Format("%d", num);
    ctrl->SetValue(v);
}

void _ct8(wxTextCtrl *ctrl, uint8_t *num) {
    long v;
    if(!ctrl->GetValue().ToLong(&v)) {
        return;
    }
    if(v < 0) v = 0;
    if(v > 0xFF) v = 0xFF;
    *num = v;
}

void _ct16(wxTextCtrl *ctrl, uint16_t *num) {
    long v;
    if(!ctrl->GetValue().ToLong(&v)) {
        return;
    }
    if(v < 0) v = 0;
    if(v > 0xFFFF) v = 0xFFFF;
    *num = v;
}

void _cti16(wxTextCtrl *ctrl, int16_t *num) {
    long v;
    if(!ctrl->GetValue().ToLong(&v)) {
        return;
    }
    if(v < -0x7FFF) v = -0x7FFF;
    if(v > 0x7FFF) v = 0x7FFF;
    *num = v;
}

void _ctb(wxTextCtrl *ctrl, uint8_t *flag) {
    long v;
    if(!ctrl->GetValue().ToLong(&v)) {
        return;
    }

    if(v > 0) v = 1;
    if(v <= 0) v = 0;
    *flag = v;
}