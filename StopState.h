#include "IState.h"
#include "TrafficControler.h"

class StopState: public IState
{
private:
    TrafficControler* m_controler;

public:
    StopState(TrafficControler* p_controler);
    void stateHandling(unsigned int timeCount);
};