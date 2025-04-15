#include <QApplication>
#include "NodeEditor.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    NodeEditor editor;
    editor.show();
    return app.exec();
}
