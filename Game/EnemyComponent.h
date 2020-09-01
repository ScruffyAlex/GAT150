#pragma once
#include "Components/Component.h"
namespace nc
{

    class EnemyComponent : public Component
    {
        virtual bool Create(void* data = nullptr) override;
        virtual void Destroy() override;
        virtual Object* Clone() override { return new EnemyComponent{ *this }; }

        virtual void Update() override;
    };

}
