#include "IState.h"
#include "TrafficControler.h"

class GreenState: public IState
{
private:
    TrafficControler* m_controler;

public:
    GreenState(TrafficControler* p_controler);
    void stateHandling(unsigned int timeCount);
};