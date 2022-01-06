#include "IState.h"
#include "TrafficControler.h"

class YellowState: public IState
{
private:
    TrafficControler* m_controler;

public:
    YellowState(TrafficControler* p_controler);
    void stateHandling(unsigned int timeCount);
};