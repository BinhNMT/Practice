#include "IState.h"
#include "TrafficControler.h"

class RestartState: public IState
{
private:
    TrafficControler* m_controler;

public:
    RestartState(TrafficControler* p_controler);
    void stateHandling(unsigned int timeCount);
};