#ifndef SampleScene_HPP_
#define SampleScene_HPP_
#include "IScene.hpp"

class SampleScene final : public IScene{
public:
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Finalize() override;

private:

}; // class SampleScene

#endif // SampleScene_HPP_
