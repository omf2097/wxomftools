#include "app.h"
#include "editorframe.h"

IMPLEMENT_APP(EditorApp);

bool EditorApp::OnInit() {
    EditorFrame* frame = new EditorFrame(0L);
    frame->Show();
    return true;
}
