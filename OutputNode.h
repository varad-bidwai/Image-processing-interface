#pragma once
#include "NodeBase.h"

class OutputNode : public NodeBase {
public:
    OutputNode();
    void process() override;
    void onInputChanged(Socket* socket) override;
};
