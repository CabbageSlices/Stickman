#include "Includes.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "./Entity.h"
#include "components/Component.h"
#include "components/Component_Tests.h"
#include "gmock/gmock-function-mocker.h"

using ::testing::MockFunction;
using testing::Mock;

class EntityTest : public ::testing::Test {
public:
    EntityTest():
        entity(),
        mockComponent(new MockComponent()),
        mockComponent2(new MockComponent()),
        copyOfMockComponent(mockComponent)
    {}

protected:

    Entity entity;
    std::shared_ptr<MockComponent> mockComponent;
    std::shared_ptr<MockComponent> mockComponent2;
    std::shared_ptr<MockComponent> copyOfMockComponent;
    MockFunction<Entity::UpdateCallbackSignature> updateCallback;
    MockFunction<Entity::UpdateCallbackSignature> updateCallback2;
    MockFunction<Entity::RenderCallbackSignature> renderCallback;
};

