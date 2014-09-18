#ifndef _HELPERS_H
#define _HELPERS_H

#include <stdint.h>
#include <wx/textctrl.h>

void _cs(wxTextCtrl *ctrl, int num);
void _ct8(wxTextCtrl *ctrl, uint8_t *num);
void _ct16(wxTextCtrl *ctrl, uint16_t *num);
void _cti16(wxTextCtrl *ctrl, int16_t *num);
void _cti32(wxTextCtrl *ctrl, int *num);
void _ctb(wxTextCtrl *ctrl, uint8_t *flag);

#endif // _HELPERS_H