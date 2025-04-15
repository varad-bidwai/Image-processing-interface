#pragma once
#include "NodeBase.h"

class BlurNode : public NodeBase {
public:
    BlurNode();
    void process() override;
    void onInputChanged(Socket* socket) override;
};
