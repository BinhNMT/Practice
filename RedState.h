#include "IState.h"
#include "TrafficControler.h"

class RedState: public IState
{
private:
    TrafficControler* m_controler;

public:
    RedState(TrafficControler* p_controler);
    void stateHandling(unsigned int timeCount);
};