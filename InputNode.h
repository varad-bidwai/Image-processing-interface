#pragma once
#include "NodeBase.h"

class InputNode : public NodeBase {
public:
    InputNode();
    void process() override;
    void onInputChanged(Socket*) override {}
};
