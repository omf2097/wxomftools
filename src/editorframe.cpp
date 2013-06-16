#include "editorframe.h"

EditorFrame::EditorFrame(wxFrame *frame) : BaseFrame(frame) {
    // Load handlers
    wxImage::AddHandler(new wxPNGHandler);
}

EditorFrame::~EditorFrame() {

}
