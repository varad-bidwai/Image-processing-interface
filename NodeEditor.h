#pragma once
#include <QMainWindow>

class NodeCanvas;

class NodeEditor : public QMainWindow {
    Q_OBJECT
public:
    NodeEditor(QWidget *parent = nullptr);
private:
    NodeCanvas* canvas;
};
